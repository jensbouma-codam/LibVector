NAME	= libvector.a
GCC 	:= gcc
CFLAGS	:= -Wall -Werror -Wextra

INCLUDE	=	-I ./include
SRCDIR	=	./src
BUILD	=	./build


SRC		= 	vector.c		\
	  		vector_get.c	\
			vector_set.c	\

SOURCES	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJECTS = 	$(addprefix $(BUILD)/, $(SRC:.c=.o))

all: $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Compiled $^"

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $^


$(BUILD)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILD)
	@$(GCC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@printf "\033[0m[ ✔ ] %s\n\033[0m" "$<"

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re