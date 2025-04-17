#include <iostream>
#include <locale>
#include "Loja.h"
#include"Produto.h"
#include"Cliente.h"
#include"Venda.h"
#include"Auxiliar.h"
#include <string>
#include <iomanip>
#include <limits>
#include<ctime>
using namespace std;

// Função principal
int main()
{
    setlocale(LC_ALL, ""); // Configura a localização para permitir o uso de acentos
    Loja loja;


    loja.armazenaCliente("Henrique", 910000000, "Rua do freixo");
    loja.armazenaCliente("Joao", 920000000, "Avenida Liberdade");
    loja.armazenaCliente("Angelo", 930000000, "Rua  vila de cima");
    loja.armazenaCliente("Tiago Silva", 910000001, "Rua Sao Jose");
    loja.armazenaCliente("Ernesto", 920000001, "Rua da paz");
    loja.armazenaCliente("Osvaldo", 930000001, "Rua do comercio");

    loja.armazenaProduto("Disco Rigido", 254, 599.0);
    loja.armazenaProduto("Grafica", 254, 599.0);
    loja.armazenaProduto("Teclado", 335, 105.9);
    loja.armazenaProduto("Secretaria", 298, 70.0);
    loja.armazenaProduto("Monitores", 134, 152.0);
    loja.armazenaProduto("Tapete Rato", 555, 30.0);
    loja.armazenaProduto("Rato", 424, 45.0);
    loja.armazenaProduto("Fones", 632, 60.0);
    loja.armazenaProduto("Ram", 234, 75.0);
    loja.armazenaProduto("Processador", 445, 250.0);
    loja.armazenaProduto("Componentes termicos", 96, 10.0);
    loja.armazenaProduto("Placa de som", 85, 5.90);
    loja.armazenaProduto("Motherboard", 365, 590.99);
    loja.armazenaProduto("Coolers de CPU", 78, 79.90);
    loja.armazenaProduto("Caixa Computador", 53, 106.0);
    loja.armazenaProduto("Microfone", 247, 42.99);
    loja.armazenaProduto("Fonte de Alimentacao", 190, 94.90);
    loja.armazenaProduto("Ventoinhas", 543, 29.99);
    loja.armazenaProduto("Placas de expansao", 67, 8.90);
    loja.armazenaProduto("Drives opticas", 110, 25.99);

    loja.armazenaVenda(1, 31, 1, "Disco Rigido", 1, 486.99, 23.0, 650);
    loja.armazenaVenda(2, 32, 1, "Teclado", 1, 86.09, 23.0, 110.0);
    loja.armazenaVenda(3, 33, 1, "Processador", 1, 203.25, 23.0, 300);
    loja.armazenaVenda(4, 34, 1, "Processador", 1, 203.25, 23.0, 270);
    loja.armazenaVenda(5, 35, 1, "Processador", 1, 203.25, 23.0, 260);

   


    loja.MenuPrincipal();


}