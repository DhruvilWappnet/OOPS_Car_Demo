#include <bits/stdc++.h>
using namespace std;

// Abstract class representing a Vehicle

class Engine
{
protected:
    string fuelType;
    double engineCapacity;
    double milage;
    float capacity = 1;

public:
    Engine(const string &fuelType, double engineCapacity, double milage)
    {
        this->fuelType = fuelType;
        this->engineCapacity = engineCapacity;
        this->milage = milage;
    }
    void displayEngineDetails() const
    {
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Engine Capacity: " << engineCapacity << " liters" << endl;
    }
};

class Tires
{
protected:
    int numTires;

public:
    Tires(int numTires) : numTires(numTires) {}

    // Display tires details
    void displayTiresDetails() const
    {
        cout << "Number of Tires: " << numTires << endl;
    }
};

class Vehicle : public Engine, public Tires
{
protected:
    string make, model, transmissionType;
    int year, peopleCapacity, maxSpeed;

public:
    Vehicle(const string &make, const string &model, int year, const string &fuelType, const string &transmissionType, int numTires, int peopleCapacity, int engineCapacity, int maxSpeed, double milage)
        : Engine(fuelType, engineCapacity, milage), Tires(numTires), make(make), model(model), year(year), transmissionType(transmissionType), peopleCapacity(peopleCapacity), maxSpeed(maxSpeed) {}

    // Abstract method for displaying vehicle details
    virtual void displayDetails() const
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        displayEngineDetails();
        displayTiresDetails();
        cout << "People Capacity: " << peopleCapacity << endl;
        cout << "Transmission Type: " << transmissionType << endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
    string getvehicalmodel()
    {
        return model;
    }
    string getvehicalmake()
    {
        return make;
    }
    int getProductionYear()
    {
        return year;
    }

    void driveVehicle(int distaceTraveled)
    {
        cout << this->getVehicleType() << " named " << this->make << " model" << this->model << " is ";
        cout << "moved " << distaceTraveled << " Kilometers." << endl;
        int maxdistance = engineCapacity * milage;
        int fuelbefore = capacity * maxdistance;
        int fuelafter = fuelbefore - distaceTraveled;
        // cout<<capacity<<" "<<maxdistance<<" "<<fuelbefore<<" "<<fuelafter<<endl;
        capacity = (fuelafter * capacity) / fuelbefore;
        if (capacity < 0)
        {
            cout << "No fuel is remaining."
                 << ".....Car is stopped!!!!" << endl;
        }
        else
            cout << "Fuel capacity " << capacity * 100 << " remaining " << endl;
    }

    // Abstract method for getting vehicle type
    virtual string getVehicleType() const = 0;

    virtual void startVehical() const = 0;

    // Virtual destructor for proper polymorphic behavior
    virtual ~Vehicle() {}
};

// Car class inheriting from Vehicle
class Car : public Vehicle
{
private:
    int numDoors;
    bool hasAirConditioning;
    bool hasNavigationSystem;

public:
    Car(const string &make, const string &model, int year, int numDoors, int numTires, int peopleCapacity, const string &fuelType, const string &transmissionType, double engineCapacity, double maxSpeed, bool hasAirConditioning, bool hasNavigationSystem, double milage)
        : Vehicle(make, model, year, fuelType, transmissionType, numTires, peopleCapacity, engineCapacity, maxSpeed, milage), numDoors(numDoors),
          hasAirConditioning(hasAirConditioning), hasNavigationSystem(hasNavigationSystem) {}

    // Overridden method to display car details
    void displayDetails() const override
    {
        cout << "Car Details:\n";
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Air Conditioning: " << (hasAirConditioning ? "Yes" : "No") << endl;
        cout << "Navigation System: " << (hasNavigationSystem ? "Yes" : "No") << endl;
    }

    // Overridden method to get car type
    string getVehicleType() const override
    {
        return "Car";
    }
    void startVehical() const override
    {
        cout << "Car named " << make << " " << model << " is starting." << endl;
    }
};

// Bus class inheriting from Vehicle
class Bus : public Vehicle
{
private:
    int numDoors;
    int seatingCapacity;
    bool isWheelchairAccessible;

public:
    Bus(const string &make, const string &model, int year, int numDoors, int numTires, int peopleCapacity, const string &fuelType, const string &transmissionType, double engineCapacity, double maxSpeed, int seatingCapacity, bool isWheelchairAccessible, double milage)
        : Vehicle(make, model, year, fuelType, transmissionType, numTires, peopleCapacity, engineCapacity, maxSpeed, milage), numDoors(numDoors), seatingCapacity(seatingCapacity),
          isWheelchairAccessible(isWheelchairAccessible) {}

    // Overridden method to display bus details
    void displayDetails() const override
    {
        cout << "Bus Details:\n";
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Wheelchair Accessible: " << (isWheelchairAccessible ? "Yes" : "No") << endl;
    }

