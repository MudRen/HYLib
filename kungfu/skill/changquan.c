//��ȭ changquan.c
//menpai skill(can also be used by non-menpai NPCs)
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N����һ�����������һ���������ڡ���׼$n�ı��Ӻ��������˹�ȥ",
                "dodge":                15,
                "parry":                15,
       "force":     190,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�֣���ȭ������һ�С��β�Ѱ�ߡ�����$n��$l�к���ȥ",
                "dodge":                15,
                "parry":                15,
       "force":     160,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��ȭ��$n����һ�Σ�����ʹ�˸���Ҷ��͵�ҡ���$n��$l����һץ",
                "dodge":                15,
                "parry":                15,
       "force":     160,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N����һ������ȭ��������ȭ���磬һ�С��ڻ����ġ��Ʋ��ɵ��ػ���$n$l",
                "dodge":                15,
                "parry":                15,
       "force":     180,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N������ʽ��һ�С�˫������ʹ�û����з硣����ȴ����һ������$n$l",
                "dodge":                15,
                "parry":                15,
       "force":     170,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������𣬴��һ�����������С������ཻ����\n������$n���һ������ȭ����$n�������˹�ȥ",
                "dodge":                15,
                "parry":                15,
       "force":     220,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�����󹭲���˫��ʹ�˸�������Ʊա���$n��$lһ��",
                "dodge":                15,
                "parry":                15,
       "force":     150,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����������һ����ȭ����$n$l������һȭ�߹�һȭ��\n��һ�е����ֻ��൱���ţ�����������������",
                "dodge":                15,
                "parry":                15,
       "force":     180,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ�˸��������̸���������ɨ��$n��$l",
                "dodge":                15,
                "parry":                15,
       "force":     150,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��ת�����ƻ��أ����Ʒ���ʹ�˸���������ɽ����$n��ͷһ��",
                "dodge":                15,
                "parry":                15,
       "force":     190,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n˵ʱ����ʱ�죬ֻ��$Nһ��������˫���ѵ���$n��$l",
                "dodge":                15,
                "parry":                15,
       "force":     200,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("����ȭ������֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("jing") < 30)
     return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("����������������Ϣһ�������ɡ�\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("������������ˡ�\n");

   me->receive_damage("qi", 30);
   me->add("neili", -10);

   return 1;
}
string perform_action_file(string action)
{
        return __DIR__"changquan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
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
if (random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
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