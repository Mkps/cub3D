#include "../../include/cub3d.h"

static int	is_skipped(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

static int	is_bound(t_data *data, int i, int j)
{
	if (i <= 0 || i >= data->mapinfo.height - 1 || j <= 0
		|| (data->cmap[i] && (size_t)j >= ft_strlen(data->cmap[i])))
		return (0);
	if (data->cmap[i - 1][j] == ' ' || data->cmap[i][j - 1] == ' ')
		return (0);
	if ((size_t)j > ft_strlen(data->cmap[i - 1]) - 1)
		return (0);
	if ((size_t)j > ft_strlen(data->cmap[i + 1]) - 1)
		return (0);
	return (1);
}

void	spacehandler(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->cmap[i])
	{
		j = 0;
		while (is_skipped(data->cmap[i][j]))
			j++;
		while (data->cmap[i][j])
		{
			if (is_skipped(data->cmap[i][j])
				&& is_bound(data, i, j))
				data->cmap[i][j] = '1';
			j++;
		}
		i++;
	}
}
