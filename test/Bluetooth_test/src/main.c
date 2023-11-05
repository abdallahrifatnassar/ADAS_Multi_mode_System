#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MUSART_interface.h"

u32 G_u32Read = 0;

int main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(1, 0);
	MRCC_voidEnablePeripheral(4, 4);

	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN9,ALTERNATE_FUNCTION);
	MGPIO_voidSetPinOutput(MGPIOA,MGPIO_PIN9, PUSH_PULL);
	MGPIO_voidSetPinInPut(MGPIOA,MGPIO_PIN9, PULLUP_MODE);
	MGPIO_voidSetAlternative(MGPIOA,MGPIO_PIN9,7);

	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN10,ALTERNATE_FUNCTION);
	MGPIO_voidSetPinOutput(MGPIOA,MGPIO_PIN10, PUSH_PULL);
	MGPIO_voidSetPinInPut(MGPIOA,MGPIO_PIN10,PULLUP_MODE);
	MGPIO_voidSetAlternative(MGPIOA,MGPIO_PIN10,7);

	MUSART_voidInit(1667);
	MUSART_voidEnableRX();
	MUSART_voidEnableTX();
	MUSART_voidEnableUART();
	// Infinite loop
	while (1)
	{
		G_u32Read = MUSART_voidReadData();
		if(G_u32Read == 'F')
		{
			MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,OUTPUT_MODE);
			MGPIO_voidSetPinOutput(MGPIOA,MGPIO_PIN0, PUSH_PULL);
			MGPIO_voidSetPinInPut(MGPIOA,MGPIO_PIN0, PULLUP_MODE);
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0, HIGH);
		}
		else if (G_u32Read == 'B')
		{
			MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_MODE);
			MGPIO_voidSetPinOutput(MGPIOA,MGPIO_PIN1, PUSH_PULL);
			MGPIO_voidSetPinInPut(MGPIOA,MGPIO_PIN1, PULLUP_MODE);
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1, HIGH);
		}
	}
}
