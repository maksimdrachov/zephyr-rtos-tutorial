/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

void main(void)
{
	printk("main: basic sample started \n");

	while (1) {
		printk("main: basic sample loop \n");
		k_msleep(SLEEP_TIME_MS);
	}
}
