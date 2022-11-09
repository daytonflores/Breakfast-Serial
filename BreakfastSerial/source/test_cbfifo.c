/**
 * \file    test_cbfifo.c
 * \author	Dayton Flores (dafl2542@colorado.edu)
 * \date	11/09/2022
 * \brief   Macros and function defintions for testing circular/ring buffer
 */



#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "cbfifo.h"
#include "test_cbfifo.h"



bool test_cbfifo(cbfifo_t *cbfifo){

	return(	test_cbfifo_enqueue(cbfifo) &
			test_cbfifo_dequeue(cbfifo) &
			test_cbfifo_length(cbfifo) &
			test_cbfifo_capacity(cbfifo));
}



bool test_cbfifo_enqueue(cbfifo_t *cbfifo){

	/**
	 * Happy Cases
	 */




	/**
	 * Fail Cases
	 */




	/**
	 * Boundary Cases
	 */




	return true;
}



bool test_cbfifo_dequeue(cbfifo_t *cbfifo){

	/**
	 * Happy Cases
	 */




	/**
	 * Fail Cases
	 */




	/**
	 * Boundary Cases
	 */




	return true;
}



bool test_cbfifo_length(cbfifo_t *cbfifo){

	/**
	 * Happy Cases
	 */




	/**
	 * Fail Cases
	 */




	/**
	 * Boundary Cases
	 */




	return true;
}



bool test_cbfifo_capacity(cbfifo_t *cbfifo){

	;
	/**
	 * Happy Cases
	 */




	/**
	 * Fail Cases
	 */




	/**
	 * Boundary Cases
	 */




	return true;
}
