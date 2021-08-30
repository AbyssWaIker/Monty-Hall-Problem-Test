#include <iostream>
#include <random>

using namespace std;

bool chooseTheDoorTest(bool viewer_switches_the_door)
{
    unsigned short correct_door = random() % 3;
    unsigned short chosen_door = random() % 3;

    bool viewer_had_chosen_correctly = chosen_door == correct_door;

    bool had_viewer_won = (viewer_had_chosen_correctly != viewer_switches_the_door);
    return had_viewer_won;
}

unsigned long repeatTestsWithSetSwitch(unsigned number_of_tests, bool b_does_viewer_switch)
{
    unsigned n_successes = 0;
    //rc is "return carriage"
    const char rc = '\r';
    for(unsigned i = 0; i < number_of_tests; i++)
    {
        //noticeable if you do millions and more tests
        cout << rc << "Try #"<< i+1 << flush;

        n_successes += chooseTheDoorTest(b_does_viewer_switch);
    }

    cout << "\rTest is finished!" << endl;

    return n_successes;
}

int main()
{
    cout << "Programs that test Monty Hall problem" << endl;

    long long number_of_tests;
    do {
        cout << "Enter number of repeats for tests\n" << endl;
        cin >> number_of_tests;
    } while (number_of_tests < 1);

    cout << "Start "<< number_of_tests <<" tests in which viewers switches their door" << endl;
    unsigned n_successes_with_switches = repeatTestsWithSetSwitch(number_of_tests, true);
    cout << n_successes_with_switches << " of " << number_of_tests << " viewers won by switching the door" << endl;

    cout << "Start " << number_of_tests << " tests in which viewers don\'t switches their door" << endl;
    unsigned n_successes_without_switches = repeatTestsWithSetSwitch(number_of_tests, false);
    cout << n_successes_without_switches << " of " << number_of_tests << " viewers won by NOT switching the door" << endl;

    return 0;
}

