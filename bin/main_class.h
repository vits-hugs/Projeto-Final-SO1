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
#include "../game/ghost.h"
#include "../game/agent.h"
#define FPS 20
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
        pacman = new Pacman();

        for (int i = 0; i < 4; i++)
        {
            ghost_array[i]= new Ghost(i);
            /* code */
        }
        window_logic = new Window(window,pacman,ghost_array);
        


        // pacman_thread = new Thread(run_ghost,(char *) pang_name.data(),0);
        window_thread = new Thread(show_window);
        input_thread = new Thread(Read_input);
        pacman_thread = new Thread(run_pacman);
        // Ghosts
        ghost_threads[0] = new Thread(run_ghost, (char *) pang_name.data(), 0);
        ghost_threads[1] = new Thread(run_ghost, (char *) peng_name.data(), 1);
        ghost_threads[2] = new Thread(run_ghost, (char *) ping_name.data(), 2);
        ghost_threads[3] = new Thread(run_ghost, (char *) pong_name.data(), 3);

        sem = new Semaphore();

        for (int i = 0; i < 2; i++) {
            std::cout << "main: " << i << "\n";
            Main::do_work(WORKLOAD);
        }

        int ec;
        ec = window_thread->join();
        ec =  input_thread->join();
        ec = pacman_thread->join();
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

    static void run_pacman() {
        while(window->isOpen()) { 
            sem->p();
            //Thread::yield();
            pacman->run();
            //std::cout << "X: " << pacman->x() << " Y: " << pacman->y() << "\n";
            sem->v();
        }
        pacman_thread->thread_exit(4);        

    } 
    
    static void run_ghost(char *name,int id) {
        std::cout << name << ": inicio\n";
        while(window->isOpen()) { 
        sem->p();
        //std::cout << name << "\n" ;
        ghost_array[id]->run();
            //Thread::yield();
        sem->v();
        }
        ghost_threads[id]->thread_exit(id);        
        
    }
    
    static void show_window() {
        window->setFramerateLimit(FPS);
        while(window->isOpen()) {
        sem->p();

        window_logic->run();
        //Thread::yield();
        //std::cout << "TAM_X: "<<window_logic->test_x << "\nTAM_Y: "
        //<< window_logic->test_y << "\n";
        sem->v();
        }
        window_thread->thread_exit(2);
       
    }

    static void Read_input() {
    db<Thread>(TRC) << "LENDO INPUT\n";
    
    bool pause = false;
    while(window->isOpen()) {
        
        sf::Event event;
        sem->p(); 
        if (window->pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                    window->close();
                    break;
            
            // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                    pacman->set_direction(pacman->LEFT);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    pacman->set_direction(pacman->RIGHT);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    pacman->set_direction(pacman->DOWN);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    pacman->set_direction(pacman->UP);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    window->close();
                } else if(event.type == sf::Event::KeyPressed && event.key.code == (sf::Keyboard::P)) {
                    std::cout << "PAUSE";
                    pause = true;
                    while(pause){
                        window->waitEvent(event);
                        if (event.type == sf::Event::KeyPressed && event.key.code == (sf::Keyboard::P)){
                            pause = false;
                        }
                                
                    }
                 
                }
                break;
            }
            sem->v();
        } else {
            sem->v();
        }
        }
        window_thread->thread_exit(2);
    }

    private:
        static sf::RenderWindow *window;
        static Window *window_logic;
        static Pacman *pacman;
        static Ghost  *ghost_array[4];
        static Thread *ghost_threads[4];
        static Thread *pacman_thread;
        static Thread *window_thread;
        static Thread *input_thread;
        static Semaphore *sem;
};

__END_API

#endif
