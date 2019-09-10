/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vocab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:46:12 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 12:46:15 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		globals_two(t_env *e, char *tabless, int ret_tabs)
{
	if (ft_strcmp("<objects>", tabless) == 0 && ret_tabs == 1)
	{
		e->p.objects += 1;
		e->p.skip = 1;
	}
	if (ft_strcmp("</objects>", tabless) == 0 && ret_tabs == 1)
	{
		if ((e->p.ret_p = open_close(&e->p.objects)) != 0)
		{
			ft_strfree(tabless);
			return (e->p.ret_p);
		}
	}
	return (0);
}

int		globals(t_env *e, char *gnl_line)
{
	int		ret_tabs = 0;
	char	*tabless;

	e->p.skip = 0;
	e->p.ret_p = 0; // need this ?
	ret_tabs = ft_charfreq(gnl_line, '\t');
	tabless = ft_strtrim(gnl_line);
	if ((ft_strcmp("<scene>", tabless) == 0) && ret_tabs == 0)
		e->p.scene += 1;
	if (ft_strcmp("</scene>", tabless) == 0 && ret_tabs == 0)
		e->p.scene += 1;
	if (ft_strcmp("<specs>", tabless) == 0 && ret_tabs == 1)
	{
		e->p.specs += 1;
		e->p.skip = 1;
	}
	if (ft_strcmp("</specs>", tabless) == 0 && ret_tabs == 1)
		if ((e->p.ret_p = open_close(&e->p.specs)) != 0)
		{
			ft_strfree(tabless);
			return (e->p.ret_p);
		}
	if ((e->p.ret_p = globals_two(e, tabless, ret_tabs)) != 0)
		return(e->p.ret_p);
	return (0);
}

void		set_vocab(t_env *e)
{
	e->p.vocab_one[0] = "sphere";
	e->p.vocab_one[1] = "cylinder";
	e->p.vocab_one[2] = "cone";
	e->p.vocab_one[3] = "plane";
	e->p.vocab_two[0] = "position";
	e->p.vocab_two[1] = "direction";
	e->p.vocab_two[2] = "diffusion";
	e->p.vocab_two[3] = "reflection";
	e->p.vocab_two[4] = "specvalue"; 
	e->p.vocab_two[5] = "specpower";
	e->p.vocab_two[6] = "intensity"; 
	e->p.vocab_two[7] = "translate";
	e->p.vocab_two[8] = "rotate";
	e->p.vocab_two[9] = "angle";
	e->p.vocab_two[10] = "color";
	e->p.vocab_two[11] = "center";
	e->p.vocab_two[12] = "d";
	e->p.vocab_two[13] = "radius";
	e->p.vocab_two[14] = "ambient"; // -- correct name ? // need this ?????
	e->p.vocab_two[15] = "normal";
}