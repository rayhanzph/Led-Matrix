
const int rows[] = { 0, 1, 2, 3, 4, 5, 6 };
const int cols[] = { 13, 12, 11, 10, 9, 8, 7 };

const int led[37][2] = { {0, 3}, {1, 4}, {2, 5}, {3, 6},
                         {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6},
                         {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6},
                         {0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6},
                         {1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}, {6, 5},
                         {2, 0}, {3, 1}, {4, 2}, {5, 3}, {6, 4},
                         {3, 0}, {4, 1}, {5, 2}, {6, 3}
                       };

// letter
// index 0 berisi panjang array

int A[] = {12, 6, 11, 12, 17, 19, 23, 24, 25, 26, 28, 32};
int B[] = {12, 5, 6, 7, 13, 17, 18, 19, 26, 29, 30, 31};
int C[] = {10, 5, 6, 7, 10, 16, 23, 29, 30, 31};
int D[] = {11, 5, 6, 7, 13, 17, 20, 26, 29, 30, 31};
int N[] = {11, 5, 8, 10, 11, 13, 16, 18, 19, 22, 25};
int E[] = {12, 5, 6, 7, 10, 17, 18, 19, 23, 29, 30, 31};
int H[] = {13, 5, 7, 8, 10, 13, 17, 18, 19, 23, 26, 28, 31};
int HI[] = {13, 4, 8, 9, 10, 13, 14, 15, 17, 19, 21, 24, 25};
int S[] = {12, 5, 6, 7, 10, 17, 18, 19, 26, 29, 30, 31};
int M[] = {12, 5, 7, 10, 11, 12, 13, 16, 18, 20, 22, 27};
int G[] = {12, 5, 6, 7, 10, 16, 19, 23, 26, 29, 30, 31};
int T[] = {8, 10, 11, 12, 13, 18, 24, 30};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 7; i++){
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}
int timeCount = 0;
void loop() {
  // put your main code here, to run repeatedly:
   timeCount += 2;
   if(timeCount < 200){
    draw(A);
   }else if(timeCount < 400){
    draw(N);
   }else if(timeCount < 600){
    draw(E);
   }else if(timeCount < 800){
    draw(H);
   }else if(timeCount < 1000){
    draw(HI);
   }else{
    delay(1000);
    timeCount = 0;
   }
}

void draw(int alphabet[]){
  for(int i = 0; i < 37; i++){
    digitalWrite(rows[led[i][0]], HIGH);
    digitalWrite(cols[led[i][1]], LOW);
  }
  for(int i = 1; i < alphabet[0]; i++){
    digitalWrite(rows[led[alphabet[i]][0]], LOW);
    digitalWrite(cols[led[alphabet[i]][1]], HIGH);
    delay(1);
    digitalWrite(rows[led[alphabet[i]][0]], HIGH);
    digitalWrite(cols[led[alphabet[i]][1]], LOW);
  }
}
