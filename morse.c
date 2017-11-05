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
	// naaman pinnit järjestyksessä
	// yksinäinen morsesilmä
	pinMode(7, OUTPUT);
	//larson skanner simmut vasemmalta oikealle
	pinMode(11, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(A0, INPUT);

	dash();dot();dot();chardelay();dot();dot();chardelay();
	dot();dot();dot();chardelay();dash();dash();dash();chardelay();
	dash();dot();dot();dot();chardelay();dot();chardelay();dash();dot();dash();dash();
}
 
void loop() {
	// joka 12. kerta näytettään challenge koodi

	for (int i=0; i < 10; i++) {
		//larson vasemmalta oikealle
		digitalWrite (11, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (11, LOW);
		digitalWrite (5, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (5, LOW);
		digitalWrite (6, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (6, LOW);
		digitalWrite (10, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (10, LOW);
		digitalWrite (3, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (3, LOW);
		digitalWrite (9, HIGH);
		delayMicroseconds(larsondelay);
		//larson oikealta vasemmalle
		digitalWrite (9, LOW);
		digitalWrite (3, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (3, LOW);
		digitalWrite (10, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (10, LOW);
		digitalWrite (6, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (6, LOW);
		digitalWrite (5, HIGH);
		delayMicroseconds(larsondelay);
		digitalWrite (5, LOW);
		digitalWrite (11, HIGH);
		delayMicroseconds(larsondelay);
	}
	digitalWrite (11, LOW);

	dot();dot();dash();dot();chardelay();dot();dot();chardelay();
	dash();dot();chardelay();dash();dot();dot();chardelay();worddelay();
	chardelay();dash();dash();dash();chardelay();dash();dot();chardelay();
	dot();dot();chardelay();dash();dot();chardelay();dot();dot();

	// asetetaan varmuudeksi kaikki pinnit alas
	digitalWrite (7, LOW);
	digitalWrite (5, LOW);
	digitalWrite (6, LOW);
	digitalWrite (9, LOW);
	digitalWrite (10, LOW);
	digitalWrite (3, LOW);
	digitalWrite (7, LOW);
	digitalWrite (11, LOW);
}
