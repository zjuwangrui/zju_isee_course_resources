[x,fs] = audioread('qi.wav');
N = length(x);
t = 0:1/fs:(length(x)-1)/fs;

subplot(2,1,1);
plot(t,x);
title('Time Domain');
xlabel('Time (s)');
ylabel('Amplitude');

y = fft(x);
y = fftshift(y); 
y = y/fs;
f = -fs/2:fs/N:fs/2-fs/N;

subplot(2,1,2);
plot(f,abs(y));
title('Frequency Domain');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

saveas(gcf,'qi_time_domain.png');