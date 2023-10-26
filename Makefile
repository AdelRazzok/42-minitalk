NAME          = server
NAMECL        = client
NAMEB         = server_bonus
NAMEBCL       = client_bonus
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
OBJ_DIR       = obj/

LIBFT_DIR     = libft/
LIBFT_LIB     = $(LIBFT_DIR)libft.a

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_FILES     = server
SRCCL_FILES   = client

SRCB_FILES    = server_bonus
SRCBCL_FILES  = client_bonus

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRCCL         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCB          = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCB_FILES)))
OBJB          = $(addprefix $(SRC_DIR), $(addsuffix .o, $(SRCB_FILES)))

SRCBCL        = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBCL_FILES)))
OBJBCL        = $(addprefix $(SRC_DIR), $(addsuffix .o, $(SRCBCL_FILES)))

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
					@$(CC) $(CC_FLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

bonus:			$(LIBFT_LIB) allbonus

allbonus:		$(NAMEB) $(NAMEBCL)

$(NAMEB):		$(OBJB)
					$(CC) $(CFLAGS) $(OBJB) $(LIBFT_LIB) -o $(NAMEB)

$(NAMEBCL):     $(OBJBCL)
					$(CC) $(CFLAGS) $(OBJBCL) $(LIBFT_LIB) -o $(NAMEBCL)

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