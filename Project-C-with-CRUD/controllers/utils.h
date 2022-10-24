#include <thread>
#include <chrono>

void sleep() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void clearScreen() {
  system("cls||clear");
}