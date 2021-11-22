#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>

class	Array {

	private:
		T *				_array;
		unsigned int	_size;

	public:
		Array(void) : _array(NULL), _size(0)	{}

		Array(unsigned int n) : _array(new T[n]), _size(n)	{}

		Array(Array const & src) : _array(NULL), _size(0)	{ *this = src; }

		~Array(void)	{ delete [] _array; }


		unsigned int	size(void) const	{ return _size; }

		T &				operator [] (unsigned int index) {
			if (_size <= index)
				throw std::range_error("Error: Index is out of array range");
			return _array[index];
		}

		T const &		operator [] (unsigned int index) const {
			if (_size <= index)
				throw std::range_error("Error: Index is out of array range");
			return _array[index];
		}

		Array &			operator = (Array const & rhs) {
			if (this == &rhs)
				return *this;
			delete [] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return *this;
		}
};

#endif
