//ar fi fost mai simplu sa adaug si un int val (sa retin nr in baza 10)

class Number
{
private:
    char *value;
    int base;
public:
    Number();
    Number(const char * value, int base); // where base is between 2 and 16
    Number(int value);
    ~Number();
    Number(const Number &n);
    Number(Number &&n);
    friend Number operator + (Number n1,Number n2);
    friend Number operator - (Number n1,Number n2);
    Number& operator = (int val);
    Number& operator = (const char * val);
    Number& operator = (Number n);
    Number& operator += (Number n);
    Number& operator -= (Number n);
    Number operator ! ();
    friend bool operator > (Number n1,Number n2);
    friend bool operator < (Number n1,Number n2);
    friend bool operator >= (Number n1,Number n2);
    friend bool operator <= (Number n1,Number n2);
    friend bool operator == (Number n1,Number n2);
    char& operator[](int index);
    Number& operator -- ();
    Number& operator -- (int val);
    // add operators and copy/move constructor
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};

// #define CRT_SECURE_NO_WARNING
