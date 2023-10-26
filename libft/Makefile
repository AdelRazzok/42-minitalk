NAME      = libft.a
INCLUDES  = include/
SRC_DIR   = src/
OBJ_DIR   = obj/

CC        = gcc
C_FLAGS  = -Wall -Werror -Wextra -I
AR        = ar rcs

FTIS_DIR  = ft_is/
FTIS      = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR = ft_mem/
FTMEM     = ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

FTPUT_DIR = ft_put/
FTPUT     = ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR  = ft_to/
FTTO      = ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR = ft_str/
FTSTR     = ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr

FTLST_DIR = ft_lst/
FTLST     = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPTF_DIR = ft_printf/
FTPTF     = ft_print_char ft_print_hexa ft_print_nbr ft_print_ptr ft_print_str ft_print_uint ft_printf

FTGNL_DIR = ft_gnl/
FTGNL     = get_next_line.c get_next_line_utils.c

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(FTPTF_DIR),$(FTPTF))

SRC       = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ       = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE = .cache_exists

#####

all: $(NAME)

$(NAME):		$(OBJ)
					@$(AR) $(NAME) $(OBJ)
					@ranlib $(NAME)
					@echo "Libft compiled!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(FTIS_DIR)
					@mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
					@mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
					@mkdir -p $(OBJ_DIR)$(FTTO_DIR)
					@mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
					@mkdir -p $(OBJ_DIR)$(FTLST_DIR)
					@mkdir -p $(OBJ_DIR)$(FTPTF_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@rm -f $(OBJ_CACHE)
					@echo "Libft objects files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "Libft executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for libft!"

.PHONY:			all clean fclean re
