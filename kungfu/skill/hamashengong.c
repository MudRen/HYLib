// hamagong.c �����

#include <ansi.h>

inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N������������󡹦�ھ��ŷ���һ�������ӵ�����ֱ��������˫��һ�䣬���и��һ���кȣ����Ʊ㳯$n�Ƴ�",
	"dodge": 15,
	"parry": 20,
	"force": 300,
	"lvl" : 0,
	"damage": 320,
	"damage_type": "����"
]),
([      "action":"$N�ͺ�һ����˫��ٿ��$n$l�Ƴ������������ȥ������ʮ���Ͷ��������ú������죬������������ͬѰ��",
	"parry": 15,
	"force": 380,
	"lvl" : 105,
	"damage": 340,
	"damage_type": "����"
]),
([      "action":"$N�������ӣ���������һ����У��͵�˫���Ƴ����Ʒ����������$nͻ��һ����ɽ�����������ײ������Ѹ����",
	"dodge": 25,
	"force": 400,
         "parry": 40,
	"lvl" : 110,
	"damage": 340,
	"damage_type": "����"
]),
([      "action":"$N�׵����ӣ�������$n��ȥ���������ƣ�����������˫��������ϣ��Ʒ����������Ʋ�ס׷������������֮��",
	"dodge": 35,
	"parry": 40,
	"force": 420,
	"lvl" : 115,
	"damage": 330,
	"damage_type": "����"
]),
([      "action":"$N���󡱵�һ����У��������ƣ�˫��һ��һ�£�һ��һ�գ���Ȼ����������$n��ɽ��������������",
	"dodge": 20,
	"force": 400,
	"lvl" : 120,
	"damage": 390,
	"damage_type": "����"
]),
([      "action":"$N���Ӷ��£�˫��ƽ�ƶ��������п�����У�����һ��һ�ϡ���һ�ƾ�������ȥ��ȴ��������ƽƽ���棬����ȴ�ǰ��ؼ���Ǳ��",
	"dodge": 0,
	"force": 500,
	"parry": 100,
	"lvl" : 125,
	"damage": 350,
	"damage_type": "����"
]),
([      "action":"$N���ڵ��£��������Ľ��˼�����������ӿ��������һ�������������ϣ�������Ծ����˫���Ƴ���һ������֮�����Ʒ���֮��$nѹ��",
	"parry": 80,
	"dodge": 10,
	"force": 540,
	"lvl" : 130,
	"damage": 380,
	"damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N����������һ�ֳŵأ����Ӻ�ͦ��ֻ��һ����$n��$l�ĳ�"NOR"",
        "parry": 80,
        "dodge": 140,
        "force": 150,
        "damage" : 300,
        "lvl" : 5,	
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N˫���ڵ���һ�ţ����Ӻ��ذ���һԾ���ߣ�����$n����ǰ��������$pֱ������"NOR"",
        "weapon" : "��Ե",
        "parry": 80,
        "dodge": 135,
        "force": 160,
        "damage" : 300,
        "lvl" : 15,
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$NͻȻ�������Լ�������ץһ�ѣ��ַ������Լ����Ϻ���һ�ţ�һ�ƻ�������;����ر䣬ʵ��֪����δ�"NOR"",
        "dodge": 80,
        "parry": 80,
        "force": 100,
        "lvl" : 25,
        "damage" : 350,
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"ͻȻ֮�䣬$N������������ȫȻ���أ�΢΢��ͷ��һ����ĭ��$n$l��ȥ"NOR"",
        "weapon" : "��Һ",
        "dodge": 80,
        "parry": 80,
        "force": 280,
        "damage" : 300,
        "lvl" : 55,
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N˿��������ɫ��˫��΢��������ƽ�죬���ƻ��������󡹦�ľ���������һ������$n"NOR"",
        "dodge": 80,
        "force": 200,
        "parry": 80,
        "lvl" : 85,
        "damage" : 300,
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$NĬ��ھ�����������ֻ����ת����˳�죬����һ������Ծ�𣬹���һ���к���˫�ƶ���$n�ĳ�"NOR"",
        "dodge": 80,
        "force": 250,
        "parry": 80,
        "lvl" : 115,
        "damage" : 350,
        "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"����$N˫��΢����˫�ƻ��գ�Ȼ����$nһ��һ�£�һ��һ�գ���Ȼ����"NOR"",
        "dodge": 80,
        "force": 460,
        "parry": 80,
        "lvl" : 145,
        "damage" : 460,
        "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N���۱�ס����������Ƭ�̣���Ծ�����۾�Ҳ����������˫�Ʊ���$n�ķ������˳�ȥ"NOR"",
        "dodge": 80,
        "force": 580,
        "lvl" : 175,
        "parry": 80,
        "damage" : 580,
        "damage_type": "����"
]),
([  "action": ""+(order[random(13)])+"$N�Ų�ҡҡ�ϻϵĿ���ȥ���Ͼͻ��������Ȼ˫��һ�䡢һ�ǣ����и��һ���кȣ�������$n��Ȼ�Ƴ�"NOR"",
        "dodge": 85,
        "force": 600,
        "lvl" : 195,
        "parry": 80,
        "damage" : 640,
        "damage_type": "����"
]),
});

