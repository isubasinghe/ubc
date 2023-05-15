int uninit() {
  int x;
  return x;
}

int overflow(int x) {
  return x + 1;
}

int underflow(int x) {
  return x - 1;
}


int overflow1(int x) {
  return x + (23 + 234);
}


int overflow2(int x, int y) {
  return y+23+(x+45);
}

int overflow3(int x, int y, int z) {
  return x + y + z;
}

int overflow4(int x, int y) {
  return x + (y - 45);
}
