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