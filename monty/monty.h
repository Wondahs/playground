#ifndef LISTS_H
#define LISTS_H

#define MAX_LINES 1024
#define MAX_ARGS 2

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct commands
{
	char *lines[MAX_LINES];
	char buffer[MAX_LINES];
	int line_count;
	char *args[MAX_ARGS];
	int num;
} cmd_t;

extern cmd_t *cmds;

void read_code(char *argv_1);
char *rmv_space(char *cmd);
void parse(cmd_t *cmds);
void executer(void);
void free_all(stack_t *stack);
void free_stack(stack_t *stack);
void check_op(stack_t **stack, int line_number);
void tokenizer(int i);
char *_strdup(char *s);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /* LISTS_H */
