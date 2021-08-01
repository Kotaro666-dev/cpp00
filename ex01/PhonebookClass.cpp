/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:59:31 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/23 11:30:55 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhonebookClass.hpp"

C_Phonebook::C_Phonebook()
{
	m_length = 0;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		m_contacts[i].Initialize();
	}
}

void C_Phonebook::Add_phonebook()
{
	std::string input;

	for (int i = 0; i < 5; i++)
	{
		this->Display_question(i);
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::exit(1);
		}
		bool is_phonebook_full = this->m_length == 8;
		if (is_phonebook_full)
		{
			Creat_space_for_new_contact();
		}
		this->m_contacts[this->m_length].Set_contact(i, input);
	}
	this->m_length++;
}

void C_Phonebook::Search_phonebook()
{
	if (this->m_length == 0)
	{
		std::cout << SEARCH_EMPTY_MSG << std::endl;
		return ;
	}
	Display_search_list_header();
	for (int i = 0; i < this->m_length; i++)
	{
		this->m_contacts[i].Get_name_related_members(i + 1);
	}
	Display_search_list_bottom();
	Display_next_search_question();
}

void C_Phonebook::Exit_phonebook()
{
	std::cout << "  ________                  .___ ___.                 " << std::endl;
	std::cout << " /  _____/  ____   ____   __| _/ \\_ |__ ___.__. ____" << std::endl;
	std::cout << "/   \\  ___ /  _ \\ /  _ \\ / __ |   | __ <   |  |/ __ \\" << std::endl;
	std::cout << "\\    \\_\\  (  <_> |  <_> ) /_/ |   | \\_\\ \\___  \\  ___/" << std::endl;
	std::cout << " \\______  /\\____/ \\____/\\____ |   |___  / ____|\\___  >" << std::endl;
	std::cout << "        \\/                   \\/       \\/\\/         \\/" << std::endl;
	exit(0);
}

void C_Phonebook::Creat_space_for_new_contact()
{
	for (int i = 0; i < 7; i++)
	{
		this->m_contacts[i].Initialize();
		this->m_contacts[i] = this->m_contacts[i + 1];
	}
	this->m_contacts[7].Initialize();
	this->m_length--;
}

void C_Phonebook::Display_search_list_header()
{
	std::cout << "|------------|------------|------------|------------|" << std::endl;
	std::cout << "|   index    | first name | last name  |  nickname  |" << std::endl;
	std::cout << "|------------|------------|------------|------------|" << std::endl;
}

void C_Phonebook::Display_search_list_bottom()
{
	std::cout << "|------------|------------|------------|------------|" << "\n" << std::endl << std::endl;
}

void C_Phonebook::Display_next_search_question()
{
	std::string input;
	while (true)
	{
		std::cout << SEARCH_INDEX_INQUIRY_MSG << std::flush;
		std::getline(std::cin, input);
		char c = input[0];
		while (input.length() != 1 || !('0' <= c && c < '9'))
		{
			std::cout << SEARCH_UNEXPECTED_INPUT_MSG << std::endl;
			std::cout << SEARCH_INDEX_INQUIRY_MSG << std::flush;
			std::getline(std::cin, input);
			c = input[0];
		}
		if (std::cin.eof())
		{
			std::exit(1);
		}
		int number = c - '0';
		bool does_index_exist = (0 < number && number < this->m_length + 1);
		if (!does_index_exist)
		{
			std::cout << SERACH_UNKNOWN_INDEX << std::endl;
			continue;
		}
		else
		{
			this->m_contacts[number - 1].Get_full_contact_field_by_index();
		}
		bool want_quit = false;
		while (true)
		{
			std::cout << SERACH_QUIT_OR_CONTINUE_MSG << std::flush;
			std::string input;
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::exit(1);
			}
			if (input == SEARCH_QUIT)
			{
				want_quit = true;
				break ;
			}
			else if (input == SEARCH_CONTINUE)
			{
				break ;
			}
			else
			{
				std::cout << SEARCH_UNEXPECTED_COMMAND_MSG << std::endl;
			}
		}
		if (want_quit)
		{
			break;
		}
	}
}

void C_Phonebook::Display_question(int index)
{
	switch (index)
	{
		case FIRST_NAME:
			std::cout << PROMPT_FIRST_NAME;
			break;
		case LAST_NAME:
			std::cout << PROMPT_LAST_NAME;
			break;
		case NICKNAME:
			std::cout << PROMPT_NICKNAME;
			break;
		case PHONE_NUMBER:
			std::cout << PROMPT_PHONE_NUMBER;
			break;
		case DARKEST_SECRET:
			std::cout << PROMPT_DARKEST_SECRET;
			break;
		default:
			break;
	}
}

void C_Phonebook::Display_no_match_command_msg(std::string input)
{
	std::cout << input << " does not exist." << std::endl;
	std::cout << AVAILABLE_COMMAND_MSG << std::endl;
}
