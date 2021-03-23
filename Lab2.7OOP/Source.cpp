// Source.cpp
// Конструктори та перевантаження операцій для класів з композицією – складніші завдання
// Михайлов Олександр
// Варіант 19*

#include <iostream>
#include "Date.h"
#include "Payment.h"

using namespace std;

int main()
{
	Date today;
	cout << " Enter todays date:" << endl;
	cin >> today;
	cout << endl;

	Payment P1;

	cin >> P1;
	cout << P1;

	cout << " Years of expirience: " << P1.CountExpirience(today) << endl;
	cout << " Amount of SumNarah: " << P1.AmountSumNarah() << " uah" << endl;
	cout << " Amount of SumUtrym: " << P1.AmountSumUtrym() << " uah" << endl;
	cout << " Amount of Zarplata: " << P1.AmountZarplata() << " uah" << endl;


	Date D1(2002, 3, 4), D2(2005, 5, 23);

	if (D1.IsEarlierThan(D2))
		cout << " TRUE" << endl << endl;
	else
		cout << " FALSE" << endl << endl;

	D1.SubstractDays();
	cout << D1 << endl;

	D1.DateAfterDays();
	cout << D1 << endl;

	cout << " Days between 2 dates: " << DaysBetweenAmount(D1, D2) << endl;
	

	return 0;
}