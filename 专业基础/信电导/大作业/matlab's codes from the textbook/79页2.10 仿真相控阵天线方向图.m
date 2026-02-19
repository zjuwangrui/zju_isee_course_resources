%用MATLAB仿真相控阵天线方向图
clc;                            % 清除命令窗口的内容
clear;                          % 清除工作空间的所有变量；
%参数设置
f=10*10^9; 						% 频率为10GHz
c=3*10^8; 						% 真空中的光速
lmd=c/f; 						% 波长
k=2*pi/lmd; 					% 传播常数
rho=10000*lmd; 					% 以距离原点10000*lambda的球面上的场作为远场
syms phi                        % 定义一个符号变量phi。符号变量可以进行算数运算、积分等操作。
N=8;                            % 阵列中单元个数
d=lmd/2;                        % 阵元间距
%相位差
PhaseDifference=input('PhaseDifference(度, 可正负)='); 		% 输入天线单元间的相位差
PhaseDifference=PhaseDifference*pi/180;                     % 转化为弧度
Et=0;
for i=1:N
  x=(i-N/2-0.5)*d;                                                      % 第i个天线单元离原点距离
  r=sqrt(rho*rho+x*x-2*rho*x*cos(phi)); 					            % 第i个天线单元离P点距离
  Et=Et+j*k*120*pi*exp(-j*k*r)/4/pi/r*exp(j*(i-1)*PhaseDifference);     % N个天线单元的叠加电场
end
%phi取0到360度
t1=linspace(0,2*pi,721);                            % linspace是均分计算指令，用于产生0和2pi之间的721点行矢量。
Et_num=vpa(subs(Et,phi,t1));                        % subs(Et,phi,t1)表示将符号表达式Et中的符号变量phi替换为新的值t1；vpa用于控制精度
Et_num_abs=abs(Et_num); 			                % 电场幅度
%画图
Et_rel=Et_num_abs/max(Et_num_abs);                  % 归一化
figure(1);                                          % 图形窗口1                                               
polar(t1,Et_rel);                                   % 绘制极坐标图
title(['N=8, d={\lambda}/2, {\psi}=',num2str(PhaseDifference*180/pi),'{\circ}']);   % 设置图形标题。