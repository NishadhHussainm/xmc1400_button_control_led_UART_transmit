#include <DAVE.h>
#include <xmc_gpio.h>
//#define LED_PIN P1_0
//#define BUTTON_PIN P1_1

uint8_t ledMode = 0; //to store the current LED mode
uint8_t buttonState = 0; //to store the previous state of the pushbutton
uint8_t count = 0;
uint8_t count1 = 0;
uint8_t uart_data_arr[8]={0};


int main(void)
{
  DAVE_STATUS_t status;

  // Initialization of DAVE apps
   status = DAVE_Init();

  // Check if DAVE initialization is successful
  if (status != DAVE_STATUS_SUCCESS)
  {
    // Handle error
    while(1);
  }

  // Infinite loop
  while(1)
  {

    // Read the current state of the pushbutton
    buttonState = DIGITAL_IO_GetInput(&DIGITAL_IO_2);


    // Check if the pushbutton is pressed (active high)
    if (buttonState == 0)
    {
    //  changeLEDMode();

    	for (volatile uint32_t i = 0; i < 999999; i++);
    	 ledMode++;

    	  if (ledMode > 2)
    	  {
    	    ledMode = 0;


    	  }
    }
    	  // Update the LED based on the new mode
    	  switch (ledMode)
    	  {
    	    case 1:

    	    	ledMode = 1;
    	    	if ((DIGITAL_IO_GetInput(&DIGITAL_IO_0)) == 1)  // pushbutton 1 press
    	    	 {
    	    		uart_data_arr[1] = 1;
    	    	    DIGITAL_IO_ToggleOutput(&DIGITAL_IO_4);
    	    	    UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));

    	    	 }
    	    	if ((DIGITAL_IO_GetInput(&DIGITAL_IO_1)) == 1)  // pushbutton 2 press
    	    	{
    	    		uart_data_arr[1] = 2;
    	    		DIGITAL_IO_ToggleOutput(&DIGITAL_IO_5);
    	    		UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));

    	    	}
    	      break;
    	    case 2:
    	    	ledMode = 2;
    	      break;

    }

    }

  }


void blink_speed(void)


{
	if (ledMode == 2)  // to blink the led. speed determined by the timer 1
	{
	if (DIGITAL_IO_GetInput(&DIGITAL_IO_0) == 1) // pushbutton 1 press
	   {
		 count++;
	   }
		 if(count == 1 )
		 {
			 uart_data_arr[1]= 3;
			 DIGITAL_IO_ToggleOutput(&DIGITAL_IO_4);
			 UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));


		 }
		 else
		 {

			 DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4);
			 UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));


			 count=0;
		 }


	 if (DIGITAL_IO_GetInput(&DIGITAL_IO_1) == 1)  // pushbutton 2 press
		{
				 count1++;
			   }
				 if(count1 == 1 )
				 {
					 uart_data_arr[1]=5;
					 DIGITAL_IO_ToggleOutput(&DIGITAL_IO_5);
					 UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));


				 }
				 else
				 {

					 DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_5);
					 UART_Transmit(&UART_0, uart_data_arr, sizeof(uart_data_arr));


					 count1=0;
				 }

	}
	}


