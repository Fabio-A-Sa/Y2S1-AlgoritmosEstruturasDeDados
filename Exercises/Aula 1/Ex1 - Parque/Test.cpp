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


    return 0;
}

/*

TEST(test_1, retirarCliente){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    // Testa se nao deixa remover cliente que esta dentro do parque
    ASSERT_EQ(false, p1.retiraCliente("Maria"));
    // Testa se deixa remover cliente que esta fora do parque
    ASSERT_EQ(true, p1.retiraCliente("Antonio"));
    // Testa se nao deixa remover cliente que nao existe
    ASSERT_EQ(false, p1.retiraCliente("Ana"));
}

TEST(test_1, sairParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Rui");
    p1.entrar("Maria");
    p1.entrar("Joao");
    p1.entrar("Rui");
    // Testa se um cliente estacionado no parque, sai.
    ASSERT_EQ(true, p1.sair("Maria"));
    // Testa se nao deixa sair um cliente que nao esta estacionado.
    ASSERT_EQ(false, p1.sair("Maria"));
    // Testa se nao deixa sair um cliente que nao existe.
    ASSERT_EQ(false, p1.sair("Antonio"));
}

TEST(test_1, lugaresLotacaoParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    p1.entrar("Antonio");
    // Testa se Lotacao do parque esta correcta
    ASSERT_EQ(3, p1.getNumLugares());
    // Testa se o numero de viaturas presentes no parque esta correcto
    ASSERT_EQ(2, p1.getNumLugaresOcupados());
    // Testa se o o numero de clientes registados no parque esta correcto
    ASSERT_EQ(3, p1.getNumClientesAtuais());
}
*/
