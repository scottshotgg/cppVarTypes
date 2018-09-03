#include "../var/var.cpp"
#include <map>

int TestVarVsInt() {
  int varOperationsAmount = 10000000; // one hundred thousand ops

  auto t1 = chrono::high_resolution_clock::now();
  var vz = 0;
  var vy = 8;
  var vx = 7;
  for (int i = 0; i < varOperationsAmount; i++) {
    vz += vx * vy;
  }
  cout << "vz " << vz << endl;

  int varDuration = chrono::duration_cast<chrono::milliseconds>(
                        std::chrono::high_resolution_clock::now() - t1)
                        .count();

  cout << "var type operations took " << varDuration << " milliseconds\n\n";

  int intOperationsAmount = 10000000; // ten million ops

  auto t3 = chrono::high_resolution_clock::now();
  int iz = 0;
  for (int i = 0; i < intOperationsAmount; i++) {
    iz += 7 * 8;
  }
  cout << "iz " << iz << endl;

  int intDuration = chrono::duration_cast<chrono::milliseconds>(
                        std::chrono::high_resolution_clock::now() - t3)
                        .count();
  cout << "int type operations took " << intDuration << " milliseconds\n\n";

  // var statsObj = {
  //     { "varOperations", {
  //         { "amount", varOperationsAmount },
  //         { "duration", varDuration }},
  //     },
  //     { "intOperations",  {
  //         { "amount", varOperationsAmount },
  //         { "duration", intDuration }},
  //     }
  // };

  // cout << "stats: " << statsObj << endl << endl;

  return 0;
}

int main() {
  // TestVarVsInt();

  map<string,var> me = map<string,var>{
      { "hey", "its me" },
      { "maybe", false },
      { "floater", 7.88865 },
      { "interino", 65 },
      { "anotherObject", map<string,var>{
          { "intBro", 789 },
          { "fadedString", "woah" },
      }},
  };
  cout << "var: " << me << endl;

// Fix this syntax
  // var mel = {
  //     { "hey", "its me" },
  //     { "maybe", false },
  //     { "floater", 7.88865 },
  //     { "interino", 65 },
  //     { "anotherObject", {
  //         { "intBro", 789 },
  //         { "fadedString", "woah" },
  //     },
  //     },
  // };
  // cout << "var: " << mel << endl;
  var test = "6";
  cout << "string: " << test << endl;
  test += "5";
  cout << "string +=: " << test << endl;
  cout << "string +: " << test + "5" << endl;
  cout << endl;

  test = 6;
  cout << "int: " << test << endl;
  test += 5;
  cout << "int +=: " << test << endl;
  cout << "int +: " << test + 6 << endl;
  test -= 6;
  cout << "int -=: " << test << endl;
  cout << "int -: " << test - 6 << endl;
  test *= 6;
  cout << "int *=: " << test << endl;
  cout << "int *: " << test * 6 << endl;
  cout << endl;

  test = true;
  cout << "bool: " << test << endl;
  test += false;
  cout << "bool +=: " << test << endl;
  cout << "bool +: " << test + false << endl;
  cout << endl;

  test = 6.66666;
  cout << "float: " << test << endl;
  test += 2.22222;
  cout << "float +=: " << test << endl;
  cout << "float +: " << test + 1.11111 << endl;
  test -= 2.22222;
  cout << "float -=: " << test << endl;
  cout << "float -: " << test - 2.22222 << endl;
  cout << endl;

  // FIXME: for some reason this thrashes the object de/cons calls
  test = {};
  test["me"] = "hey";
  cout << "object string: " << test << endl;
  test["me"] = 7;
  cout << "object int: " << test << endl;
  cout << endl;

  printf("Running speed test between int and var types....\n");
  TestVarVsInt();

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