%Resample to 16000 Hz
clear;


[Data, Fs]=audioread('colony-with-queen-gruber.mp3');
Fs=2205;
Data=dlmread('Swarm_long.dat');
[p,q] = rat(6300 / Fs);
Data=resample(Data,p,q);
dlmwrite('Active_ger.dat', Data, 'delimiter', '\n', 'precision', '%.6f');

%%
Data=dlmread('Swarm_long.dat');
Fs=6300;
audiowrite('SWARM.wav',Data,Fs);