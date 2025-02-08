const int ti_t = 12500;
const int chardelay_t = 50;
const int worddelay_t = 65;
const int larsondelay = ti_t / 2;
 
void dash()
{
	digitalWrite (7, HIGH);
	delayMicroseconds(ti_t);
	delayMicroseconds(ti_t);
	delayMicroseconds(ti_t);
	digitalWrite (7, LOW);
	delayMicroseconds(ti_t);
}

void dot()
{
	digitalWrite (7, HIGH);
	delayMicroseconds(ti_t);
	digitalWrite (7, LOW);
	delayMicroseconds(ti_t);
}

void chardelay()
{
	delay(chardelay_t);
}

void worddelay()
{
	delay(worddelay_t);
}
 
void setup() {
	pinMode(7, OUTPUT); // lonely

	pinMode(11, OUTPUT); // "led strip"
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(A0, INPUT);
}

int led_strip_cycle[] = { 11,5,6,10,3,9 };
int led_cycle_length = sizeof(led_strip_cycle) / sizeof(led_strip_cycle[0]);

void loop() {

// send the pixels!
	for (int i=0; i<led_cycle_length; i++) {
    for(int a=0; a<3; a++) {
      dash();
		  digitalWrite (led_strip_cycle[i], HIGH);
		  delayMicroseconds(larsondelay);
		  digitalWrite (led_strip_cycle[i], LOW);
      delayMicroseconds(larsondelay);
    }    
    digitalWrite (led_strip_cycle[i], HIGH);
    delayMicroseconds(larsondelay);
  }

// main pixel blinking
  dot();dot();dot();dot();dot();dot();;chardelay();

// eat all pixels reversed
  for (int i=led_cycle_length; i>-1; i--) {
    dash();
    digitalWrite (led_strip_cycle[i], LOW);  
    delayMicroseconds(larsondelay);
  }

// all off
  digitalWrite (11, LOW);
  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (10, LOW);
  digitalWrite (3, LOW);
  digitalWrite (9, LOW);
}

