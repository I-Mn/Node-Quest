#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

enum Skill { ATTACK, MAGIC, COUNTER, DODGE };

struct Enemy {
    string name;
    int hp;
    int difficultyLevel;  // 1: mudah, 2: sedang, 3: sulit
};

struct PlayerStats {
    int hp = 100;
    int attack = 25;
    int magic = 25;
    int counter = 25;
    int evade = 25;
    int skillPoint = 0;
};

string skillToString(Skill s) {
    switch (s) {
        case ATTACK: return "Attack";
        case MAGIC: return "Magic";
        case COUNTER: return "Counter";
        case DODGE: return "Dodge";
        default: return "Unknown";
    }
}

Skill getRandomSkill() {
    return static_cast<Skill>(rand() % 4);
}

string resolveBattle(Skill player, Skill enemy) {
    if (player == enemy)
        return "draw";
    if ((player == ATTACK && enemy == MAGIC) ||
        (player == MAGIC && enemy == COUNTER) ||
        (player == COUNTER && enemy == ATTACK))
        return "player";
    return "enemy";
}

bool attemptDodge(PlayerStats& player, Enemy& enemy) {
    int base = 30 * enemy.difficultyLevel;
    float successChance = static_cast<float>(player.evade) / base;
    float roll = static_cast<float>(rand()) / RAND_MAX;

    cout << "\nDodge attempt (peluang: " << (int)(successChance * 100) << "%) ";
    cout << flush;
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500)); // jeda 0.5 detik per titik
        cout << "." << flush;
    }
    cout << endl;

    if (roll < successChance) {
        cout << "Berhasil menghindar!\n";
        return true;
    } else {
        cout << "Gagal menghindar! Musuh menyerang!\n";
        return false;
    }
}

