class Alu
{

private:
	bitset<32> PC, bit8, bit16, bit24, rc, ra, rb, r31, num, zero;
	bitset<16> novoPC, novoRc;
	Registradores *regs;
	If *ifStage;
	Id *idStage;
	Controle *controle;
	Memoria *memoria;
	bool ALUzero;
	bool overflow;
	bool carry;
	bool borrow;
	bool neg;
	bool continuar;
	void verificaNegativo(bitset<32> rc);
	void verificaOverflow(bitset<32> ra, bitset<32> rb, bitset<32> result, string operacao);
	void converteBits(int operacao);
	bitset<32> calculaBits(bitset<32> ra, bitset<32> rb, string operacao);

public:
	Alu(Registradores *regs, If *ifStage, Id *idStage, Controle *controle, Memoria *memoria);
	void instrucoesAritmeticas();
	void instrucoesDeDesvio();
	void instrucoesDeMemoria();
	void mostrarFlags();
	bool getOverflow() { return overflow; };
	bitset<32> getResultadoRa() { return ra; };
	bitset<32> getResultadoRc() { return rc; };
	bitset<32> getRetornoFuncao() { return r31; };
	bool getHalt() { return continuar; };
};

Alu::Alu(Registradores *regs, If *ifStage, Id *idStage, Controle *controle, Memoria *memoria)
{

	this->regs = regs;
	this->ifStage = ifStage;
	this->idStage = idStage;
	this->controle = controle;
	this->memoria = memoria;

	rc = idStage->getRcValue();
	ra = idStage->getRaValue();
	rb = idStage->getRbValue();
	r31 = regs->getRegistrador(31);

	converteBits(1);

	ALUzero = 0;
	zero = 0;
	overflow = 0;
	carry = 0;
	borrow = 0;
	neg = 0;
	num = 65535;
	continuar = true;
}

