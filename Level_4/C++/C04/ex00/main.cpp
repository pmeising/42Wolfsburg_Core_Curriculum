/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:16 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/08 20:54:33 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); // The problem with this instantiation is that we assign a Dog class object to an Animal class object
	// Now when we want to delete that memory (Dog is alloced on the heap), we'll pass an Animal class object (i.e. j) to the delete 
	// function. This triggers the Default destructor of the Animal class to run, not freeing all the memory allocated in the Dog class
	// We solve this issue by using the virtual keyword also for the destructor. This way, the compiler knows not to use the default destructor of class Animal.
	// but instead to use the Dog destructor first.
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();


	delete meta;
	delete j;
	delete i;

	std::cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~ Further tests ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* Wrongj = new WrongDog();
	const WrongAnimal* Wrongi = new WrongCat();
	
	std::cout << Wrongj->getType() << " " << std::endl;
	std::cout << Wrongi->getType() << " " << std::endl;
	Wrongi->makeSound();
	Wrongj->makeSound();
	Wrongmeta->makeSound();
	
	delete Wrongmeta;
	delete Wrongj;
	delete Wrongi;

	const Animal	one;
	const Cat		cat;
	const Cat		two = cat;

	two.makeSound();
	cat.makeSound();
	
	return 0;
}
