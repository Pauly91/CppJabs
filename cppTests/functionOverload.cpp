#include "functionOverload.hpp"

using namespace abel;


void fraction::print()
{
    std::cout<<numerator<<'/'<<denominator<<std::endl;
}




fraction fraction::operator*(const fraction &f1)
{
    return fraction((f1.numerator*this->numerator),(f1.denominator*this->denominator));
}

/*
fraction fraction::operator*(const fraction &f1,const int a)
{
    return fraction((f1.numerator*a),(f1.denominator*1));
}

fraction fraction::operator*(const int a,const fraction &f1)
{
 
    return fraction((f1.numerator*a),(f1.denominator*1));
}
*/

