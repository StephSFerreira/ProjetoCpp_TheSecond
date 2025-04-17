#include "Loja.h"
#include "Cliente.h"
#include "Produto.h"
#include"Auxiliar.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include<ctime>
#include<vector>
#include <algorithm> 
#include <cctype>
#include <sstream>


using namespace std;



Loja::Loja() 
{

}



void Loja::armazenaCliente(string nomeCliente, int Telefone, string Morada)
{
	int lastID = getLastId() + 1;
	if (contadorCliente < 100)
	{
		Povo[contadorCliente] = Cliente(lastID, nomeCliente, Telefone, Morada);
		contadorCliente++;

	}
		else
		{
			cout << " Lista clientes cheia!";
		}
}

void Loja::armazenaProduto(string nomeProduto, int quantidadeProduto, float precoVenda)
{
	int lastID = getLastIdProduto() + 1;
	if (contadorProduto < 100) 
	{
		Stock[contadorProduto] = Produto(lastID, nomeProduto, quantidadeProduto, precoVenda);
		contadorProduto++;
		//cout << " 'Produto' " << nomeProduto << "' adicionado com sucesso!\n";
	}
		else
		{
			cout << " Stock cheio!\n";
		}
}

void Loja::armazenaVenda(int numFatura, int numCliente, int numLinha, string nomeProduto, int quantidade, double precoSemIVA, double taxaIVA, double valorEntregue)
{
	int lastID = getLastIDTaloes() + 1; // Obtém o próximo ID para a venda
	if (contadorProduto < 100)
	{
		// Calcular o valor total com IVA aqui, se for necessário
		double precoComIVA = precoSemIVA * (1 + taxaIVA);

		// Armazenar a venda com todos os dados necessários
		Taloes[contadorVenda] = Venda(numFatura, numCliente, numLinha, nomeProduto, quantidade, precoSemIVA, taxaIVA, valorEntregue);
		contadorVenda++; // Incrementar o contador de vendas
	}
		else
		{
			cout << " Vendas cheio!\n";
		}
}



int Loja::getLastId()
{
	int maiorID = 30;
	
	for (int i = 0; i < contadorCliente; i++)
	{
		int idCliente = Povo[i].getidCliente();
		if (idCliente > maiorID)
		{
			maiorID = idCliente;
		}

	}
	return maiorID;

}

int Loja::getLastIdProduto()
{
	int maiorID = 0;
	// Itera sobre os produtos no stock 
	for (int i = 0; i < contadorProduto; i++)
	{
		int idProduto = Stock[i].getidProduto();  // Supondo que os produtos têm um método `getIdProduto()`
		if (idProduto > maiorID) 
		{
			maiorID = idProduto;
		}
	}
	return maiorID;
}

int Loja::getLastIDTaloes()
{
	int maiorID = 0;
	for (int i = 0; i < contadorTaloes; i++)
	{
		int numFatura = Taloes[i].getNumFatura();
		if (numFatura > maiorID)
		{
			maiorID = numFatura;
		}
	}
	return maiorID;
}



void Loja::imprimePovo()
{
	if (contadorCliente == 0)
	{
		cout << "\nNenhum cliente registado!\n";
		return;
	}

	cout << "==========================================================================\n";
	cout << "|                                \033[33mCLIENTES\033[0m                                |\n";
	cout << "==========================================================================\n";
	cout << "| " << setw(4) << left << "ID"
		 << "| " << setw(20) << left << "NOME"
		 << "| " << setw(15) << left << "TELEFONE"
		 << "| " << setw(25) << left << "MORADA" << " |\n";
	cout << "==========================================================================\n";

	for (int i = 0; i < contadorCliente; i++)
	{
		imprimeCliente(i);
	}

	cout << "==========================================================================\n" << endl;
}

void Loja::imprimeCliente(int i)
{
	cout << "| " << setw(4) << left << Povo[i].getidCliente()
		 << "| " << setw(20) << left << Povo[i].getnomeCliente()
		 << "| " << setw(15) << left << Povo[i].getTelefone()
		 << "| " << setw(25) << left << Povo[i].getMorada() << " |\n";
}

void Loja::imprimeStock()
{
	cout << "|=====================================================|\n";
	cout << "|                      \033[33mPRODUTO\033[0m                        |\n";
	cout << "|=====================================================|\n";
	cout << "| " << setw(4) << left << "ID"
		 << "| " << setw(25) << left << "NOME"
		 << "| " << setw(6) << left << "QTD"
		 << "| " << setw(10) << left << "PRECO      |\n";
	cout << "|=====================================================|\n";

	for (int i = 0; i < contadorProduto; i++)
	{

		imprimeProduto(i);
	}

	cout << "|=====================================================|\n";
	cout << endl << endl;
}

void Loja::imprimeProduto(int i)
{
	if (contadorProduto == 0)
	{
		cout << "\n Nenhum produto em stock! \n";
		return;
	}

	// Agora a função imprime apenas os detalhes de um produto por vez
	cout << "| " << setw(4) << left << Stock[i].getidProduto()
		<< "| " << setw(25) << left << Stock[i].getnomeProduto()
		<< "| " << setw(6) << left << Stock[i].getquantidadeProduto()
		<< "| " << setw(10) << left << fixed << setprecision(2) << Stock[i].getprecoVenda() << " |\n";
	    
}



