% Initialize arrays to hold voltage and air flow rate values
voltages = [];
air_flow_rates = [];

% Open the file
fileID = fopen('data_air_flow_sensor.txt', 'r');

% Read the file line by line
while ~feof(fileID)
    % Read the current line
    line = fgetl(fileID);
    
    % Check if the line contains 'Voltage:' and 'Air Flow Rate:'
    if contains(line, 'Voltage:') && contains(line, 'Air Flow Rate:')
        % Extract the voltage value
        voltage_str = extractBetween(line, 'Voltage: ', ' V');
        voltage = str2double(voltage_str{1});
        
        % Extract the air flow rate value
        air_flow_rate_str = extractBetween(line, 'Air Flow Rate: ', ' L/min');
        air_flow_rate = str2double(air_flow_rate_str{1});
        
        % Append the values to the arrays
        voltages(end + 1) = voltage;
        air_flow_rates(end + 1) = air_flow_rate;
    end
end

% Close the file
fclose(fileID);

% Find the index where the air flow rate jumps significantly
jump_threshold = 50; % Define a threshold for significant jump
jumps = find(diff(air_flow_rates) > jump_threshold);

% Plot the data
figure;
hold on;
% Plot segments of data before and after the jump
plot(voltages(1:jumps), air_flow_rates(1:jumps), '-r.', 'MarkerSize', 10);
plot(voltages(jumps+1:end), air_flow_rates(jumps+1:end), '-r.', 'MarkerSize', 10);
hold off;

title('Air Flow Rate vs Voltage');
xlabel('Voltage (V)');
ylabel('Air Flow Rate (L/min)');
grid on;

