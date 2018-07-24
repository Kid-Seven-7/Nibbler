# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 09:06:50 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/24 15:37:24 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42_nibbler

#lib names
LIB_1_NAME = LIB_1/sfml.so
LIB_2_NAME = LIB_2/sdl.so
LIB_3_NAME = LIB_3/glfw.so

SRC = src/main.cpp

LIB_1_HEADER = -I includes -I LIB_1/SFML/include
LIB_2_HEADER = -I LIB_2/SDL/SDL2.framework/Headers

SFML_EXP = DYLD_FRAMEWORK_PATH="$(PWD)/LIB_1/SFML/Frameworks"

CMP = clang++

all:
	+$(MAKE) -C LIB_1
	+$(MAKE) -C LIB_2
	$(CMP) $(SRC) -o $(NAME) $(LIB_1_HEADER) $(LIB_2_HEADER)
	export $(SFML_EXP)

clean:
	rm -rf $(LIB_1_NAME)
	rm -rf $(LIB_2_NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
