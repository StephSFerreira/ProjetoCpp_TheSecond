#include "auxiliar.h"
#include <iostream>
#include <limits> // necessário para numeric_limits
#include <cctype> // Para isalpha()
using namespace std;



using namespace std;

bool Auxiliar::getValidString(string& input) {
    if (input.empty()) return false; // Verifica se está vazio

    for (char c : input) {
        if (!isalpha(c) && c != ' ') { // Permite apenas letras e espaços
            return false;
        }
    }
    return true;
}



int Auxiliar::getValidNumber()
{
    int valor;
    while (true) {
        cin >> valor;

        if (cin.fail()) {  // Se o input não for um número válido
            cin.clear();  // Limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer do cin
            cout << "Entrada inválida! Insira um número válido ou '0' para voltar atrás: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer após a leitura do número
            return valor;
        }
    }
}
