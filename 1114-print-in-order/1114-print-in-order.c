typedef struct {
    // User defined data may be declared here.
    sem_t sem1;
    sem_t sem2;
} Foo;

// Function Declaration, do not remove
void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    sem_init(&obj->sem1, 0, 0);
    sem_init(&obj->sem2, 0, 0);
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->sem1);
}

void second(Foo* obj) {
    sem_wait(&obj->sem1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->sem2);
}

void third(Foo* obj) {
    sem_wait(&obj->sem2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    sem_destroy(&obj->sem1);
    sem_destroy(&obj->sem2);
}