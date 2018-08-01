#ifndef FRACTION_ABEL_H
#define FRACTION_ABEL_H

#include <iostream>

namespace abel
{
    class fraction
    {
    private:
        int numerator;
        int denominator;
    public:
        fraction(const int &a, const int &b)
        {
            numerator = a;
            denominator = b;
        }
        void print();
        fraction simplifyFraction(fraction &f)
        {
            if(f.numerator%f.denominator == 0)
            {
                f.numerator = f.numerator/f.denominator;
                f.denominator = 1;
            }
            else
            {
                f.denominator = f.denominator/f.numerator;
                f.numerator = 1;
            }
        }
        fraction operator*(const fraction &f1);
        //fraction operator*(const fraction &f1,const int a);
        //fraction operator*(const int a,const fraction &f1);
    };
} // End of namespace
#endif