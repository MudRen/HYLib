// xianglong-zhang.c ����ʮ����
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;  
int sanhui(object me, object victim, object weapon, int damage);
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
"$p�����������С�������β�������Ʒ�����$P���������׺ݣ�����Ӳ�ӣ�����ܿ���\n",
"ֻ��$p����Բ��������ֱ�ƣ�������ǰ��һ�д��Ƿ�����ȴ����˫��֮�䲼��һ����ڡ�\n",
"$p���²��ҵ�����˫�Ƶ���ƽ�ƣ����Լ�ȫ������������֮�¡��ص�����Ԩͣ���ţ�ֱ�ް��������\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
	object me = victim->select_opponent();

if (me && victim
&& victim!=me)
{
	if ( victim->query_temp("weapon") || victim->query_skill("xianglong-zhang", 1) < 100
	|| victim->query_skill_prepared("strike") != "xianglong-zhang" )
		return SKILL_D("parry")->query_parry_msg(weapon);
        else {
        string *slbw = ({
                "$n������������һ�С�������β������ȥ�����ǽ���ʮ�����еľ������У�$p���鼱֮��ʹ������������������������\n",
                "$n���ò�������������һ�С�������β����������$P����һ�ƣ�\n",
                "������һ˲֮�䣬$p��æת��ͬʱһ�С�������β����$P���ֺ�����\n",
        });
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
		return COMBAT_D->do_attack(victim, me, me->query_temp("weapon")) + "";
                }
}
}


mapping *action = ({
([      "action": "$NͻȻ���μӿ죬˫��ƽƽ����$n��$l",
    "dodge": -30,
    "parry": 10,
    "force": 400,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$NͻȻ���η���˫�ƾӸ�����һ��"+(order[random(13)])+"���������졹"NOR"����$n��$l",     
    "dodge": -15,
    "parry": -20,
    "force": 280,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N����һ��"+(order[random(13)])+"���������"NOR"��Ѹ���ޱȵ�����$n��$l",
    "dodge": -10,
    "parry": -10,
    "force": 220,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N˫��ʩ��һ��"+(order[random(13)])+"���轥��½��"NOR"���������ŷ�������$n��$l",
    "dodge": -15,
    "parry": -10,
    "force": 260,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N���ƾ۳�ȭ״������һ��"+(order[random(13)])+"��Ǳ�����á�"NOR"��������$n��$l",
    "dodge": -10,
    "parry": 10,
    "force": 200,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʩ��һ��"+(order[random(13)])+"������󴨡�"NOR"�����Ʋ�������������$n��$l",
    "dodge": -10,
    "parry": 20,
    "force": 250,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"��ͻ��������"NOR"�����ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
    "dodge": 0,
    "parry": 10,
    "force": 100,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N���һ����˫��ʹ��"+(order[random(13)])+"���𾪰��"NOR"������һ�а����$n",
    "dodge": -25,
    "parry": -10,
    "force": 300,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"����Ծ��Ԩ��"NOR"����$n��$l��������",
    "dodge": -20,
    "parry": -20,
    "force": 230,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N���λ�����˫��ʹһ��"+(order[random(13)])+"��˫��ȡˮ��"NOR"һǰһ����$n��$l",
    "dodge": -10,
    "parry": 20,
    "force": 160,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"����Ծ��Ԩ��"NOR"�����η���˫�Ʋ���һ����$n��$l����",     
    "dodge": -20,
    "parry": 30,
    "force": 250,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N˫������ʹ��"+(order[random(13)])+"��ʱ��������"NOR"��$n��������",
    "dodge": -20,
    "parry": 20,
    "force": 270,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"�����Ʋ��꡹"NOR"�����Ʒ�ס$n����·������бб������$l",     
    "dodge": -15,
    "parry": 20,
    "force": 220,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"���������ڡ�"NOR"��˫�������������$n��$l",
    "dodge": -25,
    "parry": 10,
    "force": 350,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N����һת��ͻȻ�۵�$n��ǰ��һ��"+(order[random(13)])+"����ս��Ұ��"NOR"����$n��$l",     
    "dodge": -20,
    "parry": 40,
    "force": 330,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N�Ż��󿪣�һ��"+(order[random(13)])+"����˪������"NOR"��$n��$l��ȥ",
    "dodge": -25,
    "parry": 1,
    "force": 320,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$Nʹ��"+(order[random(13)])+"������ެ��"NOR"��˫���������ϻ���$n��$l",
    "dodge": -15,
    "parry": 40,
    "force": 200,
        "damage": 300,
    "damage_type": "����"
]),
([      "action": "$N���ƻ��أ�����ʹһ��"+(order[random(13)])+"��������β��"NOR"���»ζ��Ż���$n",     
    "dodge": -10,
    "parry": 40,
    "force": 220,
        "damage": 350,
    "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("������ʮ���Ʊ�����֡�\n");
if ((int)me->query_skill("huntian-qigong",1) < 80)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 80)
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 80)
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 80)
               return notify_fail("�����ң��̫���ˡ�\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷�������ʮ���ơ�\n");
    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 70)
   return notify_fail("�������̫���ˡ�\n");
