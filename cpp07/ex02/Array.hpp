#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src)
		Array & operator=(Array const &rhs);
		~Array();
	private:
		T *array;
}
#endif