void Loja::criarCliente() {
	bool continuar = true;  // Variável para controlar o loop e permitir voltar atrás

	// Verifica se há espaço para adicionar um novo cliente
	if (contadorCliente >= 100) 
	{
		cout << "Não há espaço para adicionar um novo cliente.\n";
		return;
	}

		do 
		{
			// Pedir o ID do cliente
			int idCliente = getLastId() + 1;  // O ID é gerado automaticamente com base no contador de clientes

			string nomeCliente;
			int Telefone;
			string Morada;
		 // Solicita o nome do cliente
			cout << "Inserir o nome do cliente ou '0' para voltar atrás: ";
			cin.ignore(); // limpa o '\n' que ficou no buffer
			getline(cin, nomeCliente);

			if (nomeCliente == "0")
			{
				continuar = false;
				break;
			}

				// Verifica se o nome do cliente é válido
			while (!Auxiliar::getValidString(nomeCliente)) 
			{
				cout << "Inserir um nome de cliente válido: ";
				getline(cin, nomeCliente);  // Usando getline novamente para capturar nomes com espaços
			}
		
				// Solicita o número de telefone
				cout << "Inserir o número de telefone ou '0' para voltar atrás: ";
				Telefone = Auxiliar::getValidNumber(); // Usando a função de validação de números

				// Se o utilizador digitar '0', volta para o menu anterior
			if (Telefone == 0) 
			{
				continuar = false;
				break;
			}

				// Verifica se o número de telefone já existe
				for (int i = 0; i < contadorCliente; ++i) 
				{
					if (Povo[i].getTelefone() == Telefone) 
					{
						cout << "Número de telefone já existe. Insira um número diferente: ";
						Telefone = Auxiliar::getValidNumber();  // Pede novamente o número de telefone
						i = -1;  // Reinicia a verificação
					}
				}

			// Solicita a morada do cliente
			cout << "Inserir a morada do cliente ou '0' para voltar atrás: ";
			getline(cin, Morada);  // Usa getline para permitir entrada com espaços

			// Se o utilizador digitar '0', volta para o menu anterior
				if (Morada == "0") 
				{
					continuar = false;
					break;
				}

				// Verifica se a morada é válida
				while (!Auxiliar::getValidString(Morada)) 
				{
					cout << "Morada inválida! Insira uma morada válida contendo apenas letras e espaços: ";
					getline(cin, Morada);  // Novamente, usamos getline para a morada
				}

			// Criação do cliente no array de clientes
			Povo[contadorCliente] = Cliente(idCliente, nomeCliente, Telefone, Morada);
			contadorCliente++;  // Incrementa o contador de clientes
			cout << "Cliente criado com sucesso! ID do cliente: " << idCliente << endl;

			continuar = false;  // Interrompe o loop após a criação do cliente

		} while (continuar);  // O loop continua até o utilizador escolher sair
}

int Loja::procurarCliente(int idCliente)
{

	for (int i = 0; i < contadorCliente; i++)
	{
		if (Povo[i].getidCliente() == idCliente)
		{
			return i;
		}
	}
	return -1;
}

void Loja::eliminarCliente()
{
	int idCliente;
	cout << "Insira o ID do cliente a ser eliminado: ";
	cin >> idCliente;

	int posicao = procurarCliente(idCliente);

	if (posicao != -1) 
	{
		// Encontrou o cliente, então deve ser removido
		for (int i = posicao; i < contadorCliente - 1; i++) 
		{
			Povo[i] = Povo[i + 1];  // Desloca os elementos para a esquerda
		}
		contadorCliente--;  // Decrementa o contador de clientes
		cout << "Cliente com ID " << idCliente << " foi removido com sucesso!" << endl;
	}
		else 
		{
			cout << "Cliente com ID " << idCliente << " não encontrado." << endl;
		}
}

void Loja::alteraCliente() {
	int idCliente;
	bool clienteEncontrado = false;

	do {
		cout << "Insira o ID do cliente a ser alterado (ou '0' para voltar): ";
		idCliente = Auxiliar::getValidNumber();// verifica se o numero é valido

		if (idCliente == 0) 
		{
			cout << "Operação cancelada. A voltar ao menu...\n";
			return;
		}

		int posicao = procurarCliente(idCliente);

		if (posicao != -1) 
		{
			clienteEncontrado = true;
			string novoNomeCliente;

			do {
				cout << "Cliente encontrado! Insira o novo nome do cliente (ou '0' para cancelar): ";
				getline(cin, novoNomeCliente);

				if (novoNomeCliente == "0") 
				{
					cout << "Alteração cancelada.\n";
					return;
				}

				if (!Auxiliar::getValidString(novoNomeCliente)) 
				{
					cout << "Nome inválido! Apenas letras e espaços são permitidos.\n";
				}

			} while (!Auxiliar::getValidString(novoNomeCliente));

			// Atualiza o nome do cliente
			Povo[posicao].setnomeCliente(novoNomeCliente);
			cout << "Nome do cliente alterado com sucesso!\n";
		}
			else 
			{
				cout << "Cliente com ID " << idCliente << " não encontrado. Tente novamente ou digite '0' para voltar.\n";
			}

	} while (!clienteEncontrado);
}



int Loja::procurarProduto(int idProduto)
{
	for (int i = 0; i < contadorProduto; i++) 
	{
		if (Stock[i].getidProduto() == idProduto) 
		{
			return i;
		}
	}
	return -1; // Produto não encontrado
}

void Loja::eliminaProduto(int idProduto)
{

	int posicao = procurarProduto(idProduto);

	for (int i = posicao; i < contadorProduto - 1; i++) 
	{
		Stock[i] = Stock[i + 1];
	}
	contadorProduto--;
	cout << " Produto com ID " << idProduto << " foi removido!\n";
}

