int adc;
float volt;
int lm35 = A1;
int val = 0;
int temp;
int LOADCELL = A2;
int LOAD = 0;
int load;
int min_temp = 24;

void setup()
{
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  adc = analogRead(A0);
  val = analogRead(A1);
  temp = val * 5;
  temp *= 100;
  temp /= 1024;
  LOAD = analogRead(A2);
  
  // KONDISI MENYALAKAN LED 1
 if (( ADC >100) && (temp < min_temp)){  
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  Serial.print("Nilai ADC: ");
  Serial.println(adc);
  Serial.print("Nilai temp: ");
  Serial.println(temp);
  Serial.print("Nilai LOAD: ");
  Serial.println(LOAD);
  delay(1000);
  }
  //KONDISI MENYALAKAN LED 2
    if (( ADC < 100) && (temp > min_temp)){ 
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  Serial.print("Nilai ADC: ");
  Serial.println(adc);
  Serial.print("Nilai temp: ");
  Serial.println(temp);
  Serial.print("Nilai LOAD: ");
  Serial.println(LOAD);
  delay(1000);
  }
  //KONDISI MENYALAKAN LED 3
   if ((temp >= min_temp) && (LOAD <= 5)){ 
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  Serial.print("Nilai ADC: ");
  Serial.println(adc);
  Serial.print("Nilai temp: ");
  Serial.println(temp);
  Serial.print("Nilai LOAD: ");
  Serial.println(LOAD);
  delay(1000);
   }
}
 
