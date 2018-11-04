//wuying-jian ÉÙÁÖÎŞÓ°½£
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$NÎÕ½ôÊÖÖĞ$wÒ»ÕĞ"+(order[random(13)])+"¡¸À´È¥×ÔÈç¡¹"NOR"µãÏò$nµÄ$l",
        "force" : 280,
        "dodge" : 40,
        "damage" : 280,
        "lvl"    : 0,
        "skill_name" : "À´È¥×ÔÈç", 
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÈÕÔÂÎŞ¹â¡¹"NOR"£¬ÎŞÊı$wÉÏÏÂ´Ì³ö£¬Ö±Ïò$n±ÆÈ¥",
        "force" : 280,
        "dodge" : 10,
        "damage" : 280,
        "lvl"    : 20,
        "skill_name" : "ÈÕÔÂÎŞ¹â",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬ÊÖÖĞ$wÊ¹³ö"+(order[random(13)])+"¡¸½£Æø·âºí¡¹"NOR"Ö±´Ì$nµÄºí²¿",
        "force" : 300,
        "dodge" : 80,
        "damage" : 300,
        "lvl"    : 40,
        "skill_name" : "½£Æø·âºí",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NĞé»ĞÒ»²½£¬Ê¹³ö"+(order[random(13)])+"¡¸ĞÄ¾³ÈçË®¡¹"NOR"ÊÖÖĞ$wÖ±´Ì$nµÄÒªº¦",
        "force" : 290,
        "dodge" : 60,
        "damage" : 280,
        "lvl"    : 60,
        "skill_name" : "ĞÄ¾³ÈçË®",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "Ö»¼û$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö"+(order[random(13)])+"¡¸·ğ¹âÆÕÕÕ¡¹"NOR"Íòµã½ğ¹âÖ±Éä$n",
        "force" : 390,
        "dodge" : 70,
        "damage" : 280,
        "lvl"    : 80,
        "skill_name" : "·ğ¹âÆÕÕÕ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö"+(order[random(13)])+"¡¸·çĞĞÒ¶Âä¡¹"NOR"ÎŞÊı½£¹âÖ±Éä$n",
        "force" : 390,
        "dodge" : 60,
        "damage" : 290,
        "lvl"    : 100,
        "skill_name" : "·çĞĞÒ¶Âä", 
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊ¹³ö"+(order[random(13)])+"¡¸Éù¶«»÷Î÷¡¹"NOR"£¬ÊÖÖĞ$wÈç¹ÎÆğ¿ñ·çÒ»°ãÉÁË¸²»¶¨£¬´ÌÏò$n",
        "force" : 300,
        "dodge" : 80,
        "damage" : 340,
        "lvl"    : 220,
        "skill_name" : "Éù¶«»÷Î÷",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NËæÊÖÊ¹³ö½£·¨Ö®°ÂÒå"+(order[random(13)])+"¡¸ÎŞÓ°ÎŞ×Ù¡¹"NOR"£¬ÊÖÖĞ$wÈç¹í÷ÈÒ»°ãÆÌÌì¸ÇµØµÄ´ÌÏò$n",
        "force" : 500,
        "dodge" : 90,
        "damage" : 450,
        "lvl"    : 150,
        "skill_name" : "¡¸ÎŞÓ°ÎŞ×Ù¡¹",
        "damage_type" : "´ÌÉË"
]),
([      "action" : HIY"$NÊ¹³öÎŞÓ°½£·¨Ö®×îÖÕ¾ø¼¼[1;36m¡¸òÔÁú³öË®¡¹[0m,[1;33mÊÖÖĞ$wÓÌÈçòÔÁúÒ»°ã´ÌÏò$n[0m"NOR,
        "force" : 500,
        "dodge" : 100,
        "damage" : 800,
        "lvl"    : 220,
        "skill_name" : "HIY¡¸½£ÆøºÏÒ»¡¹"NOR,
        "damage_type" : "´ÌÉË"
]),



});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
                return notify_fail("ÄãµÄ¡¸»ìÔªÒ»Æø¡¹»ğºò²»¹»£¬ÎŞ·¨Ñ§¡¸ÎŞÓ°½£·¨¡¹¡£\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("ÄãµÄ»ìÔªÒ»Æø¹¦»ğºòÌ«Ç³¡£\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("ÄãµÄÒ×½î¾­ÄÚ¹¦»ğºòÌ«Ç³¡£\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("ÄãµÄÈÕÔÂ±Ş·¨»ğºòÌ«Ç³¡£\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("ÄãµÄ´ïÄ¦½£»ğºòÌ«Ç³¡£\n");

         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("ÄãµÄÉÙÁÖÉí·¨»ğºò²»×ã£¬ÄÑÒÔÁìÎò¡¸ÎŞÓ°½£·¨¡¹¡£\n");              
        if ((int)me->query("max_neili") < 300)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·¡¸ÎŞÓ°½£·¨¡¹¡£\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("wuying-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("ÄãµÄ»ìÔªÒ»Æø¹¦»ğºòÌ«Ç³¡£\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("ÄãµÄÒ×½î¾­ÄÚ¹¦»ğºòÌ«Ç³¡£\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("ÄãµÄÈÕÔÂ±Ş·¨»ğºòÌ«Ç³¡£\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("ÄãµÄ´ïÄ¦½£»ğºòÌ«Ç³¡£\n");
         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("ÄãµÄÉÙÁÖÉí·¨»ğºò²»×ã£¬ÄÑÒÔÁìÎò¡¸ÎŞÓ°½£·¨¡¹¡£\n");              
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¡¸ÎŞÓ°½£·¨¡¹¡£\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¡¸ÎŞÓ°½£·¨¡¹¡£\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuying-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"Ö»¼û$n$lÃÆºßÒ»Éù£¬ÍÂ³öÒ»¿ÚÏÊÑª£¬ÒÑ±»Ò×½î¾­µÄ»¤ÌåÕæÆø¸ø»÷ÉË!\n"NOR;
}
        if( damage_bonus < 50 ) return 0;
        if( random(5)==0) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "ÄãÌıµ½¡¸ßê¡¹Ò»ÉùÇáÏìÒ»µÀ°ÔÆøÆËÌì¶øÀ´£¬ºöÈ»¼ä$nÑªÃ°ÈıÕÉ£¬±»$N½£ÆøËùÉË£¡\n";
        }
        else if( random(damage_bonus/2) > victim->query_str() ) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "ÄãÌıµ½¡¸ßê¡¹Ò»ÉùÇáÏìÒ»µÀ°ÔÆøÆËÌì¶øÀ´£¬ºöÈ»¼ä$nÑªÃ°ÈıÕÉ£¬±»$N½£ÆøËùÉË£¡\n";
        }
}


