# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 15:28:13 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/20 16:20:48 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42_nibbler

LIB_1_NAME = sfml.so

SFML_EXP = DYLD_FRAMEWORK_PATH="$(PWD)/SFML/Frameworks"

SRC = main.cpp

SRC_DLL = Sfml.lib.cpp

HEADER = -I includes -I ./SFML/include

CMP_DLL = clang++ -shared -fPIC -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks

CMP = clang++

all:
	export $(SFML_EXP)
	$(CMP_DLL) $(SRC_DLL) -o $(LIB_1_NAME) $(HEADER)
	$(CMP) $(SRC) -o $(NAME) $(HEADER)

clean:
	rm -rf $(LIB_1_NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all