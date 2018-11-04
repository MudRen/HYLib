// ·ÉÌìÓù½£Á÷

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N×óÊÖÄóÁË¸ö½£¾÷£¬ÓÒÊÖ$wÆ½Æ½µİ³ö£¬Ò»Ê½¿´ËÆÆÕÆÕÍ¨Í¨µÄ"+(order[random(13)])+"¡¸ÌÆÖñ¡¹"NOR"Ö±´Ì$nµÄÇ°ĞØ",
        "force" : 150,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 5,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N×İÉíÏòÇ°£¬$w´ÓÒ»¸öÏë²»µ½µÄ½Ç¶ÈÍ»È»µ¯³ö£¬Ò»Ê½¿´ËÆÆ½µ­ÎŞÆæµÄ"+(order[random(13)])+"¡¸ôÂôÄÕ¶¡¹"NOR"Ö±´Ì$nµÄ×óÀß",
        "force" : 180,
        "dodge" : 15,
        "damage" : 85,
        "lvl" : 25,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N²à¶Ô$nÒ»ÕĞ"+(order[random(13)])+"¡¸ÄæôÂôÄ¡¹"NOR"£¬$wºáÏ÷¶ø³ö£ £¬Ö±Ïò$nµÄÍ·²¿£¬ÆÕÍ¨µÄ½£ÕĞÖ®ÖĞÍ¸×ÅÒ»¹É°ÔÆø",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N½£ÉíĞ±»Ó£¬½£¼âÖ¸Ïò$nµÄ¸¹²¿£¬Ò»ÕĞ"+(order[random(13)])+"¡¸×ó´Ì¡¹"NOR"£¬×ÔÏÂ¶øÉÏ£¬´ÌÏò$n£¬ÒşÔ¼¾¹È»ÊÇÉÏ¹ÅÃÜ½£·ÉÌìÓù½£Á÷µÄ½£Òâ",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 95,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NË«ÊÖ³Ö½££¬Ğ±·É¶ø³ö£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÓÒ´Ì¡¹"NOR"£¬$w´ÌÏò$nµÄ¸¹²¿",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 125,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N³¤Ğ¥Ò»Éù£¬ºá½£Çá»ÓÒşÒşÍ¸³ö£¬Ò»ÕĞÆÕÍ¨µÄÈÕÊ½"+(order[random(13)])+"¡¸×óÇĞÉÏ¡¹"NOR"£¬µ«½£·çÕÖ×¡$nµÄÈ«Éí",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 165,
        "damage_type" : "´ÌÉË"

]),
([  "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÓÒÇĞÉÏ¡¹"NOR"£¬ÊÖÖĞ$w×Ô×óÏòÓÒÏò$nµÄ$l
»º»º»®È¥",
    "force" : 150,
    "dodge" : 130,
    "damage" : 25,
    "lvl" : 0,
    "skill_name" : "ÓÒÇĞÉÏ",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÏòÉÏÔ¾Æğ£¬×óÊÖ½£¾÷£¬ÓÒÊÖÒ»¶¶£¬$w½£¹âçÏÃîÈçÆÙ£¬Ò»Ê½"+(order[random(13)])+"¡¸Äæ·ç¡¹"NOR"Ö±´Ì$nµÄ$l",
    "force" : 300,
    "dodge" : 115,
    "damage" : 200,
    "lvl" : 90,
    "skill_name" : "Äæ·ç",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸´ÌÍ»½£¡¹"NOR"£¬$wÉÁÆğÊıµÀº®¹â£¬×ÔÏÂ¶øÉÏ·´Ìô$nµÄ$l",
    "force" : 500,
    "dodge" : 115,
    "damage" : 500,
    "lvl" : 150,
    "skill_name" : "´ÌÍ»½£",
    "damage_type" : "´ÌÉË"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
//    if ((int)me->query_skill("feitian-xinfa", 1) < 20)
//       return notify_fail("ÄãµÄ·ÉÌìÓù½£Á÷ĞÄ·¨²»Êì¡£\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("feitian-sword",1);
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
    if ((int)me->query("qi") < 50)
       return notify_fail("ÄãµÄÌåÁ¦²»¹»Á··ÉÌìÓù½£Á÷¡£\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"feitian-sword/" + action;
}

