#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

void print(const boost::system::error_code&)
{
    std::cout << "No one was ever that patient, lmao!" << std::endl;
}

void Simon(std::string line)
{
    std::cout << "Simon says: " << line << std::endl;
}

int main()
{
    std::cout << "Hello world!\n";
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.async_wait(&print);
    std::cout << "Really ?\n";
    std::cout << "Lol" << std::endl;
    io.run();
    std::thread t1(Simon, "Hello !");
    t1.join();
    return 0;
}
