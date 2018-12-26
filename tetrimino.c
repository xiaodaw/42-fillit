#include "fillit.h"

t_tet	*new_tet(char *str, int top, int left, int count)
{
	t_tet	*tet;
	int		i;
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	if (!(tet = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	tet->row = top;
	tet->col = left;
	tet->letter = alpha[count];
	while (i < 20)
	{
		if (!(i != 0 && i % 5 == 4))
			tet->shape[i / 5][i % 5] = str[i];
		i++;
	}
	return (tet);
}

void	add_tet(t_board *bd, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < (4 - tet->row))
	{
		j = 0;
		while (j < (4 - tet->col))
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
				(bd->board)[row + i][col + j] = tet->letter;
			j++;
		}
		i++;
	}
	return ;
}

void	delete_tet(t_board *bd, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < (4 - tet->row))
	{
		j = 0;
		while (j < (4 - tet->col))
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
				(bd->board)[row + i][col + j] = 0;
			j++;
		}
		i++;
	}
	return ;
}

t_tet	*check_tet(char *str, int count)
{
	int		i;
	int		j;
	t_piece	piece;

	initialize_piece(&piece);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (str[i] != '\n')
				return (NULL);
			j++;
		}
		else if (!(str[i] == '#' || str[i] == '.'))
			return (NULL);
		else if (str[i] == '#')
			modify_piece(&piece, str, i, j);
		i++;
	}
	if (piece.num == 4 && (piece.connection == 6 || piece.connection == 8))
			return (new_tet(str, p.top, p.left, count));
	return (NULL);
}
