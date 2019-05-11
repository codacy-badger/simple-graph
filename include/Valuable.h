#ifndef _VALUABLE_
#define _VALUABLE_

template <typename Vtype = double>
class Valuable {
protected:
    bool valued;

public:
    Valuable() : valuated(false), value(0) {};
    ~Valuable() {};
    Vtype value;
    virtual void set_value (Vtype __v) {
        value = __v;
    };
};

#endif