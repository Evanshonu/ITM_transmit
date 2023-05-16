/*
ITM (Instrumentation Trace Macrocell) is a powerful feature available in STM32 microcontrollers, 
designed to aid in debugging and performance analysis of embedded systems. 
It provides a means of capturing and tracing real-time program execution data, 
such as CPU cycles, instruction execution, and application-specific events.

The ITM module integrates with the ARM Cortex-M core found in STM32 microcontrollers,offering advanced debugging capabilities. 
 It allows developers to instrument their code by inserting trace points at specific locations, 
 which can be triggered to record relevant data during program execution. These trace points can be 
 placed at various levels, ranging from individual instructions to function calls or custom events.








*/
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint16_t character)
{

	//Enable TRCENA
	DEMCR |= 0x1000000;

	//enable stimulus port 0
	ITM_TRACE_EN |= 0x1;

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = character;
}
