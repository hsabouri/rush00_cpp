# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 11:38:54 by hsabouri          #+#    #+#              #
#    Updated: 2018/04/01 12:05:29 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_retro

SRCDIR = sources
OBJDIR = objs
INCDIR = includes

SRCNAM = main.cpp \
		 AbstractGameEntity.cpp \
		 Moving.cpp \
		 Ennemy.cpp \
		 Bullet.cpp \
		 Window.cpp \
		 Player.cpp \
		 lib.cpp
INCNAM = AbstractGameEntity.hpp \
		 Window.hpp \
		 Moving.hpp \
		 Ennemy.hpp \
		 Bullet.hpp \
		 Player.hpp \
		 lib.hpp
CC=g++
CFLAGS= -Wall -Wextra -I$(INCDIR) -g -std=c++98
#CFLAGS+= -Werror
LDFLAGS=

SRC=$(SRCNAM:%=$(SRCDIR)/%)
INC=$(INCNAM:%=$(INCDIR)/%)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -lncurses -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all
