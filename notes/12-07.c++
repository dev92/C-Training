typedef int foo;

using foo = int;

int (*)(int, int) same as int (int, int)

int    a[] = {2, 3, 4};
double x[10];
double* p = copy(a, a + 3, x);

template <typename II, typename OI>
OI copy (II b, II e, OI o)  {
    while (b != e) {
        *o = *b;
        ++b;
        ++o;}
    return o;}

const list<int> y(...);
list<int>::const_iterator p = begin(y);
++p;
equal(..., p);
