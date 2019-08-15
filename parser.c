/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/30 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int	add_link(char *line, t_ll **head, t_env *e, int i)
{
	(void)i;
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	new->content = line;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	e->lenfile++;
	return (0);
}

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

int		extract_status(t_env *e, char **strings)
{
	// checks the status of the spec/object
	int	i;

	i = 0;
	if (ft_strcmp("status", strings[1]) != 0)
		return (14);
	if (ft_strcmp("=", strings[2]) != 0)
		return (14);
	if (ft_strcmp("\"basic\">", strings[3]) == 0)
		e->p.status = 1;
	else if (ft_strcmp("\"extra\">", strings[3]) == 0)
		e->p.status = 2;
	else
		return (16);
	return (0);
}

int		verifyvocab_three(t_env *e, char **split)
{
	/*
		makes sure that the vocan in a string split with three strings has matching
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
		while (++e->p.voc_i < 15)
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

int		verifyendings_three(char **split_test)
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
	printf("fake : [%d] - num : [%d]\n", fake_check, num_check);
	if (fake_check > 0 || num_check == 0)
		return (-1);
	if (num_check > 0)
		return (0);
	return (0);
}

int		verifyargs_three(t_env *e, char **split_test) 
{
	/* 
		checks the vaidity of arguments for those with three given characteristics
		for example : <position>10, 30, 40</position
		position has three values	
	*/
	(void)e;
	int		comma; // ?
	int		len1;
	int		num_check;

	num_check = 0;
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
	printf("string : [%s]\n", e->p.strone);
	if ((verifyargs_three_numbers(e->p.strone, ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[1], ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(split_test[2], '<') != 0))
		return (18);
	// store_args(e);
	return (0);
}

int		verify_cam_amb(t_env *e, char **split_test, char *split_tabless)
{
	int	ret;

	ret = 0;
	if (e->p.spec_order == 0)
	{
		if (ft_strcmp("<cam", split_tabless) != 0)
			return (10);
		e->spcs.cam = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->cam.status = e->p.status;
		e->p.current_tag = "cam";
	}
	if (e->p.spec_order == 1)
	{	
		if (ft_strcmp("<amb", split_tabless) != 0)
			return (11);
		e->spcs.amb = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->amb.status = e->p.status;
		e->p.current_tag = "amb";
	}
	return (ret);
}

int		verify_light(t_env *e, char **split_test, char *split_tabless)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("<light", split_tabless) != 0)
		return (12); // fix this tag message !
	e->spcs.light += 1;
	if (ft_iseven(e->spcs.light) == 0)
		return (23);
	// printf("light increase open ==> [%d]\n", e->spcs.light);
	if ((ret = extract_status(e, split_test)) != 0)
		return (ret);
	e->p.current_tag = "light";
	return (ret);
}

int		verify_closing_tags_specs(t_env *e, char *split_tabless)
{
	int		ret;

	ret = 0;
	if (e->p.spec_order == 1)
	{
		if ((ret = ft_strcmp("</cam>", split_tabless)) != 0)
			return (10);
		open_close(&e->spcs.cam);
	}
	if (e->p.spec_order == 2)
	{
		if ((ret = ft_strcmp("</amb>", split_tabless)) != 0)
			return (11);
		open_close(&e->spcs.amb);
	}
	if (e->p.spec_order >= 3)
	{
		if ((ret = ft_strcmp("</light>", split_tabless)) != 0)
			return (12);
		open_close(&e->spcs.light);
		if (ft_iseven(e->spcs.light) == -1)
			return (29);
		// printf("light increase close : [%d]\n", e->spcs.light);
	}
	return (0);
}

int		two_tabs_specs(t_env *e, char **split_test, char *split_tabless)
{
	int	ret_tmp;

	ret_tmp = 0;
	if ((ret_tmp = two_angle_brackets(e)) != 2)
		return (9);
	if (e->str_count == 4)
	{
		if (e->p.spec_order == 0 || e->p.spec_order == 1)
			if ((ret_tmp = verify_cam_amb(e, split_test, split_tabless)) != 0)
				return (ret_tmp);
		if (e->p.spec_order >= 2)
			if ((ret_tmp = verify_light(e, split_test, split_tabless)) != 0)
				return (ret_tmp);
	}
	else if (e->str_count == 1)
	{
		if ((ret_tmp = verify_closing_tags_specs(e, split_tabless)) != 0)
			return (ret_tmp);
	}			
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	e->p.spec_order += (e->str_count == 4 ? 1 : 0);
	return (0);
}

