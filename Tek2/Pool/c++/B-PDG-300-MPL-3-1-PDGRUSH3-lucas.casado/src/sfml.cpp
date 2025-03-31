/*
** EPITECH PROJECT, 2022
** C++
** File description:
** sfml
*/

#include "sfml.hpp"
#include "ModuleUser.hpp"
#include "ModuleOS.hpp"
#include "ModuleDate.hpp"
#include "ModuleCpu.hpp"
#include "ModuleRam.hpp"
#include "ModuleNetwork.hpp"

sfml::sfml() 
{

}

sfml::~sfml() 
{

}

void sfml::initWindow()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(800,800), "MyGKrellM");
}

sf::RenderWindow *sfml::getWindow() const
{
    return (this->_window);
}

sf::Event *sfml::getEvent() const
{
    return (this->_event);
}

void sfml::handleEvents()
{
    this->_event = new sf::Event;

    while(getWindow()->pollEvent(*_event)) {
        if (getEvent()->type == sf::Event::Closed)
            this->_window->close();
    }
}

void sfml::mainWindow()
{
    sfml::initWindow();

    while(getWindow()->isOpen()) {
        sfml::handleEvents();
        sfml::_window->clear(sf::Color(128, 128, 128));
        sfml::all_element();
        sfml::_window->display();

    }
}

void sfml::all_element()
{
    ModuleUser _os;
    ModuleOs _user;
    ModuleDate _date;
    ModuleCpu _cpu;
    ModuleRam _ram;
    ModuleNetwork _net;

    sf::Font font;
    font.loadFromFile("./font.ttf");

    //computer image
    sf::Image image;
    if (!(image.loadFromFile("./cpt.png")))
            std::cout << "Cannot load image";
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite isprite;
    isprite.setTexture(texture);
    isprite.setScale(sf::Vector2f{0.1,0.1});
    isprite.setPosition(sf::Vector2f{10, 50});
    
    this->_window->draw(isprite);

    //image ram
    sf::Image image1;
    if (!(image1.loadFromFile("./ram.png")))
            std::cout << "Cannot load image";
    sf::Texture texture1;
    texture1.loadFromImage(image1);
    sf::Sprite rsprite;
    rsprite.setTexture(texture1);
    rsprite.setPosition(sf::Vector2f{0, 300});
    
    this->_window->draw(rsprite);

    //image Network
    sf::Image image2;
    if (!(image2.loadFromFile("./network.png")))
            std::cout << "Cannot load image";
    sf::Texture texture2;
    texture2.loadFromImage(image2);
    sf::Sprite nsprite;
    nsprite.setTexture(texture2);
    nsprite.setScale(sf::Vector2f{0.17,0.17});
    nsprite.setPosition(sf::Vector2f{10, 500});
    
    this->_window->draw(nsprite);

    //date
    sf::Text date;
    std::string d = _date.sendDate();
    date.setString(d);
    date.setFillColor(sf::Color::Black);
    date.setPosition(sf::Vector2f {250,0});
    date.setCharacterSize(30);
    date.setFont(font);
    
    this->_window->draw(date);

    //hostname
    sf::Text phostname;
    std::string hostname = "Hostname : " + _os.getHostname();
    phostname.setString(hostname);
    phostname.setFillColor(sf::Color::White);
    phostname.setPosition(sf::Vector2f {250,50});
    phostname.setCharacterSize(24);
    phostname.setFont(font);
    
    this->_window->draw(phostname);

    //username
    sf::Text username;
    std::string user = "Username : " + _os.getUsername();
    username.setString(user);
    username.setFillColor(sf::Color::White);
    username.setPosition(sf::Vector2f {250,100});
    username.setCharacterSize(24);
    username.setFont(font);
    
    this->_window->draw(username);

    //os
    sf::Text os;
    std::string o = "Os : " + _user.sendOSName();
    os.setString(o);
    os.setFillColor(sf::Color::White);
    os.setPosition(sf::Vector2f {250,150});
    os.setCharacterSize(24);
    os.setFont(font);
    
    this->_window->draw(os);

    //kernel
    sf::Text kernel;
    std::string k = "Kernel : " + _user.sendKernelVersion();
    kernel.setString(k);
    kernel.setFillColor(sf::Color::White);
    kernel.setPosition(sf::Vector2f {250,200});
    kernel.setCharacterSize(24);
    kernel.setFont(font);
    
    this->_window->draw(kernel);


    //ram_used
    sf::Text ram_used;
    std::string ramused = "ram used : " + _ram.SendRamUsed();
    ram_used.setString(ramused);
    ram_used.setFillColor(sf::Color::White);
    ram_used.setPosition(sf::Vector2f {250,350});
    ram_used.setCharacterSize(24);
    ram_used.setFont(font);
    
    this->_window->draw(ram_used);

    //Free Ram
    sf::Text ram_free;
    std::string ramfree = "Free ram : " + _ram.SendRamAvailable();
    ram_free.setString(ramfree);
    ram_free.setFillColor(sf::Color::White);
    ram_free.setPosition(sf::Vector2f {250,400});
    ram_free.setCharacterSize(24);
    ram_free.setFont(font);

    this->_window->draw(ram_free);

    //ram_total
    sf::Text ram_total;
    std::string ramtotal = "Ram total : " + _ram.SendRamTotal();
    ram_total.setString(ramtotal);
    ram_total.setFillColor(sf::Color::White);
    ram_total.setPosition(sf::Vector2f {250,450});
    ram_total.setCharacterSize(24);
    ram_total.setFont(font);
    
    this->_window->draw(ram_total);

    //swap_used
    sf::Text swap_used;
    std::string swapused = "swap used : " + _ram.SendSwapUsed();
    swap_used.setString(swapused);
    swap_used.setFillColor(sf::Color::White);
    swap_used.setPosition(sf::Vector2f {530,350});
    swap_used.setCharacterSize(24);
    swap_used.setFont(font);
    
    this->_window->draw(swap_used);

    //Free swap
    sf::Text swap_free;
    std::string swapfree = "free swap : " + _ram.SendswapAvailable();
    swap_free.setString(swapfree);
    swap_free.setFillColor(sf::Color::White);
    swap_free.setPosition(sf::Vector2f {530,400});
    swap_free.setCharacterSize(24);
    swap_free.setFont(font);

    this->_window->draw(swap_free);

    //swap_total
    sf::Text swap_total;
    std::string swaptotal = "swap total : " + _ram.SendSwapTotal();
    swap_total.setString(swaptotal);
    swap_total.setFillColor(sf::Color::White);
    swap_total.setPosition(sf::Vector2f {530,450});
    swap_total.setCharacterSize(24);
    swap_total.setFont(font);
    
    this->_window->draw(swap_total);


    //upload
    sf::Text upload;
    std::string up = "Upload : " + std::to_string(_net.sendUpload()) + " -> " + std::to_string(_net.sendUpload() / (1024*1024)) + "mb";
    upload.setString(up);
    upload.setFillColor(sf::Color::White);
    upload.setPosition(sf::Vector2f {250,550});
    upload.setCharacterSize(24);
    upload.setFont(font);
    
    this->_window->draw(upload);

    //download
    sf::Text download;
    std::string down = "download : " + std::to_string(_net.sendDownload()) + " -> " + std::to_string(_net.sendDownload() / (1024*1024)) + "mb";
    download.setString(down);
    download.setFillColor(sf::Color::White);
    download.setPosition(sf::Vector2f {250,600});
    download.setCharacterSize(24);
    download.setFont(font);
    
    this->_window->draw(download);

}