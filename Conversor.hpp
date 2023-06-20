#include "Memoria.hpp"

class Conversor
{

private:
    int enderecoComecoMemoriaTexto;
    int enderecoMemoriaTexto;
    Memoria *memoria;
    void leituraArquivoEntrada();
    bool verificarIntAddress(string str, int &aux);
    vector<string> *separarString(string str, string delimiter);
    string retornarInstrucaoEmString(vector<string> *vect);
    string conversorIntParaBinario8(int valor);
    string conversorIntParaBinario16(int valor);
    string conversorIntParaBinario24(int valor);

public:
    Conversor();

    int getEnderecoComecoMemmoriaTexto();
    Memoria *getMemoria();
};

Conversor::Conversor()
{

    enderecoComecoMemoriaTexto = 0;
    enderecoMemoriaTexto = enderecoComecoMemoriaTexto;
    memoria = new Memoria();
    leituraArquivoEntrada();
}

void Conversor::leituraArquivoEntrada()
{

    string nome_arquivo_entrada;

    cout << "Digite o nome do arquivo de texto: ";
    cin >> nome_arquivo_entrada;

    ifstream arquivo_entrada("textos/" + nome_arquivo_entrada);

    if (arquivo_entrada)
    {

        string instrucaoAtual;
        vector<string> *instrucaoAtualSeparada = NULL;
        bool primeiro = false, ehAddress = false;
        int aux = 0;

        do
        {

            getline(arquivo_entrada, instrucaoAtual);

            vector<string> *instrucaoAtualSeparada = separarString(instrucaoAtual, " ");

            if (instrucaoAtualSeparada->empty())
            {
                continue;
            }

            if (instrucaoAtualSeparada->at(0) == "address")
            {

                bool auxBool = verificarIntAddress(instrucaoAtualSeparada->at(1), aux);

                ehAddress = true;
            }

            if (instrucaoAtualSeparada->at(0) != "EOF")
            {

                instrucaoAtual = retornarInstrucaoEmString(instrucaoAtualSeparada);
                delete instrucaoAtualSeparada;

                // registro da instrucao na memoria
                memoria->armazenarInstrucao(instrucaoAtual, enderecoMemoriaTexto);
                enderecoMemoriaTexto++;

                if (ehAddress)
                {

                    enderecoMemoriaTexto = aux;

                    if (!primeiro)
                        enderecoComecoMemoriaTexto = enderecoMemoriaTexto;

                    ehAddress = false;
                }

                primeiro = true;
            }

        } while (instrucaoAtual != "EOF" || arquivo_entrada.eof());

        if (instrucaoAtual != "EOF") // alteração da massa
        {
            throw("Impossivel concluir a aplicação");
        }

        arquivo_entrada.close();
    }
    else
    {
        throw("Arquivo invalido");
    }
}

bool Conversor::verificarIntAddress(string str, int &aux)
{
    aux = stoi(str);

    if (aux >= 16384 or aux < 0)
        return false;
    else
        return true;
}

