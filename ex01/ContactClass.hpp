/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:50:30 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/12 21:25:40 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "./constants.hpp"

class C_Contact
{
	private:
		std::string m_first_name;
		std::string m_last_name;
		std::string m_nickname;
		std::string m_phone_number;
		std::string m_darkest_secret;

	public:
		// constructor
		C_Contact();

		// destructor
		virtual ~C_Contact();

		// initializer
		void Initialize();

		// setter
		void Set_contact(const int index, const std::string input);
		void Set_first_name(const std::string fisrt_name);
		void Set_last_name(const std::string last_name);
		void Set_nickname(const std::string nick_name);
		void Set_phone_number(const std::string phone_number);
		void Set_darkest_secret(const std::string darkest_secret);

		// getter
		void Get_name_related_members(const int index);
		void Get_full_contact_field_by_index();

		// constants
		void Cout_field_with_name(const std::string name);
};

#endif