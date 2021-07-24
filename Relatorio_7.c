ISR(INT0_vect)
{
  // Inverte a saída 7 (PD7)
  PORTD ^= 0b10000000;
}
int main(void)
{
  // Configura os pinos 7 (PD7) e 6 (PD6) como saída
  DDRD = 0b11000000;
  // Habilita o resistor interno de pull-up no pino 2 (PD2)
  PORTD = 0b00000100;
  // Configura a interrupção externa 0 para transição de descida
  EICRA = 0b00000010;
  // Habilita a interrupção externa 0
  EIMSK = 0b00000001;
  // Habilita a interrupção global
  sei();
  //Superloop
  while (1)
  {
    // Inverte a saída 6 (PD6)
    PORTD ^= 0b01000000;
    _delay_ms(500);
  }
}