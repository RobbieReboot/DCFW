# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=DCFW - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to DCFW - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "DCFW - Win32 Debug" && "$(CFG)" != "DCFW - Win32 Release" &&\
 "$(CFG)" != "DCFW - Win32 Remote Debug for RHDebug "
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "DCFW.MAK" CFG="DCFW - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DCFW - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DCFW - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DCFW - Win32 Remote Debug for RHDebug " (based on\
 "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "DCFW - Win32 Remote Debug for RHDebug "
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "DCFW - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : "$(OUTDIR)\DCFW.exe"

CLEAN : 
	-@erase ".\WinDebug\vc40.pdb"
	-@erase ".\WinDebug\DCFW.pch"
	-@erase ".\WinDebug\vc40.idb"
	-@erase ".\WinDebug\DCFW.exe"
	-@erase ".\WinDebug\STDAFX.OBJ"
	-@erase ".\WinDebug\DCFWDLG.OBJ"
	-@erase ".\WinDebug\BATCHLST.OBJ"
	-@erase ".\WinDebug\TCPROGRE.OBJ"
	-@erase ".\WinDebug\SRCCONV.OBJ"
	-@erase ".\WinDebug\SCPROGRE.OBJ"
	-@erase ".\WinDebug\FORMATCO.OBJ"
	-@erase ".\WinDebug\BuildLibraryDialog.obj"
	-@erase ".\WinDebug\DCFW.OBJ"
	-@erase ".\WinDebug\TEXTCONV.OBJ"
	-@erase ".\WinDebug\DCFW.res"
	-@erase ".\WinDebug\DCFW.ilk"
	-@erase ".\WinDebug\DCFW.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/DCFW.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/DCFW.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /debug /machine:I386 /SUBSYSTEM:windows,4.00
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /incremental:yes /pdb:"$(OUTDIR)/DCFW.pdb" /debug\
 /machine:I386 /out:"$(OUTDIR)/DCFW.exe" /SUBSYSTEM:windows,4.00 
LINK32_OBJS= \
	"$(INTDIR)/STDAFX.OBJ" \
	"$(INTDIR)/DCFWDLG.OBJ" \
	"$(INTDIR)/BATCHLST.OBJ" \
	"$(INTDIR)/TCPROGRE.OBJ" \
	"$(INTDIR)/SRCCONV.OBJ" \
	"$(INTDIR)/SCPROGRE.OBJ" \
	"$(INTDIR)/FORMATCO.OBJ" \
	"$(INTDIR)/BuildLibraryDialog.obj" \
	"$(INTDIR)/DCFW.OBJ" \
	"$(INTDIR)/TEXTCONV.OBJ" \
	"$(INTDIR)/DCFW.res"

"$(OUTDIR)\DCFW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : "$(OUTDIR)\DCFW.exe"

CLEAN : 
	-@erase ".\WinRel\DCFW.exe"
	-@erase ".\WinRel\DCFWDLG.OBJ"
	-@erase ".\WinRel\DCFW.pch"
	-@erase ".\WinRel\TCPROGRE.OBJ"
	-@erase ".\WinRel\STDAFX.OBJ"
	-@erase ".\WinRel\SCPROGRE.OBJ"
	-@erase ".\WinRel\DCFW.OBJ"
	-@erase ".\WinRel\BuildLibraryDialog.obj"
	-@erase ".\WinRel\FORMATCO.OBJ"
	-@erase ".\WinRel\TEXTCONV.OBJ"
	-@erase ".\WinRel\SRCCONV.OBJ"
	-@erase ".\WinRel\BATCHLST.OBJ"
	-@erase ".\WinRel\DCFW.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /G4 /MD /W3 /GX /O2 /Ob2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /G4 /MD /W3 /GX /O2 /Ob2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/DCFW.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/DCFW.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /machine:I386 /SUBSYSTEM:windows,4.00
# SUBTRACT LINK32 /pdb:none
LINK32_FLAGS=/nologo /incremental:no /pdb:"$(OUTDIR)/DCFW.pdb" /machine:I386\
 /out:"$(OUTDIR)/DCFW.exe" /SUBSYSTEM:windows,4.00 
LINK32_OBJS= \
	"$(INTDIR)/DCFWDLG.OBJ" \
	"$(INTDIR)/TCPROGRE.OBJ" \
	"$(INTDIR)/STDAFX.OBJ" \
	"$(INTDIR)/SCPROGRE.OBJ" \
	"$(INTDIR)/DCFW.OBJ" \
	"$(INTDIR)/BuildLibraryDialog.obj" \
	"$(INTDIR)/FORMATCO.OBJ" \
	"$(INTDIR)/TEXTCONV.OBJ" \
	"$(INTDIR)/SRCCONV.OBJ" \
	"$(INTDIR)/BATCHLST.OBJ" \
	"$(INTDIR)/DCFW.res"

"$(OUTDIR)\DCFW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DCFW___W"
# PROP BASE Intermediate_Dir "DCFW___W"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\DCFW.exe" "$(OUTDIR)\DCFW.bsc"

CLEAN : 
	-@erase ".\vc40.pdb"
	-@erase ".\DCFW.pch"
	-@erase ".\vc40.idb"
	-@erase ".\DCFW.pdb"
	-@erase ".\DCFWDLG.OBJ"
	-@erase ".\DCFW.OBJ"
	-@erase ".\FORMATCO.OBJ"
	-@erase ".\SRCCONV.OBJ"
	-@erase ".\TEXTCONV.OBJ"
	-@erase ".\BATCHLST.OBJ"
	-@erase ".\TCPROGRE.OBJ"
	-@erase ".\SCPROGRE.OBJ"
	-@erase ".\STDAFX.OBJ"
	-@erase ".\BuildLibraryDialog.obj"
	-@erase ".\DCFW.res"
	-@erase "\\rhdebug\rhc\dcfw\DCFW.exe"
	-@erase "\\rhdebug\rhc\dcfw\DCFW.ilk"
	-@erase "\\rhdebug\rhc\dcfw\DCFW.bsc"
	-@erase ".\DCFW.SBR"
	-@erase ".\FORMATCO.SBR"
	-@erase ".\SRCCONV.SBR"
	-@erase ".\TEXTCONV.SBR"
	-@erase ".\BATCHLST.SBR"
	-@erase ".\TCPROGRE.SBR"
	-@erase ".\SCPROGRE.SBR"
	-@erase ".\STDAFX.SBR"
	-@erase ".\BuildLibraryDialog.sbr"
	-@erase ".\DCFWDLG.SBR"

# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fr /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /c 
CPP_OBJS=
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/DCFW.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"\\rhdebug\rhc\dcfw\DCFW.bsc"
BSC32_FLAGS=/nologo /o"\\rhdebug\rhc\dcfw\DCFW.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/DCFW.SBR" \
	"$(INTDIR)/FORMATCO.SBR" \
	"$(INTDIR)/SRCCONV.SBR" \
	"$(INTDIR)/TEXTCONV.SBR" \
	"$(INTDIR)/BATCHLST.SBR" \
	"$(INTDIR)/TCPROGRE.SBR" \
	"$(INTDIR)/SCPROGRE.SBR" \
	"$(INTDIR)/STDAFX.SBR" \
	"$(INTDIR)/BuildLibraryDialog.sbr" \
	"$(INTDIR)/DCFWDLG.SBR"

"$(OUTDIR)\DCFW.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /debug /machine:I386 /out:"\\rhdebug\rhdbg\dcfw\DCFW.exe" /SUBSYSTEM:windows,4.00
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 /nologo /debug /machine:I386 /out:"\\rhdebug\rhc\dcfw\DCFW.exe" /SUBSYSTEM:windows,4.00
# SUBTRACT LINK32 /verbose /pdb:none
LINK32_FLAGS=/nologo /incremental:yes /pdb:"$(OUTDIR)/DCFW.pdb" /debug\
 /machine:I386 /out:"\\rhdebug\rhc\dcfw\DCFW.exe" /SUBSYSTEM:windows,4.00 
LINK32_OBJS= \
	"$(INTDIR)/DCFWDLG.OBJ" \
	"$(INTDIR)/DCFW.OBJ" \
	"$(INTDIR)/FORMATCO.OBJ" \
	"$(INTDIR)/SRCCONV.OBJ" \
	"$(INTDIR)/TEXTCONV.OBJ" \
	"$(INTDIR)/BATCHLST.OBJ" \
	"$(INTDIR)/TCPROGRE.OBJ" \
	"$(INTDIR)/SCPROGRE.OBJ" \
	"$(INTDIR)/STDAFX.OBJ" \
	"$(INTDIR)/BuildLibraryDialog.obj" \
	"$(INTDIR)/DCFW.res"

"$(OUTDIR)\DCFW.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

MTL_PROJ=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "DCFW - Win32 Debug"
# Name "DCFW - Win32 Release"
# Name "DCFW - Win32 Remote Debug for RHDebug "

!IF  "$(CFG)" == "DCFW - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"

!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\STDAFX.CPP
DEP_CPP_STDAF=\
	".\STDAFX.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\DCFW.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /G4 /MD /W3 /GX /O2 /Ob2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\DCFW.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fr /Fp"$(INTDIR)/DCFW.pch" /Yc"stdafx.h" /c $(SOURCE) \
	

"$(INTDIR)\STDAFX.OBJ" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\STDAFX.SBR" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\DCFW.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DCFW.CPP
DEP_CPP_DCFW_=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\DCFWDLG.H"\
	".\BATCHLST.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\DCFW.OBJ" : $(SOURCE) $(DEP_CPP_DCFW_) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\DCFW.OBJ" : $(SOURCE) $(DEP_CPP_DCFW_) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\DCFW.OBJ" : $(SOURCE) $(DEP_CPP_DCFW_) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\DCFW.SBR" : $(SOURCE) $(DEP_CPP_DCFW_) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DCFWDLG.CPP
DEP_CPP_DCFWD=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\DCFWDLG.H"\
	".\FORMATCO.H"\
	".\BATCHLST.H"\
	".\BuildLibraryDialog.h"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\DCFWDLG.OBJ" : $(SOURCE) $(DEP_CPP_DCFWD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\DCFWDLG.OBJ" : $(SOURCE) $(DEP_CPP_DCFWD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\DCFWDLG.OBJ" : $(SOURCE) $(DEP_CPP_DCFWD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\DCFWDLG.SBR" : $(SOURCE) $(DEP_CPP_DCFWD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DCFW.RC
DEP_RSC_DCFW_R=\
	".\RES\DCFW.ICO"\
	".\RES\DCFW.RC2"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\DCFW.res" : $(SOURCE) $(DEP_RSC_DCFW_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\DCFW.res" : $(SOURCE) $(DEP_RSC_DCFW_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\DCFW.res" : $(SOURCE) $(DEP_RSC_DCFW_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\README.TXT

!IF  "$(CFG)" == "DCFW - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"

!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\FORMATCO.CPP
DEP_CPP_FORMA=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\FORMATCO.H"\
	".\BATCHLST.H"\
	".\TCPROGRE.H"\
	".\SCPROGRE.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\FORMATCO.OBJ" : $(SOURCE) $(DEP_CPP_FORMA) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\FORMATCO.OBJ" : $(SOURCE) $(DEP_CPP_FORMA) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\FORMATCO.OBJ" : $(SOURCE) $(DEP_CPP_FORMA) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\FORMATCO.SBR" : $(SOURCE) $(DEP_CPP_FORMA) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BATCHLST.CPP
DEP_CPP_BATCH=\
	".\STDAFX.H"\
	".\BATCHLST.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\BATCHLST.OBJ" : $(SOURCE) $(DEP_CPP_BATCH) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\BATCHLST.OBJ" : $(SOURCE) $(DEP_CPP_BATCH) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\BATCHLST.OBJ" : $(SOURCE) $(DEP_CPP_BATCH) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\BATCHLST.SBR" : $(SOURCE) $(DEP_CPP_BATCH) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TCPROGRE.CPP
DEP_CPP_TCPRO=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\TCPROGRE.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\TCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_TCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\TCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_TCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\TCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_TCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\TCPROGRE.SBR" : $(SOURCE) $(DEP_CPP_TCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TEXTCONV.CPP
DEP_CPP_TEXTC=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\DCFWDLG.H"\
	".\FORMATCO.H"\
	".\TCPROGRE.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\TEXTCONV.OBJ" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\TEXTCONV.OBJ" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\TEXTCONV.OBJ" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\TEXTCONV.SBR" : $(SOURCE) $(DEP_CPP_TEXTC) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SRCCONV.CPP
DEP_CPP_SRCCO=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\DCFWDLG.H"\
	".\FORMATCO.H"\
	".\TCPROGRE.H"\
	".\SCPROGRE.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\SRCCONV.OBJ" : $(SOURCE) $(DEP_CPP_SRCCO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\SRCCONV.OBJ" : $(SOURCE) $(DEP_CPP_SRCCO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\SRCCONV.OBJ" : $(SOURCE) $(DEP_CPP_SRCCO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\SRCCONV.SBR" : $(SOURCE) $(DEP_CPP_SRCCO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SCPROGRE.CPP
DEP_CPP_SCPRO=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\SCPROGRE.H"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"

# ADD CPP /W4

"$(INTDIR)\SCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_SCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"
   $(CPP) /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE)


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\SCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_SCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"
   $(CPP) /nologo /G4 /MD /W3 /GX /O2 /Ob2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE)


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


BuildCmds= \
	$(CPP) /nologo /MDd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fr /Fp"$(INTDIR)/DCFW.pch" /Yu"stdafx.h" /c $(SOURCE) \
	

"$(INTDIR)\SCPROGRE.OBJ" : $(SOURCE) $(DEP_CPP_SCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"
   $(BuildCmds)

"$(INTDIR)\SCPROGRE.SBR" : $(SOURCE) $(DEP_CPP_SCPRO) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\BuildLibraryDialog.cpp
DEP_CPP_BUILD=\
	".\STDAFX.H"\
	".\DCFW.H"\
	".\BuildLibraryDialog.h"\
	

!IF  "$(CFG)" == "DCFW - Win32 Debug"


"$(INTDIR)\BuildLibraryDialog.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Release"


"$(INTDIR)\BuildLibraryDialog.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ELSEIF  "$(CFG)" == "DCFW - Win32 Remote Debug for RHDebug "


"$(INTDIR)\BuildLibraryDialog.obj" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"

"$(INTDIR)\BuildLibraryDialog.sbr" : $(SOURCE) $(DEP_CPP_BUILD) "$(INTDIR)"\
 "$(INTDIR)\DCFW.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
