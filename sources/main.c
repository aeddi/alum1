/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:16:28 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 20:37:14 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance4.h>
#include <errno.h>
#include <string.h>
#include <time.h>

static t_bool	set_difficulty(int ac, char **av, t_grid *grid)
{
	if (ac == 3)
		grid->level = MEDIUM;
	else if (ft_strcmp("easy", av[3]) == 0)
		grid->level = EASY;
	else if (ft_strcmp("medium", av[3]) == 0)
		grid->level = MEDIUM;
	else if (ft_strcmp("hard", av[3]) == 0)
		grid->level = HARD;
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	init_grid(int ac, char **av, t_grid *grid)
{
	if (ac < 3 || ac > 4)
	{
		if (ac < 3)
			ft_putendl("Error : Too few arguments");
		if (ac > 4)
			ft_putendl("Error : Too many arguments");
		ft_putendl("Usage : ./puissance4 line(6+) col(7+) [easy|medium|hard]");
		return (FALSE);
	}
	grid->line = ft_atoi(av[1]);
	grid->column = ft_atoi(av[2]);
	if (grid->line < 6 || grid->column < 7 || set_difficulty(ac, av, grid))
	{
		ft_putendl("Error : Wrong arguments");
		ft_putendl("Usage : ./puissance4 line(6+) col(7+) [easy|medium|hard]");
		return (FALSE);
	}
	if (malloc_grid(grid) == FALSE)
	{
		ft_putendl(strerror(errno));
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	check_win(t_player *winner, t_grid *grid)
{
	ssize_t	x;

	x = 0;
	if (check_row(AI, grid) == 4)
	{
		*winner = AI;
		return (TRUE);
	}
	if (check_row(PLAYER, grid) == 4)
	{
		*winner = PLAYER;
		return (TRUE);
	}
	while (42)
	{
		if (x == grid->column)
			return (TRUE);
		if (grid->grid[0][x] != NONE)
			x++;
		else
			break ;
	}
	return (FALSE);
}

static t_bool	init_game(t_grid *grid, t_player cur_pl)
{
	t_bool		ret;
	t_player	winner;

	ret = winner = 0;
	while (42)
	{
		print_grid(grid, cur_pl, 0);
		ft_putchar('\n');
		if (check_win(&winner, grid) == TRUE)
		{
			print_winner(winner, grid);
			return (TRUE);
		}
		if (cur_pl == AI)
			ai_turn(grid);
		else
			ret = player_turn(grid);
		if (ret == FALSE)
			return (FALSE);
		cur_pl = (cur_pl == AI) ? PLAYER : AI;
	}
}

int				main(int ac, char **av)
{
	t_grid		grid;
	t_player	first_pl;
	t_bool		ret;

	if (init_grid(ac, av, &grid))
		return (1);
	srand(time(NULL));
	if (rand() % 2)
		first_pl = PLAYER;
	else
		first_pl = AI;
	ret = init_game(&grid, first_pl);
	free_grid(&grid);
	if (ret == FALSE)
	{
		ft_putendl(strerror(errno));
		return (1);
	}
	return (0);
}