// Fungsi ASCII
string getEnemyAscii(const Enemy& enemy) { 
    if (enemy.name == "Tung Tung Sahur") {
        return R"(
            :::::::           
           .::: ::;.          
           .+x+.+X;.          
           :;x;:++::          
           .;.;:;:::          
            +;::;:;.          
            +:;.::+.          
           ;+:. ::+;          
          :;;:. ::++;         
          +;+.. ::;.;.        
         .+X:.. ::;;X:        
       ::;:..:+.+:: :         
    .;.::   ;.: :.;           
  ::: ;.    +:   ;;           
 :. ;:      ;:   :;           
  ::        ;;  .::           
         .;;.;: + :;:         
         ;+;;.   :++;                
        )";  
    } else if (enemy.name == "Tralalero Tralala") {
        return R"(
                         :;                       
                       :; +                       
                      :. :.                     ;:
                 .:;+:   ..                   :+. 
         :+:::            :.                 ;;.  
    ;::.           ::.      ;.             :::.   
 ;:       ++       .+x;       ::          ;:::    
:;;..  :::::::::;;;;;;.         :;   .   :.:.     
   :;++::.                        .:.;::;. ;      
        :;;::.        .;  :. :::  :::::::;;.      
              ;::;:.    :. ::   .; ;;;; :;;:      
             :. ;.   ::;:+  :;;;;.;;.;+.  ::      
            :;:.;;        +  ;    ;$+.:+          
          :x;   :::       :. ;   x:: :x;          
       .;;:.+++;::X     .;.;:X;: ;+X+:            
     +::::::;::;++.    :xX+.;x: :                 
                     :Xxx;    :+:                 
                  .;:;+:  x:;x:.+                 
               :+.        ;;+. .:                 
              :;:     .:+:.;+.                    
                 .;+++;.                          
        )";
    } else if (enemy.name == "Bombardilo Crocodilo") {
        return R"(
                                          ...                                
                         +*+:        .=*****+=-.        :                    
                        .%#*=:     :=*%#%#**++=-..     :%*:         ::       
                        -%%#+=. .:=#####****+++====-:.  .#%=.     :*#=       
                        +%%%**+****************#%#*+====-:*%#=:: =#*:        
               .:::::...*%%#**######%#%%%%#*#%%%%%@@%***=+*%%%*++*=.         
              :*##******#%%#%#*###%%%%%%###%%###%%@%%%%#*+===*%%#+:          
                 :-=*#%%%%#*%@%*==*%%%%%%%%%%%%%##########**+==+*+--=:       
       :--:----------==+*###%@@%#+==*%%%%%%@%%%%%%%%%%%%######%%%%#++=:      
     .=++*+++========+**%%%%%%@@%#**+*%%%%%@%%%%%%@@%%%%%%%%%%%%%#**+==.     
     :*#********++*****#%%%%#*%@%%*+=%%%%@@@%%%####%%%@@%%*##*#%#%#**=:.     
      .:::::-===+***###%%%%%##%@%%#**%%%%%%%%%######%%%%@%%***=: :....       
                       :*%%%%%%@@%%*+*%%%%%%%%%#***#%##%#%%#*+==:            
                         :+#%%@@%*+-     :=+*****=:.-+*#####*%*==*-.         
                             -%%-.             +*      .:=+*##**++=-         
                             *%+               +*           :-***+=:         
                             ::            .. -**=                           
                                          :%%*#%%=:.                         
                                          =%%%%%%#**=.                       
                                           .:%%%%%%%**:                      
                                              =*%%%%%*-                      
                                                 .:..                                                                                                          
        )";
    } else if (enemy.name == "Brbr Patapim") {
        return R"(
             .::::::                
         ::::::::;:::;.             
         ;:...;;;:;;::::            
        .;;;;;  :;:;+;:;:           
       :::x;;  .;+;+::              
      ::;+:;; .;;x; ::              
     .:;;;::: .::::: :              
     .;;;;;:;. :. :;: :             
     .+;.x;:::;;;;;;..              
    .++;:Xx;. ;::;X;:               
    ;;+;;;+:  :::x+;:.              
    ::::;x;:..;:++.+:.              
  .;;:;;;x+;:; ;;:++;+.             
 .:::+;:;+;;.++++;;;+;x:            
  .;++;xx;;::++++:;:;;+;            
  .+:+;;+.:.: ;:;+ .:;:::           
  :.:: .  ;;:::::.    :;;;;::...    
  :.      .:::::::.:::..   :::;;+;. 
   ...:.  .:::;:::.:: :;;+;.  :::;: 
       :::: :; ;::;.;;    ; .:;;:   
          .;;+;;;;+;;+:::.          
        )";
    } else if (enemy.name == "Boborito Bandito") {
        return R"(
            ..-=-.:-:.                  
          ..=+@++++++*.                 
          .=++++++++++*.                
         .-@@@@@@@@@@@@=:...            
      :%@@@%==========+@#@@#.           
      .-%*#==%*=***+=%#+++...           
      ..+*=++=-=@#%@-=++=%:.            
      .-+==*#==--+---*#%+=*:.           
     .+*===+*=--=**---=*===#.           
      .%*=======*=-+======#=.           
   .+*++@#*%++#====+=##+%%+++..         
  .*+*++%###+%..%%#%.:*+%#++**..        
..#+++*+*#*++++=.@@:=#+++#++*++.    ..  
.*++++#+#*%*++%#%###+*++*+++*++=...+#-  
*+**++*++*#%##%%#%#*#**#########=:#:*:..
+++++%*****#****%***#*#*********%%%**%**
++++++++*%@%#%%******@@@#*%###%%#.......
:*++++*-##***#%##%#%%%+++#***#*++.      
...=*+#%%****##++*####+++++#+++*..      
    .+++*###%*+*+*###*#+#**+-..         
    .#####+++++**#+###+++*#*+.          
    .+++++++++++#+*+++++++++*.          
    -++++++++++#+++*++++++++*.          
        )";
    } else if (enemy.name == "Bombombini Guzini") {
        return R"(
             +=-                                       
           =-:+**+                                     
          -===++==+    ---         ===                 
         :::+***+*##   +**        -***                 
               *##%#  +*##*      =+**                  
               ===+*+ +###*     -+***                  
              --:::-=+*###*     ****                   
         **+*+-:::::=*****##+  *****                   
         ***++-:-----====+++===++++++++===++===+==+++==
       ------=+**+=*#*+=++#******+=+%%#%==-  *#%%#+++  
   -=*+-*++==*=+#*+=-+**=*=*#****+=+#%%%+=-  *#%%%===  
+*%*=-*+%##+=+=*****###*++=*******=::---       :--     
 +*%+==-=++=     *+##*=+++#*##+                        
                   ++==+*** +++                        
                   +**      +++                        
                 +****+     *#*++                      
                +==++=+=  +==+*++=                     
                   ++       =++=                       
        )";
    }
    return 0;
}


