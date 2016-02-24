function [der] = get_derivative(data, dt, approx_method)

sz = size(data, 1);

% Shift matrix by one backwards
data_plus_dt = circshift(data, [-1]);
data_plus_dt = data_plus_dt(1:sz-1);

% Shift matrix by one forwards
data_minus_dt = circshift(data, [1]);
data_minus_dt = data_minus_dt(2:sz);

if strcmp(approx_method, 'forward')
    
    % The nominator of the derivative
    data_der_nom = data_plus_dt - data(1:sz-1);

    % The actual derivative
    der = data_der_nom ./ dt;
end 

if strcmp(approx_method, 'backward')
    % The nominator of the derivative
    data_der_nom = data(2:sz) - data_minus_dt;

    % The actual derivative
    der = data_der_nom ./ dt;
end 


if strcmp(approx_method, 'tustin')
    
    % The nominator of the derivative
    data_der_nom = data(2:sz) - data_minus_dt;

    % The denominator of the derivative
    data_der_denom = data(1:sz-1) + data_plus_dt;

    % The actual derivative
    der = 2 * data_der_nom ./ (dt .* data_der_denom);
end 

