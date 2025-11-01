//name : Omkar S  
//Lab 2 - Loan Interest Calculator
//  
//COSC 1436 Fall 2025 


#include <iostream> 
#include <iomanip> 

int main()
{

    int loanAmount;
    double interestRate;
    double monthlyPayment; //used double because interest rate can be decimal

    // introduction   

    std::cout << "Lab 2 - Loan Interest Calculator" << std::endl;
    std::cout << "Omkar S" << std::endl;
    std::cout << "COSC 1436" << std::endl << std::endl;

    // Loan amount input and validation 

    std::cout << "Enter loan amount (1 - 1000): ";
    std::cin >> loanAmount;
    std::cout << std::endl;

    while (loanAmount < 1 || loanAmount > 1000) //i used while loop to validate the input for loan amount
    {
        std::cout << "ERROR: Loan must be between 1 and 1000." << std::endl;
        std::cout << "Enter loan amount (1 - 1000): ";
        std::cin >> loanAmount;
    }
    // Interest rate input and validation 
    std::cout << "Enter interest rate (%) (1.0 - 100.0): ";
    std::cin >> interestRate;

    while (interestRate < 1.0 || interestRate > 100.0)
    {
        std::cout << "ERROR: Interest rate must be between 1.0 and 100.0." << std::endl;
        std::cout << "Enter interest rate (%) (1.0 - 100.0): ";
        std::cin >> interestRate;
    }
    // Convert percentage to decimal  / this will help me convert the interest rate from percentage to decimal for calculation on monthly interest i did by 100

    interestRate = interestRate / 100.0;

    // Monthly payment input and validation 

    std::cout << "Enter monthly payment (0 - " << loanAmount << "): ";  std::cin >> monthlyPayment;
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
        << std::setw(12) << "Interest" << std::setw(15) << "New Balance"
        << std::endl;

    double balance = loanAmount;
    double totalInterest = 0.0;

    double totalPayments = 0.0;
  // Monthly calculations loop , loop systme was one of the hardest part of the assignment , but the assigment 4 helped me understand it better like when i did the for loop for 12 months 
    for (int month = 1; month <= 12; ++month)
    {

        double paymentThisMonth = monthlyPayment;
        double interestThisMonth = 0.0;
        if (balance <= 0)
        {
            paymentThisMonth = 0.0;
        } else
        {

            if (paymentThisMonth > balance)
            {
                paymentThisMonth = balance;  balance = balance - paymentThisMonth; //if payment is more than balance adjust the payment to balance 
            }
            if (balance > 0)
            {
                interestThisMonth = balance * interestRate;
            }
            balance = balance + interestThisMonth;
            totalPayments += paymentThisMonth;
            totalInterest += interestThisMonth;
        }

      //row output just like we did on the assigment 3 usig setw to align the columns

        std::cout << std::setw(6) << month

            << std::setw(4) << "$" << std::setw(8) << std::right << (balance - interestThisMonth)

            << std::setw(4) << "$" << std::setw(8) << std::right << paymentThisMonth

            << std::setw(4) << "$" << std::setw(8) << std::right << interestThisMonth

            << std::setw(4) << "$" << std::setw(8) << std::right << balance

            << std::endl;
    }

     // Totals 

    std::cout << std::endl;
    std::cout << "Total Payments: $" << totalPayments << std::endl;
    std::cout << "Total Interest: $" << totalInterest << std::endl;
    return 0;

}
