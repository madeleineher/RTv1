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