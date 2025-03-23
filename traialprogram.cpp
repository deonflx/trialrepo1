#include <iostream>
#include <string>

// Base class
class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}
    virtual void display() {
        std::cout << "Name: " << name << "\nID: " << id << std::endl;
    }
};

// Derived class 1
class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int i, std::string dept) 
        : Employee(n, i), department(dept) {}
    void display() override {
        Employee::display();
        std::cout << "Department: " << department << std::endl;
    }
};

// Derived class 2
class Developer : public Employee {
private:
    std::string programmingLanguage;
public:
    Developer(std::string n, int i, std::string lang) 
        : Employee(n, i), programmingLanguage(lang) {}
    void display() override {
        Employee::display();
        std::cout << "Programming Language: " << programmingLanguage << std::endl;
    }
};

// Derived class 3
class Designer : public Employee {
private:
    std::string designTool;
public:
    Designer(std::string n, int i, std::string tool) 
        : Employee(n, i), designTool(tool) {}
    void display() override {
        Employee::display();
        std::cout << "Design Tool: " << designTool << std::endl;
    }
};

int main() {
    Manager mgr("John Doe", 101, "Engineering");
    Developer dev("Jane Smith", 102, "C++");
    Designer designer("Bob Wilson", 103, "Figma");

    std::cout << "Manager Details:\n";
    mgr.display();
    std::cout << "\nDeveloper Details:\n";
    dev.display();
    std::cout << "\nDesigner Details:\n";
    designer.display();

    return 0;
}