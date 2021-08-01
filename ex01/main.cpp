/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:05:21 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/12 21:25:24 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
#include "./main.hpp"

int				main()
{
	C_Phonebook phonebook;
	std::string input;

	std::cout << " __    __     _                            _____          ___ _                      _                 _    " << std::endl;
	std::cout << "/ / /\\ \\ \\___| | ___ ___  _ __ ___   ___  /__   \\___     / _ \\ |__   ___  _ __   ___| |__   ___   ___ | | __" << std::endl;
	std::cout << "\\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   / /\\/ _ \\   / /_)/ '_ \\ / _ \\| '_ \\ / _ \\ '_ \\ / _ \\ / _ \\| |/ /" << std::endl;
	std::cout << " \\  /\\  /  __/ | (_| (_) | | | | | |  __/  / / | (_) | / ___/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < " << std::endl;
	std::cout << "  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\/   \\___/  \\/    |_| |_|\\___/|_| |_|\\___|_.__/ \\___/ \\___/|_|\\_\\" << std::endl << std::endl;

	while (true)
	{
		std::cout << "$ ENTER COMMAND: " << std::flush;
		// ストリームから改行文字が現れるまで（1行すべて）あるいは仮引数delimで指定された文字までの文字列を入力する。
		std::getline(std::cin, input);
		// Ctrl-Dが押された時の判定
		if (std::cin.eof())
		{
			std::exit(1);
		}

		if (input == ADD)
		{
			phonebook.Add_phonebook();
		}
		else if (input == SEARCH)
		{
			phonebook.Search_phonebook();
		}
		else if (input == EXIT)
		{
			phonebook.Exit_phonebook();
		}
		else
		{
			phonebook.Display_no_match_command_msg(input);
		}
	}
	return (0);
}