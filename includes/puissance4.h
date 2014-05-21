/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:26:13 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/09 20:41:36 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <unistd.h>

typedef enum	e_bool
{
	TRUE = 0,
	FALSE = 1
}				t_bool;

typedef enum	e_player
{
	NONE = 0,
	PLAYER = 1,
	AI = 2
}				t_player;

typedef enum	e_dif
{
	EASY = 1,
	MEDIUM = 3,
	HARD = 5
}				t_dif;

typedef struct	s_grid
{
	ssize_t		line;
	ssize_t		column;
	t_player	**grid;
	t_dif		level;
}				t_grid;

/*
** Print functions
*/
void		print_grid(t_grid *grid, t_player cur_pl, size_t pos);
void		print_winner(t_player win_pl, t_grid *grid);

/*
** Player functions
*/
void		ai_turn(t_grid *grid);
t_bool		player_turn(t_grid *grid);

/*
** Grid functions
*/
t_bool		malloc_grid(t_grid *grid);
void		free_grid(t_grid *grid);
int			check_row(t_player check_pl, t_grid *grid);

#endif /* !PUISSANCE4_H */
