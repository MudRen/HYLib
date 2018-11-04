// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// ÇïÒâÅ¨
// [35mÖÕÄÏµÚÒ»Å®ÏÀ[2;37;0m
// 11768727
// Å®ÐÔ
// unarmed
// ÇïÒâÕÆ·¨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$NÊ¹³öÒ»Ê½¡¸ÇïÑãÄÏ»Ø¡¹£¬Ò»µÀ°×¹âÒÑµ½$nÑÛÃ¼£¬½Ó×Å$NÉíÐÎÒ»×ª£¬ÔÙÒ»Ê½¡¸»ÆÒ¶ÈÔ·çÓê¡¹£¬$nÈ«Éí¶¼ÁýÕÖÔÚ½£ÆøÖÐ¡£",
"force" :60,
"damage" :40,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "ÇïÑãÄÏ»Ø"
]),
// ZHAOSHI :1

([
"action" :"Ö»¼û$N×ËÊÆÒ»±ä£¬¶ÙÊ±ÉíÐÎÈôÒþÈôÏÖ£¬¡¸ÇïÒâ¸üÉî¡¹¡¢¡¸±±·ç½­ÉÏº®¡¹Á½Ê½½ÓÁ¬·¢³ö£¬Ë«ÕÆº®Æø±ÆÈË£¬$nÒÑÎÞÍËÂ·",
"force" :90,
"damage" :60,
"damage_type": "ðöÉË",
"lvl" : 1,
"skill_name" : "ÇïÒâ¸üÉî"
]),
// ZHAOSHI :2

([
"action" :"$NÔÚ°ë¿ÕÒ»¸öÆ¯ÁÁµÄ»ØÐý£¬½ÓÁ¬Á½Ê½¡¸ÇïÁ±ÃÎ³¤¡¹·¢³ö£¬ÕÐÎ´ÖÁ£¬ÈËÒÑÈçÑÌ£¬Á¦ÒÑÖÁ¡£Ò»µÀÂÌ¹â´©¹ý$nÉíÌå",
"force" :120,
"damage" :80,
"damage_type": "ðöÉË",
"lvl" : 2,
"skill_name" : "ÇïÁ±ÃÎ³¤"
]),
// ZHAOSHI :3

([
"action" :"Ö»¼û$NµÄÉíÐÎÔÚ¿ÕÖÐ»®³öÒ»µÀÓÅÃÀµÄ»¡Ïß£¬Ò»Ê½¡¸ÇïÒ¶Æ®Áã¡¹£¬Á¬ÐøÅÄ³ö¾Å¾Å°ËÊ®Ò»ÕÆ£¬ÂþÌìÕÆÓ°Æ®Èç»ÆÒ¶·ÉÂä£¬$n±»ÄÇË²¼äµÄÑ¤ÃÀ¾ª´ôÁË",
"force" :150,
"damage" :100,
"damage_type": "ðöÉË",
"lvl" : 3,
"skill_name" : "ÇïÒ¶Æ®Áã"
]),
// ZHAOSHI :4

([
"action" :"$NµÍÌ¾Ò»Éù£¬µ¥ÕÆÎ¢Î¢Ò»É¨£¬Ò»Ê½¡¸Çï·çÕ§Æð¡¹·÷³ö¡£$n¶ÙÊ±¸Ðµ½ÌìµØÆàÁ¹£¬ÊÀÊÂËöÉ²£¬ÈËÉúÁËÎÞÉúÈ¤£¬²»ÓÉÉíÐÎÂýÁËÏÂÀ´",
"force" :180,
"damage" :120,
"damage_type": "ðöÉË",
"lvl" : 4,
"skill_name" : "Çï·çÕ§Æð"
]),
// ZHAOSHI :5

([
"action" :"$N¸Ð¿®ÎÞÊý£¬·ÅÆú·ÀÊØ£¬Ë«ÕÆÂÖ»Ó£¬ÇïÒâÕÆ·¨¶þÊ®ËÄÊ½ÖÕ¼«ÕÐÊõ¡¸Çïº®ÒÀÈ»¡¹·¢³ö£¬´ËÒàÒ»Ê±£¬×óÊÖÍù$n×óÀßÏÂ´ò³öÈýÕÆ£¬±ËÒàÒ»Ê±£¬ÓÒÊÖÍù$nÓÒÀßÔÙ³öÈýÕÆ",
"force" :210,
"damage" :140,
"damage_type": "ðöÉË",
"lvl" : 5,
"skill_name" : "Çïº®ÒÀÈ»"
]),
// ZHAOSHI :6

