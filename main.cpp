#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


int people = 0;

void client();
void teller();

void thread_join(std::thread& th);


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tОчередь клиентов\n" << std::endl;

	std::thread th1(client);
	std::thread th2(teller);

	thread_join(th1);
	thread_join(th2);

	std::cout << "\nВсе клиенты обслужены." << std::endl;
	system("pause > nul");
	return 0;
}

void client() {
	int max_clients = 10;
	auto sleep_time = 1s;
	for (int i = 0; i < max_clients; ++i) {
		std::this_thread::sleep_for(sleep_time);
		people++;
		std::cout << "Клиентов в очереди: " << people << std::endl;
	}
}

void teller() {
	auto sleep_time = 2s;
	while (true) {
		std::this_thread::sleep_for(sleep_time);
		if (people > 0) {
			people--;
			std::cout << "Клиентов к операционисту: " << people << std::endl;
		}
		else break;
	}
}

void thread_join(std::thread& th) {
	if (th.joinable())
		th.join();
}
