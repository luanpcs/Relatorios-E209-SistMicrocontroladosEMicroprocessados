#define BUTTON_ON !(PIND & 0b00010000)
#define LED_RED_ON PORTD = PORTD | 0b10000000
#define LED_RED_OFF PORTD = PORTD & ~(0b10000000)
#define LED_GREEN_ON PORTD = PORTD | 0b00100000
#define LED_GREEN_OFF PORTD = PORTD & ~(0b00100000)
#define DELAY _delay_ms(500)
char estado = 0;
int main(void)
{
  DDRD = DDRD | 0b10100000;   // Configurando pino 5 e 7 como saída
  PORTD = PORTD | 0b00010000; // Habilita resistor de PULL-UP
  for (;;)
  {
    switch (estado)
    {
      case 0:
        LED_RED_OFF;   //desliga led do pino 7
        LED_GREEN_OFF; //desliga led do pino 5
        if (BUTTON_ON)
        {
          estado = estado + 1; //incrementa o estado
          DELAY;               // delay para evitar o Bouncing
        }
        break;
      case 1:
        LED_RED_ON;    //liga led do pino 7
        LED_GREEN_OFF; //desliga led do pino 5
        if (BUTTON_ON)
        {
          estado = estado + 1; //incrementa o estado
          DELAY;               // delay para evitar o Bouncing
        }
        break;
      case 2:
        LED_RED_OFF;  //desliga led do pino 7
        LED_GREEN_ON; //liga led do pino 5
        if (BUTTON_ON)
        {
          estado = estado + 1; //incrementa o estado
          DELAY;               // delay para evitar o Bouncing
        }
        break;
      case 3:
        LED_RED_ON;   //liga led do pino 7
        LED_GREEN_ON; //liga led do pino 5
        if (BUTTON_ON)
        {
          estado = estado + 1; //incrementa o estado
          DELAY;               // delay para evitar o Bouncing
        }
        break;
      default:
        estado = 0;
        break;
    }
  }
}
