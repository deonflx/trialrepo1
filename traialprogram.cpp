#include <iostream>
#include <string>


// Base class
class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(std::string b, int y) : brand(b), year(y) {}
    virtual void display() {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

// First level inheritance
class LandVehicle : public Vehicle {
protected:
    int wheels;

public:
    LandVehicle(std::string b, int y, int w) : Vehicle(b, y), wheels(w) {}
    void display() override {
        Vehicle::display();
        std::cout << "Wheels: " << wheels << std::endl;
    }
};

class WaterVehicle : public Vehicle {
protected:
    double length;

public:
    WaterVehicle(std::string b, int y, double l) : Vehicle(b, y), length(l) {}
    void display() override {
        Vehicle::display();
        std::cout << "Length: " << length << " meters" << std::endl;
    }
};

// Second level inheritance
class Car : public LandVehicle {
private:
    std::string type;

public:
    Car(std::string b, int y, std::string t) : LandVehicle(b, y, 4), type(t) {}
    void display() override {
        LandVehicle::display();
        std::cout << "Type: " << type << std::endl;
    }
};

class Motorcycle : public LandVehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(std::string b, int y, bool sidecar) : LandVehicle(b, y, 2), hasSidecar(sidecar) {}
    void display() override {
        LandVehicle::display();
        std::cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    Car car("Toyota", 2024, "Sedan");
    Motorcycle bike("Harley-Davidson", 2023, true);
    WaterVehicle boat("Yamaha", 2024, 25.5);

    std::cout << "Car Details:" << std::endl;
    car.display();
    std::cout << "\nMotorcycle Details:" << std::endl;
    bike.display();
    std::cout << "\nBoat Details:" << std::endl;
    boat.display();

    return 0;
}