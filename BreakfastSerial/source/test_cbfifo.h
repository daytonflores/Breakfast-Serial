/**
 * \file    test_cbfifo.h
 * \author	Dayton Flores (dafl2542@colorado.edu)
 * \date	11/09/2022
 * \brief   Macros and function headers for testing circular/ring buffer
 */



#ifndef TEST_CBFIFO_H_
#define TEST_CBFIFO_H_



/**
 * \fn		bool test_cbfifo
 * \brief	Runs unit tests for happy cases + failure cases + boundary cases
 * 			for each cbfifo function
 * \param	cbfifo_t *cbfifo	The CBFIFO to test
 * \return	bool				True if all tests pass, false if any test fails
 */
bool test_cbfifo(cbfifo_t *cbfifo);



/**
 * \fn		bool test_cbfifo_enqueue
 * \brief	Tests cbfifo_enqueue with happy cases, fail cases, boundary cases
 * \param	cbfifo_t *cbfifo	The CBFIFO to test
 * \return	bool				True if all tests pass, false if any test fails
 */
bool test_cbfifo_enqueue(cbfifo_t *cbfifo);



/**
 * \fn		bool test_cbfifo_dequeue
 * \brief	Tests cbfifo_dequeue with happy cases, fail cases, boundary cases
 * \param	cbfifo_t *cbfifo	The CBFIFO to test
 * \return	bool				True if all tests pass, false if any test fails
 */
bool test_cbfifo_dequeue(cbfifo_t *cbfifo);



/**
 * \fn		bool test_cbfifo_length
 * \brief	Tests cbfifo_length with happy cases, fail cases, boundary cases
 * \param	cbfifo_t *cbfifo	The CBFIFO to test
 * \return	bool				True if all tests pass, false if any test fails
 */
bool test_cbfifo_length(cbfifo_t *cbfifo);



/**
 * \fn		bool test_cbfifo_capacity
 * \brief	Tests cbfifo_capacity with happy cases, fail cases, boundary cases
 * \param	cbfifo_t *cbfifo	The CBFIFO to test
 * \return	bool				True if all tests pass, false if any test fails
 */
bool test_cbfifo_capacity(cbfifo_t *cbfifo);



#endif /* TEST_CBFIFO_H_ */
