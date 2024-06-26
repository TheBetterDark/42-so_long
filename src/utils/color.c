/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:17:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/27 15:47:15 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return (rgb >> 16 & 0xFF);
}

int	get_g(int rgb)
{
	return (rgb >> 8 & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}
