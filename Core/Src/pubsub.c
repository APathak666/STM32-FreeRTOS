/*
 * pubsub.c
 *
 *  Created on: Jul 13, 2022
 *      Author: aryap_dhruvaspace
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "pubsub.h"

QueueHandle_t globalQueue;
SemaphoreHandle_t gqMutex;
pubsubNode* pubList[MAX_PUBLISHERS];
TaskHandle_t subList[MAX_SUBSCRIBERS];

void initAll()
{
	globalQueue = xQueueCreate(16, sizeof(message)); //create global queue for all tasks to place messages on
	gqMutex = xSemaphoreCreateMutex(); //initialize global queue mutex

	for (int i = 0; i < MAX_PUBLISHERS; i++)
		pubList[i] = NULL;
}

void subTo()
{
	//pubsubNode* temp = pubsubList;
	//struct pubsubNode
}

void publish(struct node* mesgAddr)
{
//	while (xSemaphoreTake(gqMutex, 0xFFFFFFFF) != 1); //attempt to take mutex

	if (xSemaphoreTake(gqMutex, 0xFFFFFFFF) == 1)
		xQueueSend(globalQueue, mesgAddr, (TickType_t) 5);

	xSemaphoreGive(gqMutex);
}

void registerMsg()
{
	message RxBuff[16]; //array to receive messages

	while (1)
	{
		if (xSemaphoreTake(gqMutex, 0xFFFFFFFF) == 1) //take mutex before reading from global queue
			xQueueReceive(globalQueue, &RxBuff, (TickType_t) 5);

		xSemaphoreGive(gqMutex);
		vTaskDelay(100);

		broadcast(); //route messages to subscribers
	}
}

void broadcast()
{

}
