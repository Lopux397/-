#pragma once

#include "animal.h"
#include "vet.h"
#include "appeals.h"

#include <iostream>
#include <string>

class VetClinic
{
private:
    Animal* animal;
    int animalSize;

    Vet* vet;
    int vetSize;

    Appeals* appeals;
    int appealsSize;
public:
    VetClinic();
    ~VetClinic();

    VetClinic(const VetClinic&) = delete;
    VetClinic& operator=(const VetClinic&) = delete;

    void setAnimal(const Animal& animal);
    void setVet(const Vet& vet);
    bool setAppeals(const std::string& vetSpeciality, const std::string& nameAnimal, const std::string& date, const std::string& diagnosis, const std::string& treatment);

    bool appointmentCheck(const std::string& vetSpeciality, const std::string& viewAnimal);

    void infoAnimal() const;
    void infoVet() const;
    void infoAppeals() const;
};
