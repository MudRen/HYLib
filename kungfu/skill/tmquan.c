#include <ansi.h>
#include <combat.h>
inherit SKILL;



mapping *action = ({

       ([      "action":               
"$N˫ȭһ��һ�С�ħ����١��ó�����ȭӰ£��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                250,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫ȭ�׷ɣ�һ�С�ħ��ʳ⸡�ֱȡ$n��$l",
                "dodge":                10,
                "parry":                30,
                "damage":                230,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ����˫ȭ�����Ƴ���һ�С�ħ����ء�ǿ����ȭ��ֱ��$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                250,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ħ������ȭ�еġ�ħ߱ɭɭ������ȫ��$n��$l������˫ȭ֮��",
                "dodge":                10,
                "parry":                30,
                "damage":                260,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ȭΪ����һ�С�Ǭ����ħ��������ȭ�ֿ�$n������Ҫ��",
                "dodge":                20,
                "parry":                30,
                "damage":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ᣬȫ�����һ�С�ħ�ߺ͹ѡ���˫ȭ�������",
                "dodge":                70,
                "parry":                10,
                "damage":                280,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ߣ�һ�С�ħ�����ݡ���ɭɭȭ���޿ײ����ػ���$n��$l",
                "parry":                40,
                "force":                220,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ�������ħ������ȭ�еġ�����ħ��˫ȭЯ���ħ��֮������$n��$l",
                "parry":                40,
                "force":                120,
                "damage" :              250,
                "damage_type":  "����"
        ]),

});






mapping query_action(object me)

{

        if (random(me->query_skill("unarmed")) > 60 &&

            me->query_skill("force") > 50 &&

            me->query("neili") > 100 ) {

                me->add("neili", -100);

                return ([

                "action": HIY"ֻ��$N�վ�ȫ����ȫ����������˫ȭ���Ⱪ�֣�һ��"

                          "���˵�ȭ������$n����ǰ"NOR,

                "parry": 60,
                "dodge": 60,
                "force": 600,
                "damage" : 880,
                "damage_type": "����"]);

        }

        return action[random(sizeof(action))];

}

int valid_enable(string usage) { return usage=="parry" || usage=="cuff"; }

int valid_combine(string combo) { return combo=="tmzhang"; }

int valid_learn(object me)

{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

                return notify_fail("����ħȭ������֡�\n");

        if ((int)me->query_skill("tmdafa", 1) < 10)

                return notify_fail("�����ħ�󷨻�򲻹����޷�����ħȭ��\n");

        if ((int)me->query("max_neili") < 60)

                return notify_fail("�������̫�����޷�����ħȭ");

        return 1;

}





int practice_skill(object me)

{

        if ((int)me->query("qi") < 30)

                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 8)

                return notify_fail("���������������ħȭ��\n");

        if (me->query_skill("tmquan", 1) < 50)

                me->receive_damage("qi", 20);

        else

                me->receive_damage("qi", 30);

        me->add("neili", -5);

        return 1;

}

string perform_action_file(string action)
{
        return __DIR__"tmquan/" + action;
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
	        name = "˫ȭ";
if (!me->query_temp("action_flag") && random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
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
victim->receive_wound("qi", random(lvl)+10 );
return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }
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

