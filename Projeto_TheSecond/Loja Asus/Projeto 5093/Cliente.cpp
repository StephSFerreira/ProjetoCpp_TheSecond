#include "Cliente.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

Cliente::Cliente()
{
    idCliente = 0;
    nomeCliente = " Nao definido ";
    Telefone = 0;
    Morada = " Nao definido ";

}

Cliente::Cliente(int idCliente, string nomeCliente, int Telefone, string Morada)
{
    this->idCliente = idCliente;
    this->nomeCliente = nomeCliente;
    this->Telefone = Telefone;
    this->Morada = Morada;
}


int Cliente::getidCliente() {
    return idCliente;
}

string Cliente::getnomeCliente() {
    return nomeCliente;
}

int Cliente::getTelefone() {
    return Telefone;
}

string Cliente::getMorada() {
    return Morada;
}

int Cliente::getvalorTotal()
{
    return valorTotal;
}

void Cliente::setnomeCliente(const string& novoNomeCliente) {
    this->nomeCliente = novoNomeCliente;
}

void Cliente::setTelefone(int telefone) {
    this->Telefone = telefone;
}

void Cliente::setMorada(string Morada) {
    this->Morada = Morada;
}

string Cliente::toString() {
    return "ID: " + to_string(idCliente) + " Nome: " + nomeCliente + ", Telefone : " + to_string(Telefone) + ", Morada : " + Morada;
}
