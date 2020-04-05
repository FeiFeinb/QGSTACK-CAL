#include<iostream>    
template<class T, int SIZE = 100>
class QGARRSTACK {
private:
    T *arr = new T[SIZE];
    int TOP; 
public:
    QGARRSTACK() :TOP(-1) {}
    ~QGARRSTACK() {
        delete arr;
        TOP = -1;
    }
    void push(const T& data)
    {
        if (!isFull())
            arr[++TOP] = data;
        else
            std::cout << "FULL!" << std::endl;
    }
    void pop()
    {
        if (!isEmpty())
            TOP--;
        else
            std::cout << "EMPTY!" << std::endl;
    }
    void clear()
    {
        TOP = -1;
    }
    const T& top()
    {
        if(!isEmpty())
            return arr[TOP];
    }
    bool isEmpty()
    {
        return TOP == -1;
    }
    bool isFull() 
    {
        return TOP == SIZE - 1;
    }
    int howBig() {
        return TOP + 1;
    }
};