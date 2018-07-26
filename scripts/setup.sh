#!usr/bin/env/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

#brew installation
echo "${BLUE}checking for brew...${NC}"
if [ ! -d $HOME/.brew ];
then
	echo ${RED}brew not found${NC}
	echo ${ORANGE}installing brew...${NC}
  sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	zsh
else
	echo ${GREEN}brew found${NC}
fi

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

#cmake installation
echo "${BLUE}checking for cmake...${NC}"
if [ ! -d $HOME/.brew/Cellar/cmake ];
then
	echo ${RED}cmake not found${NC}
	echo ${ORANGE}installing cmake...${NC}
  brew install cmake
else
	echo "${GREEN}glfw found${NC}"
fi

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

#glfw installation
echo "${BLUE}checking for glfw...${NC}"
if [ ! -d $HOME/.brew/Cellar/glfw ];
then
	echo ${RED}glfw not found${NC}
	echo ${ORANGE}installing glfw...${NC}
  brew install glfw
else
	echo "${GREEN}glfw found${NC}"
fi

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

echo "${BLUE}checking for sfml frameworks...${NC}"
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

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

if [ -f LIB_3/GLFW/CMakeCache.txt ];
then
	echo ${RED}CMakeCache found${NC}
	echo ${ORANGE}removing CMakeCache.txt...${NC}
	rm LIB_3/GLFW/CMakeCache.txt
fi

printf ${CYAN}'%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -${NC}

echo ${}creating build directory${}
mkdir build
cd build
echo ${}building GLFW${}
cmake ../LIB_3/GLFW/
make install ../LIB_3/GLFW/
cd ..
echo ${ORANGE}removing build directory...${NC}
rm -rf build

clear

echo ${GREEN}Nibbler and all dependencies successfully installed and setup${NC}
