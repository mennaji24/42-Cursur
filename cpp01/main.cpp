#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

int main() {
    Warlock richard("Richard", "the Titled");

    Dummy bob;
    Fwoosh* fwoosh = new Fwoosh();

    richard.learnSpell(fwoosh);
    delete fwoosh;

    richard.introduce();
    richard.launchSpell("Fwoosh", bob);

    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", bob);

    return 0;
}