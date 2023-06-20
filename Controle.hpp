class Controle
{

private:
    bool reg_dst;
    bool reg_write;
    string AluControl;
    bool mem_read;
    bool mem_wr;
    int Alu_OP;
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
    int getAlu_OP()
    {
        return Alu_OP;
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

    reg_dst = 0;
    reg_write = 0;
    AluControl = "invalido";
    mem_read = 0;
    mem_wr = 0;
    Alu_OP = 0;
    Alusrc = 0;
    MemtoReg = 0;
    Branch = 0;
    Jump = 0;

    alterarSinais(opcode);
}

void Controle ::alterarSinais(string opcode)
{

    if (opcode == "00000000")
    {
        reg_dst = 0;
        reg_write = 0;
        AluControl = "address";
        mem_read = 0;
        mem_wr = 0;
        Alu_OP = 0;
        Alusrc = 0;
        MemtoReg = 0;
        Branch = 0;
        Jump = 1;
    }
    else if (opcode == "00000001")
    {
        reg_write = 1;
        AluControl = "add";
        Alu_OP = 10;
    }
    else if (opcode == "00000010")
    {
        reg_write = 1;
        AluControl = "sub";
        Alu_OP = 10;
        Alusrc = 1;
    }
    else if (opcode == "00000011")
    {
        reg_write = 1;
        AluControl = "zeros";
        Alusrc = 1;
    }
    else if (opcode == "00000100")
    {
        reg_write = 1;
        AluControl = "xor";
        Alu_OP = 10;
    }
    else if (opcode == "00000101")
    {
        reg_write = 1;
        AluControl = "or";
        Alu_OP = 10;
    }
    else if (opcode == "00000110")
    {
        reg_write = 1;
        AluControl = "passnota";
        Alu_OP = 10;
    }
    else if (opcode == "00000111")
    {
        reg_write = 1;
        AluControl = "and";
        Alu_OP = 10;
    }
    else if (opcode == "00001000")
    {
        reg_write = 1;
        AluControl = "asl";
    }
    else if (opcode == "00001001")
    {
        reg_write = 1;
        AluControl = "asr";
    }
    else if (opcode == "00001010")
    {
        reg_write = 1;
        AluControl = "lsl";
    }
    else if (opcode == "00001011")
    {
        reg_write = 1;
        AluControl = "lsr";
    }
    else if (opcode == "00001100")
    {
        reg_write = 1;
        AluControl = "passa";
    }
    else if (opcode == "00001101")
    {
        reg_write = 1;
        AluControl = "lch";
    }
    else if (opcode == "00001110")
    {
        reg_write = 1;
        AluControl = "lcl";
        Alusrc = 1;
    }
    else if (opcode == "00001111")
    {
        reg_write = 1;
        AluControl = "load";
        mem_read = 1;
        Alusrc = 1;
        MemtoReg = 1;
    }
    else if (opcode == "00010000")
    {

        AluControl = "store";
        mem_wr = 1;
        Alusrc = 1;
    }
    else if (opcode == "00010001") // dando provlema
    {
        AluControl = "jal";
        Jump = 1;
    }
    else if (opcode == "00010010")
    {
        AluControl = "jr";
        Jump = 1;
    }
    else if (opcode == "00010011")
    {
        AluControl = "beq";

        Branch = 1;
    }
    else if (opcode == "00010100") // dando zika
    {
        AluControl = "bne";
        Branch = 1;
        Jump = 0;
    }
    else if (opcode == "00010101") // dando problema
    {
        AluControl = "j";
        Jump = 1;
    }
    else if (opcode == "11111111")
    {
        AluControl = "halt - saída de sistema";
    }

    else if (opcode == "00010110")
    {
        reg_write = 1;
        AluControl = "xori";
        Alu_OP = 10;
    }
    else if (opcode == "00010111")
    {
        reg_dst = 1;
        reg_write = 1;
        AluControl = "slti";
        Alu_OP = 10;
        Alusrc = 1;
    }
    else if (opcode == "00011000")
    {
        AluControl = "blt";
        Branch = 1;
    }
    else if (opcode == "00011001")
    {

        reg_dst = 0;
        reg_write = 1;
        AluControl = "storei";
        mem_read = 0;
        mem_wr = 1;
        Alu_OP = 0;
        Alusrc = 1;
        MemtoReg = 0;
        Branch = 0;
        Jump = 0;
    }
    else if (opcode == "00011010")
    {
        reg_write = 1;
        AluControl = "andi";
        Alu_OP = 10;
    }
    else if (opcode == "00011011")
    {
        reg_dst = 1;
        reg_write = 1;
        AluControl = "addi";
        Alu_OP = 10;
        Alusrc = 1;
    }
    else if (opcode == "00011100")
    { // subi b.28
        reg_write = 1;
        AluControl = "nand";
        Alusrc = 10;
    }
    else if (opcode == "00011101")
    {

        reg_dst = 1;
        reg_write = 1;
        AluControl = "subi";
        Alu_OP = 10;
        Alusrc = 1;
    }
    else if (opcode == "00011110")
    {
        AluControl = "bge";
        Branch = 1;
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
    cout << "| Alu_OP: " << Alu_OP << " |||||||"
         << "Alusrc: " << Alusrc << "   |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| MemtoReg: " << MemtoReg << "                  |" << endl;
    cout << "|______________________________|" << endl;
    cout << "| Branch: " << Branch << " Jump: " << Jump << "            |" << endl;
    cout << "|______________________________|\n"
         << endl;
}
