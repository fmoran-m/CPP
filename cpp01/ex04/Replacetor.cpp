#include "Replacetor.hpp"
#include <iostream>
#include <string>
#include <fstream>

Replacetor::Replacetor(const std::string &s1,  const std::string &s2, const std::string &file) : _s1(s1), _s2(s2), _file(file){
	return;
}

Replacetor::~Replacetor(){
	return;
}

std::string Replacetor::getFileContent(){

	char		c;
	std::string	buffer;

	while (this->_original.get(c))
		buffer += c;
	this->_original.close();
	return buffer;
}

void		Replacetor::replaceContent(std::string &buffer){

	size_t pos = buffer.find(this->_s1);

	while(pos != std::string::npos)
	{
		buffer.erase(pos, this->_s1.length());
		buffer.insert(pos, this->_s2);
		pos = buffer.find(this->_s1, pos + this->_s2.length());
	}
	return;
}

int	Replacetor::openOgFile(){

	this->_original.open(this->_file);
	if (!this->_original.is_open())
	{
		std::cout << "Error: cannot open the input file" << std::endl;
		return 0;
	}
	return 1;
}

int			Replacetor::createCpyFile(std::string &buffer){

	this->_copy.open(this->_file + ".replace");
	if (!this->_copy.is_open())
	{
		std::cout << "Error: cannot create the output file" << std::endl;
		return 0;
	}
	this->_copy << buffer;
	this->_copy.close();
	return 1;
}
