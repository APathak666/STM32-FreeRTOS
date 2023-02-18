/*
 * pubsub.h
 *
 *  Created on: Jul 13, 2022
 *      Author: aryap_dhruvaspace
 */

#ifndef INC_PUBSUB_H_
#define INC_PUBSUB_H_

#include <stddef.h >
//message structure
typedef struct
{
	TaskHandle_t pubHandle;
	char payload[32];
} message;

typedef struct
{
	TaskHandle_t nodeHandle;
	struct pubsubNode* next;
} pubsubNode;

#define MAX_PUBLISHERS 10
#define MAX_SUBSCRIBERS 10
//publisher APIs
//void regPub();
void sendMesg();

//subscriber APIs
//void regSub();
void subTo(uint8_t pubID);
void unsubFrom(uint8_t pubID);
void readMsg();
void readMsgFrom(uint8_t pubID);

//broker functionalities
//void addSub();
//void removeSub();
void registerMsg();
void broadcast();

#endif /* INC_PUBSUB_H_ */
