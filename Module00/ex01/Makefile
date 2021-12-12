# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 23:50:00 by smun              #+#    #+#              #
#    Updated: 2021/09/20 15:35:37 by smun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact PhoneBook Main
INC = -I.

FINAL_SRCS = $(addsuffix .cpp, $(SRCS))
FINAL_OBJS = $(FINAL_SRCS:.cpp=.o)

NAME = phonebook

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(FINAL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(FINAL_OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
