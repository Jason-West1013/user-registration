#include "../include/mongodb_handler.h"

MongoDBHandler::MongoDBHandler()
    : uri(mongocxx::uri(MongoDbUri)), client(mongocxx::client(uri)), db(client[DatabaseName]) {}

bool MongoDBHandler::add_user(const std::string &username, const std::string &password)
{
    mongocxx::collection collection = db[CollectionName];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value doc_to_add = 
        builder << "username" << username
        << "password" << password << bsoncxx::builder::stream::finalize;

    collection.insert_one(doc_to_add.view());

    return true;
}

std::string MongoDBHandler::get_password(const std::string &username)
{
    mongocxx::collection collection = db[CollectionName];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value query_doc = 
        builder << "username" << username << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = 
        collection.find_one(query_doc.view());

    if (result)
    {
        bsoncxx::document::element password = result->view()["password"];
        return password.get_string().value.to_string();
    }            
    return "";
}

bool MongoDBHandler::update_password(const std::string &username, const std::string &password)
{
    mongocxx::collection collection = db[CollectionName];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value query_doc = 
        builder << "username" << username
            << bsoncxx::builder::stream::finalize;

    bsoncxx::document::value update_doc = 
        builder << "$inc" << bsoncxx::builder::stream::open_document
            << "password" << password
            << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::update> result = 
        collection.update_one(query_doc.view(), update_doc.view());

    if (result)
    {
        return result->modified_count() == 1;
    } 
    return false;
}

bool MongoDBHandler::remove_user(const std::string &username)
{
    mongocxx::collection collection = db[CollectionName];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value query_doc = 
        builder << "username" << username
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::delete_result> result = 
        collection.delete_one(query_doc.view());

    if (result)
    {
        return result->deleted_count() == 1;
    } 
    return false;
}

