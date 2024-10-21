# **ARQUITETURA - Simulador de Instruções RISC**

## **GCC123 - Arquitetura de Computadores II**

Este projeto é uma implementação de um processador RISC simplificado para a disciplina de Arquitetura de Computadores II da Universidade Federal de Lavras (UFLA).

### Estrutura do Projeto

O projeto está organizado da seguinte forma:

### Descrição dos Arquivos

- **dev/Alu.hpp**: Implementação da Unidade Lógica e Aritmética (ALU).
- **dev/App.cpp**: Arquivo principal que inicializa e executa o processador.
- **dev/Controle.hpp**: Implementação da unidade de controle do processador.
- **dev/Conversor.hpp**: Conversor de instruções.
- **dev/ExeM.hpp**: Estágio de execução/memória do pipeline.
- **dev/If-Id.hpp**: Estágio de busca de instrução/decodificação do pipeline.
- **dev/Memoria.hpp**: Implementação da memória do processador.
- **dev/Processador.hpp**: Implementação do processador RISC.
- **dev/Registradores.hpp**: Implementação do banco de registradores.
- **dev/Wb.hpp**: Estágio de write-back do pipeline.

### Exemplos

A pasta `examples/` contém arquivos de exemplo para testar o processador:

- **examples/exemplo.txt**: Exemplo básico de execução.
- **examples/exemploGeral.txt**: Exemplo geral de instruções.
- **examples/exemploTudo.txt**: Exemplo com todas as instruções suportadas.
- **examples/OutroTeste.txt**: Outro teste de execução.

### Como Compilar e Executar

Para compilar o projeto, utilize um compilador C++ como o `g++`. Navegue até a pasta `dev/` e execute o seguinte comando:

```sh
g++ -o processador App.cpp
```

Para executar o processador, utilize o comando:

```sh
./processador
```

## Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.