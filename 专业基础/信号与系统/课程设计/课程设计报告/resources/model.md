# table
普通表格
\begin{table}[H]
    \centering
    \begin{tabular}{|c|c|c|c|c|c|c|}
    \hline
    $I_C$ ($\mu A$) & $V_{CE}$ (V) & $V_B$ (V) & $V_E$ (V) & $I_B$ ($\mu$A) & $I_{R1}$ ($\mu$A) & $I_{R2}$ ($\mu$A) \\
    \hline
    894.7 & 5.752 & 2.111 & 1.470 & 5.729 & 123.0 & 117.3 \\
    \hline
    \end{tabular}
    \caption{静态工作点测量数据}
    \label{tab:1.1}
\end{table}

多列合并的表格
\begin{table}[H]
\centering
\begin{tabular}{|l|c|c|c|c|c|c|}
\hline 
\multirow{2}{*}{测试条件} & \multicolumn{4}{c|}{实测值} & \multicolumn{1}{c|}{理论值}  & \multicolumn{1}{c|}{仿真值}\\
\cline{2-7} 
& $V_{\text{iP－P}}$ & $V_{\text{oP－P}}$ & $V_{\text{oP－Pmax}}$ & $\left|A_{\mathrm{V}}\right|$ & $\left|A_{\mathrm{V}}\right|$ & $\left|A_{\mathrm{V}}\right|$\\
\hline 
$R_{\mathrm{L}}=\infty$、有$\mathrm{C}_{\mathrm{E}}$ & 20.041 $\mathrm{mV}$ & $549.38 \mathrm{mV}$ & $3.05 \mathrm{V}$ & 27.41& 28.96 &27.32 \\
\hline 
$R_{\mathrm{L}}=\infty$、无$\mathrm{C}_{\mathrm{E}}$ & 20.048 $\mathrm{mV}$ & $23.750 \mathrm{mV}$ & $\times$ & 1.18 & 1.23 &1.19\\
\hline 
$R_{\mathrm{L}}$(5.1 $\mathrm{k}\Omega$)有$\mathrm{C}_{\mathrm{E}}$ & 19.964 $\mathrm{mV}$ & $391.09 \mathrm{mV}$& $\times$ & 19.59& 20.82 & 19.68\\
\hline 
\end{tabular}
\caption{电压增益测量数据表}
\end{table}

# image

## single image
\begin{figure}[H]
    \centering
    \includegraphics[width=0.4\textwidth, height=0.2\textheight]{figure/check_process.jpg}
    \caption{验算过程}
\end{figure}

## 一行三图
subcaption方法
\begin{figure}[H]
    \centering
    \begin{subfigure}[b]{0.32\textwidth}
        \centering
        \includegraphics[width=\textwidth]{figure/Ro_circuit.png}
        \caption{输出电阻电路图}
        \label{fig:Ro1}
    \end{subfigure}
    \hfill
    \begin{subfigure}[b]{0.32\textwidth}
        \centering
        \includegraphics[width=\textwidth]{figure/Ro_waveform.png}
        \caption{输出电阻频率特性曲线}
        \label{fig:Ro2}
    \end{subfigure}
    \hfill
    \begin{subfigure}[b]{0.32\textwidth}
        \centering
        \includegraphics[width=\textwidth]{figure/Ro_measure_result.png}
        \caption{输出电阻仿真值}
        \label{fig:Ro3}
    \end{subfigure}
    \caption{输出电阻仿真结果}
    \label{fig:Ro}
\end{figure}
subfigure方法
\begin{figure}[H]
    \centering
    \subfigure[信号2在窗长700下的时频图\label{fig:signal2-stft-700}]{
        \includegraphics[width=0.32\textwidth]{stft/signal2_stft_W700.png}
    }
    \hfill
    \subfigure[信号2在窗长1400下的时频图\label{fig:signal2-stft-1400}]{
        \includegraphics[width=0.32\textwidth]{stft/signal2_stft_W1400.png}
    }
    \hfill
    \subfigure[信号2在窗长2800下的时频图\label{fig:signal2-stft-2800}]{
        \includegraphics[width=0.32\textwidth]{stft/signal2_stft_W2800.png}
    }
    \caption{信号2在不同窗长下的 STFT 结果}
    \label{fig:signal2-stft}
\end{figure}
## 一行双图
\begin{figure}[H]
    \centering
    \begin{subfigure}[b]{0.32\textwidth}
        \centering
        \includegraphics[width=\textwidth]{figure/i_2.1.5.png}
        \caption{截止失真波形}
        \label{fig:cutoff_distort}
    \end{subfigure}
    \hfill

    \begin{subfigure}[b]{0.32\textwidth}
        \centering
        \includegraphics[width=\textwidth]{figure/i_2.1.6.png}
        \caption{饱和失真波形}
        \label{fig:sati_distort}
    \end{subfigure}
    \hfill

    \caption{失真波形图像}
    \label{fig:distort}
\end{figure}



## 双图并排非子图
    \begin{figure}[H]
        \centering
        \begin{minipage}[b]{0.45\linewidth}
            \centering
            \includegraphics[width=0.9\textwidth]{example}
            \caption{非子图并排题注1}
             
        \end{minipage}%
        \begin{minipage}[b]{0.45\linewidth}
            \centering
            \includegraphics[width=0.9\textwidth]{example}
            \caption{非子图并排题注2}
             
        \end{minipage}
    \end{figure}

    % fig.tex
