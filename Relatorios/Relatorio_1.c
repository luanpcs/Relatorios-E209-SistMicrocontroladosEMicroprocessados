char vezes = 0, flag = 0; //Declaração das variáveis globais
int main(void)
{
  DDRD = 0b10000000; // Configura pino 7 como saída
  for (;;)
  {
    while (flag == 0)
    {
      PORTD = PORTD | 0b10000000; // Liga o led que está conectado no pino 7
      _delay_ms(500);             // Espera 500ms
      PORTD = PORTD & 0b01111111; // Desliga o led que está conectado no pino 7
      _delay_ms(500);             // Espera 500ms
      vezes++;
      if (vezes >= 3)
        flag = 1;
    }
  }
}
