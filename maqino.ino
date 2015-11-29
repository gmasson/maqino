/* -------------------------------------------------
 Sistema de estudo para maquina de lavar roupas
 Fase de Desenvolvimento
------------------------------------------------- */

// Tempos (Alterar valores para prática)
int Delay = 1500;
int Secagem = 10000;
int Stop = 600;
int Provisorio = 1000; // vai ser substituido por ÍNPUT de sensores

// Pinos
int Rotation = 8;
int in = 9;
int out = 10;

// Codigos
void setup(){
  pinMode(Rotation, OUTPUT);
  pinMode(out, OUTPUT);
  pinMode(in, OUTPUT);
}

void esvaziar() {
  digitalWrite(out, HIGH);
  delay(Provisorio); // Trocar por controle de sensores de agua
  digitalWrite(out, LOW);
  delay(Stop); // Stop
}

void encher() {
  digitalWrite(in, HIGH);
  delay(Provisorio); // Trocar por controle de sensores de agua
  digitalWrite(in, LOW);
  delay(Stop); // Stop
}

void loop(){
  // ---------- Ciclo 1 -> Encher maquina com agua
  encher();

  // ---------- Ciclo 2 -> Lavagem
  for (int i = 0; i < 20; i++) {
    digitalWrite(Rotation,HIGH);
    delay(Delay);
    digitalWrite(Rotation,LOW);
    delay(Stop); // Stop
  }

  // ---------- Ciclo 3 -> Troca de Agua
  esvaziar();
  encher();

  // ---------- Ciclo 4 -> Enchague
  for (int i = 0; i < 25; i++) {
    digitalWrite(Rotation,HIGH);
    delay(Delay);
    digitalWrite(Rotation,LOW);
    delay(Stop); // Stop
  }

  // ---------- Ciclo 5 -> Retiragem da Agua de Enchague
  esvaziar();

  // ---------- Ciclo 6 -> Secagem
  digitalWrite(Rotation,HIGH);
  delay(Secagem);
  digitalWrite(Rotation,LOW);
  
  delay(Stop); // Stop
}
