#include<iostream>
#include<vector>

int main() {
    std::vector<std::string> names;

    //Add elements
    names.push_back("Alice");
    names.push_back("Bob");
    names.push_back("Charlie");
    
    //Access elements
    std::cout <<"Second name:"<<names[1]<<std::endl;

    //iterate
    for(const auto& name : names){
        std::cout <<name<<" ";
    }
    return 0;
}