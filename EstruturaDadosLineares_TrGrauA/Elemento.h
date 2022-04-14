#pragma once

#include <string>

class Elemento
{
public:
	Elemento(char caractere, const std::string& nome, int unidades)
		:
		caractere(caractere),
		nome(nome),
		unidades(unidades)
	{};
	std::string ToString() const
	{
		return std::string(nome + " (" + caractere + ") que tem " + std::to_string(unidades) + " unidade(s)");
	}
private:
	friend class Mapa;
	Elemento() = default;
private:
	char caractere = 0;
	std::string nome = "";
	int unidades = 0;
};

class Agua : public Elemento
{
public:
	Agua(char caractere, const std::string& nome, int unidades)
		:
		Elemento(caractere, nome, unidades)
	{}
};

class Arvore : public Elemento
{
public:
	Arvore(char caractere, const std::string& nome, int unidades)
		:
		Elemento(caractere, nome, unidades)
	{}
};

class Campo : public Elemento
{
public:
	Campo(char caractere, const std::string& nome, int unidades)
		:
		Elemento(caractere, nome, unidades)
	{}
};

class Cerca : public Elemento
{
public:
	Cerca(char caractere, const std::string& nome, int unidades)
		:
		Elemento(caractere, nome, unidades)
	{}
};

class Edificacao : public Elemento
{
public:
	Edificacao(char caractere, const std::string& nome, int unidades)
		:
		Elemento(caractere, nome, unidades)
	{}
};