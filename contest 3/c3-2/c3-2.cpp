
#include <iostream>
using namespace std;
class Storage
{
public:
	int *s;
	unsigned int size;
	// Конструктор хранилища размерности n
	Storage(unsigned int n) {
		this->s = new int[n];
		this->size = n;
	};

	// Добавьте нужный деструктор

	// Получение размерности хранилища
	unsigned getSize() {
		return this->size;
	};

	// Получение значения i-го элемента из хранилища,
	// i находится в диапазоне от 0 до n-1,
	// случаи некорректных i можно не обрабатывать.
	int getValue(unsigned int i) {
		return this->s[i];
	};

	// Задание значения i-го элемента из хранилища равным value,
	// i находится в диапазоне от 0 до n-1,
	// случаи некорректных i можно не обрабатывать.
	void setValue(unsigned int i, int value) {
		this->s[i] = value;
	};
	virtual ~Storage(){
		delete[] this->s;
	}
};
class TestStorage : public Storage {
protected:
	// Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
	int* more_data;

public:
	// В конструкторе память выделяется,
	TestStorage(unsigned int n) : Storage(n) {
		more_data = new int[n];
	}
	// ... а в деструкторе освобождается - всё честно.
	~TestStorage() {
		delete[] more_data;
	}
};
int main() {
	Storage* ts = new TestStorage(42);
	delete ts;
	return 0;
}