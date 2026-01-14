#include "Warlock.hpp"

int main()
{
	Warlock const richard("Richard", "The Titled");

	Dummy bob;

	Fwoosh *fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	
	return (0);
}
