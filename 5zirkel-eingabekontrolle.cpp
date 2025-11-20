#include <iostream>
#include <print>
#include <limits>
#include <string>
#include <charconv> 


template <typename T>
T prompt_read(const std::string& message);


template <>
char prompt_read<char>(const std::string& message) {
    std::print("{}", message);
    std::string line;
    std::getline(std::cin, line);
    if (line.size() != 1) throw std::runtime_error("Expected a single character");
    return line[0];
}

template <>
int prompt_read<int>(const std::string& message) {
    std::print("{}", message);
    std::string s;
    std::cin >> s;
    bool negativ = false;
    int acc = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        
        if (i == 0 && c == '-') {
            negativ = true;
            continue;
        }
        if (c < '0' || c > '9') throw std::runtime_error("not an integer");
        acc = acc * 10 + (c - '0');
    }
    if (negativ) {
        //std::print("negativ {} \n", (-1 * acc));
        return -1 * acc;
    }
    else {
        return acc;
    }
    
}
//#include <scan>
int main() {
    
    char ton = 'c';
    int mode = 0;//0 = dur/ionisch, 1 = dorisch, 2 = phrygisch, 3 = lydisch, 4=mixolydisch, 5=moll/aeolisch, 6=lokrisch
    int halb = 0;

    ton = prompt_read<char>("Stammton:");
    if (ton < 97 || ton >103) {
        
        std::print("ton nicht verfügbar\n");
        return 2;
    }
    mode = prompt_read<int>("mode \n 0 = dur/ionisch \n 1 = dorisch \n 2 = phrygisch \n 3 = lydisch \n 4 = mixolydisch \n 5 = moll/aeolisch \n 6 = lokrisch \n : ");

    if (mode < 0 || mode > 6) {
        std::print("modus nicht verfügbar\n");
        return 3;
    }
    halb = prompt_read<int>("um wieviele halbtöne erhöhen \n (vertiefen ist einfach negativ erhöhen):");
    int wurst = 2 * ((ton - 1) % 7);
    wurst -= (int)(wurst > 4);
    wurst += halb - (2 * mode);
    wurst += (int)(mode > 2);
    wurst += 12 * (int)(wurst < 0);
    wurst = (wurst + 6 * (int)(wurst % 2 != 0)) % 12;
    std::cout << "kreuz: " << wurst << " b: " << (12 - wurst) << std::endl;
    return 0;
}

