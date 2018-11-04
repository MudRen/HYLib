// pixie-jian.c ±ÙÐ°½£·¨
// Jay 4/5/96
// modified by Venus Oct.1997
inherit SKILL;

string *dodge_msg = ({
    "Í»È»Ö®¼ä£¬°×Ó°¼±»Ï£¬$nÏòºó»¬³öÕÉÓà£¬Á¢Ê±ÓÖ»Øµ½ÁËÔ­µØ£¬¶ã¹ýÁË$NÕâÒ»ÕÐ¡£\
n",
    "$nÊÖ±Û»Ø×ª£¬ÔÚ$NÊÖÖâÏÂÒ»ÍÆ£¬Ë³ÊÆÉÁµ½Ò»ÅÔ¡£\n",
    "$nÓÒÊÖÉì³ö£¬ÔÚ$NÊÖÍóÉÏÑ¸ËÙÎÞ±ÈµÄÒ»°´£¬Ë³ÊÆÌøµ½Ò»ÅÔ¡£\n",
    "$nÉíÐÎÆ®ºö£¬ÓÐÈç¹í÷È£¬×ªÁË¼¸×ª£¬ÒÆ²½µ½$NµÄÉíºó£¬¶ã¹ýÁË$NÕâÒ»ÕÐ¡£\n",
    "$NÖ»¾õÑÛÇ°Ò»»¨£¬ËÆºõ¼ûµ½$nÉíÐÎÒ»»Ï£¬µ«Ëæ¼´ÓÖ¼û$n»Øµ½Ô­µØ£¬È´ËÆ´ÓÎ´Àë¿ª¡
£\n",
    "$NÑÛ¾¦Ò»»¨£¬$nÒÑÃ»ÁË×ÙÓ°¡£Í»È»$n´ÓÉíºóÅÄÁËÒ»ÏÂ$NµÄÍ·£¬ÇáÇáÔ¾¿ª¡£\n",
    "$næÌÈ»Ò»Ð¦£¬¹îÒìÖ®¼«£¬$N¾¹²»ÖªÈçºÎÊÇºÃ£¬Í£×¡ÁË¹¥»÷¡£\n",
});

mapping *action = ({
([      "action":"Í»È»Ö®¼ä£¬°×Ó°¼±»Ï£¬$NÏòºó»¬³öÕÉÓà£¬Á¢Ê±ÓÖ»Øµ½ÁËÔ­µØ",
    "force" : 100,
    "dodge" : 40,
    "damage": 40,
    "lvl" : 0,
    "skill_name" : "°×Ó°¼±»Ï",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÓÒÊÖÉì³ö£¬ÔÚ$nÊÖÍóÉÏÑ¸ËÙÎÞ±ÈµÄÒ»°´£¬$nÏÕÐ©»÷ÖÐ×Ô¼ºÐ¡¸¹",    
    "force" : 120,
    "dodge" : 30,
    "damage": 50,
    "lvl" : 0,
    "skill_name" : "×Ô¼ºÐ¡¸¹",
    "damage_type":  "´ÌÉË"
]),
([      "action":"ÝëµØÀï$Nâ®Éí¶øÉÏ£¬´Úµ½$nµÄÉíºó£¬ÓÖÔ¾»ØÔ­µØ",
    "force" : 125,
    "dodge" : 60,
    "damage": 70,
    "lvl" : 25,
    "skill_name" : "â®Éí¶øÉÏ",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÍ»È»¼äÕÐ·¨Ò»±ä£¬$wºöÉìºöËõ£¬ÕÐÊ½¹îÆæ¾øÂ×¡£$n¾ªº§Ö®ÖÐ·½´ç´óÂÒ
",
    "force" : 130,
    "dodge" : 40,
    "damage": 50,
    "lvl" : 5,
    "skill_name" : "ÕÐ·¨Ò»±ä",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÉíÐÎÆ®ºö£¬ÓÐÈç¹í÷È£¬×ªÁË¼¸×ª£¬ÒÆ²½µ½$nµÄ×ó²à",
    "force" : 140,
    "dodge" : 40,
    "damage": 90,
    "lvl" : 10,
    "skill_name" : "ÓÐÈç¹í÷È",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÒ»ÉùÀäÐ¦£¬ÝëµØÀï¼²³åÉÏÇ°£¬Ò»Ë²Ö®¼ä£¬Óë$nÏà¾àÒÑ²»µ½Ò»³ß£¬$wËæ
¼´µÝ³ö",
    "force" : 160,
    "dodge" : -5,
    "damage": 100,
    "lvl" : 10,
    "skill_name" : "¼²³åÉÏÇ°",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NºÈµÀ£º¡°ºÃ£¡¡±£¬±ã¼´°Î³ö$w£¬·´ÊÖ´Ì³ö£¬¸ú×Å×ªÉíÀëÈ¥",
    "force" : 200,
    "dodge" : 30,
    "damage": 50,
    "lvl" : 0,
    "skill_name" : "·´ÊÖ´Ì³ö",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$nÖ»¾õÑÛÇ°Ò»»¨£¬ËÆºõ¼ûµ½$NÉíÐÎÒ»»Ï£¬µ«Ëæ¼´ÓÖ¼û$N»Øµ½Ô­µØ£¬È´ËÆ
´ÓÎ´Àë¿ª",
    "force" : 190,
    "dodge" : 80,
    "damage": 100,
    "lvl" : 20,
    "skill_name" : "ÑÛÇ°Ò»»¨",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÏòºó¼²ÍË£¬$n½ô×·Á½²½£¬Í»È»¼ä$NÉÁµ½$nÃæÇ°£¬ÊÖÖÐ$wÖ±Ö¸$nµÄ$l",
    "force" : 180,
    "dodge" : 10,
    "damage": 90,
    "lvl" : 5,
    "skill_name" : "Ïòºó¼²ÍË",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÝëµØ³åµ½$nÃæÇ°£¬ÊÖÖÐ$wÖ±´Ì$nÓÒÑÛ£¡$n»ÅÃ¦ÕÐ¼Ü£¬²»Ïë$NµÄ$wÍ»È»
×ªÏò",
    "force" : 250,
    "dodge" : 4,
    "damage": 100,
    "lvl" : 45,
    "skill_name" : "Ö±´ÌÓÒÑÛ",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$N·ÉÉíÔ¾Æð£¬$nÌ§ÑÛÒ»Íû£¬µ«¼ûµÃ$N´ÓÌìÖ±Âä¶øÏÂ£¬ÊÖÖÐ$w´ÌÏò$nµÄ$l
",
    "force" : 340,
    "dodge" : 20,
    "damage": 125,
    "lvl" : 64,
    "skill_name" : "·ÉÉíÔ¾Æð",
    "damage_type":  "´ÌÉË"
]),
([      "action":"$NÑüÖ¦ÃÍ°Ú£¬$nÑÛÇ°·Â·ðÍ»È»³öÏÖÁËÆß°Ë¸ö$N£¬Æß°ËÖ»$wÒ»Æð´ÌÏò$n",
    "force" : 400,
    "dodge" : 60,
    "damage": 130,
    "lvl" : 79,
    "skill_name" : "ÑüÖ¦ÃÍ°Ú",
    "damage_type":  "´ÌÉË"
]),
});


int valid_enable(string usage)
{
    return usage == "sword" || usage == "dodge" || usage == "parry";
}

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
    level   = (int) me->query_skill("pixie-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    return notify_fail("±ÙÐ°½£·¨Ö»ÄÜÍ¨¹ýÑÐÏ°¡¶¿û»¨±¦µä¡·À´Ñ§Ï°¡£\n");
}

