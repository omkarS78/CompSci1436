/*
* Omkar S
* Lab 1 - Grade Calcluator   // 
*/

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // this is starting part 
    std::cout<<"Lab 1 - Grade Calcluator"<<std::endl;

    std::cout<<"Omkar S"<<std::endl;
    std::cout<<"COSC 1436  C++ course"<<std::endl;

    std::cout<<std::endl;


    
    std::string name;

    std::cout<<"Pls enter your name: ";std::getline(std::cin,name);
    
    std::getline(std::cin,name);int l1,l2,l3,l4;  int e1,e2,e3; int part, finalExam;


 int l1,l2,l3,l4; 
    int e1,e2,e3;
    int part, finalExam;

    
    
    std::cout<<"lab1: "; std::cin>>l1;std::cout<<"lab2: "; std::cin>>l2;


  std::cout<<"lab2: "; std::cin>>l2;std::cout<<"lab3: "; std::cin>>l3;
    
    std::cout<<"lab4: "; std::cin>>l4; std::cout<<"lab4: "; std::cin>>l4;

    
    std::cout<<"exam1: "; std::cin>>e1; std::cout<<"exam2: "; std::cin>>e2; // i guess i this for exam1 thru 2
    
    
  std::cout<<"exam3: "; std::cin>>e3;

    
    std::cout<<"participation: "; std::cin>>part;


    std::cout<<"finalExam: "; std::cin>>finalExam;

    
    double labAvg=(l1+l2+l3+l4)/4.0;double examAvg=(e1+e2+e3)/3.0;// this one i add all the averge like on the class

  
    // weighted
    double classAvg=(labAvg*0.65)+(examAvg*0.20)+(part*0.05)+(finalExam*0.10);

    std::cout<<std::endl;

    //output labs (with setw like chap2)
  { std::cout<<name<<" lab grades:"<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"Lab1"<<l1<<std::endl;
 
    std::cout<<std::setw(10)<<std::left<<"Lab2"<<l2<<std::endl;

    std::cout<<std::setw(10)<<std::left<<"Lab3"<<l3<<std::endl;
 std::cout<<std::setw(10)<<std::left<<"Lab4"<<l4<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"Avg"<<labAvg<<std::endl;

    std::cout<<std::endl;}

    //exams
    std::cout<<name<<" exam gradez:"<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"Exam1"<<e1<<std::endl;std::cout<<std::setw(10)<<std::left<<"Exam2"<<e2<<std::endl;
    
    std::cout<<std::setw(10)<<std::left<<"Exam3"<<e3<<std::endl;std::cout<<std::setw(10)<<std::left<<"Avg"<<examAvg<<std::endl;


    std::cout<<std::endl;

    // others
    std::cout<<name<<" other:"<<std::endl;
    std::cout<<std::setw(12)<<std::left<<"Participation"<<part<<std::endl;std::cout<<std::setw(12)<<std::left<<"FinalExam"<<finalExam<<std::endl;



 std::cout<<std::endl;

    //class grade
   { std::cout<<name<<" class grade:"<<std::endl;}


    {     std::cout<<std::fixed<<std::setprecision(2); //from percison i add 2 for fixed number following same 
    std::cout<<std::setw(18)<<std::left<<"Lab average(65%)"<<labAvg<<std::endl;
 std::cout<<std::setw(18)<<std::left<<"Exam average(20%)"<<examAvg<<std::endl; //   i did same as example
    std::cout<<std::setw(18)<<std::left<<"Part (5%)"<<(double)part<<std::endl;
    std::cout<<std::setw(18)<<std::left<<"Final Exam(10%)"<<(double)finalExam<<std::endl; 

    std::cout<<std::setw(18)<<std::left<<"Class Avg"<<classAvg<<std::endl;std::cout<<std::setw(18)<<std::left<<"Exam Average(20%)"<<examAvg<<std::endl;

    return 0;}
}
