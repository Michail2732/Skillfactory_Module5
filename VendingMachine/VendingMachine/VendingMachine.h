#pragma once

#include "SnackSlot.h"
#include <iostream>


namespace module_5
{
	class VendingMachine
	{
		private:
			uint32_t emptySlotsCount;
			uint32_t slotsCount;			
			SnackSlot** snackSlots;
		public:
			~VendingMachine();
			VendingMachine(uint32_t slotsCount);
			void AddSlot(SnackSlot* snackSlot);
			void RemoveSlot(SnackSlot* snackSlot);			
			uint32_t GetEmptySlotsCount() const;

			friend ostream& operator<<(ostream& s, VendingMachine* machine);
	};
}

