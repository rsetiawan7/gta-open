#include <YSI_Coding\y_hooks>

hook OnMySQLConnected()
{
    static const query[] = "\
        CREATE TABLE IF NOT EXISTS armys \
        (\
            u_id int(11) NOT NULL AUTO_INCREMENT,\
            IsArmy tinyint(4) NOT NULL DEFAULT '0',\
            Blacklisted tinyint(4) NOT NULL DEFAULT '0',\
            PRIMARY KEY (u_id), \
            FOREIGN KEY (u_id) REFERENCES players(u_id) \
            ON DELETE CASCADE \
            ON UPDATE RESTRICT \
        )";
    mysql_tquery(MySQL_GetHandle(), query);

    log("setting up 'armys' table...");
    return 1;
}   