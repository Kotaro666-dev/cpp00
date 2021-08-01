/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:05:25 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/23 10:13:02 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define ARGC_EQUAL_TO_ONE_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static bool	is_charactor_lowercase(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (true);
	}
	return (false);
}

static char to_uppercase(char target)
{
	char c;

	c = target - ('a' - 'A');
	return (c);
}

static void	cout_argv_with_uppercase(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_charactor_lowercase(str[i]))
		{
			char c = to_uppercase(str[i]);
			std::cout << c << std::flush;
		}
		else
		{
			std::cout << str[i] << std::flush;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << ARGC_EQUAL_TO_ONE_MSG << std::endl;
	}
	else
	{
		int i = 1;
		while(argv[i])
		{
			cout_argv_with_uppercase(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}