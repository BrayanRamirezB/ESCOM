%**************************************************************************
%DISE?O DE FILTROS
%**************************************************************************
%clc;
close all;
clear all;
s=tf('s');

%**************************************************************************
%Acelerometro

%**************************************************************************
m=0.1;
wc=100;
 Kd=1;
 Ka=10;
 R=1000;
 Kf=1;
 e=0.5;
 K=1000;
 Gr=((1/K)*(wc*wc))/((s*s)+(2*e*wc*s)+(wc*wc));
 Gao=Gr*Kd*Ka*R*m;
 H=Kf*(1/m)*(1/R);
%Gm=41.67/((s*s)+(16.7*s)+(83.3));
% Gm=(10*(s+2.5))/((s*s)+(6*s)+(25));
%Gm=(s+2)/((s*s)+(4*s)+(20));
%Gm= 1/((5+5)*(s+10));
%Gm=(s*(s-2))/((s+5)*((s*s)+(6*s)+(10)));
sisotool


% %bode(Gp)
% 
%                                                                                                                                                                          