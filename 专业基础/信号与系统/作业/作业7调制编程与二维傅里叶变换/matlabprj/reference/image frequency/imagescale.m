function B=imagescale(A,lower,upper);
if lower>=upper
    error('The input of the scale bound is not correct.');
end;
if length(size(A))~=2
    error('The dimension of the input matrix is not equal to 2');
end;
[M,N]=size(A);
B=zeros(M,N);
MAX=0;
MIN=inf;
for i=1:M
    for j=1:N
        if A(i,j)>MAX
            MAX=A(i,j);
        elseif A(i,j)<MIN
            MIN=A(i,j);
        end;
    end;
end;
if MAX~=MIN
    for i=1:M
        for j=1:N
            B(i,j)=lower+(upper-lower)*(A(i,j)-MIN)/(MAX-MIN);
        end;
    end;
end;