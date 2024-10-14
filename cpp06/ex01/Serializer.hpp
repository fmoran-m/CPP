#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>

typedef struct s_data{
	int a;
	int b;
	int c;
} Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &rhs);
		~Serializer(void);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
