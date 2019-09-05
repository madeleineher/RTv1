/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:21:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 16:21:09 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/rtv1.h"

int		open_close(int *check_me)
{
	if (*check_me == 0)
		return (7);
	*check_me += 1;
	return (0);
}

int		two_angle_brackets(t_env *e)
{
	// checks that there is a pair of brackets for a line with a single tag, ex "<specs>"
	int	brackets;
	int	bad_brackets;
	int	i;
	int	j;

	brackets = 0;
	bad_brackets = 0;
	i = 0;
	j = -1;
	while (e->p.gnl_line[i] == '\t')
		i++;
	j = i;
	while (e->p.gnl_line[j])
	{
		if (j == i && e->p.gnl_line[j] == '<')
			brackets++;
		if (e->p.gnl_line[j] == '>' && e->p.gnl_line[j + 1] == '\0')
			brackets++;
		if (j != i && e->p.gnl_line[j + 1] != '\0' && (e->p.gnl_line[j] == '<' || e->p.gnl_line[j] == '>'))
			bad_brackets++;
		j++;
	}
	return (brackets + bad_brackets);
}

int		extract_status(t_env *e, char **strings)   	 // used globally
{
	// checks the status of the spec/object
	int	i;

	i = 0;
	if (ft_strcmp("status", strings[1]) != 0)
		return (14);
	if (ft_strcmp("=", strings[2]) != 0)
		return (15);
	if (ft_strcmp("\"basic\">", strings[3]) == 0)
		e->p.status = 1;
	else if (ft_strcmp("\"extra\">", strings[3]) == 0)
		e->p.status = 2;
	else
		return (16);
	return (0);
}

