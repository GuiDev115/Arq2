class Registradores
{

private:
	bitset<32> *vecReg;

public:
	Registradores();
	~Registradores();
	bitset<32> getRegistrador(bitset<8> numeroRegistrador);
	void setRegistrador(bitset<32> dadoParaEscrever, bitset<8> numeroRegistrador);
	void depuracao();
};

Registradores::Registradores()
{

	vecReg = new bitset<32>[32];

	vecReg[28] = 16384;		// gp
	vecReg[29] = 65536 - 1; // sp
}

Registradores::~Registradores()
{

	delete[] vecReg;
}

bitset<32> Registradores::getRegistrador(bitset<8> numeroRegistrador)
{

	if (numeroRegistrador == bitset<8>("00000000"))
	{
		return vecReg[0];
	}
	else if (numeroRegistrador == bitset<8>("00000001"))
	{
		return vecReg[1];
	}
	else if (numeroRegistrador == bitset<8>("00000010"))
	{
		return vecReg[2];
	}
	else if (numeroRegistrador == bitset<8>("00000011"))
	{
		return vecReg[3];
	}
	else if (numeroRegistrador == bitset<8>("00000100"))
	{
		return vecReg[4];
	}
	else if (numeroRegistrador == bitset<8>("00000101"))
	{
		return vecReg[5];
	}
	else if (numeroRegistrador == bitset<8>("00000110"))
	{
		return vecReg[6];
	}
	else if (numeroRegistrador == bitset<8>("00000111"))
	{
		return vecReg[7];
	}
	else if (numeroRegistrador == bitset<8>("00001000"))
	{
		return vecReg[8];
	}
	else if (numeroRegistrador == bitset<8>("00001001"))
	{
		return vecReg[9];
	}
	else if (numeroRegistrador == bitset<8>("00001010"))
	{
		return vecReg[10];
	}
	else if (numeroRegistrador == bitset<8>("00001011"))
	{
		return vecReg[11];
	}
	else if (numeroRegistrador == bitset<8>("00001100"))
	{
		return vecReg[12];
	}
	else if (numeroRegistrador == bitset<8>("00001101"))
	{
		return vecReg[13];
	}
	else if (numeroRegistrador == bitset<8>("00001110"))
	{
		return vecReg[14];
	}
	else if (numeroRegistrador == bitset<8>("00001111"))
	{
		return vecReg[15];
	}
	else if (numeroRegistrador == bitset<8>("00010000"))
	{
		return vecReg[16];
	}
	else if (numeroRegistrador == bitset<8>("00010001"))
	{
		return vecReg[17];
	}
	else if (numeroRegistrador == bitset<8>("00010010"))
	{
		return vecReg[18];
	}
	else if (numeroRegistrador == bitset<8>("00010011"))
	{
		return vecReg[19];
	}
	else if (numeroRegistrador == bitset<8>("00010100"))
	{
		return vecReg[20];
	}
	else if (numeroRegistrador == bitset<8>("00010101"))
	{
		return vecReg[21];
	}
	else if (numeroRegistrador == bitset<8>("00010110"))
	{
		return vecReg[22];
	}
	else if (numeroRegistrador == bitset<8>("00010111"))
	{
		return vecReg[23];
	}
	else if (numeroRegistrador == bitset<8>("00011000"))
	{
		return vecReg[24];
	}
	else if (numeroRegistrador == bitset<8>("00011001"))
	{
		return vecReg[25];
	}
	else if (numeroRegistrador == bitset<8>("00011010"))
	{
		return vecReg[26];
	}
	else if (numeroRegistrador == bitset<8>("00011011"))
	{
		return vecReg[27];
	}
	else if (numeroRegistrador == bitset<8>("00011100"))
	{
		return vecReg[28];
	}
	else if (numeroRegistrador == bitset<8>("00011101"))
	{
		return vecReg[29];
	}
	else if (numeroRegistrador == bitset<8>("00011110"))
	{
		return vecReg[30];
	}
	else if (numeroRegistrador == bitset<8>("00011111"))
	{
		return vecReg[31];
	}
	throw("O registrador lido não pertence ao conjunto!");
}

