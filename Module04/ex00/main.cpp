/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:15:13 by smun              #+#    #+#             */
/*   Updated: 2021/11/28 12:48:02 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << " >> ( Dog 타입이 나오기를 기대함. ) " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << " >> ( Cat 타입이 나오기를 기대함. ) " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << " >> ( Animal의 포인터지만, Cat의 울음 소리가 나오기를 기대함. ) " << std::endl;
	i->makeSound();
	std::cout << std::endl;

	std::cout << " >> ( Animal의 포인터지만, Dog의 울음 소리가 나오기를 기대함. ) " << std::endl;
	j->makeSound();
	std::cout << std::endl;

	std::cout << " >> ( 아무 소리도 나지 않을 것임. ) " << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	std::cout << std::endl;

	delete j;
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;

	const WrongAnimal* wmeta = new WrongAnimal();
	std::cout << std::endl;

	const WrongAnimal* wi = new WrongCat();
	std::cout << std::endl;

	std::cout << " >> ( getType 함수는 자식 클래스의 오버라이드 되는 함수가 아니며, 따라서 Cat으로 올바르게 출력되기를 기대함. ) " << std::endl;
	std::cout << wi->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << " >> ( makeSound 함수의 virtual 키워드가 제거되었으므로, ) " << std::endl;
	std::cout << " >> ( WrongAnimal의 포인터로는 WrongCat의 makeSound를 호출할 수 없음. ) " << std::endl;
	std::cout << " >> ( 따라서, WrongAnimal의 makeSound가 호출되므로, 아무 출력도 없을 것임. ) " << std::endl;
	wi->makeSound();
	std::cout << std::endl;

	std::cout << " >> ( 마찬가지로 WrongAnimal의 makeSound가 호출되므로, 아무 출력도 없을 것임. ) " << std::endl;
	wmeta->makeSound();
	std::cout << std::endl;

	delete wi;
	std::cout << std::endl;

	delete wmeta;
	std::cout << std::endl;

	return 0;
}
