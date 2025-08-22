#include "includes/libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <dlfcn.h>

int y;
typedef char* gnl(int);

int main(int argc, char **argv)
{
	char *line;
	void *f = NULL;
	int fd = open(argv[1], O_RDONLY);
	do
	{
		system("make dynamic 2>&1 >/dev/null");
		f = dlopen("libft_malloc_x86_64_Darwindyn.dylib", RTLD_NOW);
		gnl *g =  dlsym(f, "get_next_line");
		line = (*g)(fd);
		if (line) {
			write(1, line, ft_strlen(line));
			sleep(1);
		}
		dlclose(f);
		dlclose(f);
	} while (line);
	return 0;
}

// x is a copy not the real x
// void function(int x) {
// 	x = 10;
// }

// int main1() {
// 	int x = 9;
// 	function(x);
// }
