#include <iostream>
#include <string>

class Zombie {

public:

	Zombie();
	~Zombie(void);

    void    setName(std::string name);
	void	announce(void);

private:

	std::string _name;
};
