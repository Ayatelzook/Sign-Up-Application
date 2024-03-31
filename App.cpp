#include<iostream>
#include<string>
#include<array>

constexpr  int MAX_RECORDS=100;
int ID=0;
int ID_RECORDED=0;
class User
{
    public:
    std::string USER_NAME;
    int USER_AGE;
    
};

std::array<User,MAX_RECORDS>RECORDS;
enum class options
{
    Add=1,
    Fetch=2,
    quit=3

};

void SHOW()  
{
    std::cout<<"please select an option: \n ";
    std::cout<<"1.Add Record \n";
    std::cout<<"2.Fetch Record \n";
    std::cout<<"3.Quit \n";

}

void ADD_RECORD(std::string name ,int age)
    {
        
        if(ID<MAX_RECORDS)
        {
            RECORDS[ID].USER_NAME=name;
            RECORDS[ID].USER_AGE=age;
            ID=ID+1;
            std::cout<<"User Record Added Successfully \n";
        }
        else
        std::cout<<"Sorry! Max number of Records reached \n";
        
    }
    void FETCH(int ID_RECORDED)
    {
        if(ID_RECORDED<=ID)
        {
            std::cout<<"User_ID :"<<ID_RECORDED<<"\n";
            std::cout<<"User_name :"<<RECORDS[ID_RECORDED].USER_NAME<<"\n";
            std::cout<<"User_Age :"<<RECORDS[ID_RECORDED].USER_AGE<<"\n";

        }      
        else
        std::cout<<"INVALID ID"<<"\n";  
    }
    const int USER_SELECT()
    {
        int option;
        std::cout<<"Enter Option :";
        std::cin>>option;
        return option;

    }
    
    int main ()
    {
    std::cout<<"Sign up Application  \n";
    bool QUIT=false;
    while(!QUIT)
    {  
      SHOW();
      int option =USER_SELECT();
      std::string User_Name;
      int User_Age;
      switch(option)
      {
        case (static_cast<int>(options::Add)):  //to convert from options to int 
        std::cout<<"please enter your name and age \n";
        std::cout<<"User Name:";
        std::cin>>User_Name;
        std::cout<<"User Age :";
        std::cin>>User_Age;
        ADD_RECORD(User_Name,User_Age);
        break;
        case (static_cast<int>(options::Fetch)):
        std::cout<<"please Enter User ID: ";
        std::cin>>ID_RECORDED;
        FETCH(ID_RECORDED);
        break;
        case (static_cast<int>(options::quit)):
        QUIT=true;
        break;
        default:
        std::cout<<"INVALID OPTION \n";
        break;


      }
     }
     return 0;
   }
