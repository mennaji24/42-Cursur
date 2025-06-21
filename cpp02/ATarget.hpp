#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>

class ASpell;

class ATarget {
protected:
    std::string type;

public:
    ATarget();
    ATarget(const std::string& type);
    virtual ~ATarget();

    const std::string& getType() const;
    virtual ATarget* clone() const = 0;

    void getHitBySpell(const ASpell& spell) const;
};

#endif