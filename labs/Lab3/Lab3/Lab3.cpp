//name : Omkar S 
//Lab 3 
//COSC 1436 Fall 2025  

#include <iostream>
#include <iomanip>
#include <string>

int main() { // introduction 

    std::cout << "Lab 3 - Falling Distance" << std::endl; std::cout << "Omkar S" << std::endl; std::cout << "COSC 1436" << std::endl << std::endl;

   // constants and variables   
      const double g = 9.8;           // I used gravity in m/s^2   
       const double metersToFeet = 3.28084; // used for conversion from meters to feet   
      const double maxVelocity = 90.0;      // limit the velocity to 90 m/s   
     int seconds;
    char unitChoice;

    // ask user for falling time   // so i did  same as assigment 6
    std::cout << "Enter falling time (1 - 60 seconds): ";
     std::cin >> seconds;
       std::cout << std::endl;
    // validate seconds input   
    while (seconds < 1 || seconds > 60)
    {
        std::cout << "ERROR: Time must be between 1 and 60 seconds." << std::endl;
        std::cout << "Enter falling time (1 - 60 seconds): "; std::cin >> seconds;
        std::cout << std::endl;
      std::cout << "Do you want the results in meters or feet? (m/f): ";
       std::cin >> unitChoice; std::cout << std::endl;

      // unit input 
       while (unitChoice != 'm' && unitChoice != 'M' && unitChoice != 'f' && unitChoice != 'F') // this one same as the assigment 4 im using while loop to validate input 
       {
        std::cout << "ERROR: Please enter 'm' for meters or 'f' for feet." << std::endl;
         std::cout << "Do you want the results in meters or feet? (m/f): ";  std::cin >> unitChoice;
        std::cout << std::endl;
       }
          bool useFeet = (unitChoice == 'f' || unitChoice == 'F');
      std::string distUnit = useFeet ? "ft" : "m";
        std::string velUnit = useFeet ? "ft/s" : "m/s";

       // im using  const char to avoid and im using std just in case annswer is asked from different compiler
      std::string distanceHeader = std::string("Distance (") + distUnit + ")";
       std::string velocityHeader = std::string("Velocity (") + velUnit + ")";

      // table header   
       std::cout << std::fixed << std::setprecision(2);
          std::cout << std::setw(8) << "Seconds"   << std::setw(15) << distanceHeader<< std::setw(15) << velocityHeader  << std::endl;
           std::cout << "============================"  << std::endl;

      // I used the same kind of loop idea like Lab 2, just changed it to show distance each second   
     double totalDistance = 0.0;  for (int t = 1; t <= seconds; ++t)
     {
        // calculate distance and velocity   
        double distanceMeters = 0.5 * g * t * t;
        double velocityMps = g * t;
      if (velocityMps > maxVelocity)
            velocityMps = maxVelocity;

        //im  convert if user chose feet   
        double distanceOut = useFeet ? distanceMeters * metersToFeet : distanceMeters; double velocityOut = useFeet ? velocityMps * metersToFeet : velocityMps;

        // i used that to the row   
        std::cout << std::setw(8) << t << std::setw(15) << distanceOut  << std::setw(15) << velocityOut
            << std::endl;

        // keep track of total distance in meters   
        totalDistance += distanceMeters; std::cout << std::endl;
     
     }
     // show total distance based on chosen unit   
       std::cout << "Total distance covered: ";
     if (useFeet)
        std::cout << totalDistance * metersToFeet << " ft" << std::endl;
     
     else
        std::cout << totalDistance << " m" << std::endl;
       std::cout << "Program completed successfully." << std::endl;

      return 0;
    }

