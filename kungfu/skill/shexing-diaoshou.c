
// shexing-diaoshou.c ���ε���
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$Nһʽ"+(order[random(13)])+"�����߳�����"NOR"��������Σ���������ͻȻ����$n�ı����Ѩ",
	"force" : 390,
        "dodge" : 50,
"damage": 340,
	"lvl" : 0,
	"skill_name" : "���߳���",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�Σ�һʽ"+(order[random(13)])+"����ͷ��β��"NOR"����������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"force" : 320,
        "dodge" : 50,
"damage": 340,
	"lvl" : 10,
	"skill_name" : "��ͷ��β",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ"+(order[random(13)])+"���������㡹"NOR"�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"force" : 230,
        "dodge" : 20,
	"damage": 385,
	"lvl" : 20,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�������У�����ֱ����һʽ"+(order[random(13)])+"��������Ӱ��"NOR"����Ʈ��������$n������",
	"force" : 260,
        "dodge" : 20,
	"damage": 280,
	"lvl" : 30,
	"skill_name" : "������Ӱ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ"+(order[random(13)])+"��������ܡ�"NOR"����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"force" : 300,
        "dodge" : 30,
	"damage": 295,
	"lvl" : 38,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ"+(order[random(13)])+"����������"NOR"��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 310,
        "dodge" : 40,
	"damage": 225,
	"lvl" : 51,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ"+(order[random(13)])+"��������ӿ��"NOR"����Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"force" : 380,
        "dodge" : 40,
	"damage": 230,
	"lvl" : 56,
	"skill_name" : "������ӿ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ"+(order[random(13)])+"���������š�"NOR"��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"force" : 460,
        "dodge" : 40,
	"damage": 340,
	"lvl" : 60,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ�ӳ���һʽ"+(order[random(13)])+"������ͦ��"NOR"������$n����Ե",
        "force" : 80,
        "damage" : 280,
        "dodge" : 25,
        "lvl" : 0,
        "skill_name" : "����ͦ��",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ"+(order[random(13)])+"���������š�"NOR"��ָ��$n����ǰ",
        "force" : 100,
        "damage" : 280,
        "dodge" : 25,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ"+(order[random(13)])+"�����߰�β��"NOR"����$n��$l����",
        "force" : 120,
        "damage" : 280,
        "dodge" : 28,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "���߰�β",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ"+(order[random(13)])+"�����߲�ʳ��"NOR"��˫ָ����$n�Ķ�����硢�ۡ��ء���",
        "force" : 150,
        "dodge" : 5,
        "damage" : 280,
        "damage": 265,
        "lvl" : 45,
        "skill_name" : "���߲�ʳ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ"+(order[random(13)])+"���������С�"NOR"�������������⣬��ָ���Ƶ���$n��$l",
        "force" : 180,
        "dodge" : 15,
        "damage" : 280,
        "damage": 280,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ"+(order[random(13)])+"�����߳�����"NOR"��Сָ����$n��̫ԨѨ",
        "force" : 200,
        "dodge" : 20,
        "damage": 2100,
        "lvl" : 70,
        "skill_name" : "���߳���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ų�������������һʽ"+(order[random(13)])+"��ǧ�߲���"NOR"����$n��ȫ��",
        "force" : 220,
        "dodge" : 25,
        "damage": 220,
        "lvl" : 80,
        "skill_name" : "ǧ�߲���",
        "damage_type" : "����"
]),

});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"|| usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ε��ֱ�����֡�\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦���� \n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������ε��֡�\n");
	return 1;
}
int valid_combine(string combo) { return combo=="lingshe-quan" || combo == "shentuo-zhang"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level,ob_lvl,attack;
		object ob;
		
		ob = me->select_opponent();
		level = (int)me->query_skill("shexing-diaoshou", 1)+1;
		
		attack=level/100;
		
if (!ob) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
if (!me) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}



		if(level>200
			&&random(level)>level/3
			&&(random(me->query_dex())>20)
			&&living(ob)
//			&&me!= ob
			&&me->query("neili")>800
                        && !me->is_busy() 
                        && !me->query_temp("noauto")
		&& !me->query_temp("dsauto"))
		{
				if(attack>4) attack=4;
				attack=random(attack);
				if(attack<=1) attack=1;
				if(attack>4) attack=4;
message_vision(HIY "�����ţ�$N���з�����˻˻����������˫�ְ�������ָ��������״���������ң���������缱�籩��㹥����"+
			   chinese_number(attack+1)+"�С�\n" NOR, me);
					for(i=0;i<attack;i++)
					{
						me->add("neili", -(50+random(50)));
						
						if(!ob)
						{
						break;
						}
//						if(me=ob)
//						{
//						break;
//						}


						if(!me)
						{
						break;
						}

						if(!living(ob))
						{
						break;
						}
						if(ob && me)
						{
						me->set_temp("dsauto",1);
						COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);  
						me->delete_temp("dsauto");
                                                }
					}
		}
else		if(level>200
			&&random(level)>level*2/5
			&&(random(me->query_dex())>25)
			&&living(ob)
			&&me->query("neili")>500
			&&random(5)>2
&& !me->query_temp("noauto")
			)
	{
			message_vision(YEL "$N������ϣ����������������һ�ܣ�$n��$N���������Ի󣬶�ʱ������������Ϊ���ء�\n" NOR, me,ob);

if (ob && me &&
ob!=me)
{
  if( !ob->is_busy() )
{
			ob->start_busy(3);
}
			me->add("neili", -20);
}
		}

		



        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������ε��֡�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"shexing-diaoshou/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N��ת����������һ�䣬һ�ڶ�������$n�³�!$nͷһ�裬��֪���� ��\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N��ת��������$n�ſ�һҧ!$n�˿�һ������Ѫ�����\n";
}
	if( damage_bonus/2 > victim->query_str() || random(8)==0 ) {
if(me->query_skill("hamagong", 1)>100)
{
if (me->query_skill_mapped("force") == "hamagong"
&& !me->query_temp("weapon"))
{
		victim->receive_wound("qi", (damage_bonus ) / 2 );
		return HIM " "+ victim->name()+"��Ϣδ�����־�һ�ɾ����������,�³���һ�����Ѫ��\n" NOR;
}
}
	}
}

