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
	//bool Equals(const Elemento& rhs){} Não se se precisa implementar
	void ToString()
	{
		std::cout << nome << " (" << caractere << ") que tem " << unidades << " unidade(s)" << std::endl;
	}
private:
	friend class Mapa;
	Elemento() = default;
private:
	char caractere;
	std::string nome;
	int unidades;
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