void Loja::adicionarQuantidadeouProduto()
{
	int opcao;
	bool continuar = true;  // Variável para controlar o loop e permitir voltar atrás

	// Verifica se há espaço no estoque para adicionar um novo produto
	if (contadorProduto >= 100) 
	{
		cout << "Não há espaço no stock para adicionar um novo produto.\n";
		return;
	}

	do 
	{
		// Pedir o ID do produto
		int idProduto;
		cout << "Insira o ID do produto ou '0' para voltar atrás: ";
		idProduto = Auxiliar::getValidNumber();

		// Se o utilizador digitar 0, volta para o menu anterior
		if (idProduto == 0) 
		{
			continuar = false;  // Interrompe o loop e volta atrás
			break;
		}

		// Procurar o produto pelo ID
		int posicao = procurarProduto(idProduto);  // posicao é o índice do produto no array Stock

		if (posicao != -1)
		{
			// Produto já existe, pede ao utilizador a quantidade a ser adicionada
			int quantidadeAdicionar;
			cout << "Produto encontrado! Insira a quantidade a ser adicionada ao produto com ID " << idProduto << ": ";
			quantidadeAdicionar = Auxiliar::getValidNumber();

			// Se o utilizador digitar 0, volta para o menu anterior
			if (quantidadeAdicionar == 0) 
			{
				continuar = false;  // Interrompe o loop e volta atrás
				break;
			}

			// Atualiza a quantidade do produto
			int novaQuantidade = Stock[posicao].getquantidadeProduto() + quantidadeAdicionar;
			Stock[posicao] = Produto(idProduto, Stock[posicao].getnomeProduto(), novaQuantidade, Stock[posicao].getprecoVenda());
			cout << "Quantidade do produto com ID " << idProduto << " atualizada para " << novaQuantidade << " unidades.\n";
			continuar = false;  // Após concluir, interrompe o loop
		}
			else 
			{
				// Produto não encontrado, cria um novo
				string nomeProduto;
				int precoCusto;
				int quantidadeProduto;  // Variável para a quantidade do novo produto

				// Solicita ao utilizador o nome do novo produto
				cout << "Produto não encontrado. Insira o nome do novo produto ou '0' para voltar atrás: ";
				getline(cin, nomeProduto);

				// Verifica se o nome do produto é válido
					while (!Auxiliar::getValidString(nomeProduto))
					{
						cout << "Nome inválido! Insira um nome válido contendo apenas letras e espaços: ";
						getline(cin, nomeProduto);
					}

					// Se o utilizador digitar 0, volta para o menu anterior
					if (nomeProduto == "0") 
					{
						continuar = false;  // Interrompe o loop e volta atrás
						break;
					}

				// Solicita o preço do novo produto
				cout << "Insira o preço do novo produto ou '0' para voltar atrás: ";
				precoCusto = Auxiliar::getValidNumber();

				// Se o utilizador digitar 0, volta para o menu anterior
				if (precoCusto == 0) 
				{
					continuar = false;  // Interrompe o loop e volta atrás
					break;
				}

				int precoVenda = precoCusto * 1.3;  // Calcula o preço de venda

				// Solicita a quantidade para o novo produto
				cout << "Insira a quantidade do novo produto ou '0' para voltar atrás: ";
				quantidadeProduto = Auxiliar::getValidNumber();

				// Se o utilizador digitar 0, volta para o menu anterior
				if (quantidadeProduto == 0) 
				{
					continuar = false;  // Interrompe o loop e volta atrás
					break;
				}

				// Cria o novo produto no stock com a quantidade fornecida
				Stock[contadorProduto] = Produto(contadorProduto + 1, nomeProduto, quantidadeProduto, precoVenda);
				contadorProduto++;
				cout << "Novo produto adicionado ao stock com ID " << contadorProduto << " e " << quantidadeProduto << " unidades.\n";
				continuar = false;  // Após concluir, interrompe o loop
			}
	} while (continuar);  // O loop continua até o utilizador escolher sair
}

void Loja::removerQuantidadeouProduto()
{
	int opcao;
	bool continuar = true;  // Variável para controlar o loop e permitir voltar atrás

	do {
		int idProduto;
		cout << "Insira o ID do produto ou '0' para voltar atrás: ";
		idProduto = Auxiliar::getValidNumber();

		// Se o utilizador digitar 0, volta para o menu anterior
		if (idProduto == 0) 
		{
			continuar = false;  // Interrompe o loop e volta atrás
			break;
		}

		// Procurar o produto pelo ID
		int posicao = procurarProduto(idProduto);  // posicao é o índice do produto no vetor Stock

		if (posicao != -1) 
		{
			// Produto encontrado, pede ao utilizador a quantidade a ser removida
			int quantidadeRemover;
			cout << "Produto encontrado! Insira a quantidade a ser removida do produto com ID " << idProduto << " ou '0' para voltar atrás: ";
			quantidadeRemover = Auxiliar::getValidNumber();

			// Se o utilizador digitar 0, volta para o menu anterior
			if (quantidadeRemover == 0) 
			{
				continuar = false;  // Interrompe o loop e volta atrás
				break;
			}

			// Verifica se a quantidade a ser removida é maior que a quantidade disponível
			if (quantidadeRemover > Stock[posicao].getquantidadeProduto()) 
			{
				cout << "Erro: Quantidade a ser removida é maior que a quantidade disponível!\n";
			}
				else if (quantidadeRemover == Stock[posicao].getquantidadeProduto()) 
				{
					// Se a quantidade removida for igual à quantidade disponível, remove o produto todo
					cout << "Produto com ID " << idProduto << " removido do stock, pois a quantidade foi completamente removida.\n";

					// Remove o produto, movendo os seguintes para a posição anterior
					for (int i = posicao; i < contadorProduto - 1; i++) 
					{
						Stock[i] = Stock[i + 1];
					}
					contadorProduto--;  // Decrementa o contador de produtos
					continuar = false;  // Interrompe o loop após a remoção
				}
			else 
			{
				// Caso contrário, atualiza a quantidade do produto
				int novaQuantidade = Stock[posicao].getquantidadeProduto() - quantidadeRemover;
				Stock[posicao] = Produto(idProduto, Stock[posicao].getnomeProduto(), novaQuantidade, Stock[posicao].getprecoVenda());
				cout << "Quantidade do produto com ID " << idProduto << " atualizada para " << novaQuantidade << " unidades.\n";
				continuar = false;  // Interrompe o loop após a atualização
			}
		}
			else 
			{
				// Produto não encontrado
				cout << "ID não encontrado. ";
			}

	} while (continuar);  // O loop continua até o utilizador escolher voltar atrás ou completar a operação
}



