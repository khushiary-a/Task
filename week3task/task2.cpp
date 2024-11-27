// Simulate an Instrument Cluster Data Display
// Objective: Create a simplified data display system to simulate speed, fuel level, and engine temperature.
// Requirements:
// Implement a class-based design:
// Create a VehicleData class to store parameters like speed, fuel level, and engine temperature.
// Create a Display class to show these parameters on the console.
// Simulate real-time updates:
// Use a random number generator to update speed, fuel level, and temperature every second.
// Display the updated data in a formatted manner (e.g., speed: 80 km/h, fuel: 50%, temperature: 90°C).
// Add constraints:
// Display warnings when parameters exceed thresholds (e.g., temperature > 100°C or fuel < 10%).
#include <iostream>
#include <cstdlib>
#include <random>
#include <thread>
#include <functional>
using namespace std;
class vehicledata
{
public:
    int speed;
    int fuel_level;
    int engine_temp;
};
class Display : public vehicledata
{
public:
    void setvalues()
    {
        srand(time(0));
        speed = rand() % 121;
        fuel_level = rand() % 101;
        engine_temp = rand() % 101 + 20;
    }
    
    void showdata()
    {

        cout << "Speed: " << speed << " km/h " << endl;
        if (fuel_level <= 10)
        {
            cout << "Fuel Level is Less .... " << endl;
        }
        else
        {
            cout << "Fuel: " << fuel_level << "% " << endl;
        }
        if (engine_temp >= 100)
        {
            cout << "Temperature is about to cross limit..." << endl;
        }
        else
        {
            cout << "Temperature: " << engine_temp << "\xB0" <<"C" << endl;
        }
    }
};

int main()
{
    Display obj1;

    int i = 0;

    while (i < 10)
    {
        obj1.setvalues();
        thread t1([&obj1]()
                  { obj1.showdata(); });
        t1.join();
        this_thread::sleep_for(chrono::seconds(3));
        cout<<" ============= "<<endl;
        i++;
    }

    return 0;
}