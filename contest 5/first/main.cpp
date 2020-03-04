#include <string>
#include <iostream>
class Student
{
private:
    std::string  name;
    unsigned int score;
public:
    // Задать имя студента
    void setName(std::string name){
        this->name = name;
        score = 0;
    };

    // Указать количество баллов за контрольную
    void setScore(unsigned int score){
        this->score = score;
    };

    // Получить имя студента
    std::string getName() const{
        return name;
    };

    // Получить количество баллов студента
    unsigned int getScore() const{
        return score;
    };


};

std::ostream& operator << (std::ostream& os, const Student a){
    os << "'" << a.getName() << "': " << a.getScore();
    return os;
}

std::istream& operator >> (std::istream& is, Student& a){
    std::string name;
    getline(is, name);
    a.setName(name);
    return is;
}


int main(){
    Student s;

    std::cin >> s;
    s.setScore(10);
    std::cout << s << std::endl;


    return 0;
}