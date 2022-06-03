/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:37:02 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/18 20:27:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFFER_SIZE 4096

# include <stddef.h>

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memcpy(void *dst, void const *src, size_t len);

void	*ft_memccpy(void *dst, void const *src, int c, size_t n);

void	*ft_memmove(void *dst, void const *src, size_t len);

void	*ft_memchr(void const *s, int c, size_t n);

int		ft_memcmp(void const *s1, void const *s2, size_t n);

size_t	ft_strlen(char const *s);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_isspace(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(char const *s, int c);

char	*ft_strrchr(char const *s, int c);

int		ft_strncmp(char const *s1, char const *s2, size_t n);

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);

char	*ft_strnstr(char const *haystack, char const *needle, size_t len);

int		ft_atoi(char const *s);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s, char const *set);

char	**ft_split(char const *s, char const *set);

char	*ft_itoa(int n);

size_t	ft_strnlen(char const *s, size_t maxlen);

char	*ft_strndup(char const *s, size_t len);

int		ft_strtoi(char const *s, char **endptr);

int		ft_strcmp(char const *s1, char const *s2);

size_t	ft_strcspn(char const *s, char const *reject);

size_t	ft_strspn(char const *s, char const *accept);

char	*ft_strstr(char const *haystack, char const *needle);

char	*ft_strrstr(char const *haystack, char const *needle);

char	*ft_strpbrk(char const *s, char const *accept);

int		get_next_line(int fd, char **line);

#endif
