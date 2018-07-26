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

if [ ! -d ~/Library/frameworks/SFML.framework ];
then
	echo ${RED}no sfml.framework folder found${NC}
	echo ${ORANGE}copying sfml.framework directory...${NC}
  cp -rf LIB_1/SFML/Frameworks/SFML.framework ~/Library/Frameworks
else
	echo "${GREEN}SFML.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/sfml-graphics.framework ];
then
	echo ${RED}no sfml-graphics.framework folder found${NC}
	echo ${ORANGE}copying sfml.framework directory...${NC}
  cp -rf LIB_1/SFML/Frameworks/sfml-graphics.framework ~/Library/Frameworks
else
	echo "${GREEN}sfml-graphics.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/sfml-network.framework ];
then
	echo ${RED}no sfml-network.framework folder found${NC}
	echo ${ORANGE}copying sfml-network.framework directory...${NC}
  cp -rf LIB_1/SFML/Frameworks/sfml-network.framework ~/Library/Frameworks
else
	echo "${GREEN}sfml-network.framework directory found${NC}"
fi

if [ ! -d ~/Library/frameworks/sfml-system.framework ];
then
	echo ${RED}no sfml-network.framework folder found${NC}
	echo ${ORANGE}copying sfml-system.framework directory...${NC}
  cp -rf LIB_1/SFML/Frameworks/sfml-system.framework ~/Library/Frameworks
else
	echo "${GREEN}sfml-system.framework directory found"
fi

if [ ! -d ~/Library/frameworks/sfml-window.framework ];
then
	echo ${RED}no sfml-window.framework folder found${NC}
	echo ${ORANGE}copying sfml-window.framework directory...${NC}
  cp -rf LIB_1/SFML/Frameworks/sfml-window.framework ~/Library/Frameworks
else
	echo ${GREEN}sfml-window.framework directory found${NC}
fi
