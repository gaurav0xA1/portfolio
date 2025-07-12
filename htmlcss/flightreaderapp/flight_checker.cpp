#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    std::string dob;
};

std::vector<Person> loadClients(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Person> clients;
    std::string line;

    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, dob;

        std::getline(ss, name, ',');
        std::getline(ss, dob, ',');

        clients.push_back({name, dob});
    }

    return clients;
}

std::string loadText(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

bool match(const std::string& text, const Person& person) {
    return text.find(person.name) != std::string::npos &&
           text.find(person.dob) != std::string::npos;
}

int main() {
    auto clients = loadClients("clients_data.csv");
    auto text = loadText("flight_text.txt");

    std::cout << "🔍 Checking for scheduled flights...\n\n";

    bool anyMatch = false;
    for (const auto& client : clients) {
        if (match(text, client)) {
            std::cout << "✅ " << client.name << " (DOB: " << client.dob << ") has a flight scheduled.\n";
            anyMatch = true;
        }
    }

    if (!anyMatch)
        std::cout << "❌ No scheduled flights found for listed clients.\n";

    return 0;
}
