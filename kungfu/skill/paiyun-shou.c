// panyun-shou.c ��������

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([	"action" : "$N�翪��������ǰ����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 30,
        "dodge" : 1,
        "parry" : 4,
	"damage": 110,
	"lvl" : 0,
        "damage_type" : "ץ��"
]),
([	"action" : "$N�˺�һ����˫��һ���ų����繳��ꫣ�����$n��$l",
	"force" : 40,
	"dodge" : 15,
        "parry" : 5,
	"damage": 110,
	"lvl"   : 15,
	"damage_type" : "����"
]),
([	"action" : "$N����һת�����ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"force" : 60,
        "dodge" : 18,
        "parry" : 7,
	"damage": 10,
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶���������$n��$l",
	"force" : 80,
	"dodge" : 25,
        "parry" : 11,
	"damage": 112,
	"lvl"   : 40,
	"damage_type" : "����"
]),
([	"action" : "$N���ֻ��أ�Ҹ�º��գ�������ָ�繳������$n��ҪѨ",
	"force" : 100,
	"dodge" : 30,
        "parry" : 14,
	"damage": 15,
	"lvl"   : 50,
	"damage_type" : "����"
]),
([	"action" : "$N����б�ϣ�����ȡĿ�����ַ���$n���ɲ�",
	"force" : 115,
	"dodge" : 35,
        "parry" : 17,
	"damage": 119,
	"lvl"   : 60,
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ָ$n�Ľ���������ץ��$n���еı���",
	"force" : 130,
	"dodge" : 32,
        "parry" : 13,
	"damage": 121,
	"lvl"   : 70,
	"damage_type" : "ץ��"
]),
([	"action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ������л�$n",
	"force" : 150,
	"dodge" : 38,
        "parry" : 18,
	"damage": 124,
	"lvl"   : 80,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�ֳ��죬һ��ָ�أ���������$n��ȫ��",
	"force" : 170,
	"dodge" : 42,
        "parry" : 12,
	"damage": 127,
	"lvl"   : 90,
	"damage_type" : "����"
]),
([	"action" : "$Nȭ�����������֣��������ޣ�����������$n�ĵ���",
	"force" : 190,
        "dodge" : 50,
        "parry" : 15,
	"damage": 130,
	"lvl" : 100,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo)
{
        return  combo == "yitian-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������ֱ�����֡�\n");

	if ((int)me->query_skill("force") < 40)
		return notify_fail("����ڹ���򲻹����޷�ѧ�������֡�\n");

	if ((int)me->query("max_neili") < 250)
		return notify_fail("�������̫�����޷����������֡�\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("paiyun-shou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("��������������������֡�\n");
        if ((int)me->query_skill("taiji-quan", 1) < 30)
                return notify_fail("��ġ�̫��ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("wudang-mianzhang", 1) < 30)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");
	me->receive_damage("qi", 37);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"paiyun-shou/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j,damage;
    j = me->query_skill("paiyun-shou", 1);
   
    if( damage_bonus < 100 ) return 0;
    if(random(3) == 0 && !victim->is_busy() && j > 120 &&
       me->query("neili") > victim->query("neili") &&
        me->query_skill("taiji-shengong", 1) > 150 &&
       me->query_skill_mapped("force") == "taiji-shengong" 
        &&       me->query_skill_mapped("parry") == "paiyun-shou" 
       &&       me->query("neili") > 600 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("dodge",1))){
        switch(random(4)){
            case 0 :
               msg = HIC "$N" HIC "�溬΢Ц��˫���������ǰһ�ƻ�����"
                                            "һ��ԲȦ����Ȼ��$n" +
                                            HIC "����������\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5+20);
                me->add("neili", -damage/10);
               break;
             case 1 :
               msg = HIC "$N" HIC "���Ҹ񵵣�ʹ��������ǧ����ַ���һ������"
                                            "��$n" HIC "�˵��ڵء�\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5+20);
                me->add("neili", -damage/10);
                break;
            case 2 :
               msg = HIY "$N" HIY "������ȭ"
                                 HIY "����������ȴ��$n"
                                 HIY "�е�ճ�ͣ�������$N"
                                 HIY "�����п��ٽ���$nȫ��!"
                                 HIY "��\n" NOR;
                damage = damage_bonus/4 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage+10) 
                                 { victim->set("jing",10); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
           if (!victim->is_busy())
{
                victim->start_busy(2);  
}
                me->add("neili", -20);     
               break;
            case 3 :
               msg = HIY "$N" HIY "�溬΢Ц��˫�������������"
                                 "һ��ԲȦ��Ȼ��$N" +
                                 HIY "����һ�˻���ֱ�룬��Ϯ$n"
                                 HIY "��\n" NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
                if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
            }
        switch(random(4)){
         case 0 : msg += HIR"���$n����������ǰһ�壬�����������ʼվ����\n"NOR; break;
         case 1 : msg += HIR"���$n����������ԭ�ؼ�ת���߰��£���ת���ݣ������Ĵ���\n"NOR; break;
         case 2 : msg += HIR"��ʱ���׵�$n����ײײ�������������㲻�ȣ������оƻ��ԡ�\n"NOR; break;
         case 3 : msg += HIR"$n��ʹ��ǧ��׹֮����ס���Σ�ȴ�������͵�ͨ�죬���ɼ����Ǳ���״��\n"NOR; break;
         }
        message_vision(msg, me, victim);
        }
}