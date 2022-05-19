
// FollowUps: Question is based on a graph, not a tree. 
//           The graph is undirected, so the problem is equivalent to finding if there is a cycle in the graph. 
//           The solution is to use DFS to detect cycle. 
//           The time complexity is O(V+E), where V is the number of vertices and E is the number of edges.
//           The space complexity is O(V), where V is the number of vertices.

// how you knew TC and SC? for this problem?
// TC: O(V+E) because we have to visit all vertices and edges. what is the number of vertices and edges? 
//     the number of vertices is the number of people in the social network. the number of edges is the number of friends.
// SC: O(V) because we use a stack to store the vertices we are visiting. and to say if we are friends with someone, we only need to know if they are in the stack.
//     So the space complexity is O(V)

// Question: 

// In the social media network facebook, people look forward to connect to each other. 2 people mutually decides to connect. In this problem you will be given 2 type of tasks, letsbefriends and arewefriends. In the letsbefriends query, you will be given 2 person and they will be added to each other circle. In the arewefriends query, you will be given 2 person and you have to tell whether they are connected directly/indirectly or they are independent. 2 people are considered friends if they are directly or indirectly connected.

// Input: First line of input contains number of testcases T. For each testcase, next line contains an input N, which will represent the maximum number of people involved in the facebook hub. The third line will have name of N people space separated. The fourth line will have number of queries q and then there will be q queries each starting with letsbefriends or arewefriends and two person names person1 and person2.

// Output: For each arewefriends operation code will return 1(true : If they are directly or indirectly connected) or 0(false : If they are not connected).

// Note: Initally everybody in facebook hub is not connected. Person name will be in lowercase latin letters with no spaces. 

// Constraints: 
// 1 <= T <= 10
// 1 <= N <= 5*105
// 1<= Q <= 5*105
// Total number of persons are equal to N.

// Example:
// Input:
// 1 // testcases
// 5 // number of people
// akshit ankit akash mayank siddhant // names of people
// 5 // number of queries 
// letsbefriends mayank ankit 
// arewefriends mayank siddhant
// letsbefriends mayank akash
// arewefriends ankit akash
// arewefriends akash akshit

// Output:
// 0
// 1
// 0

// Explanation: 
// There are a total of 5 people in the facebook hub namely, akshit ankit akash mayank siddhant. 
// For the first query,  letsbefriends mayank ankit, mayank and ankit become friends. 
// For the second query, arewefriends mayank siddhant , mayank and siddhant are not friends so return 0.
// For the third query, letsbefriends mayank akash , mayank and akash become friends.
// For the fourth query, arewefriends ankit akash, ankit and akash are connected through mayank so return 1. 
// For the fifth query, arewefriends akash akshit, akash and akshit are not friends so return 0.



// approach and algorithm that can be used
// 1. use a hashmap to store the friends of each person.

// is it a graph problem or a tree problem?
// graph problem : we can use adjacency list to store the friends of each person. 


    // breakdown approach : 
    // letsbefriends :
    // 1. add the person1 and person2 to each other's friend list.
    // 2. add the person2 and person1 to each other's friend list.
    // 3. return 1.
    // arewefriends :
    // 1. check if person1 and person2 are friends.
    // 2. if they are friends return 1.
    // 3. if they are not friends return 0.
   
    #include <bits/stdc++.h>
    using namespace std;

    // define a class that is used to store the friends of each person.
    class person{
        public:
            string name; // name of the person.
            vector<string> friends; // vector of friends of the person.

            person(string name){
                this->name = name; // initialize the name of the person.
            }

            void add_friend(string name){
                friends.push_back(name); // add the friend to the vector of friends.
            }

            bool is_friend(string name){ // check if the person is a friend of the person.
                for(int i=0;i<friends.size();i++){
                    if(friends[i]==name){ // if the person is a friend return true.
                        return true;
                    }
                }
                return false;
            }

            void print_friends(){
                cout<<"friends of "<<name<<" are : ";
                for(int i=0;i<friends.size();i++){ // print the friends of the person.
                    cout<<friends[i]<<" "; // print the name of the friend.
                }
                cout<<endl;
            }


    };

    // main method. to execute the program. to return 1 if the program is successful. else return 0.

    int main(){
        // take the number of testcases.
        int t;
        cin>>t;

        // iterate over the testcases.
        for(int i=0;i<t;i++){
            // take the number of people in the facebook hub.
            int n;
            cin>>n;

            // take the names of the people in the facebook hub.
            string names[n];
            for(int j=0;j<n;j++){
                cin>>names[j];
            }

            // take the number of queries.
            int q;
            cin>>q;

            // iterate over the queries.
            for(int j=0;j<q;j++){
                // take the query type.
                string query_type;
                cin>>query_type;

                // if the query type is letsbefriends.
                if(query_type=="letsbefriends"){
                    // take the person1 and person2.
                    string person1,person2;
                    cin>>person1>>person2;

                    // add the person1 and person2 to each other's friend list.
                    person p1(person1);
                    person p2(person2);
                    p1.add_friend(person2);
                    p2.add_friend(person1);

                    // print the friends of each person.
                    p1.print_friends();
                    p2.print_friends();

                    // return 1.
                    cout<<"1"<<endl;
                }

                // if the query type is arewefriends.
                else if(query_type=="arewefriends"){
                    // take the person1 and person2.
                    string person1,person2;
                    cin>>person1>>person2;

                    // check if person1 and person2 are friends.
                    person p1(person1);
                    person p2(person2);
                    if(p1.is_friend(person2) || p2.is_friend(person1)){
                        // if they are friends return 1.
                        cout<<"1"<<endl;
                    }
                    else{
                        // if they are not friends return 0.
                        cout<<"0"<<endl;
                    }
                }
            }
        }
        return 1;
    }



