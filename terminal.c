#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char *str;
	int	i;

	i = 0;
	while (i < 2)
	{
		str = readline("➜  ");
		printf("str = %s\n", str);
		free(str);

		i++;
	}

}