#include <stdlib.h>
#include <stdio.h>

struct				s_node
{
     int 			val;
     struct s_node	*next;
};

struct s_node *itrev(struct s_node *head)
{
    struct s_node *prv;
    struct s_node *cur;
    struct s_node *nxt;
    
    prv = NULL;
    cur = head;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    return (prv);
}

struct s_node *recrev(struct s_node *curr, struct s_node **head)
{
    struct s_node *ret;
    
    if (!curr->next)
    {
        *head = curr;
        return (curr);
    }
    ret = recrev(curr->next, head);
    ret->next = curr;
    return (curr);
}

struct s_node* reverseList(struct s_node* head)
{
    struct s_node *ret;
    
    if (!head)
        return (NULL);
    ret = recrev(head, &head);
    ret->next = NULL;
    return (head);
//    return (itrev(head));
}

typedef struct s_node	t_node;

t_node	*nodenew(int v)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->next = NULL;
  node->val = v;
  return (node);
}
	

int	main(void)
{
  t_node	*head;
  t_node	*rev;

  head = nodenew(1);
  head->next = nodenew(2);
  head->next->next = nodenew(3);
  rev = reverseList(head);
  while (rev)
	{
	  printf("%3d", rev->val);
	  rev = rev->next;
	}
  printf("\n");
  return (0);
}

