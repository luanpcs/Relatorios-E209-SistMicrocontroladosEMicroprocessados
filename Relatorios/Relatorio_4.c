int main(void)
{
  DDRD = DDRD | 0b10000000;      // Pino PD7 definido como saída
  PORTD = PORTD | 0b00010000;    // Habilitar resistor de PULL-UP no PD4
  PORTD = PORTD & ~(0b10000000); // Desliga a saída PD7;
  for (;;)
  {
    if ((PIND & 0b00010000) == 0) // Botão pressionado ?
    {
      PORTD = PORTD | 0b10000000; // Aciona a saída
      _delay_ms(5000);
      PORTD = PORTD & ~(0b10000000); // Desliga a saída
    }
  }
}