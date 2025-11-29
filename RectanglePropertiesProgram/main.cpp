#include <iostream>

using namespace std;

void getLength_Width(float &length, float &width);

float calcPerimeter(float l, float w);

float calcArea(float l, float w);

void displayProperties(float p, float a);

int main()
{
    // The variables for rectangle length, width, area, and perimeter are defined, with length and width being initialized as 0.
    float length, width, area, perimeter;
    length = 0;
    width = 0;

    // Length and width values will be retrieved from user
    cout << "Welcome to the Rectangle Properties Program.\n";
    getLength_Width(length, width);

    // Perimeter and Area are found
    perimeter = calcPerimeter(length, width);
    area = calcArea(length, width);

    displayProperties(perimeter, area); // Properties are printed

    return 0;
}

/*
    getLength_Width() is a function that will retrieve input from the user to set as values for length and width.
    In the parameters, length and width (both floats) are passed in via reference, and they are thus both updated once the function returns to main.
    It is a void function, featuring no return value.
    There are no preconditions, as the values will be set via user input.
    The values of length and width, after being passed through, will be updated in the original scope from which the function was called.
*/
void getLength_Width(float &length, float &width) // Length and width passed in via reference
{
    bool invalidInput; // The flag for an invalid value
    do {
            invalidInput = 0;
            cout << "What will the length of your rectangle be?\n";
            cin >> length;

            cout << "What will the width of your rectangle be?\n";
            cin >> width;

            if (length <= 0 || width <= 0)
            {
                cout << "One or more of your inputs were invalid; no values of 0 or less are accepted.\n";
                invalidInput = 1; // Will set the flag for an invalid value to true
            }

    } while (invalidInput); // If there was an invalid input, this section of code will repeat.

    return; // After the loop is escaped, with a valid input, the function will return.
}

/*
    calcPerimeter() calculates the perimeter of a rectangle.
    Variables in the parameter are floats, l being the length and w the width. They can be any positive number.
    The return value is a float, the perimeter of the rectangle.
    The length and width passed cannot be 0 or negative, however that is ensured within another function.
    Twice the value of l and twice that of 2 will be added, and that answer returned.
*/
float calcPerimeter(float l, float w)
{
    float perimeter = (2 * l) + (2 * w); // Defines float value of perimeter, setting it to 2l + 2w, the formula for the perimeter of a rectangle.

    return perimeter;
}

/*
    calcArea() calculated the area of a rectangle.
    Variables are both float type, l meaning length and w meaning width. They can be any positive number.
    The area of the rectangle, a float, is returned.
    The length or width cannot be 0 or negative.
    The product of l and w will be returned when function is called.
*/
float calcArea(float l, float w)
{
    float area = l * w; // Defines area, sets it to length times width.

    return area;
}

/*
    displayProperties() displays the properties of a rectangle.
    The parameters include float values p and a, which are short for perimeter and area.
    No value is returned by this function.
    The perimeter and area will be put to display as is; if they are faulty, they cannot be corrected.
    A message is displayed announcing to the user the values passed in through parameters, perimeter and area.
*/
void displayProperties(float p, float a)
{
    cout << "The Perimeter of your rectangle is " << p << " units.\n";
    cout << "The Area of your rectangle is " << a << " units squared.\n";

    return;
}