void Loja::produtoMenosVendido()
{
	int minVendidos = INT_MAX;  // Inicializa com o maior valor possível inteiro, garante que qualquer valor menor que esse será armazenado na variável.
	int idProdutoMenosVendido = -1; // é inicializado como -1, indicando que, inicialmente, nenhum produto foi identificado como o menos vendido.

	for (int i = 0; i < contadorProduto; i++)
	{
		int temp = Stock[i].getquantidadeComprada();

		if (temp > 0 && temp < minVendidos) // Garante que não escolhemos um produto com 0 vendas
		{
			minVendidos = temp;
			idProdutoMenosVendido = i;
		}
	}

	if (idProdutoMenosVendido == -1)
	{
		cout << "=========================================" << endl;
		cout << " Nenhum produto vendido até o momento." << endl;
		cout << "=========================================" << endl;
		return;
	}

	cout << "=========================================" << endl;
	cout << "         Produto Menos Vendido" << endl;
	cout << "=========================================" << endl;
	cout << "ID do Produto      : " << Stock[idProdutoMenosVendido].getidProduto() << endl;
	cout << "Nome do Produto    : " << Stock[idProdutoMenosVendido].getnomeProduto() << endl;
	cout << "Quantidade Vendida : " << Stock[idProdutoMenosVendido].getquantidadeComprada() << endl;
	cout << "=========================================" << endl;
}

void Loja::produtoMaisVendido()
{
	int maxVendidos = 0;
	int idProdutoMaisVendido = -1;
	int temp = 0;

	// Itera sobre o vetor de quantidadeVendida para encontrar o produto mais vendido
	for (int i = 0; i < contadorProduto; i++)
	{
		temp = Stock[i].getquantidadeComprada();
		if (temp > maxVendidos)
		{
			maxVendidos = temp;
			idProdutoMaisVendido = i;
		}
	}

	// Agora, vamos calcular o lucro do produto mais vendido
	double precoVenda = Stock[idProdutoMaisVendido].getprecoVenda();

	// Calcular o preço de compra (removendo ambos os IVAs)
	double precoCompra = precoVenda / (1.30 * 1.23);  // Remove 30% e 23% do IVA

	// Calcular o lucro
	double lucro = precoVenda - precoCompra;

	// Calcular o lucro total
	double lucroTotalProduto = lucro * Stock[idProdutoMaisVendido].getquantidadeComprada();

	// Atualizar o lucro do produto no stock
	double lucroAtual = Stock[idProdutoMaisVendido].getLucro();  // Obtém o lucro atual do produto
	Stock[idProdutoMaisVendido].setLucro(lucroAtual + lucroTotalProduto);  // Atualiza o lucro total

	// Imprimir as informações do produto mais vendido
	cout << "=========================================" << endl;
	cout << "         Produto Mais Vendido" << endl;
	cout << "=========================================" << endl;
	cout << "ID do Produto      : " << Stock[idProdutoMaisVendido].getidProduto() << endl;
	cout << "Nome do Produto    : " << Stock[idProdutoMaisVendido].getnomeProduto() << endl;
	cout << "Quantidade Vendida : " << Stock[idProdutoMaisVendido].getquantidadeComprada() << endl;
	cout << "Lucro Total       : " << fixed << setprecision(2) << lucroTotalProduto << " EUR" << endl;  // Exibe o lucro total
	cout << "=========================================" << endl;
}

void Loja::clienteQueMaisComprou()
{
	// Verifica se há vendas registradas
	if (contadorVenda == 0) 
	{
		cout << "Nenhuma venda registrada." << endl;
		return;
	}

	// Criar vetor para armazenar o total gasto por cliente
	vector<double> gastosClientes(contadorCliente, 0.0);  // Inicializa com 0.0 para todos os clientes, ou seja nenhum cliente gastou nada

	// Acumula o total gasto de cada cliente (com IVA)
	for (int i = 0; i < contadorVenda; ++i) 
	{
		int idCliente = Taloes[i].getNumCliente();  // ID do cliente
		double valorComIVA = Taloes[i].getPrecoSemIVA()*1.23;   // Total da venda com IVA

		// Verifica se o ID do cliente está dentro do intervalo correto
		if (idCliente >= 31 && idCliente < 31 + contadorCliente) 
		{
			int index = idCliente - 31;  // Ajusta o índice para o vetor
			gastosClientes[index] += valorComIVA;  // Acumula o total gasto com IVA
		}
	}

	// Descobre o cliente com maior gasto
	int idClienteMaisGastou = -1;
	double maiorGasto = 0.0;

	for (int i = 0; i < contadorCliente; ++i) 
	{
		if (gastosClientes[i] > maiorGasto) 
		{
			maiorGasto = gastosClientes[i];
			idClienteMaisGastou = 31 + i;  // Corrige o índice para o ID real (começa em 31)
		}
	}

	// Exibe o cliente com maior gasto
	if (idClienteMaisGastou != -1) 
	{
		int posCliente = procurarCliente(idClienteMaisGastou);
		if (posCliente != -1) 
		{
			Cliente cliente = Povo[posCliente];

			cout << "=========================================" << endl;
			cout << "         Cliente Que Mais Comprou        " << endl;
			cout << "=========================================" << endl;
			cout << "ID do Cliente        : " << cliente.getidCliente() << endl;
			cout << "Nome do Cliente      : " << cliente.getnomeCliente() << endl;
			cout << "Total Gasto          : " << fixed << setprecision(2) << maiorGasto << " EUR" << endl;
			cout << "=========================================" << endl;
		}
		
		else 
		{
			cout << "Erro: Cliente com ID " << idClienteMaisGastou << " não encontrado." << endl;
		}
	}
		else 
		{
			cout << "Nenhum cliente encontrado com compras registradas." << endl;
		}
}

