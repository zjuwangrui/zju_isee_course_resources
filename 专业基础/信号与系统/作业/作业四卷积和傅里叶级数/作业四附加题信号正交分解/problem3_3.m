t = linspace(0,1,1000);
x = t.^3;%produce a signal x(t) = t^3
beta1 = t>=0 & t<=1;

beta2 = t-0.5;

beta3 = t.^2 - t + 1/6;

xb=0.25*beta1 + 0.9*beta2 + 1.5*beta3;
plot(t,xb,'r',linewidth=1.5);
hold on;
plot(t,x,'b',linewidth=1.5);
yline(0, 'k-', 'LineWidth', 1);  % 黑色虚线，线宽1，标注x轴
legend('xb(t)','x(t)','Location','best');
xlabel('t');
ylabel('Amplitude');
title('Plot of x(t) and xb(t)');
saveas(gcf,'problem3_3.png');
hold off;