#include "led.h"

LED_CONTROL led[8]=
    {
	{GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOA, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOA, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOB, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET}
    };

void ledOn(uint8_t num)
{
  HAL_GPIO_WritePin(led[num].port, led[num].pinNumber, led[num].onState);
}
void ledOff(uint8_t num)
{
  HAL_GPIO_WritePin(led[num].port, led[num].pinNumber, led[num].offState);
}
void ledToggle(uint8_t num)
{
  HAL_GPIO_TogglePin(led[num].port, led[num].pinNumber);
}

void ledLeftShift(uint8_t num)
{
  for(uint8_t i = 0; i < num; i++)
    {
      ledOn(i);
      HAL_Delay(100);
    }
  HAL_Delay(500);
  for(uint8_t i = 0; i < num; i++)
    {
      ledOff(i);
      HAL_Delay(100);
    }
}
void ledRightShift(uint8_t num)
{
  uint8_t end = (num == 0) ? 0 : num;     // 0이면 0까지, 아니면 num까지
  for (int8_t i = 7; i >= (int8_t)end; i--) {
      ledOn((uint8_t)i);
      HAL_Delay(100);
  }
  HAL_Delay(500);
  for (int8_t i = 7; i >= (int8_t)end; i--) {
      ledOff((uint8_t)i);
      HAL_Delay(100);
  }
}
void ledFlower(uint8_t num)
{
  for(uint8_t i = 4; i < num; i++)
    {
      ledOn(i);
      ledOn(8 - i - 1);
      HAL_Delay(300);
    }
  for(uint8_t i = 4; i < num; i++)
    {
      ledOff(i);
      ledOff(8 - i - 1);
      HAL_Delay(300);
    }

}

void ledShift(uint8_t index)
{
  for(uint8_t i = 0; i < 8; i++)
    {
      HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, (i == index) ? led[i].onState : led[i].offState);
    }
}
