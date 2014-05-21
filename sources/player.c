/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 16:01:22 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 20:40:43 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance4.h>
#include <libft.h>

static void	valid_turn(t_grid *grid, size_t choice)
{
	ssize_t	line;

	line = 0;
	while (line != grid->line && grid->grid[line][choice] == NONE)
		line++;
	line--;
	grid->grid[line][choice] = PLAYER;
}

t_bool		player_turn(t_grid *grid)
{
	char	*buf;
	ssize_t	col;

	while (42)
	{
		ft_putstr("\033[1;33mChoose a column number (1 - ");
		ft_putnbr(grid->column);
		ft_putstr(") : ");
		if (get_next_line(0, &buf) == -1)
			return (FALSE);
		ft_putstr("\033[0;0m");
		col = (buf == NULL) ? -1 : ft_atoi(buf) - 1;
		if (buf)
			free(buf);
		if (col < 0 || col > grid->column - 1)
			ft_putendl("\033[1;33mError ! Select a valid number\033[0;0m");
		else if (grid->grid[0][col] != NONE)
			ft_putendl("\033[1;33mError ! This column is full\033[0;0m");
		else
			break ;
	}
	valid_turn(grid, col);
	return (TRUE);
}
