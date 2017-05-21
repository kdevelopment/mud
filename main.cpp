#include <iostream>

using namespace std;

int MyHealth = 100;
int EnemyHealth = 50;
int Attack = 1;
int BowSkill = 10;
int SwordSkill = 20;

int main(int argc, char **argv)
{
    cout << "Hello Adventurer," << endl;
    cout << "Soon you will embark on your adventure of revenge upon the Vikings." << endl;
    cout << "They destroyed your family, home, and friends." << endl;
    cout << "They have done this on behalf of their king Ivar the Boneless." << endl;
    cout << "You were the only survivor in your village when it was set aflame by the evil Vikings." << endl;
    cout << "You were hidden in the forest, left to whale and cry when your mother rushed back to the village only to be taken prisoner." << endl;
    cout << "You have never seen them again and will never, but you still have the few remaining hazy memories that keep you going." << endl;
    cout << "As a boy in the woods with no home, you had to fend for yourself." << endl;
    cout << "You were able to practice Sword and Shield, Bow and Arrow, but which weapon you are better at is up to you." << endl;
    cout << "You have a base of 20 Sword Skill and 10 Bow skill choose which you prefer wisely as they will have special attributes(you have 20 points to spend a counter for this has not yet been added)" << endl;
    cout << "Bow Skill is: " << endl;
    cin >> BowSkill;
    cout << "Sword Skill is: " << endl;
    cin >> SwordSkill;
    cout << "You have encountered Ship Wreckage. When you explore you find a single healthy Berserker ready for its next foe." << endl;

    while(EnemyHealth>0)
    {
        cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
        cin >> Attack;
        if (Attack == 1) {
            EnemyHealth -= BowSkill;
            //EnemyHealth = EnemyHealth - 10;
        }
        if (Attack == 2)
        {
            EnemyHealth -= SwordSkill;
        }
        cout << "The Enemy strikes back with 10 damage" << endl;
        MyHealth -= 10;
        cout << "My Health: " << MyHealth << endl;
        cout << "Enemy Health: " << EnemyHealth << endl;


    }
    cout << "Congrats! You have defeated the tutorial Berserker." << endl;
    cout << "Adventurer, now that you have completed your tutorial you will now be able to play." << endl;
    return 0;
}

