#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		Array & operator=(Array const &rhs);
		T & operator[](unsigned int index);
		const T & operator[](unsigned int index) const;
		~Array();

		unsigned int size(void) const;

		class OutofArrayException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("Error: Array index out of bounds");
				};
		};

	private:
		T *array;
		unsigned int length;
};
# include "Array.tpp"

#endif