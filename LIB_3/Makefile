# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:51:26 by jngoma            #+#    #+#              #
#    Updated: 2018/07/25 06:57:06 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_3_NAME = glfw.so

SRC_A = GLFW/src

COMPILER = clang++

CXX = -Wall -Werror -Wextra -std=c++11

HEADER = -I ~/.brew/include

LIB_1_HEADER = -I includes -I ../LIB_1/SFML/include

LIB_2_HEADER = -I ../LIB_2/SDL/SDL2.framework/Headers

LIB = -L ~/.brew/lib

LD_FLAG = -shared -fPIC -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo

gflw: clean
	@echo compiling glfw.so
	@$(COMPILER) $(CXX) glfw.lib.cpp -o $(LIB_3_NAME) $(LD_FLAG) $(HEADER) \
	$(LIB_1_HEADER) $(LIB_2_HEADER) $(LIB)

clean:
	@echo deleting glfw.so
	@rm -rf $(LIB_3_NAME)

fclean: clean

re: fclean glfw
