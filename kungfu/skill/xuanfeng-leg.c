// xuanfeng-leg.c ����ɨҶ��
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N˫����Σ�����͵ط���һʽ"+(order[random(13)])+"��������ӿ��"NOR"���ż�ζ�����
��$n��ƨ��",
        "damage" : 300,
        "dodge" : 15,
        "force" : 115,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "������ӿ"
]),
([      "action" : "$N��Ŷٵأ���ת�����������ߣ�ֻһɲ�Ǽ�һ�����ҽ�һʽ
"+(order[random(13)])+"���չ�������"NOR"������$n��$l",
        "damage" : 320,
        "force" : 50,
        "dodge" : 110,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "�չ�����"
]),
([      "action" : "$N����һ��������Ť��ס$n�����֣��ҽ�ͬʱ�߳���������׼��һ
ʽ"+(order[random(13)])+"����Ԩ���ԡ�"NOR"�����е�$n���ؿ�",
        "damage" : 340,
        "dodge" : 15,
        "force" : 110,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "��Ԩ����"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ"+(order[random(13)])+"�������Ҷ��"NOR"������糾������
$n��ȫ��",
        "damage" : 360,
        "force" : 150,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "�����Ҷ"
]),
([      "action" : "$N���ֻ��أ�˫�Ž�������һʽ"+(order[random(13)])+"����ɨ���ơ�"NOR"���ŽŲ���$n����
������",
        "damage" : 280,
        "force" : 180,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "��ɨ����"
]),
([      "action" : "$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶���һʽ"+(order[random(13)])+"������׹
�ء�"NOR"����$n������ֱ������",
        "force" : 200,
        "damage" : 300,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "����׹��"
]),
([      "action" : "$Nʹһʽ"+(order[random(13)])+"��˷�紵ѩ��"NOR"��ȫ��ͻȻ������ת��˫���ǰ����Ѹ��
�޼�����$n���ؿ�",
        "force" : 250,
        "damage" : 320,
        "dodge" : 30,
        "damage_type" : "����",
        "lvl" : 40,
        "skill_name" : "˷�紵ѩ"
]),
([      "action" : "$N����Ծ�𣬿������������һ�����ˣ�һʽ"+(order[random(13)])+"���׶����졹"NOR"��˫��
�����������$n��$l",
        "force" : 350,
        "damage" : 350,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "�׶�����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="leg"; } 

int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɨҶ�ȱ�����֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 15)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ����ɨҶ�ȡ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�������ɨҶ�ȡ�\n");
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
    level = (int)me->query_skill("xuanfeng-leg", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("�����������������ɨҶ�ȡ�\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xuanfeng-leg/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
       string msg;
       int j, k;
 //int level;
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
level2= (int) me->query_skill("xuanfeng-leg",1);             
	if (random(5)==1 && me->query_skill("xuanfeng-leg",1)>100)
	{
	if (!victim->is_busy())
	victim->start_busy(2);
	return HIR"$N��������,$n����һ����֪��֪!!\n"NOR;
	}
	if( damage_bonus > 80 && random(level2)>60) {
	victim->receive_wound("qi", (random(damage_bonus)+50));
	return HIB"$n��һ������$lҪ������ʱʹ������!!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("xuanfeng-leg", 1);
level2 = me->query_skill("xuanfeng-leg", 1);
        if (  level2 > 100
        && random(5)==1){
 
            msg = HIC"$n����ʱ��$N��̤���У�$n��ͷһ��!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
               }

}
