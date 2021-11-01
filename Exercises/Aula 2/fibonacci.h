
unsigned fibonacci_1(unsigned n) {

    unsigned valPrevPrev = 0, valPrev = 1;
    if (n == 0)
        return valPrevPrev;
    if (n == 1)
        return valPrev;
    unsigned val;
    for (unsigned i = 2; i <= n; i ++)
    {
        val = valPrevPrev + valPrev;
        valPrevPrev = valPrev;
        valPrev = val;
    }
    return val;

    // Complexidade espacial: O(1), o número de variáveis usadas não dependem do valor de n inicial
    // Complexidade temporal: O(n), o número de ciclos vai depender diretamente do valor de n inicial
}

unsigned fibonacci_2(unsigned n) {

    if (n <= 1)
        return n;
    return fibonacci_2(n-1) + fibonacci_2(n-2);

    // Complexidade espacial: O(n), o número de variáveis usadas depende do número de chamadas recursivas (n)
    // Complexidade temporal: O(2^n), o número de chamadas recursivas é sempre exponencial de base 2 (duas para cada valor de n)
}