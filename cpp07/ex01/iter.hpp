#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, int size, void (*f)(T&)){
	if (array)
	{
		for (int i = 0; i < size; i++){
			f(array[i]);
		}
	}
	return;
}

template <typename T>
void plusOne(T &value){
	value = value + static_cast<T>(1);
}

#endif