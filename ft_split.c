/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:49:58 by foctavia          #+#    #+#             */
/*   Updated: 2022/05/05 19:17:26 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char **dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
}

static int	count_substr(const char *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (c == 0)
		return (1);
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			count++;
	}
	return (count);
}

static char	**free_str(char **str, int k)
{
	while (k >= 0)
		free(str[k]);
	free(str);
	return (NULL);
}

static char	**fill_substr(char const *s, char c, char **str, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i] && k < count)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		str[k] = malloc(sizeof(char) * (i - j + 1));
		if (!str[k])
			return (free_str(str, k));
		ft_strncpy(&str[k++], &s[j], i - j + 1);
	}
	str[count] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**str;

	i = 0;
	if (!s || s[i] == '\0')
		count = 0;
	else
		count = count_substr(s, c);
	str = malloc (sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str = fill_substr(s, c, str, count);
	return (str);
}

//  int	main(int argc, char **argv)
//  {
// 	char	**new;
// 	int	i;
// 	int	count;

// 	(void) argc;
// 	if (argc != 3)
// 		return (1);
// 	i = 0;
// 	new = ft_split(argv[1], argv[2][0]);
// 	count = count_substr(argv[1], argv[2][0]);
// 	while (i < count)
// 	{
// 		printf ("%s\n", new[i]);
// 		free (new[i]);
// 		i++;
// 	}
// 	printf ("\ncount : %d\n", count);
// 	free (new);
// }
