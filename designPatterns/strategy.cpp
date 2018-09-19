#include <iostream>




class IFlyingBehaviour; 
class IQuackBehaviour;
class IDisplayBehaviour;

class IDuck
{
    public:
        IFlyingBehaviour* f;
        IQuackBehaviour* q;
        IDisplayBehaviour* d;
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


class IDisplayBehaviour
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




class CCityDuck: public IDuck
{
    public:
        CCityDuck()
        {
            IFlyingBehaviour *f = new CJetFLying;
            IQuackBehaviour* q = NULL;
            IDisplayBehaviour* d = NULL;
        }
};

int main(int argc, char const *argv[])
{
    
    CCityDuck c1;
    c1.f->flying();
    return 0;
}
