#include "singleton.hpp"
#


int main()
{
    singleton& s1 = singleton::getInstance();
    std::cout<<s1.getCount()<<std::endl;
    singleton& s2 = singleton::getInstance();
    std::cout<<s2.getCount()<<std::endl;
    std::cout<<max(1.2,2.2)<<std::endl;

    int V[5] = {1,2,3,4,6};
    for(int i: V)
    {
        std::cout<<i<<std::endl;
    }
    delegateC d1(2);
    delegateC d2 = {1,2,3,4};
    d2.printD();
    return 0;

}