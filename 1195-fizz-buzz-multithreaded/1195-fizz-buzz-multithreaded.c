typedef struct {
    int n;
} FizzBuzz;

int counter;
pthread_mutex_t lock;
pthread_cond_t cond;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    counter = 1;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
    return obj;
}

// Don't change the following declarations
void printNumber(int a);
void printFizz();
void printBuzz();
void printFizzBuzz();

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    while(counter <= obj->n) {
        pthread_mutex_lock(&lock);
        while(counter <= obj->n && (counter%3 != 0 || counter%5 == 0))
            pthread_cond_wait(&cond, &lock);
        if(counter <= obj->n) {
            printFizz();
            counter++;
        }
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    while(counter <= obj->n) {
        pthread_mutex_lock(&lock);
        while(counter <= obj->n && (counter%3 == 0 || counter%5 != 0))
            pthread_cond_wait(&cond, &lock);
        if(counter <= obj->n) {
            printBuzz();
            counter++;
        }
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    while(counter <= obj->n) {
        pthread_mutex_lock(&lock);
        while(counter <= obj->n && (counter%3 != 0 || counter%5 != 0))
            pthread_cond_wait(&cond, &lock);
        if(counter <= obj->n) {
            printFizzBuzz();
            counter++;
        }
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    while(counter <= obj->n) {
        pthread_mutex_lock(&lock);
        while(counter <= obj->n && (counter%3 == 0 || counter%5 == 0))
            pthread_cond_wait(&cond, &lock);
        if(counter <= obj->n)
            printNumber(counter++);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
}

void fizzBuzzFree(FizzBuzz* obj) {
    free(obj);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}