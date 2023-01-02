
#include  <gpio.h >


#define   RCC_APB2ENR     (uint32_t*) 0x40021018
uint8_t EtatBouton;

GPIO_Struct GPIO_InitStruct ;
int main ()
{	
	//Activate GPIOs Clocks
 
	 *RCC_APB2ENR  |= 0x14 ; //Activation de l'horloge du PORT A/C

	//Configure GPIO Pins (Push Button)=PA0:Input Floating Mode
	
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
GPIO_Init(GPIOA,&GPIO_InitStructure) ;

	//Configure GPIO Pins (LED)=PC9/PC8:Output Push Pull 2 MHZ
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 |GPIO_Pin_8; 
GPIO_InitStructure.GPIO_MODE =  GPIO_Mode_Out_PP2MHz;
GPIO_Init(GPIOC,&GPIO_InitStructure) ;

	
 while (1)
  {		
		//Test Push Button
 		//Read Oush Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOA,GPIO_PIN_0);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	GPIO_SetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);
	else //Released, Led OFF
	GPIO_ResetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);				
}
	}
