# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatshiy <amatshiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 09:51:26 by jngoma            #+#    #+#              #
#    Updated: 2018/08/01 07:49:38 by amatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_3_NAME = glfw.so

SRC_A = GLFW/src

COMPILER = clang++

CXX = -Wall -Werror -Wextra -std=c++11

HEADER = -I ~/.brew/include

GLEW_HEADER = -I ~/.brew/Cellar/glew/2.1.0/include

GLEW_LIB = -L ~/.brew/Cellar/glew/2.1.0/lib

GLEW_FLAGS = -DGLEW_STATIC -lGLEW

LIB_1_HEADER = -I includes -I ../LIB_1/SFML/include

LIB_2_HEADER = -I ../LIB_2/SDL/SDL2.framework/Headers

LIB = -L ~/.brew/lib

HIDE_FLAG = 2>/dev/null

LD_FLAG = -shared -fPIC -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo

gflw: clean
	@echo compiling glfw.so
	@$(COMPILER) $(CXX) glfw.lib.cpp -o $(LIB_3_NAME) $(LD_FLAG) $(HEADER) \
	$(LIB_1_HEADER) $(LIB_2_HEADER) $(LIB) $(GLEW_HEADER) $(GLEW_LIB) \
	$(GLEW_FLAGS) $(HIDE_FLAG) 
	@mv $(LIB_3_NAME) ../bin/

clean:
	@echo deleting glfw.so
	@rm -rf $(LIB_3_NAME)

fclean: clean

re: fclean glfw
