#include <iostream>
#include <fstream>
const std::string nomeFile = "booleani.txt";

class Color {
public:
    static std::string red;
    static std::string green;
    static std::string reset;
};

std::string Color::red = "\u001b[31m";
std::string Color::green = "\u001b[32m";
std::string Color::reset = "\u001b[0m";


int intro(bool dettatura) {
    int selezione;
    do {
        system("clear");
        system("bash robogears.sh");
        std::cout << "\n";
        std::cout << " 0) Exit\n";
        std::cout << " 1) Dettatura --> ";
        if (dettatura)
            std::cout << Color::green << "on\n" << Color::reset;
        else
            std::cout << Color::red << "off\n" << Color::reset;
        std::cout << "  >> ";
        std::cin >> selezione;
    } while (selezione < 0 or selezione > 1);
    return selezione;
}

bool letturaRiga1() {
    std::string riga;
    std::ifstream fileIn(nomeFile);
    std::getline(fileIn, riga);
    fileIn.close();
    if (riga == "TRUE")
        return true;
    else
        return false;
}

void scritturaRiga1(bool dettatura) {
    std::ofstream fileOut(nomeFile);
    if (dettatura)
        fileOut << "FALSE" << "\n";
    else
        fileOut << "TRUE" << "\n";
    fileOut.close();
}

int main() {
    int a;
    bool dettatura;

    do {
        dettatura = letturaRiga1();
        a = intro(dettatura);
        switch (a) {
            case 0:
                break;
            case 1:
                scritturaRiga1(dettatura);
                break;
        }
    } while (a != 0);
    return 0;
}
