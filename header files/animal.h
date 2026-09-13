#pragma once

#include <iostream>
#include <string>

class Animal
{
private:
    std::string name;
    std::string view;
    std::string breed;
    unsigned int age;
    std::string owner;
public:
    Animal();
    Animal(const std::string& name, const std::string& view, const std::string& breed, unsigned int age, const std::string& owner);
    
    void setName(const std::string& name);
    void setView(const std::string& view);
    void setBreed(const std::string& breed);
    void setAge(const unsigned int age);
    void setOwner(const std::string& owner);

    std::string getName() const;
    std::string getView() const;
    std::string getBreed() const;
    unsigned int getAge() const;
    std::string getOwner() const;

    void info() const;
};
