bool buttonGetPressed(uint8_t num)
{
  bool ret = false;

  if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
    {
      HAL_Delay(20);
      if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
	{
	  ret = true;
	}
    }
  return ret;
}
