# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jensbouma <jensbouma@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/27 02:52:10 by jensbouma     #+#    #+#                  #
#    Updated: 2023/07/28 11:36:33 by jensbouma     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Libary name
NAME	= libvector.a

# Sources
SRC		= 	vector.c		\
			vector_mem.c	\
	  		vector_get.c	\
			vector_set.c	\

# Set directories
SRCDIR	=	./src
BUILD	=	./build

# Compiler settings
GCC 	:= gcc
CFLAGS	:= -Wall -Werror -Wextra

#Dynamic files
SOURCES	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJECTS = 	$(addprefix $(BUILD)/, $(SRC:.c=.o))

INCLUDE	=	-I ./include

all: $(NAME)
	@make norm 2> /dev/null && printf "\n🙏 $(GREEN)All Done$(RESET)\n" || (printf "\n$(RED)Norminette KO$(RESET)\n" && exit 1)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $^
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Compiled $@"

$(BUILD)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILD)
	@$(GCC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@printf "\033[0m[ ✔ ] %s\n\033[0m" "$<"

norm: $(SOURCES)
	@norminette -R CheckForbiddenSourceHeader $^ include 2>&1 > /dev/null && exit 0 || exit 1

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re