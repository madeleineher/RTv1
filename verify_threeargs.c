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
			if (ft_strcmp(e->p.strone, e->vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	if ((e->ret_tmp = verify_tag_to_argument(e, e->p.strone, 3)) != 0)
		return (e->ret_tmp);
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

int		verify_numbers_three(t_env *e, char *string, char *num) // working here 
{
	(void)e;
	(void)string;
	(void)num;
	// int	realnum;

	// realnum = ft_atoi(num);
	// change the strcmp strings !
	// if (ft_strcmp("radius", string) == 0)
	// {
	// 	if (realnum <= 0) // || realnum > LIMIT (?))
	// 		return (83);
	// }
// 	else if (ft_strcmp("angle", string) == 0)
// 	{
		
// 	}
// 	else if (ft_strcmp("d", string) == 0)
// 	{
		
// 	}
// 	else if (ft_strcmp("specpower", string) == 0)
// 	{
		
// 	}
// 	else if (ft_strcmp("specvalue", string) == 0)
// 	{
		
// 	}
// 	else if (ft_strcmp("reflection", string) == 0)
// 	{
		
// 	}
	return (0);
}

// NEED TO COME BACK HERE AND EDIT THE WAY I VERIFY STRING INPUT
int		verifyargs_three_numbers(char *string, int letter, t_env *e)
{
	(void)e;
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
	int		comma;
	int		len1;
	int		val1;
	int		val2;
	int		val3;

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
	e->p.strtwo = ft_strsub(e->p.gnl_line, 4, ft_strclen(e->p.gnl_line, '>') - 4);	
	if ((verifyargs_three_numbers(e->p.strone, ',', e) != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[1], ',', e) != 0)) 
		return (18);
	if ((verifyargs_three_numbers(split_test[2], '<', e) != 0))
		return (18);
	val1 = ft_atoi(e->p.strone); // working here 
	val2 = ft_atoi(split_test[1]); // working here 
	val3 = ft_atoi(split_test[2]); // working here 
	printf("[%d] [%d] [%d]\n", val1, val2, val3); // working here 
	// if ((e->ret_tmp = verify_numbers_three(e, e->p.strtwo, e->p.strone)) != 0) // working here 
		// return (e->ret_tmp);
	ft_strfree(e->p.strone);
	ft_strfree(e->p.strtwo);
	// store_args(e);
	return (0);
}