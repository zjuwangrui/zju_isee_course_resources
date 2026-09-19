## 编程题1
1. 请编程实现一维卷积功能，即自己编写MATLAB中的CONV函数，自己写出一个CONV_NEW函数。要求：
（1）课堂上采用列表法编写了CONV_NEW，请试着采用卷积公式法，编写CONV_NEW。
（2）请用例子检查你写的CONV_NEW是否与CONV的输出是否一致。
（3）请用两个10000维数组检测对比你写的CONV_NEW和CONV的时间复杂度。请查资料回答，为什么MATLAB自带的CONV更快一些？

## (1)
conv_New.m
```matlab
function C = conv_New(A,B)
% 第一问的解答
C = zeros(1,length(A) + length(B)-1);
for i = 1:length(A) 
    C = C + [zeros(1,i-1),A(i)*B, zeros(1,length(A)-i)];
end
```
## (2)
```matlab
%检验手写的卷积函数与matlab内置函数%
A = [1,2,3];
B = [4,5];
C1 = conv(A,B);
C2 = conv_New(A,B);
disp('matlab内置函数的卷积结果：');
disp(C1);
disp('手写函数的卷积结果：');
disp(C2);
% 结果如下：
% matlab内置函数的卷积结果：
%      4    13    22    15

% 手写函数的卷积结果：
%      4    13    22    15
%      两种卷积计算结果相同
```

## (3)
```matlab
A = rand(1,10000);
B = rand(1,10000);
tic
C1 = conv_New(A,B);
toc
tic
C2 = conv(A,B); 
toc
% MATLAB自带的CONV函数使用了快速傅里叶变换（FFT）算法来计算卷积，
%这种算法的时间复杂度为O(n log n)，
%而我写的CONV_NEW函数使用了直接计算卷积的方法，时间复杂度为O(n^2)。
%因此，MATLAB自带的CONV函数在处理大规模数据时更快一些。
%结果如下%
% >> question3
% 历时 0.116491 秒。
% 历时 0.006995 秒。
```

