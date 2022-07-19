#include "window.h"
#define PILL_NUMBER 244
#define FPS 20
Window::tile Window::maze[28][31] =
        {
                {W,W,W,W,W,W,W,W,W,W,W,W,u,u,u,W,P,W,u,u,u,W,W,W,W,W,W,W,W,W,W},
                {W,o,o,o,o,W,W,O,o,o,o,W,u,u,u,W,u,W,u,u,u,W,o,o,o,o,O,o,o,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,W,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,u,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
                {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
                {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,W,W,o,u,u,u,u,u,u,u,u,u,W,W,o,o,o,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,W,W,W,W,u,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,u,u,u,W,u,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,o,o,o,W,W,o,o,o,o,W,W,u,W,u,u,u,W,u,u,u,o,W,W,o,o,o,o,o,W},
                {W,o,W,W,W,W,W,u,W,W,W,W,W,u,W,u,u,u,G,u,W,W,W,W,W,o,W,W,W,W,W},
                {W,o,W,W,W,W,W,u,W,W,W,W,W,u,W,u,u,u,G,u,W,W,W,W,W,o,W,W,W,W,W},
                {W,o,o,o,o,W,W,o,o,o,o,W,W,u,W,u,u,u,W,u,u,u,o,W,W,o,o,o,o,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,u,u,u,W,u,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,W,u,W,W,W,W,W,u,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,W,W,o,u,u,u,u,u,u,u,u,u,W,W,o,o,o,o,W,W,W,o,W},
                {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
                {W,o,W,W,W,W,W,o,W,W,o,W,W,W,W,W,u,W,W,W,W,W,W,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,W},
                {W,o,W,W,o,W,W,W,W,W,o,W,W,W,W,W,u,W,W,W,W,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,W,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,o,o,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,W,W,o,W,W,o,W,W,o,W,u,u,u,W,u,W,u,u,u,W,o,W,W,o,W,W,W,o,W},
                {W,o,o,o,o,W,W,O,o,o,o,W,u,u,u,W,u,W,u,u,u,W,o,o,o,o,O,o,o,o,W},
                {W,W,W,W,W,W,W,W,W,W,W,W,u,u,u,W,P,W,u,u,u,W,W,W,W,W,W,W,W,W,W}    
        };

            

/**
 * Tile defined as an enum where each type is defined as:
 *      W: Wall
 *      G: Ghost Pen Gate
 *      P: Portal
 *      u: Empty path
 *      o: Pill
 *      e: Eaten Pill
 *      O: Big Pill
 *      E: Eaten Big Pill
 */



// 2D array defines the size of the maze and also what each tile contains


Window::Window(sf::RenderWindow* window,Pacman* pacman,Ghost* ghost_array[])
{
    this->pacman = pacman; 
    this->window = window;
    pill_counter = PILL_NUMBER;
   // std::cout << "GHOST_ARRAY:" << ghost_array;
   //this->ghost_array[0] = ghost_array;
    for (size_t i = 0; i < 4; i++)
    {
        this->ghost_array[i] = ghost_array[i];
    }
    
    load_and_bind_textures();
    sf::Sprite pacman_sprites[3]={pac_0_sprite,pac_1_sprite,pac_2_sprite};
    number_sprites[0] = num_0_sprite;
    number_sprites[1] = num_1_sprite;
    number_sprites[2] = num_2_sprite;
    number_sprites[3] = num_3_sprite;
    number_sprites[4] = num_4_sprite;
    number_sprites[5] = num_5_sprite;
    number_sprites[6] = num_6_sprite;
    number_sprites[7] = num_7_sprite;
    number_sprites[8] = num_8_sprite;
    number_sprites[9] = num_9_sprite;
}

void Window::run(sf::Clock& clock)
{
    
    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
 
    std::cout << "Window RUN \n";
    window->clear();
    window->draw(maze_sprite);
    draw_objects_on_maze();
    //draw_board_testing();
    draw_pacman();
    draw_all_ghosts();
    draw_score();
    window->display();

    counter = (int)clock.getElapsedTime().asMilliseconds();
}

void Window::draw_sprite(sf::Sprite& sprite, int x, int y) {
    //center_sprite_origin(sprite);
    sprite.setPosition(x,y);
    window->draw(sprite);
}

void Window::draw_sprite_and_rotate(sf::Sprite& sprite, int x, int y, float angle)
{
    center_sprite_origin(sprite);
    sprite.setRotation(angle);
    draw_sprite(sprite,x,y);
}


void Window::center_sprite_origin(sf::Sprite& sprite) {
    sf::FloatRect rect= sprite.getLocalBounds();
    sprite.setOrigin(sf::Vector2f(rect.width/2,rect.height/2));
    test_x = rect.width;
    test_y = rect.height;
}

void Window::draw_pacman() {
    pacman_collision();
    switch (counter%3)
    {
    case 0:
        draw_sprite_and_rotate(pac_0_sprite,pacman->x(),pacman->y(),pacman->get_direction()*90);
        break;
    case 1:
        draw_sprite_and_rotate(pac_1_sprite,pacman->x(),pacman->y(),pacman->get_direction()*90);
        break;
    case 2:
        draw_sprite_and_rotate(pac_2_sprite,pacman->x(),pacman->y(),pacman->get_direction()*90);
        break;
    
    default:
        break;
    }
    //if (verify_colision_with_tile(W)) {
    // 
    //    pacman->return_old_pos();
    //    ghost_scared_0_sprite.setPosition(pacman->x(),pacman->y());
    //     window->draw(ghost_scared_0_sprite);
    //}
    //agent_collision(pacman);
}


bool Window::verify_colision_with_tile(Window::tile tile) {
    int pacman_x = (int)pacman->x();
    int pacman_y = (int)pacman->y();
    return maze[pacman_x/16][pacman_y/16] == tile;
}

sf::Vector2i Window::get_pos_matriz(Agent* agent) {
    return sf::Vector2i((int)agent->x()/16,(int)agent->y()/16);
}

void Window::pacman_collision() {
    pacman->verify_super(counter);
    sf::Vector2i agent_maze = get_pos_matriz(pacman);
    for(auto ghost:ghost_array){

        if(agent_maze.x==ghost->tile_old_x() && agent_maze.y==ghost->tile_old_y()) {
            if(pacman->is_super()) {
                ghost->kill(counter,rand()%7+1);
                increase_score("200");
            } else {
            if (!pacman->damage(counter,FPS)) lose();
            }
        }

    }
    switch (maze[agent_maze.x][agent_maze.y])
    {
    case W:
        pacman->return_to_old_pos();     
        break;   
    case o:
        maze[agent_maze.x][agent_maze.y] = e;
        pill_counter--;
        increase_score("10");
        verify_win();
        break;
    case O:
        maze[agent_maze.x][agent_maze.y] = E;
        pill_counter--;
        increase_score("10");
        verify_win();
        pacman->go_power(counter);
        break;
    case P:
        pacman->teleport();
        break;  
    default:
        break;
    }
}

void Window::agent_collision(Agent* agent) {
    sf::Vector2i agent_maze = get_pos_matriz(agent);
    switch (maze[agent_maze.x][agent_maze.y])
    {
    case W:
        agent->return_to_old_pos();     
        break;   
    case P:
        agent->teleport();
        //maze[agent_maze.x][agent_maze.y] = e;
        break;
    }

}
void Window::draw_object(sf::Sprite& sprite,int x,int y) {
        sprite.setPosition(x*16,y*16);
        window->draw(sprite);
}


void Window::draw_objects_on_maze() {
    for (int x = 0; x < 28; x++)
    {
        for (int y = 0; y < 31; y++)
        {
           switch (maze[x][y])
           {
            case o:
                draw_object(pill_sprite,x,y);
                break;
            case O:
                draw_object(bigPill_sprite,x,y);
                break;
           default:
            break;
           }
        }
    }
        
}

void Window::draw_board_testing() {
    
    for (int x = 0; x < 28; x++)
    {
        for (int y = 0; y < 31; y++)
        {
            if(maze[x][y]==W){
            ghost_p_0_sprite.setPosition(x*16,y*16);
            window->draw(ghost_p_0_sprite);
            }
        }
        
    }
    


}
//GHOSTS

void Window::draw_ghost(int ghost_id) {
    auto ghost = ghost_array[ghost_id];
    ghost->try_ressurection(counter);
    if(pacman->is_super()){
        switch (counter%3)
        {
        case 0:
            draw_sprite(ghost_scared_0_sprite,ghost->x(),ghost->y());
            break;
        case 1:
            draw_sprite(ghost_scared_1_sprite,ghost->x(),ghost->y());
            break;
        case 2:
            draw_sprite(ghost_scared_2_sprite,ghost->x(),ghost->y());
            break;
        default:
            break;
        }
    
    } else {
        switch (ghost_id)
        {
        case 0:
            if (counter%2==0) {draw_sprite(ghost_r_0_sprite,ghost->x(),ghost->y());}
            else {draw_sprite(ghost_r_1_sprite,ghost->x(),ghost->y());}
            break;

        case 1:
            if (counter%2==0) {draw_sprite(ghost_p_0_sprite,ghost->x(),ghost->y());}
            else {draw_sprite(ghost_p_1_sprite,ghost->x(),ghost->y());}
            break;
        case 2:
            if (counter%2==0) {draw_sprite(ghost_y_0_sprite,ghost->x(),ghost->y());}
            else {draw_sprite(ghost_y_1_sprite,ghost->x(),ghost->y());}
            break;
        case 3:
            if (counter%2==0) {draw_sprite(ghost_b_0_sprite,ghost->x(),ghost->y());}
            else {draw_sprite(ghost_b_1_sprite,ghost->x(),ghost->y());}
            break;
        default:
            break;
        }
    }
    inform_ghost(ghost);
    agent_collision(ghost);
}

void Window::draw_all_ghosts() {
    for (int i = 0; i < 4; i++)
    {
        draw_ghost(i);
    }



}

void Window::inform_ghost(Ghost *ghost) {
    sf::Vector2i ghost_pos = get_pos_matriz(ghost);
    ghost->center_me(ghost_pos.x,ghost_pos.y);
    if (ghost_pos.x!=ghost->tile_old_x() || ghost_pos.y!=ghost->tile_old_y()){
    ghost->set_tile_old(ghost_pos.x,ghost_pos.y);
    for(bool& x:ghost->possibles) {
        x = false;
    }
    if(maze[ghost_pos.x-1][ghost_pos.y] != W  && (ghost->get_direction()!=Agent::RIGHT)){
        ghost->possibles[0] = true; 
    } 
    if(maze[ghost_pos.x][ghost_pos.y+1] != W && (ghost->get_direction()!=Agent::UP)) {
        ghost->possibles[3] = true; 
        
    }
    if(maze[ghost_pos.x][ghost_pos.y-1] != W && (ghost->get_direction()!=Agent::DOWN)) {
        ghost->possibles[1] = true; 
        
    }
    if(maze[ghost_pos.x+1][ghost_pos.y] != W && (ghost->get_direction()!=Agent::LEFT)){
        ghost->possibles[2] = true;
        
    }
    }
    
    Ghost::send_pac_cord(pacman->x(),pacman->y());
}

void Window::verify_win() {
    if(!pill_counter) {
        std::cout << "WINNNNNNNNN\n";
        draw_sprite(score_1600_sprite,window->getSize().x/2-5,window->getSize().y/2);
        window->display();
        sf::Event event;
        while(window->waitEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                break;
            }
        }
    }

}

void Window::lose() {
    std::cout << "LOSEEEEE\n";
    draw_sprite(gameover_sprite, window->getSize().x/2-65, window->getSize().y/2);
    window->display();
    sf::Event event;
    while(window->waitEvent(event)) {
        if(event.type == sf::Event::Closed) window->close();
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) break;
                
     
    }
    

}

void Window::draw_score() {
    draw_sprite(score_sprite,0,0);
    for (int i = 0; i < 8; i++)
    {
        draw_sprite(number_sprites[num[7-i]],48+i*16,0);
    }
    

}

void Window::increase_score(const char* points) {
    int index = -2;
    for (size_t i = 0; i < 5; i++)
    {
        index++;
        if(points[i]=='\0'){
            break;
        }
    }
    int soma = num[index]+points[0]-'0';
    
    while (soma>=10) {
        num[index]=soma-9;
        index++;
        soma = num[index]+1;
    }
    if(soma<10) {
        num[index]=soma;
    }
     std::cout << "num: ";
    for (int x:num)
    {
        std::cout << x << ", "; 
    }
    
    std::cout << std::endl;

}

void Window::load_and_bind_textures()
{
    unsigned int counter{0};
    sf::RenderWindow* window;
    // Bind map textures    
    maze_tex.loadFromFile("sprites/maze/maze.png");
    maze_sprite.setTexture(maze_tex);
    center_sprite_origin(maze_sprite);
    maze_sprite.scale(2,-2);
    maze_sprite.setPosition(16*14,16*15.5);//REFATORAR
    //maze_sprite.setRotation(180);
    pill_tex.loadFromFile("sprites/maze/p-0.png");
    pill_sprite.setTexture(pill_tex);
    bigPill_tex.loadFromFile("sprites/maze/p-1.png");
    bigPill_sprite.setTexture(bigPill_tex);

    // Bind Pacman textures
    pac_0_tex.loadFromFile("sprites/pacman/0.png");
    pac_0_sprite.setTexture(pac_0_tex);
    pac_1_tex.loadFromFile("sprites/pacman/1.png");
    pac_1_sprite.setTexture(pac_1_tex);
    pac_2_tex.loadFromFile("sprites/pacman/2.png");
    pac_2_sprite.setTexture(pac_2_tex);
    dead_0_tex.loadFromFile("sprites/pacman/d-0.png");
    dead_0_sprite.setTexture(dead_0_tex);
    dead_1_tex.loadFromFile("sprites/pacman/d-1.png");
    dead_1_sprite.setTexture(dead_1_tex);
    dead_2_tex.loadFromFile("sprites/pacman/d-2.png");
    dead_2_sprite.setTexture(dead_2_tex);
    dead_3_tex.loadFromFile("sprites/pacman/d-3.png");
    dead_3_sprite.setTexture(dead_3_tex);
    dead_4_tex.loadFromFile("sprites/pacman/d-4.png");
    dead_4_sprite.setTexture(dead_4_tex);
    dead_5_tex.loadFromFile("sprites/pacman/d-5.png");
    dead_5_sprite.setTexture(dead_5_tex);
    dead_6_tex.loadFromFile("sprites/pacman/d-6.png");
    dead_6_sprite.setTexture(dead_6_tex);
    dead_7_tex.loadFromFile("sprites/pacman/d-7.png");
    dead_7_sprite.setTexture(dead_7_tex);
    dead_8_tex.loadFromFile("sprites/pacman/d-8.png");
    dead_8_sprite.setTexture(dead_8_tex);
    dead_9_tex.loadFromFile("sprites/pacman/d-9.png");
    dead_9_sprite.setTexture(dead_9_tex);
    dead_10_tex.loadFromFile("sprites/pacman/d-10.png");
    dead_10_sprite.setTexture(dead_10_tex);

    // Bind ghost textures
    ghost_r_0_tex.loadFromFile("sprites/ghosts/r-0.png");
    ghost_r_0_sprite.setTexture(ghost_r_0_tex);
    ghost_r_1_tex.loadFromFile("sprites/ghosts/r-1.png");
    ghost_r_1_sprite.setTexture(ghost_r_1_tex);
    ghost_p_0_tex.loadFromFile("sprites/ghosts/p-0.png");
    ghost_p_0_sprite.setTexture(ghost_p_0_tex);
    ghost_p_1_tex.loadFromFile("sprites/ghosts/p-1.png");
    ghost_p_1_sprite.setTexture(ghost_p_1_tex);
    ghost_b_0_tex.loadFromFile("sprites/ghosts/b-0.png");
    ghost_b_0_sprite.setTexture(ghost_b_0_tex);
    ghost_b_1_tex.loadFromFile("sprites/ghosts/b-1.png");
    ghost_b_1_sprite.setTexture(ghost_b_1_tex);
    ghost_y_0_tex.loadFromFile("sprites/ghosts/y-0.png");
    ghost_y_0_sprite.setTexture(ghost_y_0_tex);
    ghost_y_1_tex.loadFromFile("sprites/ghosts/y-1.png");
    ghost_y_1_sprite.setTexture(ghost_y_1_tex);
    ghost_scared_0_tex.loadFromFile("sprites/ghosts/s-0.png");
    ghost_scared_0_sprite.setTexture(ghost_scared_0_tex);
    ghost_scared_1_tex.loadFromFile("sprites/ghosts/s-1.png");
    ghost_scared_1_sprite.setTexture(ghost_scared_1_tex);
    ghost_scared_2_tex.loadFromFile("sprites/ghosts/s-2.png");
    ghost_scared_2_sprite.setTexture(ghost_scared_2_tex);
    ghost_scared_3_tex.loadFromFile("sprites/ghosts/s-3.png");
    ghost_scared_3_sprite.setTexture(ghost_scared_3_tex);

     // Bind ghost eye textures
    eye_up_tex.loadFromFile("sprites/eyes/up.png");
    eye_up_sprite.setTexture(eye_up_tex);
    eye_right_tex.loadFromFile("sprites/eyes/right.png");
    eye_right_sprite.setTexture(eye_right_tex);
    eye_down_tex.loadFromFile("sprites/eyes/down.png");
    eye_down_sprite.setTexture(eye_down_tex);
    eye_left_tex.loadFromFile("sprites/eyes/left.png");
    eye_left_sprite.setTexture(eye_left_tex);

    // Bind UI textures
    num_0_tex.loadFromFile("sprites/ui/0.png");
    num_0_sprite.setTexture(num_0_tex);
    num_1_tex.loadFromFile("sprites/ui/1.png");
    num_1_sprite.setTexture(num_1_tex);
    num_2_tex.loadFromFile("sprites/ui/2.png");
    num_2_sprite.setTexture(num_2_tex);
    num_3_tex.loadFromFile("sprites/ui/3.png");
    num_3_sprite.setTexture(num_3_tex);
    num_4_tex.loadFromFile("sprites/ui/4.png");
    num_4_sprite.setTexture(num_4_tex);
    num_5_tex.loadFromFile("sprites/ui/5.png");
    num_5_sprite.setTexture(num_5_tex);
    num_6_tex.loadFromFile("sprites/ui/6.png");
    num_6_sprite.setTexture(num_6_tex);
    num_7_tex.loadFromFile("sprites/ui/7.png");
    num_7_sprite.setTexture(num_7_tex);
    num_8_tex.loadFromFile("sprites/ui/8.png");
    num_8_sprite.setTexture(num_8_tex);
    num_9_tex.loadFromFile("sprites/ui/9.png");
    num_9_sprite.setTexture(num_9_tex);
    score_200_tex.loadFromFile("sprites/ui/200.png");
    score_200_sprite.setTexture(score_200_tex);
    score_400_tex.loadFromFile("sprites/ui/400.png");
    score_400_sprite.setTexture(score_400_tex);
    score_800_tex.loadFromFile("sprites/ui/800.png");
    score_800_sprite.setTexture(score_800_tex);
    score_1600_tex.loadFromFile("sprites/ui/1600.png");
    score_1600_sprite.setTexture(score_1600_tex);
    ready_tex.loadFromFile("sprites/ui/ready.png");
    ready_sprite.setTexture(ready_tex);
    gameover_tex.loadFromFile("sprites/ui/gameover.png");
    gameover_sprite.setTexture(gameover_tex);
    life_tex.loadFromFile("sprites/ui/life.png");
    life_sprite.setTexture(life_tex);
    score_tex.loadFromFile("sprites/ui/score_tex.png");
    score_sprite.setTexture(score_tex);
    high_tex.loadFromFile("sprites/ui/high.png");
    high_sprite.setTexture(high_tex);
    score_100_tex.loadFromFile("sprites/ui/100.png");
    score_100_sprite.setTexture(score_100_tex);
    score_300_tex.loadFromFile("sprites/ui/300.png");
    score_300_sprite.setTexture(score_300_tex);

    // Fruit textures
    cherry_tex.loadFromFile("sprites/fruits/cherry.png");
    cherry_sprite.setTexture(cherry_tex);
    strawberry_tex.loadFromFile("sprites/fruits/strawberry.png");
    strawberry_sprite.setTexture(strawberry_tex);
}
