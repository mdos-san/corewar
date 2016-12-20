#include "corewar.h"

int main(int ac, char **av)
{
	t_cw	cw;

	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw.ac = ac;
	cw.av = av;
	bytecode_read(&cw);
	board_print(cw);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}