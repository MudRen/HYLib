// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// yzx
// ÐÇÔÂÀË×Ó
// [1;36mº£¶ÔÃæµÄÉ³Ì²[2;37;0m
// 49089478
// ÄÐÐÔ
// unarmed
// ÌìÂíÁ÷ÐÇÈ­





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÓÒÈ­½ôÎÕ£¬ºóÍÈ½Å¼âµãµØ£¬Ò»Ê½¡¸ÃÜ¼¯Á÷ÐÇ¡¹£¬ÓÒÈ­ÓÐÈçÁ÷ÐÇ°ã£¬¹¥Ïò$nµÄÉÏÖÐÏÂÈýÂ·",
"force" :60,
"damage" :40,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "ÃÜ¼¯Á÷ÐÇ"
]),
// ZHAOSHI :1

([
"action" :"Ö»¼û$NÀ­¿ª¼ÜÊ½£¬Ò»ÕÐ¡¸Á÷ÐÇÂÓ¿Õ¡¹Ê¹µÃ»¢»¢ÓÐ·ç¡£·É¿ìµÄÆËÏò$n£¡",
"force" :90,
"damage" :60,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "Á÷ÐÇÂÓ¿Õ"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ÌìÂíÁ÷ÐÇÈ­"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÌìÂíÁ÷ÐÇÈ­"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("tianmaquan-unarmed",1);
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
