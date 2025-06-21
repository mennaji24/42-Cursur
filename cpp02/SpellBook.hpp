#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include <string>
#include "ASpell.hpp"

class SpellBook {
private:
    std::map<std::string, ASpell*> spells;

    SpellBook(const SpellBook&);
    SpellBook& operator=(const SpellBook&);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string const& name);
    ASpell* createSpell(std::string const& name);
};

#endif