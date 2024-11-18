#pragma once
#include <string>
#include "cmath"

#include <sstream>
using namespace std;
class Angle {
	int *degree, *minutes;

public:
	Angle();
	Angle(int degree, int minutes);
	Angle(const Angle& a);
	~Angle();
	double toRadians();
	Angle toRange();//����� ����
	Angle operator+(const Angle& obj);
	Angle operator-(const Angle& obj);
	//���� +- ����
	double sinus();
	const int compare(const Angle& angle2);
	friend ostream& operator<<(ostream& os, Angle const& m);
	Angle& operator=(const Angle& a);
};