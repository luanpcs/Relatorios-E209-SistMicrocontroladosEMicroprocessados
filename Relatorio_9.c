#define pwmOut (1 << PD6)
int brightness = 0;
void setup()
{
  DDRD |= pwmOut;   // configura saída para o PWM
  PORTD &= ~pwmOut; // PWM inicia desligado
  // Configura modo FAST PWM e modo do comparador A
  TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
  TCCR0B = (1 << CS00); // Seleciona opção para frequência
}
void loop()
{
  OCR0A = brightness;
  brightness += 10;
  if (brightness > 255)
    brightness = 0;
  _delay_ms(100);
}
