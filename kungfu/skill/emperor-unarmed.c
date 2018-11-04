// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xlssi
// Ð¦ÄªÎÊ
// ²É»¨Ð¡Ôô
// 8556053
// ÄÐÐÔ
// unarmed
// »ÊÈ­





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÒ»ÕÐÊ¼»Ê¶¨ÌìÏÂ,Ë«È­Æ½Æ½ÍÆÏò$nµÄÉÏÖÐÏÂÈýÂ·,Á³ÉÏ²»Å­×ÔÍþ,´óÓÐºáÉ¨ÁùºÏ,Æ½¶¨ËÄ·½µÄ°ÔÆø",
"force" :60,
"damage" :40,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "Ê¼»Ê¶¨ÌìÏÂ"
]),
// ZHAOSHI :1

([
"action" :"$NÑÛÖÐ¾«¹â´óÉÁ,Ò»Ê½¸ß×æÕ¶°×Éß,»¯È­ÎªÕÆ,Ð®ÕâÒ»¹ÉÅæ²»¿ÉÓùÄÚ¾¢,ÇÐÏò$nµÄ$l",
"force" :90,
"damage" :60,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "¸ß×æÕ¶°×Éß"
]),


// ZHAOSHI :2

([
"action" :"$N×óÕÆ»÷ÏòÓÒÈ­,×óÓÒ»¥²©,ºöÈ»Ë«ÊÖÆë³ö,¹¥Ïò$nµÄ$l,Ò»Ê½ÃÏµÂ¶·ÐþµÂÁîÈË¶úÔÎÄ¿Ñ£,ÎÞ´ÓÕÐ¼Ü.",
"force" :120,
"damage" :80,
"damage_type": "ðöÉË",
"lvl" : 2,
"skill_name" : "ÃÏµÂ¶·ÐþµÂ"
]),
// ZHAOSHI :3

([
"action" :"$NÒ»Ê½ÎÄµÛÊÂ¼ÚºÌ,ÃæÂ¶´ÈÏéÖ®É«,Ë«ÊÖ»º»ºÏò$n¹¥È¥,³äÂú»³ÈáÌìÏÂÖ®Òâ",
"force" :150,
"damage" :100,
"damage_type": "ðöÉË",
"lvl" : 3,
"skill_name" : "ÎÄµÛÊÂ¼ÚºÌ"
]),
// ZHAOSHI :4

([
"action" :"$NµÄ³öÊÖºöÈ»È«ÎÞ°ëµãÓàµØ,ÓöÉñÉ±Éñ,Óö·ðÕ½·ð,Áî$n²»º®¶øü,ÕâÕýÊÇÌ",
"force" :180,
"damage" :120,
"damage_type": "ðöÉË",
"lvl" : 4,
"skill_name" : "Ì«×ÚÆðÐþÎä"
]),
// ZHAOSHI :5

([
"action" :"$NË«ÍÈÐý×ªÈç·ç,Ò»ÕÐËÎÌ«×æ¹÷´òÌìÏÂ,$n·½Ô²ÊýÕÉ½Ô±»ÍÈ·ç°üÎ§",
"force" :210,
"damage" :140,
"damage_type": "ðöÉË",
"lvl" : 5,
"skill_name" : "¹÷´òÌìÏÂ"
]),
// ZHAOSHI :6

([
"action" :"$N»¯ÍÈÎª¼ý,Ö±²å$nµÄ$l,Ò»Ê½Íä¹­Éäµñ³äÂú×Å³É¼ªË¼º¹Æ½¶¨ÌìÏÂµÄ¿ñ°Á",
"force" :240,
"damage" :160,
"damage_type": "ðöÉË",
"lvl" : 6,
"skill_name" : "Íä¹­Éäµñ"
]),
// ZHAOSHI :7

([
"action" :"ºöÈ»ÌìµØÒ»Æ¬ÏôÉ±,$NµÄÖìÔªè°É±ÒâÒÑÈ»·¢¶¯,ÎÞÊýÉ±ÆøÄÚ¾¢Ö±³å$nµÄ$l",
"force" :270,
"damage" :180,
"damage_type": "ðöÉË",
"lvl" : 7,
"skill_name" : "É±Òâ"
]),
// ZHAOSHI :8

([
"action" :"$NµÄÄÚÏ¢Á÷×ªÈ«Éí,ÎÞ´¦·¢Ð¹,´óºÈÒ»Éù,ÎÞÒâÖÐÊ¹³öÁË»ÊÈ­µÄ²»ÃÕÖ®´«----¿µÇ¬Ê¢ÊÀ,",
"force" :300,
"damage" :200,
"damage_type": "ðöÉË",
"lvl" : 8,
"skill_name" : "¿µÇ¬Ê¢ÊÀ"
]),
// ZHAOSHI :9

