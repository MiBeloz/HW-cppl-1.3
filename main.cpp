#include <iostream>
#include <functional>
#include <vector>


constexpr auto pi = 3.1415926;

std::vector<std::function<void(double)>> functions_base();
void print_input_data(const std::vector<double>& angles);
void convert_to_radians(std::vector<double>& angles);
void print_output_data(const std::vector<double>& angles, const std::vector<std::function<void(double)>>& functions);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tОперации над углами\n" << std::endl;

	std::vector<double> angles{ 30,60,90 };
	std::vector<std::function<void(double)>> functions = std::move(functions_base());

	std::cout << "[Входные данные]: ";
	print_input_data(angles);

	convert_to_radians(angles);

	std::cout << "[Выходные данные]:" << std::endl;
	print_output_data(angles, functions);

	system("pause > nul");
	return 0;
}

std::vector<std::function<void(double)>> functions_base() {
	std::vector<std::function<void(double)>> functions;

	functions.emplace_back([](const double& angle) {std::cout << "sin: " << sin(angle) << "; "; });
	functions.emplace_back([](const double& angle) {std::cout << "cos: " << cos(angle) << "; "; });
	functions.emplace_back([](const double& angle) {std::cout << "tan: " << tan(angle) << "; "; });

	return functions;
}

void print_input_data(const std::vector<double>& angles) {
	std::cout.precision(8);
	for (auto& angle : angles) {
		if (angle != angles[angles.size() - 1]) {
			std::cout << angle << " * " << pi << " / " << 180 << ", ";
		}
		else {
			std::cout << angle << " * " << pi << " / " << 180 << "   // перевод из градусов в радианы\n";
		}
	}
	std::cout << std::endl;
}

void convert_to_radians(std::vector<double>& angles) {
	for (auto& angle : angles) {
		angle *= pi / 180;
	}
}

void print_output_data(const std::vector<double>& angles, const std::vector<std::function<void(double)>>& functions) {
	std::cout.precision(6);
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}
