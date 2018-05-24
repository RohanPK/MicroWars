##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MicroWars
ConfigurationName      :=Debug
WorkspacePath          :=/home/ishan/Documents/MicroWars
ProjectPath            :=/home/ishan/Documents/MicroWars/MicroWars
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ishan Sang
Date                   :=25/05/18
CodeLitePath           :=/home/ishan/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="MicroWars.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)home/Downloads/Eclipse_SFML/SFML-2.4.2/include  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/SFML 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" 
LibPath                :=$(LibraryPathSwitch)home/Downloads/Eclipse_SFML/SFML-2.4.2/lib  $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/include 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -std=c++14 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) $(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix): init_game.cpp $(IntermediateDirectory)/init_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/init_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/init_game.cpp$(DependSuffix): init_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/init_game.cpp$(DependSuffix) -MM init_game.cpp

$(IntermediateDirectory)/init_game.cpp$(PreprocessSuffix): init_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/init_game.cpp$(PreprocessSuffix) init_game.cpp

$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix): main_menu.cpp $(IntermediateDirectory)/main_menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/main_menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_menu.cpp$(DependSuffix): main_menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_menu.cpp$(DependSuffix) -MM main_menu.cpp

$(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix): main_menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix) main_menu.cpp

$(IntermediateDirectory)/window.cpp$(ObjectSuffix): window.cpp $(IntermediateDirectory)/window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/window.cpp$(DependSuffix): window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/window.cpp$(DependSuffix) -MM window.cpp

$(IntermediateDirectory)/window.cpp$(PreprocessSuffix): window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/window.cpp$(PreprocessSuffix) window.cpp

$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix): draw_game.cpp $(IntermediateDirectory)/draw_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/draw_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/draw_game.cpp$(DependSuffix): draw_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/draw_game.cpp$(DependSuffix) -MM draw_game.cpp

$(IntermediateDirectory)/draw_game.cpp$(PreprocessSuffix): draw_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/draw_game.cpp$(PreprocessSuffix) draw_game.cpp

$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix): Unit.cpp $(IntermediateDirectory)/Unit.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/Unit.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Unit.cpp$(DependSuffix): Unit.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Unit.cpp$(DependSuffix) -MM Unit.cpp

$(IntermediateDirectory)/Unit.cpp$(PreprocessSuffix): Unit.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Unit.cpp$(PreprocessSuffix) Unit.cpp

$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix): update_game.cpp $(IntermediateDirectory)/update_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/update_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/update_game.cpp$(DependSuffix): update_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/update_game.cpp$(DependSuffix) -MM update_game.cpp

$(IntermediateDirectory)/update_game.cpp$(PreprocessSuffix): update_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/update_game.cpp$(PreprocessSuffix) update_game.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix): Orb.cpp $(IntermediateDirectory)/Orb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ishan/Documents/MicroWars/MicroWars/Orb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Orb.cpp$(DependSuffix): Orb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Orb.cpp$(DependSuffix) -MM Orb.cpp

$(IntermediateDirectory)/Orb.cpp$(PreprocessSuffix): Orb.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Orb.cpp$(PreprocessSuffix) Orb.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


