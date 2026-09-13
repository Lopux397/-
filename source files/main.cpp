#include "animal.h"
#include "vet.h"
#include "appeals.h"
#include "vetClinic.h"
#include "functions.h"

#include <windows.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    bool end = false;
    VetClinic clinic;
    
    clinic.setVet(Vet("Иванов Иван", "Терапевт"));
    clinic.setVet(Vet("Петрова Анна", "Орнитолог"));
    clinic.setVet(Vet("Сидоров Алексей", "Ратолог"));

    clinic.setAnimal(Animal("Рекс", "Собака", "Овчарка", 5, "Мария"));
    clinic.setAnimal(Animal("Барсик", "Кошка", "Британская", 3, "Алексей"));
    clinic.setAnimal(Animal("Кеша", "Птица", "Волнистый попугай", 2, "Елена"));
    clinic.setAnimal(Animal("Хома", "Грызун", "Джунгарский хомяк", 1, "Дмитрий"));

    clinic.setAppeals("Терапевт", "Рекс", "13.09.2026", "Плановый осмотр", "Курс витаминов");
    clinic.setAppeals("Терапевт", "Барсик", "14.09.2026", "Вакцинация", "Наблюдение 2 дня");
    clinic.setAppeals("Орнитолог", "Кеша", "14.09.2026", "Проблемы с оперением", "Кормовая добавка B12");
    clinic.setAppeals("Ратолог", "Хома", "15.09.2026", "Вывих лапы", "Наложение фиксирующей повязки");

    while(!end) menu(clinic, end);       
    return 0;
}