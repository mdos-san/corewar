#include "corewar.h"


int	str_match_end(char *str, char *template)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (template[j])
		++j;
	while (str[i])
		++i;
	if (j > i)
		return (0);
	while (j >= 0)
	{
		if (template[j] != str[i])
			return (0);
		--j;
		--i;
	}
	return (1);
}

static int	parse_error()
{
	ft_printf("ERROR: Parsing.");
	exit(0);
}

static int	parse_get_number_player(t_cw *cw)
{
	char	**av;
	int		i;
	int		nb_player;

	av = cw->av;
	i = 0;
	nb_player = 0;
	while (av[i])
	{
		if (str_match_end(av[i], ".cor"))
			++nb_player;
		++i;
	}
	return (nb_player);
}

void	cw_parse(t_cw *cw)
{
	int	nb_player;
	int	i;
	int	j;

	nb_player = parse_get_number_player(cw);
	if (nb_player > 4 || nb_player < 1)
		parse_error();
	i = 0;
	j = 0;
	while (i < nb_player && cw->av[j])
	{
		if (str_match_end(cw->av[j], ".cor"))
		{
			bytecode_read(cw, cw->av[j], (MEM_SIZE / nb_player) * i);
			process_add(cw, - (i + 1), (MEM_SIZE / nb_player) * i);
			++i;
		}
		++j;	
	}
}

/*
	bytecode_read(&cw, av[1], 0);
	process_add(&cw, -1, 0);
	bytecode_read(&cw, av[2], MEM_SIZE / 3);
	process_add(&cw, -2, MEM_SIZE / 3);
	bytecode_read(&cw, av[3], (MEM_SIZE / 3) * 2);
	process_add(&cw, -3, (MEM_SIZE / 3) * 2);
*/
