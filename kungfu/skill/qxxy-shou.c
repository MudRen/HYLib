// ±±¶·ĞÇÓÉÌìÊà¡¢ÌìĞı¡¢Ììçá¡¢ÌìÈ¨¡¢Óñºâ¡¢¿ªÑô¡¢Ò¡¹"NOR"âÕâÆß¿ÅĞÇ×é³É£¬ÔË×ªÓÚ±±
// ¼«ĞÇÖÜÎ§¡£ÆäÖĞ£¬ÌìÊàÖÁÌìÈ¨ËÄĞÇÎª¿ı£¬ÓñºâÖÁÒ¡¹"NOR"âÎªÁñ¡£¡¶Ê·¼Ç¡¤Ìì¹ÙÊé¡·¼Ç
// ÔØ¡°±±¶·ÆßĞÇ£¬ËùÎ½è¯çáÓñºâ£¬ÒÔÆëÆßÕş¡£¹¹Ğ¯Áú½Ç£¬ºâ¶ÎÄÏ¶·£¬¿ıÕí²ÎÊ×¡±¡£

#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([      "action": "$NÒ»Ö¸µã³ö£¬ÕâÒ»ÕĞ"+(order[random(13)])+"¡¸³¯°İÌìî¸¡¹"NOR"ÖĞ¹¬Ö±½ø£¬Ö¸Æø½«$nÑ¹µÃ´§²»¹ıÆøÀ´",
        "force" : 90,
        "dodge" : 5,
        "damage": 115,
        "lvl"   : 0,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "³¯°İÌìî¸"
]),
([      "action": "$NÉíĞÎ²»¶¯£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÆßĞÇ»ã¾Û¡¹"NOR"¹¥³ö¡£$nÉÔÒ»ÓÌÔ¥£¬$NµÄÖĞÖ¸ÒÑ´ÌÏò×Ô¼º",
        "force" : 140,
        "attack": 5,
        "parry" : 5,
        "dodge" : 5,
        "damage": 120,
        "lvl"   : 40,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "ÆßĞÇ»ã¾Û"
]),
([      "action": "Ö»¼û$NÒ»×ªÉí£¬ÕıÊÇÒ»Ê½"+(order[random(13)])+"¡¸ºáÒÆ±±¶·¡¹"NOR"£¬Ò»Ö¸ÓÉĞ²ÏÂ´©³ö£¬¼²´Ì$nµÄ$l",
        "force" : 155,
        "attack": 10,
        "parry" : 7,
        "dodge" : 5,
        "damage": 130,
        "lvl"   : 40,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "ºáÒÆ±±¶·"
]),
([      "action": "Ö»¼û$NÒ»ÕĞ"+(order[random(13)])+"¡¸Æ«»¨ÆßĞÇ¡¹"NOR"£¬Ê®Ö¸Èç´©»¨ºûµûÒ»°ãÉÏÏÂ·­·É£¬È«È«ÁıÕÖ$n",   
        "force" : 170,
        "attack": 20,
        "parry" : 11,
        "dodge" : 9,
        "damage": 140,
        "lvl"   : 60,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "Æ«»¨ÆßĞÇ"
]),
([      "action": "Ö»¼û$NÃæ´øÎ¢Ğ¦£¬¸ºÊÖ¶øÁ¢£¬Ò»ÕĞ"+(order[random(13)])+"¡¸åçĞÇ·É×¹¡¹"NOR"£¬$n¶Ù¾õÒ»µÀÖ¸Á¦Ö±ÆË¶øÀ´",
        "force" : 190,
        "attack": 30,
        "parry" : 12,
        "dodge" : 10,
        "damage": 150,
        "lvl"   : 80,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "åçĞÇ·É×¹"
]),
([      "action": "ºöÌı$NÒ»ÉùÇáß³£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÂúÌìĞÇ³½¡¹"NOR"£¬×óÊÖ»®ÁË¸ö°ë»¡£¬Ê³Ö¸ÉÁµç°ãµãÏò$n",
        "force" : 250,
        "attack": 40,
        "parry" : 23,
        "dodge" : 25,
        "damage": 157,
        "lvl"   : 100,
        "damage_type" : "µãÑ¨",
        "skill_name"  : "ÂúÌìĞÇ³½"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ĞÇ¹â²ÓÀÃ¡¹"NOR"£¬Ë«È­ÉÁ¶¯, ¹¥Ïò$nµÄ$l",
        "force"  : 120,
        "dodge"  : 10,
        "damage" : 2,
        "lvl"    : 0,
        "skill_name" : "ĞÇ¹â²ÓÀÃ",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸Ò¡¹"NOR"âÒ×Î»¡¹"NOR"£¬Ò»È­ºáÉ¨£¬ÆøÊÆÈçºç£¬»÷Ïò$nµÄ$l",
        "force"  : 140,
        "dodge"  : 12,
        "damage" : 115,
        "lvl"    : 20,
        "skill_name" : "Ò¡¹"NOR"âÒ×Î»",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÉíÓ°ÏòÆ®¶¯£¬Á³¸¡Î¢Ğ¦£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ĞÇ¹ı³¤¿Õ¡¹"NOR"£¬ÓÒÈ­¿ìËÙÅÄÏò$nµÄ$l",
        "force"  : 150,
        "dodge"  : 16,
        "damage" : 115,
        "lvl"    : 40,
        "skill_name" : "ĞÇ¹ı³¤¿Õ",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÈºĞÇÉÁË¸¡¹"NOR"£¬Ë«È­Êı·ÖÊıºÏ£¬$nÖ»¾õµ½´¦ÊÇ$NµÄÈ­Ó°",
        "force"  : 160,
        "dodge"  : 18,
        "damage" : 122,
        "lvl"    : 60,
        "skill_name" : "ÈºĞÇÉÁË¸",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÊ©Õ¹¿ª"+(order[random(13)])+"¡¸Ç§±äÍò»¯¡¹"NOR"ÈÆ×Å$nÒ»×ª£¬·ÉÉíÓÎ×ß£¬È­³öÈç·ç£¬²»×¡µÄ»÷Ïò$n¡£",
        "force"  : 170,
        "dodge"  : 21,
        "damage" : 126,
        "lvl"    : 80,
        "skill_name" : "Ç§±äÍò»¯",
        "damage_type" : "ğöÉË"
]),
([      "action" : "Ö»¼û$NÍ»È»ÃÍ¿çÁ½²½£¬ÒÑµ½$nÃæÇ°£¬ÓÒÈ­¶¸³ö£¬Ñ¸Èç±ÀÀ×£¬"
                   "Ò»ÕĞ"+(order[random(13)])+"¡¸Á÷ĞÇÓê¡¹"NOR"»÷Ïò$nµÄÇ°ĞØ",
        "force"  : 220,
        "dodge"  : 22,
        "damage" : 130,
        "lvl"    : 100,
        "skill_name" : "µãÊ¯³É½ğ",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸±±¶·Éú²É¡¹"NOR"£¬È­Ó°½»´í£¬ÉÏÖĞÏÂÒ»Æë¹¥Ïò$n¡£",
        "force"  : 250,
        "dodge"  : 25,
        "damage" : 135,
        "lvl"    : 120,
        "skill_name" : "±±¶·Éú²É",
        "damage_type" : "ğöÉË"
]),
([      "action": "$NÓÒÊÖÎåÖ¸·Ö¿ª£¬Î¢Î¢Ò»·÷£¬Ò»Ê½"+(order[random(13)])+"¡¸ÌìÊàÖ¸¡¹"NOR"·÷Ïò$nµÄëşÖĞÒªÑ¨",
        "force" : 100,
        "dodge" : 15,
        "damage": 115,
        "lvl"   : 0,
        "damage_type" : "ğöÉË",
        "skill_name" : "ÌìÊàÖ¸"
]),
([      "action": "$N²àÉíÂÓÏò$n£¬Ò»Ê½"+(order[random(13)])+"¡¸ÌìĞıÖ¸¡¹"NOR"£¬×óÊÖÎåÖ¸²¦Ïò$nµÄĞØÇ°´óÑ¨",
        "force" : 130,
        "dodge" : 20,
        "damage": 130,
        "lvl"   : 30,
        "damage_type" : "ğöÉË",
        "skill_name" : "ÌìĞıÖ¸"
]),
([      "action": "$NÊ¹Ò»Ê½"+(order[random(13)])+"¡¸ÌìçáÖ¸¡¹"NOR"£¬×óÕÆĞé¹¥£¬²¢Ö¸Ğ±Ç°·­³ö£¬ÅÄÏò$nµÄ¼ç¾®Ñ¨",
        "force" : 170,
        "dodge" : 25,
        "damage": 140,
        "lvl"   : 60,
        "damage_type" : "ÄÚÉË",
        "skill_name" : "ÌìçáÖ¸"
]),
([      "action": "$NÎ¢Î¢²àÉí£¬ÓÒÕÆ¹´ÉÏ£¬Ò»Ê½"+(order[random(13)])+"¡¸ÌìÈ¨Ö¸¡¹"NOR"£¬»º»º·÷Ïò$nµÄÌìÍ»Ñ¨",
        "force" : 190,
        "dodge" : 25,
        "damage": 145,
        "lvl"   : 80,
        "damage_type" : "ğöÉË",
        "skill_name" : "ÌìÈ¨Ö¸"
]),
([      "action": "$NÊ¹Ò»Ê½"+(order[random(13)])+"¡¸ÓñºâÖ¸¡¹"NOR"£¬ÉíÓ°²»¶¨µØÂÓÖÁ$nÉíºó£¬ÃÍµØÅÄÏò$nµÄ´ó×µÑ¨",
        "force" : 220,
        "dodge" : 30,
        "damage": 150,
        "lvl"   : 100,
        "damage_type" : "ğöÉË",
        "skill_name" : "ÓñºâÖ¸"
]),
([      "action": "$NÊ©³ö"+(order[random(13)])+"¡¸¿ªÑôÖ¸¡¹"NOR"£¬Ë«ÊÖÏòÍâÒ»²¦£¬±ÆÏò$nµÄ»ª¸Ç¡¢è¯çá¡¢×Ï¹¬¼¸´¦´óÑ¨",
        "force" : 250,
        "dodge" : 35,
        "damage": 155,
        "lvl"   : 120,
        "damage_type" : "ğöÉË",
        "skill_name" : "¿ªÑôÖ¸"
]),
([      "action": "$NÒ»Ê½"+(order[random(13)])+"¡¸Ò¡¹"NOR"âÖ¸¡¹"NOR"£¬¾Ó¸ßÁÙÏÂ£¬·÷³öÒ»µÀ¾¢Á¦ÕÖÏò$nµÄ°Ù»á´óÑ¨",
        "force" : 280,
        "dodge" : 40,
        "damage": 165,
        "lvl"   : 140,
        "damage_type" : "ÄÚÉË",
        "skill_name" : "Ò¡¹"NOR"âÖ¸"
]),
([      "action": "$NÊ©Õ¹³ö"+(order[random(13)])+"¡¸è¯çá¿ªÆÆ¡¹"NOR"£¬Ë«ÊÖ¼²·÷£¬Ò»»·»·µÄ¾¢Æø±ÆÏò$nµÄÉÏÖĞÏÂ¸÷´óÒªÑ¨",
        "force" : 320,
        "dodge" : 45,
        "damage": 170,
        "lvl"   : 160,
        "damage_type" : "ÄÚÉË",
        "skill_name" : "è¯çá¿ªÆÆ"
])
});

