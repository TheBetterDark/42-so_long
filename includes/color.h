/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:17:44 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:26:38 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int	create_argb(int a, int r, int g, int b);
int	get_t(int argb);
int	get_r(int argb);
int	get_g(int argb);
int	get_b(int argb);

#endif
