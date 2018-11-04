// luoying-zhang.c ��Ӣ����
// modified by Venus Oct.1997
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N˫��ƽ�죬�����ӳ���һʽ������էչ����ָ����ӯƯ����
���ᷴ��$n��$l",
        "force" : 100,
        "dodge" : 45,
        "damage" : 130,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "����էչ"
]),
([      "action" : "$N������ָ����һ�գ�һʽ���ط����������ָ��Ȼңң����$n��
$nֻ������ɼ���Ϯ���Լ��崦��Ѩ",
        "force" : 110,
        "dodge" : 60,
        "damage" : 160,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "�ط����"
]),
([      "action" : "$NͻȻ����Ծ���գ�һ������ת���������䣬һʽ�����Ƿ�
����������$n��ͷ��",
        "force" : 120,
        "damage" : 100,
        "dodge" : 185,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "���Ƿɻ�"
]),
([      "action" : "$NͻȻԾ��˫�������������罣�����缲�������һʽ���꼱��
�񡹣�����$n��ȫ��",
        "force" : 130,
        "dodge" : 105,
        "damage" : 150,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "�꼱���"
]),
([      "action" : "$N���ֻ������ĳ��죬������ֲ�£ʳָ��ָ�����������һʽ
���Ǻ����졹��ֱָ$n������",
        "force" : 140,
        "dodge" : 120,
        "damage" : 200,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "�Ǻ�����"
]),
([      "action" : "$NͻȻ������ˣ�����һʽ�������׷ɡ���ƽ�����˫����$n
�ĺ�����������",
        "force" : 140,
        "dodge" : 145,
        "damage" : 230,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "�����׷�"
]),
([      "action" : "$NͻȻ����Ծ������Ю�ž�����ӿ�ĳ����������������ƺ�ͻ��
�����һʽ������׷�¡���������ǰ��$n��$l��ȥ",
        "force" : 150,
        "dodge" : 165,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "����׷��"
]),
([      "action" : "$Nʹһʽ�������®����ȫ��ͻȻ������ת��˫�ƺ�ǰ������
������$n���ؿ�",
        "force" : 160,
        "dodge" : 180,
        "damage" : 300,
        "damage_type" : "����",
        "lvl" : 40,
        "skill_name" : "�����®"
]),
([      "action" : "$Nǰ��һ�࣬һʽ�����ƺ�ȡ��������罣��һ����������Ϯ��$n
������",
        "force" : 170,
        "dodge" : 200,
        "damage" : 300,
        "damage_type" : "����",
        "lvl" : 50,
        "skill_name" : "���ƺ��"
]),
([      "action" : "$Nʹһʽ���׺羭�졹��˫���������Ȧ������һ������$n��$l
�ȥ",
        "force" : 180,
        "parry" : 15,
        "damage" : 300,
        "dodge" : 200,
        "damage_type" : "����",
        "lvl" : 70,
        "skill_name" : "�׺羭��"
]),
([      "action" : "$N˫��ʳָ����ָһ�ͣ�һʽ��������������һ��ǿ�ҵ�����ӿ��
$n��ȫ��",
        "force" : 190,
        "parry" : 5,
        "damage" : 320,
        "dodge" : 200,
        "damage_type" : "����",
        "lvl" : 60,
        "skill_name" : "��������"
]),
([      "action" : "$Nһʽ����Ӣ���졹��˫������ǰ��ת���ƻ����裬����ǵ�ֱָ
��$n��$nֻ�������ƻ����ۻ����ҡ�",
        "force" : 200,
        "parry" : 20,
        "damage" : 350,
        "dodge" : 200,
        "damage_type" : "����",
        "lvl" : 99,
        "skill_name" : "��Ӣ����"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����Ӣ���Ʊ�����֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 15)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��Ӣ���ơ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
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
    level = (int)me->query_skill("luoying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("���������������Ӣ���ơ�\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"luoying-zhang/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
       string msg;
       int j, k;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$Nʩչ����������,$n����һ��,������$l�������Ѫ��!!\n";
        }
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("luoying-zhang",1);             
	if (random(5)==1 && me->query_skill("luoying-zhang",1)>100)
	{
	if (!victim->is_busy())
	victim->start_busy(2);
	return HIR"$N��������,$n����һ����֪��֪!!\n"NOR;
	}
	if( damage_bonus > 80 && random(level2)>80) {
	victim->receive_wound("qi", (random(damage_bonus)+150));
	return HIB"$n��һ�ƻ���$lҪ������ʱʹ������!!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("luoying-zhang", 1);
level2 = me->query_skill("luoying-zhang", 1);
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n����ʱ��$N��̤���У�$n��ͷһ��!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
               }

}