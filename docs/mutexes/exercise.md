---
layout: post
title: '9.4 Exercise'
parent: 'Lesson 9: Mutexes'
---

2 preemptive threads

1 integer value, we want to in one thread add 1 and in the other subtract one.
If we don't use mutex then unpredictable results
If we do it should stay at same value
even though 2 different priorities threads (adn they are preemptive)