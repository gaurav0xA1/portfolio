#include <iostream>
#include <vector>

using namespace std;

struct Task
{
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void TakeInput();
void display();
void taskStatus();

int main()
{
    char choice;

    while (true)
    { // Infinite loop until we break out
        cout << "\nPress 'A' to add, 'V' to view,'C' to edit status ,  'X' to exit: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        if (choice == 'X')
        {
            cout << "Goodbye!\n";
            break; // Exit the loop
        }
        else if (choice == 'A')
        {
            TakeInput(); // Add new task
        }
        else if (choice == 'V')
        {
            display(); // Show all tasks
        }
        else if (choice == 'C')
        {
            taskStatus(); // Show all tasks
        }
        else
        {
            cout << "Invalid option! Try A, V or X.\n";
        }
    }

    return 0;
}

void TakeInput()
{
    string task;
    cout << "Enter the task:";
    getline(cin, task);
    Task newTask = {task, false};
    tasks.push_back(newTask);
}

void display()
{

    cout << "The list of your ucnompleted tasks is below:" << endl;

    cout << "S.N       Task Description         Status" << endl;

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i].description << "\t \t  \t" << (tasks[i].completed ? "Done" : "Undone") << endl;
    }
}



//this function has a problem , it goes into infinite loop when i press "x" at serial number input
void taskStatus()
{
    int serialNumber;
    char editStatus;
    cout << "Enter the S.N you want to edit :" << endl;
    cin >> serialNumber;
    cin.ignore();
    cout << "Press 'D' for marking as done , 'U' for marking as undone and 'X' for returning back " << endl;
    cin >> editStatus;
    cin.ignore();
    if (editStatus == 'X')
    {
        return;
    }
    else if (editStatus == 'D')
    {
        if (serialNumber < 1 || serialNumber > tasks.size())
        {
            cout << "Invalid Input!" << endl;
        }
        else
        {
            tasks[serialNumber - 1].completed = true;
        }
    }
    else if (editStatus == 'U')
    {
        if (serialNumber < 1 || serialNumber > tasks.size())
        {
            cout << "Invalid Input!" << endl;
        }
        else
        {
            tasks[serialNumber - 1].completed = false;
        }
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }
}