# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 14:10:52 by rihoy             #+#    #+#              #
#    Updated: 2024/07/10 14:23:22 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#   NAME
NAME = lib.a

#--------------------------------------#
#		Commande
#-----------------------#
RM = rm -fr
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -I includes

#--------------------------------------#
#       directory
#-----------------------#
OBJS = objs_lib

#--------------------------------------#
#       Colors
#-----------------------#
C_B = \033[0;30m
C_R = \033[1;31m
C_G = \033[1;32m
C_Y = \033[0;33m
C_BU = \033[0;34m
C_M = \033[0;35m
C_C = \033[0;36m
C_W = \033[0;37m
RESET = \033[0m

#--------------------------------------#
#		File
#-----------------------#
FILE_C =	lib_check.c \
			lib_cmp.c \
			lib_free.c \
			lib_is.c \
			lib_join.c \
			lib_len.c \
			lib_sent.c \
			lib_split.c \
			lib_srch.c \
			lib_strdup.c \
			lib_set.c \
			printf_error.c \
			nbr_base.c

FILE_O =	$(FILE_C:%.c=$(OBJS)/%.o)

WRITE_C = fd_lines.c get_next_line.c lib_write.c lib_char.c

SRC_WRITE = $(addprefix $(SRCS)/write/, $(WRITE_C))
OBJ_WRITE = $(patsubst %.c, $(OBJS)/%.o, $(WRITE_C))

MATH_C =	lib_atoi.c lib_atof.c init_coord.c \
			vec_dotcross.c normal_vec.c vec_length.c \
			basic_math.c

SRC_MATH = $(addprefix $(SRCS)/math/, $(MATH_C))
OBJ_MATH = $(patsubst %.c, $(OBJS)/%.o, $(MATH_C))

#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation lib STATUS [OK]$(RESET)\r"

$(NAME) : $(FILE_O) $(OBJ_WRITE) $(OBJ_MATH)
	@ar rc -lm $(NAME) $(FILE_O) $(OBJ_WRITE) $(OBJ_MATH)

$(OBJS)/%.o : %.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(C_B)loading : $(C_W)$< $(C_G)[OK]$(RESET)"

$(OBJS)/%.o : write/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(C_B)loading : $(C_W)$< $(C_G)[OK]$(RESET)"
	
$(OBJS)/%.o : math/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(C_B)loading : $(C_W)$< $(C_G)[OK]$(RESET)"

clean :
	@$(RM) $(OBJS)
	@echo "$(C_W)FILE '*.o' in $(C_R)LIB deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(C_W)Extension $(C_R)$(NAME) deleted$(RESET)"

re : fclean all
