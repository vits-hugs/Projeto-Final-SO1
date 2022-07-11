#ifndef main_class_h
#define main_class_h

#include <iostream>
#include "cpu.h"
#include "traits.h"
#include "thread.h"
#include "semaphore.h"

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
        
    }

    ~Main() {}

private:

    static const int ITERATIONS = 10;

    static void run_ghost(char *name,int id) {
             int i ;

        std::cout << name << ": inicio\n";

        sem->p();
        for (i = 0; i < ITERATIONS; i++)
        {
            std::cout << name << ": " << i << "\n" ;
            Thread::yield();
        }
        sem->v();
        std::cout << name << ": fim\n";


        ghost_threads[id]->thread_exit(id);        

    }

    private:
        static Thread *ghost_threads[4];
        static Semaphore *sem;
};

__END_API

#endif