#pragma once 
#include <string>
using namespace std;

class Produto {
private:
	int idProduto;
	string nomeProduto;
	string Categoria;
	string Descricao;
	int quantidadeProduto;
	int quantidadeVendida;
	float precoVenda;
	double lucroAtual = 0.0;
	int quantidadeComprada = 0;
	double Lucro;
	double lucroTotalProduto;


public:

	// construtores
	Produto();
	Produto(int idProduto, string nomeProduto, int quantidadeProduto, float precoVenda);

	// seletores
	int getidProduto();
	string getnomeProduto();
	int getquantidadeProduto();
	float getprecoVenda();
	int getquantidadeComprada();
	int getLucro();


	// modificadores
	void setidProduto(int idProduto);
	void setnomeProduto(string nomeProduto);
	void setquantidadeProduto(int quantidadeProduto);
	void setprecoVenda(float precoVenda);
	void setquantidadeComprada(int quantidadeComprada);
	void setLucro(double Lucro);


	// outras funcoes

	string toString();


};

