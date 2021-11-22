#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>

class	MutantStack:	public std::stack<T> {

	public:
		MutantStack<T>(void) : std::stack<T>()							{ }
		MutantStack<T>(MutantStack const & src) : std::stack<T>(src)	{ }
		virtual ~MutantStack<T>(void)									{ }
		MutantStack<T> &	operator = (MutantStack const & rhs)		{
			return std::stack<T>::operator = (rhs);
		}

		typedef typename std::stack<T>::container_type::iterator
														iterator;
		typedef typename std::stack<T>::container_type::const_iterator
														const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator
														reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator
														const_reverse_iterator;

		iterator				begin(void)			{ return this->c.begin(); }
		iterator				end(void)			{ return this->c.end(); }
		const_iterator			begin(void) const	{ return this->c.begin(); }
		const_iterator			end(void) const		{ return this->c.end(); }
		reverse_iterator		rbegin(void)		{ return this->c.rbegin(); }
		reverse_iterator		rend(void)			{ return this->c.rend(); }
		const_reverse_iterator	rbegin(void) const	{ return this->c.rbegin(); }
		const_reverse_iterator	rend(void) const	{ return this->c.rend(); }
};

#endif
