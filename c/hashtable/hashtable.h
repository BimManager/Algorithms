#ifndef HASHTABLE_H
# define HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct		s_data
{
	void			*content;
	size_t			size;
}					t_data;

typedef struct		s_htnode
{
	t_data			*data;
	char			*key;
	struct s_htnode	*next;
}					t_htnode;

typedef struct		s_hstbl
{
	t_htnode		**entries;
	size_t			capacity;
}					t_hstbl;

t_data		*datanew(void *content, size_t size)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->content = malloc(size);
	data->size = size;
	memcpy(data->content, content, size);
	return (data);
}

t_hstbl		*hstblnew(size_t capacity)
{
	t_hstbl	*ht;

	ht = malloc(sizeof(t_hstbl));
	ht->capacity = capacity;
	ht->entries = malloc(ht->capacity * sizeof(void *));
	bzero(ht->entries, ht->capacity * sizeof(void *));
	return (ht);
}

size_t		hstblhash(char *key, size_t htsize)
{
	size_t	hash;

	
}

int			hstbladd(t_hstbl *ht, void *content, size_t content_size, char *key)
{
	t_data	*data;

	data = datanew(content, content_size);
	
}

#endif
