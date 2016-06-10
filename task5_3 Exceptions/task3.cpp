#include <iostream>
#include <exception>
#include <cstdio>


class AutoFile
{
public:
    class FileOpenError { };
    class FileCloseError {};

    AutoFile();
    ~AutoFile();

    void autoInit(const char * fileName);
    void autoClose();

    /* ... other operations */

private:
    static const std::size_t mBufSize = 100;

    FILE * mFile;
    char * mBuf;
    bool init;
};

AutoFile::AutoFile()
    : mFile(NULL)
    , mBuf(new char[mBufSize])
    , init(false)
{

}

AutoFile::~AutoFile()
{
    delete mBuf;
    if ((NULL != mFile) && (init))
    {
        if (0 != fclose(mFile))
            throw FileCloseError();
    }


}

void AutoFile::autoInit(const char * fileName)
{
    if (!init)
    {
        init = true;
        mFile = fopen(fileName, "r");
        if (NULL == mFile)
            throw FileOpenError();
    }
}

int main()
{
    try
    {
        AutoFile file;
        file.autoInit("test.txt");

        // any file operations

    }
    catch(AutoFile::FileOpenError & error)
    {
        std::cout << "Error: could not open specified file." << std::endl;
    }
    catch(AutoFile::FileCloseError & error)
    {
        std::cout << "Error: file close operation failed." << std::endl;
    }

    return 0;
}
