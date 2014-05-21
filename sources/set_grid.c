/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:11:11 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 00:20:40 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance4.h>
#include <libft.h>

t_bool		malloc_grid(t_grid *g)
{
	ssize_t	i;

	i = 0;
	g->grid = (t_player **)ft_memalloc(sizeof(t_player *) * g->line);
	if (g->grid == NULL)
		return (FALSE);
	while (i < g->line)
	{
		g->grid[i] = (t_player *)ft_memalloc(sizeof(t_player) * g->column);
		if (g->grid[i] == NULL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		free_grid(t_grid *grid)
{
	ssize_t	i;

	i = 0;
	while (i < grid->line)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
}
