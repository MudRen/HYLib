#include <ansi.h>

inherit SKILL;

mapping *action = ({
([   "action" : "$N��¶΢Ц��һ�С����ر�����������$wһ�������Ⱪ��������$n��$l",
     "force"  : 150,
     "attack" : 15,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 110,
     "lvl"    : 0,
     "skill_name" : "���ر���",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��²���ɽ��������ͻ�������ж��䣬����$w�Ӻ�б����$n��$l",
     "force"  : 170,
     "attack" : 25,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 115,
     "lvl"    : 10,
     "skill_name" : "�²���ɽ",
     "damage_type":  "����"
]),
([   "action" : "$N�������ߣ�һ�С�������ɽ�������׸������������$w��Ȼ���ϣ�����$n��$l",
     "force"  : 175,
     "attack" : 33,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 120,
     "lvl"    : 20,
     "skill_name" : "������ɽ",
     "damage_type":  "����"
]),
([   "action" : "$N����һ�Σ����Ӷ��ϣ�ʹһ�С����ﳯ����������$w����һ������׼$n��������",
     "force"  : 190,
     "attack" : 39,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 125,
     "lvl"    : 30,
     "skill_name" : "���ﳯ��",
     "damage_type":  "����"
]),
([   "action" : "$N����һչ��ʩչ����������Ū���ὣ������Ӱ���棬����$w����$n��$l��ȥ",
     "force"  : 100,
     "attack" : 43,
     "dodge"  : 60,
     "parry"  : 40,
     "damage" : 29,
     "lvl"    : 40,
     "skill_name" : "������Ū���ὣ",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С���������֦���ϡ���������ӣ�����$w����б������ֱָ$n��$l",
     "force"  : 130,
     "attack" : 51,
     "dodge"  : 50,
     "parry"  : 45,
     "damage" : 36,
     "lvl"    : 50,
     "skill_name" : "��������֦����",
     "damage_type":  "����"
]),
([   "action" : "$N΢΢һ��ת��һ�С��ս����ٻӱޡ�������$wȴ�������´���������$n��$l",
     "force"  : 150,
     "attack" : 62,
     "dodge"  : 40,
     "parry"  : 47,
     "damage" : 243,
     "lvl"    : 60,
     "skill_name" : "�ս����ٻӱ�",
     "damage_type":  "����"
]),
([   "action" : "$N��ɫ΢�䣬һ�С������ֽ�ָ���ء������ж�ʱ��������ޱȣ�����$w���������$n",
     "force"  : 180,
     "attack" : 71,
     "dodge"  : 30,
     "parry"  : 52,
     "damage" : 51,
     "lvl"    : 80,
     "skill_name" : "�����ֽ�ָ����",
     "damage_type":  "����"
]),
([   "action" : "$N�������ף�����һ�С�ϴ�����б��¡�������$w�й�ֱ����Ѹ���ޱȵ���$n��ȥ",
     "force"  : 200,
     "attack" : 85,
     "dodge"  : 20,
     "parry"  : 54,
     "damage" : 258,
     "lvl"    : 100,
     "skill_name" : "ϴ�����б���",
     "damage_type":  "����"
]),
([   "action" : "$N�ݲ����ߣ������͵�����$n���䣬$n��Ҫ����ط���ֻ��ɲ�Ǽ佣��һ����$N\n"
                "һ�С�ӭ���ȷ�����ɽ����$w�Ѿ���������",
     "force"  : 220,
     "attack" : 88,
     "dodge"  : 30,
     "parry"  : 62,
     "damage" : 67,
     "lvl"    : 120,
     "skill_name" : "ӭ���ȷ�����ɽ",
     "damage_type":  "����"
]),
([   "action" : "$N����ಽ��һ�С�������´��ʡ�������$w���ּ�����������ৡ���һ����$n��ȥ",
     "force"  : 240,
     "attack" : 91,
     "dodge"  : 65,
     "parry"  : 65,
     "damage" : 375,
     "lvl"    : 140,
     "skill_name" : "������´���",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С�����ת�����롹����ؼ���һ�����ֳ�ǰ����������$w��Ϊһ�������Ļ���\n"
                "��$n��$l��ȥ",
     "force"  : 265,
     "attack" : 93,
     "dodge"  : 40,
     "parry"  : 68,
     "damage" : 382,
     "lvl"    : 160,
     "skill_name" : "����ת������",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��ϲ��Ʊ�ժ�¡�������Ծ�𣬲�����Ӱ������ȴ�ִӰ���д��£�˫�ֽ�������\n"
                "$w�����Ʊ��˵ش���$n��$l",
     "force"  : 290,
     "attack" : 97,
     "dodge"  : 60,
     "parry"  : 72,
     "damage" : 388,
     "lvl"    : 180,
     "skill_name" : "�ϲ��Ʊ�ժ��",
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С����ý��׺���᡹������$w���͡���һ��б������գ��漴���¡��ৡ���\n"
                "�£�����һ�����֣���$n��$l��ȥ",
     "force"  : 310,
     "attack" : 109,
     "dodge"  : 45,
     "parry"  : 75,
     "damage" : 396,
     "lvl"    : 200,
     "skill_name" : "���ý��׺����",
     "damage_type":  "����"
]),
([   "action" : "$N����΢̧��һ�С����������ر��������������������$w�͵����·����𣬼�����\n"
                "�ɾ��練��$n��$l",
     "force"  : 330,
     "attack" : 115,
     "dodge"  : 50,
     "parry"  : 82,
     "damage" : 305,
     "lvl"    : 220,
     "skill_name" : "���������ر���",
     "damage_type":  "����"
]),
});

string main_skill() { return "daojian-guizhen"; }

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{



        if ((int)me->query("max_neili") < 1300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ��ҽ�����\n");

        if ((int)me->query_skill("sixiang-bufa", 1) < 120)
                return notify_fail("������󲽷���򲻹����޷�ѧϰ��ҽ�����\n");

        if ((int)me->query_skill("tianchang-strike", 1) < 120)
                return notify_fail("����쳥�Ʒ���򲻹����޷�ѧϰ��ҽ�����\n");

        if ((int)me->query_skill("hujia-quan", 1) < 120)
                return notify_fail("��ĺ���ȭ����򲻹����޷�ѧϰ��ҽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("miaojia-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ҽ�����\n");

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
        level   = (int) me->query_skill("miaojia-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if ((int)me->query_skill("daojian-guizhen", 1))
                return notify_fail("���Ѿ�����ҽ����ͺ��ҵ������ߺ�һ�ˡ�\n");

        if ( ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("�������Ŀǰû�а취��ϰ��ҽ�����\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������޷���ϰ��ҽ�����\n");
        
        me->add("qi", -53);
        me->add("neili", -84);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"miaojia-jian/" + action;
}
