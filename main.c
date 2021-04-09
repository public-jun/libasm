/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:33:11 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/09 21:08:08 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dst, const char *src);

static char	*get_char_p_malloc(char *src)
{
	size_t	size;
	char	*res;

	size = strlen(src);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!(res))
	{
		printf("error\n");
		exit(0);
	}
	res[size] = '\0';
	return (res);
}

int		test_ft_strcpy(char *src)
{
	char *dst;

	dst = get_char_p_malloc(src);
	printf("\x1b[44m------ft_strcpy------\033[m\n");
	ft_strcpy(dst, src);
	printf("ft_strcpy		:%s\n", dst);
	free(dst);
	dst = NULL;
	dst = get_char_p_malloc(src);
	strcpy(dst, src);
	printf("ft_strcpy		:%s\n", dst);
	free(dst);
	dst = NULL;
	printf("\x1b[34mnull_test\033[m\n");
	dst = get_char_p_malloc(src);
	ft_strcpy(dst, "");
	printf("ft_strcpy		:%s\n", dst);
	free(dst);
	dst = NULL;
	dst = get_char_p_malloc(src);
	strcpy(dst, "");
	printf("ft_strcpy		:%s\n", dst);
	free(dst);
	dst = NULL;
	while(1);
	return (0);
}


int		test_ft_strlen(char *src)
{
	int		res;
	char	*s;
	size_t	size;

	size = strlen(src);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!(s))
	{
		printf("error\n");
		return (-1);
	}
	s[size] = '\0';
	strcpy(s, src);
	printf("\x1b[44m------ft_strlen------\033[m\n");
	res = 0;
	res = ft_strlen(s);
	printf("ft_strlen		:%d\n", res);
	res = 0;
	res = strlen(s);
	printf("strlen			:%d\n", res);
	free(s);
	s = NULL;
	printf("\x1b[34mnull_test\033[m\n");
	char *nl = "";
	res = 0;
	res = ft_strlen(nl);
	printf("ft_strlen		:%d\n", res);
	res = 0;
	res = strlen(nl);
	printf("strlen			:%d\n", res);
	return (0);
}

int	main(int ac, char **argv)
{
	if (ac != 3)
		return (-1);
	if (!(strncmp(argv[1], "ft_strlen", 10)))
	{
		if (argv[2])
			return (test_ft_strlen(argv[2]));
		else
		{
			printf("error\n");
			return (-1);
		}
			
	}
	if (!(strncmp(argv[1], "ft_strcpy", 10)))
	{
		if (argv[2])
			return (test_ft_strcpy(argv[2]));
		else
		{
			printf("error\n");
			return (-1);
		}
			
	}
	else
		return (0);
}
