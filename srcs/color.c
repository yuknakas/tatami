#include "../include/tatami.h"

char	findcolor_vert(t_tatami *tatami);
char	findcolor_hori(t_tatami *tatami);

char	findcolor_vert(t_tatami *tatami)
{
	bool color[4];

	color[0] = color[1] = color[2] = color[3] = true;
	if (tatami->x)
		color[tatami->map[tatami->x - 1][tatami->y] - 'A'] = false;
	if (tatami->y)
	{
		color[tatami->map[tatami->x][tatami->y - 1] - 'A'] = false;
		color[tatami->map[tatami->x + 1][tatami->y - 1] - 'A'] = false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (color[i])
			return ('A' + i);
	}
	return ('E');
}

char	findcolor_hori(t_tatami *tatami)
{
	bool color[4];

	color[0] = color[1] = color[2] = color[3] = true;
	if (tatami->x)
	{
		color[tatami->map[tatami->x - 1][tatami->y] - 'A'] = false;
		color[tatami->map[tatami->x - 1][tatami->y + 1] - 'A'] = false;
	}
	if (tatami->y)
		color[tatami->map[tatami->x][tatami->y - 1] - 'A'] = false;
	for (int i = 0; i < 4; i++)
	{
		if (color[i])
			return ('A' + i);
	}
	return ('E');
}
