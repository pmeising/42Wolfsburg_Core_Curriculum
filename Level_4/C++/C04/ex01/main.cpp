/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/09 10:46:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
	// const	Animal	*Carl = new Animal();
	Cat				*Kitty = new Cat();
	Cat				Birdie;
	// This shows, that the Brain constructor is not called when an Animal instance (i.e. Carl) is instanciated.

	// Carl->makeSound();
	Kitty->makeSound();
	Birdie.makeSound();
	
	Kitty->haveThought("dot on wall, must resist jump.");
	Kitty->voiceThought(0);
	Birdie = *Kitty;
	// delete Kitty;
	
	Birdie.voiceThought(0);

	Kitty->haveThought("I attack dot");
	Kitty->voiceThought(1);

	Birdie.voiceThought(1);

	std::cout << "\n" << Birdie.getType() << " is now attempting to learn a lot. In pos 0 she's thinking of: ";
	Birdie.voiceThought(0);
	std::cout << "\n";
	for (int i = 0; i < 99; i++)
		Birdie.haveThought("I love the sunlight.");

	
	Birdie.voiceThought(0);
	Birdie.voiceThought(10);
	Birdie.voiceThought(37);
	Birdie.voiceThought(99);
	
	
	delete Kitty;

	std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~ Extra tests ~~~~~~~~~~~~~~~~~~~~~~~~~~\n Should be about deep copies and shallow copies.\n\n";
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;
	
	Dog	Scooby;
	
	std::cout << "\n ~~~~ Filling in the ideas array of Scoobys Brain. ~~~~~\n";

	Scooby.haveThought("Ughhhh a cat...");

	std::cout << B_GREEN << "Scoobys thought index 0\n" << DEFAULT;
	Scooby.voiceThought(0);
	Scooby.voiceThought(1);

	std::cout << B_GREEN << "Making a deepcopy of Scooby called Pluto! ~~~~~ \n" << DEFAULT;
		
	Dog	Pluto = Scooby;
	// This one now is a deep copy. It uses both the copy constructor 
	// of the Dog Class as well as the assignment operator overload of
	// the Brain class.

	std::cout << B_GREEN << "Let's see if Pluto thinks the same. No thought on position 1: \n" << DEFAULT;

	Pluto.voiceThought(0);
	Pluto.voiceThought(1);
	
	std::cout << B_GREEN << "Inserting new thought into Scoobys Brain~~~~~\n" << DEFAULT;	
	
	Scooby.haveThought("I like Pluto");

	std::cout << B_GREEN << "What's he thinking?\n" << DEFAULT;
	
	Scooby.voiceThought(1);

	std::cout << B_GREEN << "And Plutos thoughts?\n" << DEFAULT;

	Pluto.voiceThought(1);
	}
	std::cout << "\n\n######################################## Array of animal objects #######################################\n\n";
	{
		const	Animal		*Animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				Animals[i] = new Cat();
			else
				Animals[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << Animals[i]->getType() << "\n";
			Animals[i]->makeSound();
			delete Animals[i];
		}
	}
	return 0;
}
