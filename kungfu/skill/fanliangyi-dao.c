// fanliangyi-dao.c �����ǵ���

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$wбָ��һ�С�����һ�ơ�������һ�٣�һ����$n��$l��ȥ",
        "force" : 120,
        "dodge" : 10,
        "damage" : 75,
        "lvl" : 0,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�̫�����ȡ�����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
        "force" : 140,
        "dodge" : 10,
        "damage" : 55,
        "lvl" : 20,
        "skill_name" : "̫������",
        "damage_type" : "����"
]),
([      "action" : "$Nչ���鲽������Ծ�䣬һ�С����Ǻϵ¡������滯������ն��$n",
        "force" : 160,
        "dodge" : 15,
        "damage" : 55,
        "lvl" : 40,
        "skill_name" : "���Ǻϵ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����»�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
        "force" : 180,
        "dodge" : 15,
        "damage" : 25,
        "lvl" : 60,
        "skill_name" : "���»���",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����һ�С���ɫ���ࡹ��˫�ֳ����������У�����$n���ؿ�",
        "force" : 200,
        "dodge" : 10,
        "damage" : 30,
        "damage" : 75,
        "lvl" : 80,
        "skill_name" : "��ɫ����",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��һ�С���ٲ��������������ã����ҿ�����������$n",
        "force" : 250,
        "dodge" : 15,
        "damage" : 75,
        "lvl" : 100,
        "skill_name" : "��ٲ���",
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry" ||
usage == "array"; }

int form_array(object leader)
//int perform(object leader, object target)
{
        object *member,ob, weapon;
        int i,j,n;
        int max,min,skill;

        member = leader->query_team();
        if( sizeof(member) != 2 )
                return notify_fail("�����ǵ��������ˣ���һ����һ�������С�\n");

        j=sizeof (member);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                if (!ob||!living(ob)||!ob->is_character())
                {
                        return notify_fail("�����˭ͬʹ�����ǵ���\n");
                }
                if (ob->query_temp("array/name"))
                {
                        return notify_fail("�Ѿ���ɵ����ˡ�\n");
                }
                if (environment(leader)!=environment(ob))
                {
                        return notify_fail("�����������ˡ�\n");
                }
                if (!ob->query_skill("fanliangyi-dao",1))
                {
                        return notify_fail(ob->name()+"�����ᷴ���ǵ�����\n");
                }
                if (ob->is_ghost())
                {
                        return notify_fail("ֻ��������˲����鵶��\n");
                }

                if( (int)ob->query("max_neili") < 50 )
                        return notify_fail(ob->query("name")+"������������\n");

                if( (string)ob->query_skill_mapped("force")!= "zixia-shengong")
                        return notify_fail(ob->query("name")+"û��ʹ�û�ɽ���ڹ���\n");

                if( !(weapon = ob->query_temp("weapon"))
                ||      (string)weapon->query("skill_type") != "blade" )
                        return notify_fail(ob->query("name")+"�����ðѵ���������\n");

                if( (int)ob->query_skill("fanliangyi-dao",1)<30)
                        return notify_fail(ob->query("name")+"�ķ����ǵ���������������\n");

                if( (string)ob->query_skill_mapped("blade")!="fanliangyi-dao")
                        return notify_fail(ob->query("name")+"����ʹ�÷����ǵ�����\n");

        }

//get the average array skill of the team
        n=0;
        for (i=0;i<j;i++)
        {
                ob=member[i];
                n+=(int)ob->query_skill("fanliangyi-dao",1);
        }
        n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
        max=member[0]->query_skill("fanliangyi-dao",1);
        min=max;
        for (i=0;i<j;i++)
        {
                skill=member[i]->query_skill("fanliangyi-dao",1);
                if(skill>max)
                        max=skill;
                else if(skill<min)
                        min=skill;
        }

//and the leader is important
        n += leader->query_skill("fanliangyi-dao", 1) * 5;
        n /= max - min + 1;
if (n> 200) n=200;
if (n< 80) n=80;	
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->set_temp("no_quit",1);

                ob->set_temp("array/name","fanliangyi-dao");
                ob->set_temp("array/level",n);

                ob->add_temp("apply/attack",n);
                ob->add_temp("apply/defense", n);
                ob->add_temp("apply/damage",n);
                ob->add_temp("apply/armor", n);
        }
        message_vision( HIG "$N����$Nվ�����Ƿ�λ����ʱ����֮���Եû�Ȼ��ɡ���������!\n" NOR, leader);
        return 1;
}

int dismiss_array(object person)
{
        int i,j,n;
        object *member,ob;

        member = person->query_team();
        j=sizeof(member);
        n=person->query_temp("array/level");
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->delete_temp("array");
                ob->add_temp("apply/attack",-n);
                ob->add_temp("apply/damage",-n);
                ob->add_temp("apply/defense",-n);
                ob->add_temp("apply/armor", -n);
                tell_object(ob,"�����ɢ��\n");
        }
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
        object *member, ob;
        int i,j;
        member=leader->query_team();
        j=sizeof(member);

        for(i=0;i<j;i++) {
                ob=member[i];
                ob->kill_ob(enemy);
        }

        return 1;
}

int effective_level() { return 10;}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 10)
                return notify_fail("��ġ���ϼ�񹦡����̫ǳ��\n");
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
        level   = (int) me->query_skill("fanliangyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if( !me->query_skill("zixia-shengong",1))
                return notify_fail("���������ǵ���������Ҫ�ԡ���ϼ�񹦡�Ϊ������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("��������������������ǵ�������\n");

        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fanliangyi-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "������ϼ�񹦣��������ǣ�,$n˫��һ��,��֪����Ǻ�!\n" NOR:
                                     HIR "$N" HIR "��������,����" + weapon->name() + HIR "��������,$n˫��һ��,��֪����Ǻ�!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
        }
}
}