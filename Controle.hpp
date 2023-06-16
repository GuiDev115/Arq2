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
    bool getRegdst() { return Regdst; };
    bool getRegwrite() { return Regwrite; };
    string getAluctrl() { return Aluctrl; };
    bool getMemread() { return Memread; };
    bool getMemwrite() { return Memwrite; };
    int getAluop() { return Aluop; };
    bool getAlusrc() { return Alusrc; };
    bool getMemtoReg() { return MemtoReg; };
    bool getBranch() { return Branch; };
    bool getJump() { return Jump; };
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

    // Instruções do UFLA-RISC (23)

    if (opcode == "00000000")
    { // address b.0
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
    { // add b.1
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
    { // sub b.2
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
    { // zero b.3
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
    { // xor b.4
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
    { // or b.5
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
    { // not b.6
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
    { // and b.7
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
    { // shift aritmético p/ esquerda b.8
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
    { // shift aritmético p/ direita b.9
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
    { // shift lógico p/ esquerda b.10
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
    { // shift lógico p/ direita b.11
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
    { // copia b.12
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
    { // carrega constante de 16 bits nos 2 bytes mais significativos b.13
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
    { // carrega constante de 16 bits nos 2 bytes menos significativos b.14
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
    { // lw b.15
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
    { // sw b.16
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
    else if (opcode == "00010001")
    { // jump and link (jal) b.17
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
    { // jump register (jr) b.18
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
    { // jump if equal b.19
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
    else if (opcode == "00010100")
    { // jump if not-equal b.20
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
    else if (opcode == "00010101")
    { // jump incondicional b.21
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
    { // halt
        Regdst = 0;
        Regwrite = 0;
        Aluctrl = "halt - saída de sistema";
        Memread = 0;
        Memwrite = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }

    // Instruções do grupo (9)
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
    cout << "\tRegdst: " << Regdst << endl;
    cout << "\tRegwrite: " << Regwrite << endl;
    cout << "\tAluctrl: " << Aluctrl << endl;
    cout << "\tMemread: " << Memread << endl;
    cout << "\tMemwrite: " << Memwrite << endl;
    cout << "\tAluop: " << Aluop << endl;
    cout << "\tAlusrc: " << Alusrc << endl;
    cout << "\tMemtoReg: " << MemtoReg << endl;
    cout << "\tBranch: " << Branch << endl;
    cout << "\tJump: " << Jump << endl
         << endl;
}
