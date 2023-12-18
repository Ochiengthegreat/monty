#ifndef _MAIN_H_
#define _MAIN_H_
/* System Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line cnt
 * @arg: value
 * @file: pointer to monty file
 * @cnt: line cnt
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *cnt;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *cnt);
void fq_push(stack_t **head, unsigned int number);
void fq_pall(stack_t **head, unsigned int number);
void fq_pint(stack_t **head, unsigned int number);
int execute(char *cnt, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void fq_pop(stack_t **head, unsigned int count);
void fq_swap(stack_t **head, unsigned int count);
void fq_add(stack_t **head, unsigned int count);
void fq_nop(stack_t **head, unsigned int count);
void fq_sub(stack_t **head, unsigned int count);
void fq_div(stack_t **head, unsigned int count);
void fq_mul(stack_t **head, unsigned int count);
void fq_mod(stack_t **head, unsigned int count);
void fq_pchar(stack_t **head, unsigned int count);
void fq_pstr(stack_t **head, unsigned int count);
void fq_rotl(stack_t **head, unsigned int count);
void fq_rotr(stack_t **head, __attribute__((unused)) unsigned int count);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void fq_queue(stack_t **head, unsigned int count);
void fq_stack(stack_t **head, unsigned int count);
#endif /* _MAIN_H_ */