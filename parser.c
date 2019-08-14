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

int		two_angle_brackets(t_env *e, char *line)
{
	(void)e;
	int	brackets;
	int	bad_brackets;
	int	i;
	int	j;

	brackets = 0;
	bad_brackets = 0;
	i = 0;
	j = -1;
	while (line[i] == '\t')
		i++;
	j = i;
	while (line[j])
	{
		if (j == i && line[j] == '<')
			brackets++;
		if (line[j] == '>' && line[j + 1] == '\0')
			brackets++;
		if (j != i && line[j + 1] != '\0' && (line[j] == '<' || line[j] == '>'))
			bad_brackets++;
		j++;
	}
	return (brackets + bad_brackets);
}

int		extract_status(t_env *e, char **strings)
{
	int	i;

	i = 0;
	if (ft_strcmp("status", strings[1]) != 0)
		return (14);
	if (ft_strcmp("=", strings[2]) != 0)
		return (14);
	if (ft_strcmp("\"basic\">", strings[3]) == 0)
		e->status = 1;
	else if (ft_strcmp("\"extra\">", strings[3]) == 0)
		e->status = 2;
	else
		return (16);
	return (0);
}

int		verifyvocab_three(t_env *e, char **split_test)
{
	int		end1;
	int		end2;

	e->voc_i = -1;
	e->voc_check = -1;
	end1 = (ft_strclen(split_test[0], '>') - ft_strclen(split_test[0], '<')) - 1;
	end2 = (ft_strclen(split_test[2], '>') - ft_strclen(split_test[2], '/')) - 1;
	e->strone = ft_strsub(split_test[0], ft_strclen(split_test[0], '<') + 1, end1);
	e->strtwo = ft_strsub(split_test[2], ft_strclen(split_test[2], '/') + 1, end2);
	if (ft_strcmp(e->strone, e->strtwo) != 0)
		return (-1);
	else
		while (++e->voc_i < 15)
			if (ft_strcmp(e->strone, e->vocab_two[e->voc_i]) == 0)
				e->voc_check++;
	free(e->strone);
	e->strone = NULL;
	free(e->strtwo);
	e->strtwo = NULL;
	return (e->voc_check);
}

int		verifyanglebrackets_three(char **split_test)
{
	int		i;
	int		set_one;
	int		set_two;

	i = -1;
	set_one = 0;
	set_two = 0;
	while (split_test[0][++i])
	{
		if (split_test[0][i] == '<')
			set_one++;
		if (split_test[0][i] == '>')
			set_one++;
	}
	i = -1;
	while (split_test[2][++i])
	{
		if (split_test[2][i] == '<' && split_test[2][i + 1] == '/')
			set_two++;
		if (split_test[2][i] == '>')
			set_two++;
	}
	if (set_one != 2 || set_two != 2)
		return (-1);
	return (0);
}

int		verifyargs_three(t_env *e, char **split_test)
{
	(void)e;
	(void)split_test;
	return (0);
}

int		verify_cam_amb(t_env *e, char **split_test, char *split_tabless)
{
	int	ret;

	ret = 0;
	if (e->spec_order == 0)
	{
		if (ft_strcmp("<cam", split_tabless) != 0)
			return (10);
		e->spcs.cam = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->cam.status = e->status;
	}
	if (e->spec_order == 1)
	{	
		if (ft_strcmp("<amb", split_tabless) != 0)
			return (11);
		e->spcs.amb = 1;
		if ((ret = extract_status(e, split_test)) != 0)
			return (ret);
		e->amb.status = e->status;
	}
	return (0);
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
	return (ret);
}

int		closing_tags_specs(t_env *e, char *split_tabless)
{
	int		ret;

	ret = 0;
	if (e->spec_order == 1)
	{
		if ((ret = ft_strcmp("</cam>", split_tabless)) != 0)
			return (10);
		open_close(&e->spcs.cam);
	}
	if (e->spec_order == 2)
	{
		if ((ret = ft_strcmp("</amb>", split_tabless)) != 0)
			return (11);
		open_close(&e->spcs.amb);
	}
	if (e->spec_order >= 3)
	{
		if ((ret = ft_strcmp("</light>", split_tabless)) != 0)
			return (12);
		open_close(&e->spcs.light);
		if (ft_iseven(e->spcs.light) == -1)
			return (23);
		// printf("light increase close : [%d]\n", e->spcs.light);
	}
	return (0);
}



