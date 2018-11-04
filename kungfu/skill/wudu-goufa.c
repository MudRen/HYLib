// wudu-goufa.c Îå¶¾¹³·¨

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"\n$NÊÖÖĞ$wÒ»¶¶£¬Ò»Ê½"+(order[random(13)])+"¡¸ÁéÉßÍÂĞÅ¡¹"NOR"£¬ÉÁµç°ãµÄ¼²´ÌÏò$nµÄ$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 315,
	"lvl" : 0,
	"skill_name" : "ÁéÉßÍÂĞÅ",
	"damage_type":	"´ÌÉË"
]),
([	"action":"\n$NÒ»Ê½"+(order[random(13)])+"¡¸ÈáË¿ÇáÏµ¡¹"NOR"£¬½£ÒâÃàÃà²»¾ø£¬»¯×öÒ»ÕÅÎŞĞÎµÄ´óÍø½«$nÀ§ÔÚµ±ÖĞ",
	"force" : 240,
        "dodge" : 10,
	"damage": 325,
	"lvl" : 10,
	"skill_name" : "ÈáË¿ÇáÏµ",
	"damage_type":	"´ÌÉË"
]),
([	"action":"\n$NÒ»ÉùÒõĞ¦£¬·ÉÉí×İÆğ£¬Ò»Ê½"+(order[random(13)])+"¡¸ÕÅÑÀÎè×¦¡¹"NOR"£¬ÊÖÖĞ$w¿ñÎè£¬»Ã³öÇ§ÍòÌõ\nÊÖ±Û£¬ºÏÉíÆËÏò$n",
       "force" : 380,
        "dodge" : 15,
	"damage": 340,
	"lvl" : 25,
	"skill_name" : "ÕÅÑÀÎè×¦",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$N×ã¼âµãµØ£¬ÉíĞÎÒ»Ğı¿´ËÆÓû×ß£¬ÊÖÖĞ$wÈ´Ù¿µÄ´ÓÒ¸ÏÂ´©¹ı£¬¼²´ÌÏò$nµÄ$l,\nºÃÒ»Ê½"+(order[random(13)])+"¡¸ÌìĞ«²ØÕë¡¹"NOR"",
       "force" : 480,
        "dodge" : 40,
	"damage": 350,
	"lvl" : 35,
	"skill_name" : "ÌìĞ«²ØÕë",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$N½Å²½õÔõÄ£¬ÉíĞÎºöµÄÏòÇ°µøµ¹£¬Ò»Ê½"+(order[random(13)])+"¡¸¾®µ×ÍûÔÂ¡¹"NOR"£¬ÕÆÖĞ$w×ÔÏÂ¶øÉÏÖ±\n´Ì$nµÄĞ"+(order[random(13)])+"¡¸¹",
       "force" : 580,
        "dodge" : 40,
	"damage": 360,
	"lvl" : 50,
	"skill_name" : "¾®µ×ÍûÔÂ",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$NÉíĞÎÒ»»Î£¬Ò»Ê½"+(order[random(13)])+"¡¸½ğÉß²øÍó¡¹"NOR"£¬ÊÖÖĞ$wÈç¸½¹ÇÖ®Çù°ãÎŞÉùÎŞÏ¢µØ´ÌÏò$n\nµÄÊÖÍó",
       "force" : 680,
        "dodge" : 70,
	"damage": 380,
	"lvl" : 60,
	"skill_name" : "½ğÉß²øÍó",
	"damage_type":	"´ÌÉË"
]),
([	"action":"\n$NÒ»ÉùÀ÷Ğ¥£¬ÉíĞÎ³åÌì¶øÆğ£¬Ò»Ê½"+(order[random(13)])+"¡¸Éñó¸¾Å±ä¡¹"NOR"£¬ÕÆÖĞ$wÈç¹í÷È°ãÁ¬´Ì\n$nÈ«Éí¾ÅµÀ´óÑ¨",
	"force" : 450,
        "dodge" : 80,
	"damage": 400,
	"lvl" : 70,
	"skill_name" : "Éñó¸¾Å±ä",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$NÉîÎüÒ»¿ÚÆğ£¬Ë«ÊÖÎÕ¹³£¬ÕĞÑİ"+(order[random(13)])+"¡¸Íò¶¾ÖÁ×ğ¡¹"NOR"£¬$w¼â¶ËÍ¸³öÒ»ÌõÇ¿¾¢µÄºÚ\nÆø£¬ÉÁµç°ãµÄÏ®Ïò$n",
       "force" : 780,
        "dodge" : 45,
	"damage": 550,
	"lvl" : 80,
	"skill_name" : "Íò¶¾ÖÁ×ğ",
	"damage_type":	"ÄÚÉË"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("ÄãµÄÎå¶¾Éñ¹¦»ğºòÌ«Ç³¡£\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("ÄãµÄ»ù±¾ÄÚ¹¦»ğºòÌ«Ç³¡£\n");
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
	level   = (int) me->query_skill("wudu-goufa",1);
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
	if ((int)me->query("qi") < 40)
		return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·Îå¶¾¹³·¨¡£\n");
	me->receive_damage("qi", 20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$NÊ¹³öÎå¶¾Éñ¹¦£¡ÌòÁËÌò$nÁ÷³öµÄÏÊÑª£¬È«ÉíµÄÉËºÃÏñºÃÁËºÜ¶à£¡!\n";
}
if (damage_bonus <10) damage_bonus=10;
  if( random(damage_bonus/2) > victim->query_con() ) {
		victim->receive_wound("qi", damage_bonus/ 3 );
        return HIM "$nÉíÖĞ¾Ş¶¾£¬ÃÆºßÒ»Éù,Éí×Ó»ÎÁËÁ½»Î£¡\n" NOR;
	}
    if ( victim->query("family/family_name")!= "Îå¶¾½Ì" && me->query_skill("wudu-shengong",1)>40) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$nÖ»¾õµÃÉË´¦Ò»Õó·¢Âé£¬ËÆºõÖĞ¶¾ÁË¡£\n" NOR;
   }
}
string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}
