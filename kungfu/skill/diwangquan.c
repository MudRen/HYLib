// ÉñÁúµÛÍõÈ­   
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": HIW"$N³¤ĞäÍ»È»·­Æğ¹¥Ïò$nµÄ$l£¬ÈçÁ÷ÔÆ£¬ÈçĞºË®£¬ÕĞÊ½×ÔÈ»ÇÉÃî£¬»ëÈçÌì³É£¬\n"
"¿ÚÖĞÈ´ÀÉÉùÒ÷µÀ£º"HIC"¡°×Ô´«·¼¾Æ·­ºìĞä£¬ËÆÓĞÎ¢´Ê¶¯ç­´½¡£¡±"NOR,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
        "damage_type": "ğöÉË"
]),
([      "action": HIC"$NÒÂÉÀÍ»È»¹Ä¶¯¶øÆğ£¬ÍğÈçÓĞÇ§°ÙÌõÇàÉß£¬ÔÚÒÂÉÀÖĞ´Ü¶¯£¬ÏÔÈ»ÌåÄÚÕæÆøÂúĞî£¬\n"
"×İ²»¶¯ÊÖ£¬Ò²¿ÉÉËµĞ£¬$N¿ÚÖĞÓÖ×ÔÀÊÒ÷µÀ£º"HIM"¡°ÎíÆø°µÍ¨Çà¹ğÔ·£¬ÈÕ»ªÒ¡¶¯»Æ½ğÅÛ¡£¡±"NOR,
        "dodge": 15,
        "parry": 20,
        "force": 18,
        "damage": 160,
        "damage_type": "ğöÉË"
]),
([      "action": HIM"$N×óÊÖÏÂ´¹£¬ÎåÖ¸Á¬Ğøµã»÷$nµÄ$l£¬ÉíĞÎÍ»×ª£¬ÓÒÊÖÒÑ×Ô¼Õ±ß·­ÆğÓÖ»ÓÏò$nµÄ$l£¬\n"
"ÉíĞÎÁ÷¶¯×ÔÈç¿ÚÖĞÒ÷µÀ£º"HIB"¡°´¹ÊÖÂÒ·­µñÓñÅå£¬±³ÈË¶àÕûÂÌÈ¥÷ß¡£¡±"NOR,
	"dodge": 10,
	"parry": 15,
	"force": 12,
        "damage": 160,
	"damage_type": "ğöÉË"
]),
([      "action": HIB"$NÓÒÊÖÒ»Ğ±£¬Ë«±ÛÇúÊÕ£¬ÕĞÊ½Ò»±ä£¬¹¥ÖĞ´øÊØ£¬$N¿ÚÖĞÒ÷µÀ£º\n"
HIY"¡°ÏËÑüÅÂÊø½ğ²õ¶Ï£¬º®÷ŞĞ±ô¢ÓñÑà¹â¡£¡±"NOR,
        "dodge": 15,
	"parry": 11,
	"force": 16,
        "damage": 160,
	"damage_type": "ğöÉË"
]),
([      "action": HIY"$NÉíĞÎÒÑ»Ø·ÉÈı´Î£¬ÊÖÕÆÍ»ÓÖĞ±»Ó¶øÆğÅüÏò$nµÄ$l£¬µÀ£º\n"
HIG"¡°»Æğ¿¾Ã×¡»ëÏàÊ¶£¬ÇàÄñÎ÷·ÉÒâÎ´»Ø¡£¡±"NOR,
	"dodge": 21,
	"parry": 21,
	"force": 20,
        "damage": 160,
	"damage_type": "ğöÉË"
]),
([      "action": HIG"$NÎ¢Î¢Ò»Ğ¦£¬×óÕÆÍ»È»»¯×÷Ò»Æ¬ÕÆÓ°£¬»¤×¡ÁËÈ«ÉíÆßÊ®¶ş´¦´óÑ¨¿ÚÖĞÄîµÀ£º\n"
HIW"¡°Á±Ç°´ºÉ«Ó¦ĞëÏ§£¬Â¥ÉÏ»¨Ö¦Ğ¦¶ÀÃß¡£¡±ÓÒÕÆÕÆÓ°ÖĞÒ»Ö¸µãÏò$nµÄ$l¡£"NOR,
	"dodge": 15,
	"parry": 12,
	"force": 25,
	"damage_type": "ğöÉË"
]),

([      "action" : "$n×¥×¡$NµÄºó¾±£¬Ò»°ÑÌáÆğ¡£"+(order[random(13)])+"¡¸×Óñã¾Ù¶¦¡¹"NOR"£¬ $N×óÊÖ·´×ª£¬ÔÚ$n×óÒ¸µ×É¦ÁËÒ»°Ñ£¬\n"
                   "$nÉí×ÓÈíÁËÏÂÀ´£¬$N×óÊÖÄÃ×¡$nÒ¸ÏÂ£¬ÓÒÊÖÂıÂı»Ø×ª£¬×¥×¡$nÁì¿Ú£¬»º»º\n"
                   "¾ÙÆğ$nµÄÉí×Ó£¬¹ıÁË×Ô¼ºÍ·¶¥£¬ÏòÍâË¤³ö"NOR,
        "force" : 50,
        "dodge" : 5,
        "parry" : 10,
        "damage": 160,
        "lvl" : 0,
        "skill_name" : "×Óñã¾Ù¶¦",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$N¸©·üµØÉÏ£¬$nÓÒ×ãÌ¤×¡$NµÄºóÑü£¬"+(order[random(13)])+"¡¸Â³´ï°ÎÁø¡¹"NOR"£¬$NË«ÍÈÒ»Ëõ,ËÆÓû¹ò°İ,\n"
                   "ÓÒ±ÛÈ´ÂıÂıºáÂÓ¶ø³ö£¬Í»È»¼äÒ»¸ö½î¶·£¬Ïò$nµÄ¿èÏÂ×êÈ¥£¬Ö»Ò»×÷ÊÆ\n"
                   "×óÊÖÒÑ×¥×¡$nÓÒ½Å×ãõ×£¬ÓÒÊÖÏò$nĞ"+(order[random(13)])+"¡¸¹»÷È¥",
        "force" : 60,
        "dodge" : 20,
        "parry" : 20,
        "damage": 190,
        "lvl" : 10,
        "skill_name" : "Â³´ï°ÎÁø",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NË«±Û·´ÔÚ±³ºó£¬Í»È»Ë«ÊÖÊ®Ö¸ÍäÆğ£¬¸÷³É°ëÇòÖ®ĞÎ£¬Éí×ÓÏòºóÒ»×²\n"
                   "Ê®Ö¸±ã×¥Ïò$nµÄĞØ²¿£¬$nÏòºóÒ»Ëõ£¬$NÍ»È»Ò»¸öµ¹·­½î¶·£¬Éí×ÓÔ¾Æğ\n"
                   "Ë«ÍÈÒ»·Ö£¬¿çÔÚ$n¼çÍ·£¬"+(order[random(13)])+"¡¸µÒÇà½µÁú¡¹"NOR"£¬Í¬Ê±Ë«ÊÖ°´Ö¸Ñ¹×¡$nÌ«ÑôÑ¨,Ê³Ö¸°´Ã¼,ÖĞÖ¸°´ÑÛ",
        "force" : 100,
        "dodge" : 30,
        "parry" : 30,
        "damage": 210,
        "lvl" : 20,
        "skill_name" : "µÒÇà½µÁú",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÉí×ÓÎ¢Çú£¬ÏËÑüÇáÅ¤,×ó×ã·´Ìß,"+(order[random(13)])+"¡¸¹óåú»Øíø¡¹"NOR",Ïò$nĞ¡¸¹ÌßÈ¥,$nºóËõÏà±Ü,\n"
                   "$NË³ÊÆ·´¹ıÉíÀ´£¬×óÊÖÂ§×¡$nÍ·¾±£¬ÓÒÊÖÎÕ½£¶Ô×¼$nºóĞÄ£¬Ò»½£´ÌÈ¥",
        "force" : 70,
        "dodge" : 5,
        "parry" : 10,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "¹óåú»Øíø",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N·­ÉíÎÔµ¹,$nÉì³öÓÒ×ãÌ¤×¡$NµÄºóÑü£¬"+(order[random(13)])+"¡¸Ğ¡Á¯ºá³Â¡¹"NOR",$NµÄÄÔ´üÏò×ÅËı×Ô¼ºµÄĞØ¿Ú×êÂä,\n"
                   "Ë³ÊÆÔÚµØÏÂÒ»¸ö½î¶·£¬ÔÚ$nµÄ¿èÏÂ×ê¹ı£¬ÓÒÊÖÎÕ½£´ÌÈë$nµÄºóĞÄ",
        "force" : 80,
        "dodge" : 20,
        "parry" : 20,
        "damage": 220,
        "lvl" : 10,
        "skill_name" : "Ğ¡Á¯ºá³Â",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÓÒ×ãÏòÇ°ÇáÌß,Ë³ÊÆÒ»¹´£¬"+(order[random(13)])+"¡¸·ÉÑà»ØÏè¡¹"NOR",ÍÈÉÏµÄ½£¼²Ïò$nµÄÑÊºí´ÌÈ¥",
        "force" : 120,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "lvl" : 20,
        "skill_name" : "·ÉÑà»ØÏè",
        "damage_type" : "´ÌÉË"
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="xuanming-zhang" || combo == "dulong-shenzhua"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·ÉñÁúµÛÍõÈ­±ØĞë¿ÕÊÖ¡£\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«ÈõÁË£¬ÎŞ·¨Á·Ï°ÉñÁúµÛÍõÈ­¡£\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 180)
		return notify_fail("ÄãµÄÉñÁúĞÄ·¨»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 180)
		return notify_fail("ÄãµÄÉñÁúÍÈ·¨»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("dulong-shenzhua", 1) < 180)
		return notify_fail("ÄãµÄ¶¾ÁúÉñ×¦¹¦»ğºò²»¹»£¬ÎŞ·¨ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 180)
		return notify_fail("ÄãµÄ»¯¹ÇÃàÕÆ»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 180)
		return notify_fail("ÄãµÄÉßµºÆæ¹¦»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 180)
		return notify_fail("ÄãµÄÉñÁú°ËÊ½»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("xuanming-zhang", 1) < 180)
		return notify_fail("ÄãµÄĞşÚ¤ÉñÕÆ»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("yixingbu", 1) < 180)
		return notify_fail("ÄãµÄÒâĞÎ²½·¨»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");

	if ((int)me->query_skill("qingshe-sword", 1) < 80)
		return notify_fail("ÄãµÄÇàÉß½£·¨»ğºò²»¹»£¬ÎŞ·¨Ñ§ÉñÁúµÛÍõÈ­.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return
notify_fail("ÉñÁúµÛÍõÈ­Ö»ÄÜÓÃÑ§µÄ¡£\n");
}

int effective_level() { return 20;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 30;
}

mixed hit_ob(object me, object victim, int damage_bonus)
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
 return HIR "$N¸ßÉù¿ñ½Ğ£ºÕ½ÎŞ²»Ê¤£¬¹¥ÎŞ²»¿Ë£¬ÎŞ¼á²»´İ£¬ÎŞµĞ²»ÆÆ£¡$nÍ·Ò»ÔÎ,ÏÊÑªÅç³ö!\n";
}

        if (random(7)==0  && me->query("neili") >= 100)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "ºöÈ»¸Ğµ½Ò»¹ÉÄªÃûµÄ¶ñĞÄ£¬Òõº®µÄÀäÆø¹¥ĞÄ£¬È«ÉíÌ±Èí£¬×ìÆ¤ÎÚ×Ï¡£\n" NOR;
        }
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() || random(10)==0) {
                victim->receive_wound("qi", (damage_bonus - 60) / 2+20 );
                switch(random(3)) {
                        case 0: return HIR"ÄãÌıµ½"+(order[random(13)])+"¡¸¿¦À²¡¹"HIR"£¬Ò»ÉùÇáÏì£¬¾¹ËÆÊÇ¹ÇËéµÄÉùÒô£¡\n"NOR;
                        case 1: return RED"$N¾¢Á¦Ò»ÍÂ£¬$nµÄ$l·¢³ö"+(order[random(13)])+"¡¸¿¦¡¹"RED"£¬µØÒ»Éù±¬Ïì£¡\n"NOR;
                        case 2: return HIY"Ö»Ìı¼û$nµÄ$l"+(order[random(13)])+"¡¸¿¦¡¹"HIY"£¬µØÒ»Éù ...\n"NOR;
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"diwangquan/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("diwangquan", 1)  % 10 == 0 ) {
                tell_object(me,
                        HIW "\nÄãÍ»È»¾õµÃÒ»¹ÉÕıÆø³åÉÏĞÄÍ·£¬Ö»¾õµÃÊÀ¼äÓĞÌ«¶àµÄ²»Æ½ÊÂ....\n\n"
 NOR);
                me->add("score", 1);
        } else
                me->add("score", 1);
}

string *parry_msg = ({
	"$nÉîÎüÒ»¿ÚÆø£¬¾ÍÏóÕ³ÔÚ$NµÄ$wÉÏÒ»Ñù¡£\n",
        "$nÉí×ÓÎ¢Î¢Ò»²à£¬ÒÑ¶ã¿ª$NµÄ¹¥ÊÆ¡£\n",
        "$n¾ÍÊÆÒ»¹ö£¬Ë«ÊÖÒ»³ÅµØ£¬È«Éíµ¯³ö$NµÄ¹¥»÷·¶Î§¡£\n",
});

string *unarmed_parry_msg = ({
        "$nÉí×ÓÎ¢Î¢Ò»²à£¬ÒÑ¶ã¿ª$NµÄ¹¥ÊÆ¡£\n",
	"$nË«È­´íÂä£¬»¤×¡È«ÉíÒªº¦¡£\n",
        "$nË«ÊÖ¼±×¥$NµÄÊÖÍó£¬$NÊÖÖĞµÄ±øÆ÷¼¸ºõÍÑÊÖ¶ø³ö¡£\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

