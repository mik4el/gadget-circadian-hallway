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
#define color_delay 60000             //Define the delay between changing colors in ms
#define time_at_color 0           //Time to stay on a color in ms

//Some Time values
unsigned long TIME_LED = 0;
unsigned long TIME_PHASE = 0;
unsigned long TIME_color = 0;
boolean is_using_morning_colors = true;

//Evening colors defined here
#define E_C1_R 200
#define E_C1_G 10
#define E_C1_B 0

#define E_C2_R 225
#define E_C2_G 20
#define E_C2_B 0

#define E_C3_R 255
#define E_C3_G 40
#define E_C3_B 0

#define E_C4_R 245
#define E_C4_G 30
#define E_C4_B 0

#define E_C5_R 150
#define E_C5_G 10
#define E_C5_B 0

#define E_MAX_COLOR_DIFFERENCE 55

//Morning colors defined here
#define M_C1_R 145
#define M_C1_G 13
#define M_C1_B 255

#define M_C2_R 72
#define M_C2_G 12
#define M_C2_B 232

#define M_C3_R 0
#define M_C3_G 0
#define M_C3_B 255

#define M_C4_R 12
#define M_C4_G 70
#define M_C4_B 232

#define M_C5_R 13
#define M_C5_G 140
#define M_C5_B 255

#define M_MAX_COLOR_DIFFERENCE 145

void turn_on_morning_colors()
{
  //Assign initial values
  RED = M_C1_R;
  GREEN = M_C1_G;
  BLUE = M_C1_B;
  //Get the led_delay speed
  led_delay = (color_delay - time_at_color) / M_MAX_COLOR_DIFFERENCE; 
  if (led_delay > 41) led_delay = 41;
  is_using_morning_colors = true;
}

void turn_on_evening_colors()
{
  //Assign initial values
  RED = E_C1_R;
  GREEN = E_C1_G;
  BLUE = E_C1_B;
  //Get the led_delay speed
  led_delay = (color_delay - time_at_color) / E_MAX_COLOR_DIFFERENCE; 
  if (led_delay > 41) led_delay = 41;
  is_using_morning_colors = false;
}

void setup()
{
  turn_on_morning_colors();
  //turn_on_evening_colors();
  
  analogWrite(GRN_PIN, 0);
  analogWrite(RED_PIN, 0);
  analogWrite(BLU_PIN, 0);
}

void loop()
{
  if (millis() - TIME_LED >= led_delay) {
    TIME_LED = millis();

    //Run the LED Function to check and adjust the values
    LED();
  }

  if (millis() - TIME_color >= color_delay) {
    TIME_color = millis();

    //Run the color Change function
    color();
  }

}

void LED()
{
  //Check Values and adjust "Active" Value
  if (RED != RED_A) {
    if (RED_A > RED) RED_A = RED_A - 1;
    if (RED_A < RED) RED_A++;
  }
  if (GREEN != GREEN_A) {
    if (GREEN_A > GREEN) GREEN_A = GREEN_A - 1;
    if (GREEN_A < GREEN) GREEN_A++;
  }
  if (BLUE != BLUE_A) {
    if (BLUE_A > BLUE) BLUE_A = BLUE_A - 1;
    if (BLUE_A < BLUE) BLUE_A++;
  }

  //Assign modified values to the pwm outputs for each color led
  analogWrite(RED_PIN, RED_A);
  analogWrite(GRN_PIN, GREEN_A);
  analogWrite(BLU_PIN, BLUE_A);
}

void color()
{
  //Increment the color by one or go back to 1 if maxed out
  if (color_count < color_count_max) {
    color_count++;
  } else {
    color_count = 1;
  }

  if (color_count == 1) {
    if (is_using_morning_colors) {
      RED = M_C1_R;
      GREEN = M_C1_G;
      BLUE = M_C1_B;    
    } else {
      RED = E_C1_R;
      GREEN = E_C1_G;
      BLUE = E_C1_B;      
    }
  } else if (color_count == 2) {
    if (is_using_morning_colors) {
      RED = M_C2_R;
      GREEN = M_C2_G;
      BLUE = M_C2_B;    
    } else {
      RED = E_C2_R;
      GREEN = E_C2_G;
      BLUE = E_C2_B;      
    }
  } else if (color_count == 3) {
    if (is_using_morning_colors) {
      RED = M_C3_R;
      GREEN = M_C3_G;
      BLUE = M_C3_B;    
    } else {
      RED = E_C3_R;
      GREEN = E_C3_G;
      BLUE = E_C3_B;      
    }
  } else if (color_count == 4) {
    if (is_using_morning_colors) {
      RED = M_C4_R;
      GREEN = M_C4_G;
      BLUE = M_C4_B;    
    } else {
      RED = E_C4_R;
      GREEN = E_C4_G;
      BLUE = E_C4_B;      
    }
  } else if (color_count == 5) {
    if (is_using_morning_colors) {
      RED = M_C5_R;
      GREEN = M_C5_G;
      BLUE = M_C5_B;    
    } else {
      RED = E_C5_R;
      GREEN = E_C5_G;
      BLUE = E_C5_B;      
    }
  }
}
