#include "VendingMachine.h"


namespace module_5
{
	VendingMachine::~VendingMachine()
	{
		cout << "���������� VendingMachine" << endl;
		delete[] snackSlots;
	}

	VendingMachine::VendingMachine(uint32_t slotsCount)
	{
		this->slotsCount = slotsCount;
		emptySlotsCount = slotsCount;
		snackSlots = new SnackSlot * [slotsCount] {nullptr};
	}

	void VendingMachine::AddSlot(SnackSlot* snackSlot)
	{
		if (emptySlotsCount <= 0)
			throw "��� ����� � ��������";
		int index = slotsCount - emptySlotsCount;
		snackSlots[index] = snackSlot;
		emptySlotsCount--;
	}

	void VendingMachine::RemoveSlot(SnackSlot* snackSlot)
	{
		int occupiedSlotsCount = slotsCount - emptySlotsCount;
		bool isRemove = false;
		for (int i = 0; i < occupiedSlotsCount; i++)
		{
			if (snackSlots[i] == snackSlot)
			{
				snackSlots[i] = nullptr;
				isRemove = true;
				break;
			}
		}
		if (isRemove)
		{
			// �������� ������ ������ � �������
			for (int i = 1; i < occupiedSlotsCount; i++)
			{
				if (snackSlots[i - 1] == nullptr)
				{
					snackSlots[i - 1] = snackSlots[i];
					snackSlots[i] = nullptr;
				}
			}
			emptySlotsCount++;
		}
	}

	uint32_t VendingMachine::GetEmptySlotsCount() const
	{
		return emptySlotsCount;
	}

	
	ostream& operator<<(ostream& s, VendingMachine* machinePtr)
	{
		if (machinePtr != nullptr)
		{
			s << "����������� ������" << endl;
			int occupiedPositionsCount = machinePtr->slotsCount - machinePtr->emptySlotsCount;
			for (int i = 0; i < occupiedPositionsCount; i++)
			{
				cout << machinePtr->snackSlots[i] << endl;
			}
		}		
		return s;
	}
}

