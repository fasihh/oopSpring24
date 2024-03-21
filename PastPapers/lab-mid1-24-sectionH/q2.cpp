#include <iostream>
using namespace std;

class User;
class Comment {
private:
    int commentId;
    string content;
    User *author;
public:
    Comment(int id = 0, string content = "") : commentId(id), content(content) {}

    void setAuthor(User *obj) { author = obj; }

    void displayInfo() {
        cout << "\t\tID: " << commentId << "\n";
        cout << "\t\tComment: " << content << "\n";
    }
};

class Post {
private:
    int postId;
    string content;
    Comment *comments;

    int count, size;
public:
    Post(int id = 0, string content = "") : postId(id), content(content), count(0), size(10) {
        comments = new Comment[size];
    }

    void createComment(const Comment& obj) {
        if (count >= size) {
            size *= 2;
            Comment *new_comments = new Comment[size];

            for (int i = 0; i < count; i++)
                new_comments[i] = comments[i];

            delete[] comments;
            comments = new_comments;
        }

        comments[count] = obj;
        count++;
    }

    void displayInfo() {
        cout << "\tID: " << postId << "\n";
        cout << "\tPost: " << content << "\n";
        cout << "\tComments: " << "\n";
        for (int i = 0; i < count; i++)
            comments[i].displayInfo();
    }
};

class User {
private:
    int userId;
    string userName;
    Post *posts;

    int count, size;
public:
    User(int id = 0, string name = "") : userId(id), userName(name), count(0), size(10) {
        posts = new Post[size];
    }

    void createPost(const Post& obj) {
        if (count >= size) {
            size *= 2;
            Post *new_posts = new Post[size];

            for (int i = 0; i < count; i++)
                new_posts[i] = posts[i];

            delete[] posts;
            posts = new_posts;
        }

        posts[count++] = obj;
    }

    void displayInfo() {
        cout << "ID: " << userId << "\n";
        cout << "Name: " << userName << "\n";
        cout << "Posts: " << "\n";
        for (int i = 0; i < count; i++)
            posts[i].displayInfo();
    }
};

class SocialMediaPlatform {
private:
    User *users;

    int count, size;
public:
    SocialMediaPlatform() : count(0), size(10) {
        users = new User[size];
    }

    void registerUser(const User& obj) {
        if (count >= size) {
            size *= 2;
            User *new_users = new User[size];

            for (int i = 0; i < count; i++)
                new_users[i] = users[i];

            delete[] users;
            users = new_users;
        }

        users[count++] = obj;
    }
};

int main() {
    SocialMediaPlatform social;

    User user1(1, "Fasih");
    social.registerUser(user1);

    Post post1(1, "Hello");
    Comment comment1(1, "World!");
    comment1.setAuthor(&user1);
    Comment comment2(2, "heck yeah");
    comment2.setAuthor(&user1);

    post1.createComment(comment1);
    post1.createComment(comment2);

    user1.createPost(post1);

    user1.displayInfo();

    return 0;
}