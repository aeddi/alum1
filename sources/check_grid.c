/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  check_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:40:08 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 13:28:28 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance4.h>

static int	check_hrow(t_player check_pl, t_grid *grid)
{
	int		ret;
	int		tmp;
	ssize_t	y;
	ssize_t	x;

	ret = y = 0;
	while (y < grid->line)
	{
		tmp = x = 0;
		while (x < grid->column)
		{
			if (grid->grid[y][x] == check_pl)
				tmp++;
			else
				tmp = 0;
			ret = (ret < tmp) ? tmp : ret;
			x++;
		}
		y++;
	}
	return (ret);
}

static int	check_vrow(t_player check_pl, t_grid *grid)
{
	int		ret;
	int		tmp;
	ssize_t	y;
	ssize_t	x;

	ret = x = 0;
	while (x < grid->column)
	{
		tmp = y = 0;
		while (y < grid->line)
		{
			if (grid->grid[y][x] == check_pl)
				tmp++;
			else
				tmp = 0;
			ret = (ret < tmp) ? tmp : ret;
			y++;
		}
		x++;
	}
	return (ret);
}

static int	check_rdrow(t_player check_pl, t_grid *grid)
{
	int		ret;
	int		tmp;
	ssize_t	y;
	ssize_t	x;
	size_t	count;

	ret = tmp = y = x = count = 0;
	while (count < (size_t)(grid->line + grid->column - 2))
	{
		tmp = 0;
		while (y >= 0 && x < grid->column)
		{
			if (grid->grid[y--][x++] == check_pl)
				tmp++;
			else
				tmp = 0;
			ret = (ret < tmp) ? tmp : ret;
		}
		count++;
		y = (count < (size_t)grid->line) ? count : (size_t)grid->line - 1;
		x = (count < (size_t)grid->line) ? 0 : count - grid->line - 1;
	}
	return (ret);
}

static int	check_ldrow(t_player check_pl, t_grid *grid)
{
	int		ret;
	int		tmp;
	ssize_t	y;
	ssize_t	x;
	size_t	count;

	ret = tmp = y = x = count = 0;
	while (count < (size_t)(grid->line + grid->column - 2))
	{
		tmp = 0;
		while (y >= 0 && x >= 0)
		{
			if (grid->grid[y--][x--] == check_pl)
				tmp++;
			else
				tmp = 0;
			ret = (ret < tmp) ? tmp : ret;
		}
		y = (++count < (size_t)grid->line) ? count : (size_t)grid->line - 1;
		if (count < (size_t)grid->line)
			x = grid->column - 1;
		else
			x = (grid->column - 1) - (count - (grid->line - 1));
	}
	return (ret);
}

int			check_row(t_player check_pl, t_grid *grid)
{
	int	ret;
	int	tmp;

	ret = check_hrow(check_pl, grid);
	tmp = check_vrow(check_pl, grid);
	ret = (ret < tmp) ? tmp : ret;
	tmp = check_rdrow(check_pl, grid);
	ret = (ret < tmp) ? tmp : ret;
	tmp = check_ldrow(check_pl, grid);
	ret = (ret < tmp) ? tmp : ret;
	return (ret);
}
