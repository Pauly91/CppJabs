#include <iostream>
#include <string>

// Reference: https://sourcemaking.com/design_patterns/strategy


/*

This design pattern is used when there is some code to be shared
and some code that is specfic to the object that is being created 


*/

class IFlyingBehaviour; 
class IQuackBehaviour;
class IDisplayBehaviour;



class Duck
{
    public:
        void setFlyStrategy(int choice);
        void setQuackStrategy(int choice);
        void display();
        void fly();
        void quack();
        Duck(std::string str):name(str){};
    private:
        IFlyingBehaviour* f;
        IQuackBehaviour* q;
        std::string name; 

};

class IFlyingBehaviour
{
    public:
        virtual void flying() = 0;
};

class IQuackBehaviour
{
    public:
        virtual void quacking() = 0;
};



class CJetFLying: public IFlyingBehaviour
{
    public:
        void flying()
        {
            std::cout<<"Jet Flying"<<std::endl;
        }
};

class CSlowFLying: public IFlyingBehaviour
{
    public:
        void flying()
        {
            std::cout<<"Slow Flying"<<std::endl;
        }
};

class CLoudQuack: public IQuackBehaviour
{
    public:
        void quacking()
        {
            std::cout<<"Loud Quack"<<std::endl;
        }
};

class CSoftQuack: public IQuackBehaviour
{
    public:
        void quacking()
        {
            std::cout<<"Soft Quack"<<std::endl;
        }
};

void Duck::setFlyStrategy(int choice)
{
    switch (choice)
    {
        case 1:
            f = new CJetFLying;
            break;
        case 2:
            f = new CSlowFLying;
        default:
            std::cout<<"Invalid Entry"<<std::endl;
            break;
    }
}

void Duck::setQuackStrategy(int choice)
{
    switch (choice)
    {
        case 1:
            q = new CLoudQuack;
            break;
        case 2:
            q = new CSoftQuack;
        default:
            std::cout<<"Invalid Entry"<<std::endl;
            break;
    }
}

void Duck::fly()
{
    f->flying();
}
void Duck::quack()
{
    q->quacking();
}

void Duck::display()
{
    std::cout<<name<<std::endl;
}

int main(int argc, char const *argv[])
{
    Duck cityDuck("City Duck");

    cityDuck.setFlyStrategy(1);
    cityDuck.setQuackStrategy(1);
    cityDuck.display();
    cityDuck.fly();
    cityDuck.quack();
    
    return 0;
}
