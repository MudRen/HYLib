// ruyi-dao.c ���⵶
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action" : "$N$w����������һʽ"+(order[random(13)])+"����Լ������"NOR""NOR"��$w�����·��ض���������ǣ�ʱ��ʱ�ֵ�Ʈ��$n",
        "force" : 170,
        "dodge" : 15,
        "parry" : 15,
        "damage": 120,
        "lvl" : 5,
        "skill_name" : "��Լ����",
        "damage_type" : "����"
]),
([      "action" : "$N������ˮ�����Ƹ��ƣ�����΢��ݳ�һ��"+(order[random(13)])+"���������ڡ�"NOR"��$w�滮��$n��$l",
        "force" : 210,
        "dodge" : 25,
        "parry" : 15,
        "damage": 160,
        "lvl" : 16,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ������������һ��"+(order[random(13)])+"������������"NOR"��������ָ�����⼴���������任�ղ���$n��$l",
        "force" : 270,
        "dodge" : 25,
        "parry" : 20,
        "damage": 175,
        "lvl" : 36,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "һ�ĵ���֮Ʈ�ݣ�$N��������ȫ����$w��ô󿪴�ͣ���̤�й���һʽ"+(order[random(13)])+"�����Ų��"NOR"��$w���ŷ�����$n��$l��ȥ��",
        "force" : 340,
        "dodge" : 20,
        "parry" : 20,
        "damage": 160,
        "lvl" : 46,
        "skill_name" : "���Ų��",
        "damage_type" : "����"
]),
([      "action" : "$N$w��ӣ�һ��"+(order[random(13)])+"������ɽˮ��"NOR"������㵶�ˣ���������һ��ӿ��$n",
        "force" : 380,
        "dodge" : 20,
        "parry" : 20,
        "damage": 170,
        "lvl" : 56,
        "skill_name" : "����ɽˮ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��־��ϼ�̡�"NOR"������Ʈ��������$w�ֳ�һƬϼ�⣬��ס$N������һ������$n",
        "force" : 400,
        "dodge" : 30,
        "parry" : 20,
        "damage": 180,
        "lvl" : 66,
        "skill_name" : "־��ϼ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ֵ�����$nһ����$w��һ��"+(order[random(13)])+"�������뻳��"NOR"�����⻮��һ��һС����ԲȦ��£��$n��������",
        "force" : 430,
        "dodge" : 20,
        "parry" : 30,
        "damage": 285,
        "lvl" : 76,
        "skill_name" : "�����뻳",
        "damage_type" : "����"
]),
([      "action" : "$N���и��ݣ�һ��"+(order[random(13)])+"����ң���졹"NOR"���ϵݳ���$w��Ϊ��ʮ����â���л��㱣�Ʈ����$n",
        "force" : 450,
        "dodge" : 30,
        "parry" : 30,
        "damage": 295,
        "lvl" : 85,
        "skill_name" : "��ң����",
        "damage_type" : "����"
]),
([	"action" : "$N����$wбָ��һ��"+(order[random(13)])+"��ͣ����·��"NOR"������һ�٣�һ����$n��$l��ȥ",
	"force" : 120,
        "dodge" : 10,
	"damage" : 150,
	"lvl" : 0,
	"skill_name" : "ͣ����·",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��ͯ�ӹһ���"NOR"����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 130,
        "dodge" : 20,
	"damage" : 180,
	"lvl" : 8,
	"skill_name" : "ͯ�ӹһ�",
	"damage_type" : "����"
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ��"+(order[random(13)])+"���ƴ����¡�"NOR"������һ������ն��$n",
	"force" : 140,
        "dodge" : 25,
	"damage" : 150,
	"lvl" : 16,
	"skill_name" : "�ƴ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����ż�ɽ��"NOR"��$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"force" : 160,
        "dodge" : 25,
	"damage" : 150,
	"lvl" : 24,
	"skill_name" : "���ż�ɽ",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ��"+(order[random(13)])+"����Ϫ���㡹"NOR"��˫�ֳ����������У�����$n���ؿ�",
	"force" : 180,
        "dodge" : 20,
	"damage" : 200,
	"lvl" : 33,
	"skill_name" : "��Ϫ����",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ��"+(order[random(13)])+"���Ź����ġ�"NOR"���������ã����ҿ�����������$n",
	"force" : 210,
        "dodge" : 25,
	"damage" : 250,
	"lvl" : 42,
	"skill_name" : "�Ź�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���������ۡ�"NOR"�����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"force" : 240,
        "dodge" : 25,
	"damage" : 300,
	"lvl" : 51,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����פ�أ�һ��"+(order[random(13)])+"��������Ϣ��"NOR"���ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"force" : 280,
        "dodge" : 40,
	"damage" : 360,
	"lvl" : 60,
	"skill_name" : "ͣ����·",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("beiming-shengong", 1) < 10)
		return notify_fail("��ı�ڤ�񹦻��̫ǳ��\n");
        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("������½�����̫ǳ��\n");


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
	level   = (int) me->query_skill("ruyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
        return notify_fail("����������������⵶��\n");
       if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("������½�����̫ǳ��\n");
		
	me->receive_damage("qi", 45);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"ruyi-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, zhencost,skill;
        string result;
        object weapon;
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage2;
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$NͻȻʹ����ڤ��,$nȫ����������ˮ��ԴԴ����������$N������!\n"NOR;
}
        lvl  = me->query_skill("ruyi-dao", 1);
        if (!objectp(weapon = me->query_temp("weapon")))
                return 0;
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return 0;
        if (lvl < 80 || 
            me->query("neili") < 300)
                return 0;

if (random(6)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }

        skill=me->query_skill("ruyi-dao",1);
        ap = me->query("combat_exp")/1000;
        dp = victim->query("combat_exp")/1000;
        
        if(random(ap)>dp/4 && random(skill) > 120) {
	        if ( random(4) == 1 ) {
        	        result = HIW "\n$N����Ʈ����������������һ�����������ӵ������һת���Ѿ��۵�$n��ǰ��৵�һ����\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -(random(skill)+50));
  victim->add("eff_qi", -(random(skill)+50));
  if( !victim->is_busy() )
{
        	        victim->start_busy(3);
}
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(4) ==0 ) {
                	result = HIG "\n$N����Ʈ�𣬳�Хһ��������"+(string)weapon->query("name")+HIG"�͵ش���$n��\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -(random(skill)+50));
  victim->add("eff_qi", -(random(skill)+50));
  if( !victim->is_busy() )
{
        	        victim->start_busy(3);
}
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(4) == 2 ) {
                	result = HIM "\n$N��һ������һ������������$n��Ҫ����ͻȻ�й�ֱ����ֱȡ$n�����š�\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -(random(skill)+50));
  victim->add("eff_qi", -(random(skill)+50));
  if( !victim->is_busy() )
{
        	        victim->start_busy(3);
}
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else
        	{
                	result = HIY"\n����"+weapon->name()+HIY"һ���������ѵ�$n��ǰ��$n���ɵ������޴롣\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -(random(skill)+50));
  victim->add("eff_qi", -(random(skill)+50));
  if( !victim->is_busy() )
{
        	        victim->start_busy(3);
}
	                damage = 0;
        
                	return ([ "result" : result, "damage" : damage ]);
        	}
     	}
}

