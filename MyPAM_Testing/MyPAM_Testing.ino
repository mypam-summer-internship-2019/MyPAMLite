
//////////////////////////////////////////////////
static double pot1Val;
static double pot2Val;
static int pot1 = A4;
static int pot2 = A1;
double L1 = 340;
double L2 = 230;
double angle1 = 0;
double angle2 = 0;
double angle1Offset = 54;
double angle2Offset = -0;
double mappValue = 2.841;
double xPos = 0;
double yPos = 0;
String data;

double xOffset = 190;
double yOffset = 330;

float targetX;
float targetY;
float kP;
float kI;
float kD;
//////////////////////////////////////////////////

void setup() 
{
  Serial.begin(38400);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
}

void loop() 
{
  while (Serial.available() == 0) {}
  targetX = Serial.parseFloat();
  
  while (Serial.available() == 0) {}
  targetY = Serial.parseFloat();

  while (Serial.available() == 0) {}
  kP = Serial.parseFloat();

  while (Serial.available() == 0) {}
  kI = Serial.parseFloat();

  while (Serial.available() == 0) {}
  kD = Serial.parseFloat();
  
  pot1Val = analogRead(pot1);
  pot2Val = analogRead(pot2);

  angle1 = (pot1Val / mappValue) + angle1Offset;
  angle2 = (pot2Val / mappValue) + angle2Offset;
  
  yPos = -(cos((angle1)/180*PI)*L1 + cos(((angle1+angle2)/180*PI))*L2) + yOffset;
  xPos = sin((angle1)/180*PI)*L1 + sin(((angle1+angle2)/180*PI))*L2 + xOffset;

  if (yPos > 105)
  {
    yPos = 105;
  }
  else if (yPos < -105)
  {
    yPos = -105;
  }

  if (xPos > 150)
  {
    xPos = 150;
  }
  else if (xPos < -150)
  {
    xPos = -150;
  }

  data = (String)(xPos) + "|";
  data = data + yPos;
  data = data + "|";
  data = data + angle1;
  data = data + "|";
  data = data + angle2;
  Serial.println(data);
}


///////////Controller Info/////////////////////////////
/*
90 Degrees = about  550 - 300 = 250
250 / 90 = 2.77778 (10 bit ADC)
*/
/////////////////////////////////////////////////////
