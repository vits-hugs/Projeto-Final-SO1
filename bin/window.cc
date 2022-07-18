#include "window.h"

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
   // std::cout << "GHOST_ARRAY:" << ghost_array;
   //this->ghost_array[0] = ghost_array;
    for (size_t i = 0; i < 4; i++)
    {
        this->ghost_array[i] = ghost_array[i];
    }
    
    load_and_bind_textures();
    sf::Sprite pacman_sprites[3]={pac_0_sprite,pac_1_sprite,pac_2_sprite};
}

void Window::run()
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
    ghost_p_0_sprite.setPosition(245, 150);
    window->draw(ghost_p_0_sprite);
    window->display();

    counter++;
}

void Window::draw_sprite(sf::Sprite& sprite, int x, int y) {
    center_sprite_origin(sprite);
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
    //pacman_collision();
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
    agent_collision(pacman);
}


bool Window::verify_colision_with_tile(Window::tile tile) {
    int pacman_x = (int)pacman->x();
    int pacman_y = (int)pacman->y();
    return maze[pacman_x/16][pacman_y/16] == tile;
}

void Window::agent_collision(Agent* agent) {
    int agent_maze_x = (int)agent->x()/16;
    int agent_maze_y = (int)agent->y()/16;
    
    switch (maze[agent_maze_x][agent_maze_y])
    {
    case W:
        agent->return_to_old_pos();     
        break;   
    case o:
        maze[agent_maze_x][agent_maze_y] = e;
        break;
    case O:
        maze[agent_maze_x][agent_maze_y] = E;
    default:
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
            ghost_r_0_sprite.setPosition(x*16,y*16);
            window->draw(ghost_r_0_sprite);
            }
        }
        
    }
    


}
//GHOSTS

void Window::draw_ghost(int ghost_id) {
    auto ghost = ghost_array[ghost_id];
    std::cout << ghost;
    switch (ghost_id)
    {
    case 1:
        if (counter%2==0) {draw_sprite(ghost_r_0_sprite,ghost->x(),ghost->y());}
        else {draw_sprite(ghost_r_1_sprite,ghost->x(),ghost->y());}
        break;
    
    default:
        break;
    }

    agent_collision(ghost);
}
void Window::draw_all_ghosts() {
    for (int i = 0; i < 4; i++)
    {
        draw_ghost(i);
    }



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
