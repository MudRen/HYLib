// six-fingers.c ������
#include <ansi.h>
inherit SKILL;
int lvl_temp;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string  *msg = ({
"$N�ֱ۶�Ȼһ�ᣬ��$n���𹥻���������$n����һ�ߣ���������Ϊָ��ʹ��"RED"�����󽣡�"NOR"��
������ȥ���仯��΢��ֻ��һ�ɽ�������Сָ�������������$n��$l",

"$N˫���������ﻮ��һ��Ȧ��˫��������ǰ�������Сָ��һ��"RED"���ٳ彣��"NOR"��
�����ص���$n�������Ѩ����ָ���������ý�ǰ�������������ƿ�֮������",

"$N��Цһ��������Ӳ�������أ����ֺ�ն����������б�У�����ָ������һʽ"RED"���س彣��"NOR"��
׾�͹��ӣ������б�ָ���Ѷ�׼$n��$l������һ��ǿ�ҵľ���",

"$Nʳָ�����������ޱȣ��񿪶Է����ƣ��������٣��綾�߳�����������״��������һ����
ʹ��"RED"����������"NOR"��˫�ֻó�����ָӰ��������������ĥ������$n��$l",

"��ָ֮�䣬���ֻ�ǵ���һ����$Nһ���ƣ��������ƣ��������������ֶ�Ȼ̽����
��ָһ����һ��"RED"���г彣��"NOR"��Ѹ������$n��$l��ȥ���󿪴�ϣ�������ΰ",

"$N���ӵ��ɣ�������ָ�����ݲ��ȵؼܿ����ƣ���Ĵָʹ��"RED"�����̽���"NOR"������$n��$l��
����ʹ�����ɣ������󼱣�������ŭ������ӿ��������·�۾���ʯ���쾪",

});

