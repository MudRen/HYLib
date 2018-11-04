// kunlun-zhang.c À¥ÂØÕÆ

#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$NÕÆ·ç¼¤µ´£¬Ë«ÕÆ´íÂä£¬À´ÊÆÉñÃîÎŞ·½£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÈÕÈë¿ÕÉ½¡¹"NOR"£¬ÅüÏò$nµÄ$l",
        "force" : 200,
                  "dodge" : 5,
                  "parry" : 5,
    "damage" : 100,
        "lvl" : 0,
        "skill_name" : "ÈÕÈë¿ÕÉ½",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NË«ÕÆÖèÆğ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÌìÇåÔÆµ­¡¹"NOR"£¬Ò»ÕÆ»÷Ïò$nÃæÃÅ£¬ÁíÒ»ÕÆÈ´°´Ïò$n¡¸¹",
        "force" : 230,
                  "dodge" : 5,
                  "parry" : 10,
    "damage" : 120,
        "lvl" : 20,
        "skill_name" : "ÌìÇåÔÆµ­",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NË«ÕÆ»¥´í£¬±ä»ÃÄª²â£¬Ò»ÕĞ"+(order[random(13)])+"¡¸Çï·ç²»¾¡¡¹"NOR"£¬Ç°ºó×óÓÒ£¬Ë²Ï¢Ö®¼äÏò$n¹¥³öÁËËÄËÄÒ»Ê®ÁùÕĞ",
        "force" : 300,
                "dodge" : 15,
                  "parry" : 20,
    "damage" : 150,
        "lvl" : 38,
        "skill_name" : "Çï·ç²»¾¡",
        "damage_type" : "ğöÉË",
]),
([      "action" : "$NÒ»ÉùÇåĞ¥£¬ºôµÄÒ»ÕÆ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸É½»ØÂ·×ª¡¹"NOR"£¬×ÔÇÉ×ª×¾£¬È´ÊÇÈ¥ÊÆÆæ¿ì£¬Ïò$nµÄ$lÃÍ»÷¹ıÈ¥£¬",
        "force" : 280,
                  "dodge" : 20,
                  "parry" : 25,
    "damage" : 180,
        "lvl" : 55,
        "skill_name" : "É½»ØÂ·×ª",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NË«ÕÆ½»´í£¬ÈôÓĞÈôÎŞ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÌìÒÂÎŞ·ì¡¹"NOR"£¬ÅÄÏò$nµÄ$l",
        "force" : 350,
                  "dodge" : 25,
                  "parry" : 25,
    "damage" : 200,
        "lvl" : 72,
        "skill_name" : "ÌìÒÂÎŞ·ì",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÇàÉ½¶ÏºÓ¡¹"NOR"£¬ÓÒÊÖÒ»È­»÷³ö£¬×óÕÆ½ô¸ú×ÅÔÚÓÒÈ­ÉÏÒ»´î£¬±ä³ÉË«ÕÆÏÂÅü£¬»÷Ïò$nµÄ$l",
       "force" : 400,
                  "dodge" : 25,
                  "parry" : 30,
    "damage" : 230,
        "lvl" : 87,
        "skill_name" : "ÇàÉ½¶ÏºÓ",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NË«ÊÖÆë»®£¬¸ú×ÅË«ÕÆÆëÍÆ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸±±·ç¾íµØ¡¹"NOR"£¬Ò»¹ÉÅÅÉ½µ¹º£µÄÕÆÁ¦£¬Ö±ÆË$nÃæÃÅ",
        "force" : 450,
                  "dodge" : 30,
                  "parry" : 35,
    "damage" : 260,
        "lvl" : 101,
        "skill_name" : "±±·ç¾íµØ",
        "damage_type" : "ÄÚÉË"
]),
([      "action" : "$NÍ»È»µÎÁïÁïµÄ×ªÉí£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÌìÉ½Ñ©Æ®¡¹"NOR"£¬ÕÆÓ°·ÉÎè£¬ö®Ê±Ö®¼ä½«$nËÄÃæ°Ë·½¶¼¹ü×¡ÁË",
        "force" : 520,
                  "dodge" : 45,
                  "parry" : 40,
    "damage" : 300,
        "lvl" : 120,
        "skill_name" : "ÌìÉ½Ñ©Æ®",
        "damage_type" : "ÓÙÉË"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
      mapping fam  = me->query("family");
    if (fam["family_name"] != "À¥ÂØÅÉ" || fam["generation"] != 2)
         return notify_fail("À¥ÂØÕÆÖ»ÄÜ´ÓºÎ×ãµÀ´¦Ñ§µ½¡£\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("Á·À¥ÂØÕÆ±ØĞë¿ÕÊÖ¡£\n");
        if ((int)me->query_skill("xuantian-wuji", 1) < 120)
                return notify_fail("ÄãµÄĞşÌìÎŞ¼«¹¦»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
    if(me->query("gender")!="Å®ĞÔ"){
        if ((int)me->query_skill("zhentian-quan", 1) < 120)
                return notify_fail("ÄãµÄÏà¹Ø¹¦·ò»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
               } else {
     if ((int)me->query_skill("chuanyun-tui", 1) < 120)
                return notify_fail("ÄãµÄÏà¹Ø¹¦·ò»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
               }
        if ((int)me->query("max_neili") < 800)
                return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
        return 1;
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
        level   = (int) me->query_skill("kunlun-zhang",1);
        
          for(i = sizeof(action); i > 0; i--)
                                 if(level > action[i-1]["lvl"]) 
               return action[NewRandom(i, 20, level/5)];
                              
}

int practice_skill(object me)
{

        int lvl = me->query_skill("kunlun-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;
        if ((int)me->query_skill("xuantian-wuji", 1) < 120)
                return notify_fail("ÄãµÄĞşÌìÎŞ¼«¹¦»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
    if(me->query("gender")!="Å®ĞÔ"){
        if ((int)me->query_skill("zhentian-quan", 1) < 120)
                return notify_fail("ÄãµÄÏà¹Ø¹¦·ò»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
               } else {
     if ((int)me->query_skill("chuanyun-tui", 1) < 120)
                return notify_fail("ÄãµÄÏà¹Ø¹¦·ò»ğºò²»¹»£¬ÎŞ·¨Á·À¥ÂØÕÆ¡£\n");
               }

        if ((int)me->query("jing") < 50)
                return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·À¥ÂØÕÆ¡£\n");
        me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kunlun-zhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N½ÅÌ¤°ËØÔ²½,ÊÖÄóÌ«ÒÒ¾ö,$NÒ»Éù³¤Ğ¥£¬$nË«ÑÛÒ»ºÚ£¬ÍÂ³öÒ»¿ÚÏÊÑª!\n"NOR;
}
}