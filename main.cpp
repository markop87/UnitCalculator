/*
Unit converter using vector of objects and calculating units by ratio
*/

#include <iostream>
#include <vector>

using namespace std;

struct Calc {
    int group;
    int order;
    string name;
    double mratio;
};

vector <Calc> table = {
    { 1, 1, "Meter", 100 },
    { 1, 2, "Kilometer", 100000 },
    { 1, 3, "Centimeter", 1 },
    { 1, 4, "Millimeter", 0.1 },
    { 1, 5, "Micrometer", 0.0001 },
    { 1, 6, "Mile", 160935 },
    { 1, 7, "Yard", 91.44 },
    { 1, 8, "Foot", 30.48 },
    { 1, 9, "Inch", 2.54 },
    { 2, 1, "Kilogram", 1 },
    { 2, 2, "Gram", 0.001 },
    { 2, 3, "Milligram", 0.000001 },
    { 2, 4, "Metric ton", 1000 },
    { 2, 5, "Pound", 0.453592 },
    { 2, 6, "Ounce", 0.0283495 },
    { 2, 7, "Carrat", 0.0002 },
    { 3, 1, "Celsius", 0 },
    { 3, 2, "Kelvin", 0 },
    { 3, 3, "Fahrenheit", 0 },
    { 4, 1, "Square kilometer", 1000000 },
    { 4, 2, "Square meter", 1 },
    { 4, 3, "Square centimeter", 0.0001 },
    { 4, 4, "Square milimeter", 0.000001 },
    { 4, 5, "Acre", 4046.8564224 },
    { 4, 6, "Hectare", 10000 },
    { 4, 7, "Square mile", 2589990 },
    { 4, 8, "Square yard", 0.83612736 },
    { 4, 9, "Square foot", 0.09290304 },
    { 5, 1, "Km per hour", 1 },
    { 5, 2, "Miles per hour", 1.609344 },
    { 5, 3, "Meters per second", 3.6 },
    { 5, 4, "Feet per minute", 0.018288 },
    { 5, 5, "Knots", 1.852 },
};

long double getResult(int x, int y, double a)
{
    if(table[x].group != 3)
    {
        return a * table[x].mratio / table[y].mratio;
    }
    else //converting temperatures as ratio doesn't apply
    {
        if(table[x].order == 1 && table[y].order == 2) // C to K
        {
            return a + 273.15;
        }
        else if(table[x].order == 1 && table[y].order == 3) // C to F
        {
            return a * 9/5 + 32;
        }
        else if(table[x].order == 2 && table[y].order == 1) // K to C
        {
            return a - 273.15;
        }
        else if(table[x].order == 2 && table[y].order == 3) // K to F
        {
            return (a - 273.15) * 9/5 + 32;
        }
        else if(table[x].order == 3 && table[y].order == 1) // F to C
        {
            return (a - 32) * 5/9;
        }
        else if(table[x].order == 3 && table[y].order == 2) // F to K
        {
            return (a - 32)* 5/9 + 273.15;
        }
    }

};

int main()
{
    char again;

    do {

    int choice1, choice2, choice3;
    double howmuch;

    //start of a menu
    cout << "1. Distance\n2. Weight\n3. Temperature\n4. Area\n5. Speed\nChoice (number): ";
    cin >> choice1;

    cout << "\nFrom:";

        for(int i = 0; i < table.size(); i++)
        {
            if(table[i].group == choice1)
            {
                cout << "\n" << table[i].order << ". " << table[i].name;
            }
        }

        cout << "\nChoice (number): ";
        cin >> choice2;

        cout << "\n\tTo:";

        for(int j = 0; j < table.size(); j++)
        {
            if(table[j].group == choice1 && table[j].order != choice2)
            {
                cout << "\n\t" << table[j].order << ". " << table[j].name;
            }
        }

        cout << "\nChoice (number): ";
        cin >> choice3;
    //end of a menu


    int index1, index2;

    //finding index of chosen units
    for(int i = 0; i < table.size(); i++)
    {
        if(table[i].group == choice1 && table[i].order == choice2)
        {
            index1 = i;
        }

        if(table[i].group == choice1 && table[i].order == choice3)
        {
            index2 = i;
        }
    }

    cout << "\nHow much (" << table[index1].name << "): ";
    cin >> howmuch;

    cout << "\n\n";

    cout << howmuch << " " << table[index1].name << " = " << getResult(index1, index2, howmuch) << " " << table[index2].name << endl;

    cout << "\nAgain? (Y or N): ";
    cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}
