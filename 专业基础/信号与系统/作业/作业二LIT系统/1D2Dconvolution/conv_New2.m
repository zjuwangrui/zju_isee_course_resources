function Y = conv_New2(X,H)
%卷积公式法做卷积。
Y = zeros(1,length(X) + length(H)-1);
for n = 0:length(Y)-1 
    for k = max(n-length(H)+1,0):min(n,length(H)-1)
        Y(n+1) = Y(n+1) + X(k+1)*H(n-k+1);
    end
end