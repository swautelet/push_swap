# -- push_swap --

## Usage (mac only) -- 👈

```bash
git clone https://github.com/swautelet/push_swap.git && cd push_swap && make && ./push_swap "0" "5" "2" "1" "4" 
```
you can then test with any suit of number little or big other than the first given.

## Topics -- 🗝

1. Sorting algorithms

2. Complexity

3. C

  

## Challenge -- 💡

  

With only 2 stacks of integer values *(a and b)* and a limited set of instructions *(see below)*, try to sort stack a with the lowest possible number of action.

  
  

## Objectives -- ✅

  

Sorting values is simple. Sort them the fastest way possible is less simple. The goal is :

- **8** instructions on average for a stack of **5** integers

done with an optimized brutforce to find the best solution

- **700** instructions on average for a stack of **100** integers

done with a personalized algorithm inspired by quicksort

- **5000** instructions on average for a stack of **500** integers

done with a radixsort algorithm


## Rules -- 🚨

If you are interested in the specifics of the project here is how it is supposed to work :

-	You have 2 stacks named a and b.

-	At the beginning :

	The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.

	The stack b is empty.

-	The goal is to sort in ascending order of numbers into stack a. To do so you have the following operations at your disposal :

| Operation | Description |
| ------------ | ------------ |
| `sa` | swap A - swap the first 2 elements at the top of stack A |
| `sb` | swap B - swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push A - take the first element at the top of b and put it at the top of A |
| `pb` | push B - take the first element at the top of a and put it at the top of B |
| `ra` | rotate A - shift up all elements of stack A by 1. The first element becomes the last one |
| `rb` | rotate B - shift up all elements of stack B by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one |
| `rrb` | reverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |

