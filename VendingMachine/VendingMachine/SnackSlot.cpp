#include "SnackSlot.h"

namespace module_5
{
	long snackSlotLastId = 0;

	SnackSlot::~SnackSlot()
	{
		cout << "Диструктор SnackSlot" << endl;
		delete[] snacks;		
	}

	SnackSlot::SnackSlot(uint32_t positionsCount)
	{
		this->positionsCount = positionsCount;
		this->snacks = new Snack * [positionsCount] {nullptr};		
		this->emptyPositionsCount = positionsCount;
		this->snacksCount = 0;
		this->id = ++snackSlotLastId;
	}

	void SnackSlot::AddSnack(Snack* snack)
	{
		if (emptyPositionsCount <= 0)
			throw "Нет места в слоте";
		int index = positionsCount - emptyPositionsCount;
		snacks[index] = snack;
		emptyPositionsCount--;
		snacksCount++;

	}

	void SnackSlot::RemoveSnack(Snack* snack)
	{
		int occupiedPositionsCount = positionsCount - emptyPositionsCount;
		bool isRemove = false;
		for (int i = 0; i < occupiedPositionsCount; i++)
		{
			if (snacks[i] == snack)
			{
				snacks[i] = nullptr;
				isRemove = true;
				break;
			}				
		}
		if (isRemove)
		{
			// сдвигаем ссылки снеков в массиве
			for (int i = 1; i < occupiedPositionsCount; i++)
			{
				if (snacks[i - 1] == nullptr)
				{
					snacks[i - 1] = snacks[i];
					snacks[i] = nullptr;
				}
			}
			emptyPositionsCount++;
			snacksCount--;
		}
	}

	const long SnackSlot::GetId() const
	{
		return id;
	}

	const uint32_t SnackSlot::GetPositionsCount() const
	{
		return positionsCount;
	}

	const uint32_t SnackSlot::GetEmptyPositionsCount() const
	{
		return emptyPositionsCount;
	}

	const uint32_t SnackSlot::GetSnackCount() const
	{
		return snacksCount;
	}
	bool SnackSlot::operator==(SnackSlot& snackSlot)
	{
		return id == snackSlot.id;
	}

	bool SnackSlot::operator!=(SnackSlot& snackSlot)
	{
		return id != snackSlot.id;
	}


	Snack* SnackSlot::GetSnackById(long id)
	{
		int occupiedPositionsCount = positionsCount - emptyPositionsCount;		
		for (int i = 0; i < occupiedPositionsCount; i++)
		{
			if (snacks[i]->GetId() == id)
			{
				return snacks[i];
			}
		}
		return nullptr;
	}

	ostream& operator<<(ostream& s, const SnackSlot* snackSlotPtr)
	{		
		if (snackSlotPtr != nullptr)
		{			
			s << "Слот " << snackSlotPtr->id << endl;
			int occupiedPositionsCount = snackSlotPtr->positionsCount - snackSlotPtr->emptyPositionsCount;
			for (int i = 0; i < occupiedPositionsCount; i++)
			{
				cout << snackSlotPtr->snacks[i] << endl;
			}
		}		
		return s;
	}
}
