#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {

public:

	Contact(void);
	~Contact(void);

	std::string	getName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	void		setName(std::string &name);
	void		setLastName(std::string &lastName);
	void		setNickname(std::string &nickName);
	void		setPhoneNumber(std::string &phoneNumber);
	void		setDarkestSecret(std::string &darkestSecret);

private:

	std::string _name;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

};
#endif
