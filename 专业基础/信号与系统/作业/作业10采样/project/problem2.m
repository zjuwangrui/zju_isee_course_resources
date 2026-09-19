% problem2.m
% 根据 solution.md 中的第二题要求编写

% 清理工作区和命令窗口
clear; clc; close all;

% --- 基本参数定义 ---
% 提示用户输入日期
date_str = input('请输入日期 (例如 20260528): ', 's');

% 定义符号变量和信号
syms t;
T = 0.1; % 采样周期
xt = sin(4*pi*t); % 原始信号
yt = sin(4*pi*(t - T/2)); % 延时信号

% 定义绘图和采样的时间范围
t_range = [-1, 1];
n_min = ceil(t_range(1)/T);
n_max = floor(t_range(2)/T);
n = n_min:n_max;
t_samples = n * T;

% --- (1) 绘制 x(t) 和采样信号 x[n] ---
figure(1);
hold on;
% 绘制连续信号
fplot(xt, t_range, 'b');
% 计算并绘制采样点
xn = subs(xt, t, t_samples);
stem(t_samples, xn, 'r', 'filled');
hold off;

% 设置图像属性
title('原始信号 x(t) 及其采样 x[n]');
xlabel('时间 (t)');
ylabel('幅值');
legend('连续信号 x(t)', '采样点 x[n]', 'Location', 'best');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q21_' date_str '.png']));


% --- (2) 绘制 y(t) 和采样信号 y[n] ---
figure(2);
hold on;
% 绘制连续信号
fplot(yt, t_range, 'b');
% 计算并绘制采样点
yn = subs(yt, t, t_samples);
stem(t_samples, yn, 'r', 'filled');
hold off;

% 设置图像属性
title('延时信号 y(t) 及其采样 y[n]');
xlabel('时间 (t)');
ylabel('幅值');
legend('连续信号 y(t)', '采样点 y[n]', 'Location', 'best');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q22_' date_str '.png']));

% --- (3) 计算延时采样值 yr[n] ---
% 根据公式 hd[n] = sinc(n - fs*t0)
fs = 1/T;
t0 = T/2;
d = fs * t0; % 延迟对应的样本数

% 定义 h_d[n] 的计算范围，为了卷积结果准确，范围应足够大
n_hd = -20:20; 
hd = sinc(n_hd - d);

% 计算卷积 yr[n] = x[n] * hd[n]
% 注意：MATLAB的conv函数会使结果序列长度变长
yr_full = conv(double(xn), hd, 'full');

% 为了与 yn 对齐，我们需要截取卷积结果中与 xn 对应的部分
% yr_full(k) 对应时间索引 n_min + n_hd(1) + k - 1
% 要得到 n_min 对应的位置：k = 1 - n_hd(1)
start_index = 1 - n_hd(1);  % = 1 - (-20) = 21
end_index = start_index + length(xn) - 1;
yr = yr_full(start_index:end_index);

% 绘制 yr[n] 和 yn 的对比图
figure(3);
hold on;
stem(t_samples, double(yn), 'b', 'filled', 'DisplayName', '直接采样 y[n]');
stem(t_samples, yr, 'Color', 'r', 'Marker', 'o', 'DisplayName', '卷积计算 y_r[n]');
hold off;

title('直接采样与卷积计算的延时信号对比');
xlabel('时间 (t)');
ylabel('幅值');
legend('Location', 'best');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q23_' date_str '.png']));

% --- (4) 从 yr[n] 恢复 yr(t) 并比较 ---
% 使用带限内插公式重建 yr(t)
% 截止频率 fc 应为 fs/2 = 1/(2*T)
fc = 1/(2*T); 
yrt = 0;
for i = 1:length(n)
    yrt = yrt + yr(i) * sinc(2*fc*(t - n(i)*T));
end

% 绘制 yr(t) 和 y(t) 的对比图
figure(4);
hold on;
fplot(yrt, t_range, 'r--', 'LineWidth', 1.5); % 绘制重建信号 yr(t)
fplot(yt, t_range, 'b'); % 绘制原始延时信号 y(t)
hold off;

% 设置图像属性
title('重建信号 y_r(t) 与原始延时信号 y(t) 对比');
xlabel('时间 (t)');
ylabel('幅值');
legend('重建信号 y_r(t)', '原始延时信号 y(t)', 'Location', 'best');
grid on;

% 保存图像
saveas(gcf, fullfile('output', ['q24_' date_str '.png']));
disp('problem2.m 已成功执行，图像已保存到 output 文件夹中。');
