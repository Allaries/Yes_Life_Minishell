#include "pipex.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

int	here_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if (s1[i] == '\n' && s2[i] == '\0')
				return (0);
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	heredoc_init(char *hname)
{
	int		fdhere;
	char	*str;

	fdhere = open(hname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	// if (unlink(hname) == -1);
	// {
	// 	perror("ERROR ");
	// 	return (0);
	// }
	while (1)
	{
		str = get_next_line(1);
		if (here_strncmp(str, hname, ft_strlen(hname) + 1) != 0)
		{
			write(fdhere, str, ft_strlen(str));
			free(str);
		}
		else
			return (free(str), fdhere);
	}
	if (str)
		free(str);
	return (0);
}

// int	main(void)
// {
// 	int	fd;
// 	fd = heredoc_init("test la famille\n");
// }