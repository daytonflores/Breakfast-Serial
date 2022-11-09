/**
 * \file    cbfifo.h
 * \author	Dayton Flores (dafl2542@colorado.edu)
 * \date	11/09/2022
 * \brief   Macros and function headers for circular/ring buffer
 */



#ifndef CBFIFO_H_
#define CBFIFO_H_

/**
 * \def		CBFIFO_SIZE
 * \brief	The size of the transmit + receive CBFIFOs in bytes
 */
#define CBFIFO_SIZE\
	(256)



/**
 * \typedef	cbfifo_t
 * \brief	Allows struct cbfifo_s to be instantiated as cbfifo_t
 */
typedef struct cbfifo_s cbfifo_t;



/**
 * \struct	cbfifo_s
 * \brief	Circular buffer of fixed size
 * \var		uint8_t buf[CBFIFO_SIZE]	Buffer of fixed size. It is CB_SIZE number
 * 										of bytes large
 * \var		size_t head					Current head. This increments just after
 * 										elements are added to buf
 * \var		size_t tail					Current tail. This increments just after
 * 										elements are removed from buf
 * \var		size_t capacity				The amount of bytes the buffer can store
 * 										at a time
 * \var		size_t length				The amount of bytes currently stored in
 * 										the buffer
 * \var		bool is_full				Flag to keep track of status of the buf
 */
struct cbfifo_s {
	uint8_t buf[CBFIFO_SIZE];
	size_t head;
	size_t tail;
	size_t capacity;
	size_t length;
	bool is_full;
};



/**
 * \fn		size_t cbfifo_enqueue
 * \brief	Enqueues data onto a CBFIFO, up to the limit of the available
 * 			CBFIFO capacity
 * \param	cbfifo_t *cbfifo	The CBFIFO to enqueue onto
 * \param	void *buf			Pointer to the data
 * \param	size_t nbyte		Max number of bytes to enqueue
 * \return	size_t				The number of bytes actually enqueued, which could
 * 								be 0. In case of an error, returns (size_t)(-1)
 */
size_t cbfifo_enqueue(cbfifo_t *cbfifo, void *buf, size_t nbyte);



/**
 * \fn		size_t cbfifo_dequeue
 * \brief	Attempts to remove ("dequeue") up to nbyte bytes of data from a
 * 			CBFIFO. Removed data will be copied into the buffer pointed to by buf
 * \param	cbfifo_t *cbfifo	The CBFIFO to dequeue from
 * \param	void *buf			Destination for the dequeued data
 * \param	size_t nbyte		Bytes of data requested
 * \return	size_t				The number of bytes actually copied, which will be
 * 								between 0 and nbyte
 * \detail	To further explain the behavior: If the CBFIFO's current length is
 * 			24 bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 * 			return the 24 bytes it has, and the new FIFO length will be 0. If
 * 			the CBFIFO is empty (current length is 0 bytes), a request to dequeue
 * 			any number of bytes will result in a return of 0 from cbfifo_dequeue.
 */
size_t cbfifo_dequeue(cbfifo_t *cbfifo, void *buf, size_t nbyte);



/**
 * \fn		size_t cbfifo_length
 * \brief	Returns the number of bytes currently on the CBFIFO
 * \param	cbfifo_t *cbfifo	The CBFIFO to return length of
 * \return	size_t				Number of bytes currently available to be
 * 								dequeued from the CBFIFO
 */
size_t cbfifo_length(cbfifo_t *cbfifo);



/**
 * \fn		size_t cbfifo_capacity
 * \brief	Returns the CBFIFO's capacity
 * \param	cbfifo_t *cbfifo	The CBFIFO to return capacity of
 * \return	size_t				The capacity, in bytes, for the CBFIFO
 */
size_t cbfifo_capacity(cbfifo_t *cbfifo);



#endif /* CBFIFO_H_ */