void Loja::relatorioVendasPorProduto() 
{
	while (true) 
	{
		string nomeProduto;
		cout << "Introduza o nome do produto (ou 0 para sair): ";
		getline(cin >> ws, nomeProduto); // ws para ignorar espaços anteriores

		// Opção de saída
		if (nomeProduto == "0") 
		{
			cout << "A sair do relatório de vendas por produto...\n";
			break;
		}

		// Converter para lowercase
		string nomeProdutoLower = nomeProduto;
		transform(nomeProdutoLower.begin(), nomeProdutoLower.end(), nomeProdutoLower.begin(), ::tolower);

		bool encontrou = false;
		double totalProduto = 0.0;
		int totalQuantidade = 0;

		cout << "\n=== Relatório de Vendas para o Produto \"" << nomeProduto << "\" ===\n\n";

		for (int i = 0; i < contadorVenda; ++i) 
		{
			string produtosTal = Taloes[i].getNomeProduto();
			string produtosTalLower = produtosTal;
			transform(produtosTalLower.begin(), produtosTalLower.end(), produtosTalLower.begin(), ::tolower);

			if (produtosTalLower.find(nomeProdutoLower) != string::npos) 
			{
				encontrou = true;

				cout << "--------------------------------------\n";
				cout << " Fatura Nº:      " << Taloes[i].getNumFatura() << endl;
				cout << " Cliente Nº:     " << Taloes[i].getNumCliente() << endl;
				cout << " Produto(s):     " << Taloes[i].getNomeProduto();
				cout << "\n Quantidade:     " << Taloes[i].getQuantidade() << " unid.\n";

				cout << fixed << setprecision(2);
				cout << " Total (s/IVA):  " << Taloes[i].getPrecoSemIVA() << " EUR\n";
				cout << " IVA:            " << Taloes[i].getTaxaIVA() << "%\n";
				cout << " Total (c/IVA):  " << Taloes[i].getPrecoSemIVA() * 1.23 << " EUR\n";
				cout << " Valor Entregue: " << Taloes[i].getValorEntregue() << " EUR\n";
				cout << " Troco:          " << Taloes[i].getValorEntregue() - Taloes[i].getPrecoSemIVA() * 1.23 << " EUR\n";

				totalProduto += Taloes[i].getPrecoSemIVA() * 1.23;
				totalQuantidade += Taloes[i].getQuantidade();
			}
		}

		if (!encontrou) 
		{
			cout << "\nNenhuma venda encontrada para o produto \"" << nomeProduto << "\".\n";
			cout << "Tente novamente ou insira 0 para sair.\n\n";
		}
			else 
			{
				cout << "======================================\n";
				cout << " Total Vendido (" << nomeProduto << "):\n";
				cout << " Quantidade Total: " << totalQuantidade << " unidades\n";
				cout << " Faturado (c/IVA): " << fixed << setprecision(2) << totalProduto << " EUR\n";
				cout << endl;
				system("pause");
				break; // Sai do loop depois de encontrar
			}
	}
}



void Loja::imprimirTalao(int numero_cliente, const string& produtosVendidos, double valor_sIVA, double valor_total, double valor_entregue, double troco) {
	int contadorTaloes = 5; // Inicializando contadorTaloes com 0 para esta função

	// Calculando o número da fatura
	int numFatura = contadorTaloes + 1;

	// Obtém a data e hora atuais
	time_t t = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &t);

	char buffer[50];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeinfo); // Formata a data


	cout << "\033[47m\033[30m";

	// Formatação para o talão
	cout << "----------------------------------------\n";
	cout << "         *** TALÃO DE COMPRA ***        \n";
	cout << "----------------------------------------\n";
	cout << " Data: " << buffer << "              " <<endl;
	cout << " Nº Fatura: " << setw(8) << numFatura << "                    " << endl; // Fatura com zeros à esquerda
	cout << " Nº Cliente: " << numero_cliente << "                         " << endl;
	cout << "----------------------------------------\n";
	 
	// Exibe os produtos vendidos
	
	cout << "Produtos vendidos:" << "                      " << endl
		<< fixed << setprecision(2) << produtosVendidos.substr(0, 40) << endl;  // Primeira linha
	
	
	cout << "----------------------------------------\n";

	// Exibe valores com formatação adequada
	cout << fixed << setprecision(2);
	cout << " Total (s/IVA): " << setw(10) << right << fixed << setprecision(2) << valor_sIVA << " EUR          \n";
	cout << " IVA (23%):     " << setw(10) << right << fixed << setprecision(2) << (valor_total - valor_sIVA) << " EUR          \n";
	cout << "----------------------------------------\n";
	cout << " Total (c/IVA): " << setw(10) << right << fixed << setprecision(2) << valor_total << " EUR          \n";
	cout << " Valor Entregue: " << setw(10) << right << fixed << setprecision(2) << valor_entregue << " EUR         \n";
	cout << " Troco:          " << setw(10) << right << fixed << setprecision(2) << troco << " EUR         \n";
	


	// Finalizando o talão
	cout << "----------------------------------------\n";
	cout << "     *** Obrigado pela compra! ***      \n";
	cout << "----------------------------------------\n";

	cout << "\033[0m" << endl;
	
	contadorTaloes++; // Incrementa contador de talões
	system("pause");    // Limpa a tela (opcional)
}

