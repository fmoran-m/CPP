#include <iostream>
#include <string>
#include <fstream>
#include "Replacetor.hpp"

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
	//Control arguments error
	if (argumentControl(argc, argv) == false)
		return 1;

	//Instance of the replacetor object with the init of the s1, s2, file
	Replacetor	replacetor((std::string)argv[2], (std::string)argv[3], (std::string)argv[1]);

	//Open_file
	if (!replacetor.openOgFile())
		return 1;

	//Get file content in a buffer
	std::string buffer = replacetor.getFileContent();

	//Replace s1 strings with s2 strings in buffer
	replacetor.replaceContent(buffer);

	//Stream buffer to file
	if (!replacetor.createCpyFile(buffer))
		return 1;

	return 0;
}
