/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:36:14 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 18:36:26 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		add_link_light(t_env *e, t_ll **head, int i)
{
	(void)i;
	(void)e;
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	// new->content = line;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}

int		add_link_obj(t_env *e, t_ol **head, int i)
{
	(void)i;
	(void)e;
	t_ol	*new;
	t_ol	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ol*)malloc(sizeof(t_ol))))
		return (-1);
	// new->content = line;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}
