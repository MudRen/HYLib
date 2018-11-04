#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action":"$Nʹһʽ"+(order[random(13)])+"�������Ƶء�"NOR"������$w����һ��������������$n",
        "force" : 120,
        "dodge" : 10,
        "damage": 280,
        "lvl" : 0,
        "skill_name" : "�����Ƶ�",
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��ʹ��"+(order[random(13)])+"��ˮ�����졹"NOR"��ֻ�����콣Ӱ������ɽ���������$nѹȥ",
        "force" : 140,
        "dodge" : 10,
        "damage": 260,
        "lvl" : 9,
        "skill_name" : "ˮ������",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ"+(order[random(13)])+"�������Ұ��"NOR"���͵��˷�����������$w���������$n���ɶ���",
        "force" : 160,
        "dodge" : 5,
        "damage": 260,
        "lvl" : 18,
        "skill_name" : "�����Ұ",
        "damage_type":  "����"
]),
([      "action":"$N�߶�������һʽ"+(order[random(13)])+"��ɽ����񾪡�"NOR"������Ю������ɽ��ľ޴�����ѹ��$n",
        "force" : 180,
        "dodge" : 10,
        "damage": 220,
        "lvl" : 27,
        "skill_name" : "ɽ�����",
        "damage_type":  "����"
]),
([      "action":"$N���쳤Х��һʽ"+(order[random(13)])+"����������项"NOR"�����Ϻ�Ȼ���ֳ������Ľ�Ӱ���������$n�������",
        "force" : 220,
        "dodge" : 15,
        "damage": 220,
        "lvl" : 36,
        "skill_name" : "���������",
        "damage_type":  "����"
]),
([      "action":"$N����$w�ֳ���â���ɣ�һʽ"+(order[random(13)])+"������ħ�"NOR"�����콻���ŵĽ�â��$n����Χס",
        "force" : 260,
        "dodge" : 5,
        "damage": 300,
        "lvl" : 44,
        "skill_name" : "����ħ�",
        "damage_type":  "����"
]),
([      "action":"$NһԾ����һʽ"+(order[random(13)])+"��ħ�����졹"NOR"��$w����ҫ�۹�ã������ó�����������$n��ȫ��",
        "force" : 380,
        "dodge" : 5,
        "damage": 360,
        "lvl" : 60,
        "skill_name" : "ħ������",
        "damage_type":  "����"
]),
([      "action":"$Nʹ����ħ���ռ�����"+(order[random(13)])+"���˽���һ��"NOR"�����뽣�˴�����һ�壬����һ����â����$n",
        "force" : 480,
        "dodge" : 5,
        "damage": 380,
        "lvl" : 80,
        "skill_name" : "�˽���һ",
        "damage_type":  "����"
]),
        ([      "action":               "$N����$wһ����$n����û�п����$N�ĳ�����",
        "force" : 480,
                "damage":               200,
                "dodge":                60,
                "parry":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��δ�������ѳ���$nֻ��������档����������",
                "dodge":                50,
                "parry":                50,
                "damage":               240,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����һ�ۣ�$w���ⲻ����$nȫ�����¶�ʱ���������У�",
                "damage":               220,
                "dodge":                50,
                "parry":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����Բ��һ����ת�������ٶȻ��ǽǶȶ���$n�������㡣",
                "dodge":                50,
                "parry":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               "$n��ǰһ����$N��$w���ѵ���$n����ǰ��",
                "damage":               340,
                "dodge":                50,
                "parry":                50,
                "damage_type":  "����"
        ]), 

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="tmdao"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
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
        level   = (int) me->query_skill("tmjian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "����" + weapon->name();
        else
	        name = "˫��";
if ( !me->query_temp("action_flag") && random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"	))
{

	        message_vision(HIW "\n��ʱ��ֻ��$N" HIW "�����Ͱڣ���ʱ����Ϊ������Ӱ��" + name +
        	               HIW "\n�������ǰ�ִӲ�ͬ�ķ�λͬʱ����$n" HIW "��\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
        lvl  = me->query_skill("tmdafa", 1);
        if (lvl==0)
        lvl  = me->query_skill("tmdafa", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "tmdafa" )
                return;
        if (lvl < 120 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));
return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("���������������ħ������\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"tmjian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "һ����Ц! ���Ǵ�!! " HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}