// kongming.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹ�����ա��־�����ȭ������ȭʽ�������ޣ��ƺ�������������ȴ�־�ֱϮ��$n",
	"force" : 100,
	"dodge" : 15,
	"parry" : 1,
	"damage" : 300,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־���ȭ�к����Ϳ�����Ʋ����·�����ȭ��ȴֱָ$n��$l",
	"force" : 120,
	"dodge" : 12,
	"parry" : 2,
	"damage" : 300,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־�����ȭ�ƺ��ɶ��д�����������������ʽȴ���ͱ��ˣ��ݺݵػ���$n",
	"force" : 140,
	"dodge" : 13,
	"parry" : 12,
	"damage" : 300,
	"lvl" : 6,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����ɡ��־�����ȭ����������������ػ�������ƮƮ�ػ���$n��$l",
	"force" : 160,
	"dodge" : 15,
	"parry" : 11,
	"damage" : 300,
	"lvl" : 12,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����硹�־�����ȭ����������һ����磬$n�վ������壬ȭ�о���Ϯ������ǰ",
	"force" : 180,
	"dodge" : 13,
	"parry" : 12,
	"damage" : 300,
	"lvl" : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ͨ���־���ȭ���۶���ɢ�����д�֮ͨ�Σ�ֱ��$n��$l",
	"force" : 200,
	"dodge" : 15,
	"parry" : 13,
	"damage" : 300,
	"lvl" : 28,
	"skill_name" : "ͨ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����ݡ��־���ȭ�߿�����������ݣ�����ʵ�أ�������$n���ض�ȥ",
	"force" : 220,
	"dodge" : 11,
	"parry" : 11,
	"damage" : 300,
	"lvl" : 35,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����Ρ��־���ȭ�����Σ����ڰ��ΰ��ѣ�$nһʱ��ڣ�ȭ����Ȼ����",
	"force" : 250,
	"dodge" : 14,
	"parry" : 11,
	"damage" : 300,
	"lvl" : 40,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����塹�־�����ȭֱ����ȭʽ�������ᣬ��$n��$l��ȥ",
	"force" : 280,
	"dodge" : 13,
	"parry" : 12,
	"damage" : 300,
	"lvl" : 46,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ������־��������ʵ�֮�Σ�ȭ����Ȼ�Գ���;ĩ·��ȴ����ɱ������$n��������ʩ��ȭ",
	"force" : 310,
	"dodge" : 13,
	"parry" : 10,
	"damage" : 300,
	"lvl" : 53,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����С��־�����ȭ������������ƫ���У�����ָ�����У�ȭ��ȴ��$n��������ס",
	"force" : 340,
	"dodge" : 13,
	"parry" : 14,
	"damage" : 300,
	"lvl" : 59,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����Ū���־���ȭ�ж�Ȼ���Σ�������Ū$n��ȴ�ְ�������",
	"force" : 370,
	"dodge" : 11,
	"parry" : 13,
	"damage" : 300,
	"lvl" : 65,
	"skill_name" : "Ū�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ͯ���־�����ȭ����ͯ������·������һ���$n��$l",
	"force" : 400,
	"dodge" : 13,
	"parry" : 14,
	"damage" : 300,
	"lvl" : 72,
	"skill_name" : "ͯ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ӹ���־�����ȭ����ʱ����򵥵���ʽ��ƽƽ���棬����ȴ��ס��$n����·",
	"force" : 440,
	"dodge" : 13,
	"parry" : 12,
	"damage" : 300,
	"lvl" : 78,
	"skill_name" : "ӹ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־������������繭��ȭ���Ƽ���Ѹ�ݵ�Ϯ��$n",
	"force" : 480,
	"dodge" : 15,
	"parry" : 12,
	"damage" : 300,
	"lvl" : 85,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����桹�־�������������棬ȭ��Ҳ�����䶯��$n���޷��ж���һȭ������",
	"force" : 530,
	"dodge" : 8,
	"parry" : 11,
	"damage" : 400,
	"lvl" : 95,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
    ([  "action":       "$Nʹһ�С�"+HIB+"����ס��"+NOR+"����˫����ƮƮ�ع���$n$l",
        "force": 380,
	"dodge" : 8,
	"parry" : 11,
        "damage" : 300,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һƽ,����һ��,һ�С�"+HIB+"����ʢ��"+NOR+"��ֱ��$n��$l",
        "force": 320,
	"dodge" : 8,
	"parry" : 11,
        "damage" : 400,
        "damage_type": "����"
    ]),
    ([  "action":       "$N������$nһת��˫������,һ�С�"+HIB+"�ղ�װˮ"+NOR+"������$n$l",
        "force": 360,
	"dodge" : 8,
	"parry" : 11,
        "damage" : 400,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һ��,����һ��,һ�С�"+HIB+"�黳����"+NOR+"������$n��$l",
        "force": 430,
	"dodge" : 8,
	"parry" : 11,
        "damage" : 400,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nʹһ�С�"+HIB+"��ɽ����"+NOR+"����$n��$l��Χ��$N��������Ӱ֮��",
        "force": 340,
	"dodge" : 8,
	"parry" : 11,
        "damage" : 400,
        "damage_type": "����"
    ]),
    ([  "action":       "$N��ɫһ����ʹ����"+HIB+"���Ŀ���"+NOR+"����Χ��$n��$l��������",
        "damage" : 400,
	"dodge" : 8,
	"parry" : 11,
        "force": 480,
        "damage_type": "����"
    ]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("max_neili") < 150)
        return notify_fail("�������̫�����޷�������ȭ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("kongming-quan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-jian", 1) < 80 )
                return notify_fail("������ǽ�����򲻵����޷�ѧϰ����ȭ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-shou", 1) < 80 )
                return notify_fail("������Ƿ����ֻ�򲻵����޷�ѧϰ����ȭ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("haotian-zhang", 1) < 80 )
                return notify_fail("�������ƻ�򲻵����޷�ѧϰ����ȭ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("jinyan-gong", 1) < 80 )
                return notify_fail("��Ľ��㹦��򲻵����޷�ѧϰ����ȭ��\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level   = (int) me->query_skill("kongming-quan",1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = level/5;
    a_action["attack"]  = level;
    a_action["force"]  = level;
    a_action["damage"] = 2*level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-jian", 1) < 80 )
                return notify_fail("������ǽ�����򲻵����޷�ѧϰȫ�潣����\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("qixing-shou", 1) < 80 )
                return notify_fail("������Ƿ����ֻ�򲻵����޷�ѧϰȫ�潣����\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("haotian-zhang", 1) < 80 )
                return notify_fail("�������ƻ�򲻵����޷�ѧϰȫ�潣����\n");

        if ((int)me->query_skill("xiantian-qigong", 1) >  1 &&
            (int)me->query_skill("jinyan-gong", 1) < 80 )
                return notify_fail("��Ľ��㹦��򲻵����޷�ѧϰȫ�潣����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}

int ob_hit(object ob, object me, int damage)
{
	        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        string dodge_skill,*limbs;
        int i,   q;
        
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);
        weapon = me->query_temp("weapon");
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
	

        limbs = ob->query("limbs");
        level = me->query_skill("kongming-quan", 1);
level2 = me->query_skill("kongming-quan", 1);

        if (  level2 > 100
        && random(3)==1){
             msg = HIY"$N����ʵʵ���仯Ī�⣬��$nһʱ���Բ�׽!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
               }

}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	victim->start_busy(3);
	return HIR"$N̤���ţ���ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("kongming-quan",1);             
	if (random(3)==1 && me->query_skill("kongming-quan",1)>100)
	{
	if( damage_bonus > 20 && random(level2)>80) {
	victim->receive_wound("qi", (random(damage_bonus)+150));
	return HIY"$n��һȭ����Ҫ������ʱŻ��һ�����Ѫ��\n"NOR;
        }
}
}




string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}