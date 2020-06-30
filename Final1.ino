bool selftest = true;
bool infirstmode = true;
byte passord[4] = {1, 2, 3, 4};
byte changepassword[4] = {1, 2, 1, 2};
byte matchpass = 0;
byte matchreverspass = 4;
byte changepass = 0;
bool takethefour = false;
byte take = 0;

bool erro = false;
bool errorevers = false;
bool errochange = false;

bool keytodraw = false;
int keypreswhendraw = 0;

bool  rows[10][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 1}};
bool  colums[10][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 1}};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);

}

void loop() {
  if (selftest) {
    offallrows();
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        onspacificled(rows[j][0], rows[j][1], rows[j][2], rows[j][3], colums[i][0], colums[i][1], colums[i][2], colums[i][3], 1);
      }
      delay(200);
      offallrows();
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        onspacificled(rows[i][0], rows[i][1], rows[i][2], rows[i][3], colums[j][0], colums[j][1], colums[j][2], colums[j][3], 1);
      }
      delay(200);
      offallrows();
    }
    selftest = false;
  }
  mode();
}
void onspacificled(bool cbit0, bool cbit1, bool cbit2, bool cbit3, bool rbit0, bool rbit1, bool rbit2, bool rbit3, bool ledstatus) {
  digitalWrite(9, 0);
  digitalWrite(0, cbit0);
  digitalWrite(1, cbit1);
  digitalWrite(2, cbit2);
  digitalWrite(3, cbit3);
  digitalWrite(4, rbit0);
  digitalWrite(5, rbit1);
  digitalWrite(6, rbit2);
  digitalWrite(7, rbit3);
  digitalWrite(8, ledstatus);
  digitalWrite(9, 1);
}
void offallrows() {
  for (int k = 0; k < 10; k++) {
    for (int m = 0; m < 10; m++) {
      onspacificled(rows[k][0], rows[k][1], rows[k][2], rows[k][3], colums[m][0], colums[m][1], colums[m][2], colums[m][3], 0);
    }
  }
}
void drawongrid(bool  grid[10][10], int currentdraw) {
  offallrows();
  keypreswhendraw = 0;
  keytodraw = false;
  for (int i = 0; i < 10; i++) {
    int g = 0;
    for (int j = 0; j < 10; j++) {
      onspacificled(rows[i][0], rows[i][1], rows[i][2], rows[i][3], colums[j][0], colums[j][1], colums[j][2], colums[j][3], grid[i][g]);
      if (analogRead(A0) > 0) {
        keypreswhendraw = analogRead(A0);
        if (keypreswhendraw != currentdraw) {
          keytodraw = true;
          break;
        }
      }
      if (grid[i][g]) {
        delay(100);
      }
      g++;
    }
  }
}
void checkmatch(byte num) {
  if (takethefour) {
    passord[take] = num;

    take++;
    if (take == 4) {
      takethefour = false;
      take = 0;
    }
  }
  else {
    if (erro) {
      matchpass = 0;
    }
    if (errochange) {
      changepass = 0;
    }
    if (errorevers) {
      matchreverspass = 4;
    }
    if (changepassword[changepass] == num) {

      errochange = false;
      changepass++;
      if (changepass == 4) {

        takethefour = true;

      }
    }
    else {
      errochange = true;
    }
    if (infirstmode)
      if (passord[matchpass] == num) {

        erro = false;
        matchpass++;
        if (matchpass == 4) {
          infirstmode = false;
          matchpass = 0;
          takethefour = false;

        }
      }
      else {
        erro = true;
      }

    else {
      if (passord[matchreverspass - 1] == num) {

        errorevers = false;
        matchreverspass--;
        if (matchreverspass == 0) {
          infirstmode = true;
          matchreverspass = 4;
          takethefour = false;

        }
      }
      else {
        errorevers = true;
      }

    }
  }
}
void drawkey( int key) {
  bool  zero[10][10] = {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  bool  one[10][10] = {{0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 0, 0}};
  bool  two[10][10] = {{0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  three[10][10] = {{0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  four[10][10] = {{0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
  bool  five[10][10] = {{0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}};
  bool  six[10][10] = {{0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}};
  bool  seven[10][10] = {{0, 0, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};
  bool  eight[10][10] = {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  bool  nine[10][10] = {{0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}};
  if (key == 719) {
    checkmatch(0);

    drawongrid( zero, 719);
  }
  else if (key == 894) {
    checkmatch(1);

    drawongrid(one, 894);
  }
  else if (key == 911) {
    checkmatch(2);

    drawongrid(two, 911);
  }
  else if (key == 929) {
    checkmatch(3);

    drawongrid(three, 929);
  }
  else if (key == 822) {
    checkmatch(4);

    drawongrid(four, 822);
  }
  else if (key == 837) {
    checkmatch(5);

    drawongrid(five, 837);
  }
  else if (key == 852) {
    checkmatch(6);

    drawongrid(six, 852);
  }
  else if (key == 761) {
    checkmatch(7);

    drawongrid(seven, 761);
  }
  else if (key == 773) {
    checkmatch(8);

    drawongrid(eight, 773);
  }
  else if (key == 786) {
    checkmatch(9);

    drawongrid(nine, 786);
  }
}

void drawemoj( int key) {
  bool  smile[10][10] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  sad[10][10] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  surprised[10][10] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  ok[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  bool  dontok[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  bool  upsidedwon[10][10] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
  bool  heart[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  bool  right[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  bool  left[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  bool  verysad[10][10] = {{0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 1, 1, 0, 0, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};

  if (key == 719) {
    checkmatch(0);

    drawongrid( smile, 719);
  }
  else if (key == 894) {
    checkmatch(1);

    drawongrid(sad, 894);
  }
  else if (key == 911) {
    checkmatch(2);

    drawongrid(surprised, 911);
  }
  else if (key == 929) {
    checkmatch(3);

    drawongrid(ok, 929);
  }
  else if (key == 822) {
    checkmatch(4);

    drawongrid(dontok, 822);
  }
  else if (key == 837) {
    checkmatch(5);

    drawongrid(upsidedwon, 837);
  }
  else if (key == 852) {
    checkmatch(6);

    drawongrid(heart, 852);
  }
  else if (key == 761) {
    checkmatch(7);

    drawongrid(right, 761);
  }
  else if (key == 773) {
    checkmatch(8);

    drawongrid(left, 773);
  }
  else if (key == 786) {
    checkmatch(9);

    drawongrid(verysad, 786);
  }
}

void mode() {
  if (!keytodraw) {
    int key = analogRead(A0);
    if (key > 0) {

      if (infirstmode) {
        drawkey(key);
      }
      else {
        drawemoj(key);
      }
    }
  }
  else {

    if (infirstmode) {
      drawkey(keypreswhendraw);
    }
    else {
      drawemoj(keypreswhendraw);
    }
  }
}
