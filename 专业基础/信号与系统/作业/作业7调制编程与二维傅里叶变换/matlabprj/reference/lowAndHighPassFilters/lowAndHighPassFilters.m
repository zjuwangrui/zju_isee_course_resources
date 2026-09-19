[x1,fs] = audioread("reference\lowAndHighPassFilters\segment2.wma");
x1 = x1(:,1);
figure(1);
plot(x1);
title('segment2 time domain');
xlabel('t');
ylabel('x');

figure(2);
y1 = fft(x1);
y1 = fftshift(y1);
N = length(x1);
derta_fs = fs/N;

N1 = floor(fs/(2*derta_fs));
w = [-N1*derta_fs:derta_fs:(N-N1-1)*derta_fs];
plot(w,abs(y1)/fs);
title('ԭʼ�����źŵ�Ƶ��');
grid on;

%***********************************
%ֱ�ӽضϸ�Ƶ��
originalY1 = y1;
fc1 = 4000;
frequency = [-fs/2:derta_fs:fs/2-derta_fs];
clipStart = ceil((-frequency(1)-fc1)/derta_fs);
clipEnd = floor((frequency(end)-fc1)/derta_fs);
y1([1:clipStart-1],:) = 0;
y1([end-clipEnd+1:end],:) = 0;

newx = abs(ifft(ifftshift(y1)));
audiowrite('segment2AfterIdeaLowPassFilter.wav', newx, fs);

y1 = originalY1;
y1([clipStart:end-clipEnd],:) = 0;
newx = abs(ifft(ifftshift(y1)));
audiowrite('segment2AfterIdeaHighPassFilter.wav',newx, fs);



%��ͨ�˲������ ��ֹƵ��4000 ���˥�� 20DB�� ���ɴ���0.1pi
fc1 = 4000;
N1 = 2*pi*0.9/(0.1*pi);
wc1 = 2*pi*fc1/fs;
if rem(N1,2)
    N1 = N1+1;
end
Window = boxcar(N1+1);
b1 = fir1(N1,wc1/pi,Window);
figure(3);
freqz(b1,1,512);
title('��ͨ�˲�����Ƶ����Ӧ');
x1_low = filter(b1,1,x1);
figure(4);
plot(x1_low);
title('�źž�����ͨ�˲���ʱ����ͼ');
figure(5);
plot([-fs/2:derta_fs:fs/2-derta_fs],abs(fftshift(fft(x1_low))));
title('�źž�����ͨ�˲���Ƶ����ͼ');
audiowrite('segment2AfterLowpassFilter.wav', x1_low, fs);

%��ͨ�˲�����ֹƵ��4000�����˥��40DB�� ���ɴ���0.1PI��
fc2 = fc1;
N2 = 2*pi*3.1/(0.1*pi);
wc2 = 2*pi*fc2/fs;
N2 = N2+mod(N2,2);
Window = hanning(N2+1);
b2 = fir1(N2,wc2/pi,'high',Window);
figure(6);
freqz(b2,1,512);

x1_high = filter(b2,1,x1);
title('��ͨ�˲�����Ƶ����Ӧ');
figure(7);
plot(x1_high);
title('�źž�����ͨ�˲���ʱ����ͼ');
figure(8);
plot([-fs/2:derta_fs:fs/2-derta_fs],abs(fftshift(fft(x1_high))));
title('�źž�����ͨ�˲���Ƶ����ͼ');
audiowrite('segment2AfterHighFilter.wav',x1_high, fs);