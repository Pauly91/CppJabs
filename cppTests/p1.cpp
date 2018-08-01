#include <iostream>

class fruit
{
    
    protected:
        std::string name;
        std::string color;
    public:
        fruit(std::string fname,std::string fcolor): name(fname), color(fcolor) {}
};

class Apple: public fruit
{
    public:
        Apple(std::string fname = "apple",std::string fcolor = "red"): fruit(fname,fcolor){};
        
        std::string getName()
        {   
            return name;
        }
        std::string getColor()
        {   
            return color;
        }
};

class Banana: public fruit
{
    public:
        Banana(std::string fname = "banana",std::string fcolor = "yellow"):fruit(fname,fcolor){};
        Banana(std::string fcolor = "yellow"): fruit("banana",fcolor){};
        Banana(): fruit("banana","yellow"){};


        std::string getName()
        {   
            return name;
        }
        std::string getColor()
        {   
            return color;
        }

};


int main(int argc, char const *argv[])
{
	Apple a("red");
	Banana b;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	
	return 0;
    return 0;
}