void Registradores::setRegistrador(bitset<32> dadoParaEscrever, bitset<8> numeroRegistrador)
{

	long aux = conversorBinInteiro(dadoParaEscrever);

	if (aux < -2147483648 or aux > 2147483647)
	{

		throw("Valor invalido");
	}

	if (numeroRegistrador == bitset<8>("00000000"))
	{
		throw("Tentativa de setar algum valor no registrador zero!");
	}
	else if (numeroRegistrador == bitset<8>("00000001"))
	{
		vecReg[1] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000010"))
	{
		vecReg[2] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000011"))
	{
		vecReg[3] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000100"))
	{
		vecReg[4] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000101"))
	{
		vecReg[5] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000110"))
	{
		vecReg[6] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000111"))
	{
		vecReg[7] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001000"))
	{
		vecReg[8] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001001"))
	{
		vecReg[9] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001010"))
	{
		vecReg[10] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001011"))
	{
		vecReg[11] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001100"))
	{
		vecReg[12] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001101"))
	{
		vecReg[13] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001110"))
	{
		vecReg[14] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001111"))
	{
		vecReg[15] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010000"))
	{
		vecReg[16] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010001"))
	{
		vecReg[17] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010010"))
	{
		vecReg[18] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010011"))
	{
		vecReg[19] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010100"))
	{
		vecReg[20] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010101"))
	{
		vecReg[21] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010110"))
	{
		vecReg[22] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010111"))
	{
		vecReg[23] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011000"))
	{
		vecReg[24] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011001"))
	{
		vecReg[25] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011010"))
	{
		throw("Lugar reservado ao OS");
	}
	else if (numeroRegistrador == bitset<8>("00011011"))
	{
		throw("Lugar reservado ao OS");
	}
	else if (numeroRegistrador == bitset<8>("00011100"))
	{
		vecReg[28] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011101"))
	{
		vecReg[29] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011110"))
	{
		vecReg[30] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011111"))
	{
		vecReg[31] = dadoParaEscrever;
	}
	else
	{
		throw("Tentativa de escrever em um registrador inexistente!");
	}
}

void Registradores::depuracao()
{

	cout << endl;
	cout << "REGISTRADORES UM A UM:" << endl;
	cout << "________________________________________________" << endl;
	cout << "|  zero    : " << vecReg[0] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  at (1)  : " << vecReg[1] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  v0 (2)  : " << vecReg[2] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  v1 (3)  : " << vecReg[3] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  a0 (4)  : " << vecReg[4] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  a1 (5)  : " << vecReg[5] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  a2 (6)  : " << vecReg[6] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  a3 (7)  : " << vecReg[7] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t0 (8)  : " << vecReg[8] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t1 (9)  : " << vecReg[9] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t2 (10) : " << vecReg[10] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t3 (11) : " << vecReg[11] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t4 (12) : " << vecReg[12] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t5 (13) : " << vecReg[13] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t6 (14) : " << vecReg[14] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t7 (15) : " << vecReg[15] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s0 (16) : " << vecReg[16] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s1 (17) : " << vecReg[17] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s2 (18) : " << vecReg[18] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s3 (19) : " << vecReg[19] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s4 (20) : " << vecReg[20] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s5 (21) : " << vecReg[21] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s6 (22) : " << vecReg[22] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  s7 (23) : " << vecReg[23] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t8 (24) : " << vecReg[24] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  t9 (25) : " << vecReg[25] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  k0 (26) : " << vecReg[26] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  k1 (27) : " << vecReg[27] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  gp (28) : " << vecReg[28] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  sp (29) : " << vecReg[29] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  fp (30) : " << vecReg[30] << "   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|  ra (31) : " << vecReg[31] << "   |" << endl;
	cout << "|_______________________________________________|" << endl
		 << endl;
}
