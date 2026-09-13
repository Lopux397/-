#pragma once

#include "animal.h"
#include "vet.h"

#include <iostream>
#include <string>

class Appeals
{
private:
    Vet vet;
    Animal animal;
    std::string date;
    std::string diagnosis;
    std::string treatment;
public:
    Appeals();
    Appeals(const Vet& vet, const Animal& animal, const std::string& date, const std::string& diagnosis, const std::string& treatment);

    void setVet(const Vet& vet);
    void setAnimal(const Animal& animal);
    void setDate(const std::string& date);
    void setDiagnosis(const std::string& diagnosis);
    void setTreatment(const std::string& treatment);

    Vet getVet() const;
    Animal getAnimal() const;
    std::string getDate() const;
    std::string getDiagnosis() const;
    std::string getTreatment() const;

    void info() const;
};
