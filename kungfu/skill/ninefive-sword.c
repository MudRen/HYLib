// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tianyu
// °×ÈçÃÎ
// [1;35mÌúÕÆ°ïÉÏ¹Ù°ïÖ÷µÜ×Ó[2;37;0m
// 2219919
// ÄÐÐÔ
// sword
// ¾ÅÎåÖ®½£





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÒ»½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :60,
"damage" :40,
"damage_type": "´ÌÉË",
"lvl" : 0,
"skill_name" : "¾ÅÎåµÚÒ»½£"
]),
// ZHAOSHI :1

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚ¶þ½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :90,
"damage" :60,
"damage_type": "´ÌÉË",
"lvl" : 1,
"skill_name" : "¾ÅÎåµÚ¶þ½£"
]),
// ZHAOSHI :2

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÈý½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :120,
"damage" :80,
"damage_type": "´ÌÉË",
"lvl" : 2,
"skill_name" : "¾ÅÎåµÚÈý½£"
]),
// ZHAOSHI :3

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚËÄ½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :150,
"damage" :100,
"damage_type": "´ÌÉË",
"lvl" : 3,
"skill_name" : "¾ÅÎåµÚËÄ½£"
]),
// ZHAOSHI :4

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÎå½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :180,
"damage" :120,
"damage_type": "´ÌÉË",
"lvl" : 4,
"skill_name" : "¾ÅÎåµÚÎå½£"
]),
// ZHAOSHI :5

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÁù½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :210,
"damage" :140,
"damage_type": "´ÌÉË",
"lvl" : 5,
"skill_name" : "¾ÅÎåµÚÁù½£"
]),
// ZHAOSHI :6

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÆß½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :240,
"damage" :160,
"damage_type": "´ÌÉË",
"lvl" : 6,
"skill_name" : "¾ÅÎåµÚÆß½£"
]),
// ZHAOSHI :7

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚ°Ë½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :270,
"damage" :180,
"damage_type": "´ÌÉË",
"lvl" : 7,
"skill_name" : "¾ÅÎåµÚ°Ë½£"
]),
// ZHAOSHI :8

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚ¾Å½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :300,
"damage" :200,
"damage_type": "´ÌÉË",
"lvl" : 8,
"skill_name" : "¾ÅÎåµÚ¾Å½£"
]),
// ZHAOSHI :9

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÊ®½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :330,
"damage" :220,
"damage_type": "´ÌÉË",
"lvl" : 9,
"skill_name" : "¾ÅÎåµÚÊ®½£"
]),
// ZHAOSHI :10

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåµÚÊ®Ò»½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :360,
"damage" :240,
"damage_type": "´ÌÉË",
"lvl" : 10,
"skill_name" : "¾ÅÎåµÚÊ®Ò»½£"
]),
// ZHAOSHI :11

([
"action" :"$N×ÝÉíÒ»Ô¾£¬ÊÖÖÐ$wÒ»ÕÐ¡¸¾ÅÎåÖ®Ê®¶þ½£¡¹¶Ô×¼$nµÄ$lÐ±Ð±´Ì³öÒ»½£",
"force" :390,
"damage" :260,
"damage_type": "´ÌÉË",
"lvl" : 11,
"skill_name" : "¾ÅÎåÖ®Ê®¶þ½£"
]),
 });
// ZHAOSHI :12
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"¾ÅÎåÖ®½£"+"¡£\n");
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
    level = (int)me->query_skill("ninefive-sword",1);
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
