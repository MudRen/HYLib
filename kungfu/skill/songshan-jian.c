// songshan-jian.c  ��ɽ����

#include <ansi.h>
#include <combat.h>

inherit SKILL;
int next_sword(object me, object victim, object weapon, int damage);
mapping *action = ({
([      "action" : "$N�ٽ�������������������һʽ���������ڡ���$w��$n��$l�����ȥ��",
        "force" : 120,
        "dodge" : 20,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "ͻȻ�佣��һ�£�$w����һ���׺磬$Nʹ��һʽ��ǧ�����������������ӣ�$wֱ��$n��$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 270,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$N��������һ�֣�����$w�����ӳ�һ�С����ż�ɽ��������ɭȻ����$n��$l��ȥ",
        "force" : 200,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһ���ӿ��м������£���ʽ����ƽƽ���棬������һ���죬ʵ��ʯ���쾪�����ƣ�һ�С�������ɽ��$w���ش���$n��$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 290,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��$w�԰���к��������������ֱ����һ������һ�㣬һʽ���������������ڽ�ز�������ۻ��ն��$n��$l",
        "force" : 270,
        "dodge" : 10,
        "damage" : 200,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N��������һʽ������ء���$w��Ȼһ��������ǧ�������۶�������������$n��$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 210,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N��תһʽ�����両�ࡹ��ٲȻ��ǹ��ꪣ���ɳǧ�$w������������$n���������ؽ���֮��",
        "force" : 300,
        "dodge" : 5,
        "damage" : 230,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N�������£�һ�С���Х���졹��$w��Ȼ��ת���ϣ�����Ľ�����$n����Ҫ������Χס",
        "force" : 380,
        "dodge" : -5,
        "damage" : 240,
        "lvl" : 70,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 20)
                return notify_fail("�����ɽ�������̫ǳ��\n");
        if ((int)me->query_skill("songyang-zhang", 1) < 20)
                return notify_fail("��Ĵ��������ƻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{

        int i, level, xuli;
	level   = (int) me->query_skill("songshan-jian",1);
	xuli = me->query_temp("songshan_xuli");

	if (me->query_temp("s_hit"))
	return ([
	"action":HIW"ͻȻ�亮��һ����$N����$w"+HIW"ֱ����$n�������𵴶���������ʵ��Ǭ��һ�����ͻ���һ��֮�������������֮�ƣ�"NOR,
        "force" : 600 + xuli/5,
	"dodge" : 10,
        "parry" : 10,
        "damage": 600 + xuli/10,
	"post_action": (: next_sword :),	
        "damage_type":  "����"
]);

	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("���������������ɽ������\n");
        me->receive_damage("jing", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-jian/" + action;
}


int next_sword(object me, object victim, object weapon, int damage)
{
	int wap,wdp;
	object ob;
	ob = victim->query_temp("weapon");
if (!victim) return 1;
if (!me) return 1;
victim->start_busy(2);
        if(victim->query("eff_qi") < 0 && victim->query("qi") < 0) 
        {
        message_vision(HIW"�����Ž��������"+weapon->name()+HIW"һ����$n���ֱ������������һ���Ƶ�֮�������˵��Ƿ�����˼��ֻ�������һ����$n�ѱ�ն�����أ�\n"NOR, me,victim );
        
        }
        	
        else if( damage==RESULT_PARRY && objectp(ob = victim->query_temp("weapon")) ) 
        {
                
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str()
                        + (int)me->query("jiali")
                        + (int)me->query_skill("songshan-jian")/3
                        + me->query_temp("songshan_xuli");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("jiali")
                        + (int)victim->query_skill("parry")/3;
                wap = random(wap/2)+wap/2;

                if( wap > 3 * wdp ) {
	message_vision(HIY"$N����"+weapon->name()+HIY"�����߾�����������һ���죬��$n��"+ob->name()+HIY"һײ��������ʮ���������ȥ��$n����"+ob->name()+HIY"��ϣ��۳���ʮ�ص��ڵ��£�\n"NOR, me,victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�����" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > 2 * wdp ) {
                        message_vision(HIW"����$N����"+weapon->name()+HIW"�����߾���$n�ֱ����飬���ھ�ʹ��"+ob->name()+HIW"��ʱ���֣�\n" NOR,me,victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("songshan-jian",1);

	if( random(6)==0 
	&& me->query_skill("songshan-jian",1) > 290) {
	victim->start_busy(3);
	victim->apply_condition("cold_poison", victim->query_condition("cold_poison") + random(4));
	return HIC"$nͻȻȫ��һ�䣡�޷��������������˼��صĺ���������\n"NOR;
}

}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("songshan-jian",1);
        level2= (int) me->query_skill("songshan-jian",1);
        skill = me->query_skill("songshan-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("songshan-jian",1);
damage2= (int) ob->query("neili",1)/10;
if (random(6)==0 && level2>=290 && (me->query_skill_mapped("sword") == "songshan-jian"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"ʹ���������� !$nȫ��һ�䣡�޷������� \n" +NOR;
ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
  ob->start_busy(3);
           message_vision(msg, me, ob);
  
}


           return j;
}      