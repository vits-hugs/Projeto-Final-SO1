#ifndef main_class_h
#define main_class_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"
#include "window.h"
#include "../game/pacman.h"

__BEGIN_API

class Main
{
public:
    Main() {
    }

    static const int WORKLOAD = 20000;

    static int do_work(int n){
        int i, j, soma;

        soma = 0 ;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                soma += j * i;
        return soma;
    }

    static void run(void * name) {
        std::cout << (char *) name << ": inicio\n";

        std::string pang_name = "   Pang";
        std::string peng_name = "       Peng";
        std::string ping_name = "           Ping";
        std::string pong_name = "               Pong";
        std::string pung_name = "                   Pung";

        sf::RenderWindow window_(sf::VideoMode(500, 500), "SFML works!");
        window_.setKeyRepeatEnabled(false);
        window = &window_;
        // pacman_thread = new Thread(run_ghost,(char *) pang_name.data(),0);
        window_thread = new Thread(show_window);
        input_thread = new Thread(Read_input);

        // Ghosts
        ghost_threads[0] = new Thread(run_ghost, (char *) pang_name.data(), 3);
        ghost_threads[1] = new Thread(run_ghost, (char *) peng_name.data(), 4);
        ghost_threads[2] = new Thread(run_ghost, (char *) ping_name.data(), 5);
        ghost_threads[3] = new Thread(run_ghost, (char *) pong_name.data(), 6);

        sem = new Semaphore();

        for (int i = 0; i < 2; i++) {
            std::cout << "main: " << i << "\n";
            Main::do_work(WORKLOAD);
        }

        int ec;
        ec = window_thread->join();
        ec =  input_thread->join();
        std::cout << "main: esperando Pang...\n";
        ec = ghost_threads[0]->join();
        std::cout << "main: Pang acabou com exit code " << ec << "\n";

        std::cout << "main: esperando Peng...\n";
        ec = ghost_threads[1]->join();
        std::cout << "main: Peng acabou com exit code " << ec << "\n";

        std::cout << "main: esperando Ping...\n";
        ec = ghost_threads[2]->join();
        std::cout << "main: Ping acabou com exit code " << ec << "\n";

        std::cout << "main: esperando Pong...\n";
        ec = ghost_threads[3]->join();
        std::cout << "main: Pong acabou com exit code " << ec << "\n";

        std::cout << (char *) name << ": fim\n";
        
        delete sem;

        delete ghost_threads[0];
        delete ghost_threads[1];
        delete ghost_threads[2];
        delete ghost_threads[3];
        
        //delete pacman_thread;
        delete input_thread;
        delete window_thread;
    }

    ~Main() {}

private:

    static const int ITERATIONS = 10;

    static void run_ghost(char *name,int id) {
        std::cout << name << ": inicio\n";
        while(window->isOpen()) { 
        sem->p();
            std::cout << name << "\n" ;
            //Thread::yield();
        sem->v();
        }
        ghost_threads[id]->thread_exit(id);        
        
    }
    
    static void show_window() {
        Window window_logic;
        while(window->isOpen()) {
        sem->p();

        window_logic.run(window);
        //Thread::yield();
        sem->v();
        }
        
       
    }

    static void Read_input() {
    db<Thread>(TRC) << "LENDO INPUT\n";
    
    while(window->isOpen()) {
        
        sf::Event event;
        while (window->pollEvent(event))
        {
            sem->p();
            switch (event.type) {
            case sf::Event::Closed:
                    window->close();
                    break;
            
            // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                } else
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
            
            }
            //Thread::yield();
            sem->v();
        }
    }
    }

    private:
        static sf::RenderWindow* window;
        static Thread *ghost_threads[4];
        static Thread *pacman_thread;
        static Thread *window_thread;
        static Thread *input_thread;
        static Semaphore *sem;
};

__END_API

#endif
