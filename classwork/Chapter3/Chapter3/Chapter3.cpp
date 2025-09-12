#include <iostream>
#include < string>


void main()
{
	//prompt user for radius of circle 
	std::cout << "enter radius:";
	

	int radius = 0;
	std::cin >> radius;
	const double Pi = 3.14159;

	//Area pi * R^2
	double area = Pi * radius * radius;
	std::cout << "Area = "<< Pi <<"*" << radius << "*" << radius << std::endl;
	std::cout << "Area = "<< area << std::endl;

	//Trinagle 
	// Area = 1/2 * base * height 

	std::cout << "enter base and height of tringle:";
	int base = 0, height = 0;
	//std::cin >> base;
	//std::cin >> height;
	std::cin >> base >> height;
	//Area =1/2 * base * height 
	area = (1.0 / 2) * base * height;
	std::cout << "Area=" << area << std::endl;
	int someVaule = (1.0 / 2);

	std::cout << "Enter name:";
	std::string name;
	//std::cin >> name;
	std::cin.ignore();
	std::getline(std::cin, name); //getline is use to get space when it need 

	std::cout << name << std::endl;


	//overflow and underflow
	short smallValue = 32767;
	smallValue = smallValue + 1;

	short largeValue = -32768;
	largeValue = largeValue - 1;
	std::cout << smallValue << "" << largeValue << std::endl;
	//double * int *int = double . because double is lager so it break dowm into small to big
	//(int*int) * int * int = double 



    










}