    // Overridden method to get bus type
    string getVehicleType() const override
    {
        return "Bus";
    }

    void startVehical() const override
    {

        cout << "Bus named " << make << " " << model << " is starting." << endl;
    }
};

// Bike class inheriting from Vehicle
class Bike : public Vehicle
{
private:
    string bikeType;
    bool hasABS;
    bool hasTractionControl;

public:
    Bike(const string &make, const string &model, int year, int numTires, int peopleCapacity, const string &fuelType, const string &transmissionType, double engineCapacity, double maxSpeed, const string &bikeType, bool hasABS, bool hasTractionControl, double milage)
        : Vehicle(make, model, year, fuelType, transmissionType, numTires, peopleCapacity, engineCapacity, maxSpeed, milage),
          bikeType(bikeType), hasABS(hasABS), hasTractionControl(hasTractionControl) {}

    // Overridden method to display bike details
    void displayDetails() const override
    {
        cout << "Bike Details:\n";
        Vehicle::displayDetails();
        cout << "Bike Type: " << bikeType << endl;
        cout << "ABS: " << (hasABS ? "Yes" : "No") << endl;
        cout << "Traction Control: " << (hasTractionControl ? "Yes" : "No") << endl;
    }

    // Overridden method to get bike type
    string getVehicleType() const override
    {
        return "Bike";
    }

    void startVehical() const override
    {
        cout << "Bike named " << make << " " << model << " is starting." << endl;
    }
};

// Manager class to manage vehicle details
class VehicleManager
{
private:
    vector<Vehicle *> vehicles;
    vector<Vehicle *> bikes, cars, buses;

public:
    void addVehicle(Vehicle *currvehicle)
    {
        vehicles.push_back(currvehicle);
        // if(currvehicle->getVehicleType()=="Bus")buses.push_back(currvehicle);
        // else if(currvehicle->getVehicleType()=="Car")cars.push_back(currvehicle);
        // else if(currvehicle->getVehicleType()=="Bike")bikes.push_back(currvehicle);
    }

    void displayAllVehicles() const
    {
        for (const auto &vehicle : vehicles)
        {
            cout << "\n====================\n";
            vehicle->displayDetails();
        }
    }
    void deleteVehicle(string Make, string Model, int year)
    {
        // Iterate through the vehicles vector and find the matching vehicle
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
        {
            Vehicle *wanted = *it;
            if (wanted->getvehicalmodel() == Model && wanted->getvehicalmake() == Make && wanted->getProductionYear() == year)
            {
                // Vehicle found, delete it
                cout << "Deleting vehical --> " << wanted->getVehicleType() << " " << wanted->getvehicalmodel() << endl;
                delete wanted;
                vehicles.erase(it);
                return;
            }
        }

        // vehical not found
        cout << "Vehicle not found." << endl;
    }

    void rideVehicle(string Make, string Model, int year)
    {
        vector<Vehicle *>::iterator it = vehicles.begin();
        Vehicle *wanted = *it;
        for (it = vehicles.begin(); it != vehicles.end(); ++it)
        {
            if (wanted->getvehicalmodel() == Model && wanted->getvehicalmake() == Make && wanted->getProductionYear() == year)
            {
                int distanceTravelled;
                cout << "Enter how much kilometer you wanted to drive: ";
                cin >> distanceTravelled;
                wanted->driveVehicle(distanceTravelled);
                return;
            }
        }
        cout << "\n Vehicle not found......." << endl;
    }

    ~VehicleManager()
    {
        for (const auto &vehicle : vehicles)
        {
            string type = vehicle->getVehicleType();
            cout << "Deleting:" << type << endl;
            delete vehicle;
        }
    }
};

