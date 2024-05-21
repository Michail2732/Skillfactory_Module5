#include "Snack.h"

namespace module_5
{
    long snacksLastId = 0;

    Snack::Snack(string name, float cost, float calories)
    {        
        this->id = ++snacksLastId;
        this->name = name;
        this->cost = cost;
        this->calories = calories;
    }

    Snack::Snack(string name)
    {
        this->id = ++snacksLastId;
        this->name = name;
        this->cost = 0;
        this->calories = 0;
    }

    const int Snack::GetId() const
    {
        return 0;
    }

    const string& Snack::GetName() const
    {
        return name;
    }

    const float Snack::GetCost() const
    {
        return cost;
    }

    const float Snack::GetCalories() const
    {
        return calories;
    }

    void Snack::SetCost(float cost)
    {
        this->cost = cost;
    }

    void Snack::SetCalories(float calories)
    {
        this->calories = calories;
    }

    bool Snack::operator==(Snack& snack)
    {
        return id == snack.id;
    }

    bool Snack::operator!=(Snack& snack)
    {
        return id == snack.id;
    }

    ostream& operator<<(ostream& s, const Snack* snackPtr)
    {
        if (snackPtr != nullptr)
        {
            s << "id: " << snackPtr->id << ", имя: " << snackPtr->name << ", Цена: " << snackPtr->cost << ", калории: " << snackPtr->calories << endl;
        }        
        return s;
    }    
}
