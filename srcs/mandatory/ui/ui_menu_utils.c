/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_menu_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:15 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:29 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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
