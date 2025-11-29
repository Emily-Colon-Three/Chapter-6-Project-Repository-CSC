#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
const int NUMBEROFJUDGES = 5;

float getScore();

bool isLower(float s1, float s2);

bool isHigher(float s1, float s2);

float calcAverage(int judgeCount, float total, float lo, float hi);

int main()
{
    // Defines float variables for the lowest score, highest score, total from all added scores, the score currently being worked with, and the average of all scores.
    float lowScore, highScore, total, score, average;

    cout << "This contestant will be judged by a collection of " << NUMBEROFJUDGES << " judges.\n\n"; // Introduces user

    // Section for the first judge's score; it is generated, set to score, added to the total, and set to the lowest and highest scores by default.
    cout << "Judge 1: ";
    score = getScore(); // This completes the output started last line, with the calling of getScore().

    total += score;
    lowScore = score;
    highScore = score;

    for (int i = 2; i <= NUMBEROFJUDGES; i++) // Starting at 2 instead of 1 to account for the first judge, the loop will iterate for each judge afterwards. i can be used as the judge number.
    {
        cout << "Judge " << i << ": "; // Judge number changes with i
        score = getScore();

        total += score;

        if (isLower(score, lowScore))
        {
            lowScore = score;
        }
        if (isHigher(score, highScore))
        {
            highScore = score;
        }
    }

    average = calcAverage(NUMBEROFJUDGES, total, lowScore, highScore); // Uses the global constant number of judges, and the corresponding variables from main, utilizing calcAverage() to store average.

    // Displays average to user, with uniform output of the average.
    cout << "The average of scores, with highest and lowest counted out, is ";
    cout << fixed << setprecision(1) << average << ".\n";

    return 0;
}

/*
    Summary: Generates a random float number for the score by averaging two random numbers.
    Parameters: None.
    Return: A float for a score between 0 and 10 is returned.
    Preconditions: None.
    Postconditions: The float returned could have a variable level of precision. The score will also be output to the terminal, and endl will end the line and clear the buffer.
*/
float getScore()
{
    // Using <random> library to set up random number generation
    static random_device scoreEngine;
    static uniform_real_distribution<float> randomNum(0, 10); // Generates float numbers between 0 and 10

    // The two random numbers are initialized
    float num1 = randomNum(scoreEngine);
    float num2 = randomNum(scoreEngine);

    // The two random number are averaged out
    float score = (num1 + num2) / 2.0;

    // Outputs the score to display, and returns it to main.
    cout << fixed << setprecision(1) << score << endl;
    return score;
}

/*
    Summary: Determines if first number is less than or equal to the second. If yes, true, else, false.
    Parameters: s1 represents the score being compared, and s2 is the lowest score so far. These are passed in from main. Both are float.
    Return: A boolean true or false is returned, depending on whether the first score is less than or equal to the first.
    Preconditions: Both scores are float-type, and are between 0 and 10. Though, if the range were expanded, it would still function normally. Second input also needs to be the lowest score so far.
    Postconditions: True or false is returned.
*/
bool isLower(float s1, float s2)
{
    bool result;

    if (s1 <= s2) // if 1st score is less than or equal to 2nd score
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

/*
    Summary: Determines if first score is more than, or at least equal to, the first one. Do not confuse with isLower(), very similar.
    Parameters: Both inputs are float-type, s1 representing the score being evaluated and s2 as the current highest score.
    Return: A boolean is returned, true or false. True is the result if the first score is higher than or equal to the second.
    Preconditions: Both inputs are float-type, usually between 0 and 10. Additionally, second input must be the highest score encountered so far in the program.
    Postconditions: True or false is returned to caller function.
*/
bool isHigher(float s1, float s2)
{
    bool result; // Same as isLower(), however this is for determining if the first input is the highest so far.

    if (s1 >= s2) // if 1st score is more than or equal to 2nd score
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

/*
    Summary: Calculates the average of scores submitted by a number of judges, dropping out the lowest and highest scores before averaging.
    Parameters: An integer for the number of judges, judgeCount, and float variables for the total of all scores (total), the lowest score (lo), and the highest score (hi).
    Return: Average is returned in float data type.
    Preconditions: judgeCount is a whole number greater than 2, total includes all scores from all judges, lo is the true lowest score, and hi is the true highest score.
    Postconditions: float is returned to caller function.
*/
float calcAverage(int judgeCount, float total, float lo, float hi)
{
    judgeCount -= 2; // To account for lowest and highest scores being dropped out

    // Lowest and highest are taken out of total.
    total -= lo;
    total -= hi;

    // Calculates the average by dividing the remaining total by the remaining number of judges. Then, average returned.
    float average = total / float(judgeCount);
    return average;
}
