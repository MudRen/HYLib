// ����������.������ȭ��

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action" : "$N��ϥ���������ֺ�ʮ��һʽ"+(order[random(13)])+"���衹"NOR"��˫ȭ���ƶ���������$n��$l",
    "force" : 180,
    "dodge" : 5,
    "damage":               200,
    "lvl" : 0,
    "skill_name" : "��",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ"+(order[random(13)])+"��ϼ��"NOR"��˫�������»���ȭ�����棬��ž����",
    "force" : 200,
    "dodge" : 5,
    "damage": 170,
    "lvl" : 2,
    "skill_name" : "ϼ",
    "damage_type" : "����"
]),
([  "action" : "$N�ڿշ���һʽ"+(order[random(13)])+"��Ϣ����"NOR"��˫��˫���������$n�޿ɶ��",    
    "force" : 230,
    "dodge" : 15,
    "damage": 200,
    "lvl" : 4,
    "skill_name" : "Ϣ��",
    "damage_type" : "����"
]),
([  "action" : "$N�ڿշ���һʽ"+(order[random(13)])+"��Ϣ����"NOR"��˫��˫���������$n�޿ɶ��",    
    "force" : 230,
    "dodge" : 15,
    "damage": 200,
    "lvl" : 10,
    "skill_name" : "Ϣ��",
    "damage_type" : "����"
]),


([  "action" : "$N˫���麬����Ե�³���һʽ"+(order[random(13)])+"��������"NOR"��������$n�Ƴ�",
    "force" : 200,
    "dodge" : 5,
    "damage": 220,
    "lvl" : 20,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action" : "$N˫���麬����Ե�³���һʽ"+(order[random(13)])+"��������"NOR"��������$n�Ƴ�",
    "force" : 170,
    "dodge" : 5,
    "damage": 100,
    "lvl" : 30,
    "skill_name" : "����",
    "damage_type" : "����"
]),

