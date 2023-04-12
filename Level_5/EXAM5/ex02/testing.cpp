#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"

	

// c++ -Wall -Werror -Wextra Warlock.cpp main.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp BrickWall.cpp Fireball.cpp Polymorph.cpp SpellBook.cpp TargetGenerator.cpp

int main(void)
{
	// {
	// 	Warlock richard("Richard", "foo");
	// 	richard.setTitle("Hello, I'm Richard the Warlock!");
	// 	BrickWall model1;
	// 	BrickWall test1(model1);
		
	// 	Polymorph* polymorph = new Polymorph();
	// 	TargetGenerator tarGen;

	// 	tarGen.learnTargetType(&test1);
	// 	richard.learnSpell(polymorph);

	// 	Fireball* fireball = new Fireball();

	// 	richard.learnSpell(fireball);

	// 	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	// 	richard.introduce();
	// 	richard.launchSpell("Polymorph", *wall);
	// 	richard.launchSpell("Fireball", *wall);
	// 	delete wall;
	// 	delete fireball;
	// 	delete polymorph;
	// }
	{
		std::cout << "--- Constructors:\n";
		Warlock richard("Aang", "The Avatar");

		std::cout << "--- Spells:\n";
		Polymorph *water = new Polymorph();
		Fireball *fire = new Fireball();
		Fwoosh *air = new Fwoosh();

		richard.learnSpell(water);
		richard.forgetSpell("Polymorph");
		richard.learnSpell(water);
		richard.learnSpell(fire);
		richard.forgetSpell("Fwoosh");
		richard.learnSpell(air);
		richard.forgetSpell("Fwoosh");
		richard.forgetSpell("Fwoosh");
		richard.learnSpell(air);
		richard.learnSpell(water);
		richard.learnSpell(fire);

		std::cout << "--- Targets:\n";
		Dummy *hay = new Dummy();
		BrickWall *earth = new BrickWall();

		TargetGenerator tarGen;
		tarGen.learnTargetType(hay);
		tarGen.learnTargetType(earth);

		std::cout << "--- Spells (all):\n";

		ATarget	*target = tarGen.createTarget("Target Practice Dummy");
		richard.launchSpell("Fwoosh", *target);
		richard.launchSpell("Fireball", *target);
		richard.launchSpell("Polymorph", *target);

		std::cout << "--- Forgotten \"Fwoosh\":\n";
		richard.forgetSpell("Fwoosh");
		richard.launchSpell("Fwoosh", *target);
		richard.launchSpell("Fireball", *target);
		richard.launchSpell("Polymorph", *target);

		std::cout << "--- Spells (all):\n";

		richard.learnSpell(air);
		richard.launchSpell("Fwoosh", *target);
		richard.launchSpell("Fireball", *target);
		richard.launchSpell("Polymorph", *target);

		std::cout << "--- Non-existant spell:\n";

		richard.launchSpell("ACID", *target);
		richard.forgetSpell("ACID");
		richard.launchSpell("ACID", *target);
		delete water;
		delete fire;
		delete air;
		delete hay;
		delete earth;
		delete target;
		// std::cout << "--- Destructors:\n";
	}
	return (0);
}
