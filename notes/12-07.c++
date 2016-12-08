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

int x[3];
fill(x, x + 3, 2.34);

template <typename FI, typename T>
void fill (FI b, FI e, T v) {
    while (b != e) {
        *b = v;
        ++b;}}

      int i  = 2; // initialization optional
const int ci = 3; // initialization required
++ci; // not ok

int* p = &i; // ok
++*p;
p = &ci;     // not ok
++*p;

const int* pc;       // ok
const int* pc = &ci;
++*pc;               // not ok
++pc;                // ok
pc = &i;             // ok
int* tmp = pc;       // not ok

int* const cp;       // not ok
int* const cp = &ci; // not ok
int* const cp = &i;  // ok
++*cp;               // ok
++cp;                // not ok

int* const p = new int[1000];
...
++p; // not ok
...
delete [] p;

const int* const cpc;       // not ok
const int* const cpc = &ci;
const int* const cqc = &i;
++cpc;                      // not ok
++*cpc;                     // not ok

      int a[] = {2, 3, 4}; //       int* const a
const int a[] = {2, 3, 4}; // const int* const a

struct A {
    int i;

    void f () {
        // there's a special keyword, this
        // A* const this;
        //i = (3 * i) + 1;
        g();
        }

    void g () const {
        // const A* const this;
        f();          // not ok
        i = 0;}};     // not ok

void h (const A& r) {...}

int main () {
    A x;
    x.i = 2;
    x.f(); // this is a pointer to x
    cout << x.i; // 7
    A y;
    y.f(); // this is a pointer to y
    h(y);


    const A z;
    z.f(); // not ok
    z.g(); // ok






























