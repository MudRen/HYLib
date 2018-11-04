// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// udb
// Ñ©É½¹Âºè
// [1;31m¡¾·ÉÌìÓù½£Á÷¡¿[1;31m´«ÈË[2;37;0m
// 3355087
// ÄÐÐÔ
// blade
// ¾ÓºÏµ¶





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÇåÐ¥Ò»Éù£¬³åÌì¶øÆð,ÉýÖÁ×î¸ßµã¿ªÊ¼ÏÂÂäÖ®Ê±£¬ºöÈ»ÒÔ×Ô¼ºÎªÔ²ÐÄ£¬ÒÔÊÖ±Û¼ÓÉÏ´ó°ãÈô³¤¹âÎª°ë¾¶³öµ¶£¬»®³öÒ»µÀÍêÃÀÔ²»¡,ÊÖÖÐ$w¶Ô×¼$nµÄ$lÅüÈ¥",
"force" :60,
"damage" :40,
"damage_type": "¸îÉË",
"lvl" : 0,
"skill_name" : "ÃØ½££ªÑà·µ"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"¾ÓºÏµ¶"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
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
    level = (int)me->query_skill("juhublade-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
