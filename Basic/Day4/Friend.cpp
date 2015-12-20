#include <iostream>

#define NONE 0
#define ROME 1
#define GREEK 2
#define FRANCE 3
#define JAPAN 4
#define CHINA 5
#define KOREA 6

class Dominations
{
	friend bool checkHack(Dominations &user);
	friend class DB;
	public:
		Dominations(const char *name = "guest", int nation = NONE);
		int getUnitLimit() { return unit_limit; }
	private:
		const char *name;
		int nation;
		int unit_limit;
		int level;
};

class DB
{
	public:
		DB() : location("sayaten.net:3306") { }
		void DBInsert(Dominations user) { std::cout << "insert " << user.name << std::endl; }
		void DBDelete(Dominations user) { std::cout << "select " << user.name << std::endl; }
	private:
		const char *location;
};

Dominations::Dominations(const char *name, int nation)
	: name(name), nation(nation)
{
	std::cout << "Join new player!!" << std::endl;
	unit_limit = 10;
	level = 1;
}

bool checkHack(Dominations &user)
{
	if(user.unit_limit != user.level * 10)
		return true;
	else
		return false;
}

int main()
{
	Dominations my_id("Miyamoto Ruri", KOREA);
	DB db;

	std::cout << my_id.getUnitLimit() << std::endl;
	if(checkHack(my_id))
	{
		std::cout << "It is hacked!!" << std::endl;
	}
	db.DBInsert(my_id);
	db.DBDelete(my_id);
	return 0;
}

