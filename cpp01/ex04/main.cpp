#include <iostream>
#include <string>
#include <fstream>

std::string getFileContent(std::ifstream &original)
{
	char		c;
	std::string	buffer;

	while (original.get(c))
		buffer += c;
	return buffer;
}

void	replaceContent(std::string &buffer, const std::string &s1, const std::string &s2)
{
	size_t pos;

	pos = buffer.find(s1);
	while(pos != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos = buffer.find(s1, pos + s2.length());
	}
	return;
}

bool	argumentControl(const int argc, const char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: incorrect number of arguments" << std::endl;
		return false;
	}
	if (!*argv[1] || !*argv[2] || !*argv[3])
	{
		std::cout << "Error: arguments cannot be empty" << std::endl;
		return false;
	}
	if ((std::string)argv[2] == (std::string)argv[3])
	{
		std::cout << "Error: strings cannot be equal" << std::endl;
		return false;
	}
	return (true);
}

int main(const int argc, const char **argv)
{
	if (argumentControl(argc, argv) == false)
		return 1;
	std::ifstream	original(argv[1]);
	if (!original.is_open())
	{
		std::cout << "Error: cannot open the input file" << std::endl;
		return 1;
	}
	std::string buffer = getFileContent(original);
	original.close();
	replaceContent(buffer, argv[2], argv[3]);
	std::ofstream	copy((std::string)argv[1] + ".replace");
	if (!copy.is_open())
	{
		std::cout << "Error: cannot create the output file" << std::endl;
		return 1;
	}
	copy << buffer;
	copy.close();
	return 0;
}
