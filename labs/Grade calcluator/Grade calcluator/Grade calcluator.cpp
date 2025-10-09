/*
 Omkar S
 Lab 1 - Grade Calculator
*/

#include <iostream>
  #include <string>
#include <iomanip>

int main() {
    
    std::cout << "Lab 1  Grade Calculator"<< std::endl;
    std::cout << "Omkar S" << std::endl;
    std::cout << "COSC 1436 C++ course" << std::endl << std::endl;


         std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    // Grade variables
    int lab1, lab2, lab3, lab4;
    int exam1, exam2, exam3; 
    int participation, finalExam;

    // Get lab grades
      std::cout << "Lab1: "; std::cin >> lab1;
     std::cout << "Lab2: "; std::cin >> lab2;
      std::cout << "Lab3: "; std::cin >> lab3;
    std::cout << "Lab4: "; std::cin >> lab4;

    // Get exam grades
    std::cout << "Exam1: "; std::cin >> exam1;std::cout << "Exam2: "; std::cin >> exam2;
    std::cout << "Exam3: "; std::cin >> exam3;

    // Get participation and final exam
    std::cout << "Participation: "; std::cin >> participation;
    std::cout << "Final Exam: "; std::cin >> finalExam;

    // Calculate averages
    double labAvg = (lab1 + lab2 + lab3 + lab4) / 4.0;
    double examAvg = (exam1 + exam2 + exam3) / 3.0;
    double classAvg = (labAvg * 0.65) + (examAvg * 0.20) + (participation * 0.05) + (finalExam * 0.10);

    std::cout << std::endl;

    // Output lab grades
    std::cout << name << " lab grades:" << std::endl;
    std::cout << std::setw(10) << std::left << "Lab1" << lab1 << std::endl;std::cout << std::setw(10) << std::left << "Lab2" << lab2 << std::endl; std::cout << std::setw(10) << std::left << "Lab3" << lab3 << std::endl;
    std::cout << std::setw(10) << std::left << "Lab4" << lab4 << std::endl;
    std::cout << std::setw(10) << std::left << "Avg" << labAvg << std::endl << std::endl; //i used setw and left to format the output just like in class 

    // Output exam grades
    std::cout << name << " exam grades:" << std::endl;
    std::cout << std::setw(10) << std::left << "Exam1" << exam1 << std::endl;std::cout << std::setw(10) << std::left << "Exam2" << exam2 << std::endl;
    std::cout << std::setw(10) << std::left << "Exam3" << exam3 << std::endl;
    std::cout << std::setw(10) << std::left << "Avg" << examAvg << std::endl << std::endl;

    //  grades for both final exam and participation
    std::cout << name << " other grades:" << std::endl;
    std::cout << std::setw(12) << std::left << "Participation" << participation << std::endl;
    std::cout << std::setw(12) << std::left << "Final Exam" << finalExam << std::endl << std::endl;

    //  final grade 
    std::cout << name << " class grade:" << std::endl; std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(18) << std::left << "Lab Average (65%)" << labAvg << std::endl;std::cout << std::setw(18) << std::left << "Exam Average (20%)" << examAvg << std::endl;
    std::cout << std::setw(18) << std::left << "Participation (5%)" << static_cast<double>(participation) << std::endl;
    std::cout << std::setw(18) << std::left << "Final Exam (10%)" << static_cast<double>(finalExam) << std::endl;
    std::cout << std::setw(18) << std::left << "Class Average" << classAvg << std::endl;

    return 0;
}
