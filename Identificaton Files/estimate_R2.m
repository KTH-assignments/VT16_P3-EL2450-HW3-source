st = 2;

dt = f_file(end,4) - f_file(st,4)
dt = f_file(end,1) - f_file(st,1)
dt = dt * 10^(-6)
dx = f_file(end,2) - f_file(st,2)
dy = f_file(end,3) - f_file(st,3)
R = sqrt((dx / (dt*200))^2 + (dy / (dt*200))^2)
format long
R = sqrt((dx / (dt*200))^2 + (dy / (dt*200))^2)