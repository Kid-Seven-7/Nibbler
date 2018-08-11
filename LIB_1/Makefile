# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 15:28:13 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/26 07:57:47 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_1_NAME = sfml.so

SRC_DLL = Sfml.lib.cpp

HEADER = -I includes -I ./SFML/include

LIB_2_HEADER = -I ../LIB_2/SDL/SDL2.framework/Headers

LIB_3_HEADER = -I ~/.brew/include

CMP_DLL = clang++ -Wall -Werror -Wextra -shared -fPIC -framework sfml-graphics -framework sfml-window -framework sfml-system -framework sfml-audio -F SFML/Frameworks

sfml: clean
	$(CMP_DLL) $(SRC_DLL) -o $(LIB_1_NAME) $(HEADER) $(LIB_2_HEADER) $(LIB_3_HEADER)
	@mv $(LIB_1_NAME) ../bin/

clean:
	rm -rf $(LIB_1_NAME)

fclean: clean

re: fclean sfml
