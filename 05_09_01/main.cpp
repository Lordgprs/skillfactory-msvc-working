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
  SnackSlot *slot = new SnackSlot(10/*���������� ����������, ������� ���������� � ����*/);
  slot->addSnack(bounty); //��������� �������� � ����
  slot->addSnack(snickers);
  SnackSlot *slot2 = new SnackSlot(4);
  slot2->addSnack(mars);
  VendingMachine *machine = new VendingMachine(slotCount /*���������� ������ ��� ������*/);
  machine->addSlot(slot); // �������� ���� ������� � �������
  machine->addSlot(slot2);
  machine->addSlot(new SnackSlot);

  std::cout << "Empty slot count: " << machine->getEmptySlotsCount() << std::endl; // ������� ���������� ������ ������ ��� ������, ������������� � �������
  std::cout << "Free slot cells count: " << machine->getUninstalledSlotsCount() << std::endl; // ������� ���������� ������ ����� � ��������, ������� � ��������� � ��� ����� �� �������
  //std::cout << "\n" << (*machine)[1] << std::endl;
  std::cout << "\n" << *machine << std::endl;

  // � ��� � ��� ����� � ����� ������ ����� � ����� ������ ������?
  std::cout << "Content of the first cell of the first slot:\n" << (*machine)[0][0] << std::endl;

  // ������ ��� ������ ���� - �� ��� ������ �� �����
  delete &(*machine)[2];
  machine->removeSlot(2);

  //������ ���� ���� ������, ��� ������������� ��� ������ ������ � ������
  delete slot2;
  machine->removeSlot(1);

  // ��� �������� ��� ����� ���������� ���, ����� � �������� �� ���� ������ ���� ��� �����. ���� ��� ���������� �������� �������� ���� ��� ���� ����� 
  // �������� �������� � ���� ������ (�� � ��� ��������� ��� �����������), ���������� ����� uninstall():
  (*machine)[0].uninstall();
  // ������ ����������� ����� ������?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  (*machine)[0].setCapacity(12);
  // � ������?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  ++(*machine)[0];
  // � ������?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  (*machine)[0]--;
  // � ������?
  std::cout << "Slot #0 capacity is " << (*machine)[0].getCapacity() << std::endl;
  // � ������ ����� ���� ������� � �������
  slot->install();
  // ������� �������� ��������� ���������� � ������:
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
  // ������� ��������� ���� �� ����� ���� � ���� ����� - 10 ������
  slot->setPrice(10.00);
  // � ������ ������� �������� ������� ����:
  std::cout << *machine << std::endl; // ������� ������� ���������� �� ��������
  machine->sellSnack(0);
  std::cout << "Machine balance is now " << machine->getBalance() << std::endl;

  // ���� ���������� ������, ���������� �� ����
  delete machine;
  delete slot;
  delete mars;
  delete snickers;
  delete bounty;

	return 0;
}