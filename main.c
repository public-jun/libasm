/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:33:11 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/12 11:24:17 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libasm.h"


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

int		test_ft_strcmp(char *s1, char *s2)
{
	int	res;

	printf("\x1b[44m------ft_strcmp------\033[m\n");
	res = ft_strcmp(s1, s2);
	printf("ft_strcmp	:	%s , %s		:%d\n", s1, s2, res);
	res = strcmp(s1, s2);
	printf("strcmp		:	%s , %s		:%d\n", s1, s2, res);

	printf("\x1b[34mnull_test\033[m\n");
	res = ft_strcmp("", "");
	printf("ft_strcmp	:	%s , %s		:%d\n", "", "", res);
	res = strcmp("", "");
	printf("strcmp		:	%s , %s		:%d\n", "", "", res);
	res = ft_strcmp(s1, "");
	printf("ft_strcmp	:	%s , %s		:%d\n", s1, "", res);
	res = strcmp(s1, "");
	printf("strcmp		:	%s , %s		:%d\n", s1, "", res);
	res = ft_strcmp("", s2);
	printf("ft_strcmp	:	%s , %s		:%d\n", "", s2, res);
	res = strcmp("", s2);
	printf("strcmp		:	%s , %s		:%d\n", "", s2, res);
	//res = ft_strcmp(NULL, s2);
	//printf("ft_strcmp	:	NULL , %s		:%d\n",  s2, res);
	res = strcmp(NULL, s2);
	printf("strcmp		:	NULL , %s		:%d\n",  s2, res);
	return (0);
}

void	test_write(int fd, char *buf, size_t len)
{
	printf("------libc---------\n");
	errno = 0;
	printf("write\t\t");
	fflush(stdout);
	ssize_t ret_libc = ft_write(fd, buf, len);
	int	errno_libc = errno;
	printf("\tlibc	: ret=%zd errno=%d\n", ret_libc, errno);
	errno = 0;
	printf("------libasm---------\n");
	printf("ft_write\t");
	fflush(stdout);
	ssize_t ret_asm = write(fd, buf, len);
	int	errno_asm = errno;
	printf("\tlibasm	: ret=%zd errno=%d\n", ret_asm, errno);
	errno = 0;
	printf("\n\n");

}


int	main(int ac, char **argv)
{
	if (ac != 3 && ac != 2 && ac != 4)
		return (-1);
	if (!(strncmp(argv[1], "strlen", 7)))
	{
		if (argv[2])
			return (test_ft_strlen(argv[2]));
		else
		{
			printf("error\n");
			return (-1);
		}
			
	}
	else if (!(strncmp(argv[1], "strcpy", 7)))
	{
		if (argv[2])
			return (test_ft_strcpy(argv[2]));
		else
		{
			printf("error\n");
			return (-1);
		}
			
	}
	else if (!(strncmp(argv[1], "strcmp", 7)))
	{
		if (argv[2] && argv[3])
			return (test_ft_strcmp(argv[2], argv[3]));
		else
		{
			printf("error\n");
			return (-1);
		}
	 }
	else if (!(strncmp(argv[1], "write", 6)))
	{
		printf("\x1b[44m------ft_write------\033[m\n");
		test_write(1, "test", 4);
		test_write(1, "test", 100);
		test_write(1, "test", 0);
		test_write(1, "   ", 2);
		test_write(1, "", 2);
		int fd = open("test_write.txt", O_WRONLY | O_APPEND | O_CREAT, S_IREAD | S_IWRITE);
		test_write(fd, "test\n", 5);

		printf("~~~~~~~~error_case~~~~~~~~~~~~\n");
		fflush(stdout);
		test_write(42, "test", 4);
		test_write(42, "t", 1);
		test_write(42, "", 1);
		test_write(fd, "NULL", 2);
		test_write(-1, "test", 4);
		test_write(1, "123456789", -1);

		close(fd);
		return (0);
	}
	else
		return (0);
}
