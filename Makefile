# **************************************************************************** #
#                                                                              #
#    Makefile                                             :::      ::::::::    #
#                                                       :+:      :+:    :+:    #
#    By: hsabouri <hsabouri@student.42.fr>            +:+ +:+         +:+      #
#    By: jde-maga <jde-maga@stduent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 11:38:54 by hsabouri          #+#    #+#              #
#    Updated: 2018/03/31 12:43:27 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_retro

SRCDIR = sources
OBJDIR = objs
INCDIR = includes

SRCNAM = main.cpp
INCNAM = 

CC=g++
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR) -std=c++98 -pedantic
LDFLAGS=

SRC=$(SRCNAM:%=$(SRCDIR)/%)
INC=$(INCNAM:%=$(INCDIR)/%)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INC)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all