## 双图并排子图
    \begin{figure}[H]
        \centering
        \subcaptionbox{双图并排子图1}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.4\textwidth]{example}
             
        }%
        \hspace{0.5cm} 
        \subcaptionbox{双图并排子图1}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.4\textwidth]{example}
             
        } 
        \caption{双图并排子图}
         
    \end{figure}


## 双图纵排子图
    % fig.tex
    \begin{figure}[H]
        \centering
        \subcaptionbox{双图纵排子图1}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.4\textwidth]{example}
             
        }\\[0.5cm]% % 换行并产生图片纵向距离
        \subcaptionbox{双图纵排子图2}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.4\textwidth]{example}
             
        } 
        \caption{双图纵排子图}
         
    \end{figure}
    
## 三个子图横排
    % fig.tex
    \begin{figure}[H]
        \centering
        \subcaptionbox{三个子图横排1}[0.33\textwidth][c]{
            \centering
            \includegraphics[width=0.32\textwidth]{example}
             
        }%
            \subcaptionbox{三个子图横排2}[0.33\textwidth][c]{
            \centering
            \includegraphics[width=0.32\textwidth]{example}
             
        }%
            \subcaptionbox{三个子图横排3}[0.33\textwidth][c]{
            \centering
            \includegraphics[width=0.32\textwidth]{example}
             
        }%
        \caption{三个子图横排}
         
    \end{figure}

## 三个子图1+2模式
    % fig.tex
    \begin{figure}[H]
        \centering
        \subcaptionbox{三个子图1+2模式1}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }\\%
        \subcaptionbox{三个子图1+2模式2}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }%
        \hspace{0.3cm}
        \subcaptionbox{三个子图1+2模式3}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }%
        \caption{三个子图1+2模式}
         
    \end{figure}



## 三个子图一大两小
    % fig.tex
    \begin{figure}[H]
        \centering
        \begin{minipage}[b]{0.45\textwidth}
            \centering
            \includegraphics[width=\textwidth, height=1.2\textwidth]{example}
            \caption{三个图非子图一大两小1}
             
        \end{minipage}
        \hspace{0.5cm}%
        \begin{minipage}[b]{0.4\textwidth}
            \begin{minipage}[b]{\textwidth}
                \centering
                \includegraphics[width=\textwidth]{example}
                \caption{三个图非子图一大两小2}
                 
            \end{minipage}\\[0.8cm]%
            \begin{minipage}[b]{\textwidth}
                \centering
                \includegraphics[width=\textwidth]{example}
                \caption{三个图非子图一大两小3}		
                 
            \end{minipage}	
        \end{minipage}
    \end{figure}

## 四个子图
    % fig.tex
    \begin{figure}[H]
        \centering
        \subcaptionbox{四个子图1}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }%
        \hspace*{0.1cm}
        \subcaptionbox{四个子图2}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }\\% % 换行
        \subcaptionbox{四个子图3}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }%
        \hspace*{0.1cm}
        \subcaptionbox{四个子图4}[0.45\textwidth][c]{
            \centering
            \includegraphics[width=0.45\textwidth]{example}
             
        }%
        \caption{四个子图}
         
    \end{figure}
# 公式

## 一般公式
\[
\frac{\Delta R_x}{R_x}=\sqrt{
\left( \frac{u(R_s)}{R_s} \right)^2
+ \left( \frac{0.2}{S} \right)^2
}
=\sqrt{
\left( \frac{0.22 \Omega}{237.8 \Omega} \right)^2
+ \left( \frac{0.2}{396.33} \right)^2
}
=0.0011
\]
## 方程组
\[
\left\{\begin{array}{l}
g_{m}=\frac{I_{C}}{V_{T}} \\
r_{\pi}=\frac{\beta}{g_{m}} \\
r_{e}=\frac{\alpha}{g_{m}}
\end{array}\right.
\]

## 拖式计算
\begin{align}
    \mathrm{E} &= \frac{\Delta R_X}{R_X} \\
           &= \sqrt{
                \left( \frac{\Delta R_S}{R_S} \right)^2 
              + \left( \frac{\Delta R_S}{R_S} \right)^2 
              + \left( \frac{\Delta R'_S}{R'_S} \right)^2
              } \\
           &= \sqrt{
                \left( 0.001 + \frac{0.002\,m}{R_S} \right)^2 
              + \left( \frac{0.2}{S} \right)^2 
              + \left( \frac{0.2}{S'} \right)^2
              }
\end{align}

# 问题答案
\begin{problem}
adsfa
\end{problem}
\begin{solution}
\end{solution}
# 代码
\begin{lstlisting}[language=Python, caption=Python example]
def hello_world():
    print("Hello, world!")
\end{lstlisting}

# 附录

# 定理环境
\section{定理环境}
\begin{Theorem}

\end{Theorem}

\begin{Lemma}

\end{Lemma}

\begin{Corollary}

\end{Corollary}

\begin{Proposition}

\end{Proposition}

\begin{Definition}

\end{Definition}

\begin{Example}

\end{Example}

\begin{proof}

\end{proof}