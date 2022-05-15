SOURCES = Funcionarios/Diretor/Diretor.o \
        Funcionarios/Funcionario/Funcionario.o \
		Funcionarios/Gerente/Gerente.o \
    	Funcionarios/Operador/Operador.o \
		GerenciamentoFuncionarios/Data/Data.o \
		Funcionarios/Presidente/Presidente.o \
		GerenciamentoFuncionarios/Endereco/Endereco.o \
		main.o \
		GerenciamentoFuncionarios/Data/Data.o \
		GerenciamentoFuncionarios/Endereco/Endereco.o
CC = g++
PROGRAM_NAME = SGFP

SGFP*: $(SOURCES)
	$(CC) -o $(PROGRAM_NAME) $(SOURCES)