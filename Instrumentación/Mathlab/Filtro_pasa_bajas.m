%**************************************************************************
%DISEÑO DEL CONTROL PI (En Isla)
%**************************************************************************
%clc;
close all;
clear all;
 s=tf('s');
%z=tf('z');
%z=tf('z');
% Datos
%B=0.006;
%Gc=(1.94*s^2+12.244*s+25.968)/s;
%Gc1=2.04*s+12.244+(25.968/s);
%Gc2=-0.1*s;
% C = 0.1e-10;
% R = 318;
% Gp = 1 /(s*C*R+1);
% Gp = (s*C*R) / (1 + s*C*R);
% Gp = ((s*s) + (11*s) + 10) / ((s*s*s) + (10*s*s) + (10000*s));
% sisotool

	% Set up vector for zeros
	% ceros = [0.998506 ; 1.001496];
    %eros = [0];

	% Set up vector for poles
	% polos = [0.889315+0.099600j ; 0.889315-0.099600j];
    %polos = [0.9];

	%figure(1);
	% zplane(ceros,polos);
	% title('FILTRO HIGHPASS 5')
    
    % Ga= z/(z - 0.9);
    % Ga =((0.894859*(z*z))-(1.78972*z)+0.894859)/((z*z)-(1.77863*z)+0.800803);
    % bode(Ga)
    % sisotool
fs = 44100;
fc = 5000;
n = 1;    
F= fc/(fs/2);
% [num, den] = butter(n, F, 'Low');
[num, den] = butter(n, F, 'High');
freqz(num,den)



%H = tf([1 11 10],[1 10 10000 0])
%pole(H)
%zero(H)
% pzmap(H)
%bode(H)
%C=0.02e-6;
%R=8000;
%Gp1=1/((s*C*R)+1);
%bode(Gp1, 'r')
%hold on
%C=4.7e-6;
% R=1000;
% L=2.2e-3;
% % Gp=(s*L)/(s^2*C*L*R+s*L+R);
% Gp=(1)/((s^2*C*L)+(s*C*R)+1);
% %Gp=(1/C*L)/(s^2)+((s*C*R/C*L))+(1/C*L);

%Gs=100/((s^2)+(10*s)+(100));

% Gs=(100*(s+1))/((s^2)+(2*s)+(100));
%Gs=1/(s*(s+1));

% Ga =((0.894859*(z*z))-(1.78972*z)+0.894859)/((z*z)-(1.77863*z)+0.800803);
% Ga=(-0.952*z)/((z^2)-(1.8096*z)+(0.9048));
% C=0.2e-6;
% R=800;
% Gp1=s*C*R/((s*C*R)+1);
% %Gp1=1/((s*C*R)+1);
% bode(Ga, 'r')
% sisotool



%Dig1=c2d(Gp1,1/40000,'tustin')
%Dig1=c2d(Gs,0.1,'tustin');
% [NUM,DEN] = tfdata(Dig1,'v')
%hold on
% 
% 
% %Gp=10/(s+1);
% %YsDs=Gp/(1+(Gp*(Gc1+Gc2)));
% %YsDs1=Gp/(1+(Gp*(Gc1)));
% %figure (5);
%M=0.5;
%B=0;
%B=122.2;
%B=4.66;
%B=0;
%
% %Gmr=(s+6)/((s+4)*(s^2+(4*s)+8));
% %step(Gmr);
% %margin (Gmr);
% %Gp= (100*(s+1))/((0.2*s+1)*(0.1*s+1));
% % k=200;
% % c=6.0;
% % m=0.5;
% % wo=sqrt((k/m)-((c^2)/(4*m^2)));
% % E=0.6;
% % B=wo*E;
% %Gp=-(s*s)/((s*s)+(2*B*s)+(wo^2));
% %margin (Gp);
% %bode (Gp);
% sisotool
% % 
% % %**************************************************************************
% % Filtro de segundo orden
% % %**************************************************************************
% %  k=1;
% %  wn=1000*2*pi;
% %  e=0.707;
% %  Gp=((k*wn*wn)/((s*s)+(2*e*wn*s)+(wn*wn)));
% %  bode(Gp)
% % Dig1=c2d(Gp,1/40000,'tustin')
% % [NUM,DEN] = tfdata(Dig1,'v')

% %M = 0.5;
% %B = 1.7;%B = 122.2;%B = 0;
% %K = 22.2;
% %Gmr = 1/(((s^2)*M) + (B*s) + K);
% %sisotool

% m=0.5;
% wc=10;
% Kd=1;
% Ka=1;
% R=1000;
% Kf=1;
% e=0.707;
% K=22;
% Gr=(((1/K)*wc*wc)/((s*s)+(2*e*wc*s)+(wc*wc)));
% Gao=Gr*Kd*Ka*R*m;
% H=Kf*(1/m)*(1/R);
% sisotool

% Gm=(s+2)/((s*s)+(4*s)+(20));
% Gm = (s*(s-2))/((s+5)*((s*s)+(s*6)+(10)));
% sisotool

% Datos
%B=0.006;
%Gc=(1.94*s^2+12.244*s+25.968)/s;
%Gc1=2.04*s+12.244+(25.968/s);
%Gc2=-0.1*s;
% Gp = 1 /((20*(s+1))*(10*(s+1))*(0.5*(s+1)));
% sisotool












                                                                                                                                                                       