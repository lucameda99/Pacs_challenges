clear all; close all; clc;
output = readmatrix('output.txt');
t = output(:,1);
U = output(:,2);

figure;
plot(t, U, 'o-');
hold on;

%% solution of MATLAB
f = @(t,y) -t * exp(-y);

tspan = [0, 1];
y0 = 0;

[t,y] = ode45(f, tspan, y0);

% Plot the solution
plot(t, y);
xlabel('t');
ylabel('y');

legend('CN c++', 'exact')
