#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T const * array, size_t const length, void (*f)(T const & element))
{
	if (!array || !f) {
		return ;
	}
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}

	return ;
}

#endif
