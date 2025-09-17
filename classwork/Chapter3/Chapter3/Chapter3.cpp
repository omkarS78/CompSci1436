#include <iostream>
#include < string>
#include <cmath>
#include <iomanip>


void main()
{
    std::cout << "Enter values for X and Y :";

    double x, y;
    std::cin >> x >> y;
    //function X and Y result 
    //______________________
    std::cout << std:: setw(9) << "function " << "X" << std::setw(7) <<"Y"
        << std::setw(12) << "Result" << std::endl;
    std::cout << "_______________________________________" << std::endl;
    std::cout << "pow" << x << y << pow(x, y) << std::endl;
   
    std::cout << "sqrt" << x << y << sqrt(x) << std::endl;
    std::cout << "ceil" << x << y << ceil(x) << std::endl;

    std::cout << "round" << x << y << round (x) << std::endl;
    std::cout << "trunc" << x << y << trunc(x) << std::endl;






}
void experssionDemo()
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
    int left = 10;
    int right = 3;
    double intdivision = 10 / 3;//int 
    intdivision = left / right;
    intdivision = (double)left / right;
    intdivision = left / (double)right;
    intdivision = (double)(left / right);

    intdivision = static_cast<double>(left) / (right);

    intdivision = left / static_cast<double>(right);


    //math Functions 
    //pow(x,y) => power X to the Y Power 
    ///sqrt(x)=> is square root of X
    //abs(x) => absolute value of X
    //
    // ceil(x)=> Smallest posible intergral value >=X
    // floot (x) => Largest possible intergral value <=X 

    //round (x) => Round a float to an int using midpoint rounding 
    //trnc(x) => Trunactes a float to int 
    
    //exp(X) => exponential E raise to X power , E = 2.17828
    //log(x) => logarithm , inverse of exp

    double result;
    result = pow(5, 3); // 5 * 5 * 5 =125
    result - pow(25, -3);//cube root of 125

    result = sqrt(100);//10

    result = sqrt(pow(5, 2));//5
    result = abs(-10);//10
    result = abs(10);//10

    result = ceil(14.5);//15
    result = floor(3.1);//3

    result = round(14.5);
    result = round(3.1);

    result = trunc(14.5);//114
    result = trunc(3.1);//3
    result = (int)14.5;

    result = exp(4);
    result = log(exp(4));//4












    



  
    



    










}
