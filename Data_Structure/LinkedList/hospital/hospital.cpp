#include "../linkedlist.hpp"
#include <iostream>
#include <string>

enum CRITICAL_LEVEL { LOW, MEDIUM, HIGH };

struct Patient
{
    std::string name;
    int         age;
    int         critical_level;

    Patient() {}
    Patient(const std::string & pname, int page, int pcl)
        : name(pname)
        , age(page)
        , critical_level(pcl)
    {
    }

    bool operator==(const Patient & p) { return name == p.name; }
};

Patient getPatient();

int main(void)
{
    int                 choice = 0;
    LinkedList<Patient> patient_list;

    while (true)
    {
        std::cout << "Please enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Patient push_patient = getPatient();
            if (push_patient.critical_level == CRITICAL_LEVEL::HIGH)
                patient_list.Insert(
                    push_patient,
                    [](const Patient &, const Patient &) { return true; });
            else
                patient_list.Append(push_patient);
            break;
        }
        case 2:
            patient_list.PopFront();
            break;
        case 3:
            std::cout << "Name\tAge\tCritical\n";
            patient_list.Traverse([](const Patient & p) {
                std::cout << p.name << '\t' << p.age << '\t' << p.critical_level
                          << '\n';
            });
            break;
        default:
            break;
        }
    }

    return 0;
}

Patient getPatient()
{
    std::string name;
    int         age, critical_level;

    std::cout << "Please input the name: ";
    std::cin >> name;
    std::cout << "Please input the age: ";
    std::cin >> age;
    std::cout << "Please input the critical level (from 0 to 2): ";
    std::cin >> critical_level;

    return Patient(name, age, critical_level % 3);
}
