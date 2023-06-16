class Registradores
{

private:
	bitset<32> *vetorReg;

public:
	Registradores();
	~Registradores();
	bitset<32> getRegistrador(bitset<8> numeroRegistrador);
	void setRegistrador(bitset<32> dadoParaEscrever, bitset<8> numeroRegistrador);
	void depuracao();
};

Registradores::Registradores()
{

	vetorReg = new bitset<32>[32];

	vetorReg[28] = 16384;	  // gp
	vetorReg[29] = 65536 - 1; // sp
}

Registradores::~Registradores()
{

	delete[] vetorReg;
}

bitset<32> Registradores::getRegistrador(bitset<8> numeroRegistrador)
{

	if (numeroRegistrador == bitset<8>("00000000"))
	{
		return vetorReg[0];
	}
	else if (numeroRegistrador == bitset<8>("00000001"))
	{
		return vetorReg[1];
	}
	else if (numeroRegistrador == bitset<8>("00000010"))
	{
		return vetorReg[2];
	}
	else if (numeroRegistrador == bitset<8>("00000011"))
	{
		return vetorReg[3];
	}
	else if (numeroRegistrador == bitset<8>("00000100"))
	{
		return vetorReg[4];
	}
	else if (numeroRegistrador == bitset<8>("00000101"))
	{
		return vetorReg[5];
	}
	else if (numeroRegistrador == bitset<8>("00000110"))
	{
		return vetorReg[6];
	}
	else if (numeroRegistrador == bitset<8>("00000111"))
	{
		return vetorReg[7];
	}
	else if (numeroRegistrador == bitset<8>("00001000"))
	{
		return vetorReg[8];
	}
	else if (numeroRegistrador == bitset<8>("00001001"))
	{
		return vetorReg[9];
	}
	else if (numeroRegistrador == bitset<8>("00001010"))
	{
		return vetorReg[10];
	}
	else if (numeroRegistrador == bitset<8>("00001011"))
	{
		return vetorReg[11];
	}
	else if (numeroRegistrador == bitset<8>("00001100"))
	{
		return vetorReg[12];
	}
	else if (numeroRegistrador == bitset<8>("00001101"))
	{
		return vetorReg[13];
	}
	else if (numeroRegistrador == bitset<8>("00001110"))
	{
		return vetorReg[14];
	}
	else if (numeroRegistrador == bitset<8>("00001111"))
	{
		return vetorReg[15];
	}
	else if (numeroRegistrador == bitset<8>("00010000"))
	{
		return vetorReg[16];
	}
	else if (numeroRegistrador == bitset<8>("00010001"))
	{
		return vetorReg[17];
	}
	else if (numeroRegistrador == bitset<8>("00010010"))
	{
		return vetorReg[18];
	}
	else if (numeroRegistrador == bitset<8>("00010011"))
	{
		return vetorReg[19];
	}
	else if (numeroRegistrador == bitset<8>("00010100"))
	{
		return vetorReg[20];
	}
	else if (numeroRegistrador == bitset<8>("00010101"))
	{
		return vetorReg[21];
	}
	else if (numeroRegistrador == bitset<8>("00010110"))
	{
		return vetorReg[22];
	}
	else if (numeroRegistrador == bitset<8>("00010111"))
	{
		return vetorReg[23];
	}
	else if (numeroRegistrador == bitset<8>("00011000"))
	{
		return vetorReg[24];
	}
	else if (numeroRegistrador == bitset<8>("00011001"))
	{
		return vetorReg[25];
	}
	else if (numeroRegistrador == bitset<8>("00011010"))
	{
		return vetorReg[26];
	}
	else if (numeroRegistrador == bitset<8>("00011011"))
	{
		return vetorReg[27];
	}
	else if (numeroRegistrador == bitset<8>("00011100"))
	{
		return vetorReg[28];
	}
	else if (numeroRegistrador == bitset<8>("00011101"))
	{
		return vetorReg[29];
	}
	else if (numeroRegistrador == bitset<8>("00011110"))
	{
		return vetorReg[30];
	}
	else if (numeroRegistrador == bitset<8>("00011111"))
	{
		return vetorReg[31];
	}
	throw(6);
}

