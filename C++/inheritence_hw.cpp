#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string species;
    int age;
    float weight;

public:
    Animal(string species, int age, float weight) {
        this->species = species;
        this->age = age;
        this->weight = weight;
    }

    void displayInfo() {
        cout << "Species: " << species << ", Age: " << age << " years, Weight: " << weight << " kg" << endl;
    }
};


class Mammal : public Animal {
protected:
    string furColor;

public:
    Mammal(string species, int age, float weight, string furColor) 
        : Animal(species, age, weight) {
        this->furColor = furColor;
    }

    void makeSound() {
        cout << species << " makes a mammal sound." << endl;
    }
};


class Bird : public Animal {
protected:
    float wingSpan;

public:
    Bird(string species, int age, float weight, float wingSpan)
        : Animal(species, age, weight) {
        this->wingSpan = wingSpan;
    }

    void fly() {
        cout << species << " is flying with a wingspan of " << wingSpan << " meters." << endl;
    }
};


class Reptile : public Animal {
protected:
    bool isVenomous;

public:
    Reptile(string species, int age, float weight, bool isVenomous)
        : Animal(species, age, weight) {
        this->isVenomous = isVenomous;
    }

    void crawl() {
        cout << species << " is crawling." << endl;
    }
};


class Lion : public Mammal {
private:
    int prideSize;

public:
    Lion(string species, int age, float weight, string furColor, int prideSize)
        : Mammal(species, age, weight, furColor) {
        this->prideSize = prideSize;
    }

    void hunt() {
        cout << species << " hunts with its pride of " << prideSize << " members." << endl;
    }
};


class Elephant : public Mammal {
private:
    float trunkLength;

public:
    Elephant(string species, int age, float weight, string furColor, float trunkLength)
        : Mammal(species, age, weight, furColor) {
        this->trunkLength = trunkLength;
    }

    void useTrunk() {
        cout << species << " uses its trunk to drink water." << endl;
    }
};


class FlyingReptile : public Bird, public Reptile {
private:
    float wingSpan;
    bool isVenomous;

public:
    FlyingReptile(string species, int age, float weight, float wingSpan, bool isVenomous)
        : Animal(species, age, weight), Bird(species, age, weight, wingSpan), Reptile(species, age, weight, isVenomous) {
        this->wingSpan = wingSpan;
        this->isVenomous = isVenomous;
    }

    void glide() {
        cout << species << " is gliding with a wingspan of " << wingSpan << " meters." << endl;
    }
};


int main() {
    Lion lion("Lion", 5, 190, "Golden", 6);
    lion.displayInfo();
    lion.makeSound();
    lion.hunt();

    cout << endl;

    Bird parrot("Parrot", 2, 1.5, 0.8);
    parrot.displayInfo();
    parrot.fly();

    cout << endl;

    Reptile crocodile("Crocodile", 12, 400, false);
    crocodile.displayInfo();
    crocodile.crawl();

    cout << endl;

    Elephant elephant("Elephant", 10, 5000, "Grey", 2);
    elephant.displayInfo();
    elephant.makeSound();
    elephant.useTrunk();

    cout << endl;

    FlyingReptile pterodactyl("Pterodactyl", 3, 50, 3, true);
    pterodactyl.displayInfo();
    pterodactyl.fly();
    pterodactyl.crawl();
    pterodactyl.glide();

    return 0;
}