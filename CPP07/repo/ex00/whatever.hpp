#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/* swap(a, b) */
template <typename T>
void	swap(T & a, T & b) {

	T	c;

	c = a;
	a = b;
	b = c;

	return ;
}

/* min(a, b) */
template <typename T>
T const &	min(T const & x, T const & y) {

	return x < y ? x : y;
}

/* max(a, b) */
template <typename T>
T const &	max(T const & x, T const & y) {

	return x > y ? x : y;
}

#endif
