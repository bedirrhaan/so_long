/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:14:05 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/06 17:15:22 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include <stdio.h>

int	path_finder(t_game *particles)
{
	particles->copy_map = copy_two_dimensional_array(particles->map);
	particles->collectibles_copy = particles->collectibles;
	recursive_p(particles, particles->player_y, particles->player_x);
	if (particles->collectibles_copy != 0)
		return (ft_copymap_free(particles), 0);
	if (!(player_exit_control(particles)))
		return (ft_copymap_free(particles), 0);
	return (ft_copymap_free(particles), 1);
}

int	player_exit_control(t_game *particles)
{
	int	count;

	count = 0;
	if (particles->copy_map[particles->player_e_x + 1][particles->player_e_y] != 'P')
		count++;
	if (particles->copy_map[particles->player_e_x - 1][particles->player_e_y] != 'P')
		count++;
	if (particles->copy_map[particles->player_e_x][particles->player_e_y + 1] != 'P')
		count++;
	if (particles->copy_map[particles->player_e_x][particles->player_e_y - 1] != 'P')
		count++;
	if (count == 4)
		return (0);
	return (1);
}

void	recursive_p(t_game *map, int y, int x)
{
	if (map->copy_map[y][x + 1] == '0' || map->copy_map[y][x + 1] == 'C')
	{
		if (map->copy_map[y][x + 1] == 'C')
			map->collectibles_copy--;
		map->copy_map[y][x + 1] = 'P';
		recursive_p(map, y, x + 1);
	}
	if (map->copy_map[y][x - 1] == '0' || map->copy_map[y][x - 1] == 'C')
	{
		if (map->copy_map[y][x - 1] == 'C')
			map->collectibles_copy--;
		map->copy_map[y][x - 1] = 'P';
		recursive_p(map, y, x - 1);
	}
	if (map->copy_map[y + 1][x] == '0' || map->copy_map[y + 1][x] == 'C')
	{
		if (map->copy_map[y + 1][x] == 'C')
			map->collectibles_copy--;
		map->copy_map[y + 1][x] = 'P';
		recursive_p(map, y + 1, x);
	}
	if (map->copy_map[y - 1][x] == '0' || map->copy_map[y - 1][x] == 'C')
	{
		if (map->copy_map[y - 1][x] == 'C')
			map->collectibles_copy--;
		map->copy_map[y - 1][x] = 'P';
		recursive_p(map, y - 1, x);
	}
}