int		check_tag_uniform(t_env *e, char *line)
{
	char	**split_test;
	char	*split_tabless;
	int		str_count;
	int		ret_tmp;

	ret_tmp = 0;
	str_count = 0;
	split_test = ft_strsplit(line, ' ');
	split_tabless = NULL;
	if (e->specs == 1 && e->scene == 1 && e->objects == 0)
	{
		str_count = ft_countstrings(split_test);
		split_tabless = ft_strtrim(split_test[0]);
		if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
			return (5);
		if (ft_charfreq(line, '\t') == 2)
		{
			if ((ret_tmp = two_angle_brackets(e, line)) != 2)
				return (9);
			if (str_count == 4)
			{
				if (e->spec_order == 0 || e->spec_order == 1)
					if ((ret_tmp = verify_cam_amb(e, split_test, split_tabless)) != 0)
						return (ret_tmp);
				if (e->spec_order >= 2)
					if ((ret_tmp = verify_light(e, split_test, split_tabless)) != 0)
						return (ret_tmp);
			}
			else if (str_count == 1)
			{
				if ((ret_tmp = closing_tags_specs(e, split_tabless)) != 0)
					return (ret_tmp);
			}			
			else if (str_count != 1 || str_count != 4)
				return (13);
			e->spec_order += (str_count == 4 ? 1 : 0);
		}
		if (ft_charfreq(line, '\t') == 3)
		{
			if (str_count == 3)
			{
				if ((ret_tmp = verifyanglebrackets_three(split_test)) == -1)
					return (17);
				if ((ret_tmp = verifyvocab_three(e, split_test)) == -1)
					return (14);
				if ((ret_tmp = verifyargs_three(e, split_test)) == -1)
					return (18);
			}
			else if (str_count == 1)
			{
				// printf("--->[%s]\n", split_test[0]);	
			}
			else
				return (17);
		}
	}
	else if (e->specs == 1 && (e->scene != 1 || e->objects != 0))
		return (4);
	if (e->objects == 1 && e->specs == 2 && e->scene == 1)
	{
		// printf("--->[%s]\n", split_test[0]);
	}
	else if (e->objects == 1 && (e->scene != 1 || e->specs != 2))
		return (4);
	// ft_delsplit(split_test); //fix pointer situation from skip tabs;
	return (0);
}

int		globals(t_env *e, char *gnl_line)
{
	int ret_tmp = 0;
	int	ret_tabs = 0;
	char	*tabless;

	e->skip = 0;
	ret_tabs = ft_charfreq(gnl_line, '\t');
	tabless = ft_strtrim(gnl_line);
	if ((ft_strcmp("<scene>", tabless) == 0) && ret_tabs == 0)
		e->scene += 1;
	if (ft_strcmp("</scene>", tabless) == 0 && ret_tabs == 0)
		e->scene += 1;
	if (ft_strcmp("<specs>", tabless) == 0 && ret_tabs == 1)
	{
		e->specs += 1;
		e->skip = 1;
	}
	if (ft_strcmp("</specs>", tabless) == 0 && ret_tabs == 1)
		if ((ret_tmp = open_close(&e->specs)) != 0)
			return (ret_tmp);
	if (ft_strcmp("<objects>", tabless) == 0 && ret_tabs == 1)
	{
		e->objects += 1;
		e->skip = 1;
	}
	if (ft_strcmp("</objects>", tabless) == 0 && ret_tabs == 1)
		if ((ret_tmp = open_close(&e->objects)) != 0)
			return (ret_tmp);
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->objects != 2 || e->specs != 2) // change the error number
		return (8); // change error message
	if (e->scene != 2)
		return (6);
	if (e->spec_order < 3)
		return(20);
	if ((ft_iseven(e->spcs.light)) == -1)
		return(21);
	if (e->spcs.cam != 2 || e->spcs.amb != 2)
		return (22);
	if (e->ret.gnl == -1)
		return (1);
	printf("VALID!\n");
	return (0);
}

int		parser(t_env *e, int fd)
{
	t_ll	*head;

	head = NULL;
	while ((e->ret.gnl = get_next_line(fd, &e->gnl_line)) > 0)
	{
		e->gnl_i++;
		if ((e->ret.glo = globals(e, e->gnl_line)) != 0)
			return (e->ret.glo);
		if ((e->objects == 1 || e->specs == 1) && !e->skip && ((e->ret.tag = check_tag_uniform(e, e->gnl_line)) != 0))
			return (e->ret.tag);
		if (e->gnl_line)
		{
			free(e->gnl_line);
			e->gnl_line = NULL;
		}
	}
	e->ll = head;
	return (last_checks(e));
}
//	if ((add_link(gnl_line, &head, e, i)) == -1)
//		return (-1);