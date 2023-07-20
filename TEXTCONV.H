#ifndef _TextConv
#define _TextConv

//File Types

#define	TC_PC			0
#define TC_AMIGA		1
#define TC_MAC			2
#define	TC_BINARY		3
#define	TC_ERROR		4

void ProcessTextFile(CString fname,int DestType);

#endif
