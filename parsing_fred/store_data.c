/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:52:01 by ftanon            #+#    #+#             */
/*   Updated: 2024/09/07 12:55:13 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty(t_mlx *mlx, char *temp, char *concat)
{
	int	i;

	i = 0;
	if (concat[0] == '\0')
	{
		error_message(4);
		free(temp);
		return (1);
	}
	while (concat[i] != '\0')
	{
		if (concat[i] == '\n' && concat[i + 1] == '\n')
		{
			error_message(5);
			free(temp);
			return (1);
		}
		i++;
	}
	mlx->map_char = ft_split(concat, '\n');
	free(concat);
	return (0);
}

int	is_empty2(t_mlx *mlx, char *temp, char *concat)
{
	int	i;

	i = 0;
	if (concat[0] == '\0')
	{
		error_message(4);
		free(temp);
		return (1);
	}
	while (concat[i] != '\0')
	{
		if (concat[i] == '\n' && concat[i + 1] == '\n')
		{
			error_message(5);
			free(temp);
			return (1);
		}
		i++;
	}
	mlx->textures = ft_split(concat, '\n');
	free(concat);
	return (0);
}

int	store_six_line(t_mlx *mlx, char **string)
{
	int		counter;
	char	*concat2;
	char	*temp;
	counter = 0;
	concat2 = ft_strdup("");
	while (1)
	{
		if (counter == 6)
			break;
		*string = NULL;
		temp = concat2;
		*string = get_next_line(mlx->fd);
		if (string)
		{
			if (has_alpha_num(*string))
			{
				concat2 = ft_strjoin(temp, *string);
				free(*string);
				free(temp);
				// mlx->textures[counter] = ft_strdup(string);
				// parse_information(mlx, string);
				counter++;
			}
			else
				free(*string);
		}
		else
			break;
	}
	if (is_empty2(mlx, temp, concat2) == 1)
		return (1);
	return (0);
}

int	skip_empty_line(t_mlx *mlx, char **string)
{
	while (1)
	{
		*string = get_next_line(mlx->fd);
		if (*string)
		{
			if (!has_alpha_num(*string))
			{
				free(*string);
				continue;
			}
			else
				break;
		}
		else
			break;
	}
	return (0);
}

int	store_map_char(t_mlx *mlx, char **string)
{
	char	*temp;
	char	*concat;

	concat = ft_strdup("");
	temp = concat;
	concat = ft_strjoin(temp, *string);
	free(*string);
	free(temp);

	while (1)
	{
		*string = NULL;
		temp = concat;
		*string = get_next_line(mlx->fd);
		if (*string)
		{
			concat = ft_strjoin(temp, *string);
			free(*string);
			free(temp);
		}
		else
			break;
	}
	if (is_empty(mlx, temp, concat) == 1)
		return (1);
	return (0);
}

int	store_data(t_mlx *mlx)
{
	char	*string;

	string = NULL;
	store_six_line(mlx, &string);
	skip_empty_line(mlx, &string);
	if (string == NULL)
		return (1);
	else
		store_map_char(mlx, &string);
	// printf("%s\n", string);
	return (0);
}