##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

MLX			= minilibx-linux

RM 			= rm -rf

OBJ_DIR		= obj

TEST		= test/main.o

BLUE 		= \033[0;34m
CYAN 		= \033[0;36m
NC 			= \033[0m

all	: do_configure

do_configure	:
	./configure

clean:
	@if [ -d $(OBJ_DIR) ]; then 												\
		echo "$(BLUE)Cleaning  $(CYAN)$(MLX)$(OBJ_DIR)/$(NC)"; 					\
		$(RM) $(OBJ_DIR); 														\
	fi
	@if [ -d $(TEST) ]; then 													\
		echo "$(BLUE)Cleaning  $(CYAN)$(MLX)/$(TEST)$(NC)"; 					\
		$(RM) $(OBJ_DIR); 														\
	fi

fclean	:
	./configure clean

re	: clean fclean all