([
"action" :"$NÒ»ÕÐ¡¸ÇïÓ°ËæÐÎ¡¹£¬×óÍÈÌß³ö£¬$nÈ´»¹ÔÚÈýÕÉ¿ªÍâ£¬µ«¼û$NË²¼äÇ°ÒÆÈýÕÉ£¬ÍÈÒÑ»÷µ½$nÐØ¿Ú£¬×óÍÈÎ´ÂäÓÒÍÈÓÖ³ö£¬Ò»µÀ¾¢·çÉ¨¹ý$nÃÅÃæ",
"force" :240,
"damage" :160,
"damage_type": "ðöÉË",
"lvl" : 6,
"skill_name" : "ÇïÓ°ËæÐÎ"
]),
// ZHAOSHI :7

([
"action" :"µ«¼ûÂþÌìÍÈÓ°·ÉÎè£¬$nµÄÒÂÉÀÒÑ±»ÍÈ·çËº³ÉÒ»Æ¬Æ¬£¬É¢ÂäµØÉÏ£¬$NÉíÐÎÒ»Ô¾£¬Ò»Ê½¡¸ÍùÊÂËæ·ç¡¹£¬°ë¿ÕÖÐ×óÓÒÍÈ½ÓÁ¬ÌßÍù$nÐØ¿Ú",
"force" :270,
"damage" :180,
"damage_type": "ðöÉË",
"lvl" : 7,
"skill_name" : "ÍùÊÂËæ·ç"
]),
// ZHAOSHI :8

([
"action" :"¡¸ÔÙÉ¨ÂäÒ¶¡¹£¡$N×óÍÈºáÉ¨$nÄÔÃÅ£¬$n»ÅÃ¦ÖÐµÍÍ·±Ü¹ý£¬µ«·¢÷ÙÒÑ±»É¨Âä£¬ÀÇ±·²»¿°£¬µ«¼û$N±³¶Ô$n£¬¹ªÉíÍäÑüÓÒÍÈÍùºóÒ»¸öÍäÔÂÐÍ·´É¨£¬½Åµ×°åÖ±»÷$nÏÂ°Í",
"force" :300,
"damage" :200,
"damage_type": "ðöÉË",
"lvl" : 8,
"skill_name" : "ÔÙÉ¨ÂäÒ¶"
]),
// ZHAOSHI :9

([
"action" :"$NµÄÉíÐÎÔÚ°ë¿Õ¼±ËÙÐý×ª£¬ÝëÈ»Ò»¸öÐý×ª£¬·Â·ð·ï»ËÚíÅÍ£¬Ìì£¡Ëæ£¡ÈË£¡Ô¸£¡$N×ó½ÅÒÑ¾­²ÈÉÏ$nµÄÐØ¿Ú£¬ÓÒ½ÅÈ´Ö±ÌßÄÔ¸Ç£¬¿´À´ÒªÊÇ±»ÌßÖÐ£¬$n·Çµß¼´Éµ",
"force" :330,
"damage" :220,
"damage_type": "ðöÉË",
"lvl" : 9,
"skill_name" : "ÌìËæÈËÔ¸"
]),
// ZHAOSHI :10

([
"action" :"ºöÈ»£¬ÌìµØ¼äÒ»Æ¬¼Å¾²£¬$NÒ»Í··ÉÎèµÄ³¤·¢ÔÚÄÔºó¾²¾²É¢Âä£¬Ð¡ÓãÕýÄÉÃÆ£¬´º£¡Ëæ£¡ÈË£¡Òâ£¡$NµÄ³¤·¢ÔÙ´ÎÆ®ÁËÆðÀ´£¬$n¾¹Ã»¿´Çå³þ$NµÄ³ö½Å",
"force" :360,
"damage" :240,
"damage_type": "ðöÉË",
"lvl" : 10,
"skill_name" : "´ºËæÈËÒâ"
]),
// ZHAOSHI :11

