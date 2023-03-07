/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:31:59 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/06 19:14:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCL/Reply.hpp"

Reply::Reply() : _value(0), _message("")
{

}

Reply::Reply(int value, std::string message) : _value(value), _message(message)
{
	_user = NULL;
}

void	Reply::add_arg(std::string arg)
{
	int i = 0;

	for (std::string::iterator it = _message.begin(); it != _message.end(); it++)
	{
		if (*it == '<')
		{
			_message.erase(i, _message.find('>') - i + 1);
			_message.insert(i, arg);
			break;
		}
		else
			i++;
	}
}

void	Reply::add_user(User *user)
{
	std::size_t found, size = 8;

	_user = user;
	if (_message.compare("") != 0)
	{
		if (_user->get_nickname().compare("") != 0)
		{
			found = _message.find("<client>");
			if (found != std::string::npos)
				_message.replace(found,size,_user->get_nickname());
		}
	}
}


Reply::Reply(const Reply &other)
{
	*this = other;
}

Reply::~Reply() { }

Reply		&Reply::operator=(const Reply &other)
{
	if (this != &other) {
		_value = other.get_value();
		_message = other.get_message();
	}
	return (*this);
}

int			Reply::get_value() const
{
	return (_value);
}

std::string	Reply::get_message() const
{
	return (_message);
}

void	Reply::prep_to_send()
{
	std::stringstream s_value;
	s_value << _value;
	std::string value_str = s_value.str();

	_message.insert(0, " ");
	_message.insert(0, value_str);
	_message.insert(0, " ");
	if (_user)
	{
		_message.insert(0, _user->get_hostaddr());
		_message.insert(0, "@");
		_message.insert(0, _user->get_username());
		_message.insert(0, "!");
		_message.insert(0, _user->get_nickname());
	}
}
//cmaginot!cmaginot@localhost 001

// CAP LS
// PASS abc
// NICK cmaginot
// USER cmaginot cmaginot 127.0.0.1 :Celien MAGINOT
