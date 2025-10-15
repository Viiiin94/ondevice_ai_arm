#include "main.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN PV */

uint8_t rxData[10];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

// main 함수 밖에
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  // 함수 안에서 다시 선언한 이유
  // 인터럽트 함수가 실행되면 RXNE 가 0이 되어서 다시 1이 되도록 만들어야함
  HAL_UART_Receive_IT(&huart2, rxData, 4);
}

/* USER CODE END PFP */

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  // 시간이 없어짐
  HAL_UART_Receive_IT(&huart2, rxData, 4);

  /* USER CODE END 2 */

  /* Infinite loop */
  while (1)
    {

      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
      HAL_Delay(200);
    }
}
