#include "Processador.hpp"
using namespace std;

int main()
{

    Processador *uflaRisc = NULL;

    uflaRisc = new Processador();

    uflaRisc->executar();

    delete uflaRisc;

    return 0;
}