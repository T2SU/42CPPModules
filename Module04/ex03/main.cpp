/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:34:55 by smun              #+#    #+#             */
/*   Updated: 2021/11/28 12:57:27 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << " >> ( MateriaSource를 새롭게 생성하여 IMateriaSource 인터페이스 형태의 포인터에 대입. ) " << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	std::cout << " >> ( MateriaSource에 AMateria를 상속한 Ice를 생성하여 learnMateria 함수 실행. ) " << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;

	std::cout << " >> ( MateriaSource에 AMateria를 상속한 Cure를 생성하여 learnMateria 함수 실행. ) " << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << " >> ( 'me' 라는 이름을 가진 Character를 새롭게 생성하여 ICharacter 인터페이스 형태의 포인터에 대입. ) " << std::endl;
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;

	std::cout << " >> ( 'ice' 타입의 Materia를 createMateria 함수로 복제하여 me에 equip. ) " << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << " >> ( 'cure' 타입의 Materia를 createMateria 함수로 복제하여 me에 equip. ) " << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << " >> ( 'bob' 라는 이름을 가진 Character를 새롭게 생성하여 ICharacter 인터페이스 형태의 포인터에 대입. ) " << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 0번 인벤토리의 Materia를 'bob'에게 사용. ) " << std::endl;
	me->use(0, *bob);
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 1번 인벤토리의 Materia를 'bob'에게 사용. ) " << std::endl;
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 2번 인벤토리의 Materia를 'bob'에게 사용하려고 하나, 아무 것도 장착되어 있지 않기 때문에, 아무 일도 일어나지 않음. ) " << std::endl;
	me->use(2, *bob);
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 3번 인벤토리의 Materia를 'bob'에게 사용하려고 하나, 아무 것도 장착되어 있지 않기 때문에, 아무 일도 일어나지 않음. ) " << std::endl;
	me->use(3, *bob);
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 1번 인벤토리의 Materia를 장착 해제. ) " << std::endl;
	me->unequip(1);
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 1번 인벤토리에 있던 Materia를 'bob'에게 사용함. 바로 위의 unequip(장착 해제)를 통해 delete 되지 않았음을 증명. ) " << std::endl;
	tmp->use(*bob);
	std::cout << std::endl;

	std::cout << " >> ( 장착 해제된 'cure' 타입의 Materia를 삭제. ) " << std::endl;
	delete tmp;
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 1번 인벤토리의 Materia를 'bob'에게 사용하려고 하나, 아무 것도 장착되어 있지 않기 때문에, 아무 일도 일어나지 않음. ) " << std::endl;
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << " >> ( 'bob'의 Character 객체를 삭제. ) " << std::endl;
	delete bob;
	std::cout << std::endl;

	std::cout << " >> ( 'me'의 Character 객체를 삭제. 1번 인벤토리의 Materia는 이미 장착 해제했으므로, 0번 인벤토리의 'ice' Materia만 함께 삭제됨. ) " << std::endl;
	delete me;
	std::cout << std::endl;

	std::cout << " >> ( MateriaSource 객체를 삭제. 가지고 있는 'ice', 'cure' 타입 Materia도 함께 삭제. ) " << std::endl;
	delete src;
	std::cout << std::endl;

	return 0;
}
