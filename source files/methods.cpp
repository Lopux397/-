#include "animal.h"
#include "vet.h"
#include "appeals.h"
#include "vetClinic.h"

Animal::Animal() = default;
Animal::Animal(const std::string& name, const std::string& view, const std::string& breed, unsigned int age, const std::string& owner)
{
    this->name = name;
    this->view = view;
    this->breed = breed;
    this->age = age;
    this->owner = owner;
}

void Animal::setName(const  std::string& name) { this->name = name; }
void Animal::setView(const std::string& view) { this->view = view; }
void Animal::setBreed(const std::string& breed) { this->breed = breed; }
void Animal::setAge(unsigned int age) { this->age = age; }
void Animal::setOwner(const std::string& owner) { this->owner = owner; }

std::string Animal::getName() const { return name; }
std::string Animal::getView() const { return view; }
std::string Animal::getBreed() const { return breed; }
unsigned int Animal::getAge() const{ return age; }
std::string Animal::getOwner() const{ return owner; }

void Animal::info() const
{
    std::cout << "Name: " << name << "\nView: " << view << "\nBreed: " << breed << "\nAge: " << age << "\nOwner: " << owner << std::endl;
}


Vet::Vet() = default;
Vet::Vet(const std::string& name, const std::string& speciality) 
{
    this->name = name;
    this->speciality = speciality;
}

void Vet::setName(const std::string& name) { this->name = name; }
void Vet::setSpeciality(const std::string& speciality) { this->speciality = speciality; }

std::string Vet::getName() const { return name; }
std::string Vet::getSpeciality() const { return speciality; }

void Vet::info() const
{
    std::cout << "Name: "<< name << "\nSpeciality: " << speciality << std::endl;
}


Appeals::Appeals() = default;
Appeals::Appeals(const Vet& vet, const Animal& animal, const std::string& date, const std::string& diagnosis, const std::string& treatment)
{
    this->vet = vet;
    this->animal = animal;
    this->date = date;
    this->diagnosis = diagnosis;
    this->treatment = treatment;
}

void Appeals::setVet(const Vet& vet) { this->vet = vet; }
void Appeals::setAnimal(const Animal& animal) { this->animal = animal; }
void Appeals::setDate(const std::string& date) { this->date = date; }
void Appeals::setDiagnosis(const std::string& diagnosis) { this->diagnosis = diagnosis; }
void Appeals::setTreatment(const std::string& treatment) { this->treatment = treatment; }

Vet Appeals::getVet() const { return vet; }
Animal Appeals::getAnimal() const { return animal; }
std::string Appeals::getDate() const { return date; }
std::string Appeals::getDiagnosis() const { return diagnosis; }
std::string Appeals::getTreatment() const { return treatment; }

void Appeals::info() const 
{
    std::cout << "Vet: " << vet.getName() << "(" << vet.getSpeciality() << ")" << std::endl;
    std::cout << "Animal: " << animal.getName() << "(" << animal.getView() << ")" << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
    std::cout << "Treatment: " << treatment << std::endl;
}


VetClinic::VetClinic() : animal(nullptr), animalSize(0), vet(nullptr), vetSize(0), appeals(nullptr), appealsSize(0) {}
VetClinic::~VetClinic() 
{
    delete[] animal;
    delete[] vet;
    delete[] appeals;
}

bool VetClinic::appointmentCheck(const std::string& vetSpeciality, const std::string& viewAnimal) 
{
    if (vetSpeciality == "Орнитолог" && viewAnimal != "Птица") return false;
    if (vetSpeciality == "Ратолог" && viewAnimal != "Грызун") return false;
    if (vetSpeciality == "Терапевт" && (viewAnimal == "Птица" || viewAnimal == "Грызун")) return false;

    return true;
}

void VetClinic::setAnimal(const Animal& animal)
{
    Animal* temp = new Animal[animalSize + 1];

    for (int i = 0; i < animalSize; i++) 
        temp[i] = this->animal[i];

    temp[animalSize++] = animal;

    delete[] this->animal;
    
    this->animal = temp;
}

void VetClinic::setVet(const Vet& vet)
{
   Vet* temp = new Vet[vetSize + 1];

    for (int i = 0; i < vetSize; i++)
        temp[i] = this->vet[i];

    temp[vetSize++] = vet;

    delete[] this->vet;

    this->vet = temp;
}

bool VetClinic::setAppeals(const std::string& vetSpeciality, const std::string& nameAnimal, const std::string& date, const std::string& diagnosis, const std::string& treatment)
{
    const Vet* addsDoc = nullptr;
    for (int i = 0; i < vetSize; i++)
    {
        if (vet[i].getSpeciality() == vetSpeciality)
        {
            addsDoc = &vet[i];
            break;
        }
    }
    if (!addsDoc)
    {
        std::cout<< "Vet not found" << std::endl;
        return false;
    }

    const Animal* addsAnimal = nullptr;
    for (int i = 0; i < animalSize; i++)
    {
        if (animal[i].getName() == nameAnimal) {
            addsAnimal = &animal[i];
            break;
        }
    }
    if (!addsAnimal) 
    {
        std::cout << "Animal not found" << std::endl;
        return false;
    }

    if (!appointmentCheck(vetSpeciality, addsAnimal->getView())) 
    {
        std::cout << "A "<< vetSpeciality << " cannot treat a" << addsAnimal->getView() << std::endl;
        return false;
    }

    Appeals* temp = new Appeals[appealsSize + 1];

    for (int i = 0; i < appealsSize; i++)
        temp[i] = appeals[i];

    temp[appealsSize++] = Appeals(*addsDoc, *addsAnimal, date, diagnosis, treatment);

    delete[] appeals;

    appeals = temp;

    return true;
}

void VetClinic::infoAnimal() const
{
    for (int i = 0; i < animalSize; i++) 
    {
        std::cout << "========= Animal[" << i + 1 << "] =========" << std::endl;
        animal[i].info();
        std::cout << "=============================\n" << std::endl;
    }
}

void VetClinic::infoVet() const 
{
    for (int i = 0; i < vetSize; i++)
    {
        std::cout << "========= Vet[" << i + 1 << "] =========" << std::endl;
        vet[i].info();
        std::cout << "==========================\n" << std::endl;
    }
}

void VetClinic::infoAppeals() const 
{
    for (int i = 0; i < appealsSize; i++)
    {
        std::cout << "========= Appeals[" << i + 1 << "] =========" << std::endl;
        appeals[i].info();
        std::cout << "==============================\n" << std::endl;
    }
}