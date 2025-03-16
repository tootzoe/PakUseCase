




#TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#
#
PRJNAMETOOT = PAKUSECASE
DEFINES += "PAKUSECASE_API="
DEFINES += "PAKUSECASE_API(...)="
#
DEFINES += "UCLASS()=PAKUSECASE_API"
DEFINES += "UCLASS(...)=PAKUSECASE_API"
#
# this is true during development with unreal-editor...

DEFINES += "WITH_EDITORONLY_DATA=1"

## this project only

##


INCLUDEPATH += ../Intermediate/Build/Win64/UnrealEditor/Inc/$$PRJNAMETOOT/UHT
INCLUDEPATH += $$PRJNAMETOOT/Public $$PRJNAMETOOT/Private
#INCLUDEPATH += ../Plugins/NNEPostProcessing/Source/NNEPostProcessing/Public
# we should follow UE project struct to include files, start from prj.Build.cs folder
#
#  The Thirdparty libs
#
#
#
include(defs.pri)
include(inc.pri)
#
## this project only
# INCLUDEPATH += $$UESRCROOT/Runtime/Renderer/Private
##
#
#

DISTFILES += \
    PakUseCase.Target.cs \
    PakUseCase/PakUseCase.Build.cs \
    PakUseCaseEditor.Target.cs

HEADERS += \
    PakUseCase/PakUseCase.h \
    PakUseCase/Public/PakDownloader.h

SOURCES += \
    PakUseCase/PakUseCase.cpp \
    PakUseCase/Private/PakDownloader.cpp
