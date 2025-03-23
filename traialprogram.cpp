#include <iostream>
#include <string>

class Engine {
protected:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    virtual void showSpecs() {
        std::cout << "Horsepower: " << horsepower << std::endl;
    }
};

class Vehicle {
protected:
    std::string brand;
public:
    Vehicle(std::string b) : brand(b) {}
    virtual void showDetails() {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Multiple inheritance
class Car : public Vehicle, public Engine {
public:
    Car(std::string b, int hp) : Vehicle(b), Engine(hp) {}
    void display() {
        showDetails();
        showSpecs();
    }
};

int main() {
    Car car("Toyota", 200);
    car.display();
    return 0;
}