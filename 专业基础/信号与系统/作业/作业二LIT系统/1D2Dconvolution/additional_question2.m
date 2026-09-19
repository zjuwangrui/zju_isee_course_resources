%附加题请用此函数，做以下两个卷积核与附件图片lenna.jpg的卷积，将卷积结果打印出来。并想一下为什么是这样。（请查阅imread和imwrite函数）%
clc;
clear;
A = ones(3) * (1/9);
B=-A;
B(2,2)=-8/9;
img=imread('lenna.jpg');

img = double (img);
imwrite(uint8(img),'lenna.jpg');
imwrite(uint8(img),'test.bmp');
C1=conv2_New(img,A);
C2=conv2_New(img,B);
disp('卷积核A与lenna.jpg的卷积结果：');
%disp(C1);
imwrite(uint8(C1),'lenna_A.jpg');
imwrite(uint8(C1),'test_A.bmp');
disp('卷积核B与lenna.jpg的卷积结果：');
%disp(C2);
imwrite(uint8(C2),'lenna_B.jpg');
imwrite(uint8(C2),'test_B.bmp');