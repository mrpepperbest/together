
#include <iostream>
#include <string>

class Student
{
private:
	std::string name;
	unsigned int score;
public:
	Student() {
		name = '\0';
		score = 0;
	};
	~Student() {};
	// Задать имя студента
	void setName(std::string name) {
		this->name = name;
	};

	// Указать количество баллов за контрольную
	void setScore(unsigned int score) {
		this->score = score;
	};

	// Получить имя студента
	std::string getName() const {
		return name;
	};

	// Получить количество баллов студента
	unsigned int getScore() const {
		return score;
	};
};
std::istream& operator>>(std::istream& is, Student& a) {
	std::string b;
	getline(is,b);
	a.setName(b);
	a.setScore(0);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Student& a) {
	os << "'" << a.getName() <<"': " << a.getScore() << std::endl;
	return os;
}
int main()
{
	Student s;
	std::cin >> s;
	s.setScore(10);
	std::cout << s << std::endl;
	return 0;
}