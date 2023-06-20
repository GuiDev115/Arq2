class Controle
{

private:
    bool reg_dst;
    bool reg_write;
    string AluControl;
    bool mem_read;
    bool mem_wr;
    int Aluop;
    bool Alusrc;
    bool MemtoReg;
    bool Branch;
    bool Jump;
    void valuesReset();
    void alterarSinais(string opcode);

public:
    Controle(string opcode);
    bool getreg_dst()
    {
        return reg_dst;
    };
    bool getreg_write()
    {
        return reg_write;
    };
    string getAluControl()
    {
        return AluControl;
    };
    bool getmem_read()
    {
        return mem_read;
    };
    bool getmem_wr()
    {
        return mem_wr;
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

    reg_dst = 0;
    reg_write = 0;
    AluControl = "invalido";
    mem_read = 0;
    mem_wr = 0;
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
        reg_dst = 0;
        reg_write = 0;
        AluControl = "address";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00000001")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "add";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000010")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "sub";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000011")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "zeros";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000100")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "xor";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000101")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "or";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000110")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "passnota";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00000111")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "and";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001000")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "asl";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001001")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "asr";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001010")
    { // SLR
        reg_dst = 0;
        reg_write = 1;
        AluControl = "lsl";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001011")
    { // SLT
        reg_dst = 0;
        reg_write = 1;
        AluControl = "lsr";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001100")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "passa";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001101")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "lch";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001110")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "lcl";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00001111")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "load";
        mem_read = 1;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 1;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010000")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "store";
        mem_read = 0;
        mem_wr = 1;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010001") // dando provlema
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "jal";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00010010")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "jr";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00010011")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "beq";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00010100") // dando zika
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "bne";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00010101") // dando problema
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "j";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "11111111")
    {
        AluControl = "halt - saída de sistema";
    }

    else if (opcode == "00010110")
    { // set less than b.22
        reg_dst = 0;
        reg_write = 1;
        AluControl = "xori";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00010111")
    { // set less than immediate b.23
        reg_dst = 1;
        reg_write = 1;
        AluControl = "slti";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011000")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "blt";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00011001")
    {

        reg_dst = 0;
        reg_write = 1;
        AluControl = "storei";
        mem_read = 0;
        mem_wr = 1;
        Aluop = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011010")
    {
        reg_dst = 0;
        reg_write = 1;
        AluControl = "andi";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011011")
    {
        reg_dst = 1;
        reg_write = 1;
        AluControl = "addi";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011100")
    { // subi b.28
        reg_dst = 0;
        reg_write = 1;
        AluControl = "nand";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 10;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011101")
    {

        reg_dst = 1;
        reg_write = 1;
        AluControl = "subi";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 10;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011110")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "bge";
        mem_read = 0;
        mem_wr = 0;
        Aluop = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 1;
        Jump = 0;
    }
}

void Controle::depuracao_controle()
{

    cout << "Valores dos sinais de controle: " << endl;
    cout << "________________________________" << endl; // 32 tamanho
    cout << "| reg_dst: " << reg_dst << " ||||||";
    cout << " reg_write: " << reg_write << " |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| AluControl: " << AluControl << "                 |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| mem_read: " << mem_read << " |||||| "
         << "mem_wr: " << mem_wr << "|" << endl;
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
