#include <iostream>
#include <iomanip>

using namespace std;
// Variables for minimum and maximum Fahrenheit values, constant but could be altered manually.
const int MINIMUM = 0;
const int MAXIMUM = 20;

float getCelsius(int f);

int main()
{
    int fahrenheit = MINIMUM; // Starts at the minimum value

    // Title and column labels
    cout << "Fahrenheit to Celsius Conversion Examples\n";
    cout << setw(10) << "Fahrenheit" << setw(10) << "Celsius" << endl;

    for (int i = MINIMUM; i <= MAXIMUM; i++) // For each value from the minimum to maximum Fahrenheit degree:
    {
        cout << fixed << setw(10) << right << fahrenheit;
        cout << fixed << setw(10) << right << setprecision(1) << getCelsius(fahrenheit);
        cout << endl;

        fahrenheit++; // Increments Fahrenheit for the next iteration
    }

    return 0;
}

/*
    Summary: In goes Fahrenheit, out comes Celsius, using formula C = 5/9(F - 32). In other words, converts between the two units.
    Parameters: f is short for Fahrenheit, stored in integer value.
    Return: The answer from calculating the left side of the aforementioned formula is returned, as a float variable.
    Preconditions: None, really, although we have to assume the input is of a possible temperature (not below absolute zero or impossibly hot), and was meant to be an int in the first place.
    Postconditions: A converted Celsius value can be returned to main, though with a variable number of decimal points.
*/
float getCelsius(int f)
{
    float celsius = (5.0 / 9.0) * float(f - 32); // REMEMBER NEXT TIME TO CONVERT TO FLOAT TO PREVENT INTEGER DIVISION!!!

    return celsius;
}
