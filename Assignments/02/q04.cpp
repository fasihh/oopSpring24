#include <iostream>
#include <algorithm>

using namespace std;

class Comment {
private:
    int commentId;
    string content;

    static int totalComments;
public:
    Comment(string content = "")
        : content(content), commentId(totalComments++) {}

    inline void display() { cout << "\t[" << commentId << "]: " << content << '\n'; }
};
int Comment::totalComments = 0;

class Post {
private:
    int postId, likes, views;
    string content;

    Comment *comments;
    int count;
    static int totalPosts;
public:
    Post(string content = "")
        : content(content), postId(totalPosts++), likes(0), count(0), views(0), comments(new Comment[10]) {}

    int getID() const { return postId; }
    int getLikes() const { return likes; }
    int getViews() const { return views; }

    Post& setLikes(const int likes) {
        this->likes = likes;
        return *this;
    }
    Post& setViews(const int views) {
        this->views = views;
        return *this;
    }
    Post& addComment(const Comment& comment) {
        if (count > 10) return *this;
        comments[count++] = comment;
        return *this;
    }

    inline void display() {
        cout << "[" << postId << "]: " << content << '\n';
        cout << "Likes: " << likes << '\n';
        cout << "Views: " << views << '\n';
        cout << "Comments: " << count << '\n';
        for (int i = 0; i < count; i++)
            comments[i].display();
        cout << endl;
        views++;
    }
};
int Post::totalPosts = 0;

void sortPosts(Post *posts, int count) {
    std::sort(posts, posts+count, [&](const Post& a, const Post& b) { return a.getLikes() > b.getLikes(); });
    std::sort(posts, posts+count, [&](const Post& a, const Post& b) { return a.getViews() > b.getViews(); });
}

class User {
protected:
    char type;
private:
    string name, email, password;
public:
    User(string name, string email, string password, char type) 
        : name(name), email(email), password(this->encryptPassword(password)), type(type) {}

    bool verifyUser(const User& user) { return user.name == this->name && user.email == this->email && user.password == this->password; }

    string encryptPassword(const string& password) {
        string new_password = "";
        for (char c : password)
            new_password += c+1;
        return new_password;
    }

    string getName() const { return name; }
    void setName(const string& newName) { name = newName; }

    string getEmail() const { return email; }
    void setEmail(const string& newEmail) { email = newEmail; }
};

class RegularUser : public User {
private:
    Post *feed;
    int count;
    static const int MAX_FEED_SIZE = 10;
public:
    RegularUser(string name, string email, string password) : User(name, email, password, 'r'), count(0), feed(new Post[MAX_FEED_SIZE]) {}

    void addToFeed(const Post& post) {
        if (count > 5) {
            cout << "Max post limit reached!" << endl;
            return;
        }
        feed[count++] = post;
    }

    void viewFeed() const {
        cout << "Feed for " << this->getName() << '\n';
        cout << "Posts [" << count << "]\n\n";
        for (short i = 0; i < count; i++)
            feed[i].display();
        cout << endl;
    }
};

class BusinessUser : public User {
private:
    int const limit = 10;
    int count;
public:
    BusinessUser(string name, string email, string password) : User(name, email, password, 'b'), count(0) {}

    void promotePost(const Post& post, Post *posts, int count) {
        if (type != 'b') return;
        if (this->count > limit) {
            cout << "Post promotion limit reached!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            if (posts[i].getID() == post.getID()) {
                int likes = post.getLikes(), views = post.getViews();
                posts[i].setLikes(likes*2).setViews(views*3);
                break;
            }
        }
        sortPosts(posts, count);
        this->count++;
    }
};

int main() {
    Post posts[] = {
        Post("Hello World!").addComment({ "Hello" }).addComment({ "World "}).addComment({ "!" }),
        Post("Promotional Content").setLikes(2).setViews(1).addComment({ "Cool!" }),
        Post("Interesting").addComment({ "Truly" })
    };

    RegularUser regular("Fasih", "fhk", "123");
    BusinessUser businesss("Owais", "ows", "234");
    businesss.promotePost(posts[1], posts, 2);

    regular.addToFeed(posts[0]);
    regular.addToFeed(posts[1]);
    regular.addToFeed(posts[2]);
    regular.viewFeed();

    return 0;
}