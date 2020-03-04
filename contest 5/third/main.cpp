#include <iostream>

class VectorN
{
private:
    int size;
    int* mas = nullptr;
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n){
        size = n;
         mas = new int[size];
    };


    // Деструктор
    ~VectorN(){
        size = 0;
        mas = nullptr;
    };

    // Получение размерности вектора
    unsigned getSize() const{
        return size;
    };

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const{
        return mas[i];
    };

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value){
        mas[i] = value;
    };

    /*
     * Далее реализуйте перегруженные операторы
     */

    // Оператор == проверяет два вектора на равенство,
    // равны они, если строго равны всех их координаты
    bool operator == (VectorN a){
        bool r = true;
        for (int i = 0; i < size-1; i++)
        {
            if (mas[i] == a.getValue(i))
                r = true;
            else r = false;
        }
        return r;
    }
    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator != (VectorN a){
        bool r = true;
        for (int i = 0; i < size-1; i++)
        {
            if (!(mas[i] == a.getValue(i)))
                r = true;
            else r = false;
        }
        return r;
    }
    // Оператор + складывает два вектора покоординатно,
    // возвращает результат как новый экземпляр вектора
    VectorN operator + (VectorN a){
        VectorN v3(size);
        for (int i = 0; i < size; i++)
        {
            v3.setValue(i, (mas[i] + a.getValue(i)));
        }
        return v3;
    }
    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    // Умножение должно работать при любом порядке операндов.

};

VectorN operator * (const int a, VectorN s){
    VectorN b(s.getSize());
    for(unsigned int i = 0; i < s.getSize(); i++)
    {
        b.setValue(i, (s.getValue(i) * a));
    }
    return b;
}

VectorN operator * (VectorN s, const int a){
    VectorN b(s.getSize());
    for(unsigned int i = 0; i < s.getSize(); i++)
    {
        b.setValue(i, (s.getValue(i) * a));
    }
    return b;
}

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        std::cout << d.getValue(i) << std::endl;

    return 0;
}
