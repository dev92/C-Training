// variables in C++
// local and local static
// global and global static
// class (instance) and class static (class)

void f () {
    ...
    int i = g(...);
    ...}

// 1. how many are there
//      one per call
// 2. when are they allocated
//      on function entry
// 3. when are they initialized
//      on the line
// 4. what is their lifetime
//      the lifetime of the call
// 5. what is their scope
//      inside of the scope after the definition

void f () {
    ...
    static int i = g(...);
    ...}

// 1. how many are there
//      one
// 2. when are they allocated
//      on program entry
// 3. when are they initialized
//      on the line, first time only
// 4. what is their lifetime
//      the lifetime of the program
// 5. what is their scope
//      inside of the scope after the definition

// foo.c++
int i = g(...); // definition

// bar.c++
extern int i; // declaration

void f () {
    ++i;}

// 1. how many are there
//      one
// 2. when are they allocated
//      on program entry
// 3. when are they initialized
//      on program entry
// 4. what is their lifetime
//      the lifetime of the program
// 5. what is their scope
//      the program

// foo.c++
static int i = g(...); // definition

// bar.c++
extern int i; // declaration, not ok, won't link

void f () {
    ++i;}

// 1. how many are there
//      one
// 2. when are they allocated
//      on program entry
// 3. when are they initialized
//      on program entry
// 4. what is their lifetime
//      the lifetime of the program
// 5. what is their scope
//      the file

A* p = new A;
p.im();       // not ok
*p.im();      // not ok
(*p).im();    // ok
p->im();      // ok

struct A {
    A (int) {}};

int main () {
    A x; // not ok

// 1. A(), default constructor
// 2. A(A), copy constructor
// 3. =(A), copy assignment operator
// 4. ~A(), destructor

class A {
    private:
        int _i;
    public:
        A (int i) {
            _i = i;}
        A (const A& rhs) {
            _i = rhs._i;}
        A& operator = (const A& rhs) {
            _i = rhs._i;
            return *this;}

void f (A z) {...}

int main () {
    A x(2);
    A y(x);         // copy constructor
    A y = x;        // copy constructor
    f(x);
    y = x;          // copy assignment
    y.operator=(x);
    ++(y = x);

void f (vector<int> z) {...}

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;
    public:
        vector (const vector& rhs) {
            _s = rhs._s;
            _a = rhs._a;}
        vector& operator = (const vector& rhs) {
            _s = rhs._s;
            _a = rhs._a;
            return *this;}

int main () {
    vector<int> x(10, 2);
    vector<int> y(x);
    vector<int> y = x;
    f(x);
    vector<int> z(20, 3);
    x = z;
    x.operator=(z);

















