#include "includes/libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main1(int argc, char **argv)
{
	char *line;
	int fd = open(argv[1], O_RDONLY);
	do
	{
		line = get_next_line(fd);
		if (line) {
			write(1, line, ft_strlen(line));
			ft_strlen(line);
		}
	} while (line);
	return 0;
}

// x is a copy not the real x
void function(int x) {
	x = 10;
}

int main() {
	int x = 9;
	function(x);
}
