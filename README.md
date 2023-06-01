# -- push_swap --

## Usage (mac only) -- 👈

```bash
git clone https://github.com/swautelet/push_swap.git && cd push_swap && make && ./push_swap "0" "5" "2" "1" "4" 
```

<img src="https://github.com/swautelet/push_swap/media/perf100.gif" width="400" height="250"> <img src="https://github.com/swautelet/push_swap/media/perf500.gif" width="400" height="250">

## Topics -- 🗝

1. Sorting algorithms

2. Complexity

3. C

  

## Challenge -- 💡

  

With only 2 stacks of integer values *(a and b)* and a limited set of instructions *(see below)*, try to sort stack a with the lowest possible number of action.

  
  

## Objectives -- ✅

  

Sorting values is simple. Sort them the fastest way possible is less simple. The goal is :

- **8** instructions on average for a stack of **5** integers

- **700** instructions on average for a stack of **100** integers

- **5000** instructions on average for a stack of **500** integers


## Rules -- 🚨

If you are interested in the specifics of the project here is how it is supposed to work :

-	You have 2 stacks named a and b.

-	At the beginning :

	The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.

	The stack b is empty.

-	The goal is to sort in ascending order of numbers into stack a. To do so you have the following operations at your disposal :

	sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

	sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

	ss : sa and sb at the same time.

	pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

	pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

	ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

	rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

	rr : ra and rb at the same time.

	rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

	rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

	rrr : rra and rrb at the same time.



👍 Thanks to [o-reo](https://github.com/o-reo "o-reo GitHub") for his [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer "push_swap visualizer") ! 👍