void Loja::efetuarVenda()
{
	char check;
	int numero_cliente;
	int numero_fatura = contadorVenda + 1; // Número da fatura

	// Loop até o número do cliente ser válido ou 0 para sair
	while (true)
	{
		cout << "Numero do Cliente (ou pressione 0 para voltar ao menu): ";
		cin >> numero_cliente;

		if (cin.fail())
		{ // Verifica se a entrada não é um número válido
			cin.clear(); // Limpa o estado de erro do cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada
			system("cls");
			cout << "Entrada invalida. Tente novamente!\n";
		}
			else if (numero_cliente == 0)
			{
				system("cls");
				return; // Sai para o menu
			}
				else if (numero_cliente < 0)
				{
					system("cls");
					cout << "Numero de cliente não pode ser negativo. Tente novamente.\n";
				}
					else if (procurarCliente(numero_cliente) == -1)
					{ // Verifica se o cliente existe
						system("cls");
						cout << "Cliente não encontrado. Deseja criar novo cliente? (S/N)  \n";
						cin >> check;
						if (check == 'S' || check == 's')
						{
								criarCliente();
								cout << endl;
								break;
						}
							else
							{
								return;
							}
					}
		else
		{
			break; // Sai do loop quando o número do cliente for válido
		}
	}

	double valor_total = 0;
	double valor_sIVA = 0;
	double valor_entregue, troco;
	string produtosVendidos; // String para armazenar os produtos vendidos
	bool continua = true;
	int quantidade;

	do 
	{
		imprimeStock(); // Mostra o stock disponível
		int idProduto;

		// Loop até o ID ser válido ou 0 para voltar ao menu
		while (true)
		{
			cout << endl << endl << "ID do produto (ou digite '0' para finalizar a venda): ";
			cin >> idProduto;

			if (cin.fail())
			{ // Verifica se a entrada não é um número válido
				cin.clear(); // Limpa o estado de erro do cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada
				cout << "ID invalido. Tente novamente.\n";
				continue;
			}

			if (idProduto < 0)
			{ // Verifica se o ID é negativo
				cout << "ID invalido. Tente novamente.\n";
				continue;
			}

			if (idProduto == 0)
			{
				return;  // Retorna ao menu se o usuário digitar '0'
			}

			int posicao = procurarProduto(idProduto);
			if (posicao == -1)
			{ // Produto não encontrado
				cout << "Produto não encontrado. Tente novamente ou digite '0' para voltar ao menu.\n";
				continue;
			}

			// Se chegou aqui, o ID é válido
			break;
		}

		int posicao = procurarProduto(idProduto);

		if (idProduto == 0)
		{
			break;  // Finaliza a venda se o ID for 0
		}

		// Loop para garantir que a quantidade seja válida ou 0 para voltar atrás
		while (true)
		{
			cout << "Quantidade (ou digite '0' para voltar atrás): ";
			cin >> quantidade;

			if (cin.fail())
			{ // Verifica se a entrada não é um número válido
				cin.clear(); // Limpa o estado de erro do cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada
				cout << "Quantidade invalida. Tente novamente.\n";
				continue;
			}

			if (quantidade < 0)
			{ // Verifica se a quantidade é negativa
				cout << "Quantidade não pode ser negativa. Tente novamente.\n";
				continue;
			}

			if (quantidade == 0)
			{ // Se quantidade for 0, volta atrás
				cout << "Voltando ao menu...\n";
				return;  // Volta para o menu ou encerra a função
			}

			if (quantidade > Stock[posicao].getquantidadeProduto())
			{ // Verifica se a quantidade é maior do que o stock disponível
				cout << "Quantidade insuficiente em stock. Tente novamente.\n";
				continue;
			}

			// Se chegou aqui, a quantidade é válida
			break;
		}

		// Atualiza o stock e calcula os valores
		Stock[posicao].setquantidadeProduto(Stock[posicao].getquantidadeProduto() - quantidade);
		double precoVenda = Stock[posicao].getprecoVenda();
		double totalItem = precoVenda * quantidade;
		valor_total += totalItem;
		valor_sIVA += totalItem / 1.23; // Calcula o valor sem IVA

		int totalprevenda = Stock[posicao].getquantidadeComprada();
		int totalposvenda = totalprevenda + quantidade;
		Stock[posicao].setquantidadeComprada(totalposvenda);

		// ======== CÁLCULO DO LUCRO ========
		double precoCompra = precoVenda / (1.30 * 1.23);
		double lucro = precoVenda - precoCompra;           // Calcula o lucro unitário
		double lucroTotalProduto = lucro * quantidade;     // Calcula o lucro total do produto

		// Atualiza o lucro total do produto no stock
		double lucroAtual = Stock[posicao].getLucro();  // Obtém o lucro atual do produto
		Stock[posicao].setLucro(lucroAtual + lucroTotalProduto);  // Atualiza o lucro total
		// ==================================

		// Adiciona o produto vendido à string de produtos vendidos
		ostringstream ss;
		ss << fixed << setprecision(2) << precoVenda;
		string precoFormatado = ss.str();

		produtosVendidos += "  " + Stock[posicao].getnomeProduto() + " - " +
			to_string(quantidade) + " unid. - " + precoFormatado + " EUR/unid.\n";

		// Pergunta se o usuário deseja adicionar mais produtos
		char resposta;
		cout << "Deseja adicionar mais produtos? (s/n): ";
		cin >> resposta;
		if (resposta == 'n' || resposta == 'N')
		{
			continua = false;
		}

	} while (continua);

	if (valor_total == 0)
	{
		cout << "Nenhum produto vendido. Voltar ao menu...\n";
		return;
	}

	bool vendaGratuita = (rand() % 5 == 0);

	if (vendaGratuita)
	{
		cout << "PARABÉNS!   ESTA COMPRA É GRATUITA!" << endl;
		system("pause");
		valor_total = 0.0; // Zerar o valor total
	}

	// Resumo de venda
	system("cls");

	time_t t = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &t);

	char buffer[50];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeinfo); // Formata a data

	cout << " --- Resumo de Venda ---" << endl << endl;
	cout << "Data: " << buffer << endl << endl;
	cout << "Produtos: " << produtosVendidos << endl;
	cout << "Total s/IVA: " << fixed << setprecision(2) << valor_sIVA << " EUR" << endl;
	cout << "IVA (23%): " << fixed << setprecision(2) << (valor_total - valor_sIVA) << " EUR" << endl;
	cout << "Total c/IVA: " << fixed << setprecision(2) << valor_total << " EUR" << endl << endl;
	cout << endl;

	if (vendaGratuita) 
	{
		cout << "!!!!! VENDA GRATUITA! O CLIENTE NÃO PAGA !!!!!!!!" << endl;
		return;  // Se for venda gratuita, saímos da função aqui sem mais pausas
	}

	cout << "Valor entregue: ";
	valor_entregue = Auxiliar::getValidNumber();

	while (cin.fail() || valor_entregue < valor_total)
	{
		cin.clear(); // Limpa o estado de erro do cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da entrada
		cout << "Valor insuficiente. Insira um valor maior ou igual a " << valor_total << " EUR: ";
		cin >> valor_entregue;
	}

	troco = valor_entregue - valor_total;

	// Agora vamos armazenar os dados no vetor 'Taloes'
	if (contadorVenda < 100) 
	{
		// Armazenar a venda utilizando o setQuantidade()
		Taloes[contadorVenda] = Venda(numero_fatura, numero_cliente, contadorVenda + 1, produtosVendidos,
			0, valor_sIVA, 23.0, valor_entregue);

		// Agora vamos usar o setter para a quantidade
		Taloes[contadorVenda].setQuantidade(quantidade);  // Chama o setter para quantidade

		Taloes[contadorVenda].setvalorTotal(valor_total);

		// Incrementando o contador para a próxima venda
		contadorVenda++;
	}
		else 
		{
			cout << "Limite de vendas alcançado. Não é possível registrar mais vendas.\n";
		}

	// Imprime o talão de compra
	system("cls");
	imprimirTalao(numero_cliente, produtosVendidos, valor_sIVA, valor_total, valor_entregue, troco);

	return;
}

