#include "corewar.h"

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static int	parse_error(t_cw *cw, char *s)
{
	if (cw->f_v)
		endwin();
	ft_printf("ERROR: %s", s);
	ft_putchar('\n');
	exit(0);
}

static int	parse_get_number_player(t_cw *cw, int *nb)
{
	char	**av;
	int		i;
	int		nb_player;
	int		fd_test;

	av = cw->av;
	i = 1;
	nb_player = 0;
	while (i < cw->ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (i + 1 < cw->ac && str_is_digit(av[i + 1]))
				cw->f_dump = ft_atoi(av[i + 1]);
			else
				parse_error(cw, "-dump value is missing.");
			++i;
		}
		else if (ft_strcmp(av[i], "-n") == 0)
		{
			if (i + 1 < cw->ac && str_is_digit(av[i + 1]) && nb_player < 4)
				nb[nb_player] = ft_atoi(av[i + 1]);
			else
				parse_error(cw, (nb_player < 4) ? "-n value is missing." : "too many -n args");
			++i;
		}
		else if (ft_strcmp(av[i], "-v") == 0)
		{}
		else
		{
			if (nb_player < 4)
			{
				cw->champs[nb_player].path = ft_strdup(av[i]);
				fd_test = open(av[i], O_RDONLY);
				if (fd_test == -1)
					parse_error(cw, av[i]);
				close(fd_test);	
			}
			++nb_player;
		}
		++i;
	}
	return (nb_player);
}

void	cw_parse(t_cw *cw)
{
	int		nb_player;
	int		i;
	int		nb[4];

	nb[0] = 1;
	nb[1] = 2;
	nb[2] = 3;
	nb[3] = 4;
	nb_player = parse_get_number_player(cw, nb);
	if (nb_player > 4 || nb_player < 1)
		parse_error(cw, "Bad number of player.");
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < nb_player)
	{
		ft_printf("* Player %d, ", nb[i]);
		bytecode_read(cw, cw->champs[i].path, (MEM_SIZE / nb_player) * i, i + 1);
		process_new(&cw->process, nb[i], (MEM_SIZE / nb_player) * i, i + 1);
		ft_printf("\n");
		++i;
	}
}
