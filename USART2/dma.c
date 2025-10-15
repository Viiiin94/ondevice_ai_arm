/* USER CODE BEGIN PFP */
// main 함수 밖에
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  HAL_UART_Receive_DMA(&huart2, rxData, 4);
}
/* USER CODE END PFP */

int main(void)
{
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  
  /* USER CODE BEGIN 2 */

  HAL_UART_Receive_DMA(&huart2, rxData, 4);

  /* USER CODE END 2 */
  
  /* USER CODE BEGIN WHILE */
  while (1)
    {
      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
      HAL_Delay(200);
    }
}
