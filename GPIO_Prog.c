/*
 * GPIO_Prog.c
 *
 *  Created on: Jan 19, 2021
 *      Author:George Ayman
 *      Version: 01V
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "GPIO_Init.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"




void GPIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Mode)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		if (Copy_U8Pin <= 7 )
		{
			GPIOA->CRL &=~ ((0b1111)<< (Copy_U8Pin*4));
			GPIOA->CRL |=  ((Copy_U8Mode)<< (Copy_U8Pin*4));
		}
		else if (Copy_U8Pin <= 15 )
		{
			Copy_U8Pin=Copy_U8Pin-8;
			GPIOA->CRH &=~ ((0b1111)<< (Copy_U8Pin*4));
			GPIOA->CRH |=  ((Copy_U8Mode)<< (Copy_U8Pin*4));
		}
		break;
	case GPIO_PORTB :
		if (Copy_U8Pin <= 7 )
		{
			GPIOB->CRL &=~ ((0b1111)<< (Copy_U8Pin*4));
			GPIOB->CRL |=  ((Copy_U8Mode)<< (Copy_U8Pin*4));
		}
		else if (Copy_U8Pin <= 15 )
		{
			Copy_U8Pin=Copy_U8Pin-8;
			GPIOB->CRH &=~ ((0b1111)<< (Copy_U8Pin*4));
			GPIOB->CRH |=  ((Copy_U8Mode)<<(Copy_U8Pin*4));
		}
		break;
	case GPIO_PORTC :
		if (Copy_U8Pin <= 12 )
		{
			//GPIOC->CRL &=~ ((0b1111)<<(Copy_U8Pin*4));
			//GPIOC->CRL |=  ((Copy_U8Mode)<<(Copy_U8Pin*4));
		}
		else if (Copy_U8Pin <= 15 )
		{
			Copy_U8Pin=Copy_U8Pin-8;
			GPIOC->CRH &=~ ((0b1111)<<(Copy_U8Pin*4));
			GPIOC->CRH |=  ((Copy_U8Mode)<<(Copy_U8Pin*4));
		}
		break;
	default : break;
	}

}

void GPIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		if (Copy_U8Value == GPIO_HIGH )
		{
			SET_BIT(GPIOA->ODR,Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			CLR_BIT(GPIOA->ODR,Copy_U8Pin);
		}
		break;
	case GPIO_PORTB :
		if (Copy_U8Value == GPIO_HIGH )
		{
			SET_BIT(GPIOB->ODR,Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			CLR_BIT(GPIOB->ODR,Copy_U8Pin);
		}
		break;
	case GPIO_PORTC :
		if (Copy_U8Value == GPIO_HIGH )
		{
			SET_BIT(GPIOC->ODR,Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			CLR_BIT(GPIOC->ODR,Copy_U8Pin);
		}
		break;
	default : break;
	}
}

u8 GPIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin )
{
	u8 LOC_U8Result=0;
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		LOC_U8Result = GET_BIT(GPIOA->IDR,Copy_U8Pin);
		break;
	case GPIO_PORTB :
		LOC_U8Result = GET_BIT(GPIOB->IDR,Copy_U8Pin);
		break;
	case GPIO_PORTC :
		LOC_U8Result = GET_BIT(GPIOC->IDR,Copy_U8Pin);
		break;
	default : break;
	}
	return LOC_U8Result;
}



void GPIO_VidSetPortDirection( u8 Copy_U8Port , u8 Copy_U8Mode )
{
	switch( Copy_U8Port ){
	case GPIO_PORTA:
		GPIOA->CRL = 0x00000000 ;
		GPIOA->CRH = 0x00000000 ;
		for(u8 i=0 ; i<8;i++){
			GPIOA->CRL |= (Copy_U8Mode<< (i*4 ));
			GPIOA->CRH |= (Copy_U8Mode<< (i*4 ));
		}
		break;
	case GPIO_PORTB:
		GPIOB->CRL = 0x00000000 ;
		GPIOB->CRH = 0x00000000 ;
		for(u8 i=0 ; i<8;i++){
			GPIOB->CRL |= (Copy_U8Mode<< (i*4 ));
			GPIOB->CRH |= (Copy_U8Mode<< (i*4 ));
		}
		break;
	case GPIO_PORTC:
		GPIOC->CRL = 0x00000000 ;
		GPIOC->CRH = 0x00000000 ;
		for(u8 i=0 ; i<8;i++){
			GPIOC->CRL |= (Copy_U8Mode<< (i*4 ));
			GPIOC->CRH |= (Copy_U8Mode<< (i*4 ));
		}
		break;
	}

}

void GPIO_VidSetPortValue( u8 Copy_U8Port , u16 Copy_U8Value )
{
	switch( Copy_U8Port ){

	case GPIO_PORTA:
		GPIOA->ODR = Copy_U8Value ;
		break;
	case GPIO_PORTB:
		GPIOB->ODR = Copy_U8Value ;
		break;
	case GPIO_PORTC:
		GPIOC->ODR = Copy_U8Value ;
		break;
	}

}

u16 GPIO_u16GetPortValue( u8 Copy_U8Port )
{
	u16 LOC_u16Result = 0;
	switch( Copy_U8Port ){

	case GPIO_PORTA:

		LOC_u16Result =(u16) (GPIOA->IDR);
		break;
	case GPIO_PORTB:
		LOC_u16Result =(u16) (GPIOB->IDR);
		break;
	case GPIO_PORTC:
		LOC_u16Result =(u16) (GPIOC->IDR);
		break;
	}
	return LOC_u16Result ;
}

void GPIO_VidSetPinValueFaster(u8 Copy_U8Port, u8 Copy_U8Pin , u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		if (Copy_U8Value == GPIO_HIGH )
		{
			GPIOA->BSRR=(1<<Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			GPIOA->BRR=(1<<Copy_U8Pin);
		}
		break;
	case GPIO_PORTB :
		if (Copy_U8Value == GPIO_HIGH )
		{
			GPIOB->BSRR=(1<<Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			GPIOB->BRR=(1<<Copy_U8Pin);
		}
		break;
	case GPIO_PORTC :
		if (Copy_U8Value == GPIO_HIGH )
		{
			GPIOC->BSRR=(1<<Copy_U8Pin);
		}
		else if (Copy_U8Value == GPIO_LOW )
		{
			GPIOC->BRR=(1<<Copy_U8Pin);
		}
		break;
	default : break;
	}
}



void GPIO_VidSetPin(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		GPIOA->BSRR=(1<<Copy_U8Pin);
		break;
	case GPIO_PORTB :
		GPIOB->BSRR=(1<<Copy_U8Pin);
		break;
	case GPIO_PORTC :
		GPIOC->BSRR=(1<<Copy_U8Pin);
		break;
	default : break;
	}
}


void GPIO_VidClrPin(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		GPIOA->BRR=(1<<Copy_U8Pin);
		break;
	case GPIO_PORTB :
		GPIOB->BRR=(1<<Copy_U8Pin);
		break;
	case GPIO_PORTC :
		GPIOC->BRR=(1<<Copy_U8Pin);
		break;
	default : break;
	}
}

void GPIO_VidSetPortPins(u8 Copy_U8Port, u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		GPIOA->BSRR=Copy_U8Value;
		break;
	case GPIO_PORTB :
		GPIOB->BSRR=Copy_U8Value;
		break;
	case GPIO_PORTC :
		GPIOC->BSRR=Copy_U8Value;
		break;
	default : break;
	}
}



void GPIO_VidClrPortPins(u8 Copy_U8Port, u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
	case GPIO_PORTA :
		GPIOA->BRR=Copy_U8Value;
		break;
	case GPIO_PORTB :
		GPIOB->BRR=Copy_U8Value;
		break;
	case GPIO_PORTC :
		GPIOC->BRR=Copy_U8Value;
		break;
	default : break;
	}
}



void GPIO_VidSetPortPositionDirection( u8 Copy_U8Port , u8 Copy_U8Mode , u8 Copy_U8Position )
{
	switch( Copy_U8Port ){
	case GPIO_PORTA:
		if(Copy_U8Position == GPIO_POS_LOW) {
			GPIOA->CRL = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOA->CRL |= (Copy_U8Mode<< (i*4 ));
			}
		}
		else if(Copy_U8Position == GPIO_POS_HIGH){
			GPIOA->CRH = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOA->CRH |= (Copy_U8Mode<< (i*4 ));
			}
		}
		break;
	case GPIO_PORTB:
		if(Copy_U8Position == GPIO_POS_LOW) {
			GPIOB->CRL = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOB->CRL |= (Copy_U8Mode<< (i*4 ));
			}
		}
		else if(Copy_U8Position == GPIO_POS_HIGH){
			GPIOB->CRH = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOB->CRH |= (Copy_U8Mode<< (i*4 ));
			}
		}
		break;
	case GPIO_PORTC:
		if(Copy_U8Position == GPIO_POS_LOW) {
			GPIOC->CRL = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOC->CRL |= (Copy_U8Mode<< (i*4 ));
			}
		}
		else if(Copy_U8Position == GPIO_POS_HIGH){
			GPIOC->CRH = 0x00000000 ;
			for(u8 i=0 ; i<8;i++){
				GPIOC->CRH |= (Copy_U8Mode<< (i*4 ));
			}
		}
		break;
	}

}

void GPIO_VidSetPortPositionValue( u8 Copy_U8Port , u16 Copy_U8Value , u8 Copy_U8Position )
{
	switch( Copy_U8Port ){

	case GPIO_PORTA:
		if ( Copy_U8Position == GPIO_POS_LOW  ){
			GPIOA->ODR &= 0xFF00 ;
			GPIOA->ODR |= Copy_U8Value  ;
		}
		else if ( Copy_U8Position == GPIO_POS_HIGH ){
			GPIOA->ODR &=  0x00FF ;
			GPIOA->ODR |= Copy_U8Value ;
		}
		break;
	case GPIO_PORTB:
		if ( Copy_U8Position == GPIO_POS_LOW  ){
			GPIOB->ODR &= 0xFF00 ;
			GPIOB->ODR |= Copy_U8Value  ;
		}
		else if ( Copy_U8Position == GPIO_POS_HIGH ){
			GPIOB->ODR &=  0x00FF ;
			GPIOB->ODR |= Copy_U8Value ;
		}
		break;
		break;
	case GPIO_PORTC:
		if ( Copy_U8Position == GPIO_POS_LOW  ){
			GPIOC->ODR &= 0xFF00 ;
			GPIOC->ODR |= Copy_U8Value  ;
		}
		else if ( Copy_U8Position == GPIO_POS_HIGH ){
			GPIOC->ODR &=  0x00FF ;
			GPIOC->ODR |= Copy_U8Value ;
		}
		break;
	}

}
