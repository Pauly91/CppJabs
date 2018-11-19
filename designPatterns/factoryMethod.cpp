 #include <iostream>

/*
    * Types of factory:
        * Simple factory (Not really a pattern)
        * Factory method
        * Abstract factory


    * Notes of Factory Method
        * Factory handles all the instantiation
        * More like a wrapper for new
        * The creation of the object is on runtime based on conditions - These condition could vary or they set certain inital property of the object.
        * Factory methods give the client a nice utility to create object and for developer a brilliant way to control the creation of object and do what
        ever he wants with it.
        * The Game design Example of obstacles based on the level
        * This design essentially saves the client from rebuilding his code if when the developer introduces new types of object.
        * Essentially encapsulating the object creation as much as possible from the client.
        
    * This link gives a good explanation for the use case: https://sourcemaking.com/design_patterns/factory_method/cpp/1
    
*/


/*
    The example is a factory that creates a financial instrument based on the requirement
*/

#include <iostream>

class financialFactory
{
    public:
        virtual void instrumentLogic() = 0;
        static financialFactory* makeFinancialInstrument(int type); 
    // By creating this as a static object the client is not required to create an object.
    // Also by making it static gives the same function throughout the object.
};

class mutualFunds : public financialFactory
{
    void instrumentLogic()
    {
        std::cout<<"I am mutual fund"<<std::endl;
    }
};
class recurrentDeposit : public financialFactory
{
    void instrumentLogic()
    {
        std::cout<<"I am recurrentDeposit"<<std::endl;
    }
};
class fixedDeposit : public financialFactory
{
    void instrumentLogic()
    {
        std::cout<<"I am fixedDeposit"<<std::endl;
    }
};
class bladeDeposit : public financialFactory
{
    void instrumentLogic()
    {
        std::cout<<"I am blade money"<<std::endl;
    }
};




financialFactory * financialFactory::makeFinancialInstrument(int choice)
{
    financialFactory * obj = NULL;
    if (choice == 1) {
        obj = new mutualFunds;
    }
    else if(choice == 2) {
        obj = new recurrentDeposit;
    }
    else if(choice == 3) {
        obj = new fixedDeposit;
    }
    else if(choice == 4) {
        obj = new bladeDeposit;
    }
    else {
        obj = NULL;   
        std::cout<<"Invalid Choice"<<std::endl;
    }
    return obj;
    
}



int main(int argc, char const *argv[])
{
    int choice;
    std::cin>>choice;
    financialFactory *obj = financialFactory::makeFinancialInstrument(choice);
    if (obj != NULL) {
        obj->instrumentLogic();
    }
    return 0;
}

