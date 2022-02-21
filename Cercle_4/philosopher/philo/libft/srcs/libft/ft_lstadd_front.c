/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:25:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/08 14:32:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*first;

	first = *alst;
	new->next = first;
	*alst = new;
}

void	ft_chainadd_front(t_chain **alst, t_chain *new)
{
	t_chain	*first;

	first = *alst;
	new->next = first;
	first->back = new;
	*alst = new;
}