([
"action" :"Ö»¼û$NÒ»Í·³¤·¢ÔÚÄÔºó·ÉÎè²»Í££¬ÉíÓ°Æ®ºö¼ä£¬Çï£¡Ëæ£¡ÎÒ£¡Òâ£¡½ÓÁ¬Ìß³öÒ»Ê®°ËÍÈ£¬$nÒ»Õó»èÑ££¬È´Ö»¼û$NÔÚÔ­µØË«ÊÖºÏÊ®£¬·Â·ðÌìÉÏµØÏÂ£¬Î¨Çï¶À×ð",
"force" :390,
"damage" :260,
"damage_type": "ðöÉË",
"lvl" : 11,
"skill_name" : "ÇïËæÎÒÒâ"
]),
// ZHAOSHI :12

([
"action" :"$nÒÑÉúÇÓÒâ£¬ÕýÏëÌÓÅÜ£¬$N´óºÈÒ»Éù£º¡°Êó±²£¡´óµ¨£¡¡±£¬Ò»ÕÐ¡¸È±ÔÂ¹ÒÊèÍ©¡¹£¬ÎåÖ¸ÕÅ¿ª£¬Ö±×¥$nµÄÌìÁé¸Ç",
"force" :420,
"damage" :280,
"damage_type": "ðöÉË",
"lvl" : 12,
"skill_name" : "È±ÔÂ¹ÒÊèÍ©"
]),
// ZHAOSHI :13

([
"action" :"$nÑÛ¿´°Ü¾ÖÒÑ¶¨£¬Õýß´ß´ÍáÍáÖÐ£¬$NÒ»ÉùºÈ¶Ï£º¡°±Õ×ì£¡£¡¡±£¬Ò»Ê½¡¸Â©¶ÏÈË³õ¾²¡¹£¬Íù$n×óÁ³Ò»¸ö¶ú¹âñøÈ¥",
"force" :450,
"damage" :300,
"damage_type": "ðöÉË",
"lvl" : 13,
"skill_name" : "Â©¶ÏÈË³õ¾²"
]),
// ZHAOSHI :14

([
"action" :"$nÍùºóÒ»Ô¾£¬ÒÑÌÓµ½ÈýÕÉ¿ªÍâ£¬$NÒ»Ê½¡¸ÓÄÈË¶ÀÍùÀ´¡¹£¬Ë²¼äÀ¹ÔÚ$nÃæÇ°£º¡°Ã»³öÏ¢£¡£¡¡±£¬Ï¬ÀûÒ»Ö¸µãµ½$nÃ¼¼ä",
"force" :480,
"damage" :320,
"damage_type": "ðöÉË",
"lvl" : 14,
"skill_name" : "ÓÄÈË¶ÀÍùÀ´"
]),
// ZHAOSHI :15

([
"action" :"$NÂõÆð¾øÊÀ²½·¨¡¸Æ®Ãì¹ÂºèÓ°¡¹£¬Ë²¼äÎ§ÈÆ$n¼±×ª¾Å¾Å°ËÊ®Ò»È¦£¬$nÒ»ÕóÑÛ»¨çÔÂÒ£¬ÔÎµ¹ÔÚµØ",
"force" :510,
"damage" :340,
"damage_type": "ðöÉË",
"lvl" : 15,
"skill_name" : "Æ®Ãì¹ÂºèÓ°"
]),
// ZHAOSHI :16

([
"action" :"$NÌáÆðÕæÆø£¬Ê©³ö¾øÊÀÇá¹¦¡¸¾ªÆðÈ´»ØÍ·¡¹£¬Ë²¼äÔÚ$nÉíÇ°ÉíºóÒÆ¶¯£¬$nÒ»Õó»èÑ££¬Å»ÍÂÆðÀ´",
"force" :540,
"damage" :360,
"damage_type": "ðöÉË",
"lvl" : 16,
"skill_name" : "¾ªÆðÈ´»ØÍ·"
]),
// ZHAOSHI :17

([
"action" :"$NÄæ×ªÌåÄÚÕæÆø£¬ÌìµØÖèÀä£¬¡°È¥ËÀ°É£¡£¡£¡¡±£¬$NÒ»Ê½¡¸¼ÅÄ¯É³ÖÞÀä¡¹£¬È«²¿ÕæÆø»¯×÷Ò»¹ÉÇ¿´óµÄÆøÁ÷£¬Ö±ÆË$n",
"force" :570,
"damage" :380,
"damage_type": "ðöÉË",
"lvl" : 17,
"skill_name" : "¼ÅÄ¯É³ÖÞÀä"
]),
 });
// ZHAOSHI :18
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ÇïÒâÕÆ·¨"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÇïÒâÕÆ·¨"+"¡£\n");
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
    level = (int)me->query_skill("qing-unarmed",1);
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
