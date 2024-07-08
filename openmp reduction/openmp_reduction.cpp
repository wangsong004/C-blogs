#include <iostream>
#include <omp.h>

int main() {
    const int n = 10;
    int sum = 0, prod = 1, diff = 0;
    int bit_and = ~0, bit_or = 0, bit_xor = 0;
    int log_and = 1, log_or = 0;
    int a[n] = {0xF, 0xE, 0xD, 0xC, 0xB, 0xA, 0x9, 0x8, 0x7, 0x6};
    int b[n] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; // For logical operations

#pragma omp parallel for reduction(+:sum) reduction(*:prod) reduction(-:diff) \
    reduction(&:bit_and) reduction(|:bit_or) reduction(^:bit_xor) \
        reduction(&&:log_and) reduction(||:log_or)
        for (int i = 0; i < n; ++i) {
        sum += a[i];
        prod *= a[i];
        diff -= a[i];
        bit_and &= a[i];
        bit_or |= a[i];
        bit_xor ^= a[i];
        log_and = log_and && b[i];
        log_or = log_or || b[i];
    }

    std::cout << "Sum = " << sum << "\n";
    std::cout << "Product = " << prod << "\n";
    std::cout << "Difference = " << diff << "\n";
    std::cout << "Bitwise AND = 0x" << std::hex << bit_and << std::dec << "\n";
    std::cout << "Bitwise OR = 0x" << std::hex << bit_or << std::dec << "\n";
    std::cout << "Bitwise XOR = 0x" << std::hex << bit_xor << std::dec << "\n";
    std::cout << "Logical AND = " << log_and << "\n";
    std::cout << "Logical OR = " << log_or << "\n";

    return 0;
}
