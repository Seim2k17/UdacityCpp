#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream my_file;

    my_file.open("../files/board_1");
    if(my_file)
    {
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << "\n";
            std::istringstream s_stream(line);
            int number;
            char delimiter;
            while(s_stream >> number >> delimiter)
            {
                std::cout << number << ":";
            }
            std::cout << std::endl;
        }
    } 
    else{
        std::cout << "error opening file " << std::endl;
    }

    return 0;
}