mapping *action = ({
([	"action" : "$N���ӵ��ɣ�������ָ�����ݲ��ȵؼܿ����ƣ���Ĵָʹ��"RED"�����̽���"NOR"������$n��$l��
����ʹ�����ɣ������󼱣�������ŭ������ӿ��������·�۾���ʯ���쾪",
	"force" : 300,
           "dodge":  100,
           "damage": 400,
	"skill_name" : "�����ʾ�",
           "weapon" : "�������ν���",
           "damage_type":  "����"
]),
([	"action" : "��ָ֮�䣬���ֻ�ǵ���һ����$Nһ���ƣ��������ƣ��������������ֶ�Ȼ̽����
��ָһ����һ��"RED"���г彣��"NOR"��Ѹ������$n��$l��ȥ���󿪴�ϣ�������ΰ",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "Ҷ������",
           "weapon" : "�������ν���",
           "damage_type":  "����"
]),
([	"action" : "$Nʳָ�����������ޱȣ��񿪶Է����ƣ��������٣��綾�߳�����������״��������һ����
ʹ��"RED"����������"NOR"��˫�ֻó�����ָӰ��������������ĥ������$n��$l",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "������",
           "weapon" : "�������ν���",
           "damage_type":  "����"
]),
([	"action" : "$N��Цһ��������Ӳ�������أ����ֺ�ն����������б�У�����ָ������һʽ"RED"���س彣��"NOR"��
׾�͹��ӣ������б�ָ���Ѷ�׼$n��$l������һ��ǿ�ҵľ���",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "������˪",
           "weapon" : "�������ν���",
           "damage_type":  "����"
]),
([	"action" : "$N˫���������ﻮ��һ��Ȧ��˫��������ǰ�������Сָ��һ��"RED"���ٳ彣��"NOR"��
�����ص���$n�������Ѩ����ָ���������ý�ǰ�������������ƿ�֮������",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "٤Ҷ΢Ц",
           "weapon" : "�������ν���",
           "damage_type":  "����"
]),
([	"action" : "$N�ֱ۶�Ȼһ�ᣬ��$n���𹥻���������$n����һ�ߣ���������Ϊָ��ʹ��"RED"�����󽣡�"NOR"��
������ȥ���仯��΢��ֻ��һ�ɽ�������Сָ�������������$n��$l",
	"force" : 310,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "�����黨",
           "weapon" : "�������ν���",
           "damage": 500,
           "damage_type":  "����"
]),
([ "name":   "���̽�",
           "action": "$N����������˫��Ĵָͬʱ����������������죬�����̽���
����ʯ���쾪���������֮�ƣ���ָ$n���к�$l",
           "force":  350,
           "dodge":  100,
                                "weapon" : "�������ν���",
           "damage": 500,
           "damage_type":  "����"
        ]),
([      "name":   "���̽�",
        "action": "$N��Ĵָһ����������ָ������ʹ�����ɣ���" HIW "���̽�" NOR "������"
                  "��ŭ����ӿ��",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "���̽���" NOR,
        "damage_type":  "����"
]),
([      "name":   "���̽�",
        "action": "$N��Ĵָ���ӣ���" HIW "���̽�" NOR "��������һ����īɽˮ���ݺ���б"
                  "����·�۾�",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "���̽���" NOR,
        "damage_type":  "����"
]),
([      "name":   "���̽�",
        "action": "$N˫��Ĵָͬʱ�������" HIW "���̽�" NOR "���󿪴��أ����ɺ�ΰ��ÿ"
                  "һ�����з������֮��",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "���̽���" NOR,
        "damage_type":  "����"
]),
        ([ "name":   "������",
           "action": "$Nʳָ����������԰ת������������һ����һ���Ĵ̳�������
Ѹ�٣����ɻ��ã������ݺᣬ$n�����޷�������·",
           "force":  350,
           "dodge":  100,
                                "weapon" : "�������ν���",
           "damage": 500,
           "damage_type":  "����"
        ]),
([      "name":   "������",
        "action": "$N�������٣�����ʳָ������״�������" HIW "������" NOR "����ʱ�ó�"
                  "����ָӰ",
        "force" : 340,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "��������" NOR,
        "damage_type":  "����"
]),
([      "name":   "������",
        "action": "$NĴָһ����ʳָ�漴����������������죬���������������" HIW "��"
                  "����" NOR "������̳�",
        "force" : 440,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "��������" NOR,
        "damage_type":  "����"
]),
([      "name":   "������",
        "action": "$N��ʳָ���ˡ�" HIW "������" NOR "��֮���ν�����ȴ��������ָ������"
                  "��Χ��һ��һ��",
        "force" : 480,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "��������" NOR,
        "damage_type":  "����"
]),
        ([ "name":   "�г彣",
           "action": "$N������ָһ�������г彣����ǰ�̳��������ĵ�����Ȼ���죬
���ν���ֱָ$n��$l",
           "force":  350,
           "dodge":  130,
                                "weapon" : "�������ν���",
           "damage": 500,
           "damage_type":  "����"
        ]),
([      "name":   "�г彣",
        "action": "$N����ָ����һ�̣���" HIW "�г彣" NOR "���εض��𣬽�����ָ����һ"
                  "���������������㿳��",
        "force" : 560,
        "attack": 35,
        "dodge" : 10,
        "parry" : 30,
        "damage": 220,
        "weapon" : HIW "�г彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�г彣",
        "action": "����ʯ֮�䣬$N��Ȼ���ƣ����ֶ�Ȼ̽������ָ��" HIW "�г彣" NOR
                  "����$nһ��",
        "force" : 360,
        "attack": 35,
        "dodge" : 10,
        "parry" : 30,
        "damage": 220,
        "weapon" : HIW "�г彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�س彣",
        "action": "$N��������ָ�������" HIW "�س彣" NOR "����·׾�͹��ӣ�һ���ۻ���"
                  "�ȵ������ĵ�����",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "�س彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�س彣",
        "action": "$N����б�У�����ָ��" HIW "�س彣" NOR "�����������ָ���Ѷ�׼$n��"
                  "����һ��ǿ�ҵľ���",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 95,
        "damage": 280,
        "weapon" : HIW "�س彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�س彣",
        "action": "$N����ָ����һ�ӣ���������һ����׾�͹��ӵġ�" HIW "�س彣" NOR "��"
                  "������$nֱ�����",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 95,
        "damage": 280,
        "weapon" : HIW "�س彣��" NOR,
        "damage_type":  "����"
]),
        ([ "name":   "�س彣",
           "action": "$N��������ָ��������س彣����·׾�͹��ӣ�һ���ۻ����
���ĵ�����������ɽ��������$nӿȥ",
           "force":  350,
           "dodge":  130,
           "damage": 500,
           "damage_type":  "����"
        ]),
        ([ "name":   "����",
           "action": "$N����Сָһ�죬һ���������ٳ�Ѩ�м�������������󽣡�
������磬ָ��$n��$l",
           "force":  350,
           "dodge":  130,                            
           "damage": 500,
"weapon" : "�������ν���",
           "damage_type":  "����"
        ]),
([      "name":   "����",
        "action": "����$N����Сָһ�죬һ��������$P�ٳ�Ѩ�м��������һ�ɡ�" HIW "��"
                  "��" NOR "����ʱ����$n",
        "force" : 500,
        "attack": 30,
        "dodge" : 35,
        "parry" : 32,
        "damage": 270,
        "weapon" : HIW "������" NOR,
        "damage_type":  "����"
]),
        ([ "name":   "�ٳ彣",
           "action": "$N���ַ�ָ��Сָ������������ٳ�Ѩ���������������󽣡�
������䣬��$n���벻���ķ������$n��$l",
           "force":  350,
           "dodge":  130,
                                "weapon" : "�������ν���",
           "damage": 500,
           "damage_type":  "����"
        ]),
([      "name":   "�ٳ彣",
        "action": "$N��������ǰ�������Сָ��һ�С�" HIW "�ٳ彣" NOR "�������ص���$n"
                  "�������Ѩ",
        "force" : 530,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 260,
        "weapon" : HIW "�ٳ彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�ٳ彣",
        "action": "$NСָһ������" HIW "�ٳ彣" NOR "����ʽ���ֻ���������������ͬ����"
                  "һ�㣬Ʈ������",
        "force" : 430,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "�ٳ彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�ٳ彣",
        "action": "$Nһ�С�" HIW "�ٳ彣" NOR "����������ת�޶��Σ�����������˹�����"
                  "����$n",
        "force" : 530,
        "attack": 50,
        "dodge" : 50,
        "parry" : 55,
        "damage": 240,
        "weapon" : HIW "�ٳ彣��" NOR,
        "damage_type":  "����"
]),
([      "name":   "�ٳ彣",
        "action": "$N����Сָһ�ӣ�һ�С�" HIW "�ٳ彣" NOR "�����̴��ƿմ̳�������"
                  "�񻨴̻�һ��",
        "force" : 530,
        "attack": 80,
        "dodge" : 50,
        "parry" : 55,
        "damage": 280,
        "weapon" : HIW "�ٳ彣��" NOR,
        "damage_type":  "����"
]),
});


