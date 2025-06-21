#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;
    for (auto& pair : spells)
        delete pair.second;
    spells.clear();
}

const std::string& Warlock::getName() const { return name; }
const std::string& Warlock::getTitle() const { return title; }
void Warlock::setTitle(const std::string& newTitle) { title = newTitle; }

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string& name) {
    auto it = spells.find(name);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string& name, const ATarget& target) {
    ASpell* spell = spells[name];
    if (spell)
        spell->launch(target);
}
