t = linspace(0,1,1000);
x = t.^4;%produce a signal x(t) = t^4
p0 = t>=0 & t<=1;% p0 = 1, 0<=t<=1; p0 = 0, otherwise

p1 = 2*t-1;

p2 = 6*t.^2 - 6*t + 1;

p3=20*t.^3 - 30*t.^2 + 12*t - 1;

xb=0.2*p0 + 0.4*p1 + (2/7)*p2 + 0.1*p3;

plot(t,xb,'r',linewidth=1.5);
hold on;
plot(t,x,'b',linewidth=1.5);
yline(0, 'k-', 'LineWidth', 1);  % 黑色虚线，线宽1，标注x轴
legend('xb(t)','x(t)','Location','best');
xlabel('t');
ylabel('Amplitude');
title('Plot of x(t) and xb(t)');
saveas(gcf,'problem4_3.png');
hold off;