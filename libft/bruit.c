// this function read from fd and add to the linked list
void	read_list(int fd, t_list **list, int *readed)
{
	char *buf;
	t_list *ptr;
	int n;
	t_list *new_node;


	*readed = 0;
	ptr = *list;
	buf = malloc(BUFFER_SIZE);
	//read the bytes of data from the file fd and store it in buffer buf
	while(n = read(fd, buf, sizeof(BUFFER_SIZE)) > 0)
	{
		new_node = malloc(sizeof(t_list));// add a new node to the linked list using malloc
		new_node->content = malloc(n);// allocate memory for data of the new node
		ft_memcpy(new_node->next, buf, n); //copy nbyte from the buffer to new node
		new_node = 0; //set the new node to null
		if(!ptr)
		{
			//if is empty set the new head to the new node
			*list = new_node;
		}
		else{
			ptr->next = new_node; //add the new node to the end of the linked list
		}
		ptr = new_node; //update the pointer to the last node in the linked list
		*readed += n;
	}
	free(buf);
}

int		found_newline(t_list *list){
	int i;
	t_list *current;

	i = 0;
	if(list == 0)
		return (0);
	current = get_the_last(list);
	while(current->content[i]){
		if(current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);

}
//return a pointer to the last node in the list
t_list *get_the_last(t_list *list)
{
	t_list *current;
	if(current == 0)
		return (0);
	current = list;
    // Loop through the list until we reach the last element
	while(current->next != 0){
		current = current->next;
	}
	return(current);
}

void calc_line_char(char **line, t_list *list)
{
	int 	i;
	int 	len;
	t_list *current;
	char	*ptr;

	i = 0;
	len = 0;
	current = list;
	ptr = malloc(sizeof(char *) * (len + 1));
	while (current)
	{
		/* code */
		while(current->content[i])
		{
			len++;
			if(current->content[i] == '\n')
			{
				break;
			}
			i++;
		}
		current = current->next;
	}

}