vector<string> *Conversor::separarString(string str, string delimiter)
{

    // remove virgulas
    str.erase(remove(str.begin(), str.end(), ','), str.end());

    // remove R
    str.erase(remove(str.begin(), str.end(), 'R'), str.end());

    // remove espaços adjacentes
    string str_result;
    string palavra;
    istringstream iss(str);

    while (iss >> palavra)
    {

        if (!str_result.empty())
        {

            str_result += ' ';
        }
        str_result += palavra;
    }

    str = str_result;

    int start = 0;
    int end = str.find(delimiter);

    vector<string> *splitStr = new vector<string>;
    string aux;

    while (end != -1)
    {

        aux = str.substr(start, end - start);
        splitStr->push_back(aux);
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    aux = str.substr(start, end - start);
    splitStr->push_back(aux);

    if (splitStr->back() == "" or splitStr->back() == " ")
    {

        splitStr->pop_back();
    }

    return splitStr;
}

string Conversor::retornarInstrucaoEmString(vector<string> *vect)
{

    // Instrucoes do UFLA-RISC (23)
    if (vect->at(0) == "address")
    {
        return (conversorIntParaBinario8(0) + conversorIntParaBinario24(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "add")
    {
        return (conversorIntParaBinario8(1) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "sub")
    {
        return (conversorIntParaBinario8(2) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "zeros")
    {
        return (conversorIntParaBinario8(3) + conversorIntParaBinario8(0) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "xor")
    {
        return (conversorIntParaBinario8(4) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "or")
    {
        return (conversorIntParaBinario8(5) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "passnota")
    {
        return (conversorIntParaBinario8(6) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "and")
    {
        return (conversorIntParaBinario8(7) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "asl")
    {
        return (conversorIntParaBinario8(8) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "asr")
    {
        return (conversorIntParaBinario8(9) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "lsl")
    {
        return (conversorIntParaBinario8(10) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "lsr")
    {
        return (conversorIntParaBinario8(11) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "passa")
    {
        return (conversorIntParaBinario8(12) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "lch")
    {
        return (conversorIntParaBinario8(13) + conversorIntParaBinario16(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "lcl")
    {
        return (conversorIntParaBinario8(14) + conversorIntParaBinario16(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "load")
    {
        return (conversorIntParaBinario8(15) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "store")
    {
        return (conversorIntParaBinario8(16) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "jal")
    {
        return (conversorIntParaBinario8(17) + conversorIntParaBinario24(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "jr")
    {
        return (conversorIntParaBinario8(18) + conversorIntParaBinario8(0) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "beq")
    {
        return (conversorIntParaBinario8(19) + conversorIntParaBinario8(stoi(vect->at(1))) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))));
    }
    else if (vect->at(0) == "bne")
    {
        return (conversorIntParaBinario8(20) + conversorIntParaBinario8(stoi(vect->at(1))) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))));
    }
    else if (vect->at(0) == "j")
    {
        return (conversorIntParaBinario8(21) + conversorIntParaBinario24(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "halt")
    {
        return "11111111111111111111111111111111";
    }

    // Instrucoes do grupo (9)
    else if (vect->at(0) == "slt")
    {
        return (conversorIntParaBinario8(22) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "slti")
    {
        return (conversorIntParaBinario8(23) + conversorIntParaBinario8(stoi(vect->at(1))) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))));
    }
    else if (vect->at(0) == "smt")
    {
        return (conversorIntParaBinario8(24) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "inc")
    {
        return (conversorIntParaBinario8(25) + conversorIntParaBinario8(0) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "dec")
    {
        return (conversorIntParaBinario8(26) + conversorIntParaBinario8(0) + conversorIntParaBinario8(0) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "addi")
    {
        return (conversorIntParaBinario8(27) + conversorIntParaBinario8(stoi(vect->at(1))) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))));
    }
    else if (vect->at(0) == "subi")
    {
        return (conversorIntParaBinario8(28) + conversorIntParaBinario8(stoi(vect->at(1))) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))));
    }
    else if (vect->at(0) == "nand")
    {
        return (conversorIntParaBinario8(29) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }
    else if (vect->at(0) == "nor")
    {
        return (conversorIntParaBinario8(30) + conversorIntParaBinario8(stoi(vect->at(2))) + conversorIntParaBinario8(stoi(vect->at(3))) + conversorIntParaBinario8(stoi(vect->at(1))));
    }

    else
    {
        throw("Instrução invalida");
    }
}

string Conversor::conversorIntParaBinario8(int valor)
{
    if (valor < -128 or valor > 127)
    {
        throw("Overflow");
    }

    string str = bitset<8>(valor).to_string();

    return str;
}

string Conversor::conversorIntParaBinario16(int valor)
{
    if (valor < -32768 or valor > 32767)
    {
        throw("Overflow");
    }

    string str = bitset<16>(valor).to_string();

    return str;
}

string Conversor::conversorIntParaBinario24(int valor)
{

    if (valor < -8388608 or valor > 8388607)
    {
        throw("Overflow");
    }

    string str = bitset<24>(valor).to_string();

    return str;
}

int Conversor::getEnderecoComecoMemmoriaTexto()
{

    return enderecoComecoMemoriaTexto;
}

Memoria *Conversor::getMemoria()
{

    return memoria;
}
