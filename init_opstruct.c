#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * init_opstruct - gives a definition to opcode struct declarations
 */
void init_opstruct(void)
{
	push_st.opcode = "push";
	push_st.f = &push;

	pall_st.opcode = "pall";
	pall_st.f = &pall;
}
