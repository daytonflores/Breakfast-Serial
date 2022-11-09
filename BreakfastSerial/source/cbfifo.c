/**
 * \file    cbfifo.c
 * \author	Dayton Flores (dafl2542@colorado.edu)
 * \date	11/09/2022
 * \brief   Macros and function definitions for circular/ring buffer
 */



#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "cbfifo.h"



/**
 * \def		EXIT_FAILURE_N
 * \brief	Return code for failures in size_t functions
 */
#define EXIT_FAILURE_N\
	((size_t)(-1))



size_t cbfifo_enqueue(cbfifo_t *cbfifo, void* buf, size_t nbyte) {

	size_t bytes_enqueued = 0;
	size_t i;

	// Ensure buf is a valid buffer to read from
	if (buf == NULL) {
		return EXIT_FAILURE_N;
	}

	// Return 0 immediately if trying to enqueue into a full FIFO
	if (cbfifo->is_full == true) {
		return bytes_enqueued;
	}

	// Return 0 immediately if trying to enqueue zero bytes into FIFO
	if (nbyte == 0) {
		return bytes_enqueued;
	}

	// Begin enqueueing byte-by-byte
	for (i = 0; i < nbyte; i++) {

		// Case of FIFO not being full
		if (cbfifo->is_full == false) {

			// Enqueue byte from buffer into FIFO
			cbfifo->buf[cbfifo->head] = *((char*)(buf) + i);

			// Increment FIFO head for circular buffer without modulus operation.
			// This assumes FIFO capacity is a power of 2
			cbfifo->head = (cbfifo->head + 1) & (cbfifo->capacity - 1);

			// Check if FIFO is full after enqueueing byte
			if (cbfifo->head == cbfifo->tail) {
				cbfifo->is_full = true;
			}

			// Successfully enqueued byte
			(cbfifo->length)++;
			bytes_enqueued++;
		}

		// Case of FIFO being full
		else {

			// Do not enqueue anymore bytes into FIFO
			break;
		}
	}

	return (bytes_enqueued);
}



size_t cbfifo_dequeue(cbfifo_t *cbfifo, void* buf, size_t nbyte) {

	size_t bytes_dequeued = 0;
	size_t i;

	// Ensure buf is a valid buffer to write to
	if (buf == NULL) {
		return EXIT_FAILURE_N;
	}

	// Return 0 immediately if trying to dequeue from empty FIFO
	if (cbfifo->length == 0) {
		return bytes_dequeued;
	}

	// Return 0 immediately if trying to dequeue zero bytes into FIFO
	if (nbyte == 0) {
		return bytes_dequeued;
	}

	// Begin dequeueing byte-by-byte
	for (i = 0; i < nbyte; i++) {

		// Case of FIFO having bytes available to dequeue
		if (cbfifo->length > 0) {

			// Dequeue byte from FIFO into buffer
			*((char*)(buf) + i) = cbfifo->buf[cbfifo->tail];

			// Increment FIFO tail for circular buffer without modulus operation.
			// This assumes FIFO capacity is a power of 2
			cbfifo->tail = (cbfifo->tail + 1) & (cbfifo->capacity - 1);

			// Check if byte was just dequeued from a full FIFO
			if (cbfifo->is_full == true) {
				cbfifo->is_full = false;
			}

			// Successfully dequeued byte from FIFO
			(cbfifo->length)--;
			bytes_dequeued++;
		}

		// Case of FIFO being empty
		else {

			// Do not dequeue anymore bytes from FIFO
			break;
		}
	}

	return (bytes_dequeued);
}



size_t cbfifo_length(cbfifo_t *cbfifo) {

	return cbfifo->length;
}



size_t cbfifo_capacity(cbfifo_t *cbfifo) {

	return cbfifo->capacity;
}
