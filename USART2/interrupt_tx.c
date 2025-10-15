void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart->Instance == USART2)
    {
      HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));
      // HAL_UART_Transmit_IT(&huart2, &rxData, sizeof(rxData)); // tx는 주로 폴링 방식을 채택함
	    HAL_UART_Transmit(&huart2, &rxData, sizeof(rxData), 100);
    }
}

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART2_UART_Init();

  HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));

  while (1)
    {
    }
}
