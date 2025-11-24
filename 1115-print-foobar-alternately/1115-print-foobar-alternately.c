typedef struct {
    int n;
    sem_t sem1;
    sem_t sem2;
} FooBar;

// Function declarations. Do not change or remove this line
void printFoo();
void printBar();

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->sem1, 0, 1);
    sem_init(&obj->sem2, 0, 0);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->sem1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        sem_post(&obj->sem2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->sem2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        sem_post(&obj->sem1);
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&obj->sem1);
    sem_destroy(&obj->sem2);
}