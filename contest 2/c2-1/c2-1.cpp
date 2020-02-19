#include <iostream>
using namespace std;
class Animal {
public:
	virtual string getType() = 0;
	virtual bool isDangerous() = 0;
};
class ZooKeeper {
public:
	int number_of_dangerous = 0;
	// Создаём смотрителя зоопарка
	ZooKeeper() {}

	// Смотрителя попросили обработать очередного зверя.
	// Если зверь был опасный, смотритель фиксирует у себя этот факт.
	void handleAnimal(Animal* a) {
		if (a->isDangerous() == true) {
			number_of_dangerous++;
		}
	};

	// Возвращает, сколько опасных зверей было обработано на данный момент.
	int getDangerousCount() {
		return number_of_dangerous;
	}; 
};
int main(void) {
	ZooKeeper z;
	Monkey* m = new Monkey();
	z.handleAnimal(m);
	delete m;
	m = new Monkey();
	z.handleAnimal(m);
	delete m;
	Lion* l = new Lion();
	z.handleAnimal(l);
	delete l;
	cout << z.getDangerousCount() << endl;
	return 0;
}