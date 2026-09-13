#pragma once

#include <iostream>
#include <string>


class Vet
{
private:
    std::string name;
    std::string speciality;
public:
    Vet();
    Vet(const std::string& name, const std::string& speciality);

    void setName(const std::string& name);
    void setSpeciality(const std::string& speciality);

    std::string getName() const;
    std::string getSpeciality() const;

    void info() const;
};

