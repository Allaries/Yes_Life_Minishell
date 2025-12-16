#include "pipex.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

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
		if (ft_strncmp(str, hname, ft_strlen(hname)) != 0)
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
// 	fd = heredoc_init("youpi");
// }