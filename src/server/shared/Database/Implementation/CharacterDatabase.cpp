/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CharacterDatabase.h"

bool CharacterDatabaseConnection::Open()
{
    if (!MySQLConnection::Open())
        return false;

    if (!m_reconnecting)
        m_stmts.resize(MAX_CHARACTERDATABASE_STATEMENTS);

    for (uint32 index = 0; index < MAX_CHARACTERDATABASE_STATEMENTS; ++index)
    {
        PreparedStatementTable const& pst = CharacterDatabasePreparedStatements[index];        
        PrepareStatement(pst.index, pst.query, pst.type);
    }

    m_statementTable = CharacterDatabasePreparedStatements;

    PrepareStatement(CHAR_ANTICHEAT_SET_CHEATERS, "INSERT INTO cheat_reports (`guid`,`name`,`mapid`,`position_x`,`position_y`,`position_z`,`report`,`time`) VALUES (?,?,?,?,?,?,?,?);");
    PrepareStatement(CHAR_ANTICHEAT_SET_CHEATERS_TEMP, "INSERT INTO cheat_temp_reports (`guid`,`name`,`mapid`,`position_x`,`position_y`,`position_z`,`report`,`time`) VALUES (?,?,?,?,?,?,?,?);");
    PrepareStatement(CHAR_ANTICHEAT_GET_CHEATERS, "SELECT A.`name` , count( * ) AS 'Repeticiones' FROM `characters` AS A, `cheat_reports` AS B WHERE A.`online` =1 AND A.`guid` = B.`guid` GROUP BY B.`guid` ORDER BY Repeticiones DESC LIMIT 0 , 3");
    PrepareStatement(CHAR_ANTICHEAT_SET_CHEAT_FIRST_REPORT, "INSERT INTO cheat_first_report (`guid`,`name`,`time`) VALUES (?,?,?);");
    PrepareStatement(CHAR_ANTICHEAT_GET_CHEATERS_AVERAGE, "SELECT A.`name` , CAST((SUM(B.time ) / count( * ) ) - C.time AS UNSIGNED) AS 'promedio' , CAST(count( * ) AS UNSIGNED) AS 'Repeticiones' FROM `characters` AS A, `cheat_temp_reports` AS B, cheat_first_report AS C WHERE A.`online` =1 AND A.`guid` = B.`guid` AND A.guid = C.guid GROUP BY B.`guid` ORDER BY Repeticiones  DESC LIMIT 0 , 3;");
    PrepareStatement(CHAR_ANTICHEAT_GET_CHEAT_FIRST_REPORT, "SELECT * FROM cheat_first_report WHERE guid=?;");
    PrepareStatement(CHAR_ANTICHEAT_DEL_CHEAT_FIRST_REPORT, "DELETE FROM cheat_first_report WHERE guid=?");
    PrepareStatement(CHAR_ANTICHEAT_DEL_CHEATERS_TEMP, "DELETE FROM cheat_temp_reports WHERE guid=?");
    PrepareStatement(CHAR_ANTICHEAT_DEL_CHEATERS, "DELETE FROM cheat_reports WHERE guid=?");
    PrepareStatement(CHAR_ANTICHEAT_CLEAN_CHEAT_FIRST_REPORT, "DELETE FROM cheat_first_report;");
    PrepareStatement(CHAR_ANTICHEAT_CLEAN_CHEATERS_TEMP, "DELETE FROM cheat_temp_reports");
    PrepareStatement(CHAR_ANTICHEAT_CLEAN_CHEATERS, "DELETE FROM cheat_reports;");

    PrepareStatement(CHAR_ANTICHEAT_GET_CHEATERS_AVERAGE_BY_GUID,"SELECT CAST((SUM(B.time ) / count( * ) ) - C.time AS UNSIGNED) AS 'promedio' , CAST(count( * ) AS UNSIGNED) AS 'Repeticiones' FROM `characters` AS A, `cheat_temp_reports` AS B, cheat_first_report AS C WHERE A.`online` =1 AND A.`guid` = B.`guid` AND A.guid = C.guid AND A.`guid`=? GROUP BY B.`guid` ORDER BY Repeticiones  DESC LIMIT 0 , 1;");
    PrepareStatement(CHAR_ANTICHEAT_GET_CHEATERS_BY_GUID,"SELECT count( * ) AS 'Repeticiones' FROM `characters` AS A, `cheat_reports` AS B WHERE A.`online` =1 AND A.`guid` = B.`guid` AND A.`guid`=? GROUP BY B.`guid` ORDER BY Repeticiones DESC LIMIT 0 , 1");
    PrepareStatement(CHAR_ANTICHEAT_GET_REPORTS_TYPE_BY_GUID,"SELECT report FROM cheat_reports WHERE guid=?;");
    return true;
}
