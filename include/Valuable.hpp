#ifndef _VALUABLE_
#define _VALUABLE_

template <typename Vtype = double>
class Valuable {
protected:
    bool valued;

public:
    Valuable() : valued(false), value(0) {};
    ~Valuable() {};
    Vtype value;
    virtual void set_value (Vtype __v) {
        value = __v;
    };
};

#endif