#include <iostream>

using namespace std;

int MyHealth = 100;
int EnemyHealth = 50;
int Attack = 1;
int BowSkill = 10;
int SwordSkill = 20;
int EnemyBeserkerDamage = 10;
int EnemyValkyrieDamage = 20;
int PlayerPosX = 5;
int PlayerPosY = 9;
const static int MAX_MAP_X_INDEX = 9;
const static int MAX_MAP_X_INDEX = 9;

int Map[10][10] =
{
    {9,9,9,9,9,9,9,9,9,9},
    {8,8,8,8,8,8,8,8,8,8},
    {0,7,0,0,0,6,0,0,7,0},
    {0,6,0,4,0,5,0,6,0,6},
    {0,0,4,0,5,0,6,0,4,0},
    {0,5,0,4,0,0,4,0,4,0},
    {3,0,0,0,0,5,4,0,0,0},
    {0,0,3,0,3,0,0,0,3,0},
    {0,3,4,0,2,2,2,0,0,0},
    {0,0,0,0,0,1,2,0,0,0}
};

void printMap()
{
    for (int row = 0; row < 10; row++)
    {
        for(int column = 0; column < 10; column++)
        {
            if(PlayerPosX==column && PlayerPosY==row)
            {
                cout<< 'P' << " ";
            }
            else
            {
                cout << Map[row][column] << " ";
            }
        }
        cout << endl;
    }
}

class NPC
{
public:
    NPC(int health, int damage, const std::string &name) : Health(health), Damage(damage), Name(name) {}
    bool isDead()
    {
        return Health<=0;
    }
    int getDamage()
    {
        return Damage;
    }
    const std::string &getName()
    {
        return Name;
    }
    bool takeDamage(int dam)
    {
        Health-=dam;
        return isDead();
    }
    int getHealth() {
        return Health;
    }
private:
    int Health;
    int Damage;
    std::string Name;
};

void movePlayer() {
    char direction;
    cout << "which way?" << endl;
    cin >> direction;
    switch(direction) {
    case 'w':
        PlayerPosX--;
        break;
    case 'e':
        PlayerPosX++;
        break;
    case 'n':
        PlayerPosY--;
        break;
    case 's':
        PlayerPosY++;
        break;
    }
    if(PlayerPosX<0) {
        PlayerPosX=0;
    }
    if(PlayerPosX>MAX_MAP_X_INDEX) {
        PlayerPosX = MAX_MAP_X_INDEX;
    }
     if(PlayerPosY<0) {
        PlayerPosY=0;
    }
    if(PlayerPosX>MAX_MAP_Y_INDEX) {
        PlayerPosX = MAX_MAP_Y_INDEX;
    }
}

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
    NPC Beserker(100, 10, "Jeff");
    cout << "You have encountered Ship Wreckage. When you explore you find a single healthy Berserker ready for its next foe. " << Beserker.getName() << endl;

    cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
    cin >> Attack;

    if (Attack == 1)
    {
        Beserker.takeDamage(BowSkill);
        //EnemyHealth -= BowSkill;
        cout << "The Enemy can not reach you since you did not go to engage her." << endl;
    }
    if (Attack == 2)
    {
        Beserker.takeDamage(SwordSkill);
        //EnemyHealth -= SwordSkill;
        cout << "The Enemy strikes back with 10 damage" << endl;
        MyHealth -= Beserker.getDamage();
    }

    while(!Beserker.isDead())
    {
        cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
        cin >> Attack;
        if (Attack == 1)
        {
            Beserker.takeDamage(BowSkill);
            //EnemyHealth = EnemyHealth - 10;
        }
        if (Attack == 2)
        {
            Beserker.takeDamage(SwordSkill);
        }
        cout << "The Enemy strikes back with 10 damage" << endl;
        MyHealth -= Beserker.getDamage();
        cout << "My Health: " << MyHealth << endl;
        cout << "Enemy Health: " << Beserker.getHealth() << endl;
    }

    NPC Valkyrie(200, 20, "Arianna");
    cout << "Congrats! You have defeated the tutorial Berserker." << endl;
    cout << "Adventurer, now that you have completed your tutorial you will now be able to play." << endl;

    printMap();
    movePlayer();
    printMap();
    int Player = Map[9][5];
    if (Map[9][6] == Player)
    {
        cout << "You have encountered a Small Canoe. When you explore you find a single healthy Valkyrie ready for its next foe. " << Valkyrie.getName() << endl;

        cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
    cin >> Attack;

 if (Attack == 1)
    {
        Valkyrie.takeDamage(BowSkill);
        //EnemyHealth -= BowSkill;
        cout << "The Enemy can not reach you since you did not go to engage her." << endl;
    }
    if (Attack == 2)
    {
        Valkyrie.takeDamage(SwordSkill);
        //EnemyHealth -= SwordSkill;
        cout << "The Enemy strikes back with 20 damage" << endl;
        MyHealth -= Valkyrie.getDamage();
    }

        while(!Valkyrie.isDead())
        {
            cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
            cin >> Attack;
            if (Attack == 1)
            {
                Valkyrie.takeDamage(BowSkill);
                //EnemyHealth = EnemyHealth - 10;
            }
            if (Attack == 2)
            {
                Valkyrie.takeDamage(SwordSkill);
            }
            cout << "The Enemy strikes back with 20 damage" << endl;
            MyHealth -= Valkyrie.getDamage();
            cout << "My Health: " << MyHealth << endl;
            cout << "Enemy Health: " << Valkyrie.getHealth() << endl;
        }
    }
    return 0;
}


