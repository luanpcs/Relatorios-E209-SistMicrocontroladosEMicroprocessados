// PINAGEM ARDUINO ATMega328p:
// RS = 12 PB4
// EN = 11 PB3
// D4 = 5 PD5
// D5 = 4 PD4
// D6 = 3 PD3
// D7 = 2 PD7
#define P5 0b00100000
#define P4 0b00010000
#define P3 0b00001000
#define P2 0b00000100
// Data Pins
#define LCD_D0 P5
#define LCD_D1 P4
#define LCD_D2 P3
#define LCD_D3 P2
// Control Pins
#define LCD_RS P4
#define LCD_EN P3

#define LCD_EN_ON PORTB |= LCD_EN
#define LCD_EN_OFF PORTB &= ~LCD_EN
#define LCD_RS_ON PORTB |= LCD_RS
#define LCD_RS_OFF PORTB &= ~LCD_RS
#define LCD_D0_ON PORTD |= LCD_D0
#define LCD_D0_OFF PORTD &= ~LCD_D0
#define LCD_D1_ON PORTD |= LCD_D1
#define LCD_D1_OFF PORTD &= ~LCD_D1
#define LCD_D2_ON PORTD |= LCD_D2
#define LCD_D2_OFF PORTD &= ~LCD_D2
#define LCD_D3_ON PORTD |= LCD_D3
#define LCD_D3_OFF PORTD &= ~LCD_D3
#define LCD_DATA_OFF PORTD &= (~(LCD_D0 + LCD_D1 + LCD_D2 + LCD_D3))
#define LCD_DATA_DIR DDRD |= (LCD_D0 + LCD_D1 + LCD_D2 + LCD_D3)
// Functions
// Send a command to the display
void LCDCmd(uint8_t cmd)
{
  LCD_RS_OFF;
  sendnibble(cmd >> 4);
  sendnibble(cmd & 0x0F);
}
// Routine to work with four bits
void sendnibble(uint8_t data)
{
  LCD_DATA_OFF;
  if ((data & 0x01) == 0x01) LCD_D0_ON;
  if ((data & 0x02) == 0x02) LCD_D1_ON;
  if ((data & 0x04) == 0x04) LCD_D2_ON;
  if ((data & 0x08) == 0x08) LCD_D3_ON;
  LCD_EN_ON;
  delayLCD();
  LCD_EN_OFF;
}
// Initializes display
void InitLCD(void)
{
  LCD_DATA_DIR;
  LCD_EN_OFF;
  LCD_RS_OFF;
  sendnibble(0x30 >> 4);
  delayLCD();
  sendnibble(0x30 >> 4);
  delayLCD();
  sendnibble(0x30 >> 4);
  delayLCD();
  sendnibble(0x20 >> 4);
  delayLCD();
  LCDCmd(0x28);
  delayLCD();
  LCDCmd(0x08);
  delayLCD();
  LCDCmd(0x0C);
  delayLCD();
  LCDCmd(0x01);
  delayLCD();
}
// Delay to set up the display
void delayLCD(void)
{
  _delay_ms(0.2);
}
// Send a message to the display
void LCDPrintStr (const char *data)
{
  while (*data != 0)
    LCDChar(*data++);
}
// Send a message to the display in the position X,Y
void LCDPrintXYStr (uint8_t x, uint8_t y, const char *data)
{
  uint8_t pos;
  pos = x - 1;
  if (y == 1)
  {
    pos = pos + 0x80;
    LCDCmd(pos);
  }
  else if (y == 2)
  {
    pos = pos + 0xc0;
    LCDCmd(pos);
  }
  LCDPrintStr(data);
}
// Send a data to the display
void LCDChar (uint8_t data)
{
  LCD_RS_ON;
  sendnibble(data >> 4);
  sendnibble(data & 0x0F);
}
void LCDPrintVal (unsigned int dado)
{
  if (dado >= 10000) LCDChar((dado / 10000) + 0x30);
  if (dado >= 1000) LCDChar(((dado % 10000) / 1000) + 0x30);
  if (dado >= 100) LCDChar((((dado % 10000) % 1000) / 100) + 0x30);
  if (dado >= 10) LCDChar(((((dado % 10000) % 1000) % 100) / 10) + 0x30);
  LCDChar(((((dado % 10000) % 1000) % 100) % 10) + 0x30);
}
void LCDPrintXYVal (unsigned char x, unsigned char y, unsigned int dado)
{
  unsigned char pos;
  if (y == 1)
  {
    pos = pos + 0x80;
    LCDCmd(pos);
  }
  else
  {
    pos = pos + 0x80;
    LCDCmd(pos);
    pos = pos + 0xc0;
    LCDCmd(pos);
  }
  LCDPrintVal(dado);
}
int main()
{
  InitLCD();
  while (1)
  {
    PORTB ^= P5;
    _delay_ms(1000);
    LCDPrintXYStr(4, 1, "Inatel");
  }
}