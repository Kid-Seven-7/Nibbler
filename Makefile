# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 09:06:50 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/26 07:56:54 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42_nibbler

#lib names
LIB_1_NAME = LIB_1/sfml.so
LIB_2_NAME = LIB_2/sdl.so
LIB_3_NAME = LIB_3/glfw.so

SRC = src/main.cpp src/StartEngine.cpp

LIB_1_HEADER = -I includes -I LIB_1/SFML/include
LIB_2_HEADER = -I LIB_2/SDL/SDL2.framework/Headers
LIB_3_HEADER = -I ~/.brew/include

SFML_EXP = DYLD_FRAMEWORK_PATH="$(PWD)/LIB_1/SFML/Frameworks"

CMP = clang++

all: run_scripts
	+$(MAKE) -C LIB_1
	+$(MAKE) -C LIB_2
	+$(MAKE) -C LIB_3
	$(CMP) $(SRC) -o $(NAME) $(LIB_1_HEADER) $(LIB_2_HEADER) $(LIB_3_HEADER)

run_scripts:
	$(shell ./scripts/export_sfml.sh)

clean:
	rm -rf $(LIB_1_NAME)
	rm -rf $(LIB_2_NAME)
	rm -rf $(LIB_3_NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