int valid_enable(string usage) { return usage=="finger" ||  usage=="unarmed"||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������񽣱�����֡�\n");
        if ((int)me->query("max_neili") < 1000)
            return notify_fail("�������̫�����޷�ѧ�����񽣡�\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�ͣ��޷�ѧ�����񽣡�\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("��Ķμҽ����̫ǳ��\n");
        if ((int)me->query_skill("tiannan-step", 1) < 80)
		return notify_fail("������ϲ������̫ǳ��\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        object* ob, obj;
        int i,skill,damage;

        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("������������������񽣡�\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("��Ķμҽ����̫ǳ��\n");
        if ((int)me->query_skill("tiannan-step", 1) < 80)
		return notify_fail("������ϲ������̫ǳ��\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("�����书�����������¡�\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
	if (me->query_skill("kurong-changong",1) > 10 &&
		me->query("neili") > 120
	&& me->query_skill_mapped("force") == "kurong-changong")
	{
	if( damage_bonus < 50 ) return 0; 
         if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );
        return HIR "ֻ��һ���Һ���һ����Ѫ��$n�����������\n" NOR;	
}
else    if( damage_bonus > 80 ) 
{
        victim->receive_wound("qi", damage_bonus/2 );	
        return YEL "$n�ƺ�һ��,���ӻ������Σ�\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus/3 );	
        return HIM "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
}
}
}
string query_parry_msg(object victim_weapon)
{
        switch (random(4))
        {
        case 0:
                return "$n������������������ݺύ������������$NΨ��������̾��ͽ���κΡ�\n";
        case 1:
                return "$n�������ܣ�һ���г彣ֱϮ$N����ǰ��Ѩ���ȵ�$Nֻ�л����Ծȡ�\n";
        case 2:
                return "$n���������������ص���ֱ���$Nüë���䣬������ͨ����Ҳ����ǰ����֣�\n";
        default:
                return "$nһ����Ц�����ν����Ĵ�ɢ������$N����ס��Ω����ǿ֧�š���Լ�԰�����$n�ķ�����\n";
        }
}
mapping query_action(object me, object weapon)
{
       lvl_temp = random((int)me->query_skill("six-finger", 1));


	if (random(me->query_skill("six-finger",1)) > 180 &&
		me->query_skill("kurong-changong",1) > 180 &&
		me->query("neili") > 120
		&& me->query_skill_mapped("force") == "kurong-changong"
	 )
	{
		me->add("neili", -50);
		return ([
	"action": HIG"$N��Ȼ���ý����е���·����һһӿ����ͷ��ʮָ�׵�����ȥ������
�����޾��������ݺᣬ����������·������ת��ʹ��$n��ʱ������ң���
��ȫ������ʹ��������Ѫ�����ϱ������ʹ̧ͷһ����һ������ӭ���ֵ�",
        "dodge": 100,
       "force": 300,
"weapon" : "�������ν���",
	"damage": 600,
	"damage_type": "����"]);
	}

        if ( lvl_temp > 100 && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
        && me->query_skill_mapped("force") == "kurong-changong")
        {
                                 if ( lvl_temp <= 140)
                        return ([
                                "action": HIY"$N˫����ָ���ٵ�����"RED"�������������г彣��"HIY"����ʹ��������ԴԴ��������$n"NOR,
                                "damage_type": "����",
                                "dodge": 110,
                                "force": 400,
                                "damage": 400,
                        ]);

                if ( lvl_temp > 150 && lvl_temp <180  && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
                && me->query_skill_mapped("force") == "kurong-changong")
                        return ([
                                "action": BLU"$N��Цһ��������ǰ�ˣ�˫��Ĵָͬʱ����һ��"RED"�����̽���"BLU"���������ν����ƿն�����ֱ����$n,�޼᲻�ݣ��Ʋ��ɵ�" NOR,
                                "damage": 400,
                                "damage_type": "����",
                                "dodge": 100,
                                "force": 450,
                                                                "weapon": "���ν���",
                        ]);

                if ( lvl_temp >= 180  && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
                && me->query_skill_mapped("force") == "kurong-changong")
                        return ([
                                "action": HIW"$N��Ϣ��ת�����ϴ߶�������"HIY"�������񽣡�"HIW"ʹ�ð����޷��������ƿ�֮����Ϊ������Ϯ��$n�����Ŵ�Ѩ" NOR,
                                "damage_type": "����",
                                "dodge": 100,
                                "force": 400,
                                "damage": (random(6)+2)*100,
                                "weapon" : "�������ν���",
                                ]);


        }

	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
    return __DIR__"six-finger/" + action;
}

