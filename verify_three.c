/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:59:46 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 15:59:47 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

// verifying three tab , one argument tags here ~~~~~~~~~~~~~~

int		verifyanglebrackets_one(t_env *e)
{
	int		endone;
	int		endtwo;
	int		i;

	i = -1;
	endone = 0;
	endtwo = 0;
	e->p.tmp = ft_strtrim(e->p.gnl_line);
	if (e->p.tmp[0] != '<' || e->p.tmp[ft_strlen(e->p.tmp) - 1] != '>')
		return (-1);
	while (e->p.tmp[++i])
	{
		if (e->p.tmp[i] == '<' && i == 0)
			endone++;
		if (e->p.tmp[i] == '>' && e->p.tmp[i + 1] != '\0' && endone == 1)
			endone++;
		if (e->p.tmp[i] == '<' && e->p.tmp[i + 1] == '/')
			endtwo++;
		if (e->p.tmp[i] == '>' && e->p.tmp[i + 1] == '\0' && endtwo == 1)
			endtwo++;
	}
	if (endone != 2 || endtwo != 2)
		return (-1);
	free(e->p.tmp);
	e->p.tmp = NULL;
	return (0);
}

int		verifyvocab_one(t_env *e)
{
	e->p.voc_i = -1;
	e->p.voc_check = -1;
	e->p.i = ft_strclen(e->p.gnl_line, '<') + 1;
	e->p.j = ft_strclen(e->p.gnl_line, '>');
	e->p.k = ft_strclen(e->p.gnl_line, '/') + 1;
	e->p.strone = ft_strsub(e->p.gnl_line, e->p.i, (e->p.j - e->p.i));
	e->p.i = ft_strlen(e->p.gnl_line) - 1;
	if (e->p.gnl_line[e->p.i] != '>')
		return (-1);
	e->p.strtwo = ft_strsub(e->p.gnl_line, e->p.k, (e->p.i - e->p.k));
	if (ft_strcmp(e->p.strone, e->p.strtwo) != 0)
		return (-1);
	else
		while (++e->p.voc_i < 18) // could be seg faulting here ...
			if (ft_strcmp(e->p.strone, e->vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	free(e->p.strone);
	e->p.strone = NULL;
	free(e->p.strtwo);
	e->p.strtwo = NULL;
	return (e->p.voc_check);
}

int		verifyargs_one(t_env *e)
{
	int		i;
	int		num_check;
	int		fake_check;

	i = -1;
	num_check = 0;
	fake_check = 0;
	e->p.strone = ft_strsub(e->p.gnl_line, e->p.j + 1, ((e->p.k - 3) - e->p.j));
	while (e->p.strone[++i])
	{
		if (ft_isdigit(e->p.strone[i]) == 1)
			num_check++;
		if (ft_isdigit(e->p.strone[i]) == 0)
			fake_check++;
	}
	free(e->p.strone);
	e->p.strone = NULL;
	if (fake_check > 0 || num_check == 0)
		return (-1);
	if (num_check > 0)
		return (0);
	return (0);
}