#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>

#define ps(x) (printf("%s\n", (x)))
#define pd(x) (printf("%d\n", (x)))
#define plu(x) (printf("%lu", (x)))

/* text output colors */
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"


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
/* extern declarations of instances of the opcode structs */
extern instruction_t push_st;
extern instruction_t pall_st;

typedef void (*opfunc)(stack_t **, unsigned int); /* opfunc now refers to this type */


/**
 * struct oplist_s - opcode instructions list
 * opstruct: pointer to an instruction_t struct for an opcode
 * @prev: points to the previous list item
 * @next: points to the next list item
 *
 * Description: doubly-linked list of instruction_t structures
 * to enable efficient searching of the right opcode function to call.
 */
typedef struct oplist_s
{
	instruction_t *opstruct;
	struct oplist_s *prev;
	struct oplist_s *next;
} oplist_t;

/* extern declarations */
extern int linenum; /* for storing file line number count */
extern oplist_t *oplist; /* head of opcode instructions list */
extern stack_t *stack_top; /* head of program stack */
extern char **instruct_arr; /* for containing the list of instruction tokens*/
extern char *linebuff; /* stores lines of instructions from the monty file */


/* helper functions */
void handle_realloc(
		char ***str_ar, int i, int bsize, int *old_bsize, int *bsize_total);
void *realloc3(void *ptr, unsigned int old_size, unsigned int new_size);
char **str_arr(char *str, const char *delim);
size_t stack_len(const stack_t *stk_top);
char *_memset(char *s, char b, unsigned int n);
void _memncpy(void *dest, void *src, unsigned int n);
opfunc find_opfunc(char *opstr);
void perform_op(char *instruct_arr[]);
void init_opstruct(void);
void bld_oplist(oplist_t **oplist);
void free_stack(stack_t *stk_top);
void free_oplist(oplist_t *oplist);



/* instruction function prototypes */
void push(stack_t **stk_top, unsigned int n);
void pall(stack_t **stk_top, unsigned int n);
void pint(stack_t **stk_top, unsigned int n);
void pop(stack_t **stk_top, unsigned int n);
void swap(stack_t **stk_top, unsigned int n);
void add(stack_t **stk_top, unsigned int n);
void nop(stack_t **stk_top, unsigned int n);



#endif
