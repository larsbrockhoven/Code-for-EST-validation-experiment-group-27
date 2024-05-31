% Read data from the .txt file
fileName = 'data_pressure_sensor_sensor.txt';
sensorData = load(fileName);

% Generate x values (assuming x is just the index of each sensor data point)
x = 1:length(sensorData);

% Create a figure for the plot
figure;
hold on;

% Plot the sensor data
scatter(x, sensorData, 'b', 'filled');
title('Sensor Pressure vs Index');
xlabel('Index');
ylabel('Sensor Pressure');

% Fit a linear model to the data
p = polyfit(x, sensorData, 1);
best_fit_line = polyval(p, x);

% Plot the best fit line
plot(x, best_fit_line, 'r', 'LineWidth', 2);

% Plot the ideal sensor pressure line (y = x)
ideal_sensor_pressure = x;  % Since y = x, we can use x values directly
plot(x, ideal_sensor_pressure, 'k--', 'LineWidth', 2);

% Add a legend
legend('Sensor Data', 'Best Fit Line', 'Ideal Sensor Pressure', 'Location', 'best');

% Display the equation of the best fit line
eq = sprintf('y = %.2fx + %.2f', p(1), p(2));
text(min(x), max(sensorData), eq, 'FontSize', 12, 'Color', 'r');

% Save the plot as an image
saveas(gcf, 'sensor_pressure_vs_index.png');

hold off;
