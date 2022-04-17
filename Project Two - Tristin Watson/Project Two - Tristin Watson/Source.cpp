#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Constructor.cpp"

// creates vector banks
std::vector<myBank> banks;
// displays menu
void menu() {
	// variables
	double invest;
	double monthly;
	double annual;
	int years;
	std::string input;
	std::cout << "\n**********************************\n";
	std::cout << "********** Data Input ************\n";
	// while loop to take initial investment
	std::cout << "Initial Investment Amount: ";
	while (true) {
		std::cin >> input;
		if (input == "q" || input == "quit") {
			invest = 1.0;
			break;
		}
		try {
			invest = std::stod(input);
			if (invest < 0.0 || invest > 10000.0) {
				std::cout << "That amount is either too low or high\n";
			}
			else {
				std::cout << "$";
				std::cout << std::fixed << std::setprecision(2) << invest;
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// while loop to take monthly deposit input
	std::cout << "\nMonthly Deposit: ";
	while (true) {
		std::cin >> input;
		if (input == "q" || input == "quit") {
			monthly = 1.0;
			break;
		}
		try {
			monthly = std::stod(input);
			if (monthly < 0.0 || monthly > 1000.0) {
				std::cout << "That amount is either too low or high\n";
			}
			else {
				std::cout << "$";
				std::cout << std::fixed << std::setprecision(2) << monthly;
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// while loop to take annual interest
	std::cout << "\nAnnual Interest: ";
	while (true) {
		std::cin >> input;
		if (input == "q" || input == "quit") {
			annual = 1.0;
			break;
		}
		try {
			annual = std::stod(input);
			if (annual < 0.0 || annual > 20.0) {
				std::cout << "That amount is either too low or high\n";
			}
			else {
				std::cout << std::fixed << std::setprecision(2) << annual;
				std::cout << "%";
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// while loop to take years of investment
	std::cout << "\nNumbers of years: ";
	while (true) {
		std::cin >> input;
		if (input == "q" || input == "quit") {
			years = 1;
			break;
		}
		try {
			years = std::stoi(input);
			if (years < 0 || years > 100) {
				std::cout << "That amount is either too low or high\n";
			}
			else {
				std::cout << years << " years";
				break;
			}
		}
		catch (std::exception& e) {
			std::cout << "Invalid input.\n";
		}
	}
	// creates default constructor, sets constructor values, adds constructor to vector
	myBank bank;
	bank.setInvest(invest), bank.setAnnual(annual), bank.setMonthly(monthly), bank.setYears(years);
	banks.push_back(bank);
	std::cout << std::endl;
	system("Pause");

}
// calculates totals recieved from menu and displays them accordingly
void calculate() {
	// variables
	double invest;
	double invest2;
	double monthly;
	double annual;
	int years;
	double interest;
	double total;
	double total2;
	// gets bank objects variables
	for (myBank bank : banks) {
		invest = bank.getInvest();
		invest2 = bank.getInvest();
		monthly = bank.getMonthly();
		annual = bank.getAnnual();
		years = bank.getYears();
		break;
	}
	// displays balance without additional monthly deposits
	invest = invest2;
	double annual2 = 0.0;
	std::cout << std::endl;
	std::cout << "Balance and Interest Without Additional Monthly Deposits\n";
	std::cout << "==========================================================\n";
	std::cout << "Year      Year End Balance      Year End Earned Interest\n";
	for (int e = 1; e <= (years); e++) {
		invest2 = invest2 * (1 + (annual / 100));
		annual2 = invest2 - invest;
		invest = invest2;
		std::cout << std::setw(4) << e << std::setw(17) << invest2;
		std::cout<< std::setw(26) << annual2 << std::endl;
	}
	// sets invest
	for (myBank bank : banks) {
		invest = bank.getInvest();
	}
	// displays balance wih additonal monthly deposists
	double interest2= 0.0;
	std::cout << std::endl;
	std::cout << "  Balance and Interest With Additional Monthly Deposits  \n";
	std::cout << "==========================================================\n";
	std::cout << "Year      Year End Balance      Year End Earned Interest\n";
	for (int e = 1; e <= (years); e++) {
		for (int y = 0; y <= (11); y++) {
			interest = (invest + monthly) * ((annual / 100) / 12);
			interest2 = interest + interest2;
			invest = invest + monthly + interest;
		}
		std::cout << std::setw(4) << e << std::setw(17) << invest;
		std::cout << std::setw(26) << interest2 << std::endl;
	}
	std::cout << std::endl;
	// sets invest
	for (myBank bank : banks) {
		invest = bank.getInvest();
	}
	// delivers a by monthly report on compounded interest based on your set monthly deposit
	interest2 = 0.0;
	total2 = invest;
	std::cout << "        By Monthly Report On Compounded Interest Based On Your Set ";
	std::cout << "Monthly Deposit      \n";
	std::cout << "=============================================================";
	std::cout << "=============================\n";
	std::cout << "| Month | Opening Amount | Deposited Amount | ";
	std::cout << "$ Total | Total Interest | Closing Balance | " << std::endl;
	for (int i = 1; i <= (years*12); i++) {
		interest = (invest + monthly) * ((annual / 100) / 12);
		interest2 = interest2 + interest;
		invest = invest + interest + monthly;
		total = invest - interest;
		std::cout << "|" << std::setw(4) << i << std::setw(4) << "|";
		std::cout<< std::setw(16) << total2 << "|" << std::setw(18) << monthly;
		std::cout << "|" << std::setw(9) << total << "|" << std::setw(16) << interest;
		std::cout<< "|" << std::setw(17) << invest << "|" << std::endl;
		total2 = invest;
	}
	std::cout << std::endl;
	system("Pause");
}
// main
int main() {
	// calls menu options
	menu();
	// calculates totals received from menu
	calculate();
	return 0;
}