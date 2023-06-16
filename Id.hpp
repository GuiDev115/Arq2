#include "Controle.hpp"

class Id
{

private:
    bitset<8> ra;
    bitset<8> rb;
    bitset<8> rc;

    Controle *sinaisControle;
    Registradores *regs;

    bitset<8> opcode;

    bitset<32> raValue;
    bitset<32> rbValue;
    bitset<32> rcValue;

    bitset<8> bit8;
    bitset<16> bit16;
    bitset<24> bit24;

    void reset_valores();
    void decodificarInstrucao(bitset<32> instrucaoBinaria);
    bool verificarRegistrador(string textoBin);

public:
    Id(bitset<32> instrucaoBinaria, Registradores *regs);
    ~Id();
    bitset<8> getOpcode() { return opcode; };
    bitset<8> getRa() { return ra; };
    bitset<32> getRaValue() { return raValue; };
    bitset<8> getRb() { return rb; };
    bitset<32> getRbValue() { return rbValue; };
    bitset<8> getRc() { return rc; };
    bitset<32> getRcValue() { return rcValue; };
    bitset<16> getbit16() { return bit16; };
    bitset<24> getbit24() { return bit24; };
    bitset<8> getbit8() { return bit8; };
    Controle *getControle() { return sinaisControle; };
    void depuracao();
};

Id::Id(bitset<32> instrucaoBinaria, Registradores *regs)
{

    reset_valores();
    this->regs = regs;
    decodificarInstrucao(instrucaoBinaria);
}

Id::~Id()
{

    delete sinaisControle;
}

void Id::reset_valores()
{

    opcode.reset();
    ra = -1;
    raValue.reset();
    rb = -1;
    rbValue.reset();
    rc = -1;
    rcValue.reset();
    bit8.reset();
    bit16.reset();
    bit24.reset();
}

void Id::decodificarInstrucao(bitset<32> instrucaoBinaria)
{

    string instrucaoString = instrucaoBinaria.to_string(); // instrucao 32 bits em string
    string texto_Binario_Auxiliar;

    string auxOpcode = instrucaoString.substr(0, 8); // opcode string pra ser comparado na classe Controle
    opcode = bitset<8>(auxOpcode);
    sinaisControle = new Controle(auxOpcode); // enviando o opcode para a classe controle, para configurar os sinais das flags

    texto_Binario_Auxiliar = instrucaoString.substr(8, 8); // extrai os 8 bits do primeiro operando (ra)
    if (verificarRegistrador(texto_Binario_Auxiliar))
    {
        ra = bitset<8>(texto_Binario_Auxiliar);
        raValue = regs->getRegistrador(ra);
    }

    texto_Binario_Auxiliar = instrucaoString.substr(16, 8); // extrai os 8 bits do segundo operando (rb)
    if (verificarRegistrador(texto_Binario_Auxiliar))
    {
        rb = bitset<8>(texto_Binario_Auxiliar);
        rbValue = regs->getRegistrador(rb);
    }

    texto_Binario_Auxiliar = instrucaoString.substr(24, 8); // extrai os 8 bits do terceiro operando (rc)
    if (verificarRegistrador(texto_Binario_Auxiliar))
    {
        rc = bitset<8>(texto_Binario_Auxiliar);
        rcValue = regs->getRegistrador(rc);
    }

    // extrai os bits de cada constante
    texto_Binario_Auxiliar = instrucaoString.substr(24, 8);
    bit8 = bitset<8>(texto_Binario_Auxiliar);

    texto_Binario_Auxiliar = instrucaoString.substr(8, 16);
    bit16 = bitset<16>(texto_Binario_Auxiliar);

    texto_Binario_Auxiliar = instrucaoString.substr(8, 24);
    bit24 = bitset<24>(texto_Binario_Auxiliar);
}

bool Id::verificarRegistrador(string textoBin)
{

    int resultado = 0;
    int potencia_dois = 1;

    for (int i = textoBin.size() - 1; i >= 0; i--)
    {

        if (textoBin[i] == '1')
        {
            resultado += potencia_dois;
        }
        potencia_dois *= 2;
    }

    if (resultado >= 0 and resultado <= 31)
    {
        return true;
    }

    return false;
}

void Id::depuracao()
{

    cout << "Valores das variáveis do Id: " << endl;
    cout << "\tOpcode: " << opcode << endl;
    cout << "\tRa (endereço): " << ra.to_ulong() << endl;
    cout << "\tRb (endereço): " << rb.to_ulong() << endl;
    cout << "\tRc (endereço): " << rc.to_ulong() << endl;
    cout << "\tbit8 : " << bit8 << endl;
    cout << "\tbit16: " << bit16 << endl;
    cout << "\tbit24: " << bit24 << endl
         << endl;

    sinaisControle->depuracao_controle();
}
