NAME = libasm.a

SRCS = srcs/ft_strlen.s \
	   srcs/ft_strcpy.s \
	   srcs/ft_strcmp.s	\
	   srcs/ft_write.s \
	   srcs/ft_read.s \
	   srcs/ft_strdup.s

OBJCS = $(SRCS:%.s=%.o)

CC = gcc

ARFLAGS = rcs

RMFLAGS = -rf

NA = nasm

NAFLAGS = -fmacho64

all: $(NAME)

%.o:%.s
	$(NA) $(NAFLAGS) $<

$(NAME): $(OBJCS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJCS)

clean:
	$(RM) $(RMFLAGS) $(OBJCS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) a.out a.out.dSYM

re: fclean all

test:
	$(CC) -g -L . -lasm main.c

.PHONY: all clean fclean re test