// /*
int main()
{
    VehicleManager manager;

    int choice;
    do
    {
        cout << "\n-------------------------------Menu:-------------------------------\n\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display Vehicles\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Drive Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string make, model;
        int year;
        switch (choice)
        {
        case 1:
        {
            cout << "\n------------------Add Vehicle:------------------\n";

            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n";
            cout << "2. Bus\n";
            cout << "3. Bike\n";
            cout << "Enter vehicle type (1-3): ";

            int vehicleType;
            cin >> vehicleType;
            if (vehicleType > 3)
            {
                cout << "Invalid choice.\n";
                break;
            }

            string fuelType, transmissionType;
            int numDoors, numTires, peopleCapacity;
            double engineCapacity, maxSpeed, milage;
            bool hasAirConditioning, hasNavigationSystem;

            // Common details for all vehicles
            cout << "Enter make of the vehicle: ";
            cin >> make;
            cout << "Enter model of the vehicle: ";
            cin >> model;
            cout << "Enter year of the vehicle: ";
            cin >> year;
            cout << "Enter number of tires: ";
            cin >> numTires;
            cout << "Enter people capacity: ";
            cin >> peopleCapacity;
            cout << "Enter fuel type: ";
            cin >> fuelType;
            cout << "Enter transmission type: ";
            cin >> transmissionType;
            cout << "Enter engine capacity: ";
            cin >> engineCapacity;
            cout << "Enter max speed: ";
            cin >> maxSpeed;
            cout << "Enter milage: ";
            cin >> milage;

            Vehicle *newVehicle = nullptr;

            if (vehicleType == 1)
            {
                // Add Car
                cout << "How many doors are there in the car? ";
                cin >> numDoors;
                cout << "Does it have air conditioning? (1 for Yes, 0 for No): ";
                cin >> hasAirConditioning;
                cout << "Does it have a navigation system? (1 for Yes, 0 for No): ";
                cin >> hasNavigationSystem;

                newVehicle = new Car(make, model, year, numDoors, numTires, peopleCapacity,
                                     fuelType, transmissionType, engineCapacity, maxSpeed,
                                     hasAirConditioning, hasNavigationSystem, milage);
            }
            else if (vehicleType == 2)
            {
                // Add Bus
                int seatingCapacity;
                bool isWheelchairAccessible;
                cout << "How many doors are there in the car? ";
                cin >> numDoors;
                cout << "Enter seating capacity: ";
                cin >> seatingCapacity;
                cout << "Is it wheelchair accessible? (1 for Yes, 0 for No): ";
                cin >> isWheelchairAccessible;

                newVehicle = new Bus(make, model, year, numDoors, numTires, peopleCapacity,
                                     fuelType, transmissionType, engineCapacity, maxSpeed,
                                     seatingCapacity, isWheelchairAccessible, milage);
            }
            else if (vehicleType == 3)
            {
                // Add Bike
                string bikeType;
                bool hasABS, hasTractionControl;
                cout << "Enter bike type: ";
                cin >> bikeType;
                cout << "Does it have ABS? (1 for Yes, 0 for No): ";
                cin >> hasABS;
                cout << "Does it have traction control? (1 for Yes, 0 for No): ";
                cin >> hasTractionControl;

                newVehicle = new Bike(make, model, year, numTires, peopleCapacity,
                                      fuelType, transmissionType, engineCapacity, maxSpeed,
                                      bikeType, hasABS, hasTractionControl, milage);
            }

            if (newVehicle)
            {
                manager.addVehicle(newVehicle);
                cout << "Vehicle added successfully!\n";
            }
            break;
        }
        case 2:
            cout << "\n------------------Displaying Vehicles:------------------\n";
            manager.displayAllVehicles();
            break;
        case 3:
        {
            cout << "\n------------------Remove Vehicle:------------------\n";
            cout << "Enter make of the vehicle to remove: ";
            cin >> make;
            cout << "Enter model of the vehicle to remove: ";
            cin >> model;
            cout << "Enter year of the vehical to remove: ";
            cin >> year;

            manager.deleteVehicle(make, model, year);

            break;
        }
        case 4:
            cout << "\n------------------Drive Vehicle:------------------\n";
            cout << "Enter make of the vehicle to drive: ";
            cin >> make;
            cout << "Enter model of the vehicle to drive: ";
            cin >> model;
            cout << "Enter year of the vehical to drive: ";
            cin >> year;
            manager.rideVehicle(make, model, year);

            break;
        case 5:
            cout << "Exiting...\n";
            cout << "Deleting all vehicals....\n";
            manager.displayAllVehicles();
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 5);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

// */

/*
int main()
{
    VehicleManager manager;

    // Adding a car
    Car *car = new Car("Toyota", "Camry", 2024, 4, 4, 5, "Gasoline", "Automatic", 100, 100, true, true,25);
    manager.addVehicle(car);

    // // Adding a bus
    Bus *bus = new Bus("Mercedes", "Sprinter", 2023, 2, 6, 20, "Diesel", "Automatic", 3.0, 120, 30, true,15);
    manager.addVehicle(bus);

    // // Adding a bike
    Bike *bike = new Bike("Honda", "CBR500R", 2024, 2, 2, "Gasoline","Manual", 0.471, 190, "Sport", true, true,50);
    manager.addVehicle(bike);
    // string type = bike->getVehicleType();
    // cout << type << endl;
    // bike->startVehical();

    // Displaying all vehicles
    // cout<<"---------------------------------------------display started"<<endl;
    // cout<<"\n"<<endl;
    // manager.displayAllVehicles();
    // cout<<"\n"<<endl;
    // cout<<"---------------------------------------------display completed"<<endl;

    // manager.deleteVehicle("Toyota", "Camry", 2024);
    car->driveVehicle(100);
    cout<<"Driving................."<<endl;
    manager.rideVehicle("Toyota", "Camry", 2024);

    // cout<<"---------------------------------------------display started"<<endl;
    // cout<<"\n"<<endl;
    // manager.displayAllVehicles();
    // cout<<"\n"<<endl;
    // cout<<"---------------------------------------------display completed"<<endl;

    return 0;
}
*/

// some line is deleted

// extra line that is added
// new line
// new line
// new line
