// shedao-qigong  ÉßµºÆæ¹¦
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([	"action" : "$NÊ¹Ò»ÕÐ"+(order[random(13)])+"¡¸ÏÉº×Êáôá¡¹"NOR"ÊÖÖÐ$wÒ»Ìá£¬²åÏò$nµÄ$l",
	"damage" : 150,
	"parry": 40,
	"force": 150,
	"damage_type" : "´ìÉË",
	"skill_name" : "ÏÉº×Êáôá"
]),
([	"action": "$NÊ¹³ö"+(order[random(13)])+"¡¸ÁéÉß³ö¶´¡¹"NOR"£¬ÉíÐÎÎ¢¹­£¬ÊÖÖÐ$wÙ¿µÄÏò$nµÄ$l´ÁÈ¥",
	"damage" : 150,
	"dodge": 80,
	"parry": 10,
	"force": 250,
	"damage_type": "´ÌÉË",
	"skill_name" : "ÁéÉß³ö¶´"
]),
([	"action": "$NÉí×ÓÎ¢Çú£¬×ó×ã·´Ìß£¬³ËÊÆ×ªÉí£¬Ê¹Ò»ÕÐ"+(order[random(13)])+"¡¸¹óåú»Øíø¡¹"NOR"£¬ÓÒÊÖ$wÒÑ´ÁÏò$n$l",
	"damage" : 160,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "´ÌÉË",
	"skill_name" : "¹óåú»Øíø"
]),
([	"action" : "$NÊ¹Ò»Ê½"+(order[random(13)])+"¡¸·ÉÑà»ØÏè¡¹"NOR"£¬±³¶Ô×Å$n£¬ÓÒ×ãÒ»¹´£¬Ë³ÊÆÔÚ$wÉÏÒ»µã£¬$w¶¸È»Ïò×Ô¼ºÑÊºí¼²Éä£¬½Ó×Å$NÉí×ÓÍùÏÂÒ»Ëõ£¬$wÂÓ¹ýÆäÑÊºí£¬¼±±¼$n¼±Éä¶øÀ´",
	"damage" : 170,
	"force" : 350,
        "dodge" : 50,
	"lvl" : 40,
        "damage_type" : "´ÌÉË",
	"skill_name" : "·ÉÑà»ØÏè"
]),
([	"action": "$NºöµÄÔÚµØÉÏÒ»¸ö½î¶·£¬Ê¹Ò»ÕÐ"+(order[random(13)])+"¡¸Ð¡Á¯ºá³Â¡¹"NOR"£¬´Ó$n¿èÏÂ×ê¹ý£¬ÊÖÖÐ$wÖ±»÷$n",
	"damage" : 180,
	"dodge": 70,
	"parry": 130,
	"force": 350,
	"damage_type": "´ÌÉË",
	"skill_name" : "Ð¡Á¯ºá³Â"
]),
([	"action": "$N´óºðÒ»Éù£¬Ê¹Ò»ÕÐ"+(order[random(13)])+"¡¸×Óñã¾Ù¶¦¡¹"NOR"£¬·´ÊÖÇÜÄÃ$n¼«ÈªÒªÑ¨£¬Óû½«$nË¤µ¹ÔÚµØ",
	"damage" : 200,
	"dodge": 25,
	"parry": 110,
	"damage" : 70,
	"force": 400,
	"damage_type": "ÄÚÉË",
	"skill_name" : "×Óñã¾Ù¶¦"
]),
([	"action": "$NË«ÍÈÒ»Ëõ£¬ËÆÓû¹ò°Ý£¬Ò»ÕÐ"+(order[random(13)])+"¡¸Â³´ï²¦Áø¡¹"NOR"×óÊÖ×¥Ïò$nÓÒ½Å×ãõ×£¬ÓÒÊÖ$wÖ±»÷$nÐ"+(order[random(13)])+"¡¸¹",
	"dodge": 180,
	"damage" : 180,
	"parry": 110,
	"force": 400,
	"damage_type": "ÄÚÉË",
	"skill_name" : "Â³´ï²¦Áø"
]),
([	"action": "$NÍ»È»Ò»¸öµ¹·­½î¶·£¬Ò»ÕÐ"+(order[random(13)])+"¡¸µÒÇà½µÁú¡¹"NOR"£¬Ë«ÍÈÒ»·Ö£¬¿çÔÚ¼çÍ·£¬Ë«ÕÆÖ±»÷$n",
	"dodge": 190,
	"damage" : 250,
	"parry": 130,
	"force": 400,
	"damage_type": "ÄÚÉË",
	"skill_name" : "µÒÇà½µÁú"
]),
});

int valid_enable(string usage) { return usage=="sword"|| usage=="staff"|| usage=="parry"; }

int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff"&&(string)weapon->query("skill_type") != "sword")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 30)
		return notify_fail("ÄãµÄÉñÁúÐÄ·¨»ðºò²»¹»£¬ÎÞ·¨Ñ§ÉßµºÆæ¹¦.\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("ÄãµÄ»ù±¾ÄÚ¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§ÉßµºÆæ¹¦¡£\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 30)
		return notify_fail("ÄãµÄÉñÁú°ËÊ½»ðºò²»¹»£¬ÎÞ·¨Ñ§ÉßµºÆæ¹¦¡£\n");
	if ((int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shedao-qigong",1))
		return notify_fail("ÄãµÄÉñÁúÐÄ·¨»ðºò²»¹»£¬ÎÞ·¨¼ÌÐøÑ§ÉßµºÆæ¹¦¡£\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·ÉßµºÆæ¹¦¡£\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shedao-qigong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N¸ßÉù¿ñ½Ð£ºÕ½ÎÞ²»Ê¤£¬¹¥ÎÞ²»¿Ë£¬ÎÞ¼á²»´Ý£¬ÎÞµÐ²»ÆÆ£¡$nÍ·Ò»ÔÎ,ÏÊÑªÅç³ö!\n";
}

 

}