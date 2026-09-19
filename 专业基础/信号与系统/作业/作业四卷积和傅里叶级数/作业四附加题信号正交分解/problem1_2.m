t = linspace(0,1,1000);
x = sin(pi*t);

phi1 = t>=0 & t<=1;

phi2 =(t>=0 & t<=0.5) + (-1)*(t>0.5 & t<=1);

phi3 = (t>=0 & t<=0.25) + (-1)*(t>0.25 & t<=0.5);

phi4 = (t>=0.5 & t<=0.75) + (-1)*(t>0.75 & t<=1);

x_p = 2\pi * phi1 + 0 * phi2 + (2-2*sqrt(2))/pi * phi3 + (-2+2*sqrt(2))/pi * phi4;
plot(t, x, 'r-', 'LineWidth', 1.5); hold on;
plot(t, x_p, 'b-', 'LineWidth', 1.5); hold off;

legend('x','x_p', 'Location', 'best');
xlabel('Time (s)');
ylabel('Amplitude');
title('Plot of x(t) and its  series approximation x_p(t)');
grid on;
saveas(gcf, 'problem1_2_plot.png');