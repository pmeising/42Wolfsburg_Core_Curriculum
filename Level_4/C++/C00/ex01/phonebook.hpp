#ifndef _PHONEBOOK_HPP
# define _PHONEBOOK_HPP
# include <iostream>
# include <string>

class Contact
{
public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	int	set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	std::string	get_info(std::string var);

private:
	std::string firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

class	PhoneBook
{
public:
	PhoneBook();
	void	add(int i);
	void	search();

private:
	Contact	Contacts[8];
	void	search_short(int i);
	void	search(int i);
	void	str_adjust_less(std::string str);
	void	str_adjust_more(std::string str);
};

#endif
