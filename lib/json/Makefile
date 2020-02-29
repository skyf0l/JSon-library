##
## EPITECH PROJECT, 2020
## MAKEFILE
## File description:
## My lib makefile
##

# ========================= VAR ========================= #

NAME = json

SRC = $(shell find src/ -name *.c)
#$(eval SRC = $(addprefix src/, $(SRC)))

HNAME = json.h
$(eval HNAME = $(addprefix include/, $(HNAME)))

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
	@mkdir -p ../../include
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