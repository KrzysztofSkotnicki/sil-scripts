IncomingEmail mail = getIncomingEmail();
if(mail.to == "jira-costam@domena.pl") {


string issueKey = matchText(mail.subject, "[A-Z][A-Z]+-[0-9]+"); // find an issue key in the subject
if(isNull(issueKey)) {
    // if no issue key found, create a new issue
    string [] fields = {};
    fields += {"reporter", getUserByEmail(mail.from[0]).key};
    fields += {"assignee", getUserByEmail(mail.to[0]).key};
 
    string newIssue = createIssue(
      "KLUCZPROJEKTU", //projectKey
      "", //parentIssueKey
      "Task", //issueType
      mail.subject, //summary
      "Major", //priority
      mail.body, //description
      {}, //components
      "", //dueDate
      "", //estimate
      "", //security_level
      "customfield_111111|" + "Opis pola"+ "|customfield_122222|" + "Opis pola"
    );

    string [] last_epic = sql("jira", "SELECT issuenum FROM jira.jiraissue where SUMMARY LIKE date_format(now(),\"Utrzymanie %Y-%m\") and issuetype = 13 and project = 12843");
    string [] last_sprint = sql("jira", "SELECT ID FROM jira.AO_60DB71_SPRINT where name LIKE date_format(now(),\"COSTAM - %Y-%m\")");
    
    
    %newIssue%.#{Epic Link} = "COSTAM-" + last_epic[0];
    %newIssue%.Sprint = last_sprint[0];
    
    attachAllFilesFromEmail(newIssue);
    %newIssue%.watchers = getUserKeysFromEmails(mail.cc);
    
    sendEmail("jira-mbox@domena.pl", getUserByEmail(mail.from[0]).key, getUserByEmail(mail.cc[0]).key, "[JIRA] "+newIssue, "Na podstawie wiadomości email utworzono zgłoszenie: https://jira.domena.pl/browse/"+newIssue  );

} else {
    // if issue key found in subject, add a comment
    addComment(issueKey, currentUserKey(), mail.body);
}
}
