/* A struct too big for registers is returned through a hidden pointer
   passed ahead of the declared arguments; on riscv32 a 64-bit argument
   after it was taken for a variadic one and moved to an even register
   pair.  lldiv is the libc case. */
#include <stdio.h>
#include <stdlib.h>

struct big { long long a, b; int c; };

struct big mk(long long x, long long y, int z)
{
    struct big r = { x, y, z };
    return r;
}

int main(void)
{
    lldiv_t q = lldiv(100000000007LL, 10LL);
    struct big b = mk(1LL << 40, -3, 7);
    printf("%lld %lld\n", q.quot, q.rem);
    printf("%lld %lld %d\n", b.a, b.b, b.c);
    return 0;
}
