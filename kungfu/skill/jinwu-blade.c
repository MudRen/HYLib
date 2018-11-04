// jinwu-blade.c ���ڵ���
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *mjj = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N����$wֱ����һ��"+(mjj[random(13)])+"������Ҿ����"NOR"��Ю�ž�������֮ʽ����$n��ͷ����",
        "force" : 230,
        "dodge" : 10,
        "damage" : 100,
        "damage_type" : "����" ]),
([      "action" : "$Nһ��"+(mjj[random(13)])+"��÷ѩ���ġ�"NOR"������һƬ��Ļ��ֻ���������죬��$n������ȥ",
        "force" : 250,
        "dodge" : -10,
        "damage" : 150,
        "damage_type" : "����"
]),
([      "action" : "$N�ᵶֱ�ӣ�һ��"+(mjj[random(13)])+"���������ء�"NOR"����������,£��һ��쭣���$n$l��ȥ",
        "force" : 280,
        "dodge" : 5,
        "damage" : 200,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(mjj[random(13)])+"�����ս�ġ�"NOR"��$w��������������һ���â�Ե��ϼ��������ӳ��$n\n˫�۽��գ�$N�˻�������ǰ,�ӵ���ն$n$l",
        "force" : 300,
        "dodge" : 15,
        "damage" : 220,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ��"+(mjj[random(13)])+"��ǧ��ѹ�ա�"NOR"��$w���Ƴ��Ͳ���,ʵ���ƻ�ʵ�죬��������һ��������\nֱ��$n$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����"
]),
([      "action" : "$N��$w����һ����ʹ��һ��"+(mjj[random(13)])+"���󺣳�ɳ��"NOR"��$w��ʱ��ʧ����Ӱ���٣�$n�����ɼ䣬\nֻ������һ����$w��Ѹ�������ն��$l",
        "force" : 350,
        "dodge" : 15,
        "damage" : 300,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(mjj[random(13)])+"������֮����"NOR"������$w����ʮ�˵������ƻ��Ҳ�����ʵ�򵶵�����$nҪ��",
        "force" : 400,
        "dodge" : 15,
        "damage" : 350,
        "damage_type" : "����"
]),
([      "action" : "$N̤����ǰ��ʹ��"+(mjj[random(13)])+"���������ס�"NOR"������$w�����ӣ�����һ�ش����棬��$n��ͷ������նȥ",
        "force" : 500,
        "dodge" : 10,
        "damage" : 500,
        "damage_type" : "����"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("�������������û�а취�����ڵ�����\n"); 
        if( (int)me->query_skill("xueshan-sword",1)<80)
                return notify_fail("���ڵ���������ѩɽ����Ϊ���ײ�����ϰ��\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("���������һ�ѵ�������������\n");

    return 1;
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        level   = (int) me->query_skill("jinwu-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 20
        ||      (int)me->query("neili") < 10 )
                return notify_fail("�����������������û�а취��ϰ���ڵ�����\n");
        me->receive_damage("qi", 10);
        me->add("neili", -5);
        //write("�㰴����ѧ����һ����ڵ�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinwu-blade/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level,level2,level3,jiali, time;
	string msg;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xueshan-sword",1);
	level2 = (int) me->query_skill("jinwu-blade",1);
	level3 = (int) me->query_skill("bingxue-xinfa",1);
	jiali = me->query("jiali");
if (!me) return;
if(me->is_busy()) return;
if (!victim) return;
//if (victim =me) return;
if (!weapon) return;
if (!jiali) jiali=100;
        if( random(level) > 100 && random(level3)>100 && random(level2)>100 && !me->query_temp("noauto")) {
        message_vision(WHT"$Nһ��������ʽͻ�䣬���õ�ʹ����ѩ����������ʽ����$n������Ҫ����\n" NOR, me, victim );
        msg =  HIR "������������\n" NOR;
if (me && victim &&!me->is_busy()
&& !me->query_temp("jwauto")
)
{
me->set_temp("jwauto",1);
if (!me->is_busy())
me->start_busy(1);
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR,msg);
	victim->receive_wound("qi", random(jiali));
me->delete_temp("jwauto");
}
	return HIR"$N�������������"+weapon->name()+HIR"����ΪһƬ"+HIW"ѩ����\n"NOR;
        }
else    if( random(level) > 80 && random(level3)>80 && !me->query_temp("noauto")  ) {
	victim->receive_wound("qi", random(jiali)+50);
	return HIW"ֻ��$n$l����Ѫ���������㵶�۲������ǣ��ѱ�"+weapon->name()+HIW"��������Ĵ������㡣\n"NOR;
        }

}

 int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bingxue-xinfa",1);
        level2= (int) me->query_skill("bingxue-xinfa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bingxue-xinfa" )
{
if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}
if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}
msg = HIB "$N" HIB "�����Ѫ�ķ�!! ȫ�����˿�һ˲��ֹס����Ѫ��\n" NOR;
msg += HIB "һ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$n������\n" NOR;
ob->apply_condition("xscold_poison",12);

           message_vision(msg, me, ob);
           return j;
}       
}     