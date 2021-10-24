#include "Parque.cpp"
#include <string>
using namespace std;

int main () {

    string answer;

    ParqueEstacionamento p1(4, 6);
    cout << "Testa se o parque foi aberto com a lotação indicada: ";
    answer = p1.getNumLugares() == 4 ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se o parque foi aberto com o número maximo de clientes indicado: ";
    answer = p1.getNumMaximoClientes() == 6 ? "Correct" : "Error" ; cout << answer << endl;

    ParqueEstacionamento p2(3, 5);
    cout << "Testa se deixa adicionar um novo cliente: ";
    answer = p2.adicionaCliente("Joao") ? "Correct" : "Error" ; cout << answer << endl;
    p2.adicionaCliente("Antonio");
    p2.adicionaCliente("Rui");
    p2.adicionaCliente("Maria");
    p2.adicionaCliente("Clara");
    cout << "Testa se recusa novo cliente quando numero maximo de clientes foi atingido: ";
    answer = !p2.adicionaCliente("Paula") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se retorna a posição correcta do cliente: ";
    answer = p2.posicaoCliente("Antonio") == 1 ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se retorna -1 caso o cliente não exista: ";
    answer = p2.posicaoCliente("Joana") == -1 ? "Correct" : "Error" ; cout << answer << endl;

    ParqueEstacionamento p3(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.adicionaCliente("Rui");
    cout << "Testa se deixa entrar no parque um cliente existente: ";
    answer = !p3.entrar("Maria") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se não deixa entrar no parque um cliente que não existe: ";
    answer = !p3.entrar("Paula") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se não deixa entrar em cliente que já lá está: ";
    answer = !p3.entrar("Maria") ? "Correct" : "Error" ; cout << answer << endl;
    p3.entrar("Joao");
    p3.entrar("Antonio");
    cout << "Testa se não deixa entrar quando a lotação está completa: ";
    answer = !p3.entrar("Rui") ? "Correct" : "Error" ; cout << answer << endl;

    ParqueEstacionamento p4(3, 5);
    p4.adicionaCliente("Joao");
    p4.adicionaCliente("Maria");
    p4.adicionaCliente("Antonio");
    p4.entrar("Maria");
    cout << "Testa se não deixa remover cliente que está dentro do parque: ";
    answer = !p4.retiraCliente("Maria") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se deixa remover cliente que está fora do parque: ";
    answer = p4.retiraCliente("Antonio") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se não deixa remover cliente que não existe: ";
    answer = !p4.retiraCliente("Ana") ? "Correct" : "Error" ; cout << answer << endl;

    ParqueEstacionamento p5(3, 5);
    p5.adicionaCliente("Joao");
    p5.adicionaCliente("Maria");
    p5.adicionaCliente("Rui");
    p5.entrar("Maria");
    p5.entrar("Joao");
    p5.entrar("Rui");
    cout << "Testa se um cliente estacionado no parque, sai: ";
    answer = p5.sair("Maria") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se não deixa sair um cliente que não está estacionado: ";
    answer = !p5.sair("Maria") ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se não deixa sair um cliente que não existe: ";
    answer = !p5.sair("Antonio") ? "Correct" : "Error" ; cout << answer << endl;

    ParqueEstacionamento p6(3, 5);
    p6.adicionaCliente("Joao");
    p6.adicionaCliente("Maria");
    p6.adicionaCliente("Antonio");
    p6.entrar("Maria");
    p6.entrar("Antonio");
    cout << "Testa se lotação do parque está correcta: ";
    answer = p6.getNumLugares() == 3 ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se o número de viaturas presentes no parque está correcto: ";
    answer = p6.getNumLugaresOcupados() == 2 ? "Correct" : "Error" ; cout << answer << endl;
    cout << "Testa se o número de clientes registados no parque está correcto: ";
    answer = p6.getNumClientesAtuais()  == 3 ? "Correct" : "Error" ; cout << answer << endl;

    return 0;
}