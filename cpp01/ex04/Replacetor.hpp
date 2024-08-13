#ifndef REPLACETOR_HPP
# define REPLACETOR_HPP

# include <string>
# include <fstream>

class Replacetor {
public:

	Replacetor(const std::string &s1, std::string const &s2, std::string const &file);
	~Replacetor();

	void		replaceContent(std::string &buffer);
	std::string getFileContent();
	int			openOgFile(void);
	int			createCpyFile(std::string &buffer);
	
private:

	std::string	const	_s1;
	std::string	const	_s2;
	std::string	const	_file;
	std::ifstream 		_original;
	std::ofstream		_copy;

};
#endif
