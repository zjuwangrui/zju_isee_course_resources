# table
普通表格
\begin{table}[H]
    \centering
    \begin{tabular}{|c|c|c|c|c|c|c|}
    \hline
    $A_m$ & $V_{CE}$ (V) & $V_B$ (V) & $V_E$ (V) & $I_B$ ($\mu$A) & $I_{R1}$ ($\mu$A) & $I_{R2}$ ($\mu$A) \\
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
    \includegraphics[width=0.4\textwidth, height=0.2\textheight]{figure/sum_sti/sum_A.png}
    \caption{带通滤波器增益频率特性曲线}
    \label{fig:sum_A}
\end{figure}
## 一行三图
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
\begin{equation}
    \begin{cases}
    \end{cases}
\end{equation}
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

V(vout)/V(vin)
