#ifndef ARRAY_TPP
# define ARRAY_TPP

template <class T>
Array<T>::Array() : length(0){
	array = new T[0];
	return;
}

template <class T>
Array<T>::Array(unsigned int n) : length(n){
	array = new T[n];
	return;
}

template <class T>
Array<T>::Array(Array const &src){ 
	*this = src;
	return;
}

template <class T>
Array<T> & Array<T>::operator=(Array const &rhs){
	if (this == &rhs)
		return (*this);
	length = rhs.size();
	if (this->array)
		delete [] array;
	array = new T[length];
	for (unsigned int i = 0; i < length; i++){
		array[i] = rhs.array[i];
	}
	return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index){
	if (index >= this->size())
		throw OutofArrayException();
	return (array[index]);
}

template <class T>
Array<T>::~Array() {
	if (this->array)
		delete[] array;
}

template <class T>
unsigned int Array<T>::size() const{
	return (length);
}

#endif