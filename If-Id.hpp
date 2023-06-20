class If
{

public:
    bitset<16> PC;
    bitset<32> instruçãoReg;
    bitset<32> getInstrucao();
    bitset<16> getPc();
    void incrementaPC();
    void branchPC(bitset<16> PC);
    Memoria *memoria;

    If(Memoria *mem, bitset<16> PC);
};

If::If(Memoria *mem, bitset<16> PC)
{

    this->memoria = mem;
    this->PC = PC;
}

bitset<32> If::getInstrucao()
{

    instruçãoReg = memoria->getInstrucao(PC);
    incrementaPC();

    return instruçãoReg;
}

void If::incrementaPC()
{

    bool carry = false;
    bitset<16> inc(1);
    bitset<16> sum;

    for (int i = 0; i < 16; i++)
    {
        bool currentBitPC = PC[i];
        bool currentBitInc = inc[i];

        sum[i] = currentBitPC ^ currentBitInc ^ carry;                                     // Soma bit a bit com carry
        carry = (currentBitPC & currentBitInc) | (carry & (currentBitPC ^ currentBitInc)); // Calcula o carry para o próximo bit
    }

    int pcValue = static_cast<int>(sum.to_ulong());

    PC = sum;

    cout << "\nValor do PC: " << PC << endl;
}

bitset<16> If::getPc()
{
    return PC;
}

void If::branchPC(bitset<16> newPC)
{

    int pcValue = static_cast<int>(newPC.to_ulong());

    this->PC = newPC;
}

#include "Controle.hpp"

class Id
{

public:
    bitset<8> ra;
    bitset<8> rb;
    bitset<8> rc;

    Controle *sinaisControle;
    Registradores *regs;

    bitset<8> opcode;

    bitset<32> raValue;
    bitset<32> rbValue;
    bitset<32> rcValue;

    bitset<8> bit_8;
    bitset<16> bit16;
    bitset<24> bit_24;

    void reset_valores();
    void decodificarInstrucao(bitset<32> instrucaoBinaria);
    bool verificarRegistrador(string textoBin);

    Id(bitset<32> instrucaoBinaria, Registradores *regs);
    ~Id();
    bitset<8> getOpcode()
    {
        return opcode;
    };
    bitset<8> getRa()
    {
        return ra;
    };
    bitset<32> getRaValue()
    {
        return raValue;
    };
    bitset<8> getRb()
    {
        return rb;
    };
    bitset<32> getRbValue()
    {
        return rbValue;
    };
    bitset<8> getRc()
    {
        return rc;
    };
    bitset<32> getRcValue()
    {
        return rcValue;
    };
    bitset<16> getbit16()
    {
        return bit16;
    };
    bitset<24> getbit_24()
    {
        return bit_24;
    };
    bitset<8> getbit_8()
    {
        return bit_8;
    };
    Controle *getControle()
    {
        return sinaisControle;
    };
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
    bit_8.reset();
    bit16.reset();
    bit_24.reset();
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
    bit_8 = bitset<8>(texto_Binario_Auxiliar);

    texto_Binario_Auxiliar = instrucaoString.substr(8, 16);
    bit16 = bitset<16>(texto_Binario_Auxiliar);

    texto_Binario_Auxiliar = instrucaoString.substr(8, 24);
    bit_24 = bitset<24>(texto_Binario_Auxiliar);
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
        return true;

    return false;
}

void Id::depuracao()
{

    cout << "Ra (endereço): " << ra.to_ulong() << endl
         << "Rb (endereço): " << rb.to_ulong() << endl
         << "Rc (endereço): " << rc.to_ulong() << endl
         << "Valores das variáveis do Id: " << endl
         << endl
         << "Opcode: " << opcode << endl
         << endl

         << "bit_8 : " << bit_8 << endl
         << "bit16: " << bit16 << endl
         << "bit_24: " << bit_24 << endl
         << endl;

    sinaisControle->depuracao_controle();
}
