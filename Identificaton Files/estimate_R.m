f_t = f_file(:,1);
f_x = f_file(:,2);
f_y = f_file(:,3);
f_theta = f_file(:,4);

sz = size(f_t, 1);

dt = circshift(f_t, [-1]) - f_t;
dt = 10^(-6) * dt(1:sz-1);

approximation_method = 'tustin';

x_der = get_derivative(f_x, dt, approximation_method);
y_der = get_derivative(f_y, dt, approximation_method);
theta_der = get_derivative(f_theta, dt, approximation_method);


% dt has some values where it is zero.
% the derivatives will have nan or inf there
rem_id = find(dt == 0);
 
% x_der(rem_id) = 0;
% y_der(rem_id) = 0;
% theta_der(rem_id) = 0;

R_x = x_der ./ (cos(f_theta(1:sz-1)) * 200);
R_y = y_der ./ (sin(f_theta(1:sz-1)) * 200);
 
 
R = sqrt(x_der.^2 + y_der.^2) / 200;

% R(isnan(R)) = 0;