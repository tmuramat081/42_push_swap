# 42_push_swap
*--Because Swap_push isn’t as natural*  
  
<img width="295" alt="スクリーンショット 2022-11-26 17 05 24" src="https://user-images.githubusercontent.com/91453112/204078986-2c3e34c4-926b-4e83-8d34-dd547b156904.png">

## What is this ?
A demonstration of sorting algorithm, using only 2 stacks and 11 instructions.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

## Installation

Please clone this repository as follows

```
git clone https://github.com/tmuramat081/42_push_swap.git  
cd 42_push_swap
make
./push_swap
```

And if you start with debug mode, as follows. 

```
make dev
./push_swap_dev
```

With debug mode, you can check the process of graph search.

## Thecnical issues
### Algorithm
- Insertion sort
- Longest Increasing Subsequence(LIS)
- Dynamic Programming(DP)
- Greedy Algorithm
- Graph Search(A* search)

### Data structure
- Deque  

https://github.com/tmuramat081/deque  
- Vector(i.e. Stack) 

https://github.com/tmuramat081/vector  
- Priority queue 

https://github.com/tmuramat081/priority_queue  
- Hashset 

https://github.com/tmuramat081/hashset  


## Thanks
Thanks for all the student, staff, sponser of 42 Tokyo!　　

https://42tokyo.jp/

## Authors
Taisei Muramatsu (tmuramat, 42 Tokyo)
