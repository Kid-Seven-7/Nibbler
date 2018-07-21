# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 09:06:50 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/21 09:18:36 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42_nibbler

SRC = main.cpp

LIB_1_HEADER = -I includes -I ./LIB_1/SFML/include

SFML_EXP = DYLD_FRAMEWORK_PATH="$(PWD)/LIB_1/SFML/Frameworks" 

CMP = clang++

all:
	+$(MAKE) -C LIB_1
	$(CMP) $(SRC) -o $(NAME) $(LIB_1_HEADER)
	export $(SFML_EXP)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all