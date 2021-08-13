/* main.c - Hello World demo */

/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7

/* delay between greetings (in ms) */
#define SLEEPTIME 500


K_THREAD_STACK_DEFINE(threadA_stack_area, STACKSIZE);
static struct k_thread threadA_data;

K_THREAD_STACK_DEFINE(threadB_stack_area, STACKSIZE);
static struct k_thread threadB_data;

void threadA(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	int i = 3; //amount of times to loop before suspend

	printk("thread_a: thread started \n");

	while (1)
	{
		printk("thread_a: thread loop \n");
		i -= 1;
		if (i == 0)
		{
			printk("thread_a: thread suspended \n");
			k_thread_suspend(&threadA_data);
			i = 3;
		}
		
	}

}

void threadB(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	printk("thread_b: thread started \n");

	while (1)
	{
		k_msleep(SLEEPTIME);
		printk("thread_b: resuming thread_a \n");
		k_thread_resume(&threadA_data);
	}

}

void main(void)
{
	k_thread_create(&threadA_data, threadA_stack_area,
			K_THREAD_STACK_SIZEOF(threadA_stack_area),
			threadA, NULL, NULL, NULL,
			PRIORITY, 0, K_FOREVER);
	k_thread_name_set(&threadA_data, "thread_a");

	k_thread_create(&threadB_data, threadB_stack_area,
			K_THREAD_STACK_SIZEOF(threadB_stack_area),
			threadB, NULL, NULL, NULL,
			PRIORITY+1, 0, K_FOREVER);				// priority of thread_b is lower than thread_b
	k_thread_name_set(&threadB_data, "thread_b");

	k_thread_start(&threadA_data);
	k_thread_start(&threadB_data);
}
