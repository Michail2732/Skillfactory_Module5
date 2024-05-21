#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace module_5
{
	class Snack
	{
		private:			
			long id;
			/// <summary>
			/// �������� �����
			/// </summary>
			string name;
			/// <summary>
			/// ���� �����
			/// </summary>
			float cost;
			/// <summary>
			/// ���������� �������� � �����
			/// </summary>
			float calories;
		public:
			Snack(string name, float cost, float calories);
			Snack(string name);

			const int GetId() const;
			const string& GetName() const;
			const float GetCost() const;
			const float GetCalories() const;
			void SetCost(float cost);
			void SetCalories(float calories);

			bool operator==(Snack& snack);
			bool operator!=(Snack& snack);

			friend ostream& operator<<(ostream& s, const Snack* snackPtr);
	};	
}