int valid_enable(string usage)
{
	return usage == "hand" ||  usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "canhe-zhi";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("Á·ÆßĞÇĞÇÒÆÊÖ±ØĞë¿ÕÊÖ¡£\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("ÄãµÄÉñÔª¹¦»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("ÄãµÄÄ½Èİµ¶·¨»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("ÄãµÄÄ½Èİ½£·¨»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("ÄãµÄÑàÁéÉí·¨»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("ÄãµÄ¶·×ªĞÇÒÆÕÆ»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("ÄãµÄ¶·×ªĞÇÒÆ»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("force") < 100)
                return notify_fail("ÄãµÄÄÚ¹¦»ğºò²»¹»£¬ÎŞ·¨Ñ§ÆßĞÇĞÇÒÆÊÖ¡£\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·ÆßĞÇĞÇÒÆÊÖ¡£\n");

        if ((int)me->query_skill("hand", 1) < 80)
                return notify_fail("ÄãµÄ»ù±¾ÊÖ·¨Ì«²î£¬ÎŞ·¨Ñ§Ï°ÆßĞÇĞÇÒÆÊÖ¡£\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("qxxy-shou", 1))
                return notify_fail("Äã»ù±¾ÊÖ·¨»ğºò²»¹»£¬ÎŞ·¨Áì»á¸ü¸ßÉîµÄÆßĞÇĞÇÒÆÊÖ¡£\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        string msg;
        level   = (int) me->query_skill("qxxy-shou",1);
        
        if (me->query_skill("qxxy-shou",1) > 200
             && me->query_skill("hand",1) > 80
             && random(6) ==0 ){
                switch(random(4)){
                        case 3: msg = HIR"$NË«ÕÆÊÕÔÚĞØÇ°£¬ÒÆĞÎ»»²½ÉÁµç°ã½«¡¸"HIW"ÆøĞı"HIR"¡¹»÷Ïò$nµÄÌ´ÖĞÑ¨"NOR; break;
                        case 2: msg = HIG"½ô½Ó×Å$N³é³ö×óÕÆ£¬ÉíĞÎÒ»°«£¬ÓÉÏÂ¶øÉÏÃÍÏ®Ïò$nµÄĞ¡¸¹"NOR; break;
                        case 1: msg = HIR"Ö»¼û$NÓÒÕÆËæºó¶øÖÁ£¬Áè¿ÕÒ»Ô¾£¬ÓÌÈçÇç¿ÕÅùö¨ÅÄÏò$nµÄÍ·²¿"NOR; break;
                        case 0: msg = HIY"$NÔÚ¿ÕÖĞÒ»¸ö»Ø×ª£¬Ğ¯¡¸"HIR"ÈÕÔÂÖ®¹â"HIY"¡¹, Ë«ÕÆ°´Ïò$nµÄµ¤Ìï"NOR; break;
                      
                }    
                return([      
                        "action": msg,        
                        "force" : 500+random(150),
                        "dodge" : 20,
                        "damage" : 500+random(150),
                        "damage_type" : me->query_temp("mr_riyue")?"ÄÚÉË":"ğöÉË",
                ]);
        }
            
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}



int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË£¬ÎŞ·¨Á·ÆßĞÇĞÇÒÆÊÖ¡£\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË£¬ÎŞ·¨Á·ÆßĞÇĞÇÒÆÊÖ¡£\n");
                
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("ÄãµÄÉñÔª¹¦»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("ÄãµÄÄ½Èİµ¶·¨»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("ÄãµÄÑàÁéÉí·¨»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("ÄãµÄ¶·×ªĞÇÒÆÕÆ»ğºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("ÄãµÄ¶·×ªĞÇÒÆ»ğºòÌ«Ç³¡£\n");
                
        me->receive_damage("qi", 80);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qxxy-shou/" + action;
}
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return HIG "Ö»Ìı$nÒ»Éù²Òº¿£¬ÍÂ³öÒ»¹ÉÏÊÑª£¡\n" NOR;	
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"ÄıÉñÔËÆøÏò$nÃÍ¹¥¿ì´ò£¬Ê¹³öµÄÕĞÊıºÃËÆ$nµÄ³ÉÃû¾ø¼¼£¬°Ñ$nµÄÕĞÊı»¯ÓÚÎŞĞĞ£¡\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"Ê¹³öĞÇÒÆ¶·×ª£¬$nÕâÕĞÄªÃûÆäÃîµÄÔÚÖĞÍ¾×ªÁË·½Ïò£¬Ö±±¼×Ô¼ºÏ®À´!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}