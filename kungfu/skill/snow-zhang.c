// snow-zhang.c
#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
    ([  "action":       "$Nһ��"+(order[random(13)])+"��÷��С�á�"NOR"��˫�ֻ�������,��ƮƮ�ص���$n$l", 
        "parry": 10,
        "force": 40,
        "damage": 140,
        "damage_type": "����"
        ]),
    ([  "action":       "$N��ȭƽ��,��ȭ���»��˸��뻡,һ��"+(order[random(13)])+"��÷�޺��ӡ�"NOR",��ȡ$n��$l",
        "dodge": 10,
        "force": 50,
        "damage": 140,
        "damage_type": "����"
    ]),
    ([  "action":     "$Nһ��"+(order[random(13)])+"����ѩ��÷��"NOR",˫������о���,�������ǰ�����$n$l",
        "dodge": 10,
        "force": 60,
        "parry": 5,
        "damage": 140,
        "damage_type": "����"
        ]),
    ([  "action":       "$N����һ��"+(order[random(13)])+"��˪ѩ���졹"NOR",ɢ��ɭɭ����,����$n��$l",
        "dodge": 20,
        "parry": 10,
        "force": 80,
        "damage": 140,
        "damage_type": "����"
        ]),
    ([  "action":       "$Nʹһ��"+(order[random(13)])+"����ѩ��÷��"NOR"��������ת,��������$n$l",
        "dodge": 10,
        "parry": 20,
        "force": 100,
        "damage": 240,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һЦ,�������,һʽ"+(order[random(13)])+"������Ʈ÷��"NOR"��Χ��$n��$l��ƮƮ��������",
        "dodge":  10,
        "force": 140,
        "damage": 340,
        "damage_type": "����"
    ]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ѩӳ÷�Ʊ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���ϰ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 10);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"snow-zhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if ( me->query("family/family_name")== "������" && me->query_skill("bingxue-xinfa",1)>40) {
if (random(5)>3 && random(me->query_skill("bingxue-xinfa",1))>100)
{
            victim->apply_condition("cold_poison", (me->query_skill("bingxue-xinfa"))/10 +
			victim->query_condition("cold_poison"));
        victim->receive_wound("qi", (damage_bonus - 30) / 2 );
        return HIW "$nֻ�����˿�һ��,һ�ɺ����Ʊ���һ���Ĵ���$n��ȫ��\n" NOR;
}
}
} int ob_hit(object ob, object me, int damage)
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
msg = HIB "$N" HIB "�����Ѫ�ķ�!! ȫ����˿�һ˲��ֹס����Ѫ��\n" NOR;
msg += HIB "һ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$n������\n" NOR;
ob->apply_condition("xscold_poison",12);

           message_vision(msg, me, ob);
           return j;
}       
}     