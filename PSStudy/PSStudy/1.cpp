#include <iostream>
#include <stdio.h>

class B
{
public:
     int nNumber;

public:
    B() { nNumber = 1; }
    B(const B& rhs)
    {
        nNumber = rhs.nNumber;
    }
    int getNumber() const {
        return nNumber;
    }
};

class A
{
private:
    int nNumber;
    const B* nList;
public:
    A(int number) : nNumber(number)
    {
    }
    A(const A& rhs)
    {
        nNumber = rhs.nNumber;
    }
    void addB(const B* oh)
    {
        nList = oh;
    }

    const B* GetB()
    {
        return nList;
    }
};

int main()
{
    B* b = new B();
    A a(1);

    a.addB(b);

    auto ptr = a.GetB();
    std::cout << ptr->nNumber;
    
    ptr->getNumber();
    
    return 0;
}   