// verifying three tab , one argument tags here ~~~~
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
		while (++e->p.voc_i < 15) // could be seg faulting here ...
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
// ~~~~~~~~~~ end of verifying three tab , one argument tags ! 

int		verify_line(t_env *e, char *line)
{
	char	**split_test;
	char	*split_tabless;
	int		ret_tmp;

	ret_tmp = 0;
	split_test = ft_strsplit(line, ' ');
	split_tabless = NULL;
	if (e->p.specs == 1 && e->p.scene == 1 && e->p.objects == 0)
	{
		e->str_count = ft_countstrings(split_test);
		split_tabless = ft_strtrim(split_test[0]);
		if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
			return (5);
		if (ft_charfreq(line, '\t') == 2)
			if ((ret_tmp = two_tabs_specs(e, split_test, split_tabless)) != 0)
				return (ret_tmp);
		if (ft_charfreq(line, '\t') == 3)
		{
			if (e->str_count == 3)
			{
				if ((ret_tmp = verifyanglebrackets_three(e, split_test)) == -1)
					return (17);
				if ((ret_tmp = verifyvocab_three(e, split_test)) == -1)
					return (14);
				if ((ret_tmp = verifyargs_three(e, split_test)) != 0)
					return (ret_tmp);
			}
			else if (e->str_count == 1)
			{
				if ((ret_tmp = verifyanglebrackets_one(e)) == -1)
					return (17);
				if ((ret_tmp = verifyvocab_one(e)) == -1) // pick up here ~*
					return (14);
				if ((ret_tmp = verifyargs_one(e)) != 0)
					return (18);
			}
			else
				return (17);
		}
	}
	else if (e->p.specs == 1 && (e->p.scene != 1 || e->p.objects != 0))
		return (4);
	if (e->p.objects == 1 && e->p.specs == 2 && e->p.scene == 1)
	{
		// printf("--->[%s]\n", split_test[0]);
	}
	else if (e->p.objects == 1 && (e->p.scene != 1 || e->p.specs != 2))
		return (4);
	ft_delsplit(split_test);
	free(split_tabless);
	split_tabless = NULL;
	return (0);
}

int		globals(t_env *e, char *gnl_line)
{
	int ret_tmp = 0;
	int	ret_tabs = 0;
	char	*tabless;

	e->p.skip = 0;
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
		if ((ret_tmp = open_close(&e->p.specs)) != 0)
			return (ret_tmp);
	if (ft_strcmp("<objects>", tabless) == 0 && ret_tabs == 1)
	{
		e->p.objects += 1;
		e->p.skip = 1;
	}
	if (ft_strcmp("</objects>", tabless) == 0 && ret_tabs == 1)
		if ((ret_tmp = open_close(&e->p.objects)) != 0)
			return (ret_tmp);
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->p.objects != 2 || e->p.specs != 2) // change the error number
		return (8); // change error message
	if (e->p.scene != 2)
		return (6);
	if (e->p.spec_order < 3)
		return(26);
	if ((ft_iseven(e->spcs.light)) == -1)
		return(27);
	if (e->spcs.cam != 2 || e->spcs.amb != 2)
		return (28);
	if (e->ret.gnl == -1)
		return (1);
	printf("VALID!\n");
	return (0);
}

int		parser(t_env *e, int fd)
{
	t_ll	*head;

	head = NULL;
	while ((e->ret.gnl = get_next_line(fd, &e->p.gnl_line)) > 0)
	{
		e->p.gnl_i++;
		if ((e->ret.glo = globals(e, e->p.gnl_line)) != 0)
			return (e->ret.glo);
		if ((e->p.objects == 1 || e->p.specs == 1) && !e->p.skip && ((e->ret.tag = verify_line(e, e->p.gnl_line)) != 0))
			return (e->ret.tag);
		if (e->p.gnl_line)
		{
			free(e->p.gnl_line);
			e->p.gnl_line = NULL;
		}
	}
	e->ll = head;
	return (last_checks(e));
}
//	if ((add_link(gnl_line, &head, e, i)) == -1)
//		return (-1);