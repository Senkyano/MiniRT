# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 19:55:55 by eturiot           #+#    #+#              #
#    Updated: 2023/11/04 18:05:30 by eturiot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#                                   Variables                                  #
################################################################################


NAME 				= libft.a

CC					= gcc

CFLAGS 				= -Wall -Wextra -Werror

DEPFLAGS			= -MMD -MF

FILES_EXTENSION		= .c

RM 					= rm -rf

ERROR_LOG			= makefile_error.log
COMPILATION_ERROR	= makefile_compilation_error.log


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


###########################################
#               Directories               #
###########################################


INC_DIR		= incs

OBJ_DIR		= objs

SRC_DIR		= srcs

LIBFT		= libft/

GNL_DIR		= gnl/

PRINTF_DIR	= ft_printf/


###########################################
#            Sources && Object            #
###########################################


SRC_LIBFT	= ft_atoi.c 								\
			  ft_bzero.c 								\
			  ft_calloc.c 								\
			  ft_isalnum.c 								\
			  ft_isalpha.c 								\
			  ft_isascii.c 								\
			  ft_isdigit.c 								\
			  ft_isprint.c		 						\
			  ft_itoa.c 								\
			  ft_memchr.c 								\
			  ft_memcpy.c	 							\
			  ft_memcmp.c 								\
			  ft_memmove.c 								\
			  ft_memset.c 								\
			  ft_putchar_fd.c 							\
			  ft_putendl_fd.c 							\
			  ft_putnbr_fd.c			 				\
			  ft_putstr_fd.c	 						\
			  ft_split.c 								\
			  ft_strchr.c 								\
			  ft_strdup.c 								\
			  ft_striteri.c	 							\
			  ft_strjoin.c 								\
			  ft_strlcpy.c 								\
			  ft_strlcat.c	 							\
			  ft_strlen.c 								\
			  ft_strmapi.c 								\
			  ft_strncmp.c 								\
			  ft_strnstr.c 								\
			  ft_strrchr.c 								\
			  ft_strtrim.c 								\
			  ft_substr.c 								\
			  ft_tolower.c	 							\
			  ft_toupper.c

SRC_BONUS	= ft_lstadd_back.c							\
			  ft_lstadd_front.c							\
			  ft_lstclear.c								\
			  ft_lstdelone.c							\
			  ft_lstiter.c								\
			  ft_lstlast.c								\
			  ft_lstmap.c								\
			  ft_lstnew.c								\
			  ft_lstsize.c

SRC_GNL		= get_next_line.c							\
			  gnl_utils.c

SRC_PRINTF	= ft_printf.c 								\
			  ft_printf_hexa.c 							\
			  ft_printf_utils.c

SRC_FILE	= $(addprefix $(LIBFT), $(SRC_LIBFT))		\
			  $(addprefix $(LIBFT), $(SRC_BONUS))		\
			  $(addprefix $(GNL), $(SRC_GNL))			\
			  $(addprefix $(PRINTF), $(SRC_PRINTF))

OBJ_FILE	= $(SRC_LIBFT:.c=.o)						\
			  $(SRC_BONUS:.c=.o)						\
			  $(SRC_GNL:.c=.o)							\
			  $(SRC_PRINTF:.c=.o)

OBJ			= $(addprefix $(OBJ_DIR)/, $(OBJ_FILE))


###########################################
#               Dependencies              #
###########################################


DEP_DIR			= $(OBJ_DIR)/.dep

DEP_FILE		= $(OBJ_FILE:.o=.d)

DEP				= $(addprefix $(DEP_DIR)/, $(DEP_FILE))	


################################################################################
#                                     Rules                                    #
################################################################################


all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "$(BLUE)Linking   $(CYAN)$(LIBFT)$(NAME)$(NC)"
	@ar rc $(NAME) $(OBJ) 2> $(ERROR_LOG) &&											\
		{ echo "\t$(GREEN)Done$(NC)" && ranlib $(NAME); } || 							\
		(echo "\t$(RED)Failure$(NC)" && cat $(ERROR_LOG) 1>&2)
	@$(RM) $(ERROR_LOG)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(LIBFT)%$(FILES_EXTENSION) | $(OBJ_DIR) $(DEP_DIR)
	@echo -n "$(BLUE)Compiling$(NC)"
	@echo -n " $(CYAN)$(LIBFT)$<$(BLUE) -> $(CYAN)$(LIBFT)$@$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(DEP_DIR)/$*.d -c $< -o $@ 							\
	-I $(INC_DIR) 2> $(COMPILATION_ERROR) &&											\
		echo " $(GREEN)[OK]$(NC)" || 													\
		(echo -n " $(RED)[KO]$(NC)\n" && cat $(COMPILATION_ERROR) 1>&2)
	@$(RM) $(COMPILATION_ERROR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(GNL_DIR)%$(FILES_EXTENSION) | $(OBJ_DIR) $(DEP_DIR)
	@echo -n "$(BLUE)Compiling$(NC)"
	@echo -n " $(CYAN)$(LIBFT)$<$(BLUE) -> $(CYAN)$(LIBFT)$@$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(DEP_DIR)/$*.d -c $< -o $@ 							\
	-I $(INC_DIR) 2> $(COMPILATION_ERROR) &&											\
		echo " $(GREEN)[OK]$(NC)" || 													\
		(echo -n " $(RED)[KO]$(NC)\n" && cat $(COMPILATION_ERROR) 1>&2)
	@$(RM) $(COMPILATION_ERROR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PRINTF_DIR)%$(FILES_EXTENSION) | $(OBJ_DIR) $(DEP_DIR)
	@echo -n "$(BLUE)Compiling$(NC)"
	@echo -n " $(CYAN)$(LIBFT)$<$(BLUE) -> $(CYAN)$(LIBFT)$@$(NC)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(DEP_DIR)/$*.d -c $< -o $@ 							\
	-I $(INC_DIR) 2> $(COMPILATION_ERROR) &&											\
		echo " $(GREEN)[OK]$(NC)" || 													\
		(echo -n " $(RED)[KO]$(NC)\n" && cat $(COMPILATION_ERROR) 1>&2)
	@$(RM) $(COMPILATION_ERROR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then 												\
		echo "$(BLUE)Cleaning  $(CYAN)$(LIBFT)$(OBJ_DIR)/$(NC)"; 				\
		$(RM) $(OBJ_DIR); 														\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then 													\
		echo "$(BLUE)Cleaning  $(CYAN)$(LIBFT)$(NAME)$(NC)";	 				\
		$(RM) $(NAME);															\
	fi

re: fclean all

.PHONY: all 		\
		clean 		\
		fclean 		\
		re
