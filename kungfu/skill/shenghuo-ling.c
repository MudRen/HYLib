// Shenghuo-ling  ʥ���
// Shark , 98/10/01 ����
// ����Ƶ��Ultra Mind Studio ,Copyright 1998

#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action": ""+(order[random(13)])+"$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС����
�ġ��ж�������������Ѩ��$nֻ���°��������Ѷ������һ��"NOR"",
        "force" : 150,
        "dodge" : 20,
"parry" : 20,
    "damage": 200,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"ͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪���
�ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ"NOR"",
        "force" : 150,
"parry" : 20,
    "dodge": 20,
    "damage": 200,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n������
����Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����"NOR"",
    "dodge": 30,
"parry" : 20,
        "force" : 150,
    "damage": 220,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����"NOR"",
"parry" : 20,
        "force" : 150,
    "dodge": 20,
    "damage": 290,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��"NOR"",
        "force" : 150,
"parry" : 20,
    "dodge": 20,
    "damage": 280,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮
Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�"NOR"",
        "force" : 250,
"parry" : 20,
    "dodge": 20,
    "damage": 230,
    "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��"NOR"",
        "force" : 250,
"parry" : 20,
    "dodge": 20,
    "damage": 250,
    "damage_type": "����"
]),
([      "action" : ""+(order[random(13)])+"$N������$w��ӣ�һʽ����ɨǧ������$w����һ�ɷ�������ʻ��$n���ʺ�"NOR"",
        "skill_name" : "��ɨǧ��",
        "force" : 150,
        "dodge" : 20,
        "parry" : 20,
        "lvl" : 30,
        "damage" : 300,
        "damage_type" : "����",
]),
([      "action" : ""+(order[random(13)])+"$N˫�ֳ�$w�ٹ�ͷ������Ȼ�ӳ����콵�����\nֻ��һ��ǿ����������$w�Կն�����Ϯ��$n"NOR"",
        "skill_name" : "�콵���",
        "force" : 280,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 60,
        "damage" : 350,
        "damage_type" : "����",
]),
([      "action" : ""+(order[random(13)])+"$N��ߤ$w�����������������߳����첽��\n��ʱ������������$N����������$wն��$n��ͷ­�����Ż����������ħ��"NOR"",
        "skill_name" : "�����ħ",
        "force" : 320,
        "dodge" : 50,
        "parry" : 30,
        "lvl" : 100,
        "damage" : 300,
        "damage_type" : "����",
]),

([      "action" : HIR"ֻ��$N����̫�ͣ�$w����׹�䣬$N��æ����ȥ��\n$n������˴��ʱ������ϷŹ���һ������׼��ʩչ�ֶ�\n$n��֪��������ʥ����ľ��С�����Ϣ�ġ���ֻ��$NͻȻһ�����ӷ���$nֻ�е��ؿڱ�������ʱ����$w���������ദ��"NOR,
        "skill_name" : "����Ϣ��",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "lvl" : 120,
        "damage" : 500,
        "damage_type" : "����",
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        object weapon;
        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("����ѹ�ӥצ�����̫ǳ��\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("��ĺ������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 30)
                return notify_fail("���ʥ���񹦵����򲻹����޷�ѧʥ�����\n");
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
        if (random(me->query_skill("sword")) > 150 &&
            me->query_skill("force") > 150 &&
            me->query("neili") > 500)
         {
                me->add("neili", -30);
                return ([
          "action" : "ֻ��$N����̫�ͣ�$w����׹�䣬$N��æ����ȥ��\n$n������˴��ʱ������ϷŹ���һ������׼��ʩչ�ֶ�\n$n��֪��������ʥ����ľ��С�����Ϣ�ġ�\nֻ��$NͻȻһ�����ӷ���$w���¶��ϼ�����$n��ȥ��",
        "skill_name" : "����Ϣ��",
        "force" : 500,
        "dodge" : 100,
        "parry" : 100,
       "lvl" : 120,
        "damage" : 700,
        "damage_type" : "����",
                       ]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������������ʥ�����\n");
        if ((int)me->query("neili") < 600)
                return notify_fail("�������������ʥ�����\n");
        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("����ѹ�ӥצ�����̫ǳ��\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("��ĺ������ƻ��̫ǳ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-ling/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N��������� ȫ���������������ֳ�һ����͵ľ���! !" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}


           return j;
}      

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 16 + victim->query_condition("ice_poison"));
}