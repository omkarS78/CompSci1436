/*
*omkar S
*Lab
*/
// Preprocessor Directive

#include <iostream>

int main()
{
    std::cout << "HellO World" << "" << " Your Name";
    // std :: << "Hello World"
    //        << " "
   //std::cout << "Hello World";
   //std::cout << "Your Name ";
    std::cout << "HEllO WORLD" << std::endl << "Your Name";
    std::cout <<"You are" << 20 << "YEAR OLD" << std::endl;

    //Identical to << end ;
    std::cout << "HEllO WORLD" << std::endl << "Your Name\n";
  
    //String Literals ".."
    // ecscape sequences - sepcial meaning to compiler 
    // - start with // followed by character  ( only can be used for stringer literals )
    // interger  Literals - one or more digits
    //  /t -tab
    //  /" - double quote
    //   //- splash
    // Statment = Anything that does  something in the language 
    //Floating point literals - one or more digits + fraction
    //3.14159 or 3E10 3-10 -3e10
    // Variable _ Named memory loaction where data is stored 
    std::string name;
    name = "name";
    std::cout << "Hello World " << name;

}