void Alu::instrucoesAritmeticas()
{

	bool aux = 0;

	// SOMA INTEIRA
	if (controle->getAluctrl() == "add")
	{
		rc = calculaBits(ra, rb, "adicao");
		verificaNegativo(rc);
		zero = rc;
	}

	// SUBTRAÇÃO INTEIRA
	else if (controle->getAluctrl() == "sub")
	{
		rc = calculaBits(ra, rb, "subtracao");
		verificaNegativo(rc);
		zero = rc;
	}

	// ZERA
	else if (controle->getAluctrl() == "zeros")
	{
		rc = 0;
		// nao causa overflow
		// neg por padrao é zero
		zero = rc;
	}

	// XOR LÓGICO
	else if (controle->getAluctrl() == "xor")
	{
		rc = ra ^ rb;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// OR LÓGICO
	else if (controle->getAluctrl() == "or")
	{
		rc = ra | rb;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// NOT
	else if (controle->getAluctrl() == "passnota")
	{
		rc = ~ra;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// AND LÓGICO
	else if (controle->getAluctrl() == "and")
	{
		rc = ra & rb;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// SHIFT ARITMÉTICO PARA A ESQUERDA
	else if (controle->getAluctrl() == "asl")
	{
		aux = ra[31];
		rc = ra << rb.to_ulong();
		rc[31] = aux;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// SHIFT ARITMÉTICO PARA A DIREITA
	else if (controle->getAluctrl() == "asr")
	{
		aux = ra[31];
		rc = ra >> rb.to_ulong();
		rc[31] = aux;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// SHIFT LÓGICO PARA A ESQUERDA
	else if (controle->getAluctrl() == "lsl")
	{
		rc = ra << rb.to_ulong();
		rc[31] = aux;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// SHIFT LÓGICO PARA A DIREITA
	else if (controle->getAluctrl() == "lsr")
	{
		rc = ra >> rb.to_ulong();
		rc[31] = aux;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// COPIA
	else if (controle->getAluctrl() == "passa")
	{
		rc = ra;
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// CARREGA CONSTANTE NOS 2 BYTES MAIS SIGNIFICATIVOS
	else if (controle->getAluctrl() == "lch")
	{
		for (int i = 15; i >= 0; i--)
		{

			if ((rc[i] & num[i]) == 0)
			{
				rc[i] = 0;
			}
			else
			{
				rc[i] = 1;
			}
		}

		bitset<32> aux = (bit16 << 16);
		for (int i = 31; i >= 16; i--)
		{

			rc[i] = aux[i];
		}

		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// CARREGA CONSTANTE NOS 2 BYTES MENOS SIGNIFICATIVOS
	else if (controle->getAluctrl() == "lcl")
	{
		bitset<32> aux = num << 16;
		for (int i = 31; i >= 16; i--)
		{

			if ((rc[i] & aux[i]) == 0)
			{
				rc[i] = 0;
			}
			else
			{
				rc[i] = 1;
			}
		}

		for (int i = 15; i >= 0; i--)
		{

			rc[i] = bit16[i];
		}

		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// Slt
	else if (controle->getAluctrl() == "slt")
	{

		bool result = false;
		rc = result;

		for (int i = 31; i >= 0 && !result; i--)
		{
			if (ra[i] < rb[i])
			{
				result = 1;
				rc = result;
			}
			else if (ra[i] > rb[i])
			{
				break;
			}
		}

		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// Slti
	else if (controle->getAluctrl() == "slti")
	{

		bool result = false;
		rc = result;

		for (int i = 31; i >= 0 && !result; i--)
		{
			if (rb[i] < bit8[i])
			{
				result = 1;
				rc = result;
			}
			else if (rb[i] > bit8[i])
			{
				break;
			}
		}

		// não causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// Smt
	else if (controle->getAluctrl() == "smt")
	{

		bool result = false;
		rc = result;

		for (int i = 31; i >= 0 && !result; i--)
		{
			if (ra[i] > rb[i])
			{
				result = 1;
				rc = result;
			}
			else if (ra[i] < rb[i])
			{
				break;
			}
		}
	}

	// Inc
	else if (controle->getAluctrl() == "inc")
	{

		rc = calculaBits(rc, 1, "adicao");
		verificaNegativo(rc);
		zero = rc;
	}

	// Dec
	else if (controle->getAluctrl() == "dec")
	{

		rc = calculaBits(rc, 1, "subtracao");
		verificaNegativo(rc);
		zero = rc;
	}

	// Addi
	else if (controle->getAluctrl() == "addi")
	{
		rc = calculaBits(rb, bit8, "adicao");
		verificaNegativo(rc);
		zero = rc;
	}

	// Subi
	else if (controle->getAluctrl() == "subi")
	{
		rc = calculaBits(rb, bit8, "subtracao");
		verificaNegativo(rc);
		zero = rc;
	}

	// Nand
	else if (controle->getAluctrl() == "nand")
	{

		bool comeco = false;

		for (int i = 31; i >= 0; i--)
		{

			if (!comeco and ra[i] == 0 and rb[i] == 0)
				continue;

			else
			{
				comeco = true;
				if ((ra[i] & rb[i]) == 0)
				{
					rc[i] = 1;
				}
				else
				{
					rc[i] = 0;
				}
			}
		}
		// não causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// Nor
	else if (controle->getAluctrl() == "nor")
	{

		bool comeco = false;

		for (int i = 31; i >= 0; i--)
		{

			if (!comeco and ra[i] == 0 and rb[i] == 0)
			{
				continue;
			}
			else
			{
				comeco = true;
				if ((ra[i] | rb[i]) == 1)
				{
					rc[i] = 0;
				}
				else
				{
					rc[i] = 1;
				}
			}
		}
		// nao causa overflow
		verificaNegativo(rc);
		zero = rc;
	}

	// halt
	else if (controle->getAluctrl() == "halt - saída de sistema")
	{
		continuar = false;
	}

	// Verifica se algum resultado corresponde a 0 para acionar a flag
	if (zero == 0)
	{
		ALUzero = 1;
	}
}

void Alu::instrucoesDeDesvio()
{

	// JUMP AND LINK
	if (controle->getAluctrl() == "jal")
	{
		r31 = PC;
		PC = bit24;
	}

	// JUMP REGISTER
	else if (controle->getAluctrl() == "jr")
	{
		PC = r31;
	}

	//  JUMP SE IGUAL (BEQ)
	else if (controle->getAluctrl() == "beq")
	{
		if (ra == rb)
			PC = bit8;
	}

	//  JUMP SE DIFERENTE (BNE)
	else if (controle->getAluctrl() == "bne")
	{
		if (ra != rb)
		{
			PC = bit8;
		}
	}

	//  JUMP INCONDICIONAL
	else if (controle->getAluctrl() == "j")
	{
		PC = bit24;
	}

	// Altera o PC e o r31 já que eles foram modificados.
	converteBits(2);
	ifStage->branchPC(novoPC);
	regs->setRegistrador(r31, 31);
}

void Alu::instrucoesDeMemoria()
{

	// LOAD WORD (vou refazer)
	if (controle->getAluctrl() == "load")
	{
		// rc = tenho que setar na memoria o ra;
	}

	// STORE WORD (vou refazer)
	if (controle->getAluctrl() == "store")
	{

		if (controle->getRegwrite() == 0 && controle->getMemwrite() == 1)
		{

			converteBits(3);

			memoria->armazenarDado(ra, novoRc);
		}
	}
}

void Alu::converteBits(int operacao)
{

	if (operacao == 1)
	{ // Converte para 32

		bitset<16> PC = ifStage->getPc();

		bitset<8> bit8 = idStage->getbit8();
		bitset<16> bit16 = idStage->getbit16();
		bitset<24> bit24 = idStage->getbit24();

		for (int i = 0; i < 16; i++)
		{
			this->PC[i] = PC[i];
		}

		// bit8 (do id) é negativo
		if (bit8[8 - 1] == 1)
		{
			for (int i = 32 - 1; i > 0; i--)
			{
				this->bit8[i] = 1;
			}
		}
		// bit8 (da alu) recebe os bits do bit8 (do id)
		for (int i = 0; i < 8; i++)
		{
			this->bit8[i] = bit8[i];
		}

		// bit16 (do id) é negativo
		if (bit16[16 - 1] == 1)
		{
			for (int i = 32 - 1; i > 0; i--)
			{
				this->bit16[i] = 1;
			}
		}
		// bit16 (da alu) recebe os bits do bit16 (do id)
		for (int i = 0; i < 16; i++)
		{
			this->bit16[i] = bit16[i];
		}

		// bit24 (do id) é negativo
		if (bit24[24 - 1] == 1)
		{
			for (int i = 32 - 1; i > 0; i--)
			{
				this->bit24[i] = 1;
			}
		}
		// bit24 (da alu) recebe os bits do bit24 (do id)
		for (int i = 0; i < 24; i++)
		{
			this->bit24[i] = bit24[i];
		}
	}

	else if (operacao == 2)
	{ // Converte de 32 para 16 (PC)

		for (int i = 0; i < 16; i++)
		{
			novoPC[i] = this->PC[i];
		}
	}

	else if (operacao == 3)
	{ // Converte de 32 para 16 (Rc ao realizar a instrução store)

		for (int i = 0; i < 16; i++)
		{
			novoRc[i] = rc[i];
		}
	}
}

bitset<32> Alu::calculaBits(bitset<32> ra, bitset<32> rb, string operacao)
{

	// adicao
	if ((operacao == "adicao"))
	{

		bitset<32> sum;

		for (int i = 0; i < 32 - 1; i++)
		{
			sum[i] = ra[i] ^ rb[i] ^ carry;						 // Soma bit a bit com carry
			carry = (ra[i] & rb[i]) | (carry & (ra[i] ^ rb[i])); // Calcula o carry para o próximo bit
		}

		// converte o binario para um inteiro (considerendo o sinal)
		long result = conversorBinInteiro(ra) + conversorBinInteiro(rb);

		if (result < 0)
		{
			for (int i = 31; i > 0; i--)
			{
				if (sum[i] == 0)
				{
					sum[i] = 1;
				}
				else if (sum[i] == 1)
				{
					i = 0;
				}
			}
		}

		verificaOverflow(ra, rb, sum, operacao);
		return sum;
	}

	// subtracao
	if ((operacao == "subtracao"))
	{
		bitset<32> difference;

		for (int i = 0; i < 32 - 1; i++)
		{
			difference[i] = ra[i] ^ rb[i] ^ borrow;								// Subtrai bit a bit com borrow
			borrow = (!ra[i] & rb[i]) | ((borrow & !ra[i]) & !(ra[i] ^ rb[i])); // Calcula o borrow para o próximo bit
		}

		// converte o binario para um inteiro (considerendo o sinal)
		long result = conversorBinInteiro(ra) - conversorBinInteiro(rb);

		if (result < 0)
		{
			for (int i = 31; i > 0; i--)
			{
				if (difference[i] == 0)
				{
					difference[i] = 1;
				}
				else if (difference[i] == 1)
				{
					i = 0;
				}
			}
		}

		verificaOverflow(ra, rb, difference, operacao);
		return difference;
	}

	return 0;
}

void Alu::verificaOverflow(bitset<32> ra, bitset<32> rb, bitset<32> result, string operacao)
{

	if (operacao == "adicao")
	{
		if (conversorBinInteiro(ra) >= 0 and conversorBinInteiro(rb) >= 0 and conversorBinInteiro(result) < 0)
		{
			overflow = true;
		}

		else if (conversorBinInteiro(ra) < 0 and conversorBinInteiro(rb) < 0 and conversorBinInteiro(result) >= 0)
		{
			overflow = true;
		}
	}

	else if (operacao == "subtracao")
	{
		if (conversorBinInteiro(ra) >= 0 and conversorBinInteiro(rb) < 0 and conversorBinInteiro(result) < 0)
		{
			overflow = true;
		}

		else if (conversorBinInteiro(ra) < 0 and conversorBinInteiro(rb) >= 0 and conversorBinInteiro(result) >= 0)
		{
			overflow = true;
		}
	}

	if (overflow)
	{
		throw(12);
	}
}

void Alu::verificaNegativo(bitset<32> rc)
{

	// Verifica se o bit mais significativo é 1 (Se é negativo)
	if (rc[31])
	{
		neg = 1;
	}
}

void Alu::mostrarFlags()
{

	cout << "Flags da ALU e endereco de desvio: " << endl;
	cout << "\tFlag de Zero: " << ALUzero << endl;
	cout << "\tCarry: " << carry << endl;
	cout << "\tNegativo: " << neg << endl;
	cout << "\tSinal de Overflow: " << overflow << endl;
	cout << "\tCalculo do endereco de desvio (valor de resultado): " << novoPC << endl;
	cout << "\tValor do rc: " << rc << endl;
}
