//Initialize the 7 segment pins
int A = 3;
int B = 10;
int C = 4;
int D = 5;
int DP = 7;
int E = 6;
int F = 8;
int G = 9;
int p2 = 12;
int p1 = 11;

//Initialize the push buttons pins, push buttons states, and the counter
int switchUpPin = 13;
int counter = 0;
int buttonUpState = 0;
int lastButtonUpState = 0;

int pd=2;                        //Photodiode to digital pin 2
 int led=13;                     //piezo leder to digital pin 13  
 int senRead=0;                  //Readings from sensor to analog pin 0  
 int limit=40;                   //Threshold range of an obstacle  


void setup() 
{ 
 Serial.begin(9600);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);

  //Start with the deceimal point off
  digitalWrite(DP ,HIGH);
  
  
  pinMode(pd,OUTPUT);  
  pinMode(led,OUTPUT);  
  digitalWrite(pd,HIGH);       //supply 5 volts to photodiode  
  digitalWrite(led,LOW);      //set the led in off mode (initial condition)  
  Serial.begin(9600);          //setting serial monitor at a default baund rate of 9600  


}

void loop() 
{
  //Getting the reads from the buttons
  buttonUpState = digitalRead(switchUpPin);


  //Detecting button press and getting the button status
  //Do this for the button up
  if (buttonUpState != lastButtonUpState) 
  {
    if (buttonUpState == HIGH) 
    {
      //Reset the counter to -1
      if(counter == 99)
      {
        counter = -1;
      }
      //Increase the counter by 1
      counter++;
      changeNumber(counter);
      //Delaying by 50 ms
      delay(50);
    }
    //Delay to avoid button bouncing
   delay(50);
  }

  //Calling the function changeNumber with the arg counter
  changeNumber(counter);
 
 
 int val=analogRead(senRead);  //variable to store values from the photodiode  
  Serial.println(val);          // prints the values from the sensor in serial monitor  
  if(val <= limit)              //If obstacle is nearer than the Threshold range  
  {  
   digitalWrite(led,LOW);     // led will be in ON state  
   delay(20);  
  }  
  else if(val > limit)          //If obstacle is not in Threshold range  
  {  
   digitalWrite(led,HIGH);      //leder will be in ON state  
   delay(20);  
  }  

  
}

//The function to display the numbers
void changeNumber(int buttonPress)
{
  int second = buttonPress/10;
  int first = buttonPress%10;
  digitalWrite(p1, HIGH);
  digitalWrite(p2, LOW);
  switch (first)
  {
    //number 0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    //number 1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 3
    case 3:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 4
    case 4:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 5
    case 5:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 7
    case 7:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 9
    case 9:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
  delay(1);
   digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
  switch (second)
  {
    //number 0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    //number 1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 3
    case 3:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 4
    case 4:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 5
    case 5:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 7
    case 7:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 9
    case 9:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
   //digitalWrite(p1, HIGH);
   delay(1);
}