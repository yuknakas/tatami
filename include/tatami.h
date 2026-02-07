#ifndef TATAMI_H
# define TATAMI_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_tatami
{
	char	**map;
	int		max_x;
	int		max_y;
	int		x;
	int		y;
	int		total;
	int		valid;
	int		invalid;
} t_tatami;

// init
bool	init(t_tatami *tatami, int argc, char **argv);
void	clean(t_tatami *tatami, int i);
void	place(t_tatami *tatami);
char	findcolor(t_tatami *tatami);
void	check(t_tatami *tatami);

# define COLORS "ABCD"

#endif