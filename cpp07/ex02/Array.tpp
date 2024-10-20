#ifndef ARRAY_TPP
# define ARRAY_TPP

template <class T>
Array<T>::Array() : array(NULL), length(0){}

template <class T>
Array<T>::Array(unsigned int n) : length(n){
	array = new T[n];
	return;
}

template <class T>
Array<T>::Array(Array const &src) : array(NULL), length(0){ 
	*this = src;
	return;
}

template <class T>
Array<T> & Array<T>::operator=(Array const &rhs){
	if (this == &rhs)
		return (*this);

	if (this->array)
		delete [] array;

	length = rhs.size();
	if (length > 0){
	    array = new T[length];
	    for (unsigned int i = 0; i < length; i++){
		 	array[i] = rhs.array[i];
	    }
	}
	else
	    array = NULL;
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
