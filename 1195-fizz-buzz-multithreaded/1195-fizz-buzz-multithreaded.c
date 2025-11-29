typedef struct {
    int value;
    int rememberedValue;
    int generation;
    pthread_mutex_t barrierLock;
    pthread_cond_t barrierCond;
} barrier;

void barrierInit(barrier* br, int val){
    br->value = val;
    br->rememberedValue = val;
    br->generation = 0;
    pthread_mutex_init(&br->barrierLock, NULL);
    pthread_cond_init(&br->barrierCond, NULL);
}

void destroyBarrier(barrier* br){
    pthread_mutex_destroy(&br->barrierLock);
    pthread_cond_destroy(&br->barrierCond);
}

void barrierWait(barrier* br){
    pthread_mutex_lock(&br->barrierLock);
    br->value--;
    int gen = br->generation;
    if(br->value == 0){
        br->value = br->rememberedValue;
        br->generation++;
        pthread_cond_broadcast(&br->barrierCond);
    } else {
        while(br->generation == gen){
            pthread_cond_wait(&br->barrierCond, &br->barrierLock);
        }
    }
    pthread_mutex_unlock(&br->barrierLock);
}

typedef struct {
    int n;
    barrier br;
} FizzBuzz;

// Don't change the following declarations

void printNumber(int a);

void printFizz();

void printBuzz();

void printFizzBuzz();

int counter;
pthread_mutex_t lock;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    barrierInit(&obj->br, 4);
    counter = 1;
    pthread_mutex_init(&lock, NULL);
    return obj;
}

void fizz(FizzBuzz* obj) {
    while(true) {
        barrierWait(&obj->br);

        pthread_mutex_lock(&lock);
        if (counter > obj->n) {
            pthread_mutex_unlock(&lock);
            break;
        }
        bool act = (counter % 3 == 0 && counter % 5 != 0);
        pthread_mutex_unlock(&lock);

        barrierWait(&obj->br);

        if(act) {
            printFizz();
            pthread_mutex_lock(&lock);
            counter++;
            pthread_mutex_unlock(&lock);
        }
    }
}

void buzz(FizzBuzz* obj) {
    while(true) {
        barrierWait(&obj->br);

        pthread_mutex_lock(&lock);
        if (counter > obj->n) {
            pthread_mutex_unlock(&lock);
            break;
        }
        bool act = (counter % 3 != 0 && counter % 5 == 0);
        pthread_mutex_unlock(&lock);

        barrierWait(&obj->br);

        if(act) {
            printBuzz();
            pthread_mutex_lock(&lock);
            counter++;
            pthread_mutex_unlock(&lock);
        }
    }
}

void fizzbuzz(FizzBuzz* obj) {
    while(true) {
        barrierWait(&obj->br);

        pthread_mutex_lock(&lock);
        if (counter > obj->n) {
            pthread_mutex_unlock(&lock);
            break;
        }
        bool act = (counter % 3 == 0 && counter % 5 == 0);
        pthread_mutex_unlock(&lock);

        barrierWait(&obj->br);

        if(act) {
            printFizzBuzz();
            pthread_mutex_lock(&lock);
            counter++;
            pthread_mutex_unlock(&lock);
        }
    }
}

void number(FizzBuzz* obj) {
    while(true) {
        barrierWait(&obj->br);

        pthread_mutex_lock(&lock);
        if (counter > obj->n) {
            pthread_mutex_unlock(&lock);
            break;
        }
        bool act = (counter % 3 != 0 && counter % 5 != 0);
        pthread_mutex_unlock(&lock);

        barrierWait(&obj->br);

        if(act) {
            printNumber(counter);
            pthread_mutex_lock(&lock);
            counter++;
            pthread_mutex_unlock(&lock);
        }
    }
}

void fizzBuzzFree(FizzBuzz* obj) {
    destroyBarrier(&obj->br);
    pthread_mutex_destroy(&lock);
    free(obj);
}