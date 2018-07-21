#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;

// namespace var {

    // struct var { std::string type; void* data; };
    // std::unordered_map<std::type_index, std::string> type_names;

    // type_names[std::type_index(typeid(int))] = "int";
    // type_names[std::type_index(typeid(double))] = "double";

    enum varType {
        pointerType, 
        intType, 
        boolType,
        charType,
        floatType,
        stringType,
        structType,
        objectType,
        arrayType
    };

    // FIXME: this only supports homogenous type operations right now
    class var {
        // TODO: I'm sure we'll need to add more later on

        // simple gc bleh
        // map<string, 
        // map from pointer to var of all declared
        // map from pointer to var of in use
        // if that pointer is not in use anymore, i.e - redeclared, delete from both lists

        private:
            string name;
            varType type;
            void* data;
        
        public:

            // ~var() {
            //     switch(type) {
            //         // FIXME: not sure how to handle this
            //         // case pointerType:

            //         case intType: {
            //             cout << "int decons; Name: " << name << " Type: " << type << " Value: " << data << endl;
            //             delete (int*)data;
            //             break;
            //         }

            //         // case boolType: {
            //         //     delete (bool*)data;
            //         // }

            //         // case charType: {
            //         //     delete (char*)data;
            //         // }
                    
            //         // case floatType: {
            //         //     delete (float*)data;
            //         // }
                        
            //         // case stringType: {
            //         //     delete (string*)data;
            //         // }

            //         // FIXME: finish when structs are implemented
            //         // case arrayType:
            //         // case structType:
            //         // case objectType:
                    
            //         default:
            //             printf("don't know how to deallocate; Type: %u Value: %p\n", type, data);
            //     }
            // }

            // FIXME: switch ALL constructors to use pass-by-reference
            // TODO: this need to assert a default type
            // var() : type(intType), data(new int(0)) {}
            var(void) : type(objectType), data(new map<string, var>) {}
            var(void* value) : type(pointerType), data(value) {}
            var(int value) {
                if (type != 0) {
                    // var::~var();
                    printf("dater %d\n", *(int*)data);
                    printf("type %d\n", *(int*)type);
                    // delete data;
                    printf("data was not null\n");
                }
                type = intType;
                data = new int(value);
                printf("int cons; Type: %u Value: %p\n", type, data);
                //printf("int cons\n");
            }
            var(bool value) : type(boolType), data(new bool(value)) {}
            var(char value) : type(charType), data(new char(value)) {}
            var(float value) : type(floatType), data(new float(value)) {}
            var(double value) : type(floatType), data(new float(value)) {}
            var(const char* value) : type(stringType), data(new string(value)) {}
            var(string value) : type(stringType), data(new string(value)) {
                        printf("string cons; Type: %u Value: %p\n", type, data);}

            var(initializer_list<var> propList) : type(objectType) {
                if (propList.size() % 2 != 0) {
                    cout << "ERROR: invalid amount of arguments to object" << endl;
                    exit(9);
                }

                map<string, var> object;

                int i = 0;
                var lastItem;
                for (auto prop : propList) {
                    if (i % 2 == 1) {
                        // TODO: could think about supporting more than string here but that will involve many more more checks
                        object[*(string*)lastItem.Value()] = prop;
                    } else {
                        lastItem = prop;
                    }

                    i++;
                }

                data = new map<string, var>(object);
            }

            // TODO: will have to do something special here, maybe code generation?
            // var(struct value) : type(structType), data(&value) {}
            // TODO: not sure if you can do this with a map, might have to copy everything over
            var(map<string, var> value) : type(objectType), data(new map<string, var>(value)) {
                //printf("obj cons\n");
            }
            // FIXME: might take this out, kind of unsafe
            var(varType iType, void* iData) : type(iType), data(iData) {
                //printf("void*\n");
            }

            varType Type(void) const {
                return type;
            }

            void* Value(void) const {
                //printf("value\n");
                return data;
            }

            var& operator[](string attribute) {
                return (*(map<string, var>*)data)[attribute];
            }

            void operator+=(const int right) {
                // printf("+= var int\n");
                *(int*)data += right;
            }

            int operator*(const var& right) {
                // printf("* var var\n");
                return *(int*)data * *(int*)right.data;
            }

            void operator=(const int right) {
                // printf("wat this do %d\n", type);
                // printf("wat this do %d\n", *(int*)data);
                // printf("wat this do right %d\n", right);
                printf("%d", *(int*)data);
                *(int*)data = right;
            }

            void operator=(const char* right) {
                // printf("wat this do %d\n", type);
                // printf("wat this do %d\n", *(int*)data);
                // printf("wat this do right %d\n", right);
                // *(int*)data = right;
                if (type == stringType) {
                    *(string*)data = right;
                } else {
                    switch(type) {
                        case intType:
                            printf("%d\n", *(int*)data);
                            delete (int*)data;
                            data = nullptr;
                            type = stringType;
                            data = (string*)right;
                            break;
                        
                        default:
                            printf("wtf %d\n", type);
                    }
                }

                return;
            }

            // TODO: FIXME: could not get this to work
            // var& operator=(initializer_list<var> propList) {
            //     //printf("im in");

            //     int propListLen = propList.size();
            //     if (propListLen % 2 != 0) {
            //         cout << "ERROR: invalid amount of arguments to object" << endl;
            //         exit(9);
            //     }

            //     map<string, var> object;

            //     cout << object << endl;

            //     // TODO: ok this is kinda fucking hacky but w/e
            //     // var thing[propListLen];
            //     int i = 0;
            //     var lastItem;
            //     for (auto prop : propList) {
            //         cout << prop << endl;

            //         if (i % 2 == 1) {
            //             object[*(string*)lastItem.Value()] = prop;
            //         } else {
            //             lastItem = prop;
            //         }

            //         i++;
            //     }

            //     cout << object << endl;

            //     // for (int i = 0; i < propListLen; i+=2) {
            //     //     // cout << "i " << i << thing[i] << endl;
            //     //     // cout << "i " << i+1 << thing[i+1] << endl;
            //     //     // FIXME: -SUPER- unsafe, need to make sure they are strings
            //     //     object[*(string*)thing[i].Value()] = thing[i+1];
            //     //     cout << object << endl;
            //     // }


            //     data(new map<string, var>(object));
            // }

            friend ostream& operator<<(ostream& stream, const var& v){
                switch(v.Type()) {
                    case intType:
                        return stream << *(int*)v.Value();

                    case boolType:
                        if (*(bool*)v.Value()) {
                            return stream << "true";
                        }
                        return stream << "false";

                    case charType:
                        return stream << *(char*)v.Value();

                    case floatType:
                        return stream << *(float*)v.Value();

                    case stringType:
                        return stream << *(string*)v.Value();

                    case objectType: {
                        int counter = 0;
                        map<string, var> objectMap = *(map<string, var>*)v.Value();
                        stream << "{ ";
                        for (auto property : objectMap) {
                            // stream << property.first << " " << property.second.first << " " << property.second.second << "\n";
                            stream << property.first << ": " << property.second;

                            if (counter < objectMap.size()-1) {
                                stream << ", ";
                            }
                            counter++;
                        }
                        return stream << " }";
                    }

                    default:
                        printf("wtf to do Type: %u\n", v.Type());
                }

                return stream;
            }
    };

    map<void*, var> declared;
    map<void*, var> inuse;

    int gc(void) {
        printf("gc time...\n");

        for (auto memloc : declared) {
            cout << memloc.first << " " << memloc.second << endl;
        }

        return 0;
    }

    // TODO: for right now, instead of doing the map[string]function to figure out the value
    // https://stackoverflow.com/questions/4972795/how-do-i-typecast-with-type-info
    // https://stackoverflow.com/questions/2136998/using-a-stl-map-of-function-pointer
    // ostream& operator<<(ostream& stream, const var& v){
    //     switch(v.Type()) {
    //         case intType:
    //             return stream << *(int*)v.Value();

    //         case boolType:
    //             if (*(bool*)v.Value()) {
    //                 return stream << "true";
    //             }
    //             return stream << "false";

    //         case charType:
    //             return stream << *(char*)v.Value();

    //         case floatType:
    //             return stream << *(float*)v.Value();

    //         case stringType:
    //             return stream << *(string*)v.Value();

    //         case objectType: {
    //             int counter = 0;
    //             map<string, var> objectMap = *(map<string, var>*)v.Value();
    //             int mapLen = objectMap.size();
    //             stream << "{ ";
    //             for (auto property : objectMap) {
    //                 // stream << property.first << " " << property.second.first << " " << property.second.second << "\n";
    //                 stream << property.first << ": " << property.second;

    //                 if (counter < mapLen-1) {
    //                     stream << ", ";
    //                 }
    //                 counter++;
    //             }
    //             return stream << " }";
    //         }

    //         default:
    //             //printf("wtf to do Type: %u\n", v.Type());
    //     }

    //     return stream;
    // }

    // Interger operations
    int operator+(const int left, const var& right) {
        // printf("+ int var\n");
        return left + *(int*)right.Value();
    }

    int operator+=(int left, const var& right) {
        // printf("+= int var\n");
        return left += *(int*)right.Value();
    }

    // int operator+=(const var& right, int left) {
    //     printf("+= var int\n");
    //     return left += *(int*)right.Value();
    // }

    int operator+=(const var& left, const var& right) {
        // printf("+= var var\n");
        return *(int*)left.Value() += *(int*)right.Value();
    }

    int operator*(const int left, const var& right) {
        // printf("* int var\n");
        return left * *(int*)right.Value();
    }

    bool operator+(const bool left, const var& right) {
        return left || *(bool*)right.Value();
    }

    // TODO: not sure about this one for now
    // char operator+(const char left, const var& right) {
    //     return left || *(bool*)right.Value();
    // }

    float operator+(const float left, const var& right) {
        return left + *(float*)right.Value();
    }

    float operator+(const double left, const var& right) {
        return left + *(float*)right.Value();
    }

    // String/Char* operations: convert char* to string with all of these functions
    string operator+(const char* left, const var& right) {
        return left + *(string*)right.Value();
    }

    var operator+(const var& left, const char* right) {
        return var{ *(string*)left.Value() + right };
    }

    // Generic constructor for right side value
    template <typename T>
    var operator+(const var& left, T right) {
        // FIXME: this is kinda inefficient
        return var{ right + left };
    }
