
#include "get_number.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "GNL_NOFD/libft/includes/libft.h"

int main(int a, char **b)
{
	int fd;
	int	**tab;
	a = 0;
	fd = open(b[1], O_RDONLY);
	tab = get_number(fd);
	if (tab)
	{
	ft_putstr("print tab : \n");
	print_map_number(tab);
	}
	else
	{
		ft_putendl("Error Map");
	}
	return (0);
}
