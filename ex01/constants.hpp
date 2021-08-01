/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:50:54 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/23 11:28:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

enum Question
{
	FIRST_NAME = 0,
	LAST_NAME = 1,
	NICKNAME = 2,
	PHONE_NUMBER = 3,
	DARKEST_SECRET = 4,
};

/*
** PHONEBOOK
*/

const int MAX_LENGTH = 8;
const std::string GOODBYE_MSG = "############ GOOD BYE! #############";

const std::string AVAILABLE_COMMAND_MSG = "[AVAILABLE COMMANDS]: ADD, SEARCH, EXIT";

const std::string PROMPT_FIRST_NAME = "first name: ";
const std::string PROMPT_LAST_NAME = "last name: ";
const std::string PROMPT_NICKNAME = "nickname: ";
const std::string PROMPT_PHONE_NUMBER = "phone number: ";
const std::string PROMPT_DARKEST_SECRET = "darkest secret: ";

const std::string SEARCH_EMPTY_MSG = "$ Your Phonebook is empty.";
const std::string SEARCH_INDEX_INQUIRY_MSG = "$ Which index do you want to inquire?: ";
const std::string SERACH_UNKNOWN_INDEX = "$ This index nubmer does not exist. Try again.";
const std::string SERACH_QUIT_OR_CONTINUE_MSG = "$ Enter 'q' if you want to quit or enter 'c' if you want to continue: ";
const std::string SEARCH_QUIT = "q";
const std::string SEARCH_CONTINUE = "c";
const std::string SEARCH_UNEXPECTED_COMMAND_MSG = "$ Unexpected command. Try again.";
const std::string SEARCH_UNEXPECTED_INPUT_MSG = "$ Unexpected input. Try again";

/*
** CONTACT
*/

const int SEARCH_OUTPUT_MAX = 10;
const int SEARCH_FIELD_WITDH = 12;

#endif