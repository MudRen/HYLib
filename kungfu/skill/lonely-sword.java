//lonely-sword.c ���¾Ž�
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�\n",
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ���������������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�������������ͼ��ʹ$P���С�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n"
        "$n�������ܣ��ٽ������ʹ�������両�ࡹ����$P��$l���뵲������С�\n",
        "$nͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�\n"
        "$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
        "ֻ��$n���˷���������Ʈ�磬�����һʽ�������������������޶�����׽���ص�ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�������롹��ɭɭ�����������ܣ��ܿ���$P������\n",
});

mapping *action = ({
        ([      "name":                 "�ܾ�ʽ",
                "action":               "$Nʹһ�С��ܾ�ʽ��������$w���Ⱪ������$n��$l��ȥ",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�ƽ�ʽ",
                "action":               "$N����һָ��һ�С��ƽ�ʽ��бб����$n��$l",
                "dodge":                100,
                "damage":               400,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�Ƶ�ʽ",
                "action":               "$N����$wһ�С��Ƶ�ʽ�������벻���ķ�λ����$n��$l",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��ǹʽ",
                "action":               "$N����һ�Σ�����$w����һ����ʹ������ǹʽ����$n��$l��������",
                "dodge":                70,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�Ʊ�ʽ",
                "action":               "$N����$w���Ⱪ����һ�С��Ʊ�ʽ����$n$l��ȥ",
                "dodge":                60,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����ʽ",
                "action":               "$N����$w����������һ�С�����ʽ��ֱָ$n$l",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����ʽ",
                "action":               "$NͻȻ����һ�ף�����$w�����´�����һ�С�����ʽ���ó�һ���⻡ֱ��$n$l��ȥ",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�Ƽ�ʽ",
                "action":               "$Nһ�С��Ƽ�ʽ������$w���϶��£�����ба�ش���$n��$l",
                "dodge":                30,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "name":                 "����ʽ",
                "action":               "$N��̤������������$w�й�ֱ����һ�С�����ʽ��Ѹ���ޱȵ���$n��$l��ȥ",
                "dodge":                20,
                "damage":               350,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "��ɽ��"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("���¾Ž�ֻ�����������ǰ��ѧϰ��\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����¾Ž���\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("���¾Ž����������ϼ�񹦲�����ϰ��\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
        return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}

