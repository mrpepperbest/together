#include <iostream>
using namespace std;
namespace namespaceA {
	class Engine {
	public:
		void run() {
			cout << "EngineA run" << endl;
		}
	};
}

namespace namespaceB {
	class Engine {
	public:
		void run() {
			cout << "EngineB run" << endl;
		}
	};
}

namespace namespaceC {
	class Engine {
	public:
		void run() {
			cout << "EngineC run" << endl;
		}
	};
}
class MyEngine {
public:
	namespaceA::Engine eA;
	namespaceB::Engine eB;
	namespaceC::Engine eC;
	// Если передан параметр 1 - должен быть вызван метод run и Engine-а из библиотеки A.
	// Если передан параметр 2 - должен быть вызван метод run и Engine-а из библиотеки B.
	// Если передан параметр 3 - должен быть вызван метод run и Engine-а из библиотеки C.
	// Если передано что-то иное - должно ничего не произойти.
	void run(unsigned int number) {
		switch(number){
		case 1:
			 eA.run();
			 break;
		case 2:
			eB.run();
			break;
		case 3:
			eC.run();
			break;
		default:
			break;
		}

	};
};
int main(void) {
	MyEngine e;
	e.run(1); // вызов run из Engine-а из библиотеки A
	e.run(2); // вызов run из Engine-а из библиотеки B
	e.run(3); // вызов run из Engine-а из библиотеки C
	e.run(10); // ничего не происходит
	return 0;
}