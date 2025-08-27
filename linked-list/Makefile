NAME        = ./out/link
CC          = gcc
CFLAGS      = -fno-pic -fPIE -m32 -I.
VPATH       = src
SRCS        = link.c linkUtils.c
OBJS        = $(addprefix $(BUILD), $(notdir $(SRCS:.c=.o)))
RM          = rm -rf
BUILD       = build/

all: $(BUILD) $(NAME)

dump:
	objdump -D $(NAME) -M intel

out:
	make re
	clear
	./out/link

valgrind:
	make re
	clear
	valgrind ./out/link

$(BUILD):
	@mkdir -p $(BUILD)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BUILD)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re out