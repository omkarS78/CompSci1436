// Course: COSC 1436
// Semester: Fall 2025
// Lab 5 - Trip 
//name :omkar sharma

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>

/// Print basic program info
void ShowHeader()
{
        std::cout << " Lab 5 - Trip Planner\n";
    std::cout << "  Omkar sharma\n";
        std::cout << " COSC 1436 - Fall 2025\n";
    std::cout ;
}

/// Clear leftover input
void FlushInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// Simple error output
void PrintError(const std::string& msg)
{
    std::cout << "ERROR: " << msg << std::endl;
}

/// Yes/No confirmatin
bool AskYesNo(const std::string& msg)
{
    std::string answer;

    while (true)
    {
        std::cout << msg << " (Y/N): ";
        std::cin >> answer;
        FlushInput();

        if (_stricmp(answer.c_str(), "Y") == 0)
            return true;
        if (_stricmp(answer.c_str(), "N") == 0)
            return false;

        PrintError("Please enter Y or N");
    }
}

/// Stop structure
struct Stop
{
    int x;
    int y;
};

/// Read integer within a range
int GetIntRange(int min, int max)
{
    int value;

    while (true)
    {
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            FlushInput();
            PrintError("Invalid number");
            continue;
        }

        if (value < min || value > max)
        {
            FlushInput();
            PrintError("Number out of range");
            continue;
        }

        FlushInput();
        return value;
    }
}

/// Add stop pointer to array
bool AddStop(Stop* trip[], int size, Stop* stop)
{
    for (int i = 0; i < size; i++)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = stop;
            return true;
        }
    }
    return false;
}

/// Count stops
int CountStops(Stop* trip[], int size)
{
    int total = 0;
    for (int i = 0; i < size && trip[i]; i++)
        total++;
    return total;
}

/// Remove stop by index
bool DeleteStop(Stop* trip[], int size, int number)
{
    int index = number - 1;

    if (index < 0 || index >= size || trip[index] == nullptr)
        return false;

    delete trip[index];
    trip[index] = nullptr;

    for (int i = index; i < size - 1; i++)
    {
        trip[i] = trip[i + 1];
    }

    trip[size - 1] = nullptr;
    return true;
}

/// Distance formula
double CalcDistance(int x1, int y1, int x2, int y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

/// Add stop menu
void AddStopMenu(Stop* trip[], int size)
{
    std::cout << "Enter X (-100 to 100): ";
    int x = GetIntRange(-100, 100);

    std::cout << "Enter Y (-100 to 100): ";
    int y = GetIntRange(-100, 100);

    Stop* s = new Stop {x, y};

    if (!AddStop(trip, size, s))
    {
        PrintError("Trip is full");
        delete s;
    } else
    {
        std::cout << "Stop added successfully.\n\n";
    }
}

/// Remove stop menu
void RemoveStopMenu(Stop* trip[], int size)
{
    int total = CountStops(trip, size);

    if (total == 0)
    {
        PrintError("No stops available");
        return;
    }

    std::cout << "Enter stop number (1-" << total << "): ";
    int num = GetIntRange(1, total);

    if (AskYesNo("Remove selected stop?"))
    {
        if (DeleteStop(trip, size, num))
            std::cout << "Stop removed.\n\n";
        else
            PrintError("Stop not found");
    }
}

/// Clear entire trip
void ResetTrip(Stop* trip[], int size)
{
    for (int i = 0; i < size; i++)
    {
        delete trip[i];
        trip[i] = nullptr;
    }
}

/// Display trip details
void ShowTrip(Stop* trip[], int size, int speed)
{
    int total = CountStops(trip, size);

    if (total == 0)
    {
        std::cout << "No stops to show.\n\n";
        return;
    }

    std::cout << "Stop   Location      Distance      Time(min)\n";
    std::cout << "---------------------------------------------\n";

    int prevX = 0, prevY = 0;
    double totalDist = 0, totalTime = 0;

    for (int i = 0; i < total; i++)
    {
        Stop* s = trip[i];
        double dist = CalcDistance(prevX, prevY, s->x, s->y);
        double time = std::ceil((dist / speed) * 60);

        totalDist += dist;
        totalTime += time;

        std::cout << std::setw(3) << (i + 1)
            << std::setw(10) << "(" + std::to_string(s->x) + "," + std::to_string(s->y) + ")"
            << std::setw(12) << std::fixed << std::setprecision(2) << dist
            << std::setw(12) << time << "\n";

        prevX = s->x;
        prevY = s->y;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "Total stops: " << total << "\n\n";
}

/// Get speed
int AskSpeed()
{
    std::cout << "Enter speed (1-60 mph): ";
    int speed = GetIntRange(1, 60);
    std::cout << "Speed set.\n\n";
    return speed;
}

/// Main menu loop
void MainMenu(Stop* trip[], int size, int& speed)
{
    bool quit = false;

    while (!quit)
    {
        std::cout << "Trip Menu\n";
        std::cout << "---------\n";
        std::cout << "A) Add Stop\n";
        std::cout << "V) View Trip\n";
        std::cout << "R) Remove Stop\n";
        std::cout << "C) Clear Trip\n";
        std::cout << "S) Set Speed\n";
        std::cout << "Q) Quit\n\n";

        std::cout << "Choice: ";
        std::string input;
        std::getline(std::cin, input);

        if (input.empty())
        {
            PrintError("No input");
            continue;
        }

        char choice = std::toupper(input[0]);

        switch (choice)
        {
            case 'A': AddStopMenu(trip, size); break;
            case 'V': ShowTrip(trip, size, speed); break;
            case 'R': RemoveStopMenu(trip, size); break;
            case 'C':
                if (AskYesNo("Clear entire trip?"))
                {
                    ResetTrip(trip, size);
                    std::cout << "Trip cleared.\n\n";
                }
                break;
            case 'S': speed = AskSpeed(); break;
            case 'Q':
                if (AskYesNo("Exit program?"))
                    quit = true;
                break;
            default:
                PrintError("Invalid option");
        }
    }
}

int main()
{
    ShowHeader();

    const int MAX_STOPS = 100;
    Stop* trip[MAX_STOPS] = {nullptr};

    int speed = AskSpeed();
    MainMenu(trip, MAX_STOPS, speed);

    ResetTrip(trip, MAX_STOPS);
    return 0;
}