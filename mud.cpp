#include  "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inventory.h"
using namespace std;

class Player {
public:
	Player();
private:
	int mHealth;
	Inventory mInventory;
};

int MyHealth = 100;
int EnemyHealth = 50;
int Attack = 1;
int BowSkill = 10;
int SwordSkill = 20;
int MagicSkill = 30;

//int EnemyBeserkerDamage = 10;
//int EnemyValkyrieDamage = 20;
int PlayerPosX = 5;
int PlayerPosY = 9;
const static int MAX_MAP_X_INDEX = 9;
const static int MAX_MAP_Y_INDEX = 9;

int Map[10][10] =
{
    {2,9,0,0,0,0,0,0,0,2},
    {0,9,0,9,9,9,9,9,0,0},
    {0,0,0,9,0,2,0,9,0,0},
    {0,0,0,0,0,0,2,9,0,0},
    {0,0,0,9,0,2,0,9,0,0},
    {0,0,0,9,9,9,9,9,0,0},
    {2,0,0,0,0,2,0,0,0,2},
    {9,9,0,0,0,0,0,0,9,9},
    {0,9,0,0,0,2,0,2,9,0},
    {2,0,0,0,3,1,3,0,0,0}
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
    int getHealth()
    {
        return Health;
    }
private:
    int Health;
    int Damage;
    std::string Name;
};

