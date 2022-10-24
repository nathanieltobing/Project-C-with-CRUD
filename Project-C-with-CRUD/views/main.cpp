#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../controllers/controller.h"
#include "../controllers/utils.h"
#include "../controllers/validation.h"

void MenuViewAllCharacters(Node *root) {
  if(!root) {
    puts("--- There is no character in the tree ---");
  } else {
    puts("Character List: ");
    sleep();
    printAll(root);
  }
}

int generateCharacterDamage(char *str) {
  srand(time(NULL));

  if(strcmp(str, "fighter") == 0) {
    return rand() % 50; // range 0 - 49
  } else if(strcmp(str, "rogue") == 0) {
    return rand() % 25; // range 0 - 24
  } else if(strcmp(str, "mage") == 0) {
    return rand() % 75; // range 0 - 74
  }

  return -1;
}

Node* MenuAddNewCharacter(Node *root) {
  Character temp;

  do {
    printf("Input Character's Name [3..20][non space char]: ");
    scanf("%[^\n]", temp.name); getchar();
  } while(!isValidName(temp.name));

  do {
    printf("Input Character's Job [fighter/rogue/mage]: ");
    scanf("%[^\n]", temp.job); getchar();
  } while(!isValidJob(temp.job));

  do {
    printf("Input Character's Level [1..105]: ");
    scanf("%d", &temp.level); getchar();
  } while(!isValidLevel(temp.level));

  temp.damage = temp.level + generateCharacterDamage(temp.job);
  sleep();
  puts("--- Add New Character Success ---");
  return insertNode(root, temp);
}

void MenuTraversal(Node *root) {
  if(!root) {
    puts("--- There is no character in the tree ---");
  } else {
    sleep();
    printData(root);
  }
}

int main() {
  Node *baseRoot = NULL;
  bool inGame = true;

  while(inGame) {
    puts("BLUE-LUNA ONLINE");
    puts("----------------");
    puts("1. View All Characters");
    puts("2. Add New Character");
    puts("3. Inorder, Preorder, Postorder Character's Damage");
    puts("4. Exit and Popall");
  
    int input;

    do {
      printf(">> Input Choice : ");
      scanf("%d", &input); getchar();
    } while(input < 1 || input > 4);
    clearScreen();

    switch(input) {
      case 1:
        MenuViewAllCharacters(baseRoot);
        clearScreen();
        break;
      case 2:
        baseRoot = MenuAddNewCharacter(baseRoot);
        clearScreen();
        break;
      case 3:
        MenuTraversal(baseRoot);
        clearScreen();
        break;
      case 4:
        inGame = false;
        clearScreen();
        break;
    }
  }

  return 0;
}