void Registradores::setRegistrador(bitset<32> dadoParaEscrever, bitset<8> numeroRegistrador)
{

	long aux = conversorBinInteiro(dadoParaEscrever);

	if (aux < -2147483648 or aux > 2147483647)
	{

		throw(11);
	}

	if (numeroRegistrador == bitset<8>("00000000"))
	{
		throw(7);
	}
	else if (numeroRegistrador == bitset<8>("00000001"))
	{
		vetorReg[1] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000010"))
	{
		vetorReg[2] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000011"))
	{
		vetorReg[3] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000100"))
	{
		vetorReg[4] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000101"))
	{
		vetorReg[5] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000110"))
	{
		vetorReg[6] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00000111"))
	{
		vetorReg[7] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001000"))
	{
		vetorReg[8] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001001"))
	{
		vetorReg[9] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001010"))
	{
		vetorReg[10] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001011"))
	{
		vetorReg[11] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001100"))
	{
		vetorReg[12] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001101"))
	{
		vetorReg[13] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001110"))
	{
		vetorReg[14] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00001111"))
	{
		vetorReg[15] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010000"))
	{
		vetorReg[16] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010001"))
	{
		vetorReg[17] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010010"))
	{
		vetorReg[18] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010011"))
	{
		vetorReg[19] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010100"))
	{
		vetorReg[20] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010101"))
	{
		vetorReg[21] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010110"))
	{
		vetorReg[22] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00010111"))
	{
		vetorReg[23] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011000"))
	{
		vetorReg[24] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011001"))
	{
		vetorReg[25] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011010"))
	{
		throw(8);
	}
	else if (numeroRegistrador == bitset<8>("00011011"))
	{
		throw(8);
	}
	else if (numeroRegistrador == bitset<8>("00011100"))
	{
		vetorReg[28] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011101"))
	{
		vetorReg[29] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011110"))
	{
		vetorReg[30] = dadoParaEscrever;
	}
	else if (numeroRegistrador == bitset<8>("00011111"))
	{
		vetorReg[31] = dadoParaEscrever;
	}
	else
	{
		throw(9);
	}
}

void Registradores::depuracao()
{

	cout << "Conteúdos dos registradores:" << endl;
	cout << "\tzero    : " << vetorReg[0] << endl;
	cout << "\tat (1)  : " << vetorReg[1] << endl;
	cout << "\tv0 (2)  : " << vetorReg[2] << endl;
	cout << "\tv1 (3)  : " << vetorReg[3] << endl;
	cout << "\ta0 (4)  : " << vetorReg[4] << endl;
	cout << "\ta1 (5)  : " << vetorReg[5] << endl;
	cout << "\ta2 (6)  : " << vetorReg[6] << endl;
	cout << "\ta3 (7)  : " << vetorReg[7] << endl;
	cout << "\tt0 (8)  : " << vetorReg[8] << endl;
	cout << "\tt1 (9)  : " << vetorReg[9] << endl;
	cout << "\tt2 (10) : " << vetorReg[10] << endl;
	cout << "\tt3 (11) : " << vetorReg[11] << endl;
	cout << "\tt4 (12) : " << vetorReg[12] << endl;
	cout << "\tt5 (13) : " << vetorReg[13] << endl;
	cout << "\tt6 (14) : " << vetorReg[14] << endl;
	cout << "\tt7 (15) : " << vetorReg[15] << endl;
	cout << "\ts0 (16) : " << vetorReg[16] << endl;
	cout << "\ts1 (17) : " << vetorReg[17] << endl;
	cout << "\ts2 (18) : " << vetorReg[18] << endl;
	cout << "\ts3 (19) : " << vetorReg[19] << endl;
	cout << "\ts4 (20) : " << vetorReg[20] << endl;
	cout << "\ts5 (21) : " << vetorReg[21] << endl;
	cout << "\ts6 (22) : " << vetorReg[22] << endl;
	cout << "\ts7 (23) : " << vetorReg[23] << endl;
	cout << "\tt8 (24) : " << vetorReg[24] << endl;
	cout << "\tt9 (25) : " << vetorReg[25] << endl;
	cout << "\tk0 (26) : " << vetorReg[26] << endl;
	cout << "\tk1 (27) : " << vetorReg[27] << endl;
	cout << "\tgp (28) : " << vetorReg[28] << endl;
	cout << "\tsp (29) : " << vetorReg[29] << endl;
	cout << "\tfp (30) : " << vetorReg[30] << endl;
	cout << "\tra (31) : " << vetorReg[31] << endl
		 << endl;
}