if ((int)me->query_skill("huntian-qigong",1) < 80)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 80)
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 80)
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 80)
               return notify_fail("�����ң��̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�����������������ʮ���ơ�\n");
    me->receive_damage("qi", 50);
    me->add("neili", -15);
    return 1;
}
mapping query_action(object me, object weapon)
{
	int x = 1 + random(8);
	int y = 3 + random(10);
	string *sanhui_msg = 
	({
		HIW"$N������������һ�������ƺ���һ��������$n��ȥ������һ�С������лڡ��������������Ͳ��ɵ�"NOR,
		HIM"$Nһ�Ƽȳ���������ǰ������һ�С������лڡ���������ǰ�ƣ�˫����������һ����ɽ������ѹ������"NOR,
		HIG"$N��������һ�С������лڡ���ǰ������������������������������ŭ�ο�ӿ���Ʋ��ɵ�������һ�����εĸ�ǽ����$n��ǰ����"NOR,
	});

	if ( me->query_skill_mapped("force") == "huntian-qigong" )
	{
//             if ( me->query_skill("xianglong-zhang") > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
             if ( random(me->query_skill("xianglong-zhang")) > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
		{
			return ([
			"action": sanhui_msg[random(3)],
			"dodge": 20,
			"parry": 25,
			"force": 650,
			"damage": 520+random(600),
			"damage_type": random(2)?"����":"����" ]);
		}
		else if ( random(me->query_skill("xianglong-zhang")) > 230 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000  )
		{
			me->add("neili", -50);
			return ([
			"action": HIY"$Nһ�С������лڡ���ƽ�Ƴ�ȥ�����Ƴ�ȥ�������赭д����һ��������ɲʱ֮������"+ chinese_number(y) +"���ᾢ��һ��ǿ��һ�������ص�����ֱ���޼᲻�ݣ���ǿ����"NOR,
			"dodge": 20+random(20),
			"parry": 25+random(20),
			"force": 650+random(350),
			"damage": 520+random(400),
			"damage_type": random(2)?"����":"����" ]);
		}
		else if ( random(me->query_skill("xianglong-zhang")) > 200 && random(me->query_skill("force")) > 150 && me->query("neili") > 500)
		{
			me->add("neili", -30);
			return ([
			"action": YEL"$N̤������������һ����һ�С������лڡ����ػ�ȥ����һ��"+ chinese_number(x) +"�ַ���"+ chinese_number(10-x) +"���գ�����ȥ�����أ�ʵ�Ƿ�ͬС��"NOR,
			"dodge": 20+random(100),
			"parry": 25+random(100),
			"force": 600+random(350),
			"damage": 520+random(300),
			"damage_type": random(2)?"����":"����" ]);
		}
    else    if (random(me->query_skill("xianglong-zhang",1)) > 250 &&		 me->query_skill("huntian-qigong",1) > 200 &&
        me->query("neili") > 200)
{
	me->add("neili", -50);
        return ([
	"action": HIY"$N����΢�����ұ����䣬���ƻ��˸�ԲȦ������һ�����⼱�ƣ������ޱȣ�����������ǿ��"+(order[random(13)])+"�������лڡ�"NOR""NOR,
	"dodge": 80,
        "parry": 330,
        "damage": 600,
        "force": 600,
        "damage_type": "����"]);
}
else	if (random(me->query_skill("xianglong-zhang",1)) > 200 &&		me->query_skill("huntian-qigong",1) > 100 &&
        me->query("neili") > 200)
{
	me->add("neili", -30);
        return ([
	"action": HIC"$N�ۼ�$n�������͡����ò�������æת��ͬʱ�������������ǽ����Ƶľ�������"+(order[random(13)])+"��������β��"NOR""NOR,
	"parry": 60,
        "dodge": 80,
        "damage": 600,
        "force": 600,
        "damage_type": "����"]);
}
	}

	return action[random(sizeof(action))];
}

int ob_hit(object ob, object me, int damage)
{
   int i, neili;
if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;
if (ob && me &&
me!=ob)
{
   if(living(me) &&
      random(me->query("combat_exp")) > ob->query("combat_exp")/3 && 
      me->query_skill("xianglong-zhang", 1) >= 180 
      &&  !me->is_busy()
      &&      me->query("neili") > 600 &&
      me->query("qi") < me->query("max_qi")
      )
      {
        i = me->query("jiali");
        neili = me->query("neili");
        me->set("jiali", me->query_skill("force")*2);
        me->add_temp("apply/attack", 80);
        message_vision(HIC "����$NӲ����$n��һ�У����ƽ��������һ�ڣ�һ�С�������β�����䲻��ذ�����$n��$l�ϣ�\n" NOR, me, ob );
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        if(me->query("neili") < neili) me->set("neili", neili-50);
        me->set("jiali", i);
        me->add_temp("apply/attack", -80);
      }
      return 1;
}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xianglong-zhang", 1);

        if (damage_bonus < 150 || lvl < 150) return 0;
if (me->query_skill_mapped("force") != "huntian-qigong")
return 0;
        if (random(4)==0)
        {
                victim->receive_wound("qi", (damage_bonus - 50) , me);

                return random(2) ? HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                                   "�߹Ƕ��۵�������\n" NOR:

                                   HIR "$n" HIR "һ���ҽУ���ǰ���������꡹������"
                                   "�죬������Ѫ���硣\n" NOR;
        }
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

