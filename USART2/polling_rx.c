{
  // 현재 2번만 켜놔서 huart2번 주소값만 보냄, usart.c에 선언됨
  // 배열이라서 & 제외해도 됨 알아서 첫 번째 배열 주소값으로 보내짐
  // polling 방식은 순차적으로 코드가 실행되어서 아래 코드는 5번 핀은 0.5초가 아닌 1.5초가 되버림
  // blocking 당해서 그럼
  HAL_UART_Receive(&huart2, rxData, 4, 1000);

  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
  HAL_Delay(500);

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
}
