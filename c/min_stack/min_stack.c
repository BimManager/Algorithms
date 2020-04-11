#include <stdlib.h>
#include <stdio.h>

typedef struct      s_node
{
    void            *content;
    size_t          content_size;
    struct s_node   *next;
}                   t_node;

typedef struct 
{
    t_node  *top;        
    t_node  *min;
}   MinStack;

static void	stackput(MinStack *stack)
{
	t_node	*it;

	it = stack->top;
	printf("stack:\n");
	while (it)
	{
		printf("%5d", *(int *)it->content);
		it = it->next;
	}
	printf("\n");
	it = stack->min;
	while (it)
	{
		printf("%5d", *(int *)(*(t_node **)it->content)->content);
		it = it->next;
	}
	printf("\n");
}

/** initialize your data structure here. */

static t_node   *nodenew(void *content, size_t content_size)
{
    t_node  *node;
    
    node = malloc(sizeof(t_node));
    node->content = malloc(content_size);
    memcpy(node->content, content, content_size);
    node->content_size = content_size;
    node->next = NULL;
    return (node);
}

static void     nodedel(t_node **node)
{
    if ((*node)->content_size)
        free((*node)->content);
    free(*node);
    *node = NULL;
}

MinStack* minStackCreate(void) 
{
    MinStack    *stack;
    
    stack = malloc(sizeof(MinStack));
    stack->top = NULL;
    stack->min = NULL;
    return (stack);
}

int minStackIsEmpty(MinStack *stack)
{
    return (NULL == stack->top);
}

static void minStackPushMin(MinStack *stack, t_node **nodeaddr)
{
    t_node  *tmp;
    t_node  *prv;
	t_node	*node;

	node = nodenew(nodeaddr, sizeof(void *));
    tmp = stack->min;
    prv = NULL;
    while (tmp && *((int *)(*(t_node **)tmp->content)->content) <
		   *(int *)(*(t_node **)node->content)->content)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    if (prv)
	{
        prv->next = node;
		node->next = tmp;
	}
    else
    {
        node->next = stack->min;
        stack->min = node;
    }
}

static void minStackPopMin(MinStack *stack, t_node **nodeaddr)
{
    t_node  *tmp;
    t_node  *prv;
    
    prv = NULL;
    tmp = stack->min;
    while (tmp)
    {
        if (*((size_t *)tmp->content) == (size_t)(*nodeaddr))
        {
            if (!prv)
				stack->min = tmp->next;
            else
                prv->next = tmp->next;
            nodedel(&tmp);
            break ;
        }
		prv = tmp;
        tmp = tmp->next;
    }
}

void minStackPush(MinStack* stack, int x)
{
    t_node  *node;
    
    node = nodenew(&x, sizeof(int));
    if (!minStackIsEmpty(stack))
        node->next = stack->top;
    stack->top = node;
    minStackPushMin(stack, &stack->top);
}

void minStackPop(MinStack* stack) 
{
    t_node  *tmp;
    
   if (!minStackIsEmpty(stack))
   {
       tmp = stack->top;
	   minStackPopMin(stack, &stack->top);
       stack->top = stack->top->next;
	   nodedel(&tmp);
   }
}

int minStackTop(MinStack* stack)
{
    if (!minStackIsEmpty(stack))
        return (*(int *)stack->top->content);
    return (-1);
}

int minStackGetMin(MinStack* stack) 
{
    if (!minStackIsEmpty(stack))
        return (*(int *)(*(t_node **)stack->min->content)->content);
    return (-1);
}

void minStackFree(MinStack* stack) 
{
    t_node  *it;
    t_node  *del;

    it = stack->top;
    while (it)
    {
        del = it;
        it = it->next;
		nodedel(&del);
    }
    it = stack->min;
    while (it)
    {
        del = it;
        it = it->next;
		nodedel(&del);
    }
	free(stack);
}

int	main(void)
{
	MinStack	*stack;

	stack = minStackCreate();
	minStackPush(stack, -42);
	minStackPush(stack, -2);
	minStackPush(stack, -3);
	stackput(stack);
	minStackPop(stack);
	minStackPop(stack);
	stackput(stack);
//	minStackPop(stack);
	printf("%d\n", minStackTop(stack));
	printf("min: %d\n", minStackGetMin(stack));
	stackput(stack);
	minStackFree(stack);
	return (0);
}
