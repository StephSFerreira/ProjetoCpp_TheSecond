#include "auxiliar.h"
#include <iostream>
#include <limits> // necess�rio para numeric_limits
#include <cctype> // Para isalpha()
using namespace std;



using namespace std;

bool Auxiliar::getValidString(string& input) {
    if (input.empty()) return false; // Verifica se est� vazio

    for (char c : input) {
        if (!isalpha(c) && c != ' ') { // Permite apenas letras e espa�os
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

        if (cin.fail()) {  // Se o input n�o for um n�mero v�lido
            cin.clear();  // Limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer do cin
            cout << "Entrada inv�lida! Insira um n�mero v�lido ou '0' para voltar atr�s: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer ap�s a leitura do n�mero
            return valor;
        }
    }
}
