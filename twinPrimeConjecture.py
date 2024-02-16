import os

os.system('clear')
print("Welcome to our Twin Prime Conjecture Calculator")

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def find_twin_primes(limit):
    twin_primes = []
    for num in range(3, limit + 1):
        if is_prime(num) and is_prime(num - 2):
            twin_primes.append((num - 2, num))
    return twin_primes

limit = int(input("Enter the limit to find twin primes up to: "))
result = find_twin_primes(limit)

print(f"Twin primes up to {limit}: {result}")
