#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/asio.hpp>

using std::string;

void print(const boost::system::error_code&)
{
    std::cout << "Print test is done !\n";
    std::cout << "Fvckity bye !\n" << std::endl;
}

int synctest()
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(3));
    t.wait();
    std::cout << "Hello ! So where was I ? BARCELONA !\n" << std::endl;
    return 0;
}

int asynctest()
{
    //Commented for fun
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.async_wait(&print);
    //This part runs first
    std::cout<<"Press Enter to continue !";
    std::cin.get();
    std::cout<<"Kono Dio da !" << std::endl;
    //run async_wait
    io.run();  //If the timer expires, the print function will run
    //The next one will just run normally
    std::cout<< "End of the line, my friend !\n" << std::endl;
    return 0;
}

int bindtest()
{
    
    return 0;
}

int main(int argc, char** argv) {

    synctest();
    asynctest();
    return 0;
}