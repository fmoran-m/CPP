#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class Span {
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span(void);

		void			addNumber(unsigned int);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void)const;

		void			fillSpan(void);
		void			printContainer(void);
		unsigned int	spanSize(void) const;

	private:
		std::vector<unsigned int>	container;
		unsigned int limit;
};
#endif
