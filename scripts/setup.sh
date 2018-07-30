#!usr/bin/env/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

clear
#exports to .profile which needs to be sourced
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}setting bash profile...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo 'export DYLD_FRAMEWORK_PATH="$(PWD)/LIB_1/SFML/Frameworks"' > ~/.profile

#brew installation
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for brew...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ ! -d $HOME/.brew ];
then
	echo ${RED}brew not found${NC}
	echo ${ORANGE}installing brew...${NC}
  sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)";	source ~/.zshrc
else
	echo ${GREEN}brew found${NC}
fi

#cmake installation
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for cmake...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ ! -d $HOME/.brew/Cellar/cmake ];
then
	echo ${RED}cmake not found${NC}
	echo ${ORANGE}installing cmake...${NC}
  brew install cmake
else
	echo "${GREEN}cmake found${NC}"
fi

#glfw installation
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for glfw...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ ! -d $HOME/.brew/Cellar/glfw ];
then
	echo ${RED}glfw not found${NC}
	echo ${ORANGE}installing glfw...${NC}
  brew install glfw 2>&1
else
	echo "${GREEN}glfw found${NC}"
fi

#glew installation
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for glew...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ ! -d $HOME/.brew/Cellar/glew ];
then
	echo ${RED}glew not found${NC}
	echo ${ORANGE}installing glew...${NC}
	brew install glew 2>&1
	brew link glew 2>&1
else
	echo "${GREEN}glew found${NC}"
	echo "${GREEN}linking glfw...${NC}"
	brew link glew 2>&1
fi

#SFML Frameworks check
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for sfml frameworks...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ ! -d ~/Library/frameworks ];
then
	echo ${RED}no frameworks folder found${NC}
	echo ${ORANGE}creating frameworks directory...${NC}
  mkdir /Library/Frameworks
else
	echo "${GREEN}Frameworks directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/FLAC.framework ];
then
	echo ${RED}no FLAC.framework folder found${NC}
	echo ${ORANGE}copying FLAC.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/FLAC.framework ~/Library/Frameworks
else
	echo "${GREEN}FLAC.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/freetype.framework ];
then
	echo ${RED}no freetype.framework folder found${NC}
	echo ${ORANGE}copying freetype.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/freetype.framework ~/Library/Frameworks
else
	echo "${GREEN}freetype.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/ogg.framework ];
then
	echo ${RED}no ogg.framework folder found${NC}
	echo ${ORANGE}copying ogg.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/ogg.framework ~/Library/Frameworks
else
	echo "${GREEN}ogg.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/OpenAL.framework ];
then
	echo ${RED}no OpenAL.framework folder found${NC}
	echo ${ORANGE}copying OpenAL.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/OpenAL.framework ~/Library/Frameworks
else
	echo "${GREEN}OpenAL.framework directory found"
fi

if [ ! -d ~/Library/frameworks/vorbis.framework ];
then
	echo ${RED}no vorbis.framework folder found${NC}
	echo ${ORANGE}copying vorbis.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/vorbis.framework ~/Library/Frameworks
else
	echo ${GREEN}vorbis.framework directory found${NC}
fi

if [ ! -d ~/Library/frameworks/vorbisfile.framework ];
then
	echo ${RED}no vorbisfile.framework folder found${NC}
	echo ${ORANGE}copying vorbisfile.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/vorbisfile.framework ~/Library/Frameworks
else
	echo "${GREEN}vorbisfile.framework directory found"
fi

if [ ! -d ~/Library/frameworks/vorbisenc.framework ];
then
	echo ${RED}no vorbisenc.framework folder found${NC}
	echo ${ORANGE}copying vorbisenc.framework directory...${NC}
  cp -rf LIB_1/SFML/extlibs/vorbisenc.framework ~/Library/Frameworks
else
	echo ${GREEN}vorbisenc.framework directory found${NC}
fi

#Removes CMakeCache if any
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo "${BLUE}checking for residual CMakeCache.txt...${NC}"
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

#Builds GLFW
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
echo ${BLUE}building GLFW...${NC}
printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}
if [ -d Build ];
then
	echo ${GREEN}GFLW build directory found...${NC}
else
	echo ${GREEN}creating build directory...${NC}
	mkdir build
	cd build
	echo ${CYAN}
	cmake ../LIB_3/GLFW/ > /dev/null 2>&1
	make install ../LIB_3/GLFW/ > /dev/null 2>&1
	echo ${NC}
	cd ..
fi

clear

echo ${GREEN}Nibbler and all dependencies successfully installed and setup${NC}
