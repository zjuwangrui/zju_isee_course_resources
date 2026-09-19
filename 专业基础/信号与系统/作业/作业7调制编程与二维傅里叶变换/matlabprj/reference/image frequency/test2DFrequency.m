A = imread('landscape.bmp');
A = double(A);
freqA = fft2(A);
freqA = fftshift(freqA);
magnitudeA = abs(freqA);
magnitudeA = imagescale(magnitudeA,0,255);
imwrite(magnitudeA, 'landscape.bmp');