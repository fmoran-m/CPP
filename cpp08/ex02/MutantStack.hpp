#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>

template <class T, class C = std::deque<T> > 

class MutantStack : public std::stack<T>{
	public:

	MutantStack() : std::stack<T>(){};
	MutantStack(MutantStack const &src) : std::stack<T>(src){};
	MutantStack &operator=(MutantStack const &rhs){
		std::stack<T>::operator=(rhs);
		return (*this);
	};
	MutantStack(const C &src) : std::stack<T, C>(src) {};  //Para poder usar el constante
	~MutantStack(){};

	typedef typename C::iterator iterator;
	typedef typename C::const_iterator const_iterator;

	iterator begin(){
		return (this->c.begin());
	}

	iterator end(){
		return (this->c.end());
	}

	const_iterator begin() const {
		return (this->c.begin());
	}

	const_iterator end() const {
		return (this->c.end());
	}
};
#endif