([
"action" :"$N·¢Ç°ÈËÎ´·¢,´´³öÁË×Ô¼ºµÄ»ÊÈ­,¿ìÒâÎÞ±È,Ò»È­ºäÏò$nµÄ$l",
"force" :330,
"damage" :220,
"damage_type": "ðöÉË",
"lvl" : 9,
"skill_name" : "»ÊÈ­"
]),
// ZHAOSHI :10

([
"action" :"$NÒ»ÕÐ¾ý,»ÊµÀ°ÔÆø³åÌì¶ø³ö,Ö±Ö¸$n",
"force" :360,
"damage" :240,
"damage_type": "ðöÉË",
"lvl" : 10,
"skill_name" : "¾ý"
]),
// ZHAOSHI :11

([
"action" :"$NÒ»ÕÐÁÙ,$nÖ»¾õµÃ$NµÄÆøÊÆÎÞ´¦²»ÔÚ,Õý¾ªÑÈÊ±,ÉíÉÏÒÑÖÐÊýÕÐ",
"force" :390,
"damage" :260,
"damage_type": "ðöÉË",
"lvl" : 11,
"skill_name" : "ÁÙ"
]),
// ZHAOSHI :12

([
"action" :"$NÒ»ÕÐÌì,ÒÑ¾­ºÍÌìµØ»¯ÎªÒ»Ìå,ÎÞ·ìÎÞÏ¶,ÂþÌìÕÆÁ¦ÕÖÏò$n",
"force" :420,
"damage" :280,
"damage_type": "ðöÉË",
"lvl" : 12,
"skill_name" : "Ìì"
]),
// ZHAOSHI :13

([
"action" :"$NÒ»ÕÐÏÂ,ÉíÐÎ°Î¸ßÊýÕÉ,½èÏÂÂäÖ®ÊÆ,Ë«È­ºäÏò$nµÄ¶¥ÃÅ",
"force" :450,
"damage" :300,
"damage_type": "ðöÉË",
"lvl" : 13,
"skill_name" : "ÏÂ"
]),
// ZHAOSHI :14

([
"action" :"$NµÍÍ·Ú¤Ïë£¬Ò»ÕÐºÅ,ÓÉÄÚÁ¦·¢³ö,ÕðÏò$n",
"force" :480,
"damage" :320,
"damage_type": "ðöÉË",
"lvl" : 14,
"skill_name" : "ºÅ"
]),
// ZHAOSHI :15

([
"action" :"$NÒ»ÕÐÁîË«ÕÆ»Î³öÇ§ÍòÕÆÓ°½«$nµÄ$lÁýÕÖÔÚÕÆÁ¦Ö®ÏÂ",
"force" :510,
"damage" :340,
"damage_type": "ðöÉË",
"lvl" : 15,
"skill_name" : "Áî"
]),
// ZHAOSHI :16

([
"action" :"$N´í²½ÉÏÇ°£¬Ò»ÕÐÖÚ,ÕÐÕÐÇÀÏÈ£¬ÒÔ¿ì´òÂý£¬Ò»¸ö×ªÉíÒÑ¾­×ªµ½ÁË$nµÄÉíºó£¬ÔËÖ¸Èç·çµãÏò$nµÄÈ«ÉíÒªÑ¨",
"force" :540,
"damage" :360,
"damage_type": "ðöÉË",
"lvl" : 16,
"skill_name" : "ÖÚ"
]),
// ZHAOSHI :17

([
"action" :"$NÒ»ÕÐÉú,$n±¾ÎÞÍËÂ·,ºöÈ»$NÈÃ³öÉúÃÅÒ»Ë¿",
"force" :570,
"damage" :380,
"damage_type": "ðöÉË",
"lvl" : 17,
"skill_name" : "Éú"
]),
// ZHAOSHI :18

([
"action" :"$NÒ»ÕÐÌìÏÂÎÞµÐ,Ë«È­ºäÏò$nµÄ$l",
"force" :600,
"damage" :400,
"damage_type": "ðöÉË",
"lvl" : 18,
"skill_name" : "ÌìÏÂÎÞµÐ"
]),
// ZHAOSHI :19

([
"action" :"$NÒ»ÕÐÎäºóÀí³¯,×öÅ®ÈË×´,$n¿´ÔÚÑÛÀï,ÐÄÖÐÒ»Õó¶ñÐÄ,ÒÑ¾­ÖÐÁËÑÏÖØÄÚÉË",
"force" :630,
"damage" :420,
"damage_type": "ðöÉË",
"lvl" : 19,
"skill_name" : "ÎäºóÀí³¯"
]),
 });
// ZHAOSHI :20
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"»ÊÈ­"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"»ÊÈ­"+"¡£\n");
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
    level = (int)me->query_skill("emperor-unarmed",1);
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
