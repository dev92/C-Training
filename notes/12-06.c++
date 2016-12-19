C++ concepts

int i = 2;
int j = 3;
int k = (2 << 3);
(2 << 3); // not ok

i <<= 3;
int m = (i <<= 3);

++(2 << 3);  // not ok
++(i <<= 3); // C, Java, not ok, C++, ok

// type of 2 is int
// type of 2.3 is double
// type of cout is ostream
// type of cin  is istream

(cout << "hi") << "bob";

// operator overloading
//     1. you can't invent operator (e.g. ,,,)
//     2. you can't define operator (e.g. << on float)
//     3. you can overload an operator (e.g. << on ostream)
//     4. can't change precedence
//     5. can't change associativity
//     6. can't change arity
//     7. can change r-value/l-value nature of the args and the return

// a + b * c
// a - b - c
// a = b = c

// r-values: can not be on the lhs of assignment
// r-values: don't have an address

// l-values: can be on the lhs of assignment
// l-value:  do have an address

// 100 year old math conjecture
// Collatz Conjecture

// take a pos int
// if even, divide by 2
// if odd,  multiply by 3 and add 1
// repeat until 1

// 5 16 8 4 2 1
// cycle length of 5  is 6
// cycle length of 10 is 7

// 1. run it as is, confirm success
// 2. identify and fix the broken tests, confirm failure
// 3. fix the code, confirm success

int i = 2;
int j = ++i;
int k = i++;

// ++i returns i AFTER  incrementing
// i++ returns i BEFORE incrementing

++i;
i++;

for (I i = 0; ...; ++i)
    ...

int i = 0;
while ... {
   ...
   ++i;}

++++i;        // C, Java, not ok, C++, ok
cout << &++i; // ok

++(i++);        // not ok
cout << &(i++); // not ok

j = ++(i++); // not ok

++2 // ok
2++ // not ok

cout << &(i + j); // not ok
++(i + j);        // not ok

int f (...) {
    ...
    if (<something wrong>) {
	    throw E2(...);}
            ...}

int g (...) {
    ...
    try {
    	...
    	int i = f(...);
	    ...}
    catch (E e)
    	<something wrong>
    ...}

void f (int i) {...}


void g (string s) {...}


void h (vector<int> v) {...}

int main () {
    f(2.34);
    f(2);

    string t("abc");
    g(t);
    g("abc");

    vector<int> x(10000);
    h(x);
    h(10000);

// two tokens:   *, &
// two contexts: next to a type
//               next to a variable

int main () {
    int i = 2;
    int v = i;
    ++v;
    cout << i; // 2

    int  i = 2;
    int* p = &i;
    ++*p;
    cout << i; // 3

    int  i = 2;
    int& r;     // not ok
    int& r = i;
    ++r;
    cout << i;  // 3
    ++i;
    cout << r;  // 4
    cout << (&i == &r); // true

    int*  p = &i;
    int*& r = p;
    ++*p;
    ++*r;
    cout << (&p == &r); // true

    type  x;
    type& r = x;

    int i = ...;
    int j = i;

    type x = ...;
    type y = x;

    equal(a + 10, a + 15, b + 20);

// OO languages are to convert certain
// classes of runtime into compile
// time errors

void f (int* p) {
    ++*p;}

void g (int& r) {
    ++r;}

int main () {
    int i = 2;
    f(0);
    cout << i; // 3
    g(0);
    cout << i; // 4

    int a[] = {2, 3, 4};
    int b[] = {0, 2, 3, 4, 0};
    cout << equal(a, a + 3, b);     // false
    cout << equal(a, a + 3, b + 1); // true

template <typename T1, typename T2
bool equal (T1 b, T1 e, T2 x) {
    while (b != e) {
	if (*b != *x)
	    return false;
	++b;
	++x;}
    return true;}

int main () {
    vector<int> x(...);
    forward_list<int>   y(...);
    ostream_iterator<int> m(cout);
    istream_iterator<int> n(cin);

    cout << equal(begin(x), end(x), begin(y));

// categories of iterator
// 1. input iterator
//     ++, * (read only), ==, !=
// 2. output iterator
//     ++, * (write only)
// 3. forward iterator
//     ++, * (read / write), ++, !=
// 4. bidirectional iterator
//     <forward>, --
// 5. random access iterator
//     <bidirectional iterator>, +, -, [], <, >, <=, >=
