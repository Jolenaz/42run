#pragma once

class SceneManager{

    public:
    SceneManager(bool isDemo);
    SceneManager(void);
    virtual ~SceneManager(void);

    private:
    SceneManager(SceneManager const &);
    SceneManager & operator=(SceneManager const &);

};
