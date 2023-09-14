#include <bits/stdc++.h>
using namespace std;

class rover {
private:
    int x, y, z;
    char ans;
    char direction;

public:
    rover(int x_direction, int y_direction, int z_direction, char initial_direction) {
        x = x_direction;
        y = y_direction;
        z = z_direction;
        direction = initial_direction;
        ans=direction;
    }

    void forward() {
        if (ans == 'S') {
             y -= 1;
        } 
        else if (ans == 'N') {
            y += 1;
        } 
        else if (ans == 'E') {
            x += 1;
        } 
        else if (ans == 'W') {
            x -= 1;
        } 
        else if (ans == 'U') {
            z += 1;
        } 
        else if (ans == 'D') {
            z -= 1;
        }
    }

    void backward() {
        if (ans == 'N') {
            y -= 1;
        } 
        else if (ans == 'S') {
            y += 1;
        }
         else if (ans == 'E') {
            x -= 1;
        } 
        else if (ans == 'W') {
            x += 1;
        }
         else if (ans == 'U') {
            z -= 1;
        }
         else if (ans == 'D') {
            z += 1;
        }
    }

    void rotate_left() {
        if (direction == 'N') {
            direction = 'W';
             ans = 'W';
        } else if (direction == 'S') {
            direction = 'E';
               ans = 'E';
        } else if (direction == 'E') {
            direction = 'N';
            ans = 'N';
        } else if (direction == 'W') {
            direction = 'S';
              ans = 'S';
        }
       
    }

    void rotate_right() {
        if (direction == 'N') {
            direction = 'E';
              ans = 'E';
        } else if (direction == 'S') {
            direction = 'W';
            ans = 'W';
        } else if (direction == 'E') {
            direction = 'S';
            ans = 'S';
        } else if (direction == 'W') {
            direction = 'N';
            ans = 'N';
        }
    }

    void turn_up() {
        if (ans != 'U') {
            ans = 'U';
        }
    }

    void turn_down() {
        if (ans != 'D') {
            ans = 'D';
        }
    }

    void run_commands(const vector<char>& commands) {
        for (char command : commands) {
            if (command == 'f') {
                forward();
            }
             else if (command == 'b') {
                backward();
            } 
            else if (command == 'l') {
                rotate_left();
            } 
            else if (command == 'r') {
                rotate_right();
            } 
            else if (command == 'u') {
                turn_up();
            } 
            else if (command == 'd') {
                turn_down();
            }
        }
    }

    void print() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Final Direction: " << ans << endl;
    }
};

int main() {
    rover obj(0, 0, 0, 'N');
    vector<char> commands = {'f', 'r','u','b','l'};
    
    obj.run_commands(commands);
    obj.print();
    
    return 0;
}
