% 提示用户输入日期
date_str = input('请输入日期 (例如 20260528): ', 's');


% 定义符号变量和信号
syms t;
xt = 0.3*sin(2*pi*t) + 0.4*cos(2.5*pi*t + pi/4) + 0.3*cos(pi*t + pi/3);

% (2) 绘制原始信号 xt 在 [-4, 4] 的波形
figure(1);
fplot(xt, [-4, 4]);
title('原始信号 x(t)');
xlabel('时间 (t)');
ylabel('幅值');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q12_' date_str '.png']));

% (3) 和 (4) 采样和重建
% 设置采样周期 T
T = 0.25; % 

% 采样
n_min = ceil(-4/T);
n_max = floor(4/T);
n = n_min:n_max;
t_samples = n * T;
xn = subs(xt, t, t_samples);

% 带限内插重建
fc = 2;%滤波截止频率
% 重建信号 xr(t)
xr = 0;
for i = 1:length(n)
    xr = xr + xn(i) * sinc(2*fc*(t - n(i)*T));
end
xr = xr * (2*fc*T);
% 绘制重建信号和采样点
figure(2);
hold on;
fplot(xr, [-4, 4], 'b'); % 绘制重建信号
stem(t_samples, xn, 'r', 'filled'); % 绘制采样点
hold off;

title(['使用 T = ' num2str(T) ' 重建的信号']);
xlabel('时间 (t)');
ylabel('幅值');
legend('重建信号 x_r(t)', '采样点 x(nT)', 'Location', 'best');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q13_' date_str '.png']));
