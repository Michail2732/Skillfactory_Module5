// VendingMachine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Snack.h"
#include "SnackSlot.h"
#include "VendingMachine.h"

using namespace module_5;

int main()
{
    setlocale(0, "");
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10);
    slot->AddSnack(bounty); 
    slot->AddSnack(snickers);
    VendingMachine* machine = new VendingMachine(10);
    machine->AddSlot(slot); 

    cout << machine->GetEmptySlotsCount()<< endl;  
    cout << machine;
    delete machine;
    delete slot;
    delete snickers;
    delete bounty;
}
