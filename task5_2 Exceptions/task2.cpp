#include <iostream>
#include <exception>

class BaseException
{
public:
    virtual const char * exceptionName() const { return "base error"; };

};

class InputErrorException : public BaseException
{
public:
    virtual const char * exceptionName() const { return "input error"; };
};

class LogicErrorException : public BaseException
{
public:
    virtual const char * exceptionName() const { return "logic error"; };
};


int f()
{
    //...
    throw LogicErrorException();
    //...
    throw InputErrorException();
    // ...
    throw BaseException();
}


int main()
{
    try
    {
        f();
    }
    catch(LogicErrorException & exc)
    {
        std::cout << "Caught LogicErrorException" << std::endl;
    }
    catch(InputErrorException & exc)
    {
        std::cout << "Caught InputErrorException" << std::endl;
    }
    catch(BaseException & exc)
    {
        std::cout << "Caught BaseException" << std::endl;
    }

    return 0;
}
