// feitian-yujianliu // feitian-yujianliu ����������
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({

	([	"action":		"$N���е�$wӭ��һ�Σ���������ѽ����������һ��"+(order[random(13)])+"������ն��"NOR"�����ڰ�ؿ���$n��$l",
		"force":		100,
                "damage":               100,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "����ն",
    		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$wӭ����裬һ��"+(order[random(13)])+"�������ġ�"NOR"�󱩷��еĹ�ɳ������$n��$l",
                "damage":               120,
		"force":		120,
                "dodge" : 20,
                "lvl" : 10,
                "skill_name" : "������",
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ�����"+(order[random(13)])+"�������ϡ�"NOR"���ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 20,
                "lvl" : 30,
                "skill_name" : "������",
                "damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ�����"+(order[random(13)])+"�������ϡ�"NOR"���ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 30,
                "lvl" : 30,
                "skill_name" : "������",
                "damage_type":	"����"
	]),

	([	"action":		"$N�ζ����е�$w��ͻȻʹ����"+(order[random(13)])+"����ͻ����"NOR"����������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
		"force":		200,
                "damage":               200,
                "dodge" : 30,
                "lvl" : 80,
                "skill_name" : "��ͻ��",
                "damage_type":	"����"
	]),
	([	"action":		"$N����ȫ��Ĺ�����"+(order[random(13)])+"����硹"NOR"���е�$w��̹Ǻ�������$n",
		"force":		240,
		"damage":		240,
                "dodge" : 40,
                "lvl" : 100,
                "skill_name" : "���",
                "damage_type":	"����"
	]),
       ([  "action" : "$N����Ծ������$w��ӣ�һʽ"+(order[random(13)])+"���Ӻϰ�ն��"NOR"ն��$n��",
               "damage" : 250,
               "dodge"  : 40,
               "force"  : 250,
               "lvl"   : 110,
               "skill_name" : "�Ӻϰ�ն",
               "damage_type" : "����"
        ]),
       ([  "action" : "$N�߸�Ծ������$w�����������Σ�ʹ��"+(order[random(13)])+"����β����"NOR"��$n���ұ����ն��",
           "damage" : 280,
           "dodge" : 40,
           "force" : 280,
           "lvl"   : 120,
           "skill_name" : "��β��",
           "damage_type" : "����"
       ]),
       ([  "action" : "$N����һ����ʹ��"+(order[random(13)])+"����ֱն��"NOR"��ˢˢˢˢ�ĵ�����$n�أ������������Ĵ�����",
           "damage" : 300,
           "dodge" : 45,
           "force" : 205,
           "lvl"   : 140,
           "skill_name" : "��ֱն",
           "damage_type" : "����"
       ]),
       ([  "action" : "$N����һ����Х��һ��"+(order[random(13)])+"��̤�봹ֱն��"NOR"��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
           "damage" : 350,
           "dodge" : 45,
           "force" : 205,
           "lvl"   : 160,
           "skill_name" : "̤�봹ֱն",
           "damage_type" : "����"
       ]),
([      "action":"$Nʩչ����"+(order[random(13)])+"������ɱ��"NOR"����$n������$w���ſ�Ұ���磬�����ޱȵ���������",
        "force" : 220,
        "dodge" : 30,
	"damage": 400,
        "lvl" : 200,
        "skill_name" : "����ɱ",
        "damage_type":  "����"
]),
([      "action":"$Nһ��"+(order[random(13)])+"���󻬻�תն��"NOR"��ͻȻ����$n���࣬Ѹ�͵�������ն����ʽ��Ȼ�ϳ�һ��ԲȦ",
        "force" : 230,
        "dodge" : 30,
        "damage": 420,
        "lvl" : 225,
        "skill_name" : "�󻬻�תն",
        "damage_type":  "����"
]),
([      "action":"$N���һ��������$w�󿪴��أ������ӵ�ʹ��"+(order[random(13)])+"���һ���תն��"NOR"��ն��$n��$l",
        "force" : 230,
        "dodge" : 30,
        "damage": 420,
        "lvl" : 230,
        "skill_name" : "�һ���תն",
        "damage_type":  "����"
]),
([      "action":"$N�˵���磬�����ó���"+(order[random(13)])+"������ɱ��"NOR"��"+(order[random(13)])+"�����ɱ��"NOR"��"+(order[random(13)])+"���ٹ�ɱ��"NOR"�����ưԵ�֮��������$n��������Ϳ�����",
        "force" : 500,
        "dodge" : 50,
        "damage": 600,
        "lvl" : 10,
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취��������������\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���򲻹���\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("�����������������ɱ���ķ���������\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("���������һ�ѵ�������������������\n");

    return 1;
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        object target;

        level   = (int) me->query_skill("feitian-yujianliu",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"�� ������! ��"+HIM"$Nһ�ְ�����,���¶���ֱ�飬����ޱȣ������ױȣ�����������ֻһ˲��֮��"NOR,
		"force" : 550+random(200),
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "������",
		"damage_type" : "����" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : CYN"�� ������! ��"+HIY"$N����$w"+HIY"΢΢�����������������ޣ���������Ʈ�ݣ������֮"NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"�� ˫����! ��"+HIY"$N��$w"+HIY"�ֲ��ε����϶,���͵���ͬʱ����$n��ȫ��"NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "˫����",
		"damage_type": random(2)?"����":"����"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"�� ������! ��"+HIY"$N��$w"+HIY"���������ն��,�������ʯ��,����$n��Ҫ���� "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"�� ������! ��"+HIY"$NͻȻ�߸�Ծ��$w"+HIY"�������!! $n���ŵĽ����������ˡ� "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"�� ������! ��"+HIY"$N������ת�������������ٵĻӶ�$w"+HIY"�����ľ�����$n���˹�ȥ�� "NOR,
        	"force" : 450,
        	"dodge" : 50,
        	"damage": 450,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"�� ��������! ��"+HIY"$NͻȻ��ʧ�ˣ����$w�ķ����������$n��ͷ�ϡ�"+HIY"$N��Ȼ�ڰ��ʹ���˰ε����� "NOR,
		"force" : 650,
        	"dodge" : 50,
        	"damage": 650,
        	"skill_name" : "��������",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"�� ��׵��! ��"+HIW"$N���ýź����ĵ�������Ծ��,�����չ�����¹��ڻ���$n�������� �� "NOR,
		"force" : 550,
        	"dodge" : 50,
        	"damage": 550,
        	"skill_name" : "��׵��",
		"damage_type": random(2)?"����":"����"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"�� ������! ��"+HIW"$N��װ���ٰε�,ʵ�����������Ƴ�����,ʹ�����ٷ���$n �� "NOR,
		"force" : 550,
        	"dodge" : 50,
        	"damage": 550,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}

  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���򲻹���\n");

        if( (int)me->query("qi") < 80
        ||      (int)me->query("neili") < 80 )
                return notify_fail("�����������������û�а취��ϰ������������\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
        write("�㰴����ѧ����һ�������������\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"feitian-yujianliu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("shayi-xinfa",1);
        level2= (int) me->query_skill("feitian-yujianliu",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
//if (!level) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ�"+weapon->name()+HIR"ն���������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("feitian-yujianliu", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 200
         && me->query_skill_mapped("blade") =="feitian-yujianliu"
         && me->query_skill_mapped("parry") =="feitian-yujianliu"
         && weapon
         && weapon->query("skill_type") == "blade"
         && me->query_skill("blade") > 300
         && random(me->query_skill("blade",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 900
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIM"$N���$n�Ĺ��ơ����ϵĵ�����һ�ƣ�һ�����������ڵ����ϣ�$n���������̵��������ۣ���\n"NOR;
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
}
else             msg = HIG"$N���$n�Ĺ��ơ����ϵĵ�����һ�ƣ�һ�����������ڵ����ϣ�$n˫��һ��,��������!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
