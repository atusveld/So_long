# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: atusveld <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/24 17:50:02 by atusveld      #+#    #+#                  #
#    Updated: 2022/08/16 16:37:17 by atusveld      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c		ft_isalnum.c		ft_isalpha.c		ft_strdup.c\
	ft_isascii.c		ft_isdigit.c		ft_tolower.c		ft_toupper.c\
	ft_memcmp.c			ft_memchr.c			ft_memcpy.c			ft_memmove.c\
	ft_memset.c			ft_bzero.c			ft_strchr.c			ft_strrchr.c\
	ft_strnstr.c		ft_strlcat.c		ft_strlcpy.c		ft_calloc.c\
	ft_strlen.c			ft_strncmp.c		ft_strjoin.c		ft_substr.c\
	ft_strtrim.c		ft_itoa.c			ft_strmapi.c		ft_putnbr_fd.c\
	ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		ft_split.c\
	ft_isprint.c		ft_striteri.c\

B_SRCS = ft_lstadd_back_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c	ft_lstmap_bonus.c\
	ft_lstadd_front_bonus.c		ft_lstdelone_bonus.c	ft_lstlast_bonus.c	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
OBJ		= 	$(SRCS:.c=.o)
B_OBJ	=	$(B_SRCS:.c=.o)

ifdef	WITH_BONUS
	SRCS += $(B_SRCS)
	OBJ += $(B_OBJ)
endif

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^


all: $(NAME)


$(NAME): $(OBJ)
	@ar -rcs $(NAME) $^

re: fclean all


clean:
	@rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@rm -f $(NAME)

bonus: $(OBJ)
	$(MAKE) WITH_BONUS=1 --no-print-directory
