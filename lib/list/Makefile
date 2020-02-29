##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## My lib makefile
##

# ========================= VAR ========================= #

NAME = list

SRC = list_remove.c \
	list_clone.c \
	list_get.c \
	list_contain.c \
	list_index_of.c \
	list_set.c \
	list_count.c \
	list_sub_list.c \
	list_add.c \
	list_remove_range.c \
	list.c \
	list_stat.c \
	list_destructor.c \
	list_reverse.c \
	list_to_array.c
$(eval SRC = $(addprefix src/, $(SRC)))


HNAME = list.h
$(eval HNAME = $(addprefix include/, $(notdir $(HNAME))))

CFLAGS = -Wall -Wextra

IFLAGS = -I./include -I./include/private

OTHER_FLAGS =

# ======================================================= #

## echo
ECHO = echo -e

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
ERROR_COLOR = \x1b[31;01m
WARN_COLOR = \x1b[33;01m

OK_STRING = $(OK_COLOR)[✔]$(NO_COLOR)
ERROR_STRING = $(ERROR_COLOR)[X]$(NO_COLOR)
WARN_STRING = $(WARN_COLOR)[!]$(NO_COLOR)

## shell
CC = gcc -fdiagnostics-color=always
RM = rm -f

## lib vars
LIBNAME = lib$(NAME).a
LIB_DEST = ../$(LIBNAME)
H_DEST = ../../include/$(NAME)/
HNAME_DEST = $(addprefix $(H_DEST), $(notdir $(HNAME)))

## obj
OBJ = $(SRC:.c=.o)

## build
BUILD_WARN_LOG = build_warn.log
BUILD_ERROR_LOG = build_error.log
LOGS = $(BUILD_WARN_LOG) $(BUILD_ERROR_LOG)

## rules
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) $(OTHER_FLAGS) -c $< -o $@ 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(MAKE) -s check_error

check_error:
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
	fi

put_libh:
	@mv $(LIBNAME) $(LIB_DEST)
	@mkdir -p $(H_DEST)
	@cp $(HNAME) $(H_DEST)

$(NAME): $(OBJ)
	@ar rc $(LIBNAME) $(OBJ) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@$(MAKE) -s put_libh

clean:
	@$(RM) $(OBJ)
	@$(RM) $(LOGS)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

fclean:
	@$(MAKE) clean > /dev/null
	@$(RM) $(LIB_DEST) $(HNAME_DEST)
	@$(RM) -r $(H_DEST)
	@$(RM) $(NAME)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

re: fclean all

define print_build_status
	@if [ -e $(BUILD_ERROR_LOG) ] && [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(ERROR_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(ERROR_STRING) $(NAME) -> $1"; \
		$(RM) $(BUILD_ERROR_LOG); \
	elif [ -s $(BUILD_WARN_LOG) ]; then \
		$(ECHO) -n "$(WARN_STRING) "; \
		cat $(BUILD_WARN_LOG); \
		$(ECHO) "$(WARN_STRING) $(NAME) -> $1"; \
	else \
		$(ECHO) "$(OK_STRING) $(NAME) -> $1"; \
	fi
endef

.PHONY: $(NAME) all clean fclean re