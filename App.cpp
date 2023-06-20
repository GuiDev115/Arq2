#include "Processador.hpp"
using namespace std;

int main()
{
    // try
    // {
    Processador *uflaRisc = NULL;

    uflaRisc = new Processador();

    uflaRisc->executar();

    delete uflaRisc;
    // }
    // catch (string erro)
    // {
    //     cout << "Erro: " << erro << endl;
    // }

    return 0;
}