/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:13:32 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 16:13:34 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

// --------------- three tabs , THREE AGRS ---------------

int		verifyvocab_three(t_env *e, char **split)
{
	/*
		makes sure that the vocab in a string split with three strings has matching
		and valid vocabulary in the xml tags
	*/
	int		end1;
	int		end2;

	e->p.voc_i = -1;
	e->p.voc_check = -1;
	end1 = (ft_strclen(split[0], '>') - ft_strclen(split[0], '<')) - 1;
	end2 = (ft_strclen(split[2], '>') - ft_strclen(split[2], '/')) - 1;
	e->p.strone = ft_strsub(split[0], ft_strclen(split[0], '<') + 1, end1);
	e->p.strtwo = ft_strsub(split[2], ft_strclen(split[2], '/') + 1, end2);
	if (ft_strcmp(e->p.strone, e->p.strtwo) != 0)
		return (-1);
	else
		while (++e->p.voc_i < 17)
			if (ft_strcmp(e->p.strone, e->vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	free(e->p.strone);
	e->p.strone = NULL;
	free(e->p.strtwo);
	e->p.strtwo = NULL;
	return (e->p.voc_check);
}

int		verifyanglebrackets_three(t_env *e, char **split_test)
{
	/*
		makes sure that there are two pairs of brackets in 
		a string split into three strings (0, 1, 2)
	*/
	int		i;

	i = -1;
	e->p.set_one = 0;
	e->p.set_two = 0;
	while (split_test[0][++i])
	{
		if (split_test[0][i] == '<')
			e->p.set_one++;
		if (split_test[0][i] == '>')
			e->p.set_one++;
	}
	i = -1;
	while (split_test[2][++i])
	{
		if (split_test[2][i] == '<' && split_test[2][i + 1] == '/')
			e->p.set_two++;
		if (split_test[2][i] == '>')
			e->p.set_two++;
	}
	if (e->p.set_one != 2 || e->p.set_two != 2)
		return (-1);
	return (0);
}

int		verifyendings_three(char **split_test) 	 // used globally
{
	/*
		checks that the endings for the first two values in a characteristic with three 
		values end with commas
	*/
	if ((ft_strclen(split_test[0], ',') + 1) != ft_strlen(split_test[0]))
		return (-1);
	if ((ft_strclen(split_test[1], ',') + 1) != ft_strlen(split_test[1]))
		return (-1);
	return (0);
}

int		verifyargs_three_numbers(char *string, int letter)
{
	/*
		verifies that there is a valid number + also that there is a numbers
	*/
	int		num_check;
	int		fake_check;
	int		i;

	i = -1;
	num_check = 0;
	fake_check = 0;
	while (string[++i] != letter)
	{
		if (ft_isdigit(string[i]) == 1)
			num_check++;
		if (ft_isdigit(string[i]) == 0)
			fake_check++;
	}
	if (fake_check > 0 || num_check == 0)
		return (-1);
	if (num_check > 0)
		return (0);
	return (0);
}

int		verifyargs_three(t_env *e, char **split_test)  
{
	/* 
		checks the validity of arguments for those with three given characteristics
		for example : <position>10, 30, 40</position
		position has three values	
	*/
	int		comma;
	int		len1;

	if (verifyendings_three(split_test) == -1)
		return (18);
	len1 = ft_strclen(split_test[0], '>') + 1;
	comma = 0;
	comma += ft_charfreq(split_test[0], ',');
	comma += ft_charfreq(split_test[1], ',');
	comma += ft_charfreq(split_test[2], ',');
	if (comma != 2)
		return (19);
	e->p.strone = ft_strsub(split_test[0], ft_strclen(split_test[0], '>') + 1, \
		(ft_strclen(split_test[0], ',') - ft_strclen(split_test[0], '>')));
	if ((verifyargs_three_numbers(e->p.strone, ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[1], ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[2], '<') != 0))
		return (18);
	// store_args(e);
	return (0);
}