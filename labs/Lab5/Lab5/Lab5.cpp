
//omkar S
//  Final Version
 // Lab 5
// COSC 1436
// Fall 2025
 
#include <iostream>
#include <string>
#include <cmath>
#include <climits>

    struct Stop
{
    int x;
    int y;
};

const int MAX_STOPS = 100;
enum class ForegroundColor {
    Black, Red, Green, Yellow, Cyan,
    BrightRed, BrightGreen, BrightYellow, BrightCyan
};


void SetTextColor(ForegroundColor) {}
void ResetTextColor() {}

void DisplayError(const std::string& msg)
{
    std::cout << "ERROR: " << msg << std::endl;
}

void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

int ReadInt(int min, int max)
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (!std::cin.fail() && value >= min && value <= max)
        {
            ClearInput();
            return value;
        }
        DisplayError("Value is outside range");
        ClearInput();
    }
}

double Distance(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

int FindOpen(Stop* trip[])
{
    for (int i = 0; i < MAX_STOPS; i++)
        if (trip[i] == nullptr)
            return i;
    return -1;
}

int CountStops(Stop* trip[])
{
    int count = 0;
    for (int i = 0; i < MAX_STOPS; i++)
        if (trip[i])
            count++;
    return count;
}

void AddStop(Stop* trip[])
{
    int index = FindOpen(trip);
    if (index < 0)
    {
        DisplayError("Trip is full");
        return;
    }

    std::cout << "Enter X (-100 to 100): ";
    int x = ReadInt(-100, 100);
    std::cout << "Enter Y (-100 to 100): ";
    int y = ReadInt(-100, 100);

    trip[index] = new Stop {x, y};
    std::cout << "Stop added.\n";
}

void ViewTrip(Stop* trip[], int speed)
{
    if (CountStops(trip) == 0)
    {
        std::cout << "No stops.\n";
        return;
    }

    int px = 0, py = 0;
    double totalD = 0, totalT = 0;

    for (int i = 0; i < MAX_STOPS; i++)
    {
        if (!trip[i]) continue;

        double d = Distance(px, py, trip[i]->x, trip[i]->y);
        double mins = std::ceil((d / speed) * 60.0);

        totalD += d;
        totalT += mins;

        std::cout << (i + 1) << ") (" << trip[i]->x << ", "
            << trip[i]->y << ") dist=" << d
            << " time=" << mins << " mins\n";

        px = trip[i]->x;
        py = trip[i]->y;
    }

    std::cout << "Total distance: " << totalD << "\n";
    std::cout << "Total time: " << totalT << " mins\n";
}

void DeleteStop(Stop* trip[])
{
    std::cout << "Enter stop number: ";
    int num = ReadInt(1, MAX_STOPS);
    int index = num - 1;

    if (!trip[index])
    {
        std::cout << "Stop not found.\n";
        return;
    }

    delete trip[index];
    trip[index] = nullptr;
    std::cout << "Stop deleted.\n";
}

void ClearTrip(Stop* trip[])
{
    for (int i = 0; i < MAX_STOPS; i++)
    {
        delete trip[i];
        trip[i] = nullptr;
    }
}

int main()
{
    Stop* trip[MAX_STOPS] = {nullptr};

    std::cout << "Trip Planner\n--------------\n";
    std::cout << "Enter speed (1-60 mph): ";
    int speed = ReadInt(1, 60);

    bool done = false;
    do
    {
        std::cout << "\nTrip Planner\n--------------\n";
        std::cout << "A)dd Stop\n";
        std::cout << "V)iew Trip\n";
        std::cout << "D)elete Stop\n";
        std::cout << "C)lear Trip\n";
        std::cout << "Q)uit\n";

        char choice;
        std::cin >> choice;
        ClearInput();

        switch (choice)
        {
            case 'A':
            case 'a': AddStop(trip); break;

            case 'V':
            case 'v': ViewTrip(trip, speed); break;

            case 'D':
            case 'd': DeleteStop(trip); break;

            case 'C':
            case 'c': ClearTrip(trip); std::cout << "Trip cleared.\n"; break;

            case 'Q':
            case 'q': done = true; break;

            default: DisplayError("Invalid choice"); break;
        }
    } while (!done);

    ClearTrip(trip);
    return 0;
}
