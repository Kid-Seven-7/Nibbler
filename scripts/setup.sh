#!usr/bin/env/bash
printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -

#brew installation
echo "checking for brew..."
if [ ! -d $HOME/.brew ];
then
	echo brew not found
	echo installing brew
  sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	zsh
else
	echo "brew found"
fi

printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -

#glfw installation
echo "checking for glfw..."
if [ ! -d $HOME/.brew/Cellar/glfw ];
then
	echo glfw not found
	echo installing glfw
  brew install glfw
else
	echo "glfw found"
fi

printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
