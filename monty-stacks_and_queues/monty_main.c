#include "monty.h"

stack_t *stack = NULL;

/**
 * is_opcode - checks potential opcode against valid opcodes
 * @opcode: string - potential opcode
 * @arg: string - potential opcode argument
 * @line: the line number
 * Return: Nothing
 */
int is_opcode(char *opcode, char *arg, int line)
{
	int i = 0, j, len;
	/* valid opcodes is an array of type instruction_t */
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	/* check potential against valid opcodes */
	for (; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{/* call the relevant function */
			if (strcmp(opcode, "push") == 0)
			{/*check that the has some length & is a number */
				len = (int)strlen(arg);
				printf("arg len: %d\n", len);
				if (!len)
				{
					dprintf(2, "L%d: usage: push integer\n", line);
					       	exit(EXIT_FAILURE);
				}
				for (j = 0; j < len; j++)
				{
					printf("arg isdigit: %s\n", isdigit(arg[j]) ? "true" : "false");
					if (!isdigit(arg[j]))
					{
						dprintf(2, "L%d: usage: push integer\n", line);
					       	exit(EXIT_FAILURE);
					}
				}
				printf("outside the loop\n");
				opcodes[i].f(&stack, (unsigned int)atoi(arg));
			}
			else
				opcodes[i].f(&stack, (unsigned int)line);
			return (1);
		}
	}
	printf("instruction NOT a valid opcode!\n");
	return (0);
}

/**
 * valid_instruction - checks if a line is a valid opcode instruction
 * @line: string
 * @line_no: number of the line to be evaluated
 * Return: Nothing
 */
int valid_instruction(char *line, int line_no)
{
	int i = 0, j = 0;
	char opcode[50], arg[50];

	/*line can start and / end with spaces or chars*/
	for (; line[i] != '\0'; i++)
	{
		/*we only check first word we encounter - the potential opcode*/
		while(line[i] == ' ')
			i++;
		if (isalpha(line[i]))
		{
			while (line[i] != ' ' && line[i])
				opcode[j++] = line[i++];
		}
		opcode[j] = '\0';
		printf("potential opcode: %s\n", opcode);
		/* arg - opcode's potential arg is the next alnum right after(spaces) */
		while(line[i] == ' ')
			i++;
		if (isalnum(line[i]))
		{
			j = 0;
			while (line[i] != ' ' && line[i])
				arg[j++] = line[i++];
		}
		arg[j] = '\0';
		printf("potential arg: %s\n", arg);
		/*now check if the potential opcode is valid*/
		return (is_opcode(opcode, arg, line_no));
		/*if valid, execute - by calling its function & return */
	}
	printf("Empty line!\n");
	return (0);
}

/**
 * analyze_file_contents - check the opcodes in file
 * Description: checks a line at a time for valid instructions
 * and keeps track of line count
 * @str: a string, the contents of file
 * Return: the number of lines?
 */
int analyze_file_contents(char *str)
{
	int i = 0, j = 0, lines = 0, valid = 0;
	char line[BUFFER];

	/*read a line at a time  check for next '\n' in str*/
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			/* check if line is a valid instruction */
			line[j++] = '\0'; /* terminate line */
			lines++;
			printf("new line: %s\n", line);
			/*lines will be the line we are currently at */
			valid = valid_instruction(line, lines);
			printf("line: %s is %s!\n", line, valid ? "valid" : "not valid");
			j = 0; /*start a new line*/
		}
		else
			line[j++] = str[i];
	}
	return (lines);
}

/**
 * main - project entry point
 * @ac: command line args counts
 * @av: pointer to command line args array
 * Return: Nothing (use exit & exit_status)
 */
void main(int ac, char **av)
{
	struct stat status;
	size_t len, fd, size;
	int c;
	char *opcode_str;

	/*get a file from the cmd line*/
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*the file contains opcode instructions, one per line*/
	fd = open(av[1], O_RDONLY, 0);/* av[1] is the filename/path */
	if ((int)fd < 0)
	{
		printf("Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/*opcode_str stores the contents of the file as read*/
	if (stat(av[1], &status) == 0)
		size = status.st_size;/*size of file in bytes*/
	opcode_str = malloc(sizeof(char) * (8 * size));
	if (opcode_str == NULL)
		dprintf(2, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	/* read the opcode contents int opcode_str */
	len = read(fd, opcode_str, size);
	if ((long)len < 0)
		dprintf(2, "Error: can't read file\n"), exit(EXIT_FAILURE);
	c = close(fd);
	if (c < 0)
		dprintf(2, "Error: can't close file\n"), exit(EXIT_FAILURE);
	/*each instruction will have a matching fn to interpret it*/
	/*analyse the contents of the opcode_str, line by line */
	printf("opcode_str: %s\n", opcode_str);
	analyze_file_contents(opcode_str);
	/*thus: have an array of accepted opcode and its fn - instruction_t type*/
}

