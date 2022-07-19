#ifndef AGENT_H
#define AGENT_H
class Agent {

    public:
        virtual void run()=0;
        typedef enum {LEFT,UP,RIGHT,DOWN} direction;
        void return_to_old_pos(){_x=_old_x;_y=_old_y;}
        void set_old_pos(){_old_x=_x;_old_y=_y;}
        const float x(){return _x;}
        const float y(){return _y;}
        void teleport(){
            if(_x/16 > 2){
                _x = 17;
            } else {
                _x = 16*26;
            }
        }


    protected:
        float _old_x;
        float _old_y;
        float _x;
        float _y;
        float speed{1};



};

#endif