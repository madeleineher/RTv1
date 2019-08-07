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

int		check_vocab(t_env *e, char *line)
{
	(void)e;
	(void)line;
	// int i = 0;

	// while (e->vocab[i] != '\0')
	// 	printf("[%s]\n", e->vocab[i++]);

	return (0);
}

int		check_tag_uniform(t_env *e, char *line)
{
	char	**split_test;
	int		str_count;
	
	str_count = 0;
	split_test = ft_strsplit(line, ' ');
	if (e->specs == 1 && e->scene == 1 && e->objects == 0)
	{
		if (ft_charfreq(line, '\t') < 2 || ft_charfreq(line, '\t') > 3)
			return (5);
		if (ft_charfreq(line, '\t') == 2)
		{
			str_count = ft_countstrings(split_test);
			printf("[%d]", str_count);
			while (*split_test)
			{
				if (str_count == 1) // pick up here ! 
					printf("---> [%s] ", *split_test++);
				else if (str_count == 4)
					printf("[%s] ", *split_test++);				
			}
			printf("\n");
		}

	}
	else if (e->specs == 1 && (e->scene != 1 || e->objects != 0))
		return (4);
	if (e->objects == 1 && e->specs == 2 && e->scene == 1)
	{
		//printf("--->[%s]\n", split_test[0]);
	}
	else if (e->objects == 1 && (e->scene != 1 || e->specs != 2))
		return (4);
	return (0);
}

int		one_tab_parse(int *check_me)
{
	if (*check_me == 0)
		return (7);
	*check_me = 2;
	return (0);
}

int		globals(t_env *e, char *gnl_line)
{
	int ret_tmp = 0;

	e->skip = 0;
	if ((ft_strcmp("<scene>", gnl_line) == 0))
		e->scene = 1;
	if (ft_strcmp("</scene>", gnl_line) == 0)
		e->scene = 2;
	if (ft_strcmp("\t<specs>", gnl_line) == 0)
	{
		e->specs = 1;
		e->skip = 1;
	}
	if (ft_strcmp("\t</specs>", gnl_line) == 0)
		if ((ret_tmp = one_tab_parse(&e->specs)) != 0)
			return (ret_tmp);
	if (ft_strcmp("\t<objects>", gnl_line) == 0)
	{
		e->objects = 1;
		e->skip = 1;
	}
	if (ft_strcmp("\t</objects>", gnl_line) == 0)
		if ((ret_tmp = one_tab_parse(&e->objects)) != 0)
			return (ret_tmp);
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->objects != 2 || e->specs != 2)
		return (8);
	if (e->scene != 2)
		return (6);
	if (e->ret.gnl == -1)
		return (1);
	return (0);
}

int		parser(t_env *e, int fd)
{
	t_ll	*head;

	head = NULL;
	while ((e->ret.gnl = get_next_line(fd, &e->gnl_line)) > 0)
	{
		if ((e->ret.glo = globals(e, e->gnl_line)) != 0)
			return (e->ret.glo);
		if ((e->objects == 1 || e->specs == 1) && !e->skip && ((e->ret.tag = check_tag_uniform(e, e->gnl_line)) != 0))
			return (e->ret.tag);
		if ((e->objects == 1 || e->specs == 1) && !e->skip && (e->ret.voc = check_vocab(e, e->gnl_line)) != 0)
			return (e->ret.voc);

		if (e->gnl_line)
		{
			free(e->gnl_line);
			e->gnl_line = NULL;
		}
		e->gnl_i++;
	}
	e->ll = head;
	return (last_checks(e));
}

//	if ((add_link(gnl_line, &head, e, i)) == -1)
//		return (-1);