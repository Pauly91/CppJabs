#include <iostream>
#include <string>
/*
    - Decorator pattern gives additional functionality to a baseline class dynamically.
    - It is a better way than subclass that leads to class explosion.
    - Example of a use case is to build an ice-cream with add ons.
*/


class IIceCream
{
    public:
        virtual int getPrice() = 0;
        virtual std::string getName() = 0;
};

class CVanillaIceCream: public IIceCream
{
    private:
        const int price = 10;
        const std::string name = "Vanilla ";
    public:
        int getPrice()
        {
            return price;
        }
        std::string getName()
        {
            return name;
        }
};

class CChocoIceCream: public IIceCream
{
    private:
        const int price = 15;
        const std::string name = "Chocolate ";
    public:
        int getPrice()
        {
            return price;
        }
        std::string getName()
        {
            return name;
        }
};
/* 
    - Is there a way to make the decorator class abstract ?
    - Or should the decorator class abstract ?
    - What are the scenarios for the either or ?

*/    


//  Concrete decorators can only exist with the base class.

class Idecorator: public IIceCream
{
    private:
        IIceCream * IC;
    public:
        Idecorator(IIceCream *ic)
        {
            IC = ic;
        }
        ~Idecorator()
        {
            delete IC;
        }
        virtual int getPrice()
        {
            return IC->getPrice();
        }
        virtual std::string getName()
        {
            return IC->getName();
        }
};

class ChocoChipDecorator: public Idecorator
{
    private:
        const int price = 5;
        const std::string name = "Chocolate Chip ";        
    public:
        ChocoChipDecorator(IIceCream* ic):Idecorator(ic){};
        int getPrice()
        {
            return Idecorator::getPrice() + price;
        }
        std::string getName()
        {
            return Idecorator::getName() + "" + name;
        }
        
};

class SparklesDecorator: public Idecorator
{
    private:
        const int price = 3;
        const std::string name = "Sparkles ";        
    public:
        SparklesDecorator(IIceCream* ic):Idecorator(ic){};
        int getPrice()
        {
            return Idecorator::getPrice() + price;
        }
        std::string getName()
        {
            return Idecorator::getName() + "" + name;
        }
    
};


int main(int argc, char const *argv[])
{
    IIceCream *VSC = new ChocoChipDecorator(new SparklesDecorator(new CVanillaIceCream));
    // The methods get called like a "recursion".
    std::cout<<VSC->getName()<<std::endl;
    std::cout<<"Price: "<<VSC->getPrice()<<std::endl;
    return 0;
}

/*
    - The decorators should be similar to the base class.
    - Also decorators patterns would make a more sense if the behaviour of the decorators are different
      unlike the example.
    - In essential add extra functionality on the fly.
    - Deprecation of some functionalities of class. 
*/