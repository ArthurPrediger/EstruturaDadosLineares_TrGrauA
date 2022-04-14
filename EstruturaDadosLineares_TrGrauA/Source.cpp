
#include "Mapa.h"

class MapaTest
{
public:
	static void Teste()
	{
		Mapa mapa;

		try
		{
			mapa.CarregarMapa("ARQUIVO DO MAPA.txt");
		}
		catch (const std::ifstream::failure& e)
		{
			std::cout << e.what() << std::endl;
		}
		mapa.ExibirMatriz();
		mapa.Reconhecer();
		mapa.ExibirElementos();
	}
};

int main()
{
	MapaTest::Teste();

	return 1;
}