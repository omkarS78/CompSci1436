/*
*omkar S
*Lab
*/
// Preprocessor Directive

#include <iostream>
#include <string>

int main()
{
    //Every statement in C++ must end with a semicolon
    // Statement = Anything that does something in the language

    //std::cout << "Hello World" << " " << "Your Name";
    //std::cout<<"Hello World"<<" "<<"Your Name";
    //std::cout << "Hello World" 
    //          << " " 
    //          << "Your Name";
    //std::cout << "Hello World";
    //std::cout << "Your Name";
    std::cout << "Hello World " << "Your Name" << std::endl;
    std::cout << "You are " << 20 << " years old" << std::endl;

    //Identical to << endl;
    std::cout << "Hello World " << "Your Name\n";

    //std::cout << "Hello World \"Your Name\"";
    std::cout << "C:\\Windows";
    //String literals "..."
    // "Whatever"
    // Escape sequence - special meaning to the compiler
    //     - Starts with \ followed by a character
    //   \n - newline
    //   \t - tab
    //   \" - double quote
    //   \\ - slash

    //Integer literals - one or more digits 

    //Floating point literals - one or more digits + fraction
    // 3.14159 or 3E10 -3E10 3E-10  3e10 -3e10

    // Variable - Named memory location where data is stored    
    std::string name;
    name = "Name";
    std::cout << "Hello World " << name;

    //var-decl ::= T id;
    // type = defines what can be stored in the variable and in what format
    // id = unique identifier
    //      Must start with letter or underscore and be followed by letters, digits or underscores
    //      Must be unique within scope
    //      Cannot be a keyword
    int age;
    age = 20;
    std::cout << "You are " << age << " years old";

    // Area of rectangle calculator
    // A = lw 
    std::string firstName;
    //int length;
    //int width;
    //length = 10;
    //width = 20;
    int length = 10, width = 20;

    //Uninitialized variable - YOU MUST assign a value to a variable before you read it
    //int area;
    //area = 0;
    int area = 0;
    //area = length * width;

    std::cout << "Area of rectangle is " << area << std::endl;

    // 2 different approaches to variable declarations
    // Approach #1 Block - all variables together
    //int radius, diameter;
    //std::string circleName;

    //Now I can use the variables

    // Variable declarations
    // Approach #2 Inline - variables are declared just before they are used
    int radius, diameter;
    //Use radius, diameter

    std::string circleName;
    //Use circleName

    double pi;
    pi = 3.14159;

    char letterGrade;
    letterGrade = 'A';

    bool isPassing;
    isPassing = true;

    //Assignment is right associative
    //length = 100;
    //width = 100;
    length = width = 100;
    area = length * width;
    //std:: cout << length ; //verify length is correct 

    //Arithmeti operators 
    // airth_op:: +|-|*|/
    length = length + 10;
    width = width - 20;


    int REUSLT = 10 / 3; //=3
  // moduls is remainder and ONLY works for intergral types
    int  remainder = 10 % 3; // = 1

    int negativlength = -length;

} 

    //scope -liferime of variable 


{   //staring a new lock
    int newvariable1 = 10;

    double newVariable2 = 4.7;
}

    {
         char newvaribales1 = 'A';

    }
    { //std::cout << newVariabel1;
    //strings C++
        std::string
            studentName = "Bob";

        studentName = studentName + "Wilson";
        // Literals - great for static values
        //Variable - great for writable values

        const double Pi = 3.14159;


        //A= Pi * R2
        double areaCricle = Pi * (radius * radius);
        //example 
        const int NumberOfGrade = 5;
        const int NumberOfGrade = 4;
        // can't write constant 
        //pi = 140;

        //done



    }

