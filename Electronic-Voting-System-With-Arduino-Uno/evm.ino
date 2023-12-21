#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int S1 = 7;
int S2 = 6;
int S3 = 5;
int S4 = 4;
int S5 = 3;

int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  lcd.begin(16, 2);
  lcd.print("EVM ");
  delay(4000);

  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
  digitalWrite(S5, HIGH);

  lcd.clear();
  lcd.setCursor(1, 0); lcd.print("A");
  lcd.setCursor(5, 0); lcd.print("B");
  lcd.setCursor(9, 0); lcd.print("C");
  lcd.setCursor(13, 0); lcd.print("D");
}

void loop() {
  displayVotes();
  readButtons();
  displayWinner();
}

void displayVotes() {
  lcd.setCursor(1, 1); lcd.print(vote1);
  lcd.setCursor(5, 1); lcd.print(vote2);
  lcd.setCursor(9, 1); lcd.print(vote3);
  lcd.setCursor(13, 1); lcd.print(vote4);
}

void readButtons() {
  if (digitalRead(S1) == LOW) {
    vote1++;
    while (digitalRead(S1) == LOW);
  }
  if (digitalRead(S2) == LOW) {
    vote2++;
    while (digitalRead(S2) == LOW);
  }
  if (digitalRead(S3) == LOW) {
    vote3++;
    while (digitalRead(S3) == LOW);
  }
  if (digitalRead(S4) == LOW) {
    vote4++;
    while (digitalRead(S4) == LOW);
  }
}

void displayWinner() {
  if (digitalRead(S5) == LOW) {
    int totalVotes = vote1 + vote2 + vote3 + vote4;

    if (totalVotes > 0) {
      int maxVotes = max(max(vote1, vote2), max(vote3, vote4));

      if (maxVotes == vote1) {
        lcd.clear();
        lcd.print("A is Winner");
      } else if (maxVotes == vote2) {
        lcd.clear();
        lcd.print("B is Winner");
      } else if (maxVotes == vote3) {
        lcd.clear();
        lcd.print("C is Winner");
      } else if (maxVotes == vote4) {
        lcd.clear();
        lcd.print("D is Winner");
      }
    } else {
      lcd.clear();
      lcd.print("No Voting");
    }

    delay(3000);
    lcd.clear();
    vote1 = 0; vote2 = 0; vote3 = 0; vote4 = 0;
  }
}
