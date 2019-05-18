#ifndef _VALUABLE_
#define _VALUABLE_

template <typename Vtype = double>
class Valuable {
protected:
    bool valued;

public:
    Vtype value;

    // Valuable is created with value zero and not-valued value (valued=false)
    Valuable() : valued(false), value(Vtype()) {};
    ~Valuable() {};

    bool is_valued () { return valued;};
};

#endif