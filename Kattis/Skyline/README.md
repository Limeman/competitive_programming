# Skyline
Last time I visited Shanghai I admired its beautiful skyline. It also got me thinking, "Hmm, how much of the buildings do I actually see?" since the buildings wholly or partially cover each other when viewed from a distance. 

![](https://open.kattis.com/problems/skyline/file/statement/en/img-0001.png)

In this problem, we assume that all buildings have a trapezoid shape when viewed from a distance. That is, vertical walls but a roof that may slope. Given the coordinates of the buildings, calculate how large part of each building that is visible to you (i.e. not covered by other buildings).

## Input
The first line contains an integer, `N (2≤N≤100)`, the number of buildings in the city. Then follow `N` lines each describing a building. Each such line contains `4` integers, `x1`, `y1`, `x2`, and `y2` `(0≤x1<x2≤10000,0≤y1,y2≤10000)`. The buildings are given in distance order, the first building being the one closest to you, and so on.

## Output
For each building, output a line containing a floating point number between 0 and 1, the relative visible part of the building. The absolute error for each building must be within `10^−6`.

![**Figure 1:** Figure of the first sample case](https://open.kattis.com/problems/skyline/file/statement/en/img-0002.png)

## Sample Input 1
```
4
2 3 7 5
4 6 9 2
11 4 15 4
13 2 20 2
```
## Sample Output 1
```
1.00000000
0.38083333
1.00000000
0.71428571
```

## Sample Input 2
```
5
200 1200 400 700
1200 1400 1700 900
5000 300 7000 900
8200 400 8900 1300
0 1000 10000 800
```

## Sample Output 2
```
1.00000000
1.00000000
1.00000000
1.00000000
0.73667852
```