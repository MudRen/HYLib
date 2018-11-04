// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wall
// Ììô¥¾øÒô
// ÌÒ»¨µºµÚ¶þ´úµÜ×Ó
// 3205831
// ÄÐÐÔ
// unarmed
// ½«½ø¾Æ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÍ»µØÌÚ¿Õ¶øÆð,Ò÷³öÒ»Ê×Àî°×µÄ½«½ø¾Æ¡£¡°¾ý²»¼û,»ÆºÓÖ®Ë®ÌìÉÏÀ´......¡±Ò»Ê½¾.¿ÕÖÐÕÆÓ°Èç»ÆºÓÀËÌÎÒ»ÑùÓ¿Ïò$nµÄÉÏÈýÂ·.",
"force" :60,
"dodge" :40,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "¾ý²»¼û"
]),
// ZHAOSHI :1

([
"action" :"$N³·Éí»Ø×ß,È´ÄýÉñ¾ÛÆøÓÎ×ßÈ«ÉíÉÏÏÂ,Ò»¹É°×É«ÆøÌåÁýÕÖÈ«ÉíÉÏÏÂ,$NÍ»µØË«ÊÖÏòÇ°¼²ÍË,Ê¹³öÒ»Ê½±¡£Á½µÀ°ÔµÀµÄ¾¢ÆøÏò$nµÄÍ·²¿»÷È¥.",
"force" :90,
"dodge" :60,
"damage_type": "ðöÉË",
"lvl" : 2,
"skill_name" : "±¯°×·¢"
]),
// ZHAOSHI :2

([
"action" :"$N¿´×¼¿ÕÏ¶,ÏòºóÒ»Ô¾,Ëæ×Å½«½ø¾ÆµÄµÚÈý¾ä¡°ÈËÉúµÃÒâÐè¾¡»¶,ÄªÊ¹½ðé×¿Õ¶ÔÔÂ¡±Ê¹³öµÚÈýÊ½¿£¬Ë«ÊÖºÏ³É¾Ù±­×´,ÓÉÏÂ¶øÉÏÅÄÏò$nµÄÐØ¿Ú.",
"force" :120,
"dodge" :80,
"damage_type": "ðöÉË",
"lvl" : 3,
"skill_name" : "¿Õ¶ÔÔÂ"
]),
// ZHAOSHI :3

([
"action" :"$NÒ»ÕÐ¡¸Ñà×ÓÈý³­Ë®¡¹×ÝÉíÔ¾Æð£¬Ù¿ºöÒÑÂäÖÁ$nÉíºó¡£Ë«ÊÖ¼²·÷,ºÈÒ»Éù¡°ÌìÉúÎÒ²Ä±ØÓÐÓÃ,Ç§½ðÉ¢¾¡»¹¸´À´.¡±ÕÆÁ¦Ò»²ãÒ»²ãµÄÍÆÏò$nµÄ±³²¿.ÕýÊÇÒ»Ê½».",
"force" :150,
"dodge" :100,
"damage_type": "ðöÉË",
"lvl" : 4,
"skill_name" : "»¹¸´À´"
]),
// ZHAOSHI :4

([
"action" :"$NÃæÂ¶Î¢Ð¦,ËÆºõ¿´´©ÈËÊÀ¼äµÄÒ»ÇÐ,$nÕý¾õÆæ¹ÖÖ®Ê±,Ò»ÕÐÈ.Ò»¹ÉÇ¿¾¢µÄÄÚÁ¦ÃàÃà²»¶ÏÒÑ¹¥Ïò$nµÄÏÂÈýÅÌ,$nÈ´²»Öª$NºÎÊ±³öÕÐ.$Nà«à«ÄîµÀ¡°ÅëÑòÔ×Å£ÇÒÎªÀÖ,»áÐëÒ»ÒûÈý°Ù±­¡±.",
"force" :180,
"dodge" :120,
"damage_type": "ðöÉË",
"lvl" : 5,
"skill_name" : "ÇÒÎªÀÖ"
]),
// ZHAOSHI :5

([
"action" :"$NÊÖ×ö±­×´£¬½«Ç°¼¸Ê½ºÍ¶øÎªÒ»£¬¸÷ÕÐ»¥²¹£¬Ò»Ê½¡¸½«½ø¾Æ¡¹£¬$NÀÉÉùÄîµÀ£º¡°á¯·ò×Ó£¬µ¤ÇðÉú£¬½«½ø¾Æ£¬¾ýÄªÍ££¡¡±$nÖ»¾õ´ËÕÐÍþÁ¦¾Þ´ó£¬ÕýÓÌÔ¥Ö®Ê±£¬¼¸¹ÉÇ¿¾¢ÕÆÁ¦ÒÑ¾­¹¥Ïò$nµÄÈ«ÉíÉÏÏÂ",
"force" :210,
"dodge" :140,
"damage_type": "ðöÉË",
"lvl" : 5,
"skill_name" : "½«½ø¾Æ"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"½«½ø¾Æ"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"½«½ø¾Æ"+"¡£\n");
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
    level = (int)me->query_skill("myskill-unarmed",1);
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
