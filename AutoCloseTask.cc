// sprawdza czy wszytskie sub-taski sa zamkniete i jesli maja ustawiony odpowiedni status to zamykane jest glowne zgloszenie

if(isNull(parent)) {
   return;
}
string[] subtasks = subtasks(parent);

for(string subtask in subtasks) {
    if(%subtask%.resolution != "Accepted") { //ustaw odpowiedni status
       return;
    }
}

autotransition("Done", parent, true, true, true);
parent.resolution = "Accepted"; //ustaw odpowiedni status

// opcja dodania tworzenia nowego zgłoszenia - CreateIssue.sil