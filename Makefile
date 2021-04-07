NAME = libasm.a

SRCS = srcs/ft_strlen.s

OBJCS = $(SRCS:%.s=%.o)

cc = gcc

ARFLAGS = rcs

RMFLAGS = -rf

all: $(NAME)

$(NAME): $(OBJCS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJCS)

$(OBJCS): 
	nasm -fmacho64 $(SRCS)

clean:
	$(RM) $(RMFLAGS) $(OBJCS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

test:
	$(CC) -L . -lasm main.c

.PHONY: all clean fclean re test
