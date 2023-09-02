#define _CRT_SECURE_NO_WARNINGS 1
% [X Y] = meshgrid(-2:0.2 : 2);
% Z = X.*exp(-X. ^ 2 - Y. ^ 2);
%%% surf(X, Y, Z);
% t = "hellow ";
% a = [1, 2, 4, 5];
%% plot(a); % 作图
% grid on; % 添加网格线
% A = [1 2 4; 2 3 4; 4 5 6]
% B = A'
% [D, V] = eig(A) % 特征值和特征向量
% x = 0:0.05 : 20;
% y1 = sin(x);
% y2 = cos(x);
% plot(x, y1, x, y2);
% grid on;
% [X, Y] = meshgrid(-2:0.5 : 2);
% Z = X.*(-X. ^ 2 - Y. ^ 2);
%% surf(X, Y, Z);
% plot3(X, Y, Z);
% colormap hsv;
% colorbar
% subplot(1, 2, 1); surf(X.*X); colormap hsv; title('the first');
% subplot(1, 2, 2); surf(Y.*Y); title('the second');
% clear
% c = input('qing');
% a = c;
% disp(a);
% x1 = 0:0.05 : 100;
% x2 = linspace(0, 2 * pi, 10);
% y1 = sin(x1);
% y2 = sin(x2);
% subplot(1, 2, 1); plot(x1, y1); colormap hsv; title('the first');
% subplot(1, 2, 2); plot(x2, y2); title('the second');
% fplot('cos(x)', [0, 1], 1e-4)

% x = 0:pi / 100 : 2 * pi;
% y1 = 0.2 * exp(-0.5 * x).*cos(4 * pi * x);
% plot(x, y1, 'b-.')
% xlabel('this is the first ');
% hold on
% y2 = 2 * exp(-0.5 * x).*cos(pi * x);
% plot(x, y2);
% x = 0:pi / 100 : 2 * pi;
% y = sin(x).*cos(x);
% polar(x, y, '-*');
% x = 0:pi / 10 : 2 * pi;
% y = 2 * sin(x);
% subplot(2, 2, 1); bar(x, y, 'g');
% title('bar(x,y,''g'')'); axis([0, 7, -2, 2]);
% subplot(2, 2, 2); stairs(x, y, 'b');
% title('stairs(x,y,''b'')'); axis([0, 7, -2, 2]);
% subplot(2, 2, 3); stem(x, y, 'k');
% title('stem(x,y,''k'')'); axis([0, 7, -2, 2]);
% subplot(2, 2, 4); fill(x, y, 'y');
% title('fill(x,y,''y'')'); axis([0, 7, -2, 2]);
% X = randn(1000, 1);
% Y = randn(1000, 1);
% scatter(X, Y);
% xlabel('x');
% ylabel('y');
clc
clear
data = xlsread("C:\Users\Administrator\Desktop\.vs\问题一\问题一代码和excel文件\附件1：加工后123家有信贷记录企业的相关数据", "进项发票信息");
for i = 1:123
a = find(data(:, 1) == i);
te = data(a(1, 1), max(a));
te = sortrows(te, [3, 4, 5]);
rub = find(data(:, 10) == 0);
rub = size(rub, 1);
vu = size(a, 1) - rub;

aa = find(te(:, 9) > 0 & te(:, 10) == 1);
tee = te(aa, :);
ree = sortrows(tee, [3, 4, 5]);











end
xlswrite("C:\Users\Administrator\Desktop\.vs\问题一\问题一代码和excel文件", reslut, '试一下');
