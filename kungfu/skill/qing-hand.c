// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// ÇïÒâÅ¨
// [35mÖÕÄÏµÚÒ»Å®ÏÀ[2;37;0m
// 19649265
// Å®ÐÔ
// hand
// ÇïÒâËæ·çÍÈ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÒ»ÕÐ¡¸ÈçÓ°ËæÐÎ¡¹£¬×óÍÈÌß³ö£¬µ«$n»¹ÔÚÈýÕÉ¿ªÍâ£¬µ«¼û$NË²¼äÇ°ÒÆÈýÕÉ£¬ÍÈÒÑ»÷µ½$nÐØ¿Ú£¬×óÍÈÎ´ÂäÓÒÍÈÓÖ³ö£¬Ò»µÀ¾¢·çÉ¨¹ý$nÃÅÃæ",
"force" :60,
"damage" :40,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "ÈçÓ°ËæÐÎ"
]),
// ZHAOSHI :1

([
"action" :"µ«¼ûÂþÌìÍÈÓ°·ÉÎè£¬$nµÄÒÂÉÀÒÑ±»ÍÈ·çËº³ÉÒ»Æ¬Æ¬£¬É¢ÂäµØÉÏ£¬$NÉíÐÎÒ»Ô¾£¬Ò»Ê½¡¸ÍùÊÂËæ·ç¡¹£¬°ë¿ÕÖÐ×óÓÒÍÈ½ÓÁ¬ÌßÍù$nÐØ¿Ú",
"force" :90,
"damage" :60,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "ÍùÊÂËæ·ç"
]),
// ZHAOSHI :2

([
"action" :"¡¸ÔÙÉ¨ÂäÒ¶¡¹£¡$N×óÍÈºáÉ¨$nÄÔÃÅ£¬$n»ÅÃ¦ÖÐµÍÍ·±Ü¹ý£¬µ«·¢÷ÙÒÑ±»É¨Âä£¬ÀÇ±·²»¿°£¬µ«¼û$N±³¶Ô$n£¬¹ªÉíÍäÑüÓÒÍÈÍùºóÒ»¸öÍäÔÂÐÍ·´É¨£¬½Åµ×°åÖ±»÷$nÏÂ°Í",
"force" :120,
"damage" :80,
"damage_type": "ðöÉË",
"lvl" : 2,
"skill_name" : "ÔÙÉ¨ÂäÒ¶"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÇïÒâËæ·çÍÈ"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage== "hand" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("qing-hand",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
