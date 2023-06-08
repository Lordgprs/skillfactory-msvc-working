#include "VendingMachine.h"
#include "Snack.h"
#include "SnackSlot.h"
#include <iostream>
#include <string>

int main() {
  const unsigned short slotCount = 10;
  Snack *bounty = new Snack("Bounty");
  Snack *snickers = new Snack("Snickers");
  Snack *mars = new Snack("Mars", 400, 100);
  mars->setProteins(20);
  mars->setFats(10);
  mars->setCarbohydrates(70);
  SnackSlot *slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot->addSnack(bounty); //Добавляем батончик в слот
  slot->addSnack(snickers);
  SnackSlot *slot2 = new SnackSlot(4);
  slot2->addSnack(mars);
  VendingMachine *machine = new VendingMachine(slotCount /*Количество слотов для снеков*/);
  machine->addSlot(slot); // Помещаем слот обратно в аппарат
  machine->addSlot(slot2);
  machine->addSlot(new SnackSlot);

  std::cout << "Empty slot count: " << machine->getEmptySlotsCount() << std::endl; // Выводит количество пустых слотов для снеков, установленных в аппарат
  std::cout << "Free slot cells count: " << machine->getUninstalledSlotsCount() << std::endl; // Выводит количество пустых ячеек в аппарате, готовых к установке в них слота со снеками
  //std::cout << "\n" << (*machine)[1] << std::endl;
  std::cout << "\n" << *machine << std::endl;

  // А что у нас лежит в самом первом слоту в самой первой ячейке?
  std::cout << "Content of the first cell of the first slot:\n" << (*machine)[0][0] << std::endl;

  // Удалим наш пустой слот - он нам больше не нужен
  delete &(*machine)[2];
  machine->removeSlot(2);

  //Второй слот тоже удалим, для экспериментов нам сейчас хватит и одного
  delete slot2;
  machine->removeSlot(1);

  // При удалении все слоты сдвигаются так, чтобы в аппарате не было пустых мест без слота. Если нам необходимо временно вытащить слот для того чтобы 
  // например добавить в него ячейку (он у нас разборный как конструктор), используем метод uninstall():
  (*machine)[0].uninstall();
  // Какова вместимость слота сейчас?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  (*machine)[0].setCapacity(12);
  // А сейчас?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  ++(*machine)[0];
  // А сейчас?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  (*machine)[0]--;
  // А сейчас?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  // А теперь вернём слот обратно в аппарат
  slot->install();
  // Давайте заполним некоторую информацию о снеках:
  snickers->setProteins(40);
  snickers->setFats(20);
  snickers->setCarbohydrates(140);
  snickers->setCalories(500);
  snickers->setWeight(120);
  bounty->setProteins(20);
  bounty->setFats(10);
  bounty->setCarbohydrates(70);
  bounty->setCalories(400);
  bounty->setWeight(100);
  // Давайте установим цену на любой снек в этом слоте - 10 рублей
  slot->setPrice(10.00);
  // А теперь давайте продадим клиенту снек:
  std::cout << *machine << std::endl; // Выведем текущую информацию об аппарате
  machine->sellSnack(0);
  std::cout << "Machine balance is now " << machine->getBalance() << std::endl;

  // Пора освободить память, выделенную на куче
  delete machine;
  delete slot;
  delete mars;
  delete snickers;
  delete bounty;

	return 0;
}