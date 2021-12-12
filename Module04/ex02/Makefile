CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifeq ($(ABSTRACT),1)
	CFLAGS += -DABSTRACT=1
endif

SRCS = main Animal Dog Cat Brain
INC = -I./

FINAL_SRCS = $(addsuffix .cpp, $(SRCS))
FINAL_OBJS = $(FINAL_SRCS:.cpp=.o)

NAME = a.out

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
