#ifndef STATE_HPP
#define STATE_HPP


class State {
public:
    virtual ~State() { }
    virtual void init() = 0;
    
    virtual void handleInput();
    virtual void update(float dt);
    virtual void Draw(float dt);

    virtual void pause() { }
    virtual void resume() { }
};


#endif // STATE_HPP
