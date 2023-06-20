class Controle
{

private:
    bool Regdst;
    bool Regwrite;
    string Aluctrl;
    bool Memread;
    bool Memwrite;
    int Aluop;
    bool Alusrc;
    bool MemtoReg;
    bool Branch;
    bool Jump;
    void valuesReset();
    void alterarSinais(string opcode);

public:
    Controle(string opcode);
    bool getRegdst()
    {
        return Regdst;
    };
    bool getRegwrite()
    {
        return Regwrite;
    };
    string getAluctrl()
    {
        return Aluctrl;
    };
    bool getMemread()
    {
        return Memread;
    };
    bool getMemwrite()
    {
        return Memwrite;
    };
    int getAluop()
    {
        return Aluop;
    };
    bool getAlusrc()
    {
        return Alusrc;
    };
    bool getMemtoReg()
    {
        return MemtoReg;
    };
    bool getBranch()
    {
        return Branch;
    };
    bool getJump()
    {
        return Jump;
    };
    void depuracao_controle();
};

Controle::Controle(string opcode)
{

    valuesReset();
    alterarSinais(opcode);
}

void Controle::valuesReset()
{

    Regdst = 0;
    Regwrite = 0;
    Aluctrl = "invalido";
    Memread = 0;
    Memwrite = 0;
    Aluop = 0;
    Alusrc = 0;
    MemtoReg = 0;
    Branch = 0;
    Jump = 0;
};

void Controle ::alterarSinais(string opcode)
{

    if (opcode == "00000000")
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "address";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00000001")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "add";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000010")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "sub";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000011")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "zeros";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000100")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "xor";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000101")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "or";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000110")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "passnota";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000111")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "and";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001000")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "asl";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001001")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "asr";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001010")
    { // SLR
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "lsl";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001011")
    { // SLT
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "lsr";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001100")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "passa";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001101")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "lch";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001110")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "lcl";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001111")
    {
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "load";
        Memread = 1;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 1;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010000")
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "store";
        Memread = 0;
        Memwrite = 1;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010001") // dando provlema
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "jal";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00010010")
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "jr";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00010011")
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "beq";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00010100") // dando zika
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "bne";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00010101") // dando problema
    {
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "j";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "11111111")
    {
        Aluctrl = "halt - saída de sistema";
    }

    else if (opcode == "00010110")
    { // set less than b.22
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "slt";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010111")
    { // set less than immediate b.23
        Regdst = 1;
        Regwrite = 1;
        Aluctrl = "slti";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011000")
    { // smt b.24 (set more than)
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "smt";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011001")
    { // inc b.25 (increment)
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "inc";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011010")
    { // dec b.26 (decrement)
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "dec";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011011")
    { // addi b.27
        Regdst = 1;
        Regwrite = 1;
        Aluctrl = "addi";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011100")
    { // subi b.28
        Regdst = 1;
        Regwrite = 1;
        Aluctrl = "subi";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011101")
    { // nand b.29
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "nand";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 10;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011110")
    { // nor b.30
        Regdst = 0;
        Regwrite = 1;
        Aluctrl = "nor";
        Memread = 0;
        Memwrite = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
}

void Controle::depuracao_controle()
{

    cout << "Valores dos sinais de controle: " << endl;
    cout << "________________________________" << endl; // 32 tamanho
    cout << "| Regdst: " << Regdst << " ||||||";
    cout << " Regwrite: " << Regwrite << " |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| Aluctrl: " << Aluctrl << "                 |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| Memread: " << Memread << " |||||| "
         << "Memwrite: " << Memwrite << "|" << endl;
    cout << "|______________________________|" << endl;
    cout << "| Aluop: " << Aluop << " |||||||"
         << "Alusrc: " << Alusrc << "   |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| MemtoReg: " << MemtoReg << "                  |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| Branch: " << Branch << " Jump: " << Jump << "            |" << endl;
    cout << "|______________________________|\n"
         << endl;
}
