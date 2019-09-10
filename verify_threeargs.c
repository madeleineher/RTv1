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

int		verifyvocab_three(t_env *e, char **split) // /! string needs to be freed before returning error message /!
{
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
		while (++e->p.voc_i < 16)
			if (ft_strcmp(e->p.strone, e->p.vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	if ((e->p.ret_p = verify_tag_to_argument(e, e->p.strone, 3)) != 0)
		return (e->p.ret_p);
	free(e->p.strone);
	e->p.strone = NULL;
	free(e->p.strtwo);
	e->p.strtwo = NULL;
	return (e->p.voc_check);
}

int		verifyanglebrackets_three(t_env *e, char **split_test)
{
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

int		verifyendings_three(char **split_test)
{
	if ((ft_strclen(split_test[0], ',') + 1) != ft_strlen(split_test[0]))
		return (-1);
	if ((ft_strclen(split_test[1], ',') + 1) != ft_strlen(split_test[1]))
		return (-1);
	return (0);
}

int		verifyargs_three_numbers(char *string, int letter)
{
	int		num_check;
	int		fake_check;
	int		i;

	i = 0;
	num_check = 0;
	fake_check = 0;
	if (string[i] == '-')
		i++;
	while (string[i] != letter)
	{
		if (ft_isdigit(string[i]) == 1)
			num_check++;
		if (ft_isdigit(string[i]) == 0)
			fake_check++;
		i++;
	}
	if (fake_check > 0 || num_check == 0)
		return (-1);
	if (num_check > 0)
		return (0);
	return (0);
}

int		verifyargs_three(t_env *e, char **split_test)  
{
	if (verifyendings_three(split_test) == -1)
		return (18);
	e->p.comma = 0;
	e->p.comma += ft_charfreq(split_test[0], ',');
	e->p.comma += ft_charfreq(split_test[1], ',');
	e->p.comma += ft_charfreq(split_test[2], ',');
	if (e->p.comma != 2)
		return (19);
	e->p.strone = ft_strsub(split_test[0], ft_strclen(split_test[0], '>') + 1, \
		(ft_strclen(split_test[0], ',') - ft_strclen(split_test[0], '>')));
	e->p.strtwo = ft_strsub(e->p.gnl_line, 4, ft_strclen(e->p.gnl_line, '>') - 4);	
	if ((verifyargs_three_numbers(e->p.strone, ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[1], ',') != 0)) 
		return (18);
	if ((verifyargs_three_numbers(split_test[2], '<') != 0))
		return (18);
	e->p.v1 = ft_atoi(e->p.strone); // working here 
	e->p.v2 = ft_atoi(split_test[1]); // working here 
	e->p.v3 = ft_atoi(split_test[2]); // working here 
	if ((e->p.ret_p = verify_numbers_three(e, e->p.strtwo)) != 0) // working here 
		return (e->p.ret_p);  // working here, last verification (store data here)!
	ft_strfree(e->p.strone);
	ft_strfree(e->p.strtwo);
	return (0);
}