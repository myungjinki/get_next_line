/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:02:14 by seoh              #+#    #+#             */
/*   Updated: 2020/07/19 12:44:01 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

/*
** ft_strchr 함수 : 문자열에 존재하는 특정 문자를 찾는 함수
** str 문자열에서 처음으로 c문자가 존재하는 '위치'를 반환하며 없으면 NULL 반환
*/

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (!*str)
			return (0);
		str++;
	}
	return (str);
}

/*
** ft_strjoin : 문자열 두 개를 합치는 함수, strcat은 문자열 뒤에 붙이는거고 strjoin은 합친 문자열을 반환
*/

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rtn)
		return (0);
	while (*s1)
		rtn[i++] = *s1++;
	while (*s2)
		rtn[i++] = *s2++;
	rtn[i] = '\0';
	return (rtn);
}

/*
** ft_substr : 문자열에서 일부 잘라내기, 앞에서 start만큼 잘라낸후 len만큼만 가져옴
*/

char	*ft_substr(char *str, unsigned int start, int len)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	while (i < len)
		rtn[i++] = str[start++];
	rtn[i] = '\0';
	return (rtn);
}

/*
** ft_strdup : 문자열을 메모리에 복사, 복사한 메모리 위치(포인터)를 반환
*/

char	*ft_strdup(char *str)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!rtn)
		return (0);
	while (*str)
		rtn[i++] = *str++;
	rtn[i] = '\0';
	return (rtn);
}
