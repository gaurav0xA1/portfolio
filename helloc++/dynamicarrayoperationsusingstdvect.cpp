#include <iostream>
#include <vector>
#include <algorithm> // For find()

using namespace std;

// Function to display vector elements
void display(const vector<int>& vec) {
    cout << "Array elements: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr; // Create empty dynamic array

    // 1. Insertion Operations
    cout << "\n=== Insertion Operations ===\n";
    
    // Insert at end (push_back)
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    display(arr); // 10 20 30

    // Insert at specific position (insert)
    arr.insert(arr.begin() + 1, 15); // Insert 15 at index 1
    display(arr); // 10 15 20 30

    // 2. Deletion Operations
    cout << "\n=== Deletion Operations ===\n";
    
    // Remove last element (pop_back)
    arr.pop_back();
    display(arr); // 10 15 20

    // Erase by position
    arr.erase(arr.begin() + 1); // Remove element at index 1
    display(arr); // 10 20

    // Erase by value (using remove-erase idiom)
    arr.push_back(10);
    arr.push_back(40);
    display(arr); // 10 20 10 40
    
    arr.erase(remove(arr.begin(), arr.end(), 10), arr.end());
    display(arr); // 20 40

    // 3. Searching Operations
    cout << "\n=== Searching Operations ===\n";
    
    // Using std::find
    auto it = find(arr.begin(), arr.end(), 20);
    if (it != arr.end()) {
        cout << "Element 20 found at position: " 
             << distance(arr.begin(), it) << endl;
    } else {
        cout << "Element not found\n";
    }

    // Binary search (requires sorted array)
    sort(arr.begin(), arr.end());
    bool exists = binary_search(arr.begin(), arr.end(), 20);
    cout << "Element 20 exists: " << boolalpha << exists << endl;

    // 4. Other Useful Operations
    cout << "\n=== Other Operations ===\n";
    cout << "Current size: " << arr.size() << endl;
    cout << "Capacity: " << arr.capacity() << endl;
    cout << "Is empty? " << arr.empty() << endl;

    // Clear all elements
    arr.clear();
    cout << "After clear, size: " << arr.size() << endl;

    return 0;
}