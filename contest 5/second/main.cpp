#include <iostream>
class Vector2D
{
private:
    int x, y;
public:
    // Конструкторы
    Vector2D(){
        this->x = 0;
        this->y = 0;
    };
    Vector2D(int x, int y){
        this->x = x;
        this->y = y;
    };

    // Деструктор
    ~Vector2D(){
        x = 0;
        y = 0;
    };

    // Получение координат
    int getX() const{
        return  x;
    };
    int getY() const{
        return y;
    };

    // Задание координат
    void setX(int x){
        this->x = x;
    };
    void setY(int y){
        this->y = y;
    };

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const{
        return x == v2.x && y == v2.y;
    };

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector2D& v2) const{
        return !(x == v2.x && y == v2.y);
    };


    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const{
        int x2 = x + v2.x;
        int y2 = y + v2.y;
        return Vector2D(x2, y2);
    };

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const{
        int x2 = x - v2.x;
        int y2 = y - v2.y;
        return Vector2D(x2, y2);
    };

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const{
        int x2 = x * a;
        int y2 = y * a;
        return Vector2D(x2, y2);
    };
};

// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
Vector2D operator* (int a, const Vector2D& v){
    int x2 = a * v.getX();
    int y2 = a * v.getY();
    return Vector2D(x2, y2);
};

// Вывод вектора, ожидается строго в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v){
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
};

// Чтение вектора, читает просто две координаты без хитростей
std::istream& operator >> (std::istream &is, Vector2D &v){
    int a, b;
    is >> a;
    is >> b;
    v.setX(a);
    v.setY(b);
    return is;
};


int main(){
    Vector2D v1;
    std::cin >> v1;
    std::cout << v1 << std::endl;
    Vector2D v2;
    std::cin >> v2;
    std::cout << v2 << std::endl;
    std::cout  << (v1 == v2) << std::endl;
    std::cout  << (v1 != v2) << std::endl;
    Vector2D v3 = v1 - v2;
    std::cout << v3 << std::endl;
    std::cout << v3 * 42 << std::endl;
    std::cout << 42 * v3 << std::endl;
    return 0;
}