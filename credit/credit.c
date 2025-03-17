#include <stdio.h>

int get_digit(long n, int power)
{
    while (n >= power)
        n = n / 10;

    return n;
}

int get_len(long n) {
    int digits = 1;

    while (n >= 10) {
        n = n / 10;
        digits++;
    }

    return digits;
}

int get_sum(long n) {
    long aux_rest = n;
    int aux_last;
    int aux = 1;
    int others_a = 0;
    int others_b = 0;

    for (int curr = 0; aux_rest > 0; curr++)
    {
        aux_last = aux_rest % 10;
        aux_rest = aux_rest / 10;

        if (aux == -1)
        {
            if ((aux_last * 2) > 9)
            {
                others_a = others_a + (aux_last * 2) - 9;
            }
            else
            {
                others_a = others_a + (aux_last * 2);
            }
        }

        if (aux == 1)
        {
            others_b = others_b + aux_last;
        }

        aux = aux * -1;
    }

    return others_a + others_b;
}

int main(void){
    long n = 4012888888881881;
    int len = get_len(n);

    printf("Number: %li\n", n);

    int sum = get_sum(n);

    if (sum % 10 == 0) {
        int first_digit = get_digit(n, 10);
        int first_two_digits = get_digit(n, 100);

        if ((len == 13 || len == 16) && first_digit == 4)
            printf("VISA\n");
        else if (len == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
            printf("MASTERCARD\n");
        else if (len == 15 && (first_two_digits == 34 || first_two_digits == 37))
            printf("AMEX\n");
        else 
            printf("INVALID\n");
    } else {
        printf("INVALID\n");
    }
}

