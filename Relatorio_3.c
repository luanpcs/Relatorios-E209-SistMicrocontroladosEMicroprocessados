int main(void)
{
  /* Configurando os pinos PD7 e PD5 como saída (sem mascaramento).
    Todos os bits, representantes dos pinos, que tiverem nível lógico:
    1 (HIGH) - serão saída
    0 (LOW) - serão entrada
    Exemplo:
    PINOS Px. = 7 6 5 4 3 2 1 0
    BINARIO = 1 0 1 0 0 0 0 0
    HEX = 0x A | 0 => 0XA0
  */
  DDRD = 0xA0; // PD5 e PD7 agora são saída
  while (1)
  {
    /*
      P1OUT serve para atribuir um nível lógico alto (1) ou baixo (0) ao pino. Exemplo:
      1-) Quero atribuir nível lógico alto (1) para o pino PD5
      PINOS Px. = 7 6 5 4 3 2 1 0
      BINARIO = 0 0 1 0 0 0 0 0
      HEX = 0x 2 | 0 => 0x20.
      2-) Quero atribuir nível lógico alto (1) para o pino PD7
      PINOS Px. = 7 6 5 4 3 2 1 0
      BINARIO = 1 0 0 0 0 0 0 0
      HEX = 0x 8 | 0 => 0x80.
      3-) Quero desligar todos os pinos
      PINOS = 7 6 5 4 3 2 1 0
      BINARIO = 0 0 0 0 0 0 0 0
      HEX = 0x 0 | 0 => 0x00.
      No exemplo abaixo ficará piscando os leds VERDE(PD5) e VERMELHO (PD7), de acordo
      com a montagem no thinkercad.
    */
    PORTD = 0xA0;    // ligando os pino PD5 e PD7.
    _delay_ms(1000); // delay_ms contabiliza em ms, então 1000 * 1ms = 1s.
    PORTD = 0x00;    // desligando todos pinos.
    _delay_ms(1000); // delay de 1s.
  }
}
