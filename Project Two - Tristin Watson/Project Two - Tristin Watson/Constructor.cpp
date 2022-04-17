#include <iostream>
#include <string>
#include <vector>

// myBank class
class myBank {
private:
	double invest;
	double monthly;
	double annual;
	int years;
public:
	// mutated and default constructor
	myBank(double aInvest, double aMonthly, double aAnnual, int aYears) {
		setInvest(aInvest);
		setMonthly(aMonthly);
		setAnnual(aAnnual);
		setYears(aYears);
	}
	myBank() {
		invest = 0.0;
		monthly = 0.0;
		annual = 0;
		years = 0;
	}
	// getters and setters
	void setInvest(double invest) {
		this->invest = invest;
	}
	double getInvest() {
		return invest;
	}
	void setMonthly(double monthly) {
		this->monthly = monthly;
	}
	double getMonthly() {
		return monthly;
	}
	void setAnnual(double annual) {
		this->annual = annual;
	}
	double getAnnual() {
		return annual;
	}
	void setYears(int years) {
		this->years = years;
	}
	int getYears() {
		return years;
	}
};