# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 02:01:52 by eturiot           #+#    #+#              #
#    Updated: 2024/05/29 13:38:51 by eturiot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 Variables                                    #
################################################################################


AUTHOR		= rihoy && eturiot

DATE		= $(shell date +%d/%m/%Y)

NAME		= miniRT

NAME_BONUS	=


###########################################
#                  Config                 #
###########################################


CC					= gcc

CFLAGS 				= -Wall -Wextra -Werror

DEPFLAGS			= -MMD -MF

FILES_EXTENSION		= .c

RM 					= rm -rf


###########################################
#                  Libft                  #
###########################################


LIBFT_DIR			= $(LIBS_DIR)/libft

LIBFT				= $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_INC			= $(addprefix $(LIBFT_DIR)/, $(INC_DIR))

LIBS				= ft


###########################################
#				  Minilibx 				  #
###########################################


MLX_DIR		= $(LIBS_DIR)/minilibx-linux

MLX			= $(addprefix $(MLX_DIR)/, libmlx_Linux.a)

MLX_LIB		= mlx_Linux

MLX_LIBS	= -lXext -lX11


###########################################
#              Optional Flags             #
###########################################


DEBUG_FLAGS		= -g3

FAST_FLAGS		= -O2 -DNDEBUG

VALGRIND_FLAGS	= --leak-check=full 	\
				  --show-leak-kinds=all \
				  --track-origins=yes 	\
				  -s


###########################################
#               Directories               #
###########################################


INC_DIR			= incs

INC_DIR_BONUS	= incs_bonus

LIBS_DIR		= libs

OBJ_DIR			= objs

SRC_DIR			= srcs

SRC_DIR_BONUS	= srcs_bonus


###########################################
#            Sources && Objects           #
###########################################


MAIN			= main.c

SRC				= extractor.c					\
				  parsing.c

MAIN_BONUS		=

SRC_BONUS		=

OBJ_FILE		= $(MAIN:.c=.o)					\
				  $(SRC:.c=.o)