void Loja::mostrarVendas() 
{
	if (contadorVenda == 0) 
	{
		cout << "Nenhuma venda registrada.\n";
		system("pause");  // Pausa para o usuário ver a mensagem antes de continuar
		return;
	}

	
	for (int i = 0; i < contadorVenda; i++) 
	{
		cout << "Fatura: " << Taloes[i].getNumFatura() << endl;
		cout << "Cliente: " << Taloes[i].getNumCliente() << endl;
		cout << "Produto: " << Taloes[i].getNomeProduto() << endl;
		cout << "Quantidade: " << Taloes[i].getQuantidade() << endl;
		cout << "Preço Sem IVA: " << fixed << setprecision(2)<< Taloes[i].getPrecoSemIVA() << endl;
		cout << "IVA: " << fixed << setprecision(3) <<  Taloes[i].getTaxaIVA() << "%" << endl;
		cout << "Total com IVA: " << fixed << setprecision(2) << Taloes[i].getPrecoSemIVA()*1.23 << " EUR" << endl;
		cout << "Valor entregue: " << fixed << setprecision(2) << Taloes[i].getValorEntregue() << endl;
		cout << "Troco: " << Taloes[i].getValorEntregue() - Taloes[i].getPrecoSemIVA() * 1.23 << endl;
		cout << "--------------------------\n";
	}

}



void Loja::MenuPrincipal()
{
	
	int opcao;
	do {
		system("cls");
		cout << "=====================================\n";
		cout << "              \033[33mChipStore\033[0m"; 
		cout << "\n=====================================\n";
		cout << endl;
		cout << "1. Gerir Stock\n";
		cout << "2. Gerir Clientes\n";
		cout << "3. Efetuar venda\n";
		cout << "4. Relatórios\n";
		cout << "5. Sair\n";
		cout << endl;
		cout << "=====================================\n";

		// Verificar se a entrada é válida
		cout << "Escolha uma opção: ";
		while (!(cin >> opcao)) 
		{
			cin.clear();  // Limpar o estado de erro
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpar o buffer
			cout << "Entrada inválida! Por favor, insira um número válido: ";
		}

		if (opcao == 0) 
		{
			cout << "Voltando ao menu principal...\n";
			break;  // Sai do loop e volta ao menu principal
		}

		switch (opcao) 
		{
		case 1:
			gerirStock();  // Chama a função para gerir stock
			break;

		case 2:
			system("cls");
			gerirClientes();
			break;

		case 3:
			gerirVendas();
			break;

			case 4:
			gerarRelatorios();
			 break;

		case 5:
			cout << "\nSair do programa.\n";
			break;

		default:
			cout << "\nOpção inválida! Tente novamente.\n";
		}
	} while (opcao != 5);
}

void Loja::gerirStock()
{
	int opcao;
	do
	{
		system("cls");
		cout << "=====================================\n";
		cout << "              \033[33mChipStore\033[0m";
		cout << "\n=====================================\n";
		cout << endl;
		cout << "1. Mostrar Stock\n";
		cout << "2. Adicionar Novo Produto ou Quantidade\n";
		cout << "3. Remover Produto ou Quantidade\n";
		cout << "4. Voltar ao Menu Principal\n";
		cout << endl;
		cout << "=====================================\n";
		cout << "Escolhe uma opção (digite '0' para voltar a qualquer momento): ";

		// Verificar se a entrada é válida
		while (!(cin >> opcao)) 
		{
			cin.clear();  // Limpar o estado de erro
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpar o buffer
			cout << "Entrada inválida! Por favor, insira um número válido: ";
		}

		// Se o usuário digitar '0', retorna ao menu principal
		if (opcao == 0)
		{
			cout << "Voltando ao menu principal...\n";
			break;  // Sai do loop e volta ao menu principal
		}

		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");

		switch (opcao)
		{
		case 1:
			imprimeStock(); // Exibe o stock
			cout << "Pressiona qualquer tecla e enter para voltar ao menu:\n ";
			cin.ignore(); // Limpa o buffer de entrada
			cin.get(); // Espera o usuário pressionar uma tecla para continuar
			break;

		case 2:
			system("cls");
			imprimeStock();
			adicionarQuantidadeouProduto(); // Chama a função para adicionar ou atualizar produto
			break;

		case 3:
			system("cls");
			imprimeStock();
			removerQuantidadeouProduto(); // Chama a função para remover ou atualizar produto
			break;

		case 4:
			cout << "\nSair para o Menu Principal...\n";
			break;

		default:
			cout << "\nOpção inválida! Tente novamente.\n";
		}

	} while (opcao != 4);
}

