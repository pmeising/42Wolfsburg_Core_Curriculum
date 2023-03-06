/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 21:34:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	// // can't instantiate aAnimal object: 
	// // const	aAnimal	Carl;
	// const	Cat		*Kitty = new Cat();
	// // This shows, that the Brain constructor is not called when an aAnimal instance (i.e. Carl) is instanciated.

	// // Carl->makeSound();
	// // Kitty->makeSound();
	// Kitty->haveThought("Far as the sky I'll fly");
	// // Birdie = *Kitty;
	// const	Cat		Birdie(*Kitty);
	// Birdie.voiceThought(0);
	// Kitty->voiceThought(0);
	// Birdie.voiceThought(1);
	// Kitty->haveThought("I am here.");
	// Kitty->voiceThought(1);
	// Birdie.voiceThought(1);
	
	// // Birdie->makeSound();
	
	// // delete Birdie;
	// // delete Kitty;
	// // // At this point this creates a shallow copy.
	
	// // for (int i = 0; i < 100; i++)
	// // {
	// // 	if (i % 3)
	// // 		Birdie->haveThought("This bird looks tasty...");
	// // 	else if (i % 4)
	// // 		Birdie->haveThought("Dot on the wall!!!");
	// // 	else
	// // 		Birdie->haveThought("Glass go break if I go push...");
	// // }
	// // Birdie->voiceThought(0);
	// // Birdie->voiceThought(10);
	// // Birdie->voiceThought(37);
	// // Birdie->voiceThought(99);

	
	// // // delete Carl;
	// // delete Kitty;
	// // delete Birdie;

	// std::cout << "\n\n~~~~~~~~~~~~~~~~~~~~~ Extra tests ~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	
	// Dog	Scooby;
	
	// std::cout << "\n ~~~~ Filling in the ideas array of Scoobys Brain. ~~~~~\n";

	// Scooby.haveThought("Ughhhh a cat...");

	// std::cout << B_GREEN << "Scoobys thought index 0\n" << DEFAULT;
	// Scooby.voiceThought(0);
	// Scooby.voiceThought(1);

	// std::cout << B_GREEN << "Making a deepcopy of Scooby called Pluto! ~~~~~ \n" << DEFAULT;
		
	// Dog	Pluto = Scooby;
	// // This one now is a deep copy. It uses both the copy constructor 
	// // of the Dog Class as well as the assignment operator overload of
	// // the Brain class.

	// std::cout << B_GREEN << "Let's see if Pluto thinks the same. No thought on position 1: \n" << DEFAULT;

	// Pluto.voiceThought(0);
	// Pluto.voiceThought(1);
	
	// std::cout << B_GREEN << "Inserting new thought into Scoobys Brain~~~~~\n" << DEFAULT;	
	
	// Scooby.haveThought("I like Pluto");

	// std::cout << B_GREEN << "What's he thinking?\n" << DEFAULT;
	
	// Scooby.voiceThought(1);

	// std::cout << B_GREEN << "And Plutos thoughts?\n" << DEFAULT;

	// Pluto.voiceThought(1);
	
	std::cout << "\n############################ Further tests ##########################\n\n";
	
	/*---Proof that Animal class can't be instantiated --- */

	// const A_Animal *test = new A_Animal;
	
	// std::cout << "Hi, I am a " << test->getType() << std::endl;
	// delete test;

	/*---almost everything from ex01's main--------*/

	// // /*------TESTING--BRAIN--CLASS-----*/
	Cat Felix;
	// //Felix.fillBrain();
	// Felix.haveThought("Cats rule...");
	// std::cout << "Felix is thinking of ..." << std::endl;
	// Felix.voiceThought(0);
	// Dog	Dave;
	// Dave.haveThought("Dogs are the best, I love dogs...");
	// std::cout << "Dave is thinking of ..." << std::endl;
	// Dave.voiceThought(0);
	
	// // /*------TESTING--COPY--CONSTRUCTOR-----*/
	// const Cat *copy_cat = new Cat(Felix);

	// copy_cat->haveThought("catnip is fun...");
	// copy_cat->haveThought("catnip");
	// std::cout << "The copy cat has a new idea! It's :";
	// copy_cat->voiceThought(0);
	// std::cout << "But usually, " << copy_cat->getType() << " thinks only of ";
	// copy_cat->voiceThought(1);
	 

	// delete copy_cat;

	// const Dog *dogsbody = new Dog(Dave);
	// dogsbody->setIdea(2, "playing fetch");
	// std::cout << dogsbody->getType() << " is tAssignmenthinking about " << dogsbody->getIdea(2) << std::endl;
	// std::cout << dogsbody->getType() << " is thinking about " << dogsbody->getIdea(0) << std::endl;

	// delete dogsbody;

	/*------TESTING--ASSIGNMENT--OPERATOR-----*/
	{
	Cat assign;
	assign = Felix;
	// assign.haveThought("hi there!");
	std::cout << assign.getType() << " is thinking of ";
	assign.voiceThought(0);
	std::cout << " because they have no brain! " << std::endl;
	}
	// const WrongAnimal* smeta = new WrongAnimal();
	// const WrongAnimal* sj = new WrongCat();
	// std::cout << sj->getType() << " " << std::endl;
	// sj->makeSound();
	// smeta->makeSound();

	// delete smeta;
	// delete sj;
	/*------------array of Wrong Cats ---------------*/

	// WrongAnimal*	arr[10];

	// unsigned int i = 0;
	// while( i < 10 )
	// {
	// 	arr[i] = new WrongCat();
	// 	i++;
	// }
	// std::cout << "arr[3] " << arr[3]->getType();
	// arr[3]->makeSound();
	// unsigned int j = 0;
	// while( j < 10 )
	// {
	// 	std::cout << j << std::endl;
	// 	delete arr[j];
	// 	j++;
	// }

	return 0;
}
