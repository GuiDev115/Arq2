class Wb
{

private:
	Registradores *regs;
	Id *idStage;
	Controle *controle;
	Alu *alu;
	Memoria *memoria;
	void leituraEscritaRegistrador();

public:
	Wb(Registradores *regs, Id *idStage, Controle *controle, Alu *alu, Memoria *memoria);
};

Wb::Wb(Registradores *regs, Id *idStage, Controle *controle, Alu *alu, Memoria *memoria)
{

	this->regs = regs;
	this->idStage = idStage;
	this->controle = controle;
	this->alu = alu;
	this->memoria = memoria;

	leituraEscritaRegistrador();
}

void Wb::leituraEscritaRegistrador()
{

	// Bits de sinais de controle
	bool regDst = controle->getRegdst();
	bool reWrite = controle->getRegwrite();
	bool memtoReg = controle->getMemtoReg();
	bool jump = controle->getJump();

	// jal
	if (reWrite && jump)
	{
		bitset<32> novoR31(alu->getRetornoFuncao());
		regs->setRegistrador(novoR31, 31);
	}

	// lw
	else if (reWrite && memtoReg)
	{
		bitset<32> novoDado = memoria->getDado(alu->getResultadoRa());
		regs->setRegistrador(novoDado, idStage->getRc());
	}

	// addi e subi
	else if (reWrite && regDst && alu->getOverflow() == 0)
	{
		bitset<32> novoDado(alu->getResultadoRc());
		regs->setRegistrador(novoDado, idStage->getRa());
	}

	// R
	else if (reWrite && !regDst && alu->getOverflow() == 0)
	{
		bitset<32> novoDado(alu->getResultadoRc());
		regs->setRegistrador(novoDado, idStage->getRc());
	}
}