#include "corewar.h"

int main(void)
{
	t_cw	cw;

	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	board_print(cw);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}