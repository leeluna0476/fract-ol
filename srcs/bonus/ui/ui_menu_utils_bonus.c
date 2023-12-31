/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_menu_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:08 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/26 19:15:14 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

bool	check_menu(int a, int b)
{
	if (!(0 < a && a < MENU))
		return (false);
	if (!(0 < b && b < HEIGHT))
		return (false);
	return (true);
}

bool	check_write(t_data *img)
{
	size_t	i;

	i = 0;
	while (img->button_on_off[i] == false)
		i++;
	if ((i >= CLEAR && i <= TRICORN) || i == THDJULIA)
		return (true);
	return (false);
}
