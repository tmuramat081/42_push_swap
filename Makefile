# Compile variables
NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef FOR_DEBUG
CFLAGS += -g -D FOR_DEBUG
endif

SRCS_DIR := srcs/
SRCS := main.c \
		input_number.c \
		solve_problem.c \
		put_answer.c \
		delete_solver.c \
		debug_utils.c \
		best_first_search/search_routine.c \
		best_first_search/prune.c \
		best_first_search/compare.c \
		best_first_search/hash.c \
		best_first_search/copy_node.c \
		evaluator/evaluator.c \
		evaluator/compute_lics.c \
		evaluator/utils.c \
		checker/checker.c \
		operation/op_push.c \
		operation/op_rev_rotate.c \
		operation/op_rotate.c \
		operation/op_swap.c \
		operation/operations.c
	
OBJS_DIR := objs/
OBJS := ${addprefix ${OBJS_DIR},${SRCS:.c=.o}}
DEPS := ${addprefix ${OBJS_DIR},${SRCS:.c=.d}}

LIBFT_DIR := libs/ft/
LIBFT := ${LIBFT_DIR}libft.a

LIBVECTOR_DIR := libs/vector/
LIBVECTOR := ${LIBVECTOR_DIR}libvector.a

LIBDEQUE_DIR := libs/deque/
LIBDEQUE := ${LIBDEQUE_DIR}libdeque.a

LIBPQUEUE_DIR := libs/priority_queue/
LIBPQUEUE := ${LIBPQUEUE_DIR}libpqueue.a

LIBHASHSET_DIR := libs/hashset/
LIBHASHSET := ${LIBHASHSET_DIR}libhashset.a

INCS := -I./incs/ -I./${LIBFT_DIR}incs/ -I./${LIBDEQUE_DIR}incs/ \
	-I./${LIBVECTOR_DIR}incs/ -I./${LIBPQUEUE_DIR}incs/ -I./${LIBHASHSET_DIR}incs/

# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
MOVE := \033[1F
CR := \033[1G

# Progress variables
SRC_TOT := ${shell expr ${words ${SRCS}} - ${shell ls -l ${OBJS_DIR} | grep .o$ | wc -l} + 1}
ifndef ${SRC_TOT}
	SRC_TOT := ${words ${SRCS}}
endif
SRC_CNT := 0
SRC_PCT = ${shell expr 100 \* ${SRC_CNT} / ${SRC_TOT}}
PROGRESS = ${eval SRC_CNT = ${shell expr ${SRC_CNT} + 1}} \
	${PRINTF} "${DEL}${GREEN}[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}${CR}" \
	$(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

# Main commands
${NAME}: ${LIBFT} ${LIBDEQUE} ${LIBVECTOR} ${LIBPQUEUE} ${LIBHASHSET} ${OBJS}
	@${CC} ${CFLAGS} ${INCS} ${OBJS} ${LIBFT} ${LIBDEQUE} ${LIBVECTOR} ${LIBPQUEUE} ${LIBHASHSET} -o $@
	@echo "\n${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory

${LIBDEQUE}:
	@${MAKE} -C ${LIBDEQUE_DIR} --no-print-directory

${LIBVECTOR}:
	@${MAKE} -C ${LIBVECTOR_DIR} --no-print-directory

${LIBPQUEUE}:
	@${MAKE} -C ${LIBPQUEUE_DIR} --no-print-directory

${LIBHASHSET}:
	@${MAKE} -C ${LIBHASHSET_DIR} --no-print-directory

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAGS} ${INCS} -c $< -o $@

-include ${DEPS}

#: Make executable file.
all: ${NAME}

#: Remove all object files.
clean:
	${RM} ${OBJS} ${DEPS}
	@${MAKE} clean -C ${LIBFT_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBDEQUE_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBVECTOR_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBPQUEUE_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBHASHSET_DIR} --no-print-directory


#: Remove all object and executable files.
fclean:	clean
	${RM} ${NAME}
	${RM} ${LIBFT}
	${RM} ${LIBDEQUE}
	${RM} ${LIBVECTOR}
	${RM} ${LIBPQUEUE}
	${RM} ${LIBHASHSET}

#: Remove and recompile all.
re: fclean
	@${MAKE} -s all

#: [debug] Print debug info.
debug:
	@${MAKE} re FOR_DEBUG=1 --no-print-directory

#: Push to git repository.
git:
	git add .
	git commit
	git push

#: Display all commands.
help:
	@grep -A1 -E "^#:" --color=auto Makefile \
	| grep -v -- -- \
	| sed 'N;s/\n/###/' \
	| sed -n 's/^#: \(.*\)###\(.*\):.*/\2###\1/p' \
	| sed -e 's/^/make /' \
	| column -t -s '###'

.PHONY:
	all clean fclean re debug git help