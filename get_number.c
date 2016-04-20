#include "get_number.h"
#include "GNL_NOFD/get_next_line.h"
#include "GNL_NOFD/libft/includes/libft.h"

static int	*initfirst(int chose)
{
	int	count;
	int	*dim;

	count = 0;
	dim = (int*) ft_memalloc(sizeof(int) * (count + 1));
		dim[count] = chose;
		return (dim);
}

static void	myrealloc(int **dim, int **buffer, int count)
{
			*buffer = (int*) ft_memalloc(sizeof(int) * (count));
			ft_memmove(*buffer, *dim, sizeof(int) * count);
			*dim = (int*) ft_memalloc(sizeof(int) * (count + 2));
			ft_memmove(*dim, *buffer, sizeof(int) * count);
}

static int	*get_dim(const char *line)
{
	int	*dim;
	int	*buffer;
	int	count;
	int	cursor;
	int	tmpcursor;

	ft_initthreevar(&count, &cursor, &tmpcursor);
	while(line[cursor] != 0)
	{
		if (ft_isdigit(line[cursor]) || (line[cursor] == '-' && ft_isdigit(line[cursor + 1])))
		{
			tmpcursor = cursor;
			cursor++;
			while(ft_isdigit(line[cursor]))
				cursor++;
			count++;
		}
		else if (count > 0)
			myrealloc(&dim, &buffer, count);
		dim[count] = ft_atoi(ft_strsub(line, tmpcursor, cursor - tmpcursor));
		cursor++;
	}
	dim[count + 1] = ft_atoi(ft_strsub(line, tmpcursor, cursor - tmpcursor));
	dim[0] = count;
	return (dim);
}

void		print_map_number(int **arraynum)
{
	int	index;
	int	line;

	index = 1;
	line = 1;
	while (line < arraynum[0][0])
	{
		while (index < (arraynum[line][0]))
		{
			ft_putnbr(arraynum[line][index]);
			ft_putchar(' ');
			index++;
		}
		ft_putchar('\n');
		index = 1;
		line++;
	}
}
int			contain_letter(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isalpha(line[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

int			**get_number(int fd)
{
	int	**tabnumber;
	int	**buffer;
	char	*line;
	int	nbline;
	
	nbline = 1;
	while(get_next_line(fd, &line) == 1)
	{
		if (contain_letter(line))
			return (NULL);
		buffer = (int**) ft_memalloc(sizeof(int*) * (nbline + 1));
		ft_memmove(buffer, tabnumber, sizeof(int*) * nbline + 1);
		tabnumber = (int**) ft_memalloc(sizeof(int*) * (nbline + 2));
		ft_memmove(tabnumber, buffer, sizeof(int*) * nbline + 1);
		tabnumber[nbline ] = get_dim(ft_strtrim(line));
		nbline++;
	}
	tabnumber[0] = initfirst(nbline);
	return (tabnumber);
}



