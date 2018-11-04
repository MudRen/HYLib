#include <ansi.h>

inherit SKILL;

int valid_learn(object me)
{
        object ob;
  
        if (me->query_skill("throwing", 1) < 40)
                return notify_fail("��İ������ܲ�����졣\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("pidi-shenzhen", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ�������������ıٵ����롣\n");

        return 1;
}

string	*msg = ({
"$N������࣬һʽ������̤����������$w�������·�ͻȻ˦����ֱ����$n��$l",
"$w�ƿշɳ���һʽ�����羭�졹������һ�����ߣ��������ң�����$n��$l��",
"$N˫�����һʽ�����Ƽ��ա�������$w��$n����������$n��ȫ������",
"$N�����һ����ȴ��$nһ�С�������Ҷ����ʮ��ö$w�ɿ��л�������",
"$N���μ�����ǰ������һʽ��ѩ��׷�١�����ö$w��$n��в����ȥ",
"$Nһʽ�����ײ�ɣ��������һת������������ö$w������$n�ı���",
"$N���һ�ݣ�һ�С����Ƽ�����Ӹ����£�����$w���䣬ֱ��$n��$l",
"$Nһ�С����ǵ���������ָ������ö$w��һ��ڹ�����$n��ͷ��",
});

int valid_enable(string usage)
{
	return usage == "throwing" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("pidi-shenzhen",1)),
		"damage_type":"����",
		"dodge":random(20)+20,
          "force":random(150)+me->query_skill("pidi-shenzhen",1),
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("�����������û�а취��ϰ�ٵ����롣\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������������û�а취��ϰ�ٵ����롣\n");

        me->receive_damage("qi", 70);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"pidi-shenzhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("pidi-shenzhen",1);
        level2= (int) me->query_skill("pidi-shenzhen",1);


if (random(6)==0 && level>=100 )
{
        victim->receive_damage("qi",level*2+100);
        victim->receive_wound("qi",level*3+100);
	return HIB"$N˫������,�����ö����,$n˫��һ�ڣ��ؿ�����һö!\n"NOR;
}
}