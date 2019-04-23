#define CW 0
#define CCW 1

#define MOTOR_A 0
#define MOTOR_B 1

const byte PWMA = 3;
const byte PWMB = 11;
const byte DIRA = 12;
const byte DIRB = 13;

int qreLeft = 0;
int qreRight = 2;

byte spd = 240;
byte hiSpd = 255;

int threshold = 800;

void setup() {
  setupArdumoto();

}

void loop() {
  int QRE_Left = analogRead(qreLeft);
  int QRE_Right = analogRead(qreRight);
  if (QRE_Left > threshold && QRE_Right > threshold){
    forward();
    }
    else if (QRE_Left < threshold && QRE_Right > threshold){
      bearRight();
      }
      else if (QRE_Left > threshold && QRE_Right < threshold){
        bearLeft();
        }

}

void driveArdumoto(byte motor, byte dir, byte spd){
  if (motor == MOTOR_A){
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
    }
    else if(motor==MOTOR_B){
      digitalWrite(DIRB, dir);
      digitalWrite(PWMB, spd);
      }
  }

  void forward(){
    driveArdumoto(MOTOR_A, CW, spd);
    driveArdumoto(MOTOR_B, CW, spd);
    }

   void bearRight(){
    driveArdumoto(MOTOR_B, CW, 0);
    driveArdumoto(MOTOR_A, CW, hiSpd);
    }

    void bearLeft(){
    driveArdumoto(MOTOR_B, CW, hiSpd);
    driveArdumoto(MOTOR_A, CW, 0);
    }

    void setupArdumoto(){
          pinMode(PWMA, OUTPUT);
          pinMode(PWMB, OUTPUT);
          pinMode(DIRA, OUTPUT);
          pinMode(DIRB, OUTPUT);

          digitalWrite(PWMA, LOW);
          digitalWrite(PWMB, LOW);
          digitalWrite(DIRA, LOW);
          digitalWrite(DIRB, LOW);
      }
