#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  while (true)
  {
    int size;
    cout << "¬ведите длину строки:" << endl;
    cin >> size;
    cout << "¬ведите величину сдвига:" << endl;
    int shift;
    cin >> shift;
    cout << "¬ведите строку без пробелов:" << endl;
    char* stroka = new char[size];
    for (int i = 0; i < size; ++i)
    {
      cin >> stroka[i];
    }
    cout << endl;
    char* res = new char[size];

    int operation;
    cout << "¬ведите 1 чтобы зашифровать \n ¬ведите 2 чтобы дешифровать \n ƒл€ выхода введите 3 \n";
    cin >> operation;

    if (operation == 3)
    {
      break;
    }
    if (operation == 2)
    {
      shift *= -1;
    }

    for (int i = 0; i < size; ++i)
    {
      res[i] = stroka[i] + shift;
      if (stroka[i] >= 'a' && stroka[i] <= 'z')
      {
        if (res[i] < 'a')
        {
          res[i] = 'z' - ('a' - res[i] - 1);
        }

        if (res[i] > 'z')
        {
          res[i] = 'a' + (res[i] - 'z' - 1);
        }
      }
      else if (stroka[i] >= 'A' && stroka[i] <= 'Z')
      {
        if (res[i] < 'A')
        {
          res[i] = 'Z' - ('A' - res[i] - 1);
        }

        if (res[i] > 'Z')
        {
          res[i] = 'A' + (res[i] - 'Z' - 1);
        }
      }
    }
    for (int i = 0; i < size; ++i)
    {
      cout << res[i];
    }
    cout << endl;
    delete[]stroka;
    delete[]res;
  }
  return 0;
}