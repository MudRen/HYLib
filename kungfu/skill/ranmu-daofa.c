#include <ansi.h>

inherit SKILL;
 
mapping *action = ({
([      "action" : "$N���΢Ц��һ�С��һ���������$w����$n�����˰˰���ʮ�ĵ��������ݺᣬѸ�ײ��ɵ�",
        "dodge" : 1,
        "attack": 31,
        "force" : 331,
        "damage": 394,
        "parry" : 2,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N���쳤Ц��ʩչ��һ�С������ԭ������ʱ�ó�����$wͬʱն��$n",
        "dodge" : 12,
        "attack": 37,
        "force" : 363,
        "damage": 351,
        "parry" : 3,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$N�����Ծ��Խ��$nͷ����һ�С�������ġ�������$wֱ�����£�ն��$n$l",
        "dodge" : 9,
        "attack": 31,
        "force" : 351,
        "damage": 389,
        "parry" : 4,
        "lvl"   : 100,
        "damage_type": "����"
]),
([      "action" : "$N�����ڹ�һ�С���ľ���𡹣�$w�ϴ����ޱȾ���������һ���󻡣����϶�������$n��$l",
        "dodge" : 16,
        "attack": 28,
        "force" : 342,
        "damage": 307,
        "parry" : 7,
        "lvl"   : 120,
        "damage_type": "����"
]),
([      "action": "$N�ֱ�һ����һ�С��Ź����¡���˫�ֳ�$w����һ��ѩ�����⣬�����������У�����$n��$l",
        "dodge" : 11,
        "attack": 33,
        "force" : 363,
        "damage": 309,
        "parry" : 9,
        "lvl"   : 140,
        "damage_type": "����"
]),
([      "action": "$N����$w�������ã����ҿ���ʹ��һ�С��һ����ơ����������󵶷磬��������$n",
        "dodge" : 17,
        "attack": 31,
        "force" : 389,
        "damage": 337,
        "parry" : 13,
        "lvl"   : 160,
        "damage_type": "����"
]),
([      "action": "$Nһ�С�����ȡ���������Ծ����أ�����$w������ǰ��Ю�����ȵķ�������$n��$l",
        "dodge" : 13,
        "attack": 41,
        "force" : 323,
        "damage": 361,
        "parry" : 4,
        "lvl"   : 180,
        "damage_type": "����"
]),
([      "action": "$N�ڿն��𣬰����һ�С���ʯ��١�������$w�ӳ����������ĵ�Ӱ����$n��ȫ���ȥ",
        "dodge" : 11,
        "attack": 34,
        "force" : 302,
        "damage": 389,
        "parry" : 7,
        "lvl"   : 200,
        "damage_type": "����"
]),
});


int valid_enable(string usage) { return  (usage =="parry")|| (usage =="blade"); }

int valid_learn(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("���������һ�ѵ�������ȼľ������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("����������㣬û�а취��ȼľ����������Щ���������ɡ�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ����̫ǳ��û�а취��ȼľ������\n");

        if ((int)me->query_skill("blade", 1) < 100)
                return notify_fail("��Ļ����������̫ǳ��û�а취��ȼľ������\n");
         if((int)me->query_skill("xiuluo-dao",1) <120)
      		return notify_fail("������޵�����㣬��������ȼľ������\n");

         if((int)me->query_skill("jingang-quan",1) <120)
      		return notify_fail("��Ĵ���ȭ���㣬��������ȼľ������\n");

         if((int)me->query_skill("banruo-zhang",1) <120)
      		return notify_fail("��İ����Ʋ��㣬��������ȼľ������\n");
        if ((int)me->query_skill("blade", 1)+100 < (int)me->query_skill("ranmu-daofa", 1))
                return notify_fail("��Ļ�������ˮƽ���������޷����������ȼľ������\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");


        return 1;
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
        level = (int) me->query_skill("ranmu-daofa", 1);

        if (random(me->query_skill("ranmu-daofa", 1)) > 120 &&
             me->query_skill("force") > 100 &&
             me->query("neili") > 1000 &&
             random(10) > 6)
        {
                me->add("neili", -20);
                return ([
                "action": HIR "$N" HIR "��Ȼ����һ����ţ����弱��"
                          "��ת������ͨ�죬���Ĺ���ɲ�Ǽ�����" + 
                          me->query_temp("weapon")->query("name")
                          + HIR "һ�������������\n��һ�����ȵ�������"
                          "Ϯ��$n" HIR "��" NOR,
                "dodge" : 11,
                "attack": 66,
                "force" : 699,
                "damage": 699,
                "parry" : 7,
                "damage_type": "����"]);
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("�������������ȼľ������\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("�������������ȼľ������\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");
         if((int)me->query_skill("xiuluo-dao",1) <120)
      		return notify_fail("������޵�����㣬��������ȼľ������\n");

         if((int)me->query_skill("jingang-quan",1) <120)
      		return notify_fail("��Ĵ���ȭ���㣬��������ȼľ������\n");

         if((int)me->query_skill("banruo-zhang",1) <120)
      		return notify_fail("��İ����Ʋ��㣬��������ȼľ������\n");

        me->receive_damage("qi", 75);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ranmu-daofa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("ranmu-daofa",1)) > 100 ) 
{
	  victim->receive_wound("qi", (damage_bonus)/2);
        return HIM "$n������ɨ�У��о��˿�����������\n" NOR;
}
}
