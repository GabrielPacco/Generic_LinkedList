#ifndef __ITERATOR__
#define __ITERATOR__

template <typename T>
class Iterator
{
public:
    virtual bool HasNext()const = 0;
    virtual T Next() = 0;
};

#endif