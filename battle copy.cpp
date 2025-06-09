// // #include <iostream>
// // #include <queue>
// // #include <string>
// // #include <cstdlib>
// // #include <ctime>
// // #include <chrono>
// // #include <thread>
// // using namespace std;
// // #include "data.h"

// // // Gunakan enum Skill dari file ini
// // enum Skill { ATTACK, MAGIC, COUNTER, DODGE };

// // string skillToString(Skill s) {
// //     switch (s) {
// //         case ATTACK: return "Attack";
// //         case MAGIC: return "Magic";
// //         case COUNTER: return "Counter";
// //         case DODGE: return "Dodge";
// //         default: return "Unknown";
// //     }
// // }

// // Skill getRandomSkill(const MonsterTemplate& tmpl) {
// //     int roll = randomizer (1, 100);
// //     int acc = tmpl.percAttack;
// //     if (roll <= acc) {
// //         return ATTACK;
// //     }
// //     acc += tmpl.percMagic;
// //     if (roll <= acc) {
// //         return MAGIC;
// //     }
// //     acc += tmpl.percCounter;
// //     if (roll <= acc) {
// //         return COUNTER;
// //     }
// //     return DODGE;
// // }

// // string resolveBattle(Skill player, Skill enemy) {
// //     if (player == enemy)
// //         return "draw";
// //     if ((player == ATTACK && enemy == MAGIC) ||
// //         (player == MAGIC && enemy == COUNTER) ||
// //         (player == COUNTER && enemy == ATTACK))
// //         return "player";
// //     return "enemy";
// // }

// // bool attemptDodge(PlayerStats& player_stats, MonsterInstance& enemy) {
// //     int base = 30; // Difficulty level not used, or you can add a field to MonsterInstance if needed
// //     float successChance = static_cast<float>(player_stats.evade) / base;
// //     float roll = static_cast<float>(rand()) / RAND_MAX;

// //     cout << "\nDodge attempt (peluang: " << (int)(successChance * 100) << "%) ";
// //     cout << flush;
// //     for (int i = 0; i < 3; ++i) {
// //         this_thread::sleep_for(chrono::milliseconds(500));
// //         cout << "." << flush;
// //     }
// //     cout << endl;

// //     if (roll < successChance) {
// //         cout << "Berhasil menghindar!\n";
// //         return true;
// //     } else {
// //         cout << "Gagal menghindar! Musuh menyerang!\n";
// //         return false;
// //     }
// // }

