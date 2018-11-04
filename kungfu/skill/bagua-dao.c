// bagua-dao.c ���Ե�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N��̤���Է�λ������פ�أ�һ�С�����������������$w����������$n��ȥ",
        "force"  : 125,
        "attack" : 15,
        "dodge"  : 56,
        "parry"  : 52,
        "lvl"    : 0,
        "damage" : 19,
        "skill_name" : "��������",
        "damage_type" : "����",
]),
([      "action" : "$Nʹ�����ϲ���ɽ�����������էȻһ�������ּ��ٲ�ס$n���֣�����$w������$n��$l",
        "force"  : 153,
        "attack" : 32,
        "dodge"  : 70,
        "parry"  : 75,
        "lvl"    : 20,
        "damage" : 27,
        "skill_name" : "�ϲ���ɽ",
        "damage_type" : "����",
]),
([      "action" : "$N��̤���Է�λ����ת���⣬һ�С�������ɽ��������$w��Ȼ�õ�������$n����ǰ",
        "force"  : 198,
        "attack" : 45,
        "dodge"  : 67,
        "parry"  : 87,
        "lvl"    : 40,
        "damage" : 34,
        "skill_name" : "������ɽ",
        "damage_type" : "����",
]),
([      "action" : "$N����̤��������Ե�ͼʽ��������ת�������Ķ���һʽ����ţ���ء���$w������б����$n��ȥ",
        "force"  : 220,
        "attack" : 48,
        "dodge"  : 75,
        "parry"  : 91,
        "lvl"    : 60,
        "damage" : 49,
        "skill_name" : "��ţ����",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������������������㣬$wһ��һ�գ�����һ����ƽʮ�֣�����$n�ľ���",
        "force"  : 231,
        "attack" : 55,
        "dodge"  : 73,
        "parry"  : 96,
        "lvl"    : 80,
        "damage" : 58,
        "skill_name" : "������",
        "damage_type" : "����",
]),
([      "action" : "$Nһ���������ᵶ�棬$w�����ˡ����죬һ�С������š������϶���ֱ��$n��ͷ��",
        "force"  : 257,
        "attack" : 59,
        "dodge"  : 73,
        "parry"  : 95,
        "lvl"    : 100,
        "damage" : 66,
        "skill_name" : "������",
        "damage_type" : "����",
]),
([      "action" : "$Nʹ���������š������ֺ󳷣���б���мܣ�˳���¶磬���ⲻָͣ��$n��$l",
        "force"  : 253,
        "attack" : 60,
        "dodge"  : 85,
        "parry"  : 105,
        "lvl"    : 120,
        "damage" : 63,
        "skill_name" : "������",
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����������ɽ���������䣬����Ʈ������$n�ۻ�����֮�ʣ�ͻȻ���ֵ��ⷴ����$n��$l",
        "force"  : 283,
        "attack" : 63,
        "dodge"  : 87,
        "parry"  : 118,
        "lvl"    : 140,
        "damage" : 69,
        "skill_name" : "������ɽ",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С����Ʊ�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "force"  : 268,
        "attack" : 66,
        "dodge"  : 88,
        "parry"  : 124,
        "lvl"    : 160,
        "damage" : 73,
        "skill_name" : "���Ʊ���",
        "damage_type" : "����",
]),
([      "action" : "$N�ص����գ�һ�С������õ������������¶��ϻ��˸��뻡����$n��$l��ȥ��\n"
                   "$nֻ����ǰһƬ�����ĵ�Ӱ�����Լ�ȫ��ӿȥ���˺����ܣ��־�һ����ֱ�ƹ���",
        "force"  : 272,
        "attack" : 67,
        "dodge"  : 94,
        "parry"  : 133,
        "lvl"    : 180,
        "damage" : 82,
        "skill_name" : "�����õ�",
        "damage_type" : "����",
]),
([      "action" : "$N���ʹһ�С����԰��󡹣���ʱ�����������䵶��������˷�ӿ��$nȫ��",
        "force"  : 280,
        "attack" : 72,
        "dodge"  : 96,
        "parry"  : 132,
        "lvl"    : 200,
        "damage" : 85,
        "skill_name" : "���԰���",
        "damage_type" : "����",
]),
});

int valid_enable(string usage)
{
        return usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ��ǳ���޷���ϰ���Ե�����\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("bagua-zhang") < 150)
                return notify_fail("��İ����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("yanxing-dao") < 150)
                return notify_fail("������е����̫ǳ��\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

        if ((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���ϰ���Ե�����\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("bagua-dao", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������İ��Ե�����\n");

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
        int i, level, tiandao;

        level = (int)me->query_skill("bagua-dao", 1);
        tiandao = me->query_temp("pfm_tiandao");

        switch (tiandao)
        {
        case 1:
                return ([ "action": WHT "$N" WHT "ʩ����" HIY "�쵶����" NOR +
                                    WHT "��������" HIY "��Ǭ��" NOR + WHT "��"
                                    "�������е�$w" WHT "����һ�������׼$n" WHT
                                    "ֱ������",
                           "force"  : 280,
                           "damage" : 385,
                           "attack" : 65,
                           "dodge"  : 96,
                           "parry"  : 132,
                           "damage_type" : "����",
                        ]);
                break;
        case 2:
                return ([ "action": WHT "$N" WHT "����һת��һ��" HIY "������"
                                    NOR + WHT "�־�����ʩ��������$w" WHT "��ʱ"
                                    "����һ������â����$n" WHT "ȫ��",
                           "force"  : 220,
                           "damage" : 387,
                           "attack" : 63,
                           "dodge"  : 96,
                           "parry"  : 112,
                           "damage_type" : "����",
                        ]);
                break;
        case 3:
                return ([ "action": WHT "$N" WHT "��������һ������ʩһ��" HIY
                                    "���㡻" NOR + WHT "�־�ʩ��������$w" WHT
                                    "˳�Ʒ���һ������$n" WHT "��ն��",
                           "force"  : 230,
                           "damage" : 383,
                           "attack" : 61,
                           "dodge"  : 93,
                           "parry"  : 107,
                           "damage_type" : "����",
                        ]);
                break;
        case 4:
                return ([ "action": WHT "$N" WHT "����Ȼ�ӿ죬����$w" WHT "��"
                                    "��" HIY "����" NOR + WHT "�־���λն����"
                                    "������âֱ����$n" WHT "Ҫ������",
                           "force"  : 220,
                           "damage" : 387,
                           "attack" : 63,
                           "dodge"  : 96,
                           "parry"  : 112,
                           "damage_type" : "����",
                        ]);
                break;
        case 5:
                return ([ "action": WHT "����$N" WHT "һ����̾�����հ��Է�λʩ"
                                    "��" HIY "������" NOR + WHT "�־���$w" WHT
                                    "�����ʱ�ų����������$n" WHT,
                           "force"  : 223,
                           "damage" : 381,
                           "attack" : 67,
                           "dodge"  : 99,
                           "parry"  : 103,
                           "damage_type" : "����",
                        ]);
                break;
        case 6:
                return ([ "action": WHT "$N" WHT "����һԾ�������ʩһʽ" HIY
                                    "���ҡ�" NOR + WHT "�־�����ʱ����˸˸����"
                                    "ǧ���$w" WHT "������$n" WHT,
                           "force"  : 210,
                           "damage" : 385,
                           "attack" : 65,
                           "dodge"  : 96,
                           "parry"  : 132,
                           "damage_type" : "����",
                        ]);
                break;
        case 7:
                return ([ "action": WHT "$N" WHT "������ʩչ��" HIY "���롻" NOR +
                                    WHT "�־���$w" WHT "����������ף�Я�ź�Х"
                                    "�ƿ�֮��ֱ����$n" WHT "��ȥ",
                           "force"  : 253,
                           "damage" : 363,
                           "attack" : 52,
                           "dodge"  : 97,
                           "parry"  : 88,
                           "damage_type" : "����",
                        ]);
                break;
        case 8:
                return ([ "action": WHT "���$N" WHT "һ����Ц��ʩ����" HIY "��"
                                    "������" WHT "������" HIY "���ޡ�" NOR + WHT
                                    "�־���ֻ��$w" WHT "һ��������$n" WHT "��ǰ",
                           "force"  : 197,
                           "damage" : 389,
                           "attack" : 58,
                           "dodge"  : 103,
                           "parry"  : 142,
                           "damage_type" : "����",
                        ]);
                break;
        default:
                for(i = sizeof(action); i > 0; i--)
                        if(level > action[i-1]["lvl"])
                                return action[NewRandom(i, 20, level / 5)];
                break;
        }
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("bagua-zhang") < 150)
                return notify_fail("��İ����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("yanxing-dao") < 150)
                return notify_fail("������е����̫ǳ��\n");


        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("������������������˰��Ե�����\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("������������������˰��Ե�����\n");

        me->receive_damage("qi", 55);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bagua-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 90 ) return 0;

        if( random(2)==0 && me->query_temp("pfm_tiandao")) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 40) / 2 );
                return HIR "$n���˿ڱ�$N���紩�����ɳ�һ��Ѫ����\n";
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
} 
}