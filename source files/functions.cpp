#include "animal.h"
#include "vet.h"
#include "appeals.h"
#include "vetClinic.h"
#include "functions.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

void menu(VetClinic& clinic, bool& end)
{
    int option = -1;
    bool repeat;
    std::cout << "=============== Menu ================" << std::endl;
    std::cout << "1. Add a veterinarian" << std::endl;
    std::cout << "2. Add an animal" << std::endl;
    std::cout << "3. Schedule an appointment" << std::endl;
    std::cout << "4. Show all doctors" << std::endl;
    std::cout << "5. Show all animals" << std::endl;
    std::cout << "6. Show appointment history" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "=====================================" << std::endl;
    do
    {
        repeat = false;
        std::cout << "Select the item number: ";
        std::cin >> option;
        clearInput();
        std::cout << std::endl;
        switch (option) {
        case 1:
        {
            std::string fullName, speciality;

            std::cout << "Enter the veterinarian's full name: ";
            std::getline(std::cin, fullName);

            std::cout << "Enter specialization: "; //(Терапевт / Орнитолог / Ратолог)
            std::getline(std::cin, speciality);

            clinic.setVet(Vet(fullName, speciality));
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            std::string name, view, breed, owner;
            unsigned int age;

            std::cout << "Enter the animal's name: ";
            std::getline(std::cin, name);

            std::cout << "Enter the view: ";
            std::getline(std::cin, view);

            std::cout << "Enter the breed: ";
            std::getline(std::cin, breed);

            std::cout << "Enter age: ";
            std::cin >> age;
            clearInput();

            std::cout << "Enter the owner: ";
            std::getline(std::cin, owner);

            clinic.setAnimal(Animal(name, view, breed, age, owner));
            std::cout << std::endl;
            break;
        }
        case 3:
        {

            std::string vetSpeciality, nameAnimal, date, diagnosis, treatment;

            std::cout << "Enter the vet's specialization: ";
            std::getline(std::cin, vetSpeciality);

            std::cout << "Enter the animal's name: ";
            std::getline(std::cin, nameAnimal);

            std::cout << "Enter the date: ";
            std::getline(std::cin, date);

            std::cout << "Enter the diagnosis: ";
            std::getline(std::cin, diagnosis);

            std::cout << "Enter the prescribed treatment: ";
            std::getline(std::cin, treatment);

            clinic.setAppeals(vetSpeciality, nameAnimal, date, diagnosis, treatment);
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            clinic.infoVet();
            std::cout << std::endl;
            break;
        }
        case 5:
        {
            clinic.infoAnimal();
            std::cout << std::endl;
            break;
        }
        case 6:
        {
            clinic.infoAppeals();
            std::cout << std::endl;
            break;
        }
        case 0:
        {
            end = true;
            break;
        }
        default:
        {
            repeat = true;
            break;
        }
        }
    } while (repeat);
}