OBJ				= $(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

OBJ_FILE_BONUS	= $(MAIN_BONUS:.c=.o)			\
			  	  $(SRC_BONUS:.c=.o)

OBJ_BONUS		= $(addprefix $(OBJ_DIR)/, $(OBJ_FILE_BONUS))


###########################################
#               Dependencies              #
###########################################


DEP_DIR			= $(OBJ_DIR)/.dep

DEP_FILE		= $(OBJ_FILE:.o=.d)

DEP_FILE_BONUS	= $(OBJ_FILE_BONUS:.o=.d)

DEP				= $(addprefix $(DEP_DIR)/, $(DEP_FILE))			\
				  $(addprefix $(DEP_DIR)/, $(DEP_FILE_BONUS))


###########################################
#                Temp Files               #
###########################################


COMPILATION_ERROR	= makefile_compilation_error.log

ERROR_LOG			= makefile_error.log


###########################################
#               Colors ANSI               #
###########################################


BLUE 			= \033[0;34m
LIGHT_BLUE 		= \033[1;34m
BRIGHT_BLUE 	= \033[1;96m
CYAN 			= \033[0;36m

GREEN 			= \033[0;32m
LIGHT_GREEN 	= \033[1;92m

RED 			= \033[0;31m

YELLOW			= \033[0;33m

NC 				= \033[0m


################################################################################
#                                     Rules                                    #
################################################################################


all: $(NAME)

bonus: $(NAME_BONUS) 

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo "$(LIGHT_BLUE)Linking   $(BRIGHT_BLUE)$(NAME)$(LIGHT_BLUE)$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -l $(MLX_LIB) $(MLX_LIBS)								\
	-L $(MLX_DIR) -l $(LIBS) -L $(LIBFT_DIR) 2> $(ERROR_LOG) &&									\
		echo "\n$(GREEN)Linking Successful !!!$(NC)" ||					 						\
		(echo "$(RED)Linking Failure...$(NC)" && cat $(ERROR_LOG) 1>&2)
	@$(RM) $(ERROR_LOG)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJ_BONUS)
	@echo "$(LIGHT_BLUE)Linking   $(BRIGHT_BLUE)$(NAME_BONUS)$(LIGHT_BLUE)$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -l $(MLX_LIB) $(MLX_LIBS)					\
	-L $(MLX_DIR) -l $(LIBS) -L $(LIBFT_DIR) 2> $(ERROR_LOG) &&									\
		echo "\n$(GREEN)Linking Successful !!!$(NC)" ||					 						\
		(echo "$(RED)Linking Failure...$(NC)" && cat $(ERROR_LOG) 1>&2)
	@$(RM) $(ERROR_LOG)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%$(FILES_EXTENSION) | $(OBJ_DIR) $(DEP_DIR)
	@echo -n "$(LIGHT_BLUE)Compiling$(NC)"
	@echo -n " $(BRIGHT_BLUE)$<$(LIGHT_BLUE) --> $(BRIGHT_BLUE)$@$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(DEP_DIR)/$*.d -c $< -o $@									\
	-I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_DIR) 2> $(COMPILATION_ERROR) && 						\
		echo " $(LIGHT_GREEN)[OK]$(NC)"															\
		|| (echo -n " $(RED)[KO]$(NC)\n" && cat $(COMPILATION_ERROR) 1>&2)
	@$(RM) $(COMPILATION_ERROR)

$(OBJ_DIR)/%.o: $(SRC_DIR_BONUS)/%$(FILES_EXTENSION) | $(OBJ_DIR) $(DEP_DIR)
	@echo -n "$(LIGHT_BLUE)Compiling$(NC)"
	@echo -n " $(BRIGHT_BLUE)$<$(LIGHT_BLUE) --> $(BRIGHT_BLUE)$@$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(DEP_DIR)/$*.d -c $< -o $@									\
	-I $(INC_DIR_BONUS) -I $(LIBFT_INC) -I $(MLX_DIR) 2> $(COMPILATION_ERROR) && 				\
		echo " $(LIGHT_GREEN)[OK]$(NC)"															\
		|| (echo -n " $(RED)[KO]$(NC)\n" && cat $(COMPILATION_ERROR) 1>&2)
	@$(RM) $(COMPILATION_ERROR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR) CFLAGS='$(CFLAGS)' --silent

$(MLX):
	@make -C $(MLX_DIR) --silent

miniclean:
	@if [ -d $(OBJ_DIR) ]; then 																\
		echo "$(LIGHT_BLUE)Cleaning  $(BRIGHT_BLUE)$(OBJ_DIR)/$(NC)"; 							\
		$(RM) $(OBJ_DIR); 																		\
	fi

clean: miniclean
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent

fclean: miniclean
	@make fclean -C $(LIBFT_DIR) --silent
	@make fclean -C $(MLX_DIR) --silent
	@if [ -f $(NAME) ]; then 																	\
		echo "$(LIGHT_BLUE)Cleaning  $(BRIGHT_BLUE)$(NAME)$(NC)"; 								\
		$(RM) $(NAME);																			\
	fi
	@if [ -f $(NAME_BONUS) ]; then 																\
		echo "$(LIGHT_BLUE)Cleaning  $(BRIGHT_BLUE)$(NAME_BONUS)$(NC)";							\
		$(RM) $(NAME_BONUS);																	\
	fi

re: header fclean all

header:
	@printf "%b" "$(GREEN)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___|"
	@echo
	@printf "%b" "$(CYAN)Name:\t$(YELLOW)$(NAME)$(NC)\n"
	@printf "%b" "$(CYAN)Author:\t$(YELLOW)$(AUTHOR)$(NC)\n"
	@printf "%b" "$(CYAN)Date:\t$(YELLOW)$(DATE)$(NC)\n"
	@printf "%b" "$(CYAN)CC:\t\t$(YELLOW)$(CC)$(NC)\n"
	@printf "%b" "$(CYAN)Flags:\t$(YELLOW)$(CFLAGS)\n$(NC)"
	@echo

debug: CFLAGS += $(DEBUG_FLAGS)
debug: header miniclean all
	@echo -n "\n$(LIGHT_BLUE)valgrind $(BLUE)$(VALGRIND_FLAGS)$(NC)"
	@echo " $(CYAN)./$(BRIGHT_BLUE)$(NAME)$(NC)"

DEBUG: CFLAGS += $(DEBUG_FLAGS)
DEBUG: re
	@echo -n "\n$(LIGHT_BLUE)valgrind $(BLUE)$(VALGRIND_FLAGS)$(NC)"
	@echo " $(CYAN)./$(BRIGHT_BLUE)$(NAME)$(NC)"

debug_bonus: CFLAGS += $(DEBUG_FLAGS)
debug_bonus: header miniclean bonus
	@echo -n "\n$(LIGHT_BLUE)valgrind $(BLUE)$(VALGRIND_FLAGS)$(NC)"
	@echo " $(CYAN)./$(BRIGHT_BLUE)$(NAME_BONUS)$(NC)"

DEBUG_bonus: CFLAGS += $(DEBUG_FLAGS)
DEBUG_bonus: header fclean bonus
	@echo -n "\n$(LIGHT_BLUE)valgrind $(BLUE)$(VALGRIND_FLAGS)$(NC)"
	@echo " $(CYAN)./$(BRIGHT_BLUE)$(NAME_BONUS)$(NC)"

fast: CFLAGS += $(FAST_FLAGS)
fast: re 

fast_bonus: CFLAGS += $(FAST_FLAGS)
fast_bonus: header fclean bonus 

libft:
	@echo "$(BLUE)Entering directory $(CYAN)$(LIBFT)$(NC)"
	@make -C $(LIBFT_DIR) CFLAGS='$(CFLAGS)' | sed '1d;$$d'
	@echo "$(BLUE)Leaving directory $(CYAN)$(LIBFT)$(NC)"

.PHONY: all 				\
		bonus				\
		clean 				\
		fclean				\
		re					\
		fast				\
		fast_bonus			\
		debug				\
		DEBUG				\
		debug_bonus			\
		DEBUG_bonus			\
		header				\
		libft				\
		miniclean
