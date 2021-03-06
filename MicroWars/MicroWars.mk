##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MicroWars
ConfigurationName      :=Debug
WorkspacePath          :=/home/rohan/Documents/Microwars
ProjectPath            :=/home/rohan/Documents/Microwars/MicroWars
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rohan
Date                   :=14/06/18
CodeLitePath           :=/home/rohan/.codelite
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/SFML 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/include 

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
Objects0=$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) $(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tesla.cpp$(ObjectSuffix) $(IntermediateDirectory)/level_editor.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix): Unit.cpp $(IntermediateDirectory)/Unit.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/Unit.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Unit.cpp$(DependSuffix): Unit.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Unit.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Unit.cpp$(DependSuffix) -MM Unit.cpp

$(IntermediateDirectory)/Unit.cpp$(PreprocessSuffix): Unit.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Unit.cpp$(PreprocessSuffix) Unit.cpp

$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix): Orb.cpp $(IntermediateDirectory)/Orb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/Orb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Orb.cpp$(DependSuffix): Orb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Orb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Orb.cpp$(DependSuffix) -MM Orb.cpp

$(IntermediateDirectory)/Orb.cpp$(PreprocessSuffix): Orb.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Orb.cpp$(PreprocessSuffix) Orb.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/window.cpp$(ObjectSuffix): window.cpp $(IntermediateDirectory)/window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/window.cpp$(DependSuffix): window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/window.cpp$(DependSuffix) -MM window.cpp

$(IntermediateDirectory)/window.cpp$(PreprocessSuffix): window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/window.cpp$(PreprocessSuffix) window.cpp

$(IntermediateDirectory)/Tesla.cpp$(ObjectSuffix): Tesla.cpp $(IntermediateDirectory)/Tesla.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/Tesla.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tesla.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tesla.cpp$(DependSuffix): Tesla.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tesla.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tesla.cpp$(DependSuffix) -MM Tesla.cpp

$(IntermediateDirectory)/Tesla.cpp$(PreprocessSuffix): Tesla.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tesla.cpp$(PreprocessSuffix) Tesla.cpp

$(IntermediateDirectory)/level_editor.cpp$(ObjectSuffix): level_editor.cpp $(IntermediateDirectory)/level_editor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/level_editor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/level_editor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/level_editor.cpp$(DependSuffix): level_editor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/level_editor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/level_editor.cpp$(DependSuffix) -MM level_editor.cpp

$(IntermediateDirectory)/level_editor.cpp$(PreprocessSuffix): level_editor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/level_editor.cpp$(PreprocessSuffix) level_editor.cpp

$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix): main_menu.cpp $(IntermediateDirectory)/main_menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/main_menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_menu.cpp$(DependSuffix): main_menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_menu.cpp$(DependSuffix) -MM main_menu.cpp

$(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix): main_menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix) main_menu.cpp

$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix): draw_game.cpp $(IntermediateDirectory)/draw_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/draw_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/draw_game.cpp$(DependSuffix): draw_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/draw_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/draw_game.cpp$(DependSuffix) -MM draw_game.cpp

$(IntermediateDirectory)/draw_game.cpp$(PreprocessSuffix): draw_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/draw_game.cpp$(PreprocessSuffix) draw_game.cpp

$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix): update_game.cpp $(IntermediateDirectory)/update_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/update_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/update_game.cpp$(DependSuffix): update_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/update_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/update_game.cpp$(DependSuffix) -MM update_game.cpp

$(IntermediateDirectory)/update_game.cpp$(PreprocessSuffix): update_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/update_game.cpp$(PreprocessSuffix) update_game.cpp

$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix): init_game.cpp $(IntermediateDirectory)/init_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rohan/Documents/Microwars/MicroWars/init_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/init_game.cpp$(DependSuffix): init_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/init_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/init_game.cpp$(DependSuffix) -MM init_game.cpp

$(IntermediateDirectory)/init_game.cpp$(PreprocessSuffix): init_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/init_game.cpp$(PreprocessSuffix) init_game.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


