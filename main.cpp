#include <iostream>

#include <string>

using namespace std;

class Tamagotchi {

private:

    string name;

    int hunger;

    int happiness;

    int energy;

    void limitStats() {

        if (hunger < 0) hunger = 0;

        if (hunger > 100) hunger = 100;

        if (happiness < 0) happiness = 0;

        if (happiness > 100) happiness = 100;

        if (energy < 0) energy = 0;

        if (energy > 100) energy = 100;

    }

public:

    Tamagotchi(string petName) {

        name = petName;

        hunger = 50;

        happiness = 50;

        energy = 50;

    }

    void feed() {

        hunger -= 20;

        happiness += 5;

        energy -= 5;

        limitStats();

        cout << name << « was fed!\n»;

    }

    void play() {

        if (energy < 15) {

            cout << «Not enough energy to play!\n»;

            return;

        }

        happiness += 15;

        energy -= 15;

        hunger += 10;

        limitStats();

        cout << name << « played!\n»;

    }

    void sleep() {

        energy += 30;

        hunger += 10;

        happiness -= 5;

        limitStats();

        cout << name << « is sleeping!\n»;

    }

    void nextDay() {

        hunger += 15;

        happiness -= 10;

        energy -= 10;

        limitStats();

        cout << «A new day has started!\n»;

    }

    string getMood() const {

        if (happiness >= 70) {

            return «Happy»;

        }

        else if (happiness >= 40) {

            return «Normal»;

        }

        else if (happiness >= 20) {

            return «Sad»;

        }

        else {

            return «Critical»;

        }

    }

    void showStatus() const {

        cout << «\nName: « << name << endl;

        cout << «Hunger: « << hunger << endl;

        cout << «Happiness: « << happiness << endl;

        cout << «Energy: « << energy << endl;

        cout << «Mood: « << getMood() << endl;

    }

};

int main() {

    Tamagotchi pet(«Bobik»);

    pet.showStatus();

    pet.feed();

    pet.play();

    pet.sleep();

    pet.nextDay();

    pet.showStatus();

    return 0;

}