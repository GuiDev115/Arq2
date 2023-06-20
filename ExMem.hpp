#include "Alu.hpp"

class ExMem
{

public:
	Alu *alu;
	Registradores *regs;
	If *ifStage;
	Controle *controle;
	void realizarOperacoes();

	ExMem(Registradores *regs, If *ifStage, Id *idStage, Controle *controle, Memoria *memoria);
	Alu *getAlu()
	{
		return alu;
	};
};

ExMem::ExMem(Registradores *regs, If *ifStage, Id *idStage, Controle *controle, Memoria *memoria)
{

	this->regs = regs;
	this->ifStage = ifStage;
	this->controle = controle;

	alu = new Alu(regs, ifStage, idStage, controle, memoria);

	realizarOperacoes();
}

void ExMem::realizarOperacoes()
{

	// Realiza os calculos aritmeticos
	if ((controle->getBranch() == 0) && (controle->getJump() == 0) && (controle->getMemwrite() == 0) && (controle->getmem_read() == 0))
		alu->instrucoesAritmeticas();

	// Realiza os calculos dos desvios
	else if ((controle->getBranch() == 1) || (controle->getJump() == 1))
		alu->instrucoesDeDesvio();

	// Realiza os calculos para armazenar valores na memoria
	else if ((controle->getBranch() == 0) && (controle->getJump() == 0) && ((controle->getMemwrite() == 1) || (controle->getmem_read() == 1)))
		alu->instrucoesDeMemoria();
}