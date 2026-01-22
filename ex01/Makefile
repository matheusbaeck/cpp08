# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: math <math@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 18:22:37 by math42            #+#    #+#              #
#    Updated: 2026/01/21 22:24:48 by math             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cpp
SRCSDIR     = .
INCLUDES    = .
OBJDIR      = .obj

SRCS        = $(wildcard $(SRCSDIR)/*.cpp)
OBJS        = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

ifeq ($(TIME), 1)
	CFLAGS = -Wall -Wextra -Werror -DTIME_MODE
else
	CFLAGS = -Wall -Wextra -Werror -std=c++98
endif

ifeq ($(LIST), 1)
	CFLAGS +=-DLIST_MODE
else
	CFLAGS += -DVECTOR_MODE
endif

ifdef RANGE
	CFLAGS += -DRANGE=$(RANGE)
endif

ifdef MAX
	CFLAGS += -DRANGE=$(RANGE)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	find . -name "*.o" -exec rm -f {} +
	rm -rf $(NAME)
	

re: fclean all

.PHONY: all clean fclean re test

