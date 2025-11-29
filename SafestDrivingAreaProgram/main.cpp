#include <iostream>
#include <string>

using namespace std;
const int REGIONCOUNT = 5; // 5 regions of city.

void getRegInfo(string &currentRegionName, int &currentCrashesNumber);

bool isLower(int num1, int num2);

void showLowest(string name, int numCrashes);

int main()
{
    string currentRegionName;
    string lowestRegionName;

    int currentCrashesNumber;
    int lowestCrashesNumber = 999999; // Set to stupid-high value so that the first entry will replace it.

    for (int i = 0; i < REGIONCOUNT; i++) // For each of the five regions of the city, perform the following:
    {
        // Region info is retrieved from user
        getRegInfo(currentRegionName, currentCrashesNumber);

        if (isLower(currentCrashesNumber, lowestCrashesNumber)) // If the new number of crashes is less than or equal to the current lowest, the lowest is replaced with new data.
        {
            lowestCrashesNumber = currentCrashesNumber;
            lowestRegionName = currentRegionName;
        }
    }

    showLowest(lowestRegionName, lowestCrashesNumber); // The final output of the program, the region with the least experienced crashes and its number of crashes.

    return 0;
}

/*
    Summary: getRegInfo() gets the name of a region and its number of crashes after prompting the user, and passes them into a reference variable.
    Parameters: currentRegionName is a string reference from main which is the name of a region being given, currentCrashesNumber is an integer reference from main which is the number of crashes in that region.
    Return: void function, no return value.
    Precondition: None, values will be replaced anyways.
    Postcondition: Both variables will be given a new value, but the int will always be 0 or more, never negative.
*/
void getRegInfo(string &currentRegionName, int &currentCrashesNumber)
{
    cout << "What is the name of one region in the city?\n";
    cin >> currentRegionName;

    do {
        cout << "How many crashes occurred in this area in the past year?\n";
        cin >> currentCrashesNumber;

        if (currentCrashesNumber < 0)
        {
            cout << "Invalid number of crashes: Cannot be negative.\n"; // Error message returned for negative number.
        }

    } while (currentCrashesNumber < 0); // Code will loop if an invalid number of crashes was given.

    return;
}

/*
    Summary: Takes two numbers, and determines if the first is less than or equal to the second.
    Parameters: num1, the first number of crashes, and num2, the second number of crashes. Both are integers.
    Return: True or False is returned, as it is a bool function. True is returned if num1 <= num2.
    Preconditions: Both numbers are integers of a value 0 or more, in the typical use case.
    Postconditions: A bool value will end up in main.
*/
bool isLower(int num1, int num2)
{
    if (num1 <= num2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
    Summary: Displays a message showing the region with the lowest number of crashes and its statistic for the past year.
    Parameters: The name of the region is name, a string variable, and numCrashes, the number of crashes, is an integer variable.
    Return: No value is returned.
    Preconditions: numCrashes should not end up a negative number, and name should have some sort of coherent title within it.
    Postconditions: The variables will be displayed through cout.
*/
void showLowest(string name, int numCrashes)
{
    cout << "The region with the lowest amount of crashes in the past year is " << name << ".\n";
    cout << "It experienced " << numCrashes << " crashes within that time.\n";

    return;
}
