#include <iostream>
#include <vector>

struct Transition {
    int currentState;
    int readValue;
    int writeValue;
    int moveDirection;
    int nextState;
};

int busyBeaver(int n) {
    if (n == 2) {
        std::vector<Transition> transitions = {
            {1, 0, 1, 1, 2},
            {1, 1, 1, -1, 2},
            {2, 0, 1, -1, 1},
            {2, 1, 1, 1, 3},
            {3, 0, 1, 1, 0},
            {3, 1, 1, -1, 3}
        };

        std::vector<int> tape(1000, 0); // Fita da máquina de Turing
        int head = tape.size() / 2; // Posição inicial da cabeça de leitura/escrita
        int state = 1; // Estado inicial da máquina de Turing
        int steps = 0; // Contador de etapas

        while (state != 0) {
            int currentValue = tape[head];
            for (const Transition& transition : transitions) {
                if (transition.currentState == state && transition.readValue == currentValue) {
                    tape[head] = transition.writeValue; // Escreve o novo valor na fita
                    head += transition.moveDirection; // Move a cabeça de leitura/escrita
                    state = transition.nextState; // Define o novo estado
                    break;
                }
            }
            steps++;
        }

        return steps;
    }

    // Caso o valor de "n" não esteja tratado, retorne -1 indicando que não foi possível calcular o Busy Beaver.
    return -1;
}

int main() {
    int n = 2; // Valor de "n" para calcular o Busy Beaver
    int result = busyBeaver(n);

    if (result != -1) {
        std::cout << "Busy Beaver(" << n << ") = " << result << std::endl;
    } else {
        std::cout << "Não foi possível calcular o Busy Beaver para n = " << n << "." << std::endl;
    }

    return 0;
}