// // Fungsi ASCII
// string getEnemyAscii(const MonsterInstance& enemy) { 
//     if (enemy.name == "Tung Tung Sahur") {
//         return R"(
//             :::::::           
//            .::: ::;.          
//            .+x+.+X;.          
//            :;x;:++::          
//            .;.;:;:::          
//             +;::;:;.          
//             +:;.::+.          
//            ;+:. ::+;          
//           :;;:. ::++;         
//           +;+.. ::;.;.        
//          .+X:.. ::;;X:        
//        ::;:..:+.+:: :         
//     .;.::   ;.: :.;           
//   ::: ;.    +:   ;;           
//  :. ;:      ;:   :;           
//   ::        ;;  .::           
//          .;;.;: + :;:         
//          ;+;;.   :++;                
//         )";  
//     } else if (enemy.name == "Tralalero Tralala") {
//         return R"(
//                          :;                       
//                        :; +                       
//                       :. :.                     ;:
//                  .:;+:   ..                   :+. 
//          :+:::            :.                 ;;.  
//     ;::.           ::.      ;.             :::.   
//  ;:       ++       .+x;       ::          ;:::    
// :;;..  :::::::::;;;;;;.         :;   .   :.:.     
//    :;++::.                        .:.;::;. ;      
//         :;;::.        .;  :. :::  :::::::;;.      
//               ;::;:.    :. ::   .; ;;;; :;;:      
//              :. ;.   ::;:+  :;;;;.;;.;+.  ::      
//             :;:.;;        +  ;    ;$+.:+          
//           :x;   :::       :. ;   x:: :x;          
//        .;;:.+++;::X     .;.;:X;: ;+X+:            
//      +::::::;::;++.    :xX+.;x: :                 
//                      :Xxx;    :+:                 
//                   .;:;+:  x:;x:.+                 
//                :+.        ;;+. .:                 
//               :;:     .:+:.;+.                    
//                  .;+++;.                          
//         )";
//     } else if (enemy.name == "Bombardilo Crocodilo") {
//         return R"(
//                                           ...                                
//                          +*+:        .=*****+=-.        :                    
//                         .%#*=:     :=*%#%#**++=-..     :%*:         ::       
//                         -%%#+=. .:=#####****+++====-:.  .#%=.     :*#=       
//                         +%%%**+****************#%#*+====-:*%#=:: =#*:        
//                .:::::...*%%#**######%#%%%%#*#%%%%%@@%***=+*%%%*++*=.         
//               :*##******#%%#%#*###%%%%%%###%%###%%@%%%%#*+===*%%#+:          
//                  :-=*#%%%%#*%@%*==*%%%%%%%%%%%%%##########**+==+*+--=:       
//        :--:----------==+*###%@@%#+==*%%%%%%@%%%%%%%%%%%%######%%%%#++=:      
//      .=++*+++========+**%%%%%%@@%#**+*%%%%%@%%%%%%@@%%%%%%%%%%%%%#**+==.     
//      :*#********++*****#%%%%#*%@%%*+=%%%%@@@%%%####%%%@@%%*##*#%#%#**=:.     
//       .:::::-===+***###%%%%%##%@%%#**%%%%%%%%%######%%%%@%%***=: :....       
//                        :*%%%%%%@@%%*+*%%%%%%%%%#***#%##%#%%#*+==:            
//                          :+#%%@@%*+-     :=+*****=:.-+*#####*%*==*-.         
//                              -%%-.             +*      .:=+*##**++=-         
//                              *%+               +*           :-***+=:         
//                              ::            .. -**=                           
//                                           :%%*#%%=:.                         
//                                           =%%%%%%#**=.                       
//                                            .:%%%%%%%**:                      
//                                               =*%%%%%*-                      
//                                                  .:..                                                                                                          
//         )";
//     } else if (enemy.name == "Brbr Patapim") {
//         return R"(
//              .::::::                
//          ::::::::;:::;.             
//          ;:...;;;:;;::::            
//         .;;;;;  :;:;+;:;:           
//        :::x;;  .;+;+::              
//       ::;+:;; .;;x; ::              
//      .:;;;::: .::::: :              
//      .;;;;;:;. :. :;: :             
//      .+;.x;:::;;;;;;..              
//     .++;:Xx;. ;::;X;:               
//     ;;+;;;+:  :::x+;:.              
//     ::::;x;:..;:++.+:.              
//   .;;:;;;x+;:; ;;:++;+.             
//  .:::+;:;+;;.++++;;;+;x:            
//   .;++;xx;;::++++:;:;;+;            
//   .+:+;;+.:.: ;:;+ .:;:::           
//   :.:: .  ;;:::::.    :;;;;::...    
//   :.      .:::::::.:::..   :::;;+;. 
//    ...:.  .:::;:::.:: :;;+;.  :::;: 
//        :::: :; ;::;.;;    ; .:;;:   
//           .;;+;;;;+;;+:::.          
//         )";
//     } else if (enemy.name == "Boborito Bandito") {
//         return R"(
//             ..-=-.:-:.                  
//           ..=+@++++++*.                 
//           .=++++++++++*.                
//          .-@@@@@@@@@@@@=:...            
//       :%@@@%==========+@#@@#.           
//       .-%*#==%*=***+=%#+++...           
//       ..+*=++=-=@#%@-=++=%:.            
//       .-+==*#==--+---*#%+=*:.           
//      .+*===+*=--=**---=*===#.           
//       .%*=======*=-+======#=.           
//    .+*++@#*%++#====+=##+%%+++..         
//   .*+*++%###+%..%%#%.:*+%#++**..        
// ..#+++*+*#*++++=.@@:=#+++#++*++.    ..  
// .*++++#+#*%*++%#%###+*++*+++*++=...+#-  
// *+**++*++*#%##%%#%#*#**#########=:#:*:..
// +++++%*****#****%***#*#*********%%%**%**
// ++++++++*%@%#%%******@@@#*%###%%#.......
// :*++++*-##***#%##%#%%%+++#***#*++.      
// ...=*+#%%****##++*####+++++#+++*..      
//     .+++*###%*+*+*###*#+#**+-..         
//     .#####+++++**#+###+++*#*+.          
//     .+++++++++++#+*+++++++++*.          
//     -++++++++++#+++*++++++++*.          
//         )";
//     } else if (enemy.name == "Bombombini Guzini") {
//         return R"(
//              +=-                                       
//            =-:+**+                                     
//           -===++==+    ---         ===                 
//          :::+***+*##   +**        -***                 
//                *##%#  +*##*      =+**                  
//                ===+*+ +###*     -+***                  
//               --:::-=+*###*     ****                   
//          **+*+-:::::=*****##+  *****                   
//          ***++-:-----====+++===++++++++===++===+==+++==
//        ------=+**+=*#*+=++#******+=+%%#%==-  *#%%#+++  
//    -=*+-*++==*=+#*+=-+**=*=*#****+=+#%%%+=-  *#%%%===  
// +*%*=-*+%##+=+=*****###*++=*******=::---       :--     
//  +*%+==-=++=     *+##*=+++#*##+                        
//                    ++==+*** +++                        
//                    +**      +++                        
//                  +****+     *#*++                      
//                 +==++=+=  +==+*++=                     
//                    ++       =++=                       
//         )";
//     }
//     return 0;
// }


