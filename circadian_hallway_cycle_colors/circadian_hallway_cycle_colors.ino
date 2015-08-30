#define GRN_PIN 5
#define RED_PIN 6
#define BLU_PIN 9

byte RED, GREEN, BLUE; 
byte RED_A = 0;
byte GREEN_A = 0; 
byte BLUE_A = 0;
int led_delay = 0;
byte color_count = 1;                //Count the colors out
#define color_count_max 5              //Set this to the max number of colors defined
#define color_delay 20000             //Define the delay between changing colors in ms
#define time_at_color 1           //Time to stay on a color in ms

//Some Time values
unsigned long TIME_LED = 0;
unsigned long TIME_color = 0;

//Evening colors defined here
#define C1_R 200
#define C1_G 10
#define C1_B 0

#define C2_R 225
#define C2_G 20
#define C2_B 0

#define C3_R 255
#define C3_G 40
#define C3_B 0

#define C4_R 245
#define C4_G 30
#define C4_B 0

#define C5_R 150
#define C5_G 10
#define C5_B 0

void setup()
{

  //Assign initial values
  RED = C1_R;
  GREEN = C1_G;
  BLUE = C1_B;
  //Get the led_delay speed
  led_delay = (color_delay - time_at_color) / 255; 

  analogWrite(GRN_PIN, 0);
  analogWrite(RED_PIN, 0);
  analogWrite(BLU_PIN, 0);

}

void loop()
{

  //Rest of your program - Avoid using delay(); function!

  if(millis() - TIME_LED >= led_delay){
    TIME_LED = millis();

    //Run the LED Function to check and adjust the values
    LED();
  }

  if(millis() - TIME_color >= color_delay){
    TIME_color = millis();

    //Run the color Change function
    color();
  }

}

void LED()
{

  //Check Values and adjust "Active" Value
  if(RED != RED_A){
    if(RED_A > RED) RED_A = RED_A - 1;
    if(RED_A < RED) RED_A++;
  }
  if(GREEN != GREEN_A){
    if(GREEN_A > GREEN) GREEN_A = GREEN_A - 1;
    if(GREEN_A < GREEN) GREEN_A++;
  }
  if(BLUE != BLUE_A){
    if(BLUE_A > BLUE) BLUE_A = BLUE_A - 1;
    if(BLUE_A < BLUE) BLUE_A++;
  }

  //Assign modified values to the pwm outputs for each color led
  analogWrite(RED_PIN, RED_A);
  analogWrite(GRN_PIN, GREEN_A);
  analogWrite(BLU_PIN, BLUE_A);

}

void color()
{

  //Increment the color by one or go back to 1 if maxed out
  if(color_count < color_count_max) color_count++;
  else color_count = 1;

  if(color_count == 1){
    RED = C1_R;
    GREEN = C1_G;
    BLUE = C1_B;
  } else if(color_count == 2){
    RED = C2_R;
    GREEN = C2_G;
    BLUE = C2_B;
  } else if(color_count == 3){
    RED = C3_R;
    GREEN = C3_G;
    BLUE = C3_B;
  } else if(color_count == 4){
    RED = C4_R;
    GREEN = C4_G;
    BLUE = C4_B;
  } else if(color_count == 5){
    RED = C5_R;
    GREEN = C5_G;
    BLUE = C5_B;
  }
}
