#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----Main subject----" << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printContainer();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----FillSpan short subject----" << std::endl;
	try{
		Span sp = Span(5);
		sp.fillSpan();
		sp.printContainer();
		std::cout << "Container size: " << sp.spanSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----FillSpan 10000 subject----" << std::endl;
	try{
		Span sp = Span(10000);
		sp.fillSpan();
		//sp.printContainer();
		std::cout << "Container size: " << sp.spanSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----FillSpan 20000 subject----" << std::endl;
	try{
		Span sp = Span(20000);
		sp.fillSpan();
		//sp.printContainer();
		std::cout << "Container size: " << sp.spanSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----Full container Exception----" << std::endl;
	try{
		Span sp = Span(2);
		sp.addNumber(6);
		sp.addNumber(11);
		sp.addNumber(12);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----Print Exception----" << std::endl;
	try{
		Span sp = Span(0);
		sp.printContainer();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----Shortest Exception Empty----" << std::endl;
	try{
		Span sp = Span(0);
		sp.shortestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----Longest Exception Empty----" << std::endl;
	try{
		Span sp = Span(0);
		sp.longestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}
	std::cout << "----Shortest Exception One Element----" << std::endl;
	try{
		Span sp = Span(1);
		sp.shortestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}

	std::cout << "----Longest Exception One Element----" << std::endl;
	try{
		Span sp = Span(1);
		sp.longestSpan();
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;}
	return 0;
}
