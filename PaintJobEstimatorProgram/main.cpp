#include <iostream>
#include <iomanip>
using namespace std;

const float GALLONSPERSQFT = (1.0 / 110.0);
const float HOURSLABORPERSQFT = (8.0 / 110.0);
const float COSTLABORPERHOUR = 25.00;

int getRooms();

int getSqFt();

int gallonsForRoom(int sqft);

float getPricePerGallon();

void displayEstimate(float paintcost, float laborcost, int hours, int gallons);

int main()
{
    // The four total estimates are initialized to 0.
    float totalCostPaint = 0;
    float totalCostLabor = 0;
    int totalGallons = 0;
    int totalHours = 0;

    // The number of rooms is retrieved
    int numberRooms = getRooms();

    for (int i = 0; i < numberRooms; i++)
    {
        cout << "Room " << (i + 1) << endl;

        int squareFeet = getSqFt(); // gets the number of sq ft for this room

        // Gets the number of gallons of paint needed for this room and adds it to total number of gallons
        float gallons = gallonsForRoom(squareFeet);
        totalGallons += gallons;

        // Gets the price of paint per gallon and uses it to add onto the total cost of paint
        float pricePerGallon = getPricePerGallon();
        totalCostPaint += gallons * pricePerGallon;

        // Finds the number of hours of labor needed for the paint job, and adds it to the total number of hours.
        float hours = (float(squareFeet) * HOURSLABORPERSQFT);
        totalHours += hours + 1.0; // Addition to counter truncation

        // Gets the cost of labor for this room and adds it to the total cost of labor.
        totalCostLabor += hours * COSTLABORPERHOUR;
    }

    // Displays the final estimates
    cout << "Estimates for Painting " << numberRooms << " Rooms:\n";
    displayEstimate(totalCostPaint, totalCostLabor, totalHours, totalGallons);

    return 0;
}

/*
    Summary: Gets the number of rooms that must be painted by prompting the user.
    Parameters: None.
    Return: The number of rooms to be painted is returned as integer.
    Preconditions: None.
    Postconditions: Prompt is displayed to terminal, and user presses enter to submit their input. Return will not equal 0 or less.
*/
int getRooms()
{
    int roomCount;

    do {
        cout << "How many rooms must be painted?\n";
        cin >> roomCount;

        if (roomCount <= 0)
        {
            cout << "ERROR: Must be 1 or more rooms.\n";
        }

    } while (roomCount <= 0);

    return roomCount;
}

/*
    Summary: Gets number of square feet to be painted from user.
    Parameters: None.
    Return: Integer for number of square feet is returned. Return will not be negative.
    Preconditions: None.
    Postconditions: Prompt is sent to terminal, user enters input with cin.
*/
int getSqFt()
{
    int sqFt;

    do {
        cout << "How many square feet must be painted in this room?\n";
        cin >> sqFt;

        if (sqFt < 0)
        {
            cout << "ERROR: Square feet cannot be negative.\n";
        }

    } while (sqFt < 0);

    return sqFt;
}

/*
    Summary: Using the number of square feet and the constant rate of gallons to square feet, calculates the whole number of gallons needed to paint a room.
    Parameters: The integer sqft, which is short for Square Feet, representing the number of square feet to be painted in a room.
    Return: Integer variable for the number of gallons needed to paint a room.
    Preconditions: sqft should NOT be negative, and the constant rate should be in float form.
    Postconditions: Integer is returned, rounded up.
*/
int gallonsForRoom(int sqft)
{
    float gallonsFloat = float(sqft) * GALLONSPERSQFT;
    int gallonsInt = int(gallonsFloat) + 1; // 1 added to counter truncation

    return gallonsInt;
}

/*
    Summary: Gets the price of paint per gallon, in float form.
    Parameters: None.
    Return: The price of paint per gallon, floating-point. It will be 10.00 or above.
    Preconditions: None.
    Postconditions: Terminal is used for displaying prompt and receiving user input.
*/
float getPricePerGallon()
{
    float price;

    do {
        cout << "How much does the paint for this room cost per gallon? (No $)\n";
        cin >> price;

        if (price < 10.00)
        {
            cout << "ERROR: Price must be $10.00 or more.\n";
        }

    } while (price < 10.00);

    return price;
}

/*
    Summary: Displays the total cost of a paint job, as well as the cost for the paint, cost for the labor, total number of hours needed, and total number of gallons needed.
    Parameters: Float for paintcost (total cost for paint), float laborcost (total cost for labor), integer for hours (total hours needed), and int for gallons (total needed gallons of paint).
    Return: None.
    Preconditions: All variables passed in should be nonzero positive numbers, and be correctly calculated. <iomanip> is also required for use.
    Postconditions: The terminal is used for output, with very liberal use of endl.
*/
void displayEstimate(float paintcost, float laborcost, int hours, int gallons)
{
    cout << fixed << setprecision(2) << "Cost of Paint: $" << paintcost << endl;
    cout << fixed << setprecision(2) << "Cost of Labor: $" << laborcost << endl;
    cout << "Total Hours Needed: " << hours << endl;
    cout << "Gallons of Paint Needed: " << gallons << endl;

    float total = paintcost + laborcost;
    cout << fixed << setprecision(2) << "Total Cost of Paint Job: $" << total << endl;

    return;
}