// // // Fungsi pertarungan
// // bool fightEnemy(Player& player, MonsterInstance& enemy) {
// //     cout << flush;
// //     for (int i = 0; i < 3; ++i) {
// //         this_thread::sleep_for(chrono::milliseconds(1000));
// //         cout << "." << flush;
// //     }
// //     cout << endl;

// //     cout << "\n=== Lawan " << enemy.name << " (HP: " << enemy.hp << ") ===\n" << endl;
// //     cout << getEnemyAscii(enemy) << "\n\n";
// //     cout << "Pilihan Aksi:\n";
// //     cout << "1. Attack  - Serangan langsung, menang melawan Magic.\n";
// //     cout << "2. Magic   - Serangan sihir, menang melawan Counter.\n";
// //     cout << "3. Counter - Menangkis serangan fisik, menang melawan Attack.\n";
// //     cout << "4. Dodge   - Menghindari serangan, tergantung stat evade.\n";

// //     int choice;
// //     while (true) {
// //         cout << "Pilih aksi [1-4]: ";
// //         cin >> choice;
// //         if (cin.fail() || choice < 1 || choice > 4) {
// //             cin.clear();
// //             cin.ignore(1000, '\n');
// //             cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 4.\n";
// //         } else {
// //             break;
// //         }
// //     }

// //     Skill playerSkill = static_cast<Skill>(choice - 1);
// //     Skill enemySkill = getRandomSkill();

// //     cout << "\nKamu: " << skillToString(playerSkill) << "  |  Musuh: " << skillToString(enemySkill) << endl;
// //     cout << flush;
// //     for (int i = 0; i < 3; ++i) {
// //         this_thread::sleep_for(chrono::milliseconds(500));
// //         cout << "." << flush;
// //     }
// //     cout << endl;

// //     if (playerSkill == DODGE) {
// //         bool sukses = attemptDodge(player_stats, enemy);
// //         if (sukses) return true;
// //         else {
// //             player_stats.hp -= enemy.hp;
// //             cout << "HP berkurang -" << enemy.hp << ". Sisa HP: " << player_stats.hp << endl;
// //             return player_stats.hp > 0;
// //         }
// //     }

// //     string result = resolveBattle(playerSkill, enemySkill);
// //     if (result == "draw") {
// //         cout << "\nSerangan imbang! Tidak ada pemenang.\n";
// //         return false;
// //     } else if (result == "player") {
// //         cout << "\nKamu menang dalam satu ronde!\n";
// //         player_stats.exp += enemy.expReward;
// //         cout << "\nKamu dapat +" << enemy.expReward << " XP. Total XP: " << player_stats.exp << endl;
// //         return true;
// //     } else {
// //         cout << "\nKamu kalah dalam satu ronde! -" << enemy.hp << " HP.\n";
// //         player_stats.hp -= enemy.hp;
// //         if (player_stats.hp <= 0) {
// //             cout << "\nHP kamu 0! Game Over!\n";
// //             return false;
// //         } else {
// //             cout << "\nHP tersisa: " << player_stats.hp << endl;
// //             return true;
// //         }
// //     }
// // }

// // void battle(Player& player, queue<MonsterInstance>& enemyQueue) {
// //     while (!enemyQueue.empty() && player_stats.hp > 0) {
// //         MonsterInstance& current = enemyQueue.front();
// //         bool lanjut = fightEnemy(player, current);
// //         if (!lanjut && player_stats.hp <= 0) return;
// //         if (lanjut || player_stats.hp <= 0) {
// //             enemyQueue.pop();
// //         } else {
// //             cout << "\nPertandingan diulang karena hasil imbang!\n";
// //         }
// //     }
// //     if (player_stats.hp > 0)
// //         cout << "\nKamu berhasil menghadapi semua musuh!\n";
// // }

// // int main() {
// //     srand(time(0));
// //     Player player;
// //     queue<MonsterInstance> musuh;
// //     musuh.push(MonsterInstance(MonsterType::TUNG_TUNG_SAHUR, 1));
// //     musuh.push(MonsterInstance(MonsterType::TRALALERO_TRALALA, 2));
// //     musuh.push(MonsterInstance(MonsterType::BOMBARDILO_CROCODILO, 3));
// //     musuh.push(MonsterInstance(MonsterType::BRBR_PATAPIM, 1));
// //     musuh.push(MonsterInstance(MonsterType::BOBORITO_BANDITO, 3));
// //     musuh.push(MonsterInstance(MonsterType::BOMBOMBINI_GUZINI, 2));
// //     cout << "\n===================";
// //     cout << "\n    Suit Battle    ";
// //     cout << "\n===================\n";
// //     cout << "\nNote: HP awal kamu adalah 100\n";
// //     battle(player, musuh);
// //     cout << "\n===== Permainan selesai =====" << endl;
// //     cout << "\nXP akhir kamu: " << player_stats.exp << endl;
// //     cout << "\nSisa HP: " << player_stats.hp << endl;
// //     return 0;
// // }
