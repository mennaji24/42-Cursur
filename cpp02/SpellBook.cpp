#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {
    for (auto& pair : spells)
        delete pair.second;
    spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const& name) {
    auto it = spells.find(name);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const& name) {
    auto it = spells.find(name);
    if (it != spells.end())
        return it->second->clone();
    return nullptr;
}