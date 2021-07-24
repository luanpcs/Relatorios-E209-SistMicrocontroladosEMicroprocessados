int cont = 0;

int main(void)
{
  TCCR0A |= (1 << WGM01);              // MODO (CTC)
  TCCR0B |= (1 << CS02) | (1 << CS00); // SELECIONA O DIVISOR DE CLOCK (1024)
  OCR0A = 200;                         // LIMITE DA CONTAGEM
  TIMSK0 |= (1 << OCIE0A);             // HABILITANDO A INTERRUPCAO NO COMPARADOR A

  sei(); // ATIVANDO A INTERRUPCAO GLOBAL

  DDRB |= (1 << PB0);   // PB0 (8) COMO SAIDA
  PORTB &= ~(1 << PB0); // DESLIGANDO O PB0
  while (1);
}

ISR(TIMER0_COMPA_vect) // VETOR DE INTERRUPÇÃO DO COMPARADOR A
{
  cont++; // INCREMENTA A VARIÁVEL CONT 0 - 1 - 2 - 3
  if (cont >= 78)
  { // (CADA CONTAGEM DE 200 LEVA 12,8ms ((1/16MHZ)/1024)*200) = 12,8ms)
    // A CADA 78 CONTAGENS DE 200 = 1s (12,8ms * 78)
    PORTB ^= (1 << PB0); // INVERTE O LED DO PINO PB0 (8)
    cont = 0;            // ZERA A VARIAVEL CONT
  }
}
