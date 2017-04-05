#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class ZombieEvent {

public:
	static const	std::string zombiesName[9];
	std::string		type;

	ZombieEvent();
	~ZombieEvent();

	void			setZombieType(std::string zombieType);
	Zombie			randomChump(void);
	Zombie			*newZombie(std::string name);

};

#endif