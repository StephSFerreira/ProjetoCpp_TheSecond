#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cliente {
private:
    //atributos
    int idCliente;
    string nomeCliente;
    int Telefone;
    string Morada;
    int valorTotal;


public:
    // Construtores
    Cliente();
    Cliente(int idCliente, string nomeCliente, int Telefone, string Morada);
    


    // Seletores (getters)
    int getidCliente();
    string getnomeCliente();
    int getTelefone();
    string getMorada();
    int getvalorTotal();
    

    // Modificadores (setters)
    void setnomeCliente(const string& novoNomeCliente);
    void setTelefone(int telefone);
    void setMorada(string morada);
 //   void setTotalComprado();
    // Outras funções
    string toString();  // Retorna os dados do cliente como string
};


