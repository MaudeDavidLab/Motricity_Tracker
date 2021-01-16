%% Written by Nick Bira, Jan 8, 2021
% This code inputs the motor test data and plots it

x = importdata('Motor_Verification_Data_Distance.csv');
v = importdata('Motor_Verification_Data_Velocity.csv');

t = (linspace(1,length(x),length(x)))/4; %Conversion to seconds

diam_wheel = 4.5; %inches
circum = diam_wheel*pi;
%circum_miles = circum*(1.57828e-5); %Circumference of the wheel in miles

x = x.*circum; %Converts data to distance traveled
v = v.*circum; %Converts data to average speed

v = smoothdata(v); %smoothing average window function for better visualization of velocity change

color_codes = ["#3d5a80","#98c1d9","#1a659e","#EE6C4D","#293241","#450920"];

figure
subplot(2,1,1)
for i = 1:5
    plot(t,x(:,i),'LineWidth',3,'Color',color_codes(i))
    hold on
end

ylabel('Distance Traveled (inches)')
legend('Sensor 1','Sensor 2','Sensor 3','Sensor 4','Sensor 5','location','northwest')
h = gca; 
set(h,'xticklabel',[])
%h.XAxis.Visible = 'off';
set(gca,'FontName','Arial Narrow')

subplot(2,1,2)
for i = 1:5
    plot(t,v(:,i),'LineWidth',3,'Color',color_codes(i))
    hold on
end
ylabel('Average Velocity (inches/sec)')
xlabel('Time (seconds)')

set(gca,'FontName','Arial Narrow')