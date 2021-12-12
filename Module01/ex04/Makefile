# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 23:50:00 by smun              #+#    #+#              #
#    Updated: 2021/09/25 23:24:35 by smun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main
INC = -I.

FINAL_SRCS = $(addsuffix .cpp, $(SRCS))
FINAL_OBJS = $(FINAL_SRCS:.cpp=.o)

RED := "\033[31m"
GREEN := "\033[32m"
YELLOW := "\033[33m"
CYAN := "\033[36m"
WHITE := "\033[37m"
BLUE := "\033[34m"
RESET := "\033[0m"

NAME = replace

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(FINAL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(FINAL_OBJS)

fclean: clean
	rm -f $(NAME) original.txt original.txt.REPLACE

re: clean all

test: all
	@echo $(GREEN)'${CURDIR}/$(NAME)'
	@echo $(RED)
	-@${CURDIR}/$(NAME) || true
	@echo '-----------------------------------------------------'

	@echo $(GREEN)'${CURDIR}/$(NAME) NOT_EXIST_FILE'
	@echo $(RED)
	-@${CURDIR}/$(NAME) NOT_EXIST_FILE || true
	@echo '-----------------------------------------------------'

	@echo $(GREEN)'${CURDIR}/$(NAME) Makefile 11'
	@echo $(RED)
	-@${CURDIR}/$(NAME) Makefile 11 || true
	@echo '-----------------------------------------------------'

	@echo $(GREEN)"${CURDIR}/$(NAME) NOT_EXIST_FILE '' ''"
	@echo $(RED)
	-@${CURDIR}/$(NAME) NOT_EXIST_FILE '' '' || true
	@echo '-----------------------------------------------------'

	@echo $(BLUE)'echo -n hello wooooorld\\nhello\\noooo    o   o     oo \\n\\n\\ndofo\\noo" > original.txt'
	@echo -n "hello wooooorld\nhello\noooo    o   o     oo \n\n\noo" > original.txt
	@echo '-----------------------------------------------------'

	@echo $(GREEN)"${CURDIR}/$(NAME) original.txt '' ''"
	@echo $(YELLOW)
	-@${CURDIR}/$(NAME) original.txt '' '' || true
	@echo '-- [DIFF original.txt] vs [original.txt.REPLACE]:'${CYAN}
	@diff -U3 original.txt original.txt.REPLACE
	@echo '-----------------------------------------------------'

	@echo $(GREEN)"${CURDIR}/$(NAME) original.txt 'oo' '33'"
	@echo $(YELLOW)
	-@${CURDIR}/$(NAME) original.txt 'oo' '33' || true
	@echo '-- [DIFF original.txt] vs [original.txt.REPLACE]:'${CYAN}
	@-diff -U3 original.txt original.txt.REPLACE || true
	@echo '-----------------------------------------------------'

	@echo $(GREEN)"${CURDIR}/$(NAME) original.txt 'oo' ''"
	@echo $(YELLOW)
	-@${CURDIR}/$(NAME) original.txt 'oo' '' || true
	@echo '-- [DIFF original.txt] vs [original.txt.REPLACE]:'${CYAN}
	@-diff -U3 original.txt original.txt.REPLACE || true
	@echo '-----------------------------------------------------'

	@echo ${RESET}


.PHONY: all clean fclean re test
