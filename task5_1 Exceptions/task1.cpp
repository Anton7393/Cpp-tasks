#include <iostream>
#include <exception>

class BaseException
{
public:
    virtual const char * exceptionName() const { return "base exception"; };

};

class SpecialException : public BaseException
{
public:
    virtual const char * exceptionName() const { return "special exception"; };
};

int f()
{
    throw SpecialException();
}


int main()
{
    try
    {
        f();
    } catch(const BaseException & exc)
    {
        std::cout << "Caught exception: " << exc.exceptionName() << std::endl;
    }

    return 0;
}
