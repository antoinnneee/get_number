
#include "get_number.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int a, char **b)
{
	int fd;

	fd = open(b[1], O_RDONLY);
	ft_putnbrnl(fd);
	get_number(fd);	
}
