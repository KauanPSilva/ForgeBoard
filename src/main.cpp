#include <crow.h>

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "🔥 ForgeBoard API is running!";
    });

    app.port(18080).multithreaded().run();
}