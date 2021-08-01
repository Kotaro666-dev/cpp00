/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:50:26 by kkamashi          #+#    #+#             */
/*   Updated: 2021/07/12 21:37:27 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ContactClass.hpp"

C_Contact::C_Contact()
{
	m_first_name = "";
	m_last_name = "";
	m_nickname = "";
	m_phone_number = "";
	m_darkest_secret = "";
}

C_Contact::~C_Contact()
{

}

void C_Contact::Initialize()
{
	m_first_name = "";
	m_last_name = "";
	m_nickname = "";
	m_phone_number = "";
	m_darkest_secret = "";
}

void C_Contact::Set_contact(int index, std::string input)
{
	switch (index)
	{
		case FIRST_NAME:
			this->Set_first_name(input);
			break;
		case LAST_NAME:
			this->Set_last_name(input);
			break;
		case NICKNAME:
			this->Set_nickname(input);
			break;
		case PHONE_NUMBER:
			this->Set_phone_number(input);
			break;
		case DARKEST_SECRET:
			this->Set_darkest_secret(input);
			break;
		default:
			break;
	}
}

void C_Contact::Set_first_name(std::string input)
{
	this->m_first_name = input;
}

void C_Contact::Set_last_name(std::string input)
{
	this->m_last_name = input;
}

void C_Contact::Set_nickname(std::string input)
{
	this->m_nickname = input;
}

void C_Contact::Set_phone_number(std::string input)
{
	this->m_phone_number = input;
}

void C_Contact::Set_darkest_secret(std::string input)
{
	this->m_darkest_secret = input;
}

void C_Contact::Get_name_related_members(int index)
{
	std::cout << "|           " << std::flush;
	std::cout << index << std::flush;
	this->Cout_field_with_name(m_first_name);
	this->Cout_field_with_name(m_last_name);
	this->Cout_field_with_name(m_nickname);
	std::cout << "|" << std::endl;
}

void C_Contact::Get_full_contact_field_by_index()
{
	std::cout << PROMPT_FIRST_NAME;
	std::cout << this->m_first_name << std::endl;
	std::cout << PROMPT_LAST_NAME;
	std::cout << this->m_last_name << std::endl;
	std::cout << PROMPT_NICKNAME;
	std::cout << this->m_nickname << std::endl;
	std::cout << PROMPT_PHONE_NUMBER;
	std::cout << this->m_phone_number << std::endl;
	std::cout << PROMPT_DARKEST_SECRET;
	std::cout << this->m_darkest_secret << std::endl;
}

void C_Contact::Cout_field_with_name(std::string name)
{
	if (name.length() > SEARCH_OUTPUT_MAX)
	{
		std::cout << "|  " << std::flush;
		for (int i = 0; i < SEARCH_OUTPUT_MAX - 1; i++)
		{
			std::cout << name[i] << std::flush;
		}
		std::cout << "." << std::flush;
		return ;
	}
	std::cout << "|" << std::flush;
	std::cout << std::setw(SEARCH_FIELD_WITDH) << name << std::flush;
}