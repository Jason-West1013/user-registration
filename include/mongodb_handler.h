# pragma once

#include <string>

#include<bsoncxx/builder/stream/document.hpp>
#include<bsoncxx/json.hpp>
#include<bsoncxx/oid.hpp>
#include<mongocxx/client.hpp>
#include<mongocxx/database.hpp>
#include<mongocxx/uri.hpp>

class MongoDBHandler
{
private:
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;

public:
    MongoDBHandler();
    bool add_user(const std::string &username, const std::string &password);
    std::string get_password(const std::string &username);
    bool update_password(const std::string &username, const std::string &password);
    bool remove_user(const std::string &username);
};