// Fungsi pertarungan
bool fightEnemy(PlayerStats& player, Enemy& enemy) {
    cout << flush;
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(1000)); // jeda 1 detik per titik
        cout << "." << flush;
    }
    cout << endl;

    cout << "\n=== Lawan " << enemy.name << " (HP: " << enemy.hp << ") ===\n" << endl;

    cout << getEnemyAscii(enemy) << "\n\n";

    cout << "Pilihan Aksi:\n";
    cout << "1. Attack  - Serangan langsung, menang melawan Magic.\n";
    cout << "2. Magic   - Serangan sihir, menang melawan Counter.\n";
    cout << "3. Counter - Menangkis serangan fisik, menang melawan Attack.\n";
    cout << "4. Dodge   - Menghindari serangan, tergantung stat evade.\n";

    int choice;
    while (true) {
        cout << "Pilih aksi [1-4]: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 4.\n";
        } else {
            break;
        }
    }

    Skill playerSkill = static_cast<Skill>(choice - 1);
    Skill enemySkill = getRandomSkill();

    cout << "\nKamu: " << skillToString(playerSkill) << "  |  Musuh: " << skillToString(enemySkill) << endl;
    cout << flush;
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500)); // jeda 0.5 detik per titik
        cout << "." << flush;
    }
    cout << endl;

  if (playerSkill == DODGE) {
        bool sukses = attemptDodge(player, enemy);
        if (sukses) return true;
        else {
            player.hp -= enemy.hp;
            cout << "HP berkurang -" << enemy.hp << ". Sisa HP: " << player.hp << endl;
            return player.hp > 0;
        }
    }

    string result = resolveBattle(playerSkill, enemySkill);

    if (result == "draw") {
        cout << "\nSerangan imbang! Tidak ada pemenang.\n";
        return false;
    } else if (result == "player") {
        cout << "\nKamu menang dalam satu ronde!\n";
        player.hp += enemy.hp;
        // if (player.hp > 100) player.hp = 100; biar ga op
        cout << "\nKamu dapat +" << enemy.hp << " HP. Total HP: " << player.hp << endl;
        return true;
    } else {
        cout << "\nKamu kalah dalam satu ronde! -" << enemy.hp << " HP.\n";
        player.hp -= enemy.hp;
        if (player.hp <= 0) {
            cout << "\nHP kamu 0! Game Over!\n";
            return false;
        } else {
            cout << "\nHP tersisa: " << player.hp << endl;
            return true;
        }
    }
}

void battle(PlayerStats& player, queue<Enemy>& enemyQueue) {
    while (!enemyQueue.empty() && player.hp > 0) {
        Enemy current = enemyQueue.front();
        enemyQueue.pop();

        bool lanjut = fightEnemy(player, current);
        if (!lanjut && player.hp <= 0) return;
    }

    if (player.hp > 0)
        cout << "\nKamu berhasil menghadapi semua musuh!\n";
}

int main() {
    srand(time(0));
    PlayerStats player;

    queue<Enemy> musuh;
    musuh.push({"Tung Tung Sahur", 30, 1});
    musuh.push({"Tralalero Tralala", 40, 2});
    musuh.push({"Bombardilo Crocodilo", 50, 3});
    musuh.push({"Brbr Patapim", 30, 1});
    musuh.push({"Boborito Bandito", 40, 3});
    musuh.push({"Bombombini Guzini", 60, 2});

    cout << "\n===================";
    cout << "\n    Suit Battle    ";
    cout << "\n===================\n";
    cout << "\nNote: HP awal kamu adalah 100\n";

    battle(player, musuh);

    return 0;
}
