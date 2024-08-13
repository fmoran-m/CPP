#ifndef REPLACETOR_HPP
# define REPLACETOR_HPP

class Replacetor {
public:

	Replacetor(const &s1, const &s2, const &file);
	~Replacetor();

	void		replaceContent(std::string &buffer, const std::string &s1, const std::string &s2);
	std::string getFileContent(std::ifstream &original);

private:

	const std::string _s1;
	const std::string _s2;
	const std::string _file;

};
#endif
