
#include <cstdlib>
#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int numAnimals = 8;
    Animal *animals[numAnimals];
    int dogCount = 0;
    int catCount = 0;

    // Fill the array with half Dog and half Cat objects
    for (int i = 0; i < numAnimals; i++) {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Print sounds of all animals
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Animal " << (i + 1) << " says: ";
        animals[i]->makeSound();
        if (animals[i]->getType() == "Dog")
            dogCount++;
        else if (animals[i]->getType() == "Cat")
            catCount++;
    }
    std::cout << std::endl;

    // Output the counts of dogs and cats
    std::cout << "Total number of dogs: " << dogCount << std::endl;
    std::cout << "Total number of cats: " << catCount << std::endl;

    // Delete the original animals
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }
    std::cout << std::endl;

    // Testing for Dog deep copy
    Dog *deepDog = new Dog();
    std::cout << std::endl;

    Dog *dogCopy = new Dog(*deepDog);  
    dogCopy->getBrain()->setIdea(0, "New Dog Idea 0");  
    dogCopy->getBrain()->setIdea(1, "New Dog Idea 1");
    dogCopy->getBrain()->setIdea(2, "New Dog Idea 2");
    dogCopy->getBrain()->setIdea(3, "New Dog Idea 3");
    dogCopy->getBrain()->setIdea(4, "New Dog Idea ...");

    std::cout << "Original Dog's Ideas:" << std::endl;
    deepDog->getIdea();
    std::cout << std::endl;
    delete deepDog;

    std::cout << "Copied Dog's Ideas:" << std::endl;
    dogCopy->getIdea();
    std::cout << std::endl;
    delete dogCopy;

    // Testing for Cat deep copy
    Cat *deepCat = new Cat();
    std::cout << std::endl;

    Cat *catCopy = new Cat(*deepCat);  
    catCopy->getBrain()->setIdea(0, "New Cat Idea 0");  
    catCopy->getBrain()->setIdea(1, "New Cat Idea 1");
    catCopy->getBrain()->setIdea(2, "New Cat Idea 2");
    catCopy->getBrain()->setIdea(3, "New Cat Idea 3");
    catCopy->getBrain()->setIdea(4, "New Cat Idea ...");
    
    std::cout << "Original Cat's Ideas:" << std::endl;
    deepCat->getIdea();
    std::cout << std::endl;
    delete deepCat;

    std::cout << "Copied Cat's Ideas:" << std::endl;
    catCopy->getIdea();
    std::cout << std::endl;
    delete catCopy;


    return 0;
}




/*int main() {
    Animal *tab[4];

    // Create Dog objects
    tab[0] = new Dog();
    tab[1] = new Dog();

    // Create Cat objects
    tab[2] = new Cat();
    tab[3] = new Cat();

    // Accessing brains and setting ideas
    Brain* dog_brain = tab[0]->get_brain();
    Brain* cat_brain = tab[2]->get_brain();
    cat_brain->setIdea(0, "Kibbles, let's GO !!");
    dog_brain->setIdea(0, "Kibbles, let's GO !!");
    cat_brain->setIdea(1, "I will rule them all");
    dog_brain->setIdea(1, "I will rule them all");
    cat_brain->setIdea(2, "I swear, it's not me for the slippers !");
    dog_brain->setIdea(2, "I swear, it's not me for the slippers !");
    cat_brain->setIdea(3, "OH, Master is putting his shoes on, maybe an outing ??");
    dog_brain->setIdea(3, "OH, Master is putting his shoes on, maybe an outing ??");
    cat_brain->setIdea(4, "...");
    dog_brain->setIdea(4, "...");

    // Printing ideas
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|" << tab[0]->get_brain()->getIdea(0) << "|" << std::endl;
    *tab[1] = *tab[0];
    std::cout << "|" << tab[1]->get_brain()->getIdea(1) << "|" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|" << tab[2]->get_brain()->getIdea(2) << "|" << std::endl;
    *tab[3] = *tab[2];
    std::cout << "|" << tab[3]->get_brain()->getIdea(3) << "|" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // Clean up
    for (int i = 0; i < 4; i++) {
        delete tab[i];
    }

    std::cout << "===================================" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    return 0;
}*/