([  "action" : "$N˫���麬����Ե�³���һʽ"+(order[random(13)])+"��������"NOR"��������$n�Ƴ�",
    "force" : 270,
    "dodge" : 5,
    "damage": 220,
    "lvl" : 60,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ"+(order[random(13)])+"���޳���"NOR"������$n����ǰ���",    
    "force" : 320,
    "dodge" : 10,
    "damage": 115,
    "lvl" : 80,
    "skill_name" : "�޳�",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ"+(order[random(13)])+"��ɲ�ǡ�"NOR"������ʮָ���$n��ȫ����ʮ����ҪѨ",
    "force" : 380,
    "dodge" : 25,
    "damage": 225,
    "lvl" : 90,
    "skill_name" : "ɲ��",
    "damage_type" : "����"
]),
([  "action" : "$N��Ŀ���ӣ�˫��������һʽ"+(order[random(13)])+"����������"NOR"������˷������������ǵ�
����",
    "force" : 450,
    "dodge" : 15,
    "damage": 135,
    "lvl" : 100,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ"+(order[random(13)])+"��Ӱ������"NOR"����Ȼ����$n��ǰ��",
    "force" : 530,
    "dodge" : 20,
    "damage": 250,
    "lvl" : 60,
    "skill_name" : "Ӱ����",
    "damage_type" : "����"
]),
(["action" :"$N˫��һ�ӣ���һʽ"+(order[random(13)])+"��Ӱ�衹"NOR"�������ͨ��֮�ƣ�ȭ��������������ֱ��$n��ȥ",
  "force" : 150,
  "dodge" : 15,
    "damage": 215,
  "lvl" : 5,
  "skill_name" : "Ӱ��",
  "damage_type" : "����"
]),
(["action" :"$N�������������һ�գ�����һ����ǽ������������ȭ������$n��һ��"+(order[random(13)])+"��ɽ�ڡ�"NOR"��ǽ����",
  "force" : 200,
  "dodge" : 110,
    "damage": 215,
  "lvl" : 15,
  "skill_name" : "ɽ��",
  "damage_type" : "����"
]),
(["action" :"$Nһ����ʽ"+(order[random(13)])+"����׵����"NOR"��˫ȭ���������������ಢ����׼$n$lһʽ�ӳ��������쳣",
  "force" : 220,
  "dodge" : 115,
    "damage": 115,
  "lvl" : 25,
  "skill_name" : "��׵��",
  "damage_type" : "����"
]),
(["action" :"$Nʹ��һ��"+(order[random(13)])+"��������"NOR"��˫�������Ӷ���ȭ����ſ��е�ʨ�Ӻ���������ɽ��Ϯ��$n",
  "force" : 240,
  "dodge" : 120,
    "damage": 215,
  "lvl" : 45,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N��������һʽ"+(order[random(13)])+"��ֱʽ��"NOR"�������������һȭ���棬������ǰ�ˣ����������ϻ�$n",
  "force" : 260,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 65,
  "skill_name" : "ֱʽ",
  "damage_type" : "����"
]),
(["action" :"$N�ӳ���ȭ������$n�����⻨ȭ֮��ʱ��һ�ɾ��籬��������$p�ؿڣ�������ʵ��"+(order[random(13)])+"��������"NOR"",
  "force" : 280,
  "dodge" : 110,
    "damage": 115,
  "lvl" : 75,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N���̷𾭣����һ��"+(order[random(13)])+"��бʽ��"NOR"��ֱ��$nǰ�أ�ȭ�������������������������˿������",
  "force" : 300,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 85,
  "skill_name" : "бʽ",
  "damage_type" : "����"
]),
(["action" :"ֻ��$N��ʮ����������"+(order[random(13)])+"����ʽ��"NOR"һ��Ϊ��������Ϊȭ����������ȫ������ѹ��$n",
  "force" : 450,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 105,
  "skill_name" : "��ʽ",
  "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="unarmed" ||usage=="parry"; }     
int valid_combine(string combo) { return combo=="enmeiryu"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("��������ȭ��������֡�\n");
    if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("xuanhualiu-quanfa", 1))
   return notify_fail("��Ŀ��ֵ���򲻹����޷�ѧ��\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("���ɱ���ķ���򲻹����޷�ѧ������ȭ����\n");
    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������̫�����޷���������ȭ����\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
string msg;
	int level, jiali, time,level2;
	object weapon;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*3+150;
                  msg = HIR"�����ؾ�!��$N�Լ����ٵ�����,�ڵ�һ����,$nû�����ֿ���ʱ����ڶ���! \n"NOR;
if (random(3)==0) msg = HIR"�����ջ���!����$N�����ؾ�����������Զ��������$n,�����ֲ�Զ���빥���Ĳ��� ��\n"NOR;
if (random(3)==1) msg = HIR"���������!����$Nθװ�ʹ�,�û�ʯ�Ƶļ�������������,$n������Ļ������!! \n"NOR;
if (random(3)==2) msg = HIR"���ɺ׷���!����$Nʹ�����ֱ�Ӵ��ڵ�ȭ��֮һ����$n! ���߷��Ѷ���һ��!!\n"NOR;

if (victim->query("qi") > flvl)
{
victim->start_busy(2+random(3));
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
        }

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shayi-xinfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫֱ�����ѱ�����ȭ�����˿���!\n"NOR;
        }

}
mapping query_action(object me, object weapon)
{
    int i, level;
    object ob;
    ob = me->select_opponent();
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

    level   = (int) me->query_skill("xuanhualiu-quanfa",1)/10;
if (!ob)         return action[NewRandom(i, 20, level/5)];
if (  me->query_skill_mapped("unarmed") == "xuanhualiu-quanfa"
&& ! me->query_temp("weapon")
&&  !me->is_busy()
&&living(ob)
&& !me->query_temp("dsauto")
&& !me->query_temp("sc_hama")
&& random(me->query_skill("xuanhualiu-quanfa",1))> 180
)
{
	 message_vision(HIW"\n�����ؾ�!��$N�Լ����ٵ�����,�ڵ�һ����,$nû�����ֿ���ʱ����ڶ���! \n"NOR, me,ob);
me->set_temp("dsauto",1);
	me->add_temp("apply/attack", (level*2));
	me->add_temp("apply/damage", (level*4));
if (random(2)==0) ob->start_busy(3);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	me->add_temp("apply/attack", -(level*2));
	me->add_temp("apply/damage", -(level*4));
me->delete_temp("dsauto");
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");

    if ((int)me->query("qi") < 70)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("�������������������ȭ����\n");
    me->receive_damage("qi", 50);
    me->add("neili", -30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xuanhualiu-quanfa/" + action;
}

