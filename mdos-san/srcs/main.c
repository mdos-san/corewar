#include "corewar.h"

int main(int ac, char **av)
{
	t_cw	cw;

	cw.debug = DEBUG;
	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw.ac = ac;
	cw.av = av;
	cw.process = NULL;
	bytecode_read(&cw);
	process_add(&cw, 1, 0);
	board_print(cw);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}