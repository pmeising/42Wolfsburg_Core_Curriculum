
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"

int main()
{
	{
		Warlock richard("Richard", "the Titled");

		Dummy bob;
		Fwoosh* fwoosh = new Fwoosh();

		richard.learnSpell(fwoosh);

		richard.introduce();
		richard.launchSpell("Fwoosh", bob);

		richard.forgetSpell("Fwoosh");
		richard.launchSpell("Fwoosh", bob);
		delete fwoosh;
	}

	{
		Warlock richard("Richard", "foo");
		richard.setTitle("Hello, I'm Richard the Warlock!");
		BrickWall model1;
		BrickWall test1(model1);
		
		Polymorph* polymorph = new Polymorph();
		TargetGenerator tarGen;

		tarGen.learnTargetType(&test1);
		richard.learnSpell(polymorph);

		Fireball* fireball = new Fireball();

		richard.learnSpell(fireball);

		ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

		richard.introduce();
		richard.launchSpell("Polymorph", *wall);
		richard.launchSpell("Fireball", *wall);
		delete wall;
		delete fireball;
		delete polymorph;
	}
}
