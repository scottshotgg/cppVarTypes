#include "var.cpp"

int main() {
    // TestVarVsInt();

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
    var test = "6";
    cout << "string: " << test << endl;
    test += "5";
    cout << "string +=: " << test << endl;
    cout << "string +: " << test+"5" << endl;
    cout << endl;

    test = 6;
    cout << "int: " << test << endl;
    test += 5;
    cout << "int +=: " << test << endl;
    cout << "int +: " << test+6 << endl;
    test -= 6;
    cout << "int -=: " << test << endl;
    cout << "int -: " << test-6 << endl;
    test *= 6;
    cout << "int *=: " << test << endl;
    cout << "int *: " << test*6 << endl;
    cout << endl;

    test = true;
    cout << "bool: " << test << endl;
    test += false;
    cout << "bool +=: " << test << endl;
    cout << "bool +: " << test+false << endl;
    cout << endl;

    test = 6.66666;
    cout << "float: " << test << endl;
    test += 2.22222;
    cout << "float +=: " << test << endl;
    cout << "float +: " << test+1.11111 << endl;
    test -= 2.22222;
    cout << "float -=: " << test << endl;
    cout << "float -: " << test-2.22222 << endl;
    cout << endl;

    // FIXME: for some reason this thrashes the object de/cons calls
    test = {};
    test["me"] = "hey";
    cout << "object string: " << test << endl;
    test["me"] = 7;
    cout << "object int: " << test << endl;
    cout << endl;



    // ----
    // Second round
    // ----

    // test = "6";
    // cout << "string: " << test << endl;
    // test += "6";
    // cout << "string +=: " << test << endl;
    // cout << "string +: " << test+"6" << endl;
    // cout << endl;

    // test = 6;
    // cout << "int: " << test << endl;
    // test += 6;
    // cout << "int +=: " << test << endl;
    // cout << "int +: " << test+6 << endl;
    // cout << endl;

    // test = false;
    // cout << "bool: " << test << endl;
    // test += true;
    // cout << "bool +=: " << test << endl;
    // test = false;
    // cout << "bool +: " << test+true << endl;
    // cout << endl;

    // test = 6.66666;
    // cout << "float: " << test << endl;
    // test += 3.33333;
    // cout << "float +=: " << test << endl;
    // cout << "float +: " << test+1.11111 << endl;
    // cout << endl;

    return 0;
}



