#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	fresh_link;

	fresh_link = (t_list)ft_memalloc(sizeof(t_list));
	if (!(content))
	{
		fresh_link->content = NULL;
		fresh_link->content_size = 0;
	}
	else
	{
		fresh_link->content_size = content_size;
		fresh_link->content = content;
	}	
	fresh_link->next = NULL;
	free(fresh_link);
	return (fresh_link);
}
