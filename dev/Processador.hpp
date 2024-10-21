#include <iostream>
#include <math.h>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

// converte um binario para inteiro (considera o sinal)
long conversorBinInteiro(bitset<32> bin)
{

    long resultado = 0;
    long potencia = 1;
    bool ehNeg = false;

    // negativo
    if (bin[32 - 1] == 1)
    {

        ehNeg = true;

        // invertido
        bitset<32> invertido = ~bin;

        // invertido + 1
        bool carry;
        bitset<32> inc(1);
        bitset<32> sum;

        for (int i = 0; i < 32; i++)
        {

            sum[i] = invertido[i] ^ inc[i] ^ carry;
            carry = (invertido[i] & inc[i]) | (carry & (invertido[i] ^ inc[i]));
        }

        bin = sum;
    }

    // conversão
    for (int i = 0; i <= 32 - 1; i++)
    {

        if (bin[i] == 1)
        {
            resultado += potencia;
        }

        potencia *= 2;
    }

    if (ehNeg)
    {
        resultado *= -1;
    }

    return resultado;
}

#include "Conversor.hpp"
#include "Registradores.hpp"
#include "If-Id.hpp"
#include "ExeM.hpp"
#include "Wb.hpp"

class Processador
{

private:
    Conversor *conversor;
    Registradores *regs;
    If *ifStage;
    Id *idStage;
    ExMem *exMemStage;
    Wb *wbStage;
    int quant_clock;
    void incrementarClock();

public:
    Processador();
    ~Processador();
    void executar();
};

Processador::Processador()
{

    try
    {
        conversor = new Conversor();
        regs = new Registradores();
    }
    catch (string erro)
    {
        throw(erro);
    }

    quant_clock = 0;
}

Processador::~Processador()
{

    delete conversor;
    delete regs;
}

void Processador::executar()
{

    bool processando = true;

    try
    {
        bitset<16> PC(conversor->getEnderecoComecoMemmoriaTexto());
        Memoria *memoria = conversor->getMemoria();
        ifStage = new If(memoria, PC);

        cin.ignore();

        // Loop principal do processador
        while (processando)
        {

            // estágio if
            bitset<32> instrucaoAtual = ifStage->getInstrucao();
            incrementarClock();

            cout << "Bits da instrução atual: " << instrucaoAtual << endl;

            regs->depuracao();

            // estágio id
            idStage = new Id(instrucaoAtual, regs);
            idStage->depuracao();
            incrementarClock();

            // estágio ex/mem
            exMemStage = new ExMem(regs, ifStage, idStage, idStage->getControle(), memoria);
            processando = exMemStage->getAlu()->getHalt();
            exMemStage->getAlu()->mostrarFlags();
            incrementarClock();

            // estágio wb
            wbStage = new Wb(regs, idStage, idStage->getControle(), exMemStage->getAlu(), memoria);
            incrementarClock();

            delete idStage;
            delete exMemStage;
            delete wbStage;

            cout << endl;
            cout << "Número de clocks " << quant_clock << endl;

            cout << " ------------------------------ Instrucao Finalizada --------------------------------------------" << endl
                 << endl;

            cout << "Pressione ENTER para a próxima instrução . . . ";
            cin.get();
        }

        delete ifStage;
    }
    catch (string erro)
    {
        throw(erro);
    }
}

void Processador::incrementarClock()
{

    quant_clock++;
}
