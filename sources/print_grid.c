/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:58:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 20:37:17 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance4.h>
#include <stdlib.h>
#include <libft.h>

static void	print_player(t_player cur_pl, t_grid *grid)
{
	ft_putstr("\n\n\n");
	if (cur_pl == AI)
	{
		if (grid->level == EASY)
			ft_putendl("\033[1;4;31mHAL (easy) turn :\033[0;0;0m");
		else if (grid->level == MEDIUM)
			ft_putendl("\033[1;4;31mHAL (medium) turn :\033[0;0;0m");
		else if (grid->level == HARD)
			ft_putendl("\033[1;4;31mHAL (hard) turn :\033[0;0;0m");
	}
	else
	{
		if (grid->level == HARD)
			ft_putendl("\033[1;4;33mVictim turn :\033[0;0;0m");
		else
			ft_putendl("\033[1;4;33mPlayer turn :\033[0;0;0m");
	}
}

static void	print_htrace(size_t line_size, t_bool first)
{
	size_t	h_trace;

	ft_putstr("\n\t");
	if (first == TRUE)
	{
		h_trace = (line_size * 4) + 1;
		while (h_trace--)
			ft_putstr("\033[1;34m_\033[0;0m");
	}
	else
	{
		h_trace = line_size;
		ft_putstr("\033[1;34m|\033[0;0m");
		while (h_trace--)
			ft_putstr("\033[1;34m___|\033[0;0m");
	}
	ft_putchar('\n');
}

void		print_winner(t_player win_pl, t_grid *grid)
{
	ft_putstr("\n\n");
	if (win_pl == AI && grid->level == EASY)
		ft_putendl("\033[1;31mHAL (easy) win this game !\033[0;0m\n");
	else if (win_pl == AI && grid->level == MEDIUM)
		ft_putendl("\033[1;31mHAL (medium) win this game !\033[0;0m\n");
	else if (win_pl == AI && grid->level == HARD)
		ft_putendl("\033[1;31mHAL (hard) win this game !\033[0;0m\n");
	else if (win_pl == PLAYER && grid->level == HARD)
		ft_putendl("\033[1;33mVictim win this game !\033[0;0m\n");
	else if (win_pl == PLAYER)
		ft_putendl("\033[1;33mPlayer win this game !\033[0;0m\n");
	else if (win_pl == NONE)
		ft_putendl("\033[1;32mDraw, nobody win this game !\033[0;0m\n");
}

void		print_grid(t_grid *grid, t_player cur_pl, size_t pos)
{
	size_t		total;
	t_player	pos_pl;

	print_player(cur_pl, grid);
	total = grid->line * grid->column;
	print_htrace(grid->column, TRUE);
	while (pos != total)
	{
		ft_putstr("\033[1;34m\t|\033[0;0m");
		while (42)
		{
			pos_pl = grid->grid[pos / grid->column][pos % grid->column];
			if (pos_pl == AI)
				ft_putstr("\033[1;31m 0 \033[0;0m");
			else if (pos_pl == PLAYER)
				ft_putstr("\033[1;33m 0 \033[0;0m");
			else
				ft_putstr("   ");
			ft_putstr("\033[1;34m|\033[0;0m");
			pos++;
			if (pos % grid->column == 0)
				break ;
		}
		print_htrace(grid->column, FALSE);
	}
}
