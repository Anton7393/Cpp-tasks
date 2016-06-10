#ifndef PET_H
#define PET_H

class Pet
{
    public:
        virtual const char * say();
        virtual bool gnaw();
        virtual int lifes();
    private:
		virtual void pets( bool flag = false );
};

#endif//PET_H
