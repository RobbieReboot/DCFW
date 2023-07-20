#include "stdafx.h"
#include "dcfw.h"
#include "dcfwdlg.h"
#include "formatco.h"
#include "tcprogre.h"
#include "scprogre.h"
#include <string.h>
#include <stdlib.h>
#include <afxtempl.h>
#include <io.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

unsigned short SwapWord(unsigned short a);
unsigned long SwapLong(unsigned long a);

#define	OA_C		0
#define	OA_TASM		1
#define	OA_SNASM68K	2
#define	OA_SNASM658	3
#define	OA_TEXT		4


#define	LM_FNONLY	0
#define	LM_FNEXT	1
#define	LM_FNn		2
#define	LM_PREFN	3
#define	LM_PREFNn	4
#define	LM_FNSUFF	5
#define	LM_FNSUFFn	6
#define	LM_PREFFNSUFF	7
#define	LM_PREFFNSUFFn	8
#define	LM_SUFFn	9


CString Exts[]=
{
  ".c",				//c
  ".asm",			//tasm
  ".s",				//snasm68000
  ".658",			//snasm6502
  ".txt"			//text list
};

int	ipl[]=
{
	1,2,4,8,16,32

};


int	FileNo = 0;

void CFormatConvertion::BinToSource(CString fname)
{
	int	i,n;
	FILE *f;
	int	len;
	char	*buffer,*b;

	CString outFileSpec,lineno;
	char	num[64]={0};
	char 	*nc;
	int		lines,leftover;
	char	LinePrefix[80]={0};
	unsigned long	data;
	BOOL	Motorola=FALSE;
	int		ItemSize;
	int		ItemsPerLine;
	CString	Lable;

	char	d[_MAX_DRIVE],p[_MAX_PATH],fn[_MAX_FNAME],e[_MAX_EXT];
		
	_splitpath(fname,d,p,fn,e);

	switch(m_ItemSize)
	{
	 	case	0:	ItemSize = 1;
					break;
		case	1:	ItemSize = 2;
					break;
		case	2:	ItemSize = 4;
					break;
	}
	
	f=fopen(fname,"rb");
	fseek(f,0,SEEK_END);
	len = ftell(f);
	fseek(f,0,SEEK_SET);

	//check to see that the file we are converting is a multiple of the item size... if not, warn
	//that the last value ma be shagged!

	if ((len%ItemSize)!=0)
	{
		CString e;
		int	r;
		e.Format("%s is not a multiple of \n%d Bytes, so the trailing %d bytes may be incorrect,"
				 " \ndo you wish to continue?",fn,ItemSize,len%ItemSize);
		r=MessageBox(e,"File Size Error",MB_ICONSTOP|MB_OKCANCEL);
		if ( r == IDCANCEL )
		{
			fclose(f);
			return;
		}
	//allow user to ignore error...
	}

	buffer = b = new char[len];

	if (!b)
		{
		MessageBox("Not enough memory","Memory Error",MB_ICONSTOP|MB_OK);
		fclose(f);
		return;
		}
	
	fread(buffer,1,len,f);
	fclose(f);											//input file is now in buffer



	ItemsPerLine = ipl[m_ItemsPerLine];

	len /= ItemSize;				

	lines = len / ItemsPerLine;
	leftover = len % ItemsPerLine;

	//get Output filespec from the output file type...
	outFileSpec = fn;
	outFileSpec += Exts[m_OutputAs];

	f=fopen(outFileSpec,"wt");

	//SNASM68K
	if (m_OutputAs == OA_SNASM68K )
		sprintf(LinePrefix,"\t\tdc.%c\t",(ItemSize==1) ? 'b' : ((ItemSize == 2) ? 'w' : 'l'));

	if (m_OutputAs == OA_SNASM658)
		sprintf(LinePrefix,"\t\td%c\t",(ItemSize==1) ? 'b' : ((ItemSize == 2) ? 'w' : 'l'));


	//TASM
	if (m_OutputAs == OA_TASM)
		sprintf(LinePrefix,"\t\td%c\t",(ItemSize==1) ? 'b' : ((ItemSize == 2) ? 'w' : 'd'));

	//C & text have no line prefixes...

	//next write out the file lable...

	switch	(m_LabelMethod)
	{
		case	LM_FNONLY:
			Lable.Format("%s",fn);
			break;
		case	LM_FNEXT:
			Lable.Format("%s%s",fn,e);
			break;
		case	LM_FNn:
			Lable.Format("%s_%d",fn,FileNo++);
			break;
		case	LM_PREFN:
			Lable.Format("%s%s",m_LabelPrefix,fn);
			break;
		case	LM_PREFNn:
			Lable.Format("%s%s%_d",m_LabelPrefix,fn,FileNo++);
			break;
		case	LM_FNSUFF:
			Lable.Format("%s%s",fn,m_LabelSuffix);
			break;
		case	LM_FNSUFFn:
			Lable.Format("%s%s_%d",fn,m_LabelSuffix);
			break;
		case	LM_PREFFNSUFF:
			Lable.Format("%s%s%s",m_LabelPrefix,fn,m_LabelSuffix);
			break;
		case	LM_PREFFNSUFFn:
			Lable.Format("%s%s%s_%d",m_LabelPrefix,fn,m_LabelSuffix,FileNo++);
			break;
		case	LM_SUFFn:
			Lable.Format("%s_%d",m_LabelSuffix,FileNo++);
			break;

	}

	if (m_OutputAs == OA_C)
	{
		switch (ItemSize)
		{
			case	1:	fprintf(f,"unsigned char %s[] =\n{\n",Lable);
						break;

			case	2:	fprintf(f,"unsigned short %s[] =\n{\n",Lable);
						break;

			case	4:	fprintf(f,"unsigned long %s[] =\n{\n",Lable);
						break;
		}
	}
	
	if ((m_OutputAs == OA_SNASM68K) || (m_OutputAs == OA_SNASM658))
		fprintf(f,"%s:",Lable);

	if (m_OutputAs == OA_TASM)
		fprintf(f,"%s",Lable);

	if (m_OutputAs == OA_TEXT )
	{
		fprintf(f,"FILE : ** %s **\n",Lable);
	}
	
	
	//now start writing out the body data for the file.

	for (i = 0; i< lines ;i++ )
	{
		if ((m_OutputAs != OA_C) && (m_OutputAs != OA_TEXT ))
			fprintf(f,"%s",LinePrefix);

		
		if (( i&1023 ) == 0)
		{
			lineno.Format("%d",i);
			m_SCProgressDlg->GetDlgItem(IDC_SCLINE)->SetWindowText(lineno);
		}


		for (n=0;n<ItemsPerLine;n++)
		{

			data=0;
			switch (ItemSize)
			{
				case	1:
					data = *buffer++;
					break;
				case	2:
					data = (unsigned short)*(unsigned short*)buffer;
					if (m_ByteOrder)
						data=(unsigned short)SwapWord((unsigned short)data);
					buffer+=2;
					break;
				case	4:
					data = (unsigned long)*(unsigned long*)buffer;
					if (m_ByteOrder)
						data=SwapLong(data);
					buffer+=4;
					break;
			}

			ultoa(data,num,m_Radix);

			if (m_OutputAs == OA_C)
			{

				if (n != ItemsPerLine-1)
					nc = ",";
				else
					nc = ",\n";

				if ((i == lines-1) && (leftover==0) && (n == ItemsPerLine-1))
					nc = "\n";

				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"0x%02x%s",(unsigned char)data,nc);
					if (ItemSize == 2)
						fprintf(f,"0x%04x%s",(unsigned short)data,nc);
					if (ItemSize == 4)
						fprintf(f,"0x%08x%s",(unsigned long)data,nc);
				}
			
				if (m_Radix == 8)
					fprintf(f,"%s","0");

				//write out the number as text if it wasnt hex
				if (m_Radix!=16)
					fprintf(f,"%s%s",num,nc);
					
			}

			if (m_OutputAs == OA_TASM)
			{
				if (n==ItemsPerLine-1)
					nc="\n";
				else
					nc=",";

				if ((m_Radix == 8) || (m_Radix == 2))
					fprintf(f,"%s","0");
			
				//bit of extra formatting for base 16 (the default)
				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"0%02xh",(unsigned char)data);
					if (ItemSize == 2)
						fprintf(f,"0%04xh",(unsigned short)data);
					if (ItemSize == 4)
						fprintf(f,"0%08xh",(unsigned long)data);
				}
				
				//write out the number as text
				if ((m_Radix == 8) || (m_Radix == 2))
					fprintf(f,"%s",num);

				//write out the termination char
				if (m_Radix == 2)
					fprintf(f,"%s","b");

				fprintf(f,"%s",nc);
			}

			if ((m_OutputAs == OA_SNASM68K) || (m_OutputAs == OA_SNASM658))
			{
				if (n==ItemsPerLine-1)
					nc="\n";
				else
					nc=",";

				if (m_Radix == 2)
					fprintf(f,"%s","%%");			//binary prefix


				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"$%02x%s",(unsigned char)data,nc);
					if (ItemSize == 2)
						fprintf(f,"$%04x%s",(unsigned short)data,nc);
					if (ItemSize == 4)
						fprintf(f,"$%08x%s",(unsigned long)data,nc);
				}
				else
					fprintf(f,"%s%s",num,nc);

			}

		} //Column Loop

	} // Row Loop


	//do the left overs


	if (leftover)
		if (m_OutputAs != OA_C)
			fprintf(f,"%s",LinePrefix);

	for (n=0;n<leftover;n++)
		{
			data=0;
			switch (ItemSize)
			{
				case	1:
					data = *buffer++;
					break;
				case	2:
					data = (unsigned short)*(unsigned short*)buffer;
					if (m_ByteOrder)
						data=(unsigned short)SwapWord((unsigned short)data);
					buffer+=2;
					break;
				case	4:
					data = (unsigned long)*(unsigned long*)buffer;
					if (m_ByteOrder)
						data=SwapLong(data);
					buffer+=4;
					break;
			}

			ltoa(data,num,m_Radix);

			if (m_OutputAs == OA_C)
			{

				if (n != leftover-1)
					nc = ",";
				else
					nc = "\n";

				if ((i == lines-1) && (leftover==0) && (n == ItemsPerLine-1))
					nc = "\n";

				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"0x%02x%s",(unsigned char)data,nc);
					if (ItemSize == 2)
						fprintf(f,"0x%04x%s",(unsigned short)data,nc);
					if (ItemSize == 4)
						fprintf(f,"0x%08x%s",(unsigned long)data,nc);
				}
			
				if (m_Radix == 8)
					fprintf(f,"%s","0");

				//write out the number as text if it wasnt hex
				if (m_Radix!=16)
					fprintf(f,"%s%s",num,nc);
					
			}

			if (m_OutputAs == OA_TASM)
			{
				if (n==leftover-1)
					nc="\n";
				else
					nc=",";

				if ((m_Radix == 8) || (m_Radix == 2))
					fprintf(f,"%s","0");
			
				//bit of extra formatting for base 16 (the default)
				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"0%02xh",(unsigned char)data);
					if (ItemSize == 2)
						fprintf(f,"0%04xh",(unsigned short)data);
					if (ItemSize == 4)
						fprintf(f,"0%08xh",(unsigned long)data);
				}
				
				//write out the number as text
				if ((m_Radix == 8) || (m_Radix == 2))
					fprintf(f,"%s",num);

				//write out the termination char
				if (m_Radix == 2)
					fprintf(f,"%s","b");

				fprintf(f,"%s",nc);


			}

			if ((m_OutputAs == OA_SNASM68K) || (m_OutputAs == OA_SNASM658))
			{
				if (n==leftover-1)
					nc="\n";
				else
					nc=",";

				if (m_Radix == 2)
					fprintf(f,"%s","%%");			//binary prefix

				if (m_Radix == 16)
				{
					if (ItemSize == 1)
						fprintf(f,"$%02x%s",(unsigned char)data,nc);
					if (ItemSize == 2)
						fprintf(f,"$%04x%s",(unsigned short)data,nc);
					if (ItemSize == 4)
						fprintf(f,"$%08x%s",(unsigned long)data,nc);
				}
				else
					fprintf(f,"%s%s",num,nc);

			}

		} //Column Loop


	if (m_OutputAs == OA_C)
	{
		fprintf(f,"};\n");
	}

	fclose(f);
	delete[] b;

}



unsigned short SwapWord(unsigned short a)
{

	return (((a&0xff) <<8) | ((a&0xff00)>>8));
}

unsigned long SwapLong(unsigned long a)
{
	long	b=a;
	a &= 0xff00ff00;
	b &= 0x00ff00ff;
	a = _rotl(a,8);
	b =	_rotr(b,8);
	return (a|b);;
}

