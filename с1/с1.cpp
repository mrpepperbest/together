#include <iostream>
using namespace std;
class SpacePort
{
public:
	int* docks;
	int max_dock_num;
	// Создать космодром, в котором size штук доков.
	// Доки нумеруются от 0 до size-1.
	// В момент создания все доки свободны.
	SpacePort(unsigned int size) {
		docks = new int[size];
		for (int i = 0; i < size; ++i) {
			docks[i] = 0;
		}
		this->max_dock_num = size-1;
	};
	~SpacePort() {
		delete[] docks;
	};

	// Запросить посадку в док с номером dockNumber.
	// Если такого дока нет - вернуть false (запрет посадки).
	// Если док есть, но занят - вернуть false (запрет посадки).
	// Если док есть и свободен - вернуть true (разрешение посадки) и док становится занят.
	bool requestLanding(unsigned int dockNumber) {
		if (dockNumber > this->max_dock_num) {
			return false;
		}else
		if (this->docks[dockNumber]==1) {
			return false;
		}
		docks[dockNumber] = 1;
		return true;
	};

	// Запросить взлёт из дока с номером dockNumber.
	// Если такого дока нет - вернуть false (запрет взлёта).
	// Если док есть, но там пусто - вернуть false (запрет взлёта).
	// Если док есть и в нём кто-то стоит - вернуть true (разрешение взлёта) и док становится свободен.
	bool requestTakeoff(unsigned int dockNumber) {
		if (dockNumber > this->max_dock_num) {
			return false;
		}else
		if (this->docks[dockNumber] == 0) {
			return false;
		}
		this->docks[dockNumber] = 0;
		return true;
	};
};
int main(void) {
	SpacePort s(5);
	cout << boolalpha << s.requestLanding(0) << endl;
	cout << boolalpha << s.requestLanding(4) << endl;
	cout << boolalpha << s.requestLanding(5) << endl;

	cout << boolalpha << s.requestTakeoff(0) << endl;
	cout << boolalpha << s.requestTakeoff(4) << endl;
	cout << boolalpha << s.requestTakeoff(5) << endl;
	return 0;
}