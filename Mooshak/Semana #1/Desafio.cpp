// Created on 14 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Considerando as restrições do Problema, o maior valor inicial será 10^16 e o intervalo máximo 10^18,
 * pelo que o valor a retornar terá, no máximo, 18 algarismos.
 */
const int NUM_ALGA = 18;

/**
 * Uma função simples que retorna a soma de todos os dígitos do @param attemp
 * Como a soma dos dígitos está compreendida no intervalo [0..100], basta retornar um inteiro (e não long ou long long)
 */
int sumN(long long int attemp) {

    int currentSum = 0, digit;
    while (attemp) {
        digit = attemp % 10;
        attemp = attemp / 10;
        currentSum += digit;
    }
    return currentSum;
}

/**
 * Descobri a solução para o problema ontem quando estudava o CountingSort. Ao colocar os números dentro de
 * "caixas" lembrei que poderia usar esse esquema para colocar cada algarismo do long long int apresentado como input
 * num vector de inteiros. Assim é fácil manipular cada dígito separadamente até atingir a soma pedida sem chamar sempre
 * a função sumN().
 */
long long int solve (long long int num, int sum) {

    vector<int> digits(NUM_ALGA);               // O vector que irá guardar os dígitos.
    int casa = digits.size() - 1, digit;        // "casa" será o index que percorrerá os dígitos do fim para o início
    int currentSum = 0;

    /**
     * Um problema recorrente é quando a soma atual do valor dado como input já é maior do que a soma pedida.
     * Assim optei por somar iterativamente até que a situação ficasse favorável ao problema.
     */
    while (sumN(num) >= sum) num++;

    /**
     * O vector digits fica com cada um dos dígitos iniciais do valor.
     * CurrentSum ficará também com a soma dos dígitos atual.
     */
    while (num) {
        digit = num % 10;
        digits[casa] = digit;
        casa--;
        num = num / 10;
        currentSum += digit;
    }

    casa = digits.size() - 1;           // Volta a apontar para o último dígito
    int sobra = sum - currentSum;       // Sobra é o número que terei de incrementar ao vector até prefazer a soma pretendida

    while (sobra) {                     // Enquanto houver número a incrementar a dígitos

        int possivel = 9 - digits[casa]; // possível --> o que falta para preencher a casa até um máximo de 9
        if (sobra >= possivel) {
            digits[casa] += possivel;
            sobra -= possivel;
        } else {
            digits[casa] += sobra;
            sobra = 0;
        }
        casa--;
    }

    long long int result = 0;           // Reconstrução do número, agora com a soma correcta
    int index = digits.size() - 1;
    int exponent = 0;
    while (index) {
        result = result + digits[index] * pow(10, exponent);
        index--;
        exponent++;
    }
    return result;

}

int main() {

    /** Solve() tests:
   long long int number;
   int sum, lines;

   cin >> lines;
   for (int i = 0 ; i < lines ; i++) {
       cin >> number >> sum;
       cout << solve(number, sum) << endl;
   }
      */

   cout << solve(100000599988, 50) << endl;
   cout << solve(100000599989, 50) << endl;
   cout << solve(100000599998, 50) << endl;
   cout << solve(987654321098, 100) << endl;
   cout << solve(12121678909876, 42) << endl;
   cout << solve(12121128909876, 42) << endl;
   cout << solve(1, 92) << endl;


    return 0;
}