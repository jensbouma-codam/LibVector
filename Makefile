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
	@make norm 2> /dev/null && printf "\033[32m[ ✔ ] %s\n\033[0m" "Norm OK" && printf "\n🙏 \033[32mComplete\033[0m\n" || "\033[31m[ ✘ ] %s\n\033[0m" "Norm KO"

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $^


$(BUILD)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILD)
	@$(GCC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@printf "\033[0m[ ✔ ] %s\n\033[0m" "$<"

norm: $(SOURCES)
ifneq ($(UNAME_S),Linux)
	@norminette -R CheckForbiddenSourceHeader $^ include 2>&1 > /dev/null && exit 0 || exit 1
else
	@echo "Norminette not available on this machine" && exit 0
endif

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re