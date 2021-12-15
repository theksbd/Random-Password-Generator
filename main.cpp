#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void inputLength(int& length, bool isInput = false)
{
  do 
  {
  isInput && cout << "=======================================\nYour length is invalid (<= 0). Please give us an approriate number!!\n=======================================\n";
  cout << "Input your password's length: ";
  cin >> length;
  isInput = true;
  } while (length <= 0);
}

void setUpChar (bool& containSymbol, bool& containLowerChar, bool& containUpperChar, bool& containNumber)
{
  // int countType = 0; // count for number of types of characters included in password;
  cout << "Include Symbols (type 1 for YES, 0 for NO): ";
  cin >> containSymbol;
  cout << "Include Lowercase Characters (type 1 for YES, 0 for NO): ";
  cin >> containLowerChar;
  cout << "Include Uppercase Characters (type 1 for YES, 0 for NO): ";
  cin >> containUpperChar;
  cout << "Include Numbers (type 1 for YES, 0 for NO): ";
  cin >> containNumber;
}

int getRandom (int low, int high)
{
  // srand(time(0));
  return low + (rand() % (high - low + 1));
}

void generateRandomSymbol (int type)
{
  switch(type)
  {
    case 1: // symbol
    {
    char symbol1 = getRandom(35, 38);
    char symbol2 = '!', symbol3 = '@';
    int selector = getRandom(1, 3);
    if (selector == 1)
      cout << symbol1;
    else if (selector == 2)
      cout << symbol2;
    else
      cout << symbol3;
    break;
    }
    case 2: // lower char
    {
    char symbol = getRandom(97, 122);
    cout << symbol;
    break;
    }
    case 3: // upper char
    {
    char symbol = getRandom(65, 90);
    cout << symbol;
    break;
    }
    default: // number
    {
    char symbol = getRandom(48, 57);
    cout << symbol;
    break;
    }
  }
}

int main() {
  int length = 0;
  inputLength(length);
  
  bool containSymbol = false, // ( e.g. @#$% ...)
  containLowerChar = false, // ( e.g. abcdef ...)
  containUpperChar = false, // ( e.g. ABCDEF ...)
  containNumber = false; // ( e.g. 0123456789 )
  setUpChar(containSymbol, containLowerChar, containUpperChar, containNumber);
  
  srand(time(0));
  cout << "Your password: ";
  for (int i = 0; i < length; i++)
  {
    bool reRandom = false;
    do
    {
      int section = getRandom(1, 4);
      switch(section)
      {
        case 1:
        if (containSymbol)
        {
          generateRandomSymbol(1);
          reRandom = false;
        }
        else
          reRandom = true;
        break;
        case 2:
        if (containLowerChar)
        {
          generateRandomSymbol(2);
          reRandom = false;
        }
        else
          reRandom = true;
        break;
        case 3:
        if (containUpperChar)
        {
          generateRandomSymbol(3);
          reRandom = false;
        }
        else
          reRandom = true;
        break;
        default:
        if (containNumber)
        {
          generateRandomSymbol(4);
          reRandom = false;
        }
        else
          reRandom = true;
        break;
      }
    } while (reRandom == true);
  }

  return 0;
} 
