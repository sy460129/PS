# [Gold IV] Integral Pyramid - 17802 

[문제 링크](https://www.acmicpc.net/problem/17802) 

### 성능 요약

메모리: 2208 KB, 시간: 0 ms

### 분류

해 구성하기, 수학

### 제출 일자

2024년 12월 18일 10:29:57

### 문제 설명

<p>Pascal’s triangle is a marvel of the combinatorical world, and what’s more you can easily build one for yourself at home.</p>

<p>The lowest row has n numbers. The next row is staggered and has n − 1 numbers, where the ith is the sum of the ith and the i + 1th on the previous row.</p>

<p>You can choose any positive integers for the lowest row, but the single cell on the top row needs to be equal to a given x. Is this possible?</p>

### 입력 

 <ul>
	<li>The only line contains the number of rows, n (1 ≤ n ≤ 20), and the value needed at the top, x (1 ≤ x ≤ 10<sup>9</sup>).</li>
</ul>

### 출력 

 <p>If a pyramid can be constructed, output all of the numbers on each row, starting from the top. Every number must be greater than or equal to 1.</p>

<p>Otherwise, output impossible.</p>

