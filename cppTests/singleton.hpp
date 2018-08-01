#ifndef ABEL_SINGLETON_HPP
#define ABEL_SINGLETON_HPP

#include <iostream>
#include <vector>

class singleton
{
    private:
        int count1;
        singleton(){count1 = 1;};

    public:
        static singleton& getInstance();
        int getCount();

};
template <typename T1,typename T2>
T1 max(T1 x, T2 y)
{
    return (x > y)? x:y;
}


class delegateC
{
    private:
        int *array;
        int aSize;
    public:
        delegateC();
        delegateC(int aSize);
        delegateC(std::initializer_list<int> v);
        void printD();
};


/*
What is a singleton
- Singleton is design pattern that permits only the exisitence of one object at a time.
What is Static
- No matter how many objects are created Static entities only one instance of that exist for the entire class, static variables needs to be initilzed. 


*/

#endif