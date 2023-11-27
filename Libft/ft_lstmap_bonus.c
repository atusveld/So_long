/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:56:57 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 17:56:59 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelmnt;

	newlst = NULL;
	while (lst)
	{
		newelmnt = ft_lstnew((*f)(lst->content));
		if (newelmnt)
		{
			lst = lst->next;
			ft_lstadd_back(&newlst, newelmnt);
		}
		else
		{
			ft_lstclear(&newelmnt, (*del));
			return (NULL);
		}
	}
	return (newlst);
}
