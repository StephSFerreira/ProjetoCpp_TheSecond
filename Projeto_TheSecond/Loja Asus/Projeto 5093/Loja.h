#pragma once
#include <string>
#include <iostream>
#include <ctime> 
#include <limits>
#include <iomanip>
#include "Cliente.h"
#include "Produto.h"
#include "Venda.h"
#include "Auxiliar.h"

using namespace std;


class Loja
{
private:
	Cliente Povo[100];
	int contadorCliente = 0;

	Cliente gastosClientes[100];


	// Produto
	Produto Stock[100];
	int quantidadeVendida[100];
    int contadorProduto = 0;

	// Talão
	Venda Taloes[100];
	int contadorTaloes = 0;

	
	
	// Vendas
	Venda Artigo[100];
	int indexVenda = 0;
	int contadorVenda = 0;
	double saldoLoja;
	int numero_fatura;







public:

	// Clientes
	Loja();
	void armazenaCliente(string nomeCliente, int Telefone, string Morada);
	void criarCliente();
	int procurarCliente(int idCliente);  // Procurar cliente pelo ID
	void imprimePovo();  // Imprimir dados do cliente
	void imprimeCliente(int i);
	void eliminarCliente();  // Eliminar cliente
	void alteraCliente();
	int getLastId();



	// Produtos
	void armazenaProduto(string nomeProduto, int quantidadeProduto, float precoVenda);
	int procurarProduto(int idProduto);
	void imprimeStock();
	void imprimeProduto(int i);
	void eliminaProduto(int idProduto);
	int getLastIdProduto();
	void adicionarQuantidadeouProduto();
	void removerQuantidadeouProduto();
	void produtoMenosVendido();
	void produtoMaisVendido();
	
	




	
	void MenuPrincipal();
	void gerirStock();
	void gerirClientes();
	void gerirVendas();





	// venda
	
	void armazenaVenda(int numFatura,int  numCliente, int numLinha,string nomeProduto, int quantidade, double precoSemIVA,double taxaIVA,double valorEntregue);
	void imprimirTalao(int numero_cliente, const string& produtosVendidos, double valor_sIVA, double valor_total, double valor_entregue, double troco);
	void mostrarVendas();
	void efetuarVenda();
	int getLastIDTaloes();
	void clienteQueMaisComprou();
	void relatorioVendasPorProduto();

	// relatorios

	void gerarRelatorios();


	

};