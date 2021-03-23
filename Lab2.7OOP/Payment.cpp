// Payment.cpp

#include "Payment.h"

void Payment::SetStavka(double v) {
	if (v < 2000)
		v = 2000;
	this->stavka = v;
}

void Payment::SetNadbavkaProc(short v) {
	if (v > 100 || v < 0) {
		v = 0;
	}
	this->nadbavkaProc = v;
}

void Payment::SetAmountRob(short v) {
	if (v < 1 || v > data.DaysInMonth(data.GetMonth())) {
		v = 14;
	}
	this->amountRob = v;
}

void Payment::SetAmountVidprac(short v) {
	if (v < 1 || v > data.DaysInMonth(data.GetMonth())) {
		v = 1;
	}
	this->amountVidprac = v;
}

void Payment::SetSumNarah(double v) {
	if (v < 2000)
		v = 2000;
	this->SumNarah = v;
}

void Payment::SetSumUtrym(double v) {
	if (v < 100)
		v = 100;
	this->SumUtrym = v;
}

short Payment::CountExpirience(Date D2) {
	short answer = 0;
	if (D2.IsEarlierThan(data)) {
		cout << " ERROR" << endl;
		exit(0);
	}
	else if (data.IsEarlierThan(D2)) {
		unsigned int days = DaysBetweenAmount(data, D2);
		answer = days / 365;
	}
	else if (data.IsSameAs(D2)) {
		return 0;
	}
	return answer;
}

void Payment::Init(string n, string s, double stavka, Date D1, short nadbavkaproc, short amountRob, short amountVidprac) {
	SetName(n);
	SetSurname(s);
	SetStavka(stavka);
	SetDate(D1);
	SetNadbavkaProc(nadbavkaproc);
	SetAmountRob(amountRob);
	SetAmountVidprac(amountVidprac);
}

Payment::Payment()
	:name("a"), surname("a"), stavka(2000), data(2021, 3, 23), nadbavkaProc(0), amountRob(15), amountVidprac(15)
{}

Payment::Payment(string n)
	: name(n), surname("a"), stavka(2000), data(2021, 3, 23), nadbavkaProc(0), amountRob(15), amountVidprac(15)
{}

Payment::Payment(string n, string s)
	: name(n), surname(s), stavka(2000), data(2021, 3, 23), nadbavkaProc(0), amountRob(15), amountVidprac(15)
{}

Payment::Payment(string n, string s, double stvk) 
	: name(n), surname(s), data(2021, 3, 23), nadbavkaProc(0), amountRob(15), amountVidprac(15)
{
	SetStavka(stvk);
}

Payment::Payment(string n, string s, double stvk, unsigned int y, unsigned int m, unsigned int d) 
	: name(n), surname(s), nadbavkaProc(0), amountRob(15), amountVidprac(15)
{
	SetStavka(stvk);
	Date D;
	D.SetYear(y);
	D.SetMonth(m);
	D.SetDay(d);
	SetDate(D);
}

Payment::Payment(string n, string s, double stvk, unsigned int y, unsigned int m, unsigned int d, short nadbavkaprc)
	: name(n), surname(s), amountRob(15), amountVidprac(15)
{
	SetStavka(stvk);
	Date D;
	D.SetYear(y);
	D.SetMonth(m);
	D.SetDay(d);
	SetDate(D);
	SetNadbavkaProc(nadbavkaprc);
}

Payment::Payment(string n, string s, double stvk, unsigned int y, unsigned int m, unsigned int d, short nadbavkaprc, short amountRob)
	: name(n), surname(s), amountVidprac(15)
{
	SetStavka(stvk);
	Date D;
	D.SetYear(y);
	D.SetMonth(m);
	D.SetDay(d);
	SetDate(D);
	SetNadbavkaProc(nadbavkaprc);
	SetAmountRob(amountRob);
}

Payment::Payment(string n, string s, double stvk, unsigned int y, unsigned int m, unsigned int d, short nadbavkaprc, short amountRob, short amountVidprac)
	: name(n), surname(s)
{
	SetStavka(stvk);
	Date D;
	D.SetYear(y);
	D.SetMonth(m);
	D.SetDay(d);
	SetDate(D);
	SetNadbavkaProc(nadbavkaprc);
	SetAmountRob(amountRob);
	SetAmountVidprac(amountVidprac);
}

Payment::Payment(const Payment& P)
{
	*this = P;
}

Payment& Payment::operator = (const Payment& P)
{
	name = P.name;
	surname = P.surname;
	stavka = P.stavka;
	data = P.data;
	nadbavkaProc = P.nadbavkaProc;
	amountRob = P.amountRob;
	amountVidprac = P.amountVidprac;
	return *this;
}

Payment::operator string() const {
	stringstream sout;
	sout << endl << " Name: " << name << " " << surname << endl
		<< " Month stavka: " << stavka << " uah." << endl
		<< " Date of hiring: " << data.GetDay() << "." << data.GetMonth() << "." << data.GetYear() << endl
		<< " Number of working days in the month: " << amountRob << endl
		<< " Number of worked days in the month: " << amountVidprac << endl
		<< " Nadbavka percent: " << nadbavkaProc << " %" << endl;
	return sout.str();
}

Payment& Payment::operator ++() {
	++data;
	return *this;
}

Payment& Payment::operator --() {
	--data;
	return *this;
}

Payment Payment::operator ++(int) {
	Payment P = *this;
	this->data++;
	return P;
}

Payment Payment::operator --(int)
{
	Payment P = *this;
	this->data--;
		return P;
}

ostream& operator <<(ostream& out, const Payment& P) {
	out << string(P);
	return out;
}

istream& operator >>(istream& in, Payment& P) {
	string n, s;
	cout << " Enter name: "; in >> n;
	cout << " Enter surname: "; in >> s;
	P.SetName(n);
	P.SetSurname(s);

	unsigned int stavka;
	do {
		cout << " Enter stavka: "; in >> stavka;
	} while (stavka < 2000);
	P.SetStavka(stavka);

	Date D1;
	cout << " Enter date of hiring:" << endl; in >> D1;
	P.SetDate(D1);

	short nadbavka;
	do {
		cout << " Enter nadbavka: "; in >> nadbavka;
	} while (nadbavka > 100 || nadbavka < 0);
	P.SetNadbavkaProc(nadbavka);

	short amountRob;
	do {
		cout << " Enter number of working days: "; in >> amountRob;
	} while (amountRob < 1 || amountRob > D1.DaysInMonth(D1.GetMonth()));
	P.SetAmountRob(amountRob);

	short amountVidprac;
	do {
		cout << " Enter number of worked days: "; in >> amountVidprac;
	} while (amountVidprac < 1 || amountVidprac > D1.DaysInMonth(D1.GetMonth()));
	P.SetAmountVidprac(amountVidprac);

	return in;
}

double Payment::AmountSumNarah() {
	return stavka / amountRob * amountVidprac + stavka * (nadbavkaProc / 100);
}

double Payment::PrybotkovyiPodatok() {
	return AmountSumNarah() * 0.13;
}

double Payment::AmountSumUtrym() {
	return AmountSumNarah() * 0.01 + PrybotkovyiPodatok();
}

double Payment::AmountZarplata() {
	return AmountSumNarah() - AmountSumUtrym();
}
