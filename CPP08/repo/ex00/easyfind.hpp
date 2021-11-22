#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>

typename T::iterator	easyfind(T & container, int value) {

	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end()) {
		throw std::range_error("Error: value is not in a container");
	}

	return iter;
}

#endif
