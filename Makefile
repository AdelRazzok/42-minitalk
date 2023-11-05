NAME          = server
NAMECL        = client
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
OBJ_DIR       = obj/

LIBFT_DIR     = libft/
LIBFT_LIB     = $(LIBFT_DIR)libft.a

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_FILES     = server utils
SRCCL_FILES   = client utils

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRCCL         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

OBJ_CACHE     = .cache_exists

#####

all:			$(LIBFT_LIB) $(NAME) $(NAMECL)

$(LIBFT_LIB):
					@make -C $(LIBFT_DIR)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
					@echo "server compiled!"

$(NAMECL):		$(OBJCL)
					$(CC) $(CFLAGS) $(OBJCL) $(LIBFT_LIB) -o $(NAMECL)
					@echo "client compiled!"


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@rm -rf $(OBJCL_DIR)
					@echo "minitalk object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@rm -f $(NAMECL)
					@echo "minitalk executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for minitalk!"

.PHONY:			all clean fclean re
