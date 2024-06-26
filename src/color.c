/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:17:08 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:26:30 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	get_t(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_r(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_g(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_b(int argb)
{
	return (argb & 0xFF);
}
