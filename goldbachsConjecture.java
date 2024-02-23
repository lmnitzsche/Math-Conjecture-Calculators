import java.util.*;

public class GoldbachConjecture {

    // Function to generate primes up to a specified limit
    public static ArrayList<Integer> generatePrimes(int limit) {
        ArrayList<Integer> primes = new ArrayList<>();
        boolean[] isComposite = new boolean[limit + 1];
        
        for (int i = 2; i <= limit; i++) {
            if (!isComposite[i]) {
                primes.add(i);
                for (int j = i * 2; j <= limit; j += i) {
                    isComposite[j] = true;
                }
            }
        }
        return primes;
    }

    // Function to check if a number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i = i + 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    // Function to verify Goldbach's conjecture
    public static void verifyGoldbach(int limit) {
        ArrayList<Integer> primes = generatePrimes(limit);
        for (int i = 4; i <= limit; i += 2) { // Checking even numbers starting from 4
            boolean found = false;
            for (int prime : primes) {
                if (prime >= i) break;
                if (isPrime(i - prime)) {
                    System.out.println(i + " = " + prime + " + " + (i - prime));
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("Goldbach's conjecture is false for " + i);
                break;
            }
        }
    }

    public static void main(String[] args) {
        int limit = 100; // Set the limit for even numbers to check
        verifyGoldbach(limit);
    }
}
