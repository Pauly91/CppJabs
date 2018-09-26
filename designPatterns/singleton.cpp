#include "singleton.hpp"

 
singleton& singleton::getInstance()
{
    // This makes it atomic.
    static singleton s1;    
    return s1;
}

int singleton::getCount()
{
    return ++count1;
}


delegateC::delegateC()
{
    array = nullptr;
}

delegateC::delegateC(int asize = 0):aSize(asize)
{
    if(aSize == 0)
        array = nullptr;
    else
        array = new int[aSize];
}
delegateC::delegateC(std::initializer_list<int> v): delegateC(v.size())
{
    int c1 = 0;
    if(0 != v.size())
    {
        for(auto &i:v)
        {
            array[c1] = i;
            c1++;     
        }
    }
}
void delegateC::printD()
{
    for(int c1 = 0;c1 < aSize;c1++)
    {
        std::cout<<array[c1]<<std::endl;
    }
}