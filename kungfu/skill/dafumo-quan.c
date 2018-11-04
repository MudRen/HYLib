#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : HIY"$N˫��һ�֣�����$n����ǰ��ͻȻʹ������ӳ��ա���˫ȭϮ��$n"NOR,
        "force" : 280,
        "dodge" : 70,
        "lvl" : 0,
        "skill_name" : "��ӳ���",
        "damage_type" : "����"
]),
([      "action" : HIG"$Nʹ���������쿪������ȭΪ�ƣ�˫�Ʋ�������$n"NOR,
        "force" : 300,
        "dodge" : 50,
        "lvl" : 7,
        "skill_name" : "�����쿪",
        "damage_type" : "����"
]),
([      "action" : HIR"$NһԾ��$n��ǰ�����綯��ͥ����һȭ����$n"NOR,
        "force" : 330,
        "dodge" : 50,
        "lvl" : 15,
        "skill_name" : "�綯��ͥ",
        "damage_type" : "����"
]),
([      "action" : HIB"$Nֻ�����أ��Ż��󿪣�һ�С���Ŀ����������$n"NOR,
        "force" : 350,
        "dodge" : 60,
        "lvl" : 28,
        "skill_name" : "��Ŀ����",
        "damage_type" : "����"
]),
([      "action" : HIW"$N˫ȭ�趯��ɣ�һʽ���������ɨ��$n������"NOR,
        "force" : 400,
        "dodge" : 60,
        "lvl" : 45,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : HIC"$N���ΰ������ն��£���ȭ�Ӻ�ա�����$n"NOR,
        "force" : 450,
        "dodge" : 60,
        "lvl" : 60,
        "skill_name" : "ȭ�Ӻ��",
        "damage_type" : "����"
]),
([      "action" : HIM"$N������������վ����˫ȭ��ӣ�һ�С���ɽ�ƺ���Ϯ��$n"NOR,
        "force" : 500,
        "dodge" : 50,
        "lvl" : 65,
        "skill_name" : "��ɽ�ƺ�",
        "damage_type" : "����"
]),
([      "action" : MAG"$N���ƻ��˸�ȦȦ�������ɨҶ������ȭ���������$n"NOR,
        "force" : 550,
        "dodge" : 50,
        "lvl" : 70,
        "skill_name" : "���ɨҶ",
        "damage_type" : "����"
]),
([      "action" : YEL"$N�󿪴�ϣ�ʩչ�����ຣ�Ⱥ�����˫ȭײ��$n��ǰ��"NOR,
        "force" : 600,
        "dodge" : 50,
        "lvl" : 80,
        "skill_name" : "�ຣ�Ⱥ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-shenzhang"; }
int valid_learn(object me)
{
	if (!me->query("jiuyin/full") && !me->query("jiuyin/xia") && !me->query("jiuyin/gumu"))
               return notify_fail("�����ڲ���ѧϰ���ħȭ����\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ѧ���ħȭ��������֡�\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
                return notify_fail("��ľ����湦��򲻹����޷�ѧ���ħȭ����\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫�����޷������ħȭ����\n");
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

        level   = (int) me->query_skill("dafumo-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( (int)me->query_skill("dafumo-quan", 1 ) < 150 )
               return notify_fail("�����ڲ�����ϰ���ħȭ����\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ħȭ��������֡�\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������ħȭ����\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
      return __DIR__"dafumo-quan/" + action;
}

int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N����������һ����Ϣ���ң�\n"NOR,ob);
	if ((int)me->query_skill("jiuyin-zhengong", 1) < 200 && damage > 200) damage = 200;
      	ob->add("neili",-random(damage));
	if (ob->query("neili") < 0) ob->set("neili", 0);
        return 0;
}
