NAME = ../lib/libft.a
GNL = gnl

SRC_FILE =		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
				ft_tolower.c ft_toupper.c ft_memmove.c ft_strnstr.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
				ft_split.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_ultoa.c ft_ultox.c \
				ft_search.c ft_strjoin_free.c ft_ralloc.c ft_strapp_free.c ft_find_char.c \
				ft_tab_append.c

SRCS		= ${SRC_FILE}
OBJS		= $(SRCS:%.c=%.o)

INCLUDE = ../include/
HEADER_NAME = libft.h
HEADER = ${addprefix ${INCLUDE}, ${HEADER_NAME}}
FLAGS = -Wall -Werror -Wextra

ECHO = /bin/echo
AR = /usr/bin/ar
CC = /usr/bin/clang
RM = /bin/rm
MKDIR = /bin/mkdir
RANLIB = /usr/bin/ranlib


all : $(NAME)

$(NAME) : ${OBJS} ${HEADER}
	@${ECHO} Creating ${NAME}
	@${MKDIR} -p ../lib
	@${AR} rc ${NAME} ${OBJS}
	@${RANLIB} ${NAME}

%.o: %.c
	@${CC} $(FLAGS) -I ${INCLUDE} -c $< -o $@

clean :
	@${ECHO} Removing objects files from libft
	@${RM} -f ${OBJS}

fclean : clean
	@${ECHO} Removing ${NAME}
	@${RM} -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ../lib/libft
