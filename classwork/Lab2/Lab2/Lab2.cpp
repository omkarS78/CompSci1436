/*

* Omkar S

* Lab 2 - Loan Interest Calculator

* COSC 1436 Fall 2025

*/



#include <iostream> 

#include <iomanip> 



int main()

{

    int loanAmount;

    double interestRate;

    double monthlyPayment;


    //  introduction 

    std::cout << "Lab 2 - Loan Interest Calculator" << std::endl;

    std::cout << "Omkar S" << std::endl;

    std::cout << "COSC 1436 " << std::endl << std::endl;






    //so on this one the user inputs the loan amount, interest rate and monthly payment but there are checks to make sure the values are within a certain range
    std::cout << "Enter loan amount (1 - 1000): ";

    std::cin >> loanAmount;



    while (loanAmount < 1 || loanAmount > 1000)

    {

      std::cout << "ERROR: Loan must be between 1 and 1000." << std::endl;

      std::cout << "Enter loan amount (1 - 1000): ";

        std::cin >> loanAmount;

    }



 //interest rate 

    std::cout << "Enter interest rate (%) (1.0 - 100.0): ";

    std::cin >> interestRate;



    while (interestRate < 1.0 || interestRate > 100.0)

    {

        std::cout << "ERROR: Interest rate must be between 1.0 and 100.0." << std::endl; //whenver the user inputs a value higher then 1000 it will give an error message, 

     std::cout << "Enter interest rate (%) (1.0 - 100.0): ";

     std::cin >> interestRate;

    }  // so when i try to write typo like 1900 it just gave me error so i think its fine



    // so i will Convert percentage to decimal by 100

    interestRate = interestRate / 100.0;



    // Prompt for monthly payment 

    std::cout << "Enter monthly payment (0 - " << loanAmount << "): "; std::cin >> monthlyPayment;



    while (monthlyPayment < 0 || monthlyPayment > loanAmount)

    {

        std::cout << "ERROR: Payment must be between 0 and loan amount." << std::endl;

        std::cout << "Enter monthly payment (0 - " << loanAmount << "): ";

        std::cin >> monthlyPayment;

    }



    // Table header 

    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::setw(6) << "Month"

        << std::setw(12) << "Balance"

        << std::setw(12) << "Payment"

        << std::setw(12) << "Interest"

        << std::setw(15) << "New Balance"

        << std::endl;





// Variables for loop 

    double balance = loanAmount;

    double totalInterest = 0.0;

    double totalPayments = 0.0;


    for (int month = 1; month <= 12; ++month)

    {


        double interestThisMonth = 0.0;



        if (balance <= 0)

        {

            paymentThisMonth = 0.0;

        }

        else

        {

            if (paymentThisMonth > balance)

            {

                paymentThisMonth = balance;

            }



            balance = balance - paymentThisMonth;



           if (balance > 0)

           {

               interestThisMonth = balance * interestRate;

            }   



          balance = balance + interestThisMonth;



          totalPayments += paymentThisMonth;

          totalInterest += interestThisMonth;

        }



        std::cout << std::setw(6) << month

            << std::setw(12) << "$" << std::setw(7) << std::right << (balance - interestThisMonth)// i created setw same as the output example like from assigment 3 

            << std::setw(5) << " " << std::setw(7) << std::right << "$" << std::setw(5) << paymentThisMonth

            << std::setw(5) << " " << std::setw(7) << std::right << "$" << std::setw(5) << interestThisMonth

            << std::setw(5) << " " << std::setw(7) << std::right << "$" << std::setw(5) << balance

            << std::endl;

    }



    // Totals 

    std::cout << std::endl;

    std::cout << "Total Payments: $" << totalPayments << std::endl;

    std::cout << "Total Interest: $" << totalInterest << std::endl;



    return 0;

}

