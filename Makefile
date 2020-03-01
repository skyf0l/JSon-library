##
## EPITECH PROJECT, 2020
## MAKEFILE
## File description:
## My makefile
##

# ========================= VAR ========================= #

NAME = json_lib

SRC = $(shell find lib/json/ -name *.c)

TEST_NAME = unit_tests

TESTS_SRC = $(shell find tests/ -name *.c)

LIBS = json list

CFLAGS = -Wall -Wextra

TESTS_FLAGS = -lcriterion --coverage -L. lib/liblist.a

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

## flag
IFLAGS += $(addprefix -I./include/, $(LIBS))
TMP_LFLAGS += $(addsuffix .a, $(addprefix lib/lib, $(LIBS)))
LFLAGS := $(LFLAGS) $(addprefix -L. , $(TMP_LFLAGS))

## tests
TEST_BUILD = *.gcno *.gcda *.gcov

## build
BUILD_WARN_LOG = build_warn.log
BUILD_ERROR_LOG = build_error.log
LOGS = $(BUILD_WARN_LOG) $(BUILD_ERROR_LOG)

## rules
all: $(NAME)

$(NAME): make_lib

make_lib:
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s); \
	done

clean:
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s clean) > /dev/null; \
	done
	@$(RM) $(TESTS_OBJ)
	@$(RM) $(LOGS)
	@$(RM) $(TEST_BUILD)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

fclean:
	@$(MAKE) clean > /dev/null
	@for i in $(LIBS); do \
		(cd lib/$$i/ && make -s fclean) > /dev/null; \
	done
	@$(RM) $(TEST_NAME)
	@$(ECHO) "$(OK_STRING) $(NAME) -> $@"

re: fclean make_lib

tests_run: make_lib
	@$(RM) $(TEST_BUILD) $(TEST_NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(TEST_NAME) $(TESTS_SRC) -L. lib/libjson.a $(TESTS_FLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@./$(TEST_NAME)

coverage: make_lib
	@$(RM) $(TEST_BUILD) $(TEST_NAME)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(TEST_NAME) $(SRC) $(TESTS_SRC) -L. $(TESTS_FLAGS) 2> $(BUILD_WARN_LOG) || touch $(BUILD_ERROR_LOG)
	@$(call print_build_status, $@)
	@./$(TEST_NAME)
	gcovr --exclude tests/

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

.PHONY: all clean fclean re tests_run coverage