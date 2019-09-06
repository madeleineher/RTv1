/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:30:41 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/06 13:30:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void		line_errors(t_env *e, int i)
{
	if (i > 80)
	{
		if (i == 81)
		{
			ft_putstr("Oops ! It looks like [");
			ft_putstr(e->p.tmp);
			ft_putstr("] was given the incorrect number of arguments. ");
			ft_putendl("This attribute takes three parameters.");
			// free --> e->p.tmp 
		}
		if (i == 82)
		{
			ft_putstr("Oops ! It looks like [");
			ft_putstr(e->p.tmp);
			ft_putstr("] was given the incorrect number of arguments. ");
			ft_putendl("This attribute takes one parameter.");
		}
		ft_putstr("The problem lies in line : ");
		ft_putnbr(e->p.gnl_i);
		ft_putchar('\n');
	} //add free strings here if there is an error return value !
}

void		lineless_errors_eight(t_env *e, int i)
{
	if (i == 66)
		ft_putendl("Oops ! It appears a 'light' spec is missng an attribute.");
	if (i == 67)
	{
		ft_putstr("Oops ! It looks like a 'light' spec was ");
		ft_putendl("given too many attributes.");
	}
	if (i == 68)
	{
		ft_putstr("Oops ! It looks like a 'light' spec was ");
		ft_putendl("given an incorrect attribute.");
	}
	if (i == 69)
	{
		ft_putstr("Oops ! It looks like a 'light' spec status is ");
		ft_putendl("set to 'basic' but extra parameters were passed.");
	}
	if (i == 70)
	{
		ft_putstr("Oops ! It looks like a 'light' spec status is ");
		ft_putendl("set to 'extra' but some parameters are missing.");
	}
    if (i > 80)
        line_errors(e, i);
}