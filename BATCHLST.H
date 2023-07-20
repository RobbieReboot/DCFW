#include <afx.h>
#include <afxtempl.h>

//struct for Batch List Manipulation

class CBatch : public CObject
{
public:
	//options from the format convertion page

	CString		m_LabelPrefix;
	CString		m_LabelSuffix;
	CString		m_nFormat;
	DWORD		m_OutputAs;
	DWORD		m_ItemsPerLine;
	DWORD		m_ItemSize;
	DWORD		m_IncOrDec;
	DWORD		m_LabelMethod;
	DWORD		m_TextConvertMode;
	BYTE		m_SaveAsStrings;
	DWORD		m_Radix;
	DWORD		m_nStart;
	CString		m_Description;
	BOOL		m_Modified;
	BOOL		m_Loaded;
	DWORD		m_ByteOrder;
	CArray<CString,CString> Files;

	void Serialize(CArchive &ar);
	CBatch::CBatch(void);
	void SetDefaultState(void);
protected:
	DECLARE_SERIAL( CBatch);
};

extern CBatch CurrentBatch;
