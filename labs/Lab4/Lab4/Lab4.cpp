/*
 * Lab 4 
 * COSC 1436
 */

#include <iostream>
#include <iomanip>
#include <string>

int ReadInt()
{
    int value;

    while (true)
    {
        std::cin >> value;

        if (!std::cin.fail())
            return value;

        std::cin.clear();
          std::cin.ignore(1000, '\n');
         std::cout << "ERROR: You must enter an integervalue"<< std::endl;
          std::cout << "Enter a value: ";
    }
}

void DisplayError(const std::string& message)
{
    std::cout << "ERROR: " << message << std::endl;
}

void DisplayProgramInformation() // i created intro  for function so it would disply  termanial when it debug 
{
    std::cout << "Lab 4 - Array Calculations" << std::endl;
      std::cout << "Your Name" << std::endl;
      std::cout <<"COSC 1436 - Semester" << std::endl;
    std::cout <<"-------------------------" << std::endl;
}

int ReadInitialValues(int values[], int size)
{
    int count = 0;

    while (count < size)
    {
        std::cout << "Enter a value: ";

        int value = ReadInt();

        if (value == 0)
            break;
        else if (value < 0)
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        else
        {
            values[count] = value;++count;
        }
    }

    return count;
}

char ReadMenuOption()// story 2  this where the menu is displayed i used same format as the class work for chapter 4
{
    char choice;

    std::cout << std::endl;
     std::cout << "Main Menu" << std::endl;
    std::cout << "---------------" << std::endl;
     std::cout << "A) dd" << std::endl;
  std::cout << "L) argest" << std::endl;
    std::cout << "S) mallest" << std::endl;
    std::cout << "M) ean" << std::endl;
      std::cout << "V) iew" << std::endl;
    std::cout << "I) nsert" << std::endl;
     std::cout << "Q) uit" << std::endl;
    std::cout << "Enter choice: ";

    std::cin >> choice;
    return choice;
}

int GetLargest(const int values[], int count)
{
   int largest = values[0];   for (int index = 1; index < count; ++index)
   {
        if (values[index] > largest)
            largest = values[index];
    
   }

    return largest;
}

int GetSmallest(const int values[], int count) // story 3 this function gets the smallest value from the array
{
    int smallest = values[0];

  
    for (int index = 1; index < count; ++index)
    {
        if (values[index] < smallest)
            smallest = values[index];
    }

    return smallest;
}

int GetSum(const int values[], int count) //` this function gets the sum of the values in the array
{
    int sum = 0;

    for (int index = 0; index < count; ++index)
        sum += values[index];

    return sum;
}

double GetMean(const int values[], int count)
{
    int sum = GetSum(values, count);
    return static_cast<double>(sum) / count;
}

void DisplayValues(const int values[], int count)
{
    if (count == 0)
    {
        std::cout << "No values to display" << std::endl;
        return;
    }

    for (int index = 0; index < count; ++index)
    {
        std::cout << values[index] << "\t";

        if ((index + 1) % 10 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl;
}

int InsertValues(int values[], int count, int size) // story 4 this function allows the user to insert more values into the array 
{
    while (count < size)
    {
        std::cout << "Enter a value (0 to stop): ";

        int value = ReadInt();
                  if (value == 0)
            break;
        else if (value < 0)
            std::cout << "You must enter a value greater than or equal to 0"
                      << std::endl;
        else
        {
            values[count] = value;
            ++count;
        }
    }

    return count;
}

int main() // Main program entry point justlik on the class work for chapter 4
{
    const int MaximumValues = 100;
    int values[MaximumValues];
    int count = 0;

    DisplayProgramInformation();

    count = ReadInitialValues(values, MaximumValues);

    bool done = false;

    do
    {
        char choice = ReadMenuOption();

        switch (choice)
        {
            case 'A':
            case 'a':
                if (count > 0)
                    std::cout << "Sum = " << GetSum(values, count) << std::endl;
                else
                    std::cout << "No values entered yet" << std::endl; // I added this line to handle the case when no values are entered
                break;

            case 'L':
            case 'l':
                if (count > 0)
                    std::cout << "Largest = " << GetLargest(values, count) << std::endl;
                else
                    std::cout << "No values entered yet" << std::endl;
                break;
            case 'S':case 's':
                if (count > 0)
                    std::cout << "Smallest = " << GetSmallest(values, count) << std::endl;
                else
                    std::cout << "No values entered yet" << std::endl;
                break;

                          case 'M':case 'm':
                if (count > 0)
                {
                    std::cout << std::fixed << std::setprecision(4);
                    std::cout << "Mean = " << GetMean(values, count) << std::endl;
                } else
                    std::cout << "No values entered yet" << std::endl;
                break;

            case 'V':
            case 'v':
                DisplayValues(values, count);//this would display the values in the array like on chapter 6 usinf  the function 
                break;

            case 'I':
            case 'i':
                count = InsertValues(values, count, MaximumValues);
                break;

            case 'Q':
            case 'q':
                done = true;
                break;

            default:
                DisplayError("Invalid choice");
                break;
        }
    } while (!done);

    return 0;
}