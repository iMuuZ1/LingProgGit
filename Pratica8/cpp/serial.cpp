#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt");

    if (!file) {
        cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
    return 0;
}
