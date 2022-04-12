#pragma once

#include "IMapa.h"
#include <iostream>
#include <fstream>

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

	}
	void ExibirMatriz() override
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
	void ExibirElementos() override
	{

	}
	~Mapa()
	{
		delete[] caracteres;
		delete[] visitadas;
		caracteres = nullptr;
		visitadas = nullptr;
	}
private:
	int linhas = 0;
	int colunas = 0;
	char* caracteres = nullptr;
	bool* visitadas = nullptr;
};