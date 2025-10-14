bool buttonGetPressed(uint8_t num)
{
  static uint32_t prevTime = 0;		// 최초 첫 번째 디바운스 안됨 !!

  bool ret = false;

  if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
    {
      uint32_t currTime = HAL_GetTick();
      if(currTime - prevTime > 50)
	{
	  if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
	    {
	      ret = true;
	    }
	  prevTime = currTime;
	}
    }
  return ret;
}
