#include <string>
#include <iostream>
#include<fstream>
using namespace std;

class Subvector{
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
public:
    Subvector()
    {
        capacity = 0;
        top = 0;
        mas = NULL;
    }

    ~Subvector()
    {
        capacity = 0;
        top = 0;
        mas = NULL;
    }

    bool push_back (int d)
{
    int s;
    int *p = mas;
    s = d;
    if (capacity == top)
        {
            capacity++;
            mas = new int[capacity];
            for (int i = 0; i < top; i++)
                *(mas + i) = *(p + i);
            top += 1;
            *(mas + top - 1) = s;
        } else
        {
        top += 1;
        *(mas + top - 1) = s;
        }
    return true;
}

    int pop_back()
{
    top--;
    return *(mas + top);
}

    bool resize(unsigned int new_capacity)
{
    capacity += new_capacity;
    int *p = mas;
    mas = new int[capacity];
    for (int i = 0; i < top; i++)
                *(mas + i) = *(p + i);
    return true;
}

    void shrink_to_fit()
{
    int *p = mas;
    capacity = top;
    for (int i = 0; i < top; i++)
                *(mas + i) = *(p + i);
}

    void clear()
{
    top = 0;
}

bool init_from_file(char *filename)
{
    ifstream i(filename);
    int sum = 0;
    if (!i.is_open())
           {
                return false;
           }
           else
           {
               while (!(i.eof()))
                {char s;
               i.get(s);
               sum++;}
           }
        capacity = sum;
        mas = new int [capacity];
        top = 0;
        for (top; top < capacity; top++)
        {
            if (!i.is_open())
           {
                return false;
           }
           else
           {
               while (!(i.eof()))
                {
                    char s;
                    i.get(s);
                    *(mas + top) = s;
                }
           }
        }
    return true;
}

void cout_subvector()
{
    for (int i = 0; i < top; i++)
        cout << *(mas + i) << " ";
}
};

int main()
{
    Subvector a;
    a.push_back(1);
    a.cout_subvector();
    a.push_back(2);
    a.cout_subvector();

    return 0;
}
