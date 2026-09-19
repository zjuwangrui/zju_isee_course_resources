%matlab无法生成严格数学意义上的周期信号，在这里时间选择在[-1.5T, 1.5T]范围内，信号在这个范围内满足周期性条件，其他时间点的值为0
T =4;
E=1;
fs = 10000; % 采样频率 
t = 0:1/fs:3*T; % 生成时间向量，长度三个周期
t = t-1.5*T; % 平移，使得信号在[-1.5T, 1.5T]范围内
x = zeros(size(t)); % 线性函数，斜率为2E/T
for i=1:length(t)
    if(t(i)>=-1.5*T & t(i)<-0.5*T)
        x(i) = 2*E/T * (t(i)+T);
    elseif(t(i)>=0.5*T & t(i)<1.5*T)
        x(i) = 2*E/T * (t(i)-T);
    elseif(t(i)>=-0.5*T & t(i)<0.5*T)
        x(i) = 2*E/T * t(i);
    else
        x(i) = 0; % 其他时间点的值为0
    end
end

N = 1000;
omega = 2*pi/T; % 基频
xn = zeros(size(t)); % 初始化傅里叶级数近似
for k=1:N
    ak = (-1)^(k+1)/k; % 计算傅里叶系数
    xn = xn + ak*sin(k*omega*t); % 累加傅里叶级数近似
end
xn = xn * 2*E/pi;%系数在此处相乘可以减少计算量
plot(t,x,'r',linewidth=1.5);
hold on;
plot(t,xn,'b-',linewidth=1.5);
yline(0, 'k-', 'LineWidth', 1);  % 黑色虚线，线宽1，标注x轴
legend('x(t)','xn(t)','Location','best');
xlabel('t');
ylabel('Amplitude');
title('Plot of x(t) and xn(t)');
saveas(gcf,'problem6_3_when_N1000.png');
hold off;