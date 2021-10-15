#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Persona
{
    char name[20];
    char arcana[20];
    int strength;
    int magic;
    int endurance;
    int agility;
    int luck;
};

void printPersona(const struct Persona *p)
{
    printf("You have awakened %s of the %s arcana\n", p->name, p->arcana);
    printf("strength: %d\n", p->strength);
    printf("magic: %d\n", p->magic);
    printf("endurance: %d\n", p->endurance);
    printf("agility: %d\n", p->agility);
    printf("luck: %d\n", p->luck);
}

struct Persona *createPersona(char *name, char *arcana, int strength, int magic, int endurance, int agility, int luck)
{
    struct Persona *p = malloc(sizeof(struct Persona));

    strcpy(p->name, name);
    strcpy(p->arcana, arcana);
    p->strength = strength;
    p->magic = magic;
    p->endurance = endurance;
    p->agility = agility;
    p->luck = luck;

    return p;
}

int main()
{
    srand(time(NULL));

    struct Persona *p = createPersona("Alice\0", "Death\0", 41, 82, 68, 75, (rand() % 100) + 1);
    printPersona(p);
    free(p);
}
