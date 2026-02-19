%基于MATLAB的语音信号频谱分析
clear;                                      % 清除工作空间中的所有变量
clc;                                        % 清除命令窗口的内容
[y,fs]=audioread('voicewithnoise.m4a');     % 将语音信号放于matlab中。y为信号值，fs为采样率
info=audioinfo('voicewithnoise.m4a') ;      % 得到声音的格式、位数、频率等
T=1/fs;                                     % T为采样时间间隔
N=length(y);                                % N为信号长度
t=(0:N-1)*T;                                % t为时间坐标
yleft=y(:,1);                               % 取左声道
sound(yleft,fs);                            % 发出声音
figure(1);                                  % 图形窗口1
yleft=yleft/max(abs(yleft));                % 归一化
plot(t,yleft);                              % 绘信号时域曲线
axis([0,t(N),-1,1]);                        % 设置坐标轴最大值和最小值
title('Time Domain Signal');                % 设置图形标题
xlabel('Time (s)');
ylabel('Amplitude');
grid on                                     % 显示轴网格线
figure(2);                                  % 图形窗口2
Yf=fft(yleft);                              % 对N点进行傅里叶变换得到频域
P2 = abs(Yf/N);                             % 计算谱密度
if mod(N,2)==1                              % 判定奇偶数
    Nm=(N+1)/2;                             % 奇数处理
else
    Nm=N/2+1;                               % 偶数处理
end
P1 = P2(1:Nm);                              % 计算单侧频谱
if mod(N,2)==1                              % 判定奇偶数
    P1(2:end) = 2*P1(2:end);		        % 奇数处理。双侧频谱是对称的，变单侧后，除端点外幅值加倍
else
    P1(2:end-1) = 2*P1(2:end-1);            % 偶数处理。双侧频谱是对称的，变单侧后，除两端外幅值加倍
end
f = fs*(0:Nm-1)/N;                          % f为频率坐标。fs为采样频率，N为采样点数
P1=P1/max(P1);                              % 归一化
plot(f,P1);                                 % 绘信号频域曲线
axis([0,max(f),0,1]);                       % 设置坐标轴最大值和最小值
title('Single-Sided Amplitude Spectrum');   % 设置图形标题
xlabel('frequency (Hz)');
ylabel('H(f)');
grid on                                     % 显示轴网格线