void movePlayer()
{
    char direction;
    cout << "which way?" << endl;
    cin >> direction;
    switch(direction)
    {
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
    if(PlayerPosX<0)
    {
        PlayerPosX=0;
    }
    if(PlayerPosX>MAX_MAP_X_INDEX)
    {
        PlayerPosX = MAX_MAP_X_INDEX;
    }
    if(PlayerPosY<0)
    {
        PlayerPosY=0;
    }
    if(PlayerPosX>MAX_MAP_Y_INDEX)
    {
        PlayerPosX = MAX_MAP_Y_INDEX;
    }
}

MagicAbilityPrototype Prototype1("FireBall", 20, 0);

int main(int argc, char **argv)
{
	Inventory MyInventory;
	MagicAbilityFolder *maf = new MagicAbilityFolder("MyMagicFolder");
	MagicAbilityInstance *mai = new MagicAbilityInstance(&Prototype1);
	maf->addMagicAbility(std::shared_ptr<MagicAbilityInstance>(mai));
	MyInventory.addFolder(maf);
	//std::string info;
	//Prototype1.toString(info);
	//std::cout << info.c_str() << std::endl;
	std::string instanceInfo;
	mai->toString(instanceInfo);
	std::cout << instanceInfo.c_str() << std::endl;


	cout << "Hello Adventurer," << endl;
	cout << "Soon you will embark on your adventure of revenge upon the Vikings." << endl;
	cout << "They destroyed your family, home, and friends." << endl;
	cout << "They have done this on behalf of their king Ivar the Boneless." << endl;
	cout << "You were the only survivor in your village when it was set aflame by the evil Vikings." << endl;
	cout << "You were hidden in the forest, left to whale and cry when your mother rushed back to the village only to be taken prisoner." << endl;
	cout << "You have never seen them again and will never, but you still have the few remaining hazy memories that keep you going." << endl;
	cout << "As a boy in the woods with no home, you had to fend for yourself." << endl;
	cout << "You were able to practice Sword and Shield, Bow and Arrow, even magic with the elves, but which weapon you are better at is up to you." << endl;
	cout << "You have a base of 20 Sword Skill, 30 magic skill and 10 Bow skill choose which you prefer wisely as they will have special attributes(you have 20 points to spend a counter for this has not yet been added)" << endl;
	cout << "Bow Skill is: " << endl;
	cin >> BowSkill;
	cout << "Sword Skill is: " << endl;
	cin >> SwordSkill;
	cout << "Magic Skill is: " << endl;
	cin >> MagicSkill;
	NPC Beserker(100, 10, "Jeff");
	cout << "You have encountered Ship Wreckage. When you explore you find a single healthy Berserker ready for its next foe. " << Beserker.getName().c_str() << endl;

	cout << "What do you wish to do: shoot your bow(1), attack with your sword?(2), or throw a bolt of magic(3)" << endl;
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
	if (Attack == 3)
	{
		Beserker.takeDamage(MagicSkill);
		//EnemyHealth -= SwordSkill;
		if (MagicSkill <= 150) {

			unsigned long int	srand(time(NULL));
			unsigned long int RecoilChance = (rand() % 2);
			if (RecoilChance = 0)
			{
				cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
				MyHealth -= 10;
			}
			else
			{
				cout << "Your magic lands with no recoil" << endl;
			}
		}

	}

	while (!Beserker.isDead())
	{
		cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or throw a bolt of magic(3)" << endl;
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
		if (Attack == 3)
		{
			Beserker.takeDamage(MagicSkill);
			//EnemyHealth -= SwordSkill;
			if (MagicSkill <= 150) {

				unsigned long intsrand(time(NULL));
				unsigned long int	RecoilChance = (rand() % 2);
				if (RecoilChance = 0)
				{
					cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
					MyHealth -= 10;
				}
				else
				{
					cout << "Your magic lands with no recoil" << endl;
				}
			}
		}
			cout << "The Enemy strikes back with 10 damage" << endl;
			MyHealth -= Beserker.getDamage();
			cout << "My Health: " << MyHealth << endl;
			cout << "Enemy Health: " << Beserker.getHealth() << endl;

		}

		NPC Valkyrie(200, 20, "Arianna");
		cout << "Congrats! You have defeated the tutorial Berserker." << endl;
		cout << "Adventurer, now that you have completed your tutorial you will now be able to play." << endl;

		while (!MyHealth <= 0)
		{

			printMap();
			//rLocation = Map[][];
			//int (*Location)(Map[][]);
			//Location = &movePlayer;
			//rLocation = (*Location)(9,5)
			movePlayer();
			if (PlayerPosX == 6 && PlayerPosY == 9)
			{
				cout << "You have encountered a Small Canoe. When you explore you find a single healthy Valkyrie ready for its next foe. " << Valkyrie.getName().c_str() << endl;

				cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or throw a bolt of magic(3)" << endl;
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
				if (Attack == 3)
				{
					Valkyrie.takeDamage(BowSkill);
					//EnemyHealth -= SwordSkill;
					if (MagicSkill <= 150) {

						unsigned long int srand(time(NULL));
						unsigned long int	RecoilChance = (rand() % 2);
						if (RecoilChance = 0)
						{
							cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
							MyHealth -= 10;

						}
						else
						{
							cout << "Your magic lands with no recoil" << endl;
						}
					}
				}
				while (!Valkyrie.isDead())
				{
					cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or throw a bolt of magic(3)" << endl;
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
					if (Attack == 3)
					{
						Valkyrie.takeDamage(BowSkill);
						//EnemyHealth -= SwordSkill;
						if (MagicSkill <= 150) {

							unsigned long int srand(time(NULL));
							unsigned long int	RecoilChance = (rand() % 2);
							if (RecoilChance = 1)
							{
								cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
								MyHealth -= 10;
							}
							else
							{
								cout << "Your magic lands with no recoil" << endl;
							}
						}
					}
					cout << "The Enemy strikes back with 20 damage" << endl;
					MyHealth -= Valkyrie.getDamage();
					cout << "My Health: " << MyHealth << endl;
					cout << "Enemy Health: " << Valkyrie.getHealth() << endl;
				}
			}
			NPC WildBeast(300, 5, "Buff");
			if (PlayerPosX == 4 && PlayerPosY == 9)
			{
				MyHealth -= 10;
				cout << "You are starving. In the search of food you feel weak and don't see the obvious signs of a Powerful Creature you know you should avoid. There were giant footprints, tiny bits of skin everywhere and Finally, the biggest sign of all that no Healthy Human could miss was a big giant Blood dripping, Bear Foot. But since you were about to pass out (-10 Health) you did not see these signs and Found a fat Wild Beast..." << endl;
				cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or throw a bolt of magic(3)" << endl;
				cin >> Attack;

				if (Attack == 1)
				{
					WildBeast.takeDamage(BowSkill);
					//EnemyHealth -= BowSkill;
					cout << "The Enemy can not reach you since you did not go to engage it." << endl;
				}
				if (Attack == 2)
				{
					WildBeast.takeDamage(SwordSkill);
					//EnemyHealth -= SwordSkill;
					cout << "The Enemy strikes back with 20 damage" << endl;
					MyHealth -= WildBeast.getDamage();
				}
				if (Attack == 3)
				{
					WildBeast.takeDamage(MagicSkill);
					//EnemyHealth -= SwordSkill;
					if (MagicSkill <= 150) {

						unsigned long int srand(time(NULL));
						unsigned long int	RecoilChance = (rand() % 2);
						if (RecoilChance = 0)
						{
							cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
							MyHealth -= 10;
						}
						else
						{
							cout << "Your magic lands with no recoil" << endl;
						}
					}
				}
				while (!WildBeast.isDead())
				{
					cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or throw a bolt of magic(3)" << endl;
					cin >> Attack;
					if (Attack == 1)
					{
						WildBeast.takeDamage(BowSkill);
						//EnemyHealth = EnemyHealth - 10;
					}
					if (Attack == 2)
					{
						WildBeast.takeDamage(SwordSkill);
					}
					if (Attack == 3)
					{
						WildBeast.takeDamage(MagicSkill);
						//EnemyHealth -= SwordSkill;
						if (MagicSkill <= 150) {

							unsigned long int srand(time(NULL));
							unsigned long int	RecoilChance = (rand() % 2);
							if (RecoilChance = 0)
							{
								cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
								MyHealth -= 10;
							}
							else
							{
								cout << "Your magic lands with no recoil" << endl;
							}
						}
					}
					cout << "The Enemy strikes back with 20 damage" << endl;
					MyHealth -= WildBeast.getDamage();
					cout << "My Health: " << MyHealth << endl;
					cout << "Enemy Health: " << WildBeast.getHealth() << endl;
				}
			}
			if ((PlayerPosX == 5 && PlayerPosY == 8) || (PlayerPosX == 8 && PlayerPosY == 7) || (PlayerPosX == 0 && PlayerPosY == 9) ||
				(PlayerPosX == 0 && PlayerPosY == 6) || (PlayerPosX == 5 && PlayerPosY == 6) || (PlayerPosX == 9 && PlayerPosY == 6) ||
				(PlayerPosX == 0 && PlayerPosY == 0) || (PlayerPosX == 0 && PlayerPosY == 9) || (PlayerPosX == 2 && PlayerPosY == 5) ||
				(PlayerPosX == 3 && PlayerPosY == 6) || (PlayerPosX == 4 && PlayerPosY == 5 || (PlayerPosX == 7 && PlayerPosY == 8)))
			{
				switch ((rand() % 2) + 1)
				{

				case 1:
				{
					NPC BanditArcher(50, 30, "Perfect Shot");
					cout << "You smell fire in the distance. Closer, you notice that Smoke is coming from multiple different Chimney's. Amazing! You thought. You had not seen Civilization in Ages! Happily, you push your horse to a gallop. Also, when you stare down you realizes that you have been riding on the beaten path for a while now. What my Luck you think. Thats until you see a Bandit off in the distance his bow Pointed Right at you.";
					MyHealth -= BanditArcher.getDamage();
					cout << "You Take a bow shot to the leg before you can get into range to shoot him with some accuracy or charge him. Luckly, Since your mother was a medic you know that where you got hit will only make you bleed." << endl;
					cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2), or send out a bolt of magic" << endl;
					cin >> Attack;

					if (Attack == 1)
					{
						BanditArcher.takeDamage(BowSkill);
						//EnemyHealth -= BowSkill;
						cout << "The Enemy can not reach you since you did not go to engage her." << endl;
					}
					if (Attack == 2)
					{
						BanditArcher.takeDamage(SwordSkill);
						//EnemyHealth -= SwordSkill;
						cout << "The Enemy strikes back with 20 damage" << endl;
						MyHealth -= BanditArcher.getDamage();
					}
					if (Attack == 3)
					{
						BanditArcher.takeDamage(MagicSkill);
						//EnemyHealth -= SwordSkill;
						if (MagicSkill <= 150) {

							unsigned long int srand(time(NULL));
							unsigned long int	RecoilChance = (rand() % 2);
							if (RecoilChance = 0)
							{
								cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
								MyHealth -= 10;
							}
							else
							{
								cout << "Your magic lands with no recoil" << endl;
							}
						}
					}
					while (!BanditArcher.isDead())
					{
						cout << "What do you wish to do: shoot your bow(1), or attack with your sword?(2)" << endl;
						cin >> Attack;
						if (Attack == 1)
						{
							BanditArcher.takeDamage(BowSkill);
							//EnemyHealth = EnemyHealth - 10;
						}
						if (Attack == 2)
						{
							BanditArcher.takeDamage(SwordSkill);
						}
						if (Attack == 3)
						{
							BanditArcher.takeDamage(MagicSkill);
							//EnemyHealth -= SwordSkill;
							if (MagicSkill <= 150) {

								unsigned long int srand(time(NULL));
								unsigned long int	RecoilChance = (rand() % 2);
								if (RecoilChance = 0)
								{
									cout << "You are uneducated on the harsh rules of magic. You take 10 damage." << endl;
									MyHealth -= 10;
								}
								else
								{
									cout << "Your magic lands with no recoil" << endl;
								}
							}
						}
						cout << "The Enemy strikes back with 20 damage" << endl;
						MyHealth -= BanditArcher.getDamage();
						cout << "My Health: " << MyHealth << endl;
						cout << "Enemy Health: " << BanditArcher.getHealth() << endl;
					}
					cout << "After this Encounter the village People rush out of the woods to Thank You for killing the threat that has been terrorizing them for weeks. They appologize for not being able to give you a reward since the Bandit stole Everything they had but, they nurse you back to full health." << endl;
					MyHealth = 100;
				}
				case 2:
				{
					cout << "test/n";
				}
				}
			}
		}
		return 0;
	}


