// Throttle1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>


class throttle
{
public:
	void shut_off();
	void shift(int amount);
	double flow() const;
	bool is_on() const;
	bool More_than_half() const;
private:
	int position;
};

void throttle::shut_off()
{
	position = 0;
}
void throttle::shift(int amount)
{
	position += amount;
	if (position < 0)
		position = 0;
	else if (position > 6)
		position = 6;
}

double throttle::flow() const
{
	return position / 6.0;
}
bool throttle:: More_than_half() const
{
	return (flow() > .5);
}

bool throttle::is_on() const
{
	return (flow() > 0);
}
int main()
{
	throttle sample;
	int user_input;

	std::cout << "I have a throttle with 6 positions." << std::endl;
	std::cout << "Where would you like to set the throttle? " << std::endl;
	std::cout << "Please type a number from 0 to 6: ";
	std::cin >> user_input;
	sample.shut_off();
	sample.shift(user_input);

	while (sample.is_on())
	{
		std::cout << "The flow is now " << sample.flow() << std::endl;
		sample.shift(-1);
	}
	std::cout << "The flow is now off" << std::endl;
	return EXIT_SUCCESS;
}

