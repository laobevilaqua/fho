#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TEAM {
    int number;
    int points;
    int scored;
    int received;
    int entries;
};

int compare(const void *p1, const void *p2);

int main()
{
    int instance = 0;
    int first = 1;

    while (1) {
        int n;
        int t1, t2, score1, score2;
        int i, matches;
        struct TEAM teams[101];

        memset(teams, 0, sizeof(teams));

        scanf("%d", &n);
        if (!n)
            break;

        for (i = 0; i <= n; ++i)
            teams[i].number = i;

        matches = n * (n - 1) / 2;
        for (i = 0; i < matches; ++i) {
            scanf("%d%d%d%d", &t1, &score1, &t2, &score2);

            teams[t1].scored += score1;
            teams[t1].received += score2;
            teams[t1].entries += 1;

            teams[t2].scored += score2;
            teams[t2].received += score1;
            teams[t2].entries += 1;

            if (score1 > score2) {
                teams[t1].points += 2;
                teams[t2].points += 1;
            } else {
                teams[t1].points += 1;
                teams[t2].points += 2;
            }
        }

        qsort(teams, 101, sizeof(struct TEAM), compare);

        if (!first)
            putchar('\n');
        first = 0;

        printf("Instancia %d\n%d", ++instance, teams[0].number);
        for (i = 1; i < n; ++i)
            printf(" %d", teams[i].number);
        putchar('\n');
    }

    return 0;
}

int compare(const void *p1, const void *p2)
{
    const struct TEAM *t1 = (const struct TEAM *) p1;
    const struct TEAM *t2 = (const struct TEAM *) p2;

    if (t1->points == t2->points) {
        float avg1 = 0.0, avg2 = 0.0;

        if (t1->received)
            avg1 = (float) t1->scored / t1->received;
        else if (t1->entries)
            avg1 = (float) t1->scored / t1->entries;

        if (t2->received)
            avg2 = (float) t2->scored / t2->received;
        else if (t2->entries)
            avg2 = (float) t2->scored / t2->entries;

        if (avg1 > avg2)
            return -1;
        if (avg1 < avg2)
            return 1;

        if (t1->scored == t2->scored)
            return t1->entries - t2->entries;
        return t2->scored - t1->scored;
    }
    return t2->points - t1->points;
}
