// duanjia-sword.c ¶Î¼Ò½£

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"ÀÍ¹¬Ñ¨","ëþÖÐÑ¨","Çú³ØÑ¨","¹ØÔªÑ¨","Çú¹ÇÑ¨","ÖÐ¼«Ñ¨","³Ð½¬Ñ¨","ÌìÍ»Ñ¨","°Ù»áÑ¨",
"ÓÄÃÅÑ¨","ÕÂÃÅÑ¨","´óºáÑ¨","×Ï¹¬Ñ¨","ÀäÔ¨Ñ¨","Ìì¾®Ñ¨","¼«ÈªÑ¨","ÇåÁéÑ¨","ÖÁÑôÑ¨",}); 

mapping *action = ({
([      "action" : "$N×óÊÖÄóÁË¸ö½£¾÷£¬ÓÒÊÖ$wÆ½Æ½µÝ³ö£¬Ò»Ê½"+(order[random(13)])+"¡¸ÆäÀû¶Ï½ð¡¹"NOR"Ö±´Ì$nµÄÇ°ÐØ",
        "force" : 150,
        "dodge" : 15,
        "damage" : 160,
        "lvl" : 5,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N×ÝÉíÏòÇ°£¬$w´ÓÒ»¸öÏë²»µ½µÄ½Ç¶ÈÍ»È»µ¯³ö£¬Ò»Ê½"+(order[random(13)])+"¡¸±Ì¼¦±¨Ïþ¡¹"NOR"Ö±´Ì$nµÄ×óÀß",
        "force" : 180,
        "dodge" : 15,
        "damage" : 185,
        "lvl" : 25,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»ÕÐ"+(order[random(13)])+"¡¸½ðÂíÌÚ¿Õ¡¹"NOR"£¬ÉíÐÎÔ¾ÔÚ°ë¿Õ£¬$wºáÏ÷¶ø³ö£ £¬Ö±Ïò$nµÄÍ·²¿",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N½£ÉíÐ±»Ó£¬½£¼âÖ¸Ïò$nµÄ¸¹²¿£¬Ò»ÕÐ"+(order[random(13)])+"¡¸±ÌÔ¨ÌÚòÔ¡¹"NOR"£¬×ÔÏÂ¶øÉÏ£¬ÆÊÏò$n",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 45,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NË«½ÅÀëµØ£¬Ð±·É¶ø³ö£¬$wÉäÏò$nµÄ$l,ºÃÒ»ÕÐ"+(order[random(13)])+"¡¸Ð¦Ö¸ÌìÄÏ¡¹"NOR"",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 55,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N³¤Ð¥Ò»Éù£¬ºá½£Çá»ÓÒþÒþÍ¸³öÍõµÀÖ®Òâ£¬ÕýÊÇ¶Î¼Ò²»´«Ö®ÃØ"+(order[random(13)])+"¡¸ÖðÂ¹ÖÐÔ­¡¹"NOR"£¬½£·çÕÖ×¡$nµÄÈ«Éí",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 65,
        "damage_type" : "´ÌÉË"

]),
([  "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬Ò»ÕÐ"+(order[random(13)])+"¡¸ÔÆºáÇØÁë¡¹"NOR"£¬ÊÖÖÐ$w×Ô×óÏòÓÒÏò$nµÄ$l
»º»º»®È¥",
    "force" : 150,
    "dodge" : 130,
    "damage" : 125,
    "lvl" : 0,
    "skill_name" : "ÔÆºáÇØÁë",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÏòÉÏÔ¾Æð£¬×óÊÖ½£¾÷£¬ÓÒÊÖÒ»¶¶£¬$w½£¹âçÏÃîÈçÆÙ£¬Ò»Ê½"+(order[random(13)])+"¡¸·ÉÁ÷
Ö±ÏÂ¡¹"NOR"Ö±´Ì$nµÄ$l",
    "force" : 200,
    "dodge" : 115,
    "damage" : 140,
    "lvl" : 9,
    "skill_name" : "·ÉÁ÷Ö±ÏÂ",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÒ»ÕÐ"+(order[random(13)])+"¡¸Ñ©Ó¿À¼¹Ø¡¹"NOR"£¬$wÉÁÆðÊýµÀº®¹â£¬×ÔÏÂ¶øÉÏ·´Ìô$nµÄ$l",
    "force" : 220,
    "dodge" : 115,
    "damage" : 165,
    "lvl" : 19,
    "skill_name" : "Ñ©Ó¿À¼¹Ø",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÒ»ÕÐ"+(order[random(13)])+"¡¸Ææ±øÍ»Æð¡¹"NOR"£¬ÊÖÖÐ$w¿´ËÆºáÉ¨ÊµÔòÐ±Åü£¬´ÌÏò$nµÄ$l",
    "force" : 250,
    "dodge" : 110,
    "damage" : 85,
    "lvl" : 29,
    "skill_name" : "Ææ±øÍ»Æð",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÊ¹³ö"+(order[random(13)])+"¡¸Ò¹²æÌ½º£¡¹"NOR"£¬$wÍì³öÈý¸ö½£»¨£¬ÃàÃà²»¶Ï»®Ïò$nµÄ$l",
    "force" : 280,
    "dodge" : 115,
    "damage" : 100,
    "lvl" : 39,
    "skill_name" : "Ò¹²æÌ½º£",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÒ»ÕÐ"+(order[random(13)])+"¡¸Ì©É½Ñ¹¶¥¡¹"NOR"£¬×óÊÖÒ»Äó½£¾÷£¬ÓÒÊÖ$w×ÔÉÏ¶øÏÂÀ×öªÍò¾û
°ãÖ±Ïò$nµÄ$lÅüÀÖÏÂÈ¥",
    "force" : 300,
    "dodge" : 115,
    "damage" : 120,
    "lvl" : 89,
    "skill_name" : "Ì©É½Ñ¹¶¥",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÒ»ÕÐ"+(order[random(13)])+"¡¸Óê´òÀæ»¨¡¹"NOR"£¬ÉíÔÚ°ë¿Õ£¬$w»Ø³é£¬·´ÊÖ¹´Ïò$nµÄ$l",
    "force" : 350,
    "dodge" : 110,
    "damage" : 140,
    "lvl" : 99,
    "skill_name" : "Óê´òÀæ»¨",
    "damage_type" : "´ÌÉË"
]),
([  "action" : "$NÉíÓ°Ò»»Î, ÈÆµ½$n±³ºó£¬Ò»ÕÐ"+(order[random(13)])+"¡¸ÖðÂ¹ÖÐÔ­¡¹"NOR"£¬½£¼âÏò$nµÄ$l¼²Ìô",
    "force" : 400,
    "dodge" : 115,
    "damage" : 250,
    "lvl" : 100,
    "skill_name" : "ÖðÂ¹ÖÐÔ­",
    "damage_type" : "´ÌÉË"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
    if ((int)me->query_skill("kurong-changong", 1) < 20)
       return notify_fail("ÄãµÄ¿ÝÈÙìø¹¦»ðºòÌ«Ç³¡£\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("duanjia-sword",1);
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
       return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¶Î¼Ò½£¡£\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"duanjia-sword/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N ÉîÎüÒ»¿ÚÆø£¡Ê©Õ¹¿ªÒ»ÑôÖ¸¾÷£¬ÒÔ´¿ÑôÖ¸Á¦±é²¼È«Éí! Á³É«ºìÈó¶àÁË¡£\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"±»$NµÄ´¿ÑôÖ¸Á¦·´µã! ½á¹ûµãÖÐÁË "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$nµÄÁ¦µÀ±»Ì«¼«È­½èÁ¦´òÁ¦·´»÷»ØÀ´£¡\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
