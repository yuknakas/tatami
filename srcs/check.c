#include "../include/tatami.h"

static bool	check_invalid(t_tatami *tatami);

void	check(t_tatami *tatami)
{
	tatami->total++;
	if (check_invalid(tatami))
		tatami->invalid++;
	else
		tatami->valid++;
	for (int i = 0; i < tatami->max_x; i++)
	{
		write(1, tatami->map[i], tatami->max_y);
		write(1, "\n", 1);
	}
	printf("\n");	
}

static bool	check_invalid(t_tatami *tatami)
{
	for (int x = 0; x < tatami->max_x - 1; x++)
	{
		for (int y = 0; y < tatami->max_y - 1; y++)
		{
			if (tatami->map[x][y] != tatami->map[x + 1][y] &&
				tatami->map[x][y] != tatami->map[x][y + 1] &&
				tatami->map[x + 1][y] != tatami->map[x + 1][y + 1] &&
				tatami->map[x][y + 1] != tatami->map[x + 1][y + 1])
				return (true);
		}
	}
	return (false);
}