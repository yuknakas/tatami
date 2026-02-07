#include "../include/tatami.h"

bool		init(t_tatami *tatami, int argc, char **argv);
static bool invalid_args(int x, int y);

bool	init(t_tatami *tatami, int argc, char **argv)
{
	if (argc != 3)
		return (true);

	tatami->max_x = atoi(argv[2]);
	tatami->max_y = atoi(argv[1]);
	if (invalid_args(tatami->max_x, tatami->max_y))
		return (true);
	
	tatami->map = malloc(tatami->max_x * sizeof(char *));
	if (!tatami->map)
		return (true);
	for (int i = 0; i < tatami->max_x; i++)
	{
		tatami->map[i] = calloc(tatami->max_y + 1, sizeof(char));
		if (!tatami->map[i])
		{
			clean(tatami, i);
			return (true);
		}
	}

	tatami->x = 0;
	tatami->y = 0;
	tatami->total = 0;
	tatami->valid = 0;
	tatami->invalid = 0;
	return (false);
}

static bool invalid_args(int x, int y)
{
	if (x < 1 || y < 1 || (x * y) % 2)
		return (true);
	return (false);
}

void	clean(t_tatami *tatami, int i)
{
	for (int x = 0; x < i; x++)
		free(tatami->map[x]);
	free(tatami->map);
}
