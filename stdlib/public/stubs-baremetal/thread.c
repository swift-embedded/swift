#include <pthread.h>
#include <stdlib.h>
#include <errno.h>


//
// pthread condition
//

int pthread_cond_init(pthread_cond_t *restrict cond,
                      const pthread_condattr_t *restrict attr) {
    return 0;
}

int pthread_cond_destroy(pthread_cond_t *cond) {
    return 0;
}

int pthread_cond_wait(pthread_cond_t *restrict cond,
                      pthread_mutex_t *restrict mutex) {
    return 0;
}

int pthread_cond_signal(pthread_cond_t *cond) {
    return 0;
}

int pthread_cond_broadcast(pthread_cond_t *cond) {
    return 0;
}

//
// pthread getspecific
//

struct pthread_specific_entry_t;

struct pthread_specific_entry_t {
    pthread_key_t key;
    const void* value;
    void (*destructor)(void*);
    struct pthread_specific_entry_t* next;
};

static pthread_key_t specific_next_key = 0;
static struct pthread_specific_entry_t* specific_first = NULL;


int pthread_key_create(pthread_key_t *key, void (*destructor)(void*)) {
    struct pthread_specific_entry_t* entry = malloc(sizeof(struct pthread_specific_entry_t));
    entry->key = specific_next_key++;
    entry->destructor = destructor;
    entry->value = NULL;
    entry->next = NULL;

    struct pthread_specific_entry_t** last = &specific_first;
    while (*last != NULL) {
        last = &((*last)->next);
    }
    *last = entry;
    *key = entry->key;
    return 0;
}

void* pthread_getspecific(pthread_key_t key) {
    struct pthread_specific_entry_t* current = specific_first;
    while (current) {
        if (current->key == key) {
            return current->value;
        }
    }
    return NULL;
}

int pthread_setspecific(pthread_key_t key, const void *value) {
    struct pthread_specific_entry_t* current = specific_first;
    while (current) {
        if (current->key == key) {
            current->value = value;
            return 0;
        }
    }
    return EINVAL;
}

//
// pthread mutex
//

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
                       const pthread_mutexattr_t *restrict attr) {
    return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex) {
    return 0;
}

int pthread_mutex_lock(pthread_mutex_t *mutex) {
    return 0;
}

int pthread_mutex_trylock(pthread_mutex_t *mutex) {
    return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *mutex) {
    return 0;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t *attr) {
    return 0;
}

int pthread_mutexattr_init(pthread_mutexattr_t *attr) {
    return 0;
}

int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type) {
    return 0;
}

//
// pthread rwlock
//

int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
                        const pthread_rwlockattr_t *restrict attr) {
    return 0;
}

int pthread_rwlock_destroy(pthread_rwlock_t *rwlock) {
    return 0;
}

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock) {
    return 0;
}

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock) {
    return 0;
}

int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock) {
    return 0;
}

int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock) {
    return 0;
}

int pthread_rwlock_unlock(pthread_rwlock_t *rwlock) {
    return 0;
}
