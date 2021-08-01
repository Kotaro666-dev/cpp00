/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:00:16 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/12 21:26:24 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>
# include "./ContactClass.hpp"
# include "./constants.hpp"

class C_Phonebook
{
	private:
		int			m_length;
		C_Contact	m_contacts[MAX_LENGTH];

	public:
		C_Phonebook();
		void Add_phonebook();
		void Search_phonebook();
		void Exit_phonebook();

		// utility
		void Creat_space_for_new_contact();
		void Display_search_list_header();
		void Display_search_list_bottom();
		void Display_next_search_question();
		void Display_question(const int index);
		void Display_no_match_command_msg(const std::string input);
};

#endif