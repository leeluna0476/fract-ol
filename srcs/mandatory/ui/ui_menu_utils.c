/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_menu_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:15 by seojilee          #+#    #+#             */
/*   Updated: 2023/12/11 19:24:36 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

bool	check_menu(int a, int b)
{
	if (!(0 < a && a < MENU))
		return (false);
	if (!(0 < b && b < HEIGHT))
		return (false);
	return (true);
}
