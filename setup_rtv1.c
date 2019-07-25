/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_rtv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:28:43 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 15:28:44 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void    readbetweenthebrakets(t_env *e, int len)
{
    int     i;
    char    *str;

    i = ft_strclen(e->f_lines[0], '}') - (len + 1);
    str = (char*)malloc(sizeof(char) * i + 1);
    i = -1;
    while (e->f_lines[0][++len] != '}')
        str[++i] = e->f_lines[0][len];
    str[i] = 0;
    e->s.params = ft_strsplit(str, ','); // need to free str here 
}

void    shape_params(t_env *e)
{
    int len = 0;

    len = ft_strclen(e->f_lines[0], ' ');
    e->s.shape = (char*)malloc(sizeof(char) * len + 1);
    len = -1;
    while (e->f_lines[0][++len] != ' ')
        e->s.shape[len] = e->f_lines[0][len];
    e->s.shape[len] = 0;
    len++;
    readbetweenthebrakets(e, len);
    printf("shape : [%s]\n", e->s.shape);
    printf("[%s | %s | %s]\n", e->s.params[0], e->s.params[1], e->s.params[2]);
}

void    setup_rtv1(t_env *e)
{
    // int i = 0;

    // while (e->f_lines[i])
    // {
    //     printf("[%s]\n", e->f_lines[i]);
    //     i++;
    // }
    shape_params(e);
    draw_sphere(e);
}