int valid_enable(string usage) 
{ return usage == "force" || usage=="strike" || usage=="unarmed" || usage =="parry"; }

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        
	string *power_msg = 
	({
		HIR"$N���������������󡹦��˫��ƽ�ƣ�������ü�����������к���������֮�����з缲��Ѹ���;���ʵ�Ƿ�ͬС��"NOR,
		WHT"$N�������ŭ�𣬶�������������˫�����������δ�����Ʒ��ѽ����³�������һ�ɾ���ֱ��$n���ţ��Ƶ���ǿ�ޱ�"NOR,
		HIR"$N��ɫ���������������鼡��΢΢ǣ�����������������һ����У�˫��ͦ����һ�ɾ������ֱײ�ĳ�$n�ƽ�����"NOR,
		WHT"$N�׵����ӣ����й������Ľ���������˫���Ƴ����Ը�󡹦��$n�͹���$n������$P��������֮�£�ֻ���û�����������������"NOR,
	});
	string *reverse_msg = 
	({
		HIM"����$N�������أ��������ף������������Լ�������ץһ�ѣ������������Լ����Ϻ���һ�ţ�ÿһ�ƴ򽫳�������;����ر䣬ʵ��֪�򽫺δ�"NOR,
		HIM"$N��Ȼ���������������Լ��������⣬��һ����˫�־ݵأ�����$n�����ط���һ������Ȼ�����Ծ��˫����$n��������"NOR,
		HIM"ͻȻ֮�䣬$N������������ȫȻ���أ����й����ޱȣ�����󡹦��ת���ã�������֮��������֮����������׽��"NOR,
		HIM"$Nȫ������˳���棬����������Ȼ���˴�������Ǵ��д��ţ����ֵֹ�������$n����ѽ�"NOR,
	});

        level   = (int) me->query_skill("hamashengong",1);

	if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("reverse") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && me->query("neili") > 1000)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 600+random(100),
			"damage": 820,
			"damage_type": random(2)?"����":"����"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 280  && random(me->query_skill("strike")) > 300 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 800+random(100),
			"damage": 820+random(20),
			"damage_type": "����",
			]);
else        if (random(me->query_str()) > 30 && 
            random(level) > 120 &&
            me->query("max_neili") > 3000 &&
            me->query("neili") > 1300 ) {
                me->add("neili", -50);
                return ([
                "action": HIC "$N�׵����ӣ�����΢�գ����й������Ľ���������˫����$n�����Ƴ������û�����������������" NOR,
                "dodge" : 80,
                "parry": 80,
                "damage": 800,
                "force": 850,
                "damage_type": "����"]);
        }
	}

        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 200)
   return notify_fail("����ڹ��ķ���򲻹����޷�ѧ����񹦡�\n");
    if ((int)me->query_skill("hamagong", 1) < 100)
	return notify_fail("��ĸ�󡹦�ڹ���򲻹����޷�ѧ����񹦡�\n");
    if ((int)me->query("neili") < 1500)
   return notify_fail("�������̫�����޷�������񹦡�\n");
    return 1;
}

int practice_skill(object me)
{
      return notify_fail("����񹦲������ʲô�ط���������ϰ�ġ�\n");
}


string exert_function_file(string func)
{
       return __DIR__"hamashengong/" + func;
}

string perform_action_file(string action)
{
        return __DIR__"hamashengong/" + action;
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
	if( damage_bonus/2 > victim->query_str() || random(5)==0 ) {
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