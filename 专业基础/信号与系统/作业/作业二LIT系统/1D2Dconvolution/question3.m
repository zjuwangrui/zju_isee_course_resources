%请用两个10000维数组检测对比你写的CONV_NEW和CONV的时间复杂度。请查资料回答，为什么MATLAB自带的CONV更快一些？
A = rand(1,10000);
B = rand(1,10000);
tic
C1 = conv_New(A,B);
toc
tic
C2 = conv(A,B); 
toc
% MATLAB自带的CONV函数使用了快速傅里叶变换（FFT）算法来计算卷积，这种算法的时间复杂度为O(n log n)，而我写的CONV_NEW函数使用了直接计算卷积的方法，时间复杂度为O(n^2)。因此，MATLAB自带的CONV函数在处理大规模数据时更快一些。
%结果如下%
% >> question3
% 历时 0.116491 秒。
% 历时 0.006995 秒。