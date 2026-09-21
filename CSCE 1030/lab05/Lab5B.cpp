#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int rmax, rmin, sum = 0;

    rmax = rand() % 21 + 55;
    rmin = rand() % 21 + 15;

    int current = rmin;
    while (current <= rmax) {
        if (current % 2 == 0) {
            sum += current;
            printf("%d\n", current);
        }
        current++;
    }

    printf("First random number: %d\n", rmin);
    printf("Second random number: %d\n", rmax);
    printf("Sum of all even numbers between the two random numbers: %d\n", sum);

    return 0;
}
