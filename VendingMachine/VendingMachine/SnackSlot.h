#pragma once
#include <iostream>
#include "Snack.h"

namespace module_5 
{
	class SnackSlot
	{
		private:			
			long id;
			/// <summary>
			/// ������ ������
			/// </summary>
			Snack** snacks;
			/// <summary>
			/// ���������� ������� � �����
			/// </summary>
			uint32_t positionsCount;
			/// <summary>
			/// ���������� ��������� ������� � �����
			/// </summary>
			uint32_t emptyPositionsCount;
			/// <summary>
			/// ���������� ������ � �����
			/// </summary>
			uint32_t snacksCount;
		public:
			~SnackSlot();
			SnackSlot(uint32_t positionCount);
			void AddSnack(Snack* snack);
			void RemoveSnack(Snack* snack);			
			Snack* GetSnackById(long id);

			const long GetId() const;
			const uint32_t GetPositionsCount() const;
			const uint32_t GetEmptyPositionsCount() const;
			const uint32_t GetSnackCount() const;

			bool operator==(SnackSlot& snackSlot);
			bool operator!=(SnackSlot& snackSlot);

			friend ostream& operator<<(ostream& s, const SnackSlot* snackSlotPtr);
	};	
}