void Loja::gerirClientes()
{
	int opcao;
	do
	{
		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");
		cout << "=====================================\n";
		cout << "              \033[33mChipStore\033[0m";
		cout << "\n=====================================\n";
		cout << endl;
		cout << "1. Mostrar Clientes\n";
		cout << "2. Criar Cliente\n";
		cout << "3. Alterar nome Cliente\n";
		cout << "4. Eliminar Cliente\n";
		cout << "5. Voltar ao Menu Principal\n";
		cout << endl;
		cout << "=====================================\n";
		cout << "Escolhe uma opção (digite '0' para voltar a qualquer momento): ";

		// Verificar se a entrada é válida
		while (!(cin >> opcao)) 
		{
			cin.clear();  // Limpar o estado de erro
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpar o buffer
			cout << "Entrada inválida! Por favor, insira um número válido: ";
		}

		// Se o usuário digitar '0', retorna ao menu principal
		if (opcao == 0) 
		{
			cout << "Voltando ao menu principal...\n";
			break;  // Sai do loop e volta ao menu principal
		}

		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");

		// Realiza a ação de acordo com a opção escolhida
		switch (opcao)
		{
		case 1:
			imprimePovo(); // Exibe a lista de clientes
			system("pause");
			break;

		case 2:
			system("cls");
			criarCliente(); // Chama a função para criar um novo cliente
			break;

		case 3:
			system("cls");
			imprimePovo();
			alteraCliente(); // Chama a função para alterar o nome de um cliente
			break;

		case 4:
			system("cls");
			imprimePovo();
			eliminarCliente(); // Chama a função para eliminar um cliente
			break;

		case 5:
			cout << "\nSair para o Menu Principal...\n";
			break;

		default:
			cout << "\nOpção inválida! Tente novamente.\n";
		}

	} while (opcao != 5);
}

void Loja::gerirVendas()
{
	int opcao;
	do
	{
		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");
		cout << "=====================================\n";
		cout << "              \033[33mChipStore\033[0m";
		cout << "\n=====================================\n";
		cout << endl;
		cout << "1. Realizar venda\n";
		cout << "2. Mostrar Vendas\n";
		cout << "3. Voltar ao Menu Principal\n";
		cout << endl;
		cout << "=====================================\n";
		cout << "Escolhe uma opção (digite '0' para voltar a qualquer momento): ";
		

		// Verificar se a entrada é válida
		while (!(cin >> opcao)) {
			cin.clear();  // Limpar o estado de erro
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpar o buffer
			cout << "Entrada inválida! Por favor, insira um número válido: ";
		}

		// Se o usuário digitar '0', retorna ao menu principal
		if (opcao == 0) {
			cout << "Voltando ao menu principal...\n";
			break;  // Sai do loop e volta ao menu principal
		}

		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");

		// Realiza a ação de acordo com a opção escolhida
		switch (opcao)
		{
		case 1:
			imprimePovo();
			efetuarVenda(); // Chama a função para realizar uma venda
			break;

		case 2:
			mostrarVendas(); // Chama a função para mostrar as vendas
			cout << "Pressiona qualquer tecla e enter para voltar ao menu:\n ";
			system("pause");
			break;

		case 3:
			
cout << "\nSair para o Menu Principal...\n";
			break;

		default:
			cout << "\nOpção inválida! Tente novamente.\n";
		}

	} while (opcao != 3);
}

void Loja::gerarRelatorios()
{
	int opcao;
	do
	{
		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");
		cout << "=====================================\n";
		cout << "              \033[33mChipStore\033[0m";
		cout << "\n=====================================\n";
		cout << endl;
		cout << "1. Relatório de stock atual\n";
		cout << "2. Relatório de vendas por produto\n";
		cout << "3. Relatório de vendas geral\n";
		cout << "4. Relatório Mais/Menos Vendidos\n";
		cout << endl;
		cout << "=====================================\n";
		cout << "Escolhe uma opção (digite '0' para voltar a qualquer momento): ";

		// Verificação da entrada do usuário
		opcao = Auxiliar::getValidNumber();

		// Se o usuário digitar '0', retorna ao menu principal
		if (opcao == 0) 
		{
			cout << "Voltando ao menu principal...\n";
			break;  // Sai do loop e volta ao menu principal
		}

		// Limpar a tela a cada vez que uma opção é escolhida
		system("cls");

		// Realiza a ação de acordo com a opção escolhida
		switch (opcao)
		{
			case 1:
			imprimeStock(); // Exibe o relatório do stock atual
			system("pause");
			break;

			case 2:
			imprimeStock();
			relatorioVendasPorProduto();
			break;

			case 3:
			mostrarVendas(); // Exibe o relatório das vendas
			system("pause");
			break;

			case 4:
			produtoMaisVendido(); // Exibe o relatório do produto mais vendido
			cout << endl << endl;

			produtoMenosVendido();
			cout << endl << endl;

			clienteQueMaisComprou();
			system("pause");

			default:
				cout << "\nOpção inválida! Tente novamente.\n";
		}

	} while (opcao != 4);  // Continua até que o usuário decida voltar ao menu
}

