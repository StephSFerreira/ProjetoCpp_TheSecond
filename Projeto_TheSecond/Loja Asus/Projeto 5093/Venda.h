#pragma once


#include <string>
using namespace std;

class Venda {
private:
    int numFatura;
    int numCliente;
    int numLinha;
    string nomeProduto;
    int quantidade;
    double precoSemIVA;
    double taxaIVA;
    double totalComIVA;
    double valorEntregue;
    double troco;
    double valorTotal;
   

    void calcularTotal(); // Método privado para calcular total e troco

public:
    Venda(int numFatura, int numCliente, int numLinha, string nomeProduto,
        int quantidade, double precoSemIVA, double taxaIVA, double valorEntregue);

    Venda() : numFatura(0), numCliente(0), numLinha(0), nomeProduto(""),
        quantidade(0), precoSemIVA(0.0), taxaIVA(0.0), totalComIVA(0.0),
        valorEntregue(0.0), troco(0.0) {
    }

    // Getters
    int getNumFatura() ;
    int getNumCliente() ;
    int getNumLinha() ;
    string getNomeProduto() ;
    int getQuantidade();
    double getPrecoSemIVA();
    double getTaxaIVA();
    double getTotalComIVA();
    double getValorEntregue() ;
    double getTroco();
    double getvalorTotal();


    // Setters
    void setQuantidade(int quantidade);
    void setPrecoSemIVA(double preco);
    void setTaxaIVA(double taxa);
    void setValorEntregue(double valor);
    void setvalorTotal(double valor_total);
};
