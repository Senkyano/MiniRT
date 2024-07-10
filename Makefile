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
FLAGS = -Wall -Werror -Wextra -g -I $(INCLUDES) -I $(UTILS)/includes -I $(MLX_DIR)
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
INIT = initialisation


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

#########################################################################
#							MINI-libx									#
#########################################################################
MLX_DIR		= minilibx-linux

MLX			= $(MLX_DIR)/libmlx_Linux.a

MLX_LIB		= mlx_Linux

MLX_LIBS	= -lXext -lX11


#--------------------------------------#
#		File
#-----------------------#
FILE_C =	main.c \
			extractfile.c \
			display_information.c \

SRC = $(addprefix $(SRCS)/, $(FILE_C))
OBJ = $(patsubst %.c, $(OBJS)/%.o, $(FILE_C))

INIT_C =	init_obj.c \
			init_color.c \
			init_sphere.c \
			init_cylinder.c \
			init_plane.c \
			init_light.c \
			init_cam.c \
			init_ambiant.c \
			list_org.c \
			nearest.c

SRC_INIT = $(addprefix $(SRCS)/$(INIT)/, $(INIT_C))
OBJ_INIT = $(patsubst %.c, $(OBJS)/%.o, $(INIT_C))

CAM_C = ray_cam.c \
		clear_minirt.c \
		color.c

SRC_CAM = $(addprefix $(SRCS)/cam/, $(CAM_C))
OBJ_CAM = $(patsubst %.c, $(OBJS)/%.o, $(CAM_C))

EQ_C =	eq_plane.c \
		eq_sphere.c \
		init_ray.c \
		point_inter.c

SRC_EQ = $(addprefix $(SRCS)/equation/, $(EQ_C))
OBJ_EQ = $(patsubst %.c, $(OBJS)/%.o, $(EQ_C))

#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation $(NAME) STATUS [OK]$(RESET)"

$(NAME) : $(LIB) $(OBJ) $(OBJ_INIT) $(OBJ_CAM) $(OBJ_EQ) $(MLX)
	@$(CC) -lm $(FLAGS) $(MLX_LIBS) -o $(NAME) $(OBJ) $(OBJ_INIT) $(OBJ_CAM) $(MLX) $(MLX_LIBS) $(EXTENSION)

$(MLX) :
	@make -C $(MLX_DIR) --silent

$(LIB) :
	@make -C $(UTILS) --silent

$(OBJS)/%.o : $(SRCS)/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

$(OBJS)/%.o : $(SRCS)/$(INIT)/%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

$(OBJS)/%.o : $(SRCS)/cam/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

$(OBJS)/%.o : $(SRCS)/equation/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@$(EC) "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"


clean :
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR) --silent
	@$(MAKE) clean -C $(UTILS) --silent
	@echo "$(C_R)FILE '*.o' for $(NAME) deleted$(RESET)"

fclean :
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR) --silent
	@$(MAKE) fclean -C $(UTILS) --silent
	@echo "$(C_W)FILE '*.o' for $(C_R)$(NAME) deleted$(RESET)"
	@echo "Projet $(C_R)$(NAME) deleted$(RESET)"

re : fclean all

.PHONY : re clean fclean all