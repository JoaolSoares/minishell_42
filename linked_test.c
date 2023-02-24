#include <stdio.h>
#include <string.h>
#include "lib/include/libft.h"

typedef struct	s_node
{
	char			*content;
	struct s_node	*next;

}	t_node;


void	print_linked_list(t_node *root)
{
	t_node *aux;

	aux = root;
	while (aux)
	{
		ft_printf("%s\n", aux->content);
		aux = aux->next;
	}
}

void	free_linked_list(t_node *root)
{
	t_node *aux;
	t_node *aux_next;

	aux = root;
	aux_next = root->next;

	while (aux->next)
	{
		free(aux->content);
		free(aux);
		aux = aux_next;
		aux_next = aux->next;
	}
	free(aux->content);
	free(aux);
	free(aux_next);
}

void	insert_in_list(t_node **node, char *content)
{
	t_node *new_node;
	t_node *aux;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = ft_strdup(content);
	new_node->next = NULL;

	if (!*node)
	{
		*node = new_node;
		return ;
	}
	
	aux = *node;
	while (aux->next)
		aux = aux->next;
	aux->next = new_node;
}

void	envp_linked_list(t_node **root, char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		insert_in_list(root, envp[i]);
}


int main(int argc, char **argv, char **envp)
{
	t_node *root;

	root = NULL;
	envp_linked_list(&root, envp);

	print_linked_list(root);
	free_linked_list(root);

	return (0);
}
