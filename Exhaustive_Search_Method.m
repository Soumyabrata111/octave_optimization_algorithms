% Exhaustive Search Method as Explained in the book

%"Optimization of Engineering Design: Algorithms and Examples" by Prof. Kalyanmoy Deb

% Code developed by Sri. Soumyabrata Bhattacharjee

% Matlab version R2022b

% Date: 14th October, 2018

% Date: 25th October, 2023 (Updated)

% Date: 27th October, 2023 (Updated)



clear all

clc

a=0.1; %Lower bound

b=14; % Upper bound

n = 1000; %Number of divisions

dx=(b-a)/n; %Length of each division



% Equation to be minimized

f=@(x) x.^2+54./x;



% Initialization

x1=a;

x2=x1+dx;

x3=x2+dx;

x_min=x2;

f_min=f(x_min);



while x3<=b

    if f(x2)<=f(x1) && f(x2)<=f(x3)

        disp(['The approx minimum point is: ' num2str(x2)])

        disp(['The approx minimum function value is: ' num2str(f(x2))])

        x_min=x2;

        f_min=f(x_min);

    end

x1=x2;

x2=x1+dx;

x3=x2+dx;



end





% Plotting

x = linspace(a,b,n);

plot(x,f(x),'LineWidth',2,'DisplayName','Minimzed Function');

xlabel('x','FontWeight','bold'); % Corrected line

ylabel('f(x)','FontWeight','bold')

grid on;

title('Exhaustive Search Method','FontWeight','bold');



hold on;



% Scatter plot for the minimum point

scatter(x_min, f_min, 100, [1 0 0], 'filled', 'DisplayName', 'Minimum Point');



% Adding Legend

legend('Location','best')

legend('show')



% Save the figure as a PNG file

saveas(gcf, 'Exhaustive Search Method.png');



% Display the plot

hold off;
