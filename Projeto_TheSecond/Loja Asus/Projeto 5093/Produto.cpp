#include "Produto.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Produto::Produto()
{
	idProduto = 0;
	nomeProduto = " Nao definido ";
	

}

Produto::Produto(int idProduto, string nomeProduto, int quantidadeProduto, float precoVenda)
{
	this->idProduto = idProduto;
	this->nomeProduto = nomeProduto;
	this->quantidadeProduto = quantidadeProduto;
	this->precoVenda = precoVenda;

}

int Produto::getidProduto()
{
	return idProduto;
}

string Produto::getnomeProduto()
{
	return nomeProduto;
}


int Produto::getquantidadeProduto()
{
	return quantidadeProduto;
}

float Produto::getprecoVenda()
{
	return precoVenda;
}

int Produto::getquantidadeComprada()
{
	return quantidadeComprada;
}

int Produto::getLucro()
{
	return Lucro;
}



void Produto::setidProduto(int idProduto)
{
	this->idProduto = idProduto;
}

void Produto::setnomeProduto(string nomeProduto)
{
	this->nomeProduto = nomeProduto;
}



void Produto::setquantidadeProduto(int quantidadeProduto)
{
	this->quantidadeProduto = quantidadeProduto;
}

void Produto::setprecoVenda(float precoVenda)
{
	this->precoVenda = precoVenda;
}

void Produto::setquantidadeComprada(int quantidadeComprada)
{
	this->quantidadeComprada = quantidadeComprada;
}

void Produto::setLucro(double Lucro)
{
	this->Lucro = Lucro;
}



string Produto::toString()
{
	return "ID: " + to_string(idProduto) + ", Nome: " + nomeProduto + ", Quantidade: " + to_string(quantidadeProduto) + ", Preco Venda: " + to_string(precoVenda * 1.3);
}