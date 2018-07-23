# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 07:58:55 by amatshiy          #+#    #+#              #
#    Updated: 2018/07/23 08:40:26 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_2_NAME = sdl.so

SRC_DLL = Sdl.lib.cpp

HEADER = -I SDL/SDL2.framework/Headers

CMP_DLL = clang++ -shared -fPIC SDL/SDL2.framework/SDL2

sdl: clean
	$(CMP_DLL) $(SRC_DLL) -o $(LIB_2_NAME) $(HEADER)

clean:
	rm -rf $(LIB_2_NAME)

fclean: clean

re: fclean sdl