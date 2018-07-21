# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 15:28:13 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/21 09:19:05 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_1_NAME = sfml.so

SRC_DLL = Sfml.lib.cpp

HEADER = -I includes -I ./SFML/include

CMP_DLL = clang++ -shared -fPIC -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks

sfml: clean
	$(CMP_DLL) $(SRC_DLL) -o $(LIB_1_NAME) $(HEADER)

clean:
	rm -rf $(LIB_1_NAME)

fclean: clean

re: fclean sfml