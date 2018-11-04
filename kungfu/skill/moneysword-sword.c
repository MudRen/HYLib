// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xnono
// ÆÐÌáÀÏÖí
// »ðÑæ½Ì¡¡µÚÈý´úµÜ×Ó
// 6550749
// ÄÐÐÔ
// sword
// ·¢²Æ½£·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N×óÊÖÐé»Î£¬ÓÒÊÖµÄ·ÜÁ¦Ë¦³ö£¬Ò»ÕÐÕ£¬ÊÖÖÐµÄ³¤½£Ö±Ïò$nµÄ¸¹²¿ÔúÈ¥",
"force" :60,
"dodge" :40,
"damage_type": "´ÌÉË",
"lvl" : 0,
"skill_name" : "ÕÐ²Æ½ø±¦"
]),
// ZHAOSHI :1

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÓÒÊÖµÄ$wÑ¸ËÙ½»»»µ½×óÊÖ£¬Ò»ÕÐÍ£¬½£ÒÔÒ»ÒâÏë²»µ½µÄ½Ç¶È´ÌÏò$nµÄÄ³²¿",
"force" :90,
"dodge" :60,
"damage_type": "´ÌÉË",
"lvl" : 1,
"skill_name" : "ÍµÁº»»Öù"
]),
// ZHAOSHI :2

([
"action" :"look",
"force" :120,
"dodge" :80,
"damage_type": "´ÌÉË",
"lvl" : 2,
"skill_name" : "Ç§É½Á÷Ë®"
]),
// ZHAOSHI :3

([
"action" :"$NÊ¹³ö¡¸Íò·ð¹é×Ú¡¹£¬ÊÖÖÐ$wÍì³öÈý¸ö½£»¨£¬ÃàÃà²»¶Ï»®Ïò$nµÄ×ó±Û£¡",
"force" :150,
"dodge" :100,
"damage_type": "´ÌÉË",
"lvl" : 3,
"skill_name" : "Íò·ð¹é×Ú"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"·¢²Æ½£·¨"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("moneysword-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
