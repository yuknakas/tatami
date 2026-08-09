#include "../include/tatami.h"

void		print_valid(t_tatami *tatami);
static char	*add_space(const char *str);
static void	print_space(t_tatami *tatami);

void		print_valid(t_tatami *tatami)
{
	if (!check_valid(tatami))
	{
		tatami->invalid++;
		return ;
	}
	if (strchr(tatami->option, 's'))
		print_space(tatami);
	else
	{
		for (int i = 0; i < tatami->max_x; i++)
		{
			printf("%s\n", tatami->map[i]);
			// write(1, "\n", 1);
		}
		printf("\n");
	}
	tatami->valid++;
}

static char	*add_space(const char *str)
{
	char	*ans;
	size_t	len, i, j;

	len = strlen(str);
	ans  = malloc(len * 2 - 1);
	if (!ans)
	{
		printf("Err: malloc\n");
		return (NULL);
	}
	i = j = 0;
	while (1)
	{
		ans[j++] = str[i++];
		if (i == len)
			break;
		ans[j++] = ' ';
	}
	return (ans);
}

static void	print_space(t_tatami *tatami)
{
	char	*buf;

	for (int i = 0; i < tatami->max_x; i++)
	{
		buf = add_space(tatami->map[i]);
		printf("%s\n", add_space(buf));
		free(buf);
	}
	printf("\n");
}
