#include <stdio.h>
#include <string.h>

bool isValidName(char *str) {
  int len = strlen(str);

  if(len < 3 || len > 20) {
    return false;
  }

  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] == ' ') {
      return false;
    }
  }

  return true;
}

bool isValidJob(char *str) {
  if(strcmp(str, "fighter") == 0 || 
  strcmp(str, "rogue") == 0 || 
  strcmp(str, "mage") == 0) {
    return true;
  }

  return false;
}

bool isValidLevel(int level) {
  return (level < 1 || level > 105) ? false : true;
}