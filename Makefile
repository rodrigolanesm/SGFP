SGFP: main.o Diretor.o Funcionario.o Gerente.o Operador.o Presidente.o Data.o Endereco.o GerenciamentoFuncionarios.o Salarios.o MainMenu.o
	g++ main.o Diretor.o Funcionario.o Gerente.o Operador.o Presidente.o Data.o Endereco.o GerenciamentoFuncionarios.o Salarios.o MainMenu.o -o SGFP
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

Data.o: Utilitarios/Data/Data.cpp
	g++ -c Utilitarios/Data/Data.cpp

Endereco.o: Utilitarios/Endereco/Endereco.cpp
	g++ -c Utilitarios/Endereco/Endereco.cpp 

GerenciamentoFuncionarios.o: Utilitarios/GerenciamentoFuncionarios/GerenciamentoFuncionarios.cpp
	g++ -c Utilitarios/GerenciamentoFuncionarios/GerenciamentoFuncionarios.cpp

Salarios.o: Utilitarios/Salarios/Salarios.cpp
	g++ -c Utilitarios/Salarios/Salarios.cpp

MainMenu.o: Menu/MainMenu.cpp
	g++ -c Menu/MainMenu.cpp

clean:
	del *.o