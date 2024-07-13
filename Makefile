NAME_1	= client
NAME_2	= server
LIBFT_DIR	= ./ft_libft
PRINTF_DIR	= ./ft_printf
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf
SRCS_1	= clients/client.c
SRCS_2	= servers/server.c
SRCS_1_B	= clients/client_bonus.c
SRCS_2_B	= servers/server_bonus.c

OBJS_1	= $(SRCS_1:.c=.o)
OBJS_2	= $(SRCS_2:.c=.o)
OBJS_1_B	= $(SRCS_1_B:.c=.o)
OBJS_2_B	= $(SRCS_2_B:.c=.o)

INSC = include/minitalk.h

all: $(NAME_1) $(NAME_2)

extern: printf libft

printf:
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a ./

libft:
	@make -C ${LIBFT_DIR}
	@cp $(LIBFT_DIR)/libft.a ./

$(NAME_1): extern $(OBJS_1)
	@$(CC) $(FLAGS) $(OBJS_1) libftprintf.a libft.a -o $(NAME_1)

$(NAME_2): extern $(OBJS_2)
	@$(CC) $(FLAGS) $(OBJS_2) libftprintf.a libft.a -o $(NAME_2)

bonus:extern ${OBJS_1_B} ${OBJS_2_B}
	@$(CC) $(FLAGS) $(OBJS_1_B) libftprintf.a libft.a -o ${NAME_1} -I${INSC}
	@$(CC) $(FLAGS) $(OBJS_2_B) libftprintf.a libft.a -o ${NAME_2} -I${INSC}

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS_1) $(OBJS_2) ${OBJS_1_B} ${OBJS_2_B}

fclean: clean
	@$(RM) $(NAME_1) $(NAME_2) libft.a libftprintf.a ${LIBFT_DIR}/libft.a ${PRINTF_DIR}/libftprintf.a

re: fclean all

.PHONY: all clean fclean re server client
