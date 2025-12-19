
#include <fstream>
#include "Dinic.h"
#include "Problem2.h"
#include "Problem1.h"
using namespace std;
int main()
{

    // int n, m;
    // cin >> n >> m;

    // Graph g(n);

    // for (int i = 0; i < m; i++) {
    //     int u, v, c;
    //     cin >> u >> v >> c;
    //     g.addEdge(u, v, c);
    // }
    // //  cout<<"output"<<endl;
    // //  auto &adj = g.getAdj();
    // // for (int i = 0; i < adj.size();i++) {
    // //    for(int j = 0; j < adj[i].size();j++ ){
    // //     cout<<adj[i][j].to<<" "<<adj[i][j].rev<<" "<<adj[i][j].capacity<<endl;
    // //  }
    // //  }

    //   Dinic dinic(g, 1, 10);
    //   int maxflow = dinic.maxFlow();
    Graph g;
    ifstream in("Locations.txt");
    int n;
    in >> n;
    g.setSize(n);
    for (int i = 0; i < n; i++)
    {
        int id;
        string name, type;
        int demd;
        in >> id >> name >> type >> demd;
        Location a(id, name, type, demd);
    }
    in.close();
    

    Problem *problem = new Problem1();
    problem->readInput("test1.txt");
    problem->solve();
    problem->show();

    return 0;
}

// const int SCREEN_WIDTH = 800;
// const int SCREEN_HEIGHT = 600;

// int main(int argc, char* argv[])
// {
//     // Khởi tạo SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         std::cerr << "Không thể khởi tạo SDL! Lỗi: " << SDL_GetError() << "\n";
//         return 1;
//     }

//     // Tạo cửa sổ
//     SDL_Window* window = SDL_CreateWindow("Xe di chuyển - SDL2",
//                                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//                                           SCREEN_WIDTH, SCREEN_HEIGHT,
//                                           SDL_WINDOW_SHOWN);

//     if (!window) {
//         std::cerr << "Không thể tạo cửa sổ! Lỗi: " << SDL_GetError() << "\n";
//         SDL_Quit();
//         return 1;
//     }

//     // Tạo renderer
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         std::cerr << "Không thể tạo renderer! Lỗi: " << SDL_GetError() << "\n";
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 1;
//     }

//     // Thông số chiếc xe
//     SDL_Rect car = {100, SCREEN_HEIGHT / 2 - 25, 100, 50};
//     int speed = 5; // tốc độ di chuyển
//     bool movingRight = true;

//     bool quit = false;
//     SDL_Event e;

//     // Vòng lặp chính
//     while (!quit) {
//         // Xử lý sự kiện
//         while (SDL_PollEvent(&e)) {
//             if (e.type == SDL_QUIT) quit = true;
//         }

//         // Cập nhật vị trí xe
//         if (movingRight) {
//             car.x += speed;
//             if (car.x + car.w >= SCREEN_WIDTH)
//                 movingRight = false;
//         } else {
//             car.x -= speed;
//             if (car.x <= 0)
//                 movingRight = true;
//         }

//         // Xóa màn hình (màu xanh trời)
//         SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
//         SDL_RenderClear(renderer);

//         // Vẽ chiếc xe (màu đỏ)
//         SDL_SetRenderDrawColor(renderer, 220, 20, 60, 255);
//         SDL_RenderFillRect(renderer, &car);

//         // Cập nhật lên màn hình
//         SDL_RenderPresent(renderer);

//         // Giới hạn FPS
//         SDL_Delay(16); // ~60 FPS
//     }

//     // Giải phóng tài nguyên
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }