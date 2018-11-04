// zhuihun-biao.c ×·»ê¶áÃüïÚ
#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});


string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$NÊÖÖĞ$wÒ»ÉÁ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÎŞ³£ÇÃÃÅ¡¹"NOR"£¬ÊÖÍóÒ»·­£¬Ïò$nµÄ$l´òÈ¥",
	"force" : 120,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 120,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸Ğ¡¹"NOR"íÄÖ»¨µÆ¡¹"NOR"£¬ÍùµØÉÏÒ»¹ö£¬$wÇÄÎŞÉùÏ¢´òÏò$nµÄ¾±²¿",
	"force" : 130,
        "dodge" : 10,
        "parry" : 10,
	"damage" : 125,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NĞ±Éí½ø²½£¬Ò»ÕĞ"+(order[random(13)])+"¡¸Îå¹íÌ§½Î¡¹"NOR"£¬ÊÖÖĞÎåÃ¶$w,±ÊÖ±·ÉÏò$n",
	"force" : 140,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 130,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÄÎºÎ²»¹éÂ·¡¹"NOR"£¬$wÈöÊÖ·É³ö£¬¾¹ÒÔ²»¿ÉË¼ÒéµÄ½Ç¶È£¬´òÏò$n±³Ãæ",
	"force" : 160,
        "dodge" : 15,
        "parry" : 5,
	"damage" : 135,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÒõÓêÃàÃàÓû¶Ï»ê¡¹"NOR"£¬Ò»°Ñ$wÅüÍ·¸ÇÁ³´òÏò$nµÄĞØ¿Ú¡£",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 140,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÉí×ÓÒ»õÔõÄ£¬ºÃÏóÒªµøµ¹£¬È´¼û¾«Ã¢ÉÁ¶¯£¬ÕıÊÇÒ»ÕĞ"+(order[random(13)])+"¡¸¶Ï³¦ÉËĞÄÎŞÈ¥´¦¡¹"NOR"£¬$w·É¿ìÕÖÏò$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 150,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÑÖÂŞ¹ÂµÆ¡¹"NOR"£¬$wÉÁË¸²»¶¨£¬Ê±¿ìÊ±Âı£¬·À²»Ê¤·À´ò$nµÄ$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 160,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÌÚ¿ÕÔ¾Æğ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸Á¶ÓüÁ÷»ğ¡¹"NOR"£¬ÊıÃ¶$wÍÑÊÖ¶ø³ö£¬Ò»Ã¶½ÓÒ»Ã¶£¬¾¹È»³ÉÁËÒ»¸ù»ğÏßÏò$nµÄÈ«Éí´òÈ¥",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 180,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("ÄãµÄ±ÌÔÆĞÄ·¨»ğºò²»¹»¡£\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("ÄãµÄ±ÌÒ¶Ëæ·çÎè»ğºòÌ«Ç³¡£\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·×·»ê¶áÃüïÚ¡£\n");
	me->receive_damage("qi", 30);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$NÍ»È»ÊÕÕÆ£¬È»ºóÑ¸ËÙ·¢ÕÆ! ÕÆÖĞ¾¡È»ÓĞ¶¾É°£¬ÕâÕÆ·ç¾¡È»ÊÇÎåÑÕÁùÉ«µÄ£¡$nÓ²ÆğÍ·Æ¤£¬ÒÔÕÆÓ²½Ó£¡£¡½á¹ûÉíÖĞ¾Ş¶¾£¡!\n";
}	
	
	
	weapon;weapon=me->query_temp("weapon");
              
        if(weapon && 
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmzhuihun_poison", random(me->query_skill("zhuihun-biao")) + 10 +
	  victim->query_condition("tmzhuihun_poison"));
	}
	if (random(5)==1 && me->query_skill("zhuihun-biao",1)>100 )
	{
	victim->add("qi",-me->query_skill("zhuihun-biao",1)/2);
	me->add("qi",me->query_skill("zhuihun-biao",1)/2);
	return HIR"$nÖ»¾õÉË¿ÚÉÏÏÊÑªËæ×Å°µÆ÷Á÷³ö!ÅçÁËÒ»µØ!!\n"NOR;
	}
	
}
string perform_action_file(string action)
{
		return __DIR__"zhuihun-biao/" + action;
}