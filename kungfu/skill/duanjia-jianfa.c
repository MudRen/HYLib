//¶Î¼Ò½£·¨

inherit SKILL;

mapping *action = ({
([      "action" : "$N×óÊÖÄóÁË¸ö½£¾÷£¬ÓÒÊÖ$wÆ½Æ½µÝ³ö£¬Ò»Ê½¡¸ÆäÀû¶Ï½ð¡¹Ö±´Ì$nµÄÇ°ÐØ",
        "force" : 150,
        "dodge" : -5,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N×ÝÉíÏòÇ°£¬$w´ÓÒ»¸öÏë²»µ½µÄ½Ç¶ÈÍ»È»µ¯³ö£¬Ò»Ê½¡¸±Ì¼¦±¨Ïþ¡¹Ö±´Ì$nµÄ×óÀß",
        "force" : 180,
        "dodge" : -5,
        "damage" : 45,
        "lvl" : 20,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»ÕÐ¡¸½ðÂíÌÚ¿Õ¡¹£¬ÉíÐÎÔ¾ÔÚ°ë¿Õ£¬$wºáÏ÷¶ø³ö£ £¬Ö±Ïò$nµÄÍ·²¿",
        "force" : 220,
        "dodge" : 20,
        "damage" : 55,
        "lvl" : 45,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N½£ÉíÐ±»Ó£¬½£¼âÖ¸Ïò$nµÄ¸¹²¿£¬Ò»ÕÐ¡¸±ÌÔ¨ÌÚòÔ¡¹£¬×ÔÏÂ¶øÉÏ£¬ÆÊÏò$n",
        "force" : 270,
        "dodge" : -15,
        "damage" : 70,
        "lvl" : 60,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NË«½ÅÀëµØ£¬Ð±·É¶ø³ö£¬$wÉäÏò$nµÄ$l,ºÃÒ»ÕÐ¡¸Ð¦Ö¸ÌìÄÏ¡¹",
        "force" : 330,
        "dodge" : -15,
        "damage" : 90,
        "lvl" : 80,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N³¤Ð¥Ò»Éù£¬ºá½£Çá»ÓÒþÒþÍ¸³öÍõµÀÖ®Òâ£¬ÕýÊÇ¶Î¼Ò²»´«Ö®ÃØ¡¸ÖðÂ¹ÖÐÔ­¡¹£¬½£·çÕÖ×¡$nµÄÈ«Éí",
        "force" : 280,
        "dodge" : 15,
        "damage" : 100,
        "lvl" : 90,
        "damage_type" : "´ÌÉË"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
//int valid_combine(string combo) { return combo=="murong-daofa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("ÄãµÄÇ¬ÌìÒ»Ñô»ðºòÌ«Ç³¡£\n");
 //       if ((int)me->query_skill("parry", 1) < 10)
   //             return notify_fail("ÄãµÄ»ù±¾ÕÐ¼Ü»ðºòÌ«Ç³¡£\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("duanjia-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¶Î¼Ò½£·¨¡£\n");
        me->receive_damage("jingli", 20);
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"duanjia-jianfa/" + action;
}

