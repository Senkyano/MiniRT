#   NAME
NAME = miniRT

#---------------#
#	includes
#---------------#
UTILS =		utils
INCLUDES =	includes

#--------------------------------------#
#		Commande
#-----------------------#
RM = rm -fr
CC = cc
FLAGS = -Wall -Werror -Wextra -g -I $(INCLUDES) -I $(UTILS)
EC = echo
# FLAG_READLINE = -lreadline
# FLAG_PHILO = -lpthread -D_REENTRANT
# SANI_MEM = -fsanitize=address -fsanitize=leak -fsanitize=undefined
# SANI = -fsanitize=address -fsanitize=leak -fsanitize=undefined

#--------------------------------------#
#       directory
#-----------------------#
SRCS = srcs
OBJS = objs
INIT = init_info


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

# **************************** #
#     LIB                      #
# **************************** #
LIB = $(UTILS)/lib.a
EXTENSION = $(UTILS)/lib.a

#--------------------------------------#
#		File
#-----------------------#
FILE_C =	main.c \
			extrac_rt.c

SRC = $(addprefix $(SRCS)/, $(FILE_C))
OBJ = $(patsubst %.c, $(OBJS)/%.o, $(FILE_C))

INIT_C =	init_cam.c \
			init_light.c \
			init_obj.c \
			init_coord.c \
			init_color.c \
			init_cylinder.c \
			init_plan.c \
			init_sphere.c \
			init_scene.c

SRC_INIT = $(addprefix $(SRCS)/$(INIT)/, $(INIT_C))
OBJ_INIT = $(patsubst %.c, $(OBJS)/%.o, $(INIT_C))

#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation $(NAME) STATUS [OK]$(RESET)"

$(NAME) : $(LIB) $(OBJ) $(OBJ_INIT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(OBJ_INIT) $(EXTENSION)

$(LIB) :
	@make -C $(UTILS) --silent

$(OBJS)/%.o : $(SRCS)/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

$(OBJS)/%.o : $(SRCS)/$(INIT)/%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

clean :
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(UTILS) --silent
	@echo "$(C_R)FILE '*.o' for $(NAME) deleted$(RESET)"

fclean :
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@$(MAKE) fclean -C $(UTILS) --silent
	@echo "$(C_W)FILE '*.o' for $(C_R)$(NAME) deleted$(RESET)"
	@echo "Projet $(C_R)$(NAME) deleted$(RESET)"

re : fclean all

.PHONY : re clean fclean all