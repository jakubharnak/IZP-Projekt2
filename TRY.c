#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number <= 1)
        return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main() {
    int inputNumber;
    printf("Zadajte číslo: ");
    scanf("%d", &inputNumber);

    if (isPrime(inputNumber))
        printf("Číslo %d je prvočíslo.\n", inputNumber);
    else
        printf("Číslo %d nie je prvočíslo.\n", inputNumber);

    return 0;
}
