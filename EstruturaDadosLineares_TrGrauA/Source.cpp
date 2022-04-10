
#include "Mapa.h"

int main()
{
	Mapa mapa;

	mapa.CarregarMapa("ARQUIVO DO MAPA.txt");
	mapa.ExibirMatriz();
	mapa.Reconhecer();
	mapa.ExibirElementos();

	return 1;
}