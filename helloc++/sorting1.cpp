#include <iostream>
#include <vector>
#include <string>    //for string handling
#include <algorithm> //for swap function

using namespace std;

// function to perform bubble sort on names

void bubbleSort(vector<string> &names)
{
    int n = names.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // compare adjacent names
            if (names[j] > names[j + 1])
            {
                // swap if they're in wrong order
                swap(names[j], names[j + 1]);
            }
        }
    }
}

int main()
{
    vector<string> names;
    int numNames;
    string name;

    // get number of names
    cout << "Enter numbevr of names to sort:";
    cin >> numNames;
    cin.ignore(); // clear inputy buffer

    // get names from user
    cout << "Enter " << numNames << "names:\n";
    for (int i = 0; i < numNames; i++)
    {
        getline(cin, name);
        names.push_back(name);
    }

    // sort the names
    bubbleSort(names);

    // Display sorted names
    cout << "\nSorted Names(Alphabetical Order:\n)";
    for (const string &sortedName : names)
    {
        cout << sortedName << endl;
    }
    return 0;
}