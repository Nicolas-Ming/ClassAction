#include <iostream>

using namespace std;

class vehicle {
protected:
	int m_year;
	int m_miles;
	string m_model;
public:
	vehicle(int year, int miles, string model) :
		m_year(year),
		m_miles(miles),
		m_model(model) 
	{

	}
	virtual void Drive() {
		int travel = 0;
		cout << "How far do you want to travel? ";
		cin >> travel;
		m_miles += travel;
		cout << endl << "You traveled " << m_miles << "so far!" << endl;
	}
};

class boat : public vehicle {
protected:
	int m_year;
	int m_miles;
	string m_model;
	bool m_canFloat = true;
public:
	boat(int year, int miles, string model, bool canFloat) :
		vehicle(year, miles, model),
		m_year(year),
		m_miles(miles),
		m_model(model),
		m_canFloat(canFloat)
	{

	}
	void Drive() override {
		int travel = 0;
		cout << "How far do you want to travel? ";
		cin >> travel;

		if (m_canFloat) {
			m_miles += travel;
			cout << endl << "You traveled " << m_miles << " so far!" << endl;
		}
		else {
			cout << endl << "You sank, as the boat cannot float!" << endl;
		}
		
	}
};

class car : public vehicle {
protected:
	int m_year;
	int m_miles;
	string m_model;
	int m_gas;
public:
	car(int year, int miles, string model, int gas) :
		vehicle(year, miles, model),
		m_year(year),
		m_miles(miles),
		m_model(model),
		m_gas(gas)
	{

	}
	void Drive() override {
		int travel = 0;
		cout << "How far do you want to travel? ";
		cin >> travel;
		if (travel > m_gas) {
			m_miles += m_gas;
			cout << endl << "Your car traveled " << m_miles << " so far before running out of gas, you have " << travel - m_gas << " miles left on your trip!" << endl;
			m_gas = 0;
		}
		else {
			m_miles += travel;
			m_gas -= travel;
			cout << endl << "Your car traveled " << m_miles << "so far with" << m_gas << " miles left in your gastank!" << endl;
		}
		
	}
};

class plane : public vehicle {
protected:
	int m_year;
	int m_miles;
	string m_model;
	bool m_firstClass = false;
public:
	plane(int year, int miles, string model, bool firstClass) :
		vehicle(year, miles, model),
		m_year(year),
		m_miles(miles),
		m_model(model),
		m_firstClass(firstClass)
	{

	}
	void Drive() override {
		int travel = 0;
		cout << "How far do you want to travel? ";
		cin >> travel;
		m_miles += travel;
		if (m_firstClass) {
			cout << endl << "Your plane has traveled " << m_miles << " overall, and in first class you are ready for the rest of your journey." << endl;
		}
		else {
			cout << endl << "Your plane has traveled  " << m_miles << " and you are in coach, you feel tired." << endl;
		}
		
	}
};

int main()
{
	car myCar(2017, 20040, "Toyota", 200);
	plane myFlight(2004, 400000, "Boeing", true);
	boat myBoat(1997, 10234, "Yamaya", false);

	myCar.Drive();
	myFlight.Drive();
	myBoat.Drive();
}
