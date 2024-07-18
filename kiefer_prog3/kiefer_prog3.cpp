// Author: Maddison Kiefer
//
// Program: Calculating the Federal Tax
// This program will collect data from the user and use that to calculate the federal tax based on the
// information that was provided. 

// Header files
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void getData(char& maritalStatus, int& numPeople, double& grossSalary, double& percentagePension);
double taxAmount(int standardExemption, int percentagePension, int personalExemption, double grossSalary);

int main()
{
    // Defining variables
    char maritalStatus = 'n';
    int numPeople = 0;
    double grossSalary, percentagePension, standardExemption = 0.0;
    double taxOwed;
    
    // Calls the getData function for the inputs
    getData(maritalStatus, numPeople, grossSalary, percentagePension);
    
    // If statement that will set standardExemption depending on marital status
    if (maritalStatus == 'y')
        standardExemption = 7000;
    else
        standardExemption = 4000;
    
    // Calls the taxAmount function for the taxOwed variable
    taxOwed = taxAmount(standardExemption, percentagePension, numPeople, grossSalary);

    // Displays the Federal Tax that is owed
    cout << fixed << setprecision(2);
    cout << "The tax that is owed is " << taxOwed << endl;
    
}

void getData(char& maritalStatus, int& numPeople, double& grossSalary, double& percentagePension)
{
    // Sets the variables
    int numChildren;

    // Asks user for their marital status
    cout << "If Marital Status is married, please enter 'y': ";
    cin >> maritalStatus;
    cout << endl;

    // If statement that will ask for the number of children under 14 if the user is married
    if (maritalStatus == 'y')
    {
        cout << "Enter the number of children you have under the age of 14: ";
        cin >> numChildren;
        cout << endl;

        // Adds the number of children to the married couple for the total number of people
        numPeople = 2 + numChildren;
    }

    // Asks the user for gross income, including the income of their partner if they are married
    cout << "Please enter your gross income. If married, please enter combined gross income: ";
    cin >> grossSalary;
    cout << endl;

    // Asks the user for the percentage contributed to a pension fund
    cout << "Please enter the percentage of your gross income contributed to a pension fund (no more than 6 percent): ";
    cin >> percentagePension;
    cout << endl;
}

double taxAmount(int standardExemption, int percentagePension, int numpeople, double grossSalary)
{
    // Sets the variables
    double taxOwed, personalExemption, taxableIncome, pensionAmount;

    // Calcultes the personalExemption based on the number of total people
    personalExemption = 1500 * numpeople;
    
    // Calculates the amount in a pension from the gross income and the percentage in the pension, divided by 100
    pensionAmount = (grossSalary * percentagePension) / 100;
    
    // Calculates the taxable income from subtracted the calculated data from the gross income
    taxableIncome = grossSalary - (standardExemption + pensionAmount + personalExemption);

    // If statements that calculate the taxOwed depending on how much the taxableIncome is
    if (taxableIncome < 15000)
        taxOwed = taxableIncome * 0.15;
    else if (taxableIncome < 40000)
        taxOwed = 2250 + ((taxableIncome - 15000) * 0.25);
    else
        taxOwed = 8460 + ((taxableIncome - 40000) * 0.35);

    // Returns the taxOwed variable to where it is called
    return taxOwed;

}

