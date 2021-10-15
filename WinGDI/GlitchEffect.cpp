#include <Windows.h>

int main() {
  for (int i = 0; i < 100; i++) {
    int y = rand() % sh, h = sh - rand() % sh - (sh / 1 - 8);
    HBRUSH brush = CreateSolidBrush(RGB(rand() % 75, rand() % 75, rand() % 75));
    SelectObject(desk, brush);
    BitBlt(desk, 0, y, 1920, h, desk, rand() % 96 - 56, y, SRCCOPY);
    PatBlt(desk, -1, y, 1920, h, PATINVERT);
    Sleep(rand() % 1234);
  }
  return 0;
}
