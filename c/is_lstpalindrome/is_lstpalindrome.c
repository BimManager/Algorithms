/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lstpalindrome.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:33:59 by kkozlov           #+#    #+#             */
/*   Updated: 2019/12/30 17:37:13 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct				ListNode 
{
	int				val;
	struct ListNode	*next;
};

static int				lstmid(struct ListNode *head)
{
    int len;
    
    len = 0;
    while (head)
    {
        head = head->next;
        ++len;
    }
    return (len / 2);
}

static struct ListNode	*lstrev(struct ListNode *head)
{
    struct ListNode *prv;
    struct ListNode *cur;
    struct ListNode *tmp;
    
    if (!head)
        return (NULL);
    prv = NULL;
    cur = head;
    while (cur)
    {
        tmp = cur;
        cur = cur->next;
        tmp->next = prv;
        prv = tmp;
    }
    return (prv);
}

int						is_lstpalindrome(struct ListNode* head)
{
    int				mid;
    int				i;
    struct ListNode	*it;
    
    mid = lstmid(head);
    it = head;
    i = -1;
    while (++i < mid)
        it = it->next;
    it = lstrev(it);
    while (mid--)
    {
        if (head->val != it->val)
            return (0);
        head = head->next;
        it = it->next;
    }
    return (1);
}
