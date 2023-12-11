/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_menu_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:43:13 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 20:43:19 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_bonus.h"

bool	check_menu(int a, int b)
{
	if (!(0 < a && a < MENU))
		return (false);
	if (!(0 < b && b < HEIGHT))
		return (false);
	return (true);
}
