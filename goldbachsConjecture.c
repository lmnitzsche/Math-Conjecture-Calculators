#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to generate primes up to a specified limit
void generatePrimes(bool *isComposite, int limit) {
    for(int i = 2; i <= limit; i++) {
        if(!isComposite[i]) {
            for(int j = i * 2; j <= limit; j += i) {
                isComposite[j] = true;
            }
        }
    }
}

// Function to check if a number is prime
bool isPrime(int num) {
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 5; i * i <= num; i = i + 6) {
        if(num % i == 0 || num %(i + 2) == 0) return false;
    }
    return true;
}

// Function to verify Goldbach's conjecture
void verifyGoldbach(int limit) {
    bool *isComposite = malloc((limit + 1) * sizeof(bool));
    if(isComposite == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for(int i = 0; i <= limit; i++) {
        isComposite[i] = false;
    }

    generatePrimes(isComposite, limit);

    for(int i = 4; i <= limit; i += 2) { // Checking even numbers starting from 4
        bool found = false;
        for(int prime = 2; prime < i; prime++) {
            if(!isComposite[prime] && isPrime(i - prime)) {
                printf("%d = %d + %d\n", i, prime,(i - prime));
                found = true;
                break;
            }
        }
        if(!found) {
            printf("Goldbach's conjecture is false for %d\n", i);
            break;
        }
    }
    free(isComposite);
}

int main() {
    int limit;
    printf("Enter the limit for even numbers to check: ");
    scanf("%d", &limit);
    verifyGoldbach(limit);
    return 0;
}
