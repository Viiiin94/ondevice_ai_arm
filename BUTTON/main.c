int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  ledShift(0);

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
    {
      if(buttonGetPressed(0))
    	{
        // 야매로 만든 쉬프트 0 에서 7까지 이동
    	  currentLed = (currentLed == 7) ? 0 : (currentLed + 1);
    	  ledShift(currentLed);
    	  HAL_Delay(200);
    	}
      if(buttonGetPressed(1))
      {
        // 야매로 만든 쉬프트 7 에서 0까지 이동
    	  currentLed = (currentLed == 0 ) ? 7 : (currentLed - 1);
    	  ledShift(currentLed);
    	  HAL_Delay(200);
      }
      if(buttonGetPressed(2))
      {
        for(uint8_t i = 0; i < 8; i++)
          {
            ledToggle(i);
            // 딜레이가 없으면 꾹 누르고 있으면 미친듯이 켜졌다 꺼졌다 바뀜 적당한 딜레이를 줘서 방지
            // 그래도 꾹 누르면 딜레이마다 켜졌다 꺼졌다 바뀜
            HAL_Delay(300);
          }
      }

      /* USER CODE END WHILE */

      /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}
