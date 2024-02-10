/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	quick_check(t_game *game)
{
	int		pos;
	char	c;

	pos = 0;
	game->map->y = 0;
	while (game->map->y_size > game->map->y)
	{
		game->map->x = 0;
		while (c != '\0' || game->map->x == 0)
		{
			c = game->map->map[game->map->y][game->map->x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				pos++;
			else if (c != '0' && c != '1' && c != ' ' && c != '\0')
			{
				error("Error forbidden char for map", game);
			}
			game->map->x++;
		}
		game->map->y++;
	}
	if (pos != 1)
		error("Error wrong number of starting position", game);
}
