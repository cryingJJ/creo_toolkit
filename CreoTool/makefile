#             PTC             File
# -----------------------------------------------------------------------------
# File Name
MAKEFILENAME = CreoTool

# Machine Type
PRO_MACHINE_TYPE = x86e_win64

# Executable names
EXE_DLL = CreoTool.dll

# Pro/Toolkit Source & Machine Loadpoint  (EXTERNAL USE - DEFAULT)
PROTOOL_SRC = ./src

# Include File Paths
INCS = -I. -I"C:/PTC/Creo 2.0/Common Files/M060/protoolkit/includes" -I$(PROTOOL_SRC)/includes

# Compiler Flags
CC = cl
MACH = -DPRO_MACHINE=36 -DPRO_OS=4
CCFLAGS = -c -GS -fp:precise -D_WSTDIO_DEFINED  /Od /Z7
CFLAGS = $(CCFLAGS) $(INCS) $(MACH)

# Libraries
PTCLIBS = "C:/PTC/Creo 2.0/Common Files/M060/protoolkit/x86e_win64/obj/protoolkit.lib"
PTCLIBS_DLL = "C:/PTC/Creo 2.0/Common Files/M060/protoolkit/x86e_win64/obj/protk_dll.lib"
LIBS = libcmt.lib kernel32.lib user32.lib wsock32.lib advapi32.lib mpr.lib winspool.lib netapi32.lib psapi.lib gdi32.lib shell32.lib comdlg32.lib ole32.lib ws2_32.lib

# Object files
OBJS = main.obj CommonFuns.obj ShowDirectory.obj OpenSamenameDrw.obj CleanWorkDirectory.obj TimeSave.obj PaintColor.obj AlignSymDim.obj RenameMdl.obj ChangeWorkDirectory.obj PrtinAsmRename.obj BatOpenFiles.obj BatSnapshot.obj BattoPdf.obj BattoDwg.obj AutoDirSetting.obj Cfg.obj FamInstExport.obj PartShow.obj AutoWorkDirSetting.obj LayerSetting.obj qrcodegen.obj InsertQRCode.obj


# Linker
LINK = link

# Dll target
$(EXE_DLL) :  $(OBJS) $(PTCLIBS_DLL)
	$(LINK) /subsystem:console -out:$(EXE_DLL) /debug /machine:amd64 /dll @<<longline.list
$(OBJS) $(PTCLIBS_DLL) $(LIBS)
<<

# object dependencies
main.obj:  $(PROTOOL_SRC)/main.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/main.c

ShowDirectory.obj:  $(PROTOOL_SRC)/ShowDirectory.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/ShowDirectory.c

OpenSamenameDrw.obj:  $(PROTOOL_SRC)/OpenSamenameDrw.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/OpenSamenameDrw.c

CommonFuns.obj:  $(PROTOOL_SRC)/CommonFuns.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/CommonFuns.c

CleanWorkDirectory.obj:  $(PROTOOL_SRC)/CleanWorkDirectory.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/CleanWorkDirectory.c

TimeSave.obj:  $(PROTOOL_SRC)/TimeSave.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/TimeSave.c

PaintColor.obj:  $(PROTOOL_SRC)/PaintColor.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/PaintColor.c

AlignSymDim.obj:  $(PROTOOL_SRC)/AlignSymDim.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/AlignSymDim.c

RenameMdl.obj:  $(PROTOOL_SRC)/RenameMdl.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/RenameMdl.c

ChangeWorkDirectory.obj:  $(PROTOOL_SRC)/ChangeWorkDirectory.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/ChangeWorkDirectory.c

PrtinAsmRename.obj:  $(PROTOOL_SRC)/PrtinAsmRename.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/PrtinAsmRename.c

BatOpenFiles.obj:  $(PROTOOL_SRC)/BatOpenFiles.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/BatOpenFiles.c

BatSnapshot.obj:  $(PROTOOL_SRC)/BatSnapshot.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/BatSnapshot.c

BattoPdf.obj:  $(PROTOOL_SRC)/BattoPdf.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/BattoPdf.c

BattoDwg.obj:  $(PROTOOL_SRC)/BattoDwg.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/BattoDwg.c

AutoDirSetting.obj:  $(PROTOOL_SRC)/AutoDirSetting.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/AutoDirSetting.c

Cfg.obj:  $(PROTOOL_SRC)/Cfg.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/Cfg.c

FamInstExport.obj:  $(PROTOOL_SRC)/FamInstExport.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/FamInstExport.c

PartShow.obj:  $(PROTOOL_SRC)/PartShow.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/PartShow.c

AutoWorkDirSetting.obj:  $(PROTOOL_SRC)/AutoWorkDirSetting.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/AutoWorkDirSetting.c

LayerSetting.obj:  $(PROTOOL_SRC)/LayerSetting.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/LayerSetting.c

qrcodegen.obj:  $(PROTOOL_SRC)/qrcodegen.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/qrcodegen.c

InsertQRCode.obj:  $(PROTOOL_SRC)/InsertQRCode.c
	$(CC) $(CFLAGS) $(PROTOOL_SRC)/InsertQRCode.c

clean :
	del $(OBJS)
	del $(EXE_DLL)
	del $(MAKEFILENAME).pdb
	del $(MAKEFILENAME).ilk
	del $(MAKEFILENAME).exp
	del $(MAKEFILENAME).lib