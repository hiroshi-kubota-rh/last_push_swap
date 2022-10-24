/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check(char const s, char c)
{
    if (s == c)
        return (1);
    else
        return (0);
}

static int		box_num(char const *s, char c)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    while (s[j])
    {
        if (check(s[j], c) == 0 && check(s[j + 1], c) == 1)
            i++;
        else if (check(s[j], c) == 0 && s[j + 1] == '\0')
            i++;
        j++;
    }
    return (i);
}

static char		*into_box(const char *s, char c, int i)
{
    char	*tmp;
    int		b;
    int		e;

    b = 0;
    e = 0;
    while (i-- >= 0)
    {
        b = b + e;
        e = 0;
        while (check(s[b], c) == 1)
            b++;
        while (check(s[b + e], c) == 0)
            e++;
    }
    if (!(tmp = (char *)malloc(sizeof(char) * (e + 1))))
        return (NULL);
    tmp = ft_memcpy(tmp, (s + b), e);
    tmp[e] = '\0';
    return (tmp);
}

char			**ft_split(char const *s, char c)
{
    char	**box;
    int		i;

    i = 0;
    if (s == NULL)
        return (NULL);
    if (!(box = (char **)malloc(sizeof(char *) * (box_num(s, c) + 1))))
        return (NULL);
    while (i < box_num(s, c))
    {
        box[i] = into_box(s, c, i);
        if (box[i] == NULL)
        {
            while (i >= 0)
                free(box[i--]);
            free(box);
            return (NULL);
        }
        i++;
    }
    box[i] = NULL;
    return (box);
}
