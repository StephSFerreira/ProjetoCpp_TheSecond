#include "Venda.h"


void Venda::calcularTotal() {
    totalComIVA = quantidade * precoSemIVA * (1 + taxaIVA / 100);
    troco = valorEntregue - totalComIVA;
}

Venda::Venda(int numFatura, int numCliente, int numLinha, std::string nomeProduto,
    int quantidade, double precoSemIVA, double taxaIVA, double valorEntregue)
{
    this->numFatura = numFatura;
    this->numCliente = numCliente;
    this->numLinha = numLinha;
    this->nomeProduto = nomeProduto;
    this->quantidade = quantidade;
    this->precoSemIVA = precoSemIVA;
    this->taxaIVA = taxaIVA;
    this->valorEntregue = valorEntregue;
     
}

// Getters
int Venda::getNumFatura()  { return numFatura; }
int Venda::getNumCliente()  { return numCliente; }
int Venda::getNumLinha()  { return numLinha; }
std::string Venda::getNomeProduto() { return nomeProduto; }
int Venda::getQuantidade()  { return quantidade; }
double Venda::getPrecoSemIVA(){ return precoSemIVA; }
double Venda::getTaxaIVA() { return taxaIVA; }
double Venda::getTotalComIVA()  { return totalComIVA; }
double Venda::getValorEntregue()  { return valorEntregue; }
double Venda::getTroco() { return troco; }

double Venda::getvalorTotal() { return valorTotal; }

// Setters
void Venda::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
    calcularTotal();
}

void Venda::setPrecoSemIVA(double preco) {
    this->precoSemIVA = preco;
    calcularTotal();
}

void Venda::setTaxaIVA(double taxa) {
    this->taxaIVA = taxa;
    calcularTotal();
}

void Venda::setValorEntregue(double valor) {
    this->valorEntregue = valor;
    calcularTotal();
}

void Venda::setvalorTotal(double valor_total)
{
    this->valorTotal = valorTotal;
}
