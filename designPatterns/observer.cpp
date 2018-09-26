#include <iostream>
#include <vector>
#include <string>

class IObserver;

class ISubject
{
  public:
    virtual void add(IObserver* Obs) = 0;
  private:
    virtual void notify() = 0;
};

class IObserver
{
    public:
        virtual void update(int data) = 0;

};

class CSubject: public ISubject
{
    private:
        std::vector<IObserver*> obsList;
        int pData;
        
        void notify()
        {
            for(IObserver* obs:obsList)
                obs->update(this->pData);          
            
        }

    public:
        void add(IObserver* Obs)
        {
            obsList.push_back(Obs);
        }
        void setData(int data)
        {
            pData = data;
            this->notify();
        }

};

class CObserver: public IObserver
{
    public:
        void update(int data)
        {
            std::cout<<"Updated Data in "<<this->pName<<":"<<data<<std::endl;
        }
        CObserver(std::string name):pName(name){};
    private:
        std::string pName;


};

int main(int argc, char const *argv[])
{
    
    CSubject s1;
    IObserver *O1 = new CObserver("O1");
    IObserver *O2 = new CObserver("O2");
    IObserver *O3 = new CObserver("O3");
    s1.add(O1);
    s1.add(O2);
    s1.add(O3);
    s1.setData(1);
    s1.setData(23);
    return 0;
}



