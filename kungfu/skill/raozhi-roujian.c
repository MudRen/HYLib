// raozhi-roujian.c �䵱��ָ�ὣ
#include <ansi.h>
inherit SKILL;
string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$Nʹ��һ�С��������ǡ�������$w��һ�����߰����$n��$l",
        "force"  : 120,
        "dodge"  : 20,
        "parry"  : 114,
        "damage" : 25,
        "lvl"    : 0,
        "damage_type": "����"
]),
([      "action" : "$Nһʽ���仨���졹������$w�������콣Ӱֱ����$n��$l",
        "force"  : 120,
        "dodge"  : 20,
        "parry"  : 115,
        "damage" : 20,
        "lvl"    : 10,
        "damage_type": "����"
]),
([      "action" : "$Nʹ��һ�С��������¡�������$w���裬�����������Ȧ��$n��$l",
        "force"  : 140,
        "dodge"  : 15,
        "parry"  : 116,
        "damage" : 25,
        "lvl"    : 20,
        "damage_type": "����"
]),
([      "action" : "$N����һԾ��һ�С��˷��ȥ����ȴ��ת��֮�ʶ�׼$n$lбб�ӳ�һ��",
        "force"  : 150,
        "dodge"  : 15,
        "parry"  : 118,
        "damage" : 35,
        "lvl"    : 30,
        "damage_type": "����"
]),
([      "action" : "$N��̬���У�����$wƾ��һָ��һ�С�����ǧ�ء�����ػ���$n��$l",
        "force"  : 130,
        "dodge"  : 25,
        "parry"  : 121,
        "damage" : 25,
        "lvl"    : 40,
        "damage_type": "����"
]),
([      "action" : "$Nʹ��һ�С��Ǻ�Ӱ������������˸�������������޵ش���$n$l",
        "force"  : 120,
        "dodge"  : 25,
        "parry"  : 212,
        "damage" : 25,
        "lvl"    : 50,
        "damage_type": "����"
]),
([      "action" : "$N����$w����һ�֣�һ�С��������������ֶ�׼$n$lһ����ȥ",
        "force"  : 110,
        "dodge"  : 15,
        "parry"  : 135,
        "damage" : 38,
        "lvl"    : 60,
        "damage_type": "����"
]),
([      "action" : "$N����ת����ͣ��ͻȻһ�С�һ����Ϭ��ʹ��������$w����һ������������$n$l",
        "force"  : 150,
        "dodge"  : 35,
        "parry" :  145,
        "damage" : 43,
        "lvl"    : 70,
        "damage_type": "����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");
         if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("��ı����ڹ����̫ǳ��\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");


        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("raozhi-roujian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ָ�ὣ��\n");

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 90 ) return 0;

        if( random(4)==0 ) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus ) / 2 );
                return HIR "$nͻȻ�����˿�һ������Ѫ�����\n";
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N �籧̫����һ���ۻ��ޱȵ����������һ����������\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"������ ��̫���񹦽������� �������Լ����� ��\n"NOR;
//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}       
}
string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("raozhi-roujian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];

}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query_skill("taiji-shengong", 1) < 100)
                return notify_fail("��ı����ڹ����̫ǳ��\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("���������������ָ�ὣ��\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("���������������ָ�ὣ��\n");

        me->receive_damage("qi", 35);
        me->add("neili", -30);

        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"raozhi-roujian/" + action;
}
