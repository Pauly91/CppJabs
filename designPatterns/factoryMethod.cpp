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
    virtual void instrumentLogic() = 0;
    static financialFactory* makeFinancialInstrument(int type); 
    // By creating this as a static object the client is not required to create an object.
    // Also by making it static gives the same function throughout the object.
};
