#include <stdio.h>
#include "duende.h"
#include "dtime.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 3;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times, qtdTimes);

    return 0; //nao remova
}
//A funçao "proximomaisvelho" sera executada (n/2+n) vezes.logo, como o maior expoente encrontado nas variaveis "n" é 1,
//pode se afirmar q a ordem de complexidade da funçao é n¹;

//A funçao "escalarTimes" sera executada (3*n) vezes desconsiderando as funçoes internas, sendo asism temos uma funçao de complexidade n¹.
//Porem quandos consideramos as funçoes de dentro, mais especificamente a "proximomaisvelho", temos agora uma equaçao = (3n*(n/2+n)).Sendo assim,
//a ordem de complexidade passa para n²