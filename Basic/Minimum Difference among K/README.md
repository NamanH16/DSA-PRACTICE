<h2><a href="https://practice.geeksforgeeks.org/problems/minimum-difference-among-k5805/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article">Minimum Difference among K</a></h2><h3>Difficulty Level : Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of&nbsp;<strong>n</strong>&nbsp;integers and a positive number&nbsp;<strong>k</strong>. We are allowed to take any k integers from the given array. The task is to find the minimum possible value of the difference between maximum and minimum of <strong>k</strong> numbers.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=7
K=3
arr[] = {10, 100, 300, 200, 1000, 20, 30}
<strong>Output:
</strong>20
<strong>Explanation</strong>:
20 is the minimum possible difference 
between any maximum and minimum of any 
k numbers.Given k = 3, we get the result 
20 by selecting integers {10, 20, 30}.
max(10, 20, 30) - min(10, 20, 30) = 30 - 10 
= 20.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N=2
K=2
arr[] = { 1,1 }
<strong>Output:
</strong>0
<strong>Explanation</strong>:
max({1,1}) - min({1,1}) = 1 - 1 = 0
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>minDiff</strong>() that takes <strong>array arr,&nbsp;integer N</strong>&nbsp;<strong>and integer K&nbsp;</strong>as parameters and return the value of friendliness for the given array.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NLogN).<br>
<strong>Expected Auxiliary Space:</strong> O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 10<sup>5</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;