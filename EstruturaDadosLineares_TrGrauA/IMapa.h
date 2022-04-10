#pragma once

#include <string>

class IMapa
{
public:
	virtual void CarregarMapa(const std::string& nomeArquivo) = 0;
	virtual void Reconhecer() = 0;
	virtual void ExibirMatriz() = 0;
	virtual void ExibirElementos() = 0;
};