// haotian-zhang �����
// By Lgg,1998.10

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$Nʹһ��"+(order[random(13)])+"��������ˮ��"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 100,
        "dodge" : 50,
        "damage": 75,
        "skill_name" : "������ˮ",
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"���������¡�"NOR"����������һ�ӣ�����$n��$l",
        "force" : 120,
        "dodge" : 48,
        "damage": 70,
        "skill_name" : "��������",
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N�����������⣬��������ʹһ��"+(order[random(13)])+"�������沨��"NOR"����$n��$l��ȥ",
        "force" : 140,
        "dodge" : 46,
        "damage": 75,
        "skill_name" : "�����沨",
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��������ת��"NOR"���ֻ�$n���ؿں�$l",
        "force" : 160,
        "dodge" : 44,
        "damage": 70,
        "skill_name" : "������ת",
        "lvl" : 15,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"�����ջ��֡�"NOR"��������ͬʱ�������ڿ���ͻȻ�����Ʒ���
��",
        "force" : 180,
        "dodge" : 42,
        "damage": 85,
        "skill_name" : "���ջ���",
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N���ֲ�ס�ζ�������һ��"+(order[random(13)])+"��������˪��"NOR"����$n��$l��ȥ",
        "force" : 200,
        "dodge" : 40,
        "damage": 80,
        "skill_name" : "������˪",
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N���ֱ���Ϊ�ģ����������絶��һ��"+(order[random(13)])+"��͡�ϰ�ɳ��"NOR"������$n��$l",
        "force" : 220,
        "dodge" : 38,
        "damage": 85,
        "skill_name" : "͡�ϰ�ɳ",
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$N����˺�벽������ʹһ��"+(order[random(13)])+"������һɫ��"NOR"�������$n",
        "force" : 240,
        "dodge" : 36,
        "damage": 80,
        "skill_name" : "����һɫ",
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"������¡�"NOR"�������ȷ������������ƺ󷢶�����",
        "force" : 260,
        "dodge" : 34,
        "damage": 85,
        "skill_name" : "�����",
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ��"+(order[random(13)])+"��������ˮ��"NOR"����
̬����",
        "force" : 280,
        "dodge" : 32,
        "damage": 80,
        "skill_name" : "������ˮ",
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴�����ֻ�������ʹһ��"+(order[random(13)])+"���������ơ�"NOR"����$n��$l��ȥ",
        "force" : 300,
        "dodge" : 30,
        "damage": 86,
        "skill_name" : "��������",
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֱ�����ȭ����ǰ��󻮻���һ��"+(order[random(13)])+"��������ϡ�"NOR"����$n��$l",
        "force" : 320,
        "dodge" : 28,
        "damage": 82,
        "skill_name" : "�������",
        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$N�����黮�����ֱ���Ϊ��һ��"+(order[random(13)])+"��¥����ء�"NOR"����$n��$l",
        "force" : 340,
        "dodge" : 26,
        "damage": 88,
        "skill_name" : "¥�����",
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$Nʩ��"+(order[random(13)])+"�������С�"NOR"����������ӳ�������ͬʱ����$n",
        "force" : 360,
        "dodge" : 24,
        "damage": 174,
        "skill_name" : "������",
        "lvl" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N�ɱ۴��֣�����ǰ����������ʹһ��"+(order[random(13)])+"�����㳤�ɡ�"NOR"������$n��$l",
        "force" : 380,
        "dodge" : 22,
        "damage": 181,
        "skill_name" : "���㳤��",
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N����͵أ�����ʹһ��"+(order[random(13)])+"������ǱԾ��"NOR"�����¶�����$n��$l��ȥ",
        "force" : 400,
        "dodge" : 20,
        "damage": 188,
        "skill_name" : "����ǱԾ",
        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ��"+(order[random(13)])+"���»����ա�"NOR"",
        "force" : 420,
        "dodge" : 18,
        "damage": 198,
        "skill_name" : "�»�����",
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N���Ʋ�ס����ɨ������һʽ"+(order[random(13)])+"����̶�仨��"NOR"��������ת����$n��ȥ",
        "force" : 440,
        "dodge" : 16,
        "damage": 210,
        "skill_name" : "��̶�仨",
        "lvl" : 85,
        "damage_type" : "����"
]),
([      "action" : "$N���־���ǰ��������ǰƲ����ʹһ��"+(order[random(13)])+"����ˮ������"NOR"����$n��$l��ȥ
",
        "force" : 460,
        "dodge" : 14,
        "damage": 220,
        "skill_name" : "��ˮ����",
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+(order[random(13)])+"��б�³�����"NOR"����������������Ȧ�����ƴ�Ȧ�д�������$n
",
        "force" : 480,
        "dodge" : 12,
        "damage": 230,
        "skill_name" : "б�³���",
        "lvl" : 95,
        "damage_type" : "����"
]),
([      "action" : "$N�������ϻ�������������ʹһ��"+(order[random(13)])+"����ʯ���桹"NOR"�����Ʋ�ס�ζ�����
��$nͷ������֮��",
        "force" : 500,
        "dodge" : 10,
        "damage": 250,
        "skill_name" : "��ʯ����",
        "lvl" : 100,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_combine(string combo) { return combo=="qixing-shou"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������Ʊ�����֡�\n");
        if ((int)me->query_skill("xiantian-qigong", 1) < 10)
                return notify_fail("�������������򲻹����޷�ѧ����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("haotian-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ơ�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"haotian-zhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	victim->start_busy(3);
	return HIR"$N̤���ţ���ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;
}
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	ob->start_busy(3);

msg = HIG"$N������λ����ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}