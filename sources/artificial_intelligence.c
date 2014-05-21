/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artificial_intelligence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:40:08 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 20:45:06 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance4.h>

static void		valid_or_cancel_turn(t_bool valid, t_grid *grid, size_t choice)
{
	ssize_t	line;

	line = 0;
	while (line != grid->line && grid->grid[line][choice] == NONE)
		line++;
	if (valid == TRUE)
	{
		line--;
		grid->grid[line][choice] = AI;
	}
	else
		grid->grid[line][choice] = NONE;
}

static ssize_t	relevance_test(ssize_t col, int depth, t_grid *grid)
{
	ssize_t	weight;
	ssize_t	sub_col;
	int		ret;

	weight = 0;
	valid_or_cancel_turn(TRUE, grid, col);
	ret = check_row(AI, grid);
	weight = (ret == 4) ? weight + 1000 : weight + ret;
	ret = check_row(PLAYER, grid);
	weight = (ret == 4) ? weight - 1000 : weight - ret;
	sub_col = 0;
	if (depth)
	{
		while (sub_col < grid->column)
		{
			if (grid->grid[0][sub_col] == NONE)
				weight += relevance_test(sub_col, depth - 1, grid);
			sub_col++;
		}
	}
	valid_or_cancel_turn(FALSE, grid, col);
	return (weight);
}

void			ai_turn(t_grid *grid)
{
	ssize_t	choice;
	ssize_t	col;
	ssize_t	best;
	ssize_t	weight;

	col = best = weight = 0;
	while (grid->grid[0][col] != NONE)
		col++;
	choice = col;
	while (col < grid->column)
	{
		if (grid->grid[0][col] == NONE)
		{
			weight = relevance_test(col, grid->level, grid);
			if (best < weight)
			{
				best = weight;
				choice = col;
			}
		}
		col++;
	}
	valid_or_cancel_turn(TRUE, grid, choice);
}
