// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// ywc
// °¢ÎÄ
// Ø¤°ï¾Å´ü³¤ÀÏ
// 7336988
// ÄÐÐÔ
// unarmed
// °¢ÎÄÉñÕÆ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"*",
"force" :60,
"damage" :40,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "Ð¦¿´·çÔÆ"
]),
// ZHAOSHI :1

([
"action" :"$NÇ£×ÅMMµÄÊÖ£¬¿´Ò²²»¿´$n£¬Ò»Ê½Ö",
"force" :90,
"damage" :60,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "Ö´ÊÖÏà¿´"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"°¢ÎÄÉñÕÆ"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"°¢ÎÄÉñÕÆ"+"¡£\n");
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
    level = (int)me->query_skill("awenzhang-unarmed",1);
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
