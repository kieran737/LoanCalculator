/*-----------------------------------------------------------------------------

Name: Kieran Hodge

Date: 12.02.2015

Lab number: 5

--------------------------------------------------------------------------------
Program Description: This Program is a loan calculator, it will take 3 variables
off the user loan amount, amount of interest and how long they have to pay off the
loan and then it will calculate their monthly payments and output them into a table
which the user can print off and use for referancing for their loan payments.
--------------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

string validationLoop;

//Functions
float interestCal (float interestRate, float timeYears, float loan ) {
	float interest;
	interest = loan * interestRate * timeYears;
	return interest;
}
float totalInterest (float interest, float loan) {
	float total;
	total = interest + loan;
	return total;
}

int main ()
{
	//Declaring First Batch of Variables.
	while (TRUE) {
		float loan, timeYears, timeMonths;
		double rate, interestRate, monthlyPayment, total ;
		float interest;
		cout << setw (55) <<"Welcome to CNC Loan Calculator" << endl << endl;
		//Allowing the User to Input and Validating their input.
		cout << setw (66) << "Please Enter the Loan Amount that you wish to Borrow: " << char(156), cin >> loan;
		cout << endl;
		cin.ignore();
		while (cin.fail())
		{
			cin.clear();
			getline (cin, validationLoop);
			system ("color 04");
			cout << setw (65) << "Invalid Input, Please Enter a Numeric Value: ", cin >> loan;
			cout << endl;
		}
		system ("color 07");
		cout << setw (63) <<"Now Enter the Interest Rate of the Loan: ", cin >> rate;
		cout << endl;
		cin.ignore();
		while (cin.fail())
		{
			cin.clear();
			getline (cin, validationLoop);
			system ("color 04");
			cout << setw (65) <<"Invalid Input, Please Enter a Numeric Value: ", cin >> rate;
			cout << endl;
		}
		system ("color 07");
		cout << setw (65) << "Lastly Enter the amount of time to pay off the" << endl; 
		cout << setw (48) << "Loan in Years: ", cin >> timeYears;
		cout << endl;
		cin.ignore();
		while (cin.fail())
		{
			cin.clear();
			getline (cin, validationLoop);
			system ("color 04");
			cout << setw (65) << "Invalid Input, Please Enter a Numeric Value: ", cin >> timeYears;
			cout << endl;
		}
		system("CLS");
		//Calculating the User's input.
		timeMonths = timeYears * 12;
		interestRate= rate / 100;

		interest = interestCal(interestRate, timeYears, loan);
		total = totalInterest(interest, loan);
		monthlyPayment = total / timeMonths;
		//Declairing Second Batch of Variables for outputting.
		float totalPaid = 0.0;
		float interestToAdd = 0.0;
		int numberMonths = 0;
		float remainingAmount = total;
		float toAdd = 0.0;
		//Creating Output file
		ofstream outFile;
		outFile.open("output.txt");
		//Creating format to output the calculations.
		cout <<setw (67) << "Month #: Interest Added. Amount Paid. Debt Remaining" << endl;
		outFile << cout << "CNC Calculator" << endl;
		outFile << cout << "Month #: Interest Added. Amount Paid. Debt Remaining" << endl;
		while (remainingAmount > 0) {
			interestToAdd = remainingAmount * interestRate / 12;
			numberMonths++;
			remainingAmount += interestToAdd;
			if (remainingAmount > monthlyPayment) {
				toAdd = monthlyPayment;
			} else {
				toAdd = remainingAmount;
			}
			//Outputting the programs interface and to the Output file so user can print payments.
			cout <<setw (27) << numberMonths << ": "<< char(156) << interestToAdd << ", " << char(156) << toAdd << ", " << char(156) << remainingAmount << fixed << setprecision(2) << endl;
			outFile << cout << numberMonths << ": £" << interestToAdd << ", £" << toAdd << ", £" << remainingAmount << fixed << setprecision(2) << endl;
			totalPaid += toAdd;
			remainingAmount -= toAdd;
		}
		//Loan Summary
		cout << endl;
		cout << setw (43) <<"Loan Summary" << endl;
		outFile << cout << "Loan Summary" << endl;
		cout << setw (48) <<"Loan including Interest: "<< char(156) << total << endl;
		outFile << cout << "Loan including Interest: £" << total << endl;
		cout << setw (47) <<"Original Amount Loaned: " << char(156) << loan << endl;
		outFile << cout << "Original Amount Loaned: £" << loan << endl;
		cout << setw (45) <<"Total Interest Added: " << char(156) << interest << endl;
		outFile << cout << "Total Interest Added: £" << interest << endl;
		cout << setw (49) <<"Amount to Pay each month: " << char(156) << monthlyPayment << endl;
		outFile << cout << "Amount to Pay each month: £" << monthlyPayment << endl;
		cout << setw (60) <<"How Many months needed to pay the Loan: " << numberMonths << endl << endl;
		outFile << cout << "How Many months needed to pay the Loan: " << numberMonths << endl;
		outFile.close();
		//Restart Loop
		char answer;
		while(true) { 

			system ("color 07");
			cout << setw (65) << "Would you like to restart the calculator (y/n)\n ";
			cin >> answer;
			if(answer == 'y' || answer == 'Y' || answer == 'n'|| answer == 'N') {
				system ("cls");
				break;
			}
			else
				system ("color 04");
			cout << setw (47) << "Invalid input\n\n";
			Sleep (500);
		}
		if (answer == 'n' || answer == 'N') {
			system ("color 05");
			cout << "\n\n\n\n\n\n";
			cout << setw (60) << "Thank you for using CNC Calculator!";
			Sleep (2000);
			break;
		}
	}
}