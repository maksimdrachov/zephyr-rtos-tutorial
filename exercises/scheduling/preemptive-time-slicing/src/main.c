/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024

#define PRIORITY_THREAD_1	(3)
#define PRIORITY_THREAD_2	(2)
#define PRIORITY_THREAD_3 	(1)


K_THREAD_STACK_DEFINE(thread_1_stack_area, STACKSIZE);
static struct k_thread thread_1_data;

K_THREAD_STACK_DEFINE(thread_2_stack_area, STACKSIZE);
static struct k_thread thread_2_data;

K_THREAD_STACK_DEFINE(thread_3_stack_area, STACKSIZE);
static struct k_thread thread_3_data;

void thread_1(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	int i = 0;

	printk("thread_1: thread started \n");
	k_thread_start(&thread_2_data);

	while (1)
	{
		i++;
		printk("thread_1: thread loop %d\n", i);
		if (i == 3)
		{
			printk("thread_1: thread abort\n");
			k_thread_abort(&thread_1_data);
		}
	}

}

void thread_2(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	int i = 0;

	printk("thread_2: thread started \n");
	k_thread_start(&thread_3_data);

	while (1)
	{
		i++;
		printk("thread_2: thread loop %d\n", i);
		if (i == 3)
		{
			printk("thread_2: thread abort\n");
			k_thread_abort(&thread_2_data);
		}
	}

}

void thread_3(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	int i = 0;

	printk("thread_3: thread started \n");

	while (1)
	{
		i++;
		printk("thread_3: thread loop %d\n", i);
		if (i == 3)
		{
			printk("thread_3: thread abort\n");
			k_thread_abort(&thread_3_data);
		}
	}

}

void main(void)
{
	k_thread_create(&thread_1_data, thread_1_stack_area,
			K_THREAD_STACK_SIZEOF(thread_1_stack_area),
			thread_1, NULL, NULL, NULL,
			PRIORITY_THREAD_1, 0, K_FOREVER);
	k_thread_name_set(&thread_1_data, "thread_1");

	k_thread_create(&thread_2_data, thread_2_stack_area,
			K_THREAD_STACK_SIZEOF(thread_2_stack_area),
			thread_2, NULL, NULL, NULL,
			PRIORITY_THREAD_2, 0, K_FOREVER);
	k_thread_name_set(&thread_2_data, "thread_2");

	k_thread_create(&thread_3_data, thread_3_stack_area,
			K_THREAD_STACK_SIZEOF(thread_3_stack_area),
			thread_3, NULL, NULL, NULL,
			PRIORITY_THREAD_3, 0, K_FOREVER);
	k_thread_name_set(&thread_3_data, "thread_3");

	k_thread_start(&thread_1_data);
}