// };

int TestVarVsInt() {
    int varOperationsAmount = 10000000;   // one hundred thousand ops

    auto t1 = chrono::high_resolution_clock::now();
    var vz = 0;
    var vy = 8;
    var vx = 7;
    for (int i = 0; i < varOperationsAmount; i++) {
        vz += vx * vy;
    }
    cout << "vz " << vz << endl;

    int varDuration = chrono::duration_cast<chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t1).count();

    cout << "var type operations took " << varDuration << " milliseconds\n\n";

    int intOperationsAmount = 10000000; // ten million ops

    auto t3 = chrono::high_resolution_clock::now();
    int iz = 0;
    for (int i = 0; i < intOperationsAmount; i++) {
        iz += 7 * 8;
    }
    cout << "iz " << iz << endl;

    int intDuration = chrono::duration_cast<chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t3).count();
    cout << "int type operations took " << intDuration << " milliseconds\n\n";


    // var statsObj = map<string, var>{
    //     { "varOperations", map<string, var>{ 
    //         { "amount", varOperationsAmount },
    //         { "duration", varDuration }},
    //     },
    //     { "intOperations",  map<string, var>{ 
    //         { "amount", varOperationsAmount },
    //         { "duration", intDuration }},
    //     }
    // };

    // cout << "stats: " << statsObj << endl << endl; 

    return 0;
}

int main() {
    // var me = map<string, var>{
    //     { "hey", "its me" },
    //     { "maybe", false },
    //     { "floater", 7.88865 },
    //     { "interino", 65 },
    //     { "anotherObject", map<string, var>{
    //         { "intBro", 789 },
    //         { "fadedString", "woah" }
    //     }},
    // };
    // cout << "var: " << me << endl;

    // var test;
    // test["me"] = { 
    //     "something", 7,
    //     "this", {
    //         "you", true,
    //     }
    // };
    // test = "me";
    // // test.~var();
    printf("test 7\n");
    var test = 7;
    gc();
    cout << "test: " << test << " " << test.Value() << endl;
    printf("test 8\n");
    test = "yo";
    gc();
    cout << "test: " << test << " " <<test.Value() << endl;

    // TestVarVsInt();
}



