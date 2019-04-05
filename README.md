# LeetCode
刷题

### 摆动排序 II（参考网上代码）
- 题目：
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序 <br/>
- 难点：
用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现 <br/>
- 解题思路：
首先找出数组的中位数mid。然后将小于mid的数放在数组的偶数位置（0，2，4……），将大于mid的数放在数组的奇数位置（1，3，5……） <br/> 


### 有序矩阵中第K小的元素（自己做的，有待优化）
- 题目：
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。 <br/>
- 难点：
速度太慢，算法有待优化 <br/>
- 解题思路：
这个算法是自己做的（所以才慢233），很简单，从矩阵的左上角开始遍历，将当前坐标（i，j）的右方和下方的数放入priority_queue中。下一次执行时，从priority_queue中取出最小的数，然后重复执行，直至第k个数 <br/> 
