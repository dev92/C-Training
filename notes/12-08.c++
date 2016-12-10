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
        vector (const vector& rhs) {
            _s = rhs._s;
            _a = new T[_s];
            copy(rhs._a, rhs._a + _s, _a);}
//      vector (const vector& rhs) {
//          _a    = nullptr;
//          *this = rhs;}
        ~vector () {
            delete [] _a;}
        vector& operator = (const vector& rhs) {
            _s = rhs._s;
            _a = rhs._a;
            return *this;}
        vector& operator = (vector rhs) {
            swap(_s, rhs._s);
            swap(_a, rhs._a);
//          if (this == &rhs)
//              return *this;
//         _s = rhs._s;
//          delete [] _a;
//          _a = new T[_s];
//          copy(rhs._a, rhs._a + _s, _a);
            return *this;}

int main () {
    vector<int> x(10, 2);
    vector<int> y(x);
    vector<int> y = x;
    f(x);
    vector<int> z(20, 3);
    x = z;
    x.operator=(z);

// constructors exhibit refinement  overriding
// destructors  exhibit refinement  overriding
// methods      exhibit replacement overriding

class string {
    friend bool operator == (const string& lhs, const string& rhs) {
                strcmp(...)
    private:
        ...
    public:
        string (char*) {...}
//      bool operator == (const string& rhs) const {
//          strcmp(...)

void f (string u) {...}

int main () {
    const string s = "abc";
    const string t = "abc";
    cout << (s == t);         // true
//  cout << s.operator==(t);  // true
    cout << operator==(s, t); // ok
    f(s);
    f("abc");                 // ok
    f(2);                     // not ok
    cout << (s == "abc");     // ok
    cout << ("abc" == s);     // not ok, becomes ok with a function

class circle : public shape {
    friend bool operator == (const circle& lhs, const circle& rhs) {
        return (static_cast<const shape&>(lhs) == rhs) && (lhs._r == rhs._r);}
    private:
        int _r;
    public:
        circle (int x, int y, int r) :
            shape(x, y) {
            _r = r;}
        double area () const {
            return pi * r * r;}

struct A {
    int i;
    B   x;

int main () {
    int i;
    i = 2;
    const int j;
    int& k;

// 4 cases that need the member initialization list in a constructor
// 1. invoking the constructor of the parent that doesn't have a def constr
// 2. invoking the constructor of a   member that doesn't have def constr
// 3. a const     member
// 4. a reference member

struct A {
    void f () {}};

struct B : A {
    void f () {}};

struct C : A {
    void f () {}};

int main () {
    A x;
    x.f();        // A::f()
    B y;
    y.f();        // B::f()
    A* p = new B;
    p->f();       // A::f(), static binding

    if (...)
        p = new B;
    else
        p = new C;
    p->f();        // A::f()

struct A {
    friend bool operator == (const A& lhs, const A& rhs) {
        return lhs.equal(rhs);}
    virtual bool equal (const A& rhs) {
        ...}
    virtual void f () {}};

struct B : A {
    bool equal (const A& rhs) {
        B* p = dynamic_cast<B*>(&rhs);
        if (!p)
            return false;

    void f () {}};

struct C : A {
    bool equal (const A& rhs) {
        ...}
    void f () {}};

int main () {
    A* p;
    if (...)
        p = new B;
    else
        p = new C;
    p->f();        // B::f() or C::f(), dynamic binding
    A* q;
    if (...)
        q = new B;
    else
        q = new C;
    cout << (*p == *q);

// signatures are made up of 5 things
// 1. return type
// 2. name
// 3. number of args
// 4. type of args
// 5. const or not

struct A {
    void f (int) {}};

struct B : A {
    using A::f;
    void f (string) {}};

int main () {
    B x;
    x.f(2);

struct A {
    virtual void f (int) {}};

struct B : A {
    void f (long) {}};

int main () {
    A* p = new B;
    p->f(2);      // A::f(int)

class Shape {
    public:
        virtual double area () const = 0;
    ...};

class Triangle : public Shape {
    public:
        Triangle (...) {...}};

int main () {
    Triangle x(...);
    cout << x.area();

// 3 consequences to a pure virtual method (=0)
// 1. class becomes abstract
// 2. child defines the method or becomes abstract
// 3. definition in the base becomes optional

struct A {
    virtual ~A () = 0;};

A::~A() {}

// 3 consequences to a pure virtual destructor (=0)
// 1. class becomes abstract

struct A {
    virtual void f (int) final {}
    virtual void g (long) {}
    virtual void h (long) = 0;};

struct B : A {
    void f (int) {}
    virtual void g (int) override {}
    virtual void h (int) {}};

int main () {
    B x;
    x.f(2);       // B::f(int)
    A* p = new B;
    p->f(2);      // A::f(int)
