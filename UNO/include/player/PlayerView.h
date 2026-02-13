#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H
class Player;

class PlayerView
{
private:
    Player* player;
    
public:
    PlayerView(Player* player);
    ~PlayerView();
    void viewCards(bool isFlip);
    int actionsMenu();
    int selectCard();
    bool askContinueDraw();
};

#endif