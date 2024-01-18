# [Gold V] Sum of Remainders - 27856 

[문제 링크](https://www.acmicpc.net/problem/27856) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2024년 1월 18일 10:55:37

### 문제 설명

<p>Given a multiset (elements may be duplicates), K of integers ≥ 2, the sum of remainders function associated with K, SK, defined on non-negative integers, n, is given by:</p>

<p style="text-align: center;">S<sub>K</sub>(n) = ∑ (k in K | n mod k)</p>

<p>For instance, if K = {2, 5, 5, 11},</p>

<p style="text-align: center;">S<sub>K</sub>(23) = 23 mod 2 + 23 mod 5 + 23 mod 5 + 23 mod 11 = 1 + 3 + 3 + 1 = 8.</p>

<p>Note that S<sub>K</sub>(0) = 0 for any K.</p>

<p>For this problem you will write a program which takes as input the values of S<sub>K</sub>(n) for n from 1 to N for some unknown multiset K. The program will output the number of integers in K followed by the integers in K in non-decreasing order.</p>

### 입력 

 <p>Input consists of multiple lines. The first line contains a single decimal integer N, (1 ≤ N ≤ 100), which is the number of values of S<sub>K</sub>(n), (1 ≤ n ≤ N), that follow. The following lines contain the N values as space separated decimal integers, 10 values per line (except perhaps for the last line).</p>

### 출력 

 <p>There is one line of output containing a space separated sequence of decimal integers. The first value is the number, m, of integers in the multiset K. This is followed by the m integers of the multiset K in non-decreasing order. Note: if a value is a member multiple times, it should appear in the list that many times.</p>

