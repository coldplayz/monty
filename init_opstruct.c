#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * init_opstruct - gives a definition to opcode struct declarations
 */
void init_opstruct(void)
{
	globals.push_st.opcode = "push";
	globals.push_st.f = &push;

	globals.pall_st.opcode = "pall";
	globals.pall_st.f = &pall;

	globals.add_st.opcode = "add";
	globals.add_st.f = &add;
	
	globals.swap_st.opcode = "swap";
	globals.swap_st.f = &swap;
}
