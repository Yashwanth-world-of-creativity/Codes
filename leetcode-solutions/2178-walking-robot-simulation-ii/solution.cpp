class Robot {
public:
    int w, h, perimeter;
    int pos;
    bool moved;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
        pos = 0;
        moved = false;
    }
    
    void step(int num) {
        if (perimeter == 0) return;
        pos = (pos + num) % perimeter;
        moved = true;
    }
    
    vector<int> getPos() {
        int p = pos;
        int x, y;

        if (p < w) {
            x = p;
            y = 0;
        } 
        else if (p < w + h - 1) {
            x = w - 1;
            y = p - (w - 1);
        } 
        else if (p < 2*w + h - 2) {
            x = (w - 1) - (p - (w + h - 2));
            y = h - 1;
        } 
        else {
            x = 0;
            y = (h - 1) - (p - (2*w + h - 3));
        }

        return {x, y};
    }
    
    string getDir() {
        if (pos == 0) {
            if (!moved) return "East";  // initial state
            return "South";             // completed cycle
        }

        if (pos < w) return "East";
        else if (pos < w + h - 1) return "North";
        else if (pos < 2*w + h - 2) return "West";
        else return "South";
    }
};
