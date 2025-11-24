typedef struct {
    // User defined data may be declared here.
    sem_t ox;
    sem_t hy;
    pthread_mutex_t olock;
    pthread_mutex_t hlock;
    int o;
    int h;
} H2O;

void releaseHydrogen();

void releaseOxygen();

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    sem_init(&obj->ox, 0, 1);
    sem_init(&obj->hy, 0, 2);
    pthread_mutex_init(&obj->olock, 0);
    pthread_mutex_init(&obj->hlock, 0);
    obj->o = 0;
    obj->h = 0;
    return obj;
}

void hydrogen(H2O* obj) {
    sem_wait(&obj->hy);
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();

    pthread_mutex_lock(&obj->hlock);
    obj->h++;
    if(obj->h == 2){
        sem_post(&obj->ox);
        obj->h = 0;
    }
    pthread_mutex_unlock(&obj->hlock);
}

void oxygen(H2O* obj) {
    sem_wait(&obj->ox);
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();

    pthread_mutex_lock(&obj->olock);
    obj->o++;
    if(obj->o == 1){
        sem_post(&obj->hy);
        sem_post(&obj->hy);
        obj->o = 0;
    }
    pthread_mutex_unlock(&obj->olock);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    sem_destroy(&obj->ox);
    sem_destroy(&obj->hy);
    pthread_mutex_destroy(&obj->olock);
    pthread_mutex_destroy(&obj->hlock);
}