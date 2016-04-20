#include "get_number.h"
#include "GetNextLine/get_next_line.h"
#include "GetNextLine/libft/includes/libft.h"

static int	*get_dim(const char *line)
{
	int	*dim;
	int	*buffer;
	int	count;
	int	cursor;
	int	tmpcursor;

	count = 0;
	cursor = 0;
	tmpcursor = 0;
	dim = (int*) ft_memalloc(sizeof(int) * (count + 1));
	while(line[cursor] != 0)
	{
		if (ft_isdigit(line[cursor]))
		{
			tmpcursor = cursor;
			while(ft_isdigit(line[cursor]))
				cursor++;
			count++;
		}
		else if (count > 0)
		{
			buffer = (int*) ft_memalloc(sizeof(int) * (count));
			ft_memmove(buffer, dim, sizeof(int) * count);
			dim = (int*) ft_memalloc(sizeof(int) * (count + 2));
			ft_memmove(dim, buffer, sizeof(int) * count);
		}
		dim[count-1] = ft_atoi(ft_strsub(line, tmpcursor, cursor - tmpcursor));
		cursor++;
	}
	dim[count] = ft_atoi(ft_strsub(line, tmpcursor, cursor - tmpcursor));
	return (dim);
}

int **get_number(int fd)
{
	int	**tabnumber;
	int	**buffer;
	char	*line;
	int	nbline;
	
	nbline = 0;
	tabnumber = (int**) ft_memalloc(sizeof(int*) * (nbline + 1));
	while(get_next_line(fd, &line) == 1)
	{
		if (nbline > 0)
		{
			buffer = (int**) ft_memalloc(sizeof(int*) * (nbline));
			ft_memmove(buffer, tabnumber, sizeof(int*) * nbline);
			tabnumber = (int**) ft_memalloc(sizeof(int*) * (nbline + 1));
			ft_memmove(tabnumber, buffer, sizeof(int*) * nbline );
		}
		tabnumber[nbline] = get_dim(ft_strtrim(line));
		nbline++;
	
	}
	int k = 0;
	while (k < 3)
	{	
		ft_putnbr(tabnumber[0][k]);ft_putchar('-');
		k++;
	}
	k = 0;
	ft_putchar('\n');
	while (k < 3)
	{	
		ft_putnbr(tabnumber[1][k]);ft_putchar('-');
		k++;
	}
	k = 0;
	ft_putchar('\n');
	while (k < 3)
	{	
		ft_putnbr(tabnumber[2][k]);ft_putchar('-');
		k++;
	}
	ft_putchar('\n');
/*
	while (k-- >= 0)
	ft_putnbr(tabnumber[1][k]);
	k = 3;
	while (k-- >= 0)
	ft_putnbr(tabnumber[2][k]);
*/
	return (tabnumber);
}



