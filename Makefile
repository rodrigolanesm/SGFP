SGFP: main.o Diretor.o Funcionario.o Gerente.o Operador.o Presidente.o Data.o Endereco.o
	g++ main.o Diretor.o Funcionario.o Gerente.o Operador.o Presidente.o Data.o Endereco.o -o SGFP
	del *.o
	
main.o: main.cpp
	g++ -c main.cpp

Diretor.o: Funcionarios/Diretor/Diretor.cpp
	g++ -c Funcionarios/Diretor/Diretor.cpp

Funcionario.o: Funcionarios/Funcionario/Funcionario.cpp
	g++ -c Funcionarios/Funcionario/Funcionario.cpp

Gerente.o: Funcionarios/Gerente/Gerente.cpp
	g++ -c Funcionarios/Gerente/Gerente.cpp

Operador.o: Funcionarios/Operador/Operador.cpp
	g++ -c Funcionarios/Operador/Operador.cpp

Presidente.o: Funcionarios/Presidente/Presidente.cpp
	g++ -c Funcionarios/Presidente/Presidente.cpp

Data.o: GerenciamentoFuncionarios/Data/Data.cpp
	g++ -c GerenciamentoFuncionarios/Data/Data.cpp

Endereco.o: GerenciamentoFuncionarios/Endereco/Endereco.cpp
	g++ -c GerenciamentoFuncionarios/Endereco/Endereco.cpp

clean:
	del *.o