class Memoria
{

public:
    bitset<32> *mem;

    Memoria();
    void armazenarInstrucao(string instrucaoAtual, int enderecoMemoriaTexto);
    void armazenarDado(bitset<32> dado, bitset<16> enderecoMemoriaDado);
    bitset<32> getInstrucao(bitset<16> posicao);
    bitset<32> getDado(bitset<32> posicao);
};

Memoria::Memoria()
{

    mem = new bitset<32>[65536];
}

void Memoria::armazenarInstrucao(string instrucaoAtual, int enderecoMemoriaTexto)
{

    bitset<32> instrucaoBitSet(instrucaoAtual);

    mem[enderecoMemoriaTexto] = instrucaoBitSet;
}

void Memoria::armazenarDado(bitset<32> dado, bitset<16> enderecoMemoriaDado)
{

    int aux = (int)enderecoMemoriaDado.to_ulong();

    mem[aux] = dado;
}

bitset<32> Memoria::getInstrucao(bitset<16> posicao)
{

    int aux = (int)posicao.to_ulong();

    return mem[aux];
}

bitset<32> Memoria::getDado(bitset<32> posicao)
{

    int aux = (int)posicao.to_ulong();

    return mem[aux];
}
