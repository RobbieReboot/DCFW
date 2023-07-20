void BinToText(CmdLine *cl)
{
	int	rc,i,n;
	FILE *f;
	LngT	len;
	BytP	buffer,b;

	struct find_t file;
	ChrP	inFileSpec,outFileSpec,nc;
	DwdT	lines,leftover;
	ChrT	LinePrefix[80]={0};
	WrdT	plat;
	DwdT	data;
	FlgT	Motorola=FALSE;

	inFileSpec=cl->GetFirstArg();
	outFileSpec=cl->GetNextArg();

	if (!inFileSpec||!outFileSpec)
		{
		printf("ERROR : Need both input & output filenames for bintext conversion.\n");
		return;
		}

	printf("Binary To Text File Convertion of %s to %s\n",inFileSpec,outFileSpec);

	rc = _dos_findfirst(inFileSpec,_A_NORMAL,&file);

	if (rc)
		{
		printf("ERROR : Couldn't find %s\n",file.name);
		return;
		}


	f=fopen(inFileSpec,"rb");
	fseek(f,0,SEEK_END);
	len = ftell(f);
	fseek(f,0,SEEK_SET);

	b=buffer=(BytP)malloc(len);					//1024 should hold 2 lines!

	if (!b)
		{
		printf("ERROR : Couldn't Load file %s (not enough memory)\n");
		fclose(f);
		return;
		}

	fread(buffer,1,len,f);
	fclose(f);											//input file is now in buffer

	len /= ItemSize;				

	lines = len / ItemsPerLine;
	leftover = len % ItemsPerLine;

	f=fopen(outFileSpec,"w");

	if (stricmp(Platform,"snasm")==0)
		{
		sprintf(LinePrefix,"\t\tdc.%c\t",(ItemSize==1) ? 'b' : ((ItemSize == 2) ? 'w' : 'l'));
		fprintf(f,"%s:",lable);
		plat=SNASM;
		}

	if (stricmp(Platform,"tasm")==0)
		{
		sprintf(LinePrefix,"\t\td%c\t",(ItemSize==1) ? 'b' : ((ItemSize == 2) ? 'w' : 'd'));
		fprintf(f,"%s:",lable);
		plat=TASM;
		}

	if (stricmp(Platform,"C")==0)
		{
		switch (ItemSize)
			{
			case	1:	fprintf(f,"unsigned char %s[] =\n",lable);
						fprintf(f,"{\n");
						break;

			case	2:	fprintf(f,"unsigned short %s[] =\n",lable);
						fprintf(f,"{\n");
						break;

			case	4:	fprintf(f,"unsigned long %s[] =\n",lable);
						fprintf(f,"{\n");
						break;
			}
		plat=C;
		}

	if (stricmp(ByteOrder,"MOTOROLA")==0)
		Motorola=TRUE;


	for (i = 0; i< lines ;i++ )
		{
		if (plat!=C)
			fprintf(f,"%s",LinePrefix);

		for (n=0;n<ItemsPerLine;n++)
			{

			switch (ItemSize)
				{
				case	1:
						data = *buffer++;
						break;
				case	2:
						data = (WrdT)*(WrdP)buffer;
						if (Motorola)
							data=(DwdT)SwapWord(data);
						buffer+=2;
						break;
				case	4:
						data = (DwdT)*(DwdP)buffer;
						if (Motorola)
							data=SwapLong(data);
						buffer+=4;
						break;
				}




			if (plat == C)
				{

				if (n != ItemsPerLine-1)
					nc = ",";
				else
					nc = ",\n";

				if ((i == lines-1) && (leftover==0) && (n == ItemsPerLine-1))
					nc = "\n";

				switch (ItemSize)
					{
					case	1:
							fprintf(f,"0x%02x%s",(BytT)data,nc);
							break;
					case	2:
							fprintf(f,"0x%04x%s",(WrdT)data,nc);
							break;
					case	4:
							fprintf(f,"0x%08x%s",(DwdT)data,nc);
							break;
					}
				}

			if (plat == TASM)
				{
				if (n==ItemsPerLine-1)
					nc="\n";
				else
					nc=",";

				switch (ItemSize)
					{
					case	1:
							fprintf(f,"0%02Xh%s",(BytT)data,nc);
							break;
					case	2:
							fprintf(f,"0%04Xh%s",(WrdT)data,nc);
							break;
					case	4:
							fprintf(f,"0%08Xh%s",(DwdT)data,nc);
							break;
					}
				}

			if (plat == SNASM)
				{
				if (n==ItemsPerLine-1)
					nc="\n";
				else
					nc=",";


				switch (ItemSize)
					{
					case	1:
							fprintf(f,"$%02X%s",(BytT)data,nc);
							break;
					case	2:
							fprintf(f,"$%04X%s",(WrdT)data,nc);
							break;
					case	4:
							fprintf(f,"$%08X%s",(DwdT)data,nc);
							break;
					}
				}

			} //Column Loop

		} // Row Loop


	//do the left overs


	if (leftover)
		if (plat!=C)
			fprintf(f,"%s",LinePrefix);

	for (n=0;n<leftover;n++)
		{

		switch (ItemSize)
			{
			case	1:
					data = *buffer++;
					break;
			case	2:
					data = (WrdT)*(WrdP)buffer;
					if (Motorola)
						data=(DwdT)SwapWord(data);
					buffer+=2;
					break;
			case	4:
					data = (DwdT)*(DwdP)buffer;
					if (Motorola)
						data=SwapLong(data);
					buffer+=4;
					break;
			}

		if (plat == C)
			{

			if (n != leftover-1)
				nc = ",";
			else
				nc = "\n";

			switch (ItemSize)
				{
				case	1:
						fprintf(f,"0x%02x%s",(BytT)data,nc);
						break;
				case	2:
						fprintf(f,"0x%04x%s",(WrdT)data,nc);
						break;
				case	4:
						fprintf(f,"0x%08x%s",(DwdT)data,nc);
						break;
				}
			}

		if (plat == TASM)
			{
			if (n == leftover-1)
				nc="\n";
			else
				nc=",";

			switch (ItemSize)
				{
				case	1:
						fprintf(f,"0%02Xh%s",(BytT)data,nc);
						break;
				case	2:
						fprintf(f,"0%04Xh%s",(WrdT)data,nc);
						break;
				case	4:
						fprintf(f,"0%08Xh%s",(DwdT)data,nc);
						break;
				}
			}

		if (plat == SNASM)
			{
			if (n == leftover-1)
				nc = "\n";
			else
				nc = ",";


			switch (ItemSize)
				{
				case	1:
						fprintf(f,"$%02X%s",(BytT)data,nc);
						break;
				case	2:
						fprintf(f,"$%04X%s",(WrdT)data,nc);
						break;
				case	4:
						fprintf(f,"$%08X%s",(DwdT)data,nc);
						break;
				}
			}


		} //Column Loop


	if (plat == C)
		{
		fprintf(f,"};\n");
		}

	fclose(f);
	free(b);

}

f(f,"$%02X%s",(BytT)data,nc);
						break;
				case	2:
						fprintf(f,"$%04X%s",(WrdT)data,nc);
						break;
				case	4:
						fprintf(f,"$%08X%s",(DwdT)data,nc);
						break;
				}
			}


		} //Column Loop


	if (plat == C)
		{
		fprintf(f,"};\n");
		}

	fclose(f);
	free(b);

}

