#pragma once

#include <iostream>
#include <fstream>
#include "IMapa.h"
#include "Elemento.h"

struct PosArray
{
	int linha = -1;
	int coluna = -1;
};

class Mapa : public IMapa
{
public:
	Mapa() = default;
	Mapa(const Mapa& mapa) = delete;
	Mapa& operator =(Mapa mapa) = delete;
	void CarregarMapa(const std::string& nomeArquivo) override
	{
		std::ifstream file(nomeArquivo);
		if (file.is_open())
		{
			std::string line;
			std::getline(file, line);
			auto pos = line.find_first_of(" ");
			std::string strL = line.substr(0, pos);
			std::string strC = line.substr(++pos, line.find_first_of(" "));

			linhas = std::stoi(strL);
			colunas = std::stoi(strC);

			caracteres = new char[linhas * colunas];
			visitadas = new bool[linhas * colunas];

			for (int i = 0; i < linhas; i++)
			{
				for (int j = 0; j < colunas; j++)
				{
					caracteres[i * colunas + j] = file.get();
					(caracteres[i * colunas + j] == '\n') ? j-- : j;
					visitadas[i * colunas + j] = false;
				}
			}
			file.close();
		}
		else
		{
			std::cout << "Arquivo de mapa nao encontrado." << std::endl;
		}
	}
	void Reconhecer() override
	{
		elementos = new Elemento[linhas * colunas];
		auto pos = ProximaNaoVisitada();
		do
		{
			if (pos.linha != -1 && pos.coluna != -1)
			{
				char tipoElemento = caracteres[pos.linha * colunas + pos.coluna];

				int nUnidades = ReconhecerRecursiva(tipoElemento, pos.linha, pos.coluna);

				AdicionarElemento(tipoElemento, nUnidades);
			}

			pos = ProximaNaoVisitada();
		} while (pos.linha != -1 && pos.coluna != -1);
	}
	void ExibirMatriz() const override
	{
		for (int i = 0; i < linhas; i++)
		{
			for (int j = 0; j < colunas; j++)
			{
				std::cout << caracteres[i * colunas + j];
			}
			std::cout << std::endl;
		}
	}
	void ExibirElementos() const override
	{
		std::cout << "Relatorio do Reconhecimento" << std::endl;
		std::cout << "===========================" << std::endl;
		
		for (int i = 0; i < nElementos; i++)
		{
			elementos[i].ToString();
		}
	}
	~Mapa()
	{
		delete[] caracteres;
		delete[] visitadas;
		delete[] elementos;
		caracteres = nullptr;
		visitadas = nullptr;
		elementos = nullptr;
	}
private:
	const PosArray& ProximaNaoVisitada() const
	{
		PosArray naoVisitada;
		for (int i = 0; i < linhas; i++)
		{
			for (int j = 0; j < colunas; j++)
			{
				if (visitadas[i * colunas + j] == false)
				{
					naoVisitada = { i , j };
					return naoVisitada;
				}
			}
		}
		return naoVisitada;
	}
	int ReconhecerRecursiva(char tipoElemento, int linha, int coluna)
	{
		int pos = linha * colunas + coluna;
		if (linha >= 0 && coluna >= 0 &&
			linha < linhas && coluna < colunas &&
			caracteres[pos] == tipoElemento &&
			visitadas[pos] == false)
		{
			visitadas[pos] = true;
			return { 1 +
				ReconhecerRecursiva(tipoElemento, linha - 1, coluna) +
				ReconhecerRecursiva(tipoElemento, linha + 1, coluna) +
				ReconhecerRecursiva(tipoElemento, linha, coluna - 1) +
				ReconhecerRecursiva(tipoElemento, linha, coluna + 1) };
		}

		return 0;
	}
	void AdicionarElemento(char caractere, int nUnidades)
	{
		switch (caractere)
		{
			case '*':
				elementos[nElementos++] = Agua(caractere, "Agua", nUnidades);
				break;
			case '+':
				elementos[nElementos++] = Arvore(caractere, "Arvore", nUnidades);
				break;
			case ' ':
				elementos[nElementos++] = Campo(caractere, "Campo", nUnidades);
				break;
			case '=':
				elementos[nElementos++] = Cerca(caractere, "Cerca", nUnidades);
				break;
			case '/':
				elementos[nElementos++] = Edificacao(caractere, "Edificacao", nUnidades);
				break;
			default:
				break;
		}
	}
private:
	int linhas = 0;
	int colunas = 0;
	char* caracteres = nullptr;
	bool* visitadas = nullptr;
	Elemento* elementos = nullptr;
	int nElementos = 0;
};