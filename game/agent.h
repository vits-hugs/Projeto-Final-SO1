#ifndef AGENT_H
#define AGENT_H
class Agent {

    public:
        virtual void run()=0;
        const float x(){return _x;}
        const float y(){return _y;}

    protected:
        float _x;
        float _y;
        float speed{1};


};

#endif