#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int n;
char production[10][10], follow[10][10], first[10][10], nonTerminal[10];
int first_count[10][2], follow_count[10][2], count_nt = 0;

void addnonterminal(char c) {
    for(int i = 0; i < count_nt; i++)
        if(nonTerminal[i] == c)
            return;
    nonTerminal[count_nt++] = c;
}

int getIndex(char c) {
    for(int i = 0; i < count_nt; i++)
        if(nonTerminal[i] == c)
            return i;
    return -1;
}

void add_to_first(int index, char symbol) {
    for(int i = 0; i < first_count[index][0]; i++)
        if(symbol == first[index][i])
            return;
    first[index][first_count[index][0]++] = symbol;
}

void add_to_follow(int index, char symbol) {
    for(int i = 0; i < follow_count[index][0]; i++)
        if(symbol == follow[index][i])
            return;
    follow[index][follow_count[index][0]++] = symbol;
}

void First(char P) {
    int charindex = getIndex(P);
    if(first_count[charindex][1] == 1)
        return;
    first_count[charindex][1] = 1;

    for(int i = 0; i < n; i++) {
        if(P == production[i][0]) {
            int m = 3, all_epsilon = 1;
            while(m < strlen(production[i])) {
                char symbol = production[i][m];
                if(!isupper(symbol) || symbol == '$') {
                    add_to_first(charindex, symbol);
                    if(symbol != '$') { all_epsilon = 0; break; }
                } else {
                    int symindex = getIndex(symbol);
                    if(first_count[symindex][1] == 0)
                        First(symbol);
                    int has_epsilon = 0;
                    for(int k = 0; k < first_count[symindex][0]; k++) {
                        if(first[symindex][k] != '$')
                            add_to_first(charindex, first[symindex][k]);
                        else
                            has_epsilon = 1;
                    }
                    if(!has_epsilon) { all_epsilon = 0; break; }
                }
                m++;
            }
            if(all_epsilon && m >= strlen(production[i]))
                add_to_first(charindex, '$');
        }
    }
}

void Follow(char P) {
    int index = getIndex(P);
    if(follow_count[index][1] == 1)
        return;
    follow_count[index][1] = 1;

    if(index == 0)
        add_to_follow(index, '$');

    for(int i = 0; i < n; i++) {
        for(int j = 3; j < strlen(production[i]); j++) {
            if(production[i][j] == P) {
                int k = j + 1;
                int curr_nt = getIndex(production[i][0]);
                int has_epsilon = 0;

                if(k < strlen(production[i])) {
                    char next = production[i][k];
                    if(!isupper(next)) {
                        if(next != '$')
                            add_to_follow(index, next);
                        else
                            has_epsilon = 1;
                    } else {
                        int nextindex = getIndex(next);
                        for(int a = 0; a < first_count[nextindex][0]; a++) {
                            if(first[nextindex][a] != '$')
                                add_to_follow(index, first[nextindex][a]);
                            else
                                has_epsilon = 1;
                        }
                    }
                    if(has_epsilon)
                        for(int a = 0; a < follow_count[curr_nt][0]; a++)
                            add_to_follow(index, follow[curr_nt][a]);
                } else {
                    for(int a = 0; a < follow_count[curr_nt][0]; a++)
                        add_to_follow(index, follow[curr_nt][a]);
                    Follow(production[i][0]);
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (X->abc):\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", production[i]);
        addnonterminal(production[i][0]);
    }

    for(int i = 0; i < count_nt; i++) {
        first_count[i][0] = follow_count[i][0] = 0;
        first_count[i][1] = follow_count[i][1] = 0;
    }

    for(int i = 0; i < count_nt; i++)
        if(first_count[getIndex(nonTerminal[i])][1] == 0)
            First(nonTerminal[i]);

    for(int i = 0; i < count_nt; i++)
        Follow(nonTerminal[i]);

    printf("\nFIRST sets:\n");
    for(int i = 0; i < count_nt; i++) {
        printf("FIRST(%c) = { ", nonTerminal[i]);
        for(int j = 0; j < first_count[i][0]; j++) {
            printf("%c", first[i][j]);
            if(j < first_count[i][0] - 1) printf(", ");
        }
        printf(" }\n");
    }

    printf("\nFOLLOW sets:\n");
    for(int i = 0; i < count_nt; i++) {
        printf("FOLLOW(%c) = { ", nonTerminal[i]);
        for(int j = 0; j < follow_count[i][0]; j++) {
            printf("%c", follow[i][j]);
            if(j < follow_count[i][0] - 1) printf(", ");
        }
        printf(" }\n");
    }

    return 0;
}

