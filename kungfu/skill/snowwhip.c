 // snowwhip.c
#include <ansi.h> 
inherit SKILL;


string *parry_msg = ({
        "$n���е�$vһ������������һ��ҧ��$N����ۡ�\n",
                "$nһ�����е�$v��ʹ�����۱޳�ǹ���Ĺ��򣬱���ֱ��$N�Ļ��ڡ�\n",
                "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
                "$nʹ��һ�С���ѩ���������Ƶ�$N�˳����⡣\n",
                
        });
string *unarmed_parry_msg = ({
        "$n���е�$vһ������������һ��ҧ��$N����ۡ�\n",
        "$nһ�����е�$v��ʹ�����۱޳�ǹ���Ĺ��򣬱���ֱ��$N�Ļ��ڡ�\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$nʹ��һ�С���ѩ���������Ƶ�$N�˳����⡣\n",
        });
mapping *action = ({
                ([      "name":                 "��������",
                        "action":               
                        "$Nʹһ�С��������⡹������$w���ñ�ֱ��$n��$l��������",
                        "dodge":                10,
                        "damage":               530,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�����ѩ",
                        "action":               
                        "$N����һת��һ�С������ѩ��$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
                        "dodge":                50,
                        "damage":               520,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "ѩ������",
                   "action":               
                        "$N����$w��һ�С�ѩ�����桹����ӰƮ�������ص���$n��$l",
                        "dodge":                40,
                        "damage":               525,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��ѩ����",
                        "action":               
                        "$N����$wһ����һ�С���ѩ���ߡ���һ������ĽǶ���$n���̾�ȥ",
                        "dodge":                40,
                        "damage":               530,
                        "damage_type":  "����"
                ]),
                ([
                        "name":                 "�����ѩ",
                        "action":               
                        "$N����һ����ʹ�С������ѩ��������$wһ�޽���һ�޲�ͣ�س���$n��$l",
                        "dodge":                50,
                        "damage":               500,
                        "damage_type":   "����"
                ]),
                ([      "name":                 "��ѩ����",
                        "action":               
                        "$Nһ�С���ѩ���ӡ�����$w���һƬ��Ӱɨ��$nȫ��",
                        "dodge":                60,
                        "damage":               550,
                        "damage_type":  "����"
        ]),
        });
int valid_enable(string usage) { return usage == "whip" ||  usage == "parry"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"snowwhip/" + action;
}        

int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_neili") < 150 ){
                return notify_fail("�������������û�а취����ѩ�޷�, ����Щ���������ɡ�\n");
        }
   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("�����书������ϱ�ѩ�ķ���������\n");
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("neili") < 5 ){
                return notify_fail("�������������û�а취��ϰ��ѩ�޷���\n");
        }

        me->add("neili", -5);
        write("�㰴����ѧ����һ�麮ѩ�޷���\n");
        return 1;
}    


mixed hit_ob(object me, object victim, int damage_bonus)
{

   if ( me->query("family/family_name")== "������" && me->query_skill("bingxue-xinfa",1)>40) {
if (random(3)==0 && random(me->query_skill("bingxue-xinfa",1))>100)
{
            victim->apply_condition("cold_poison", (me->query_skill("bingxue-xinfa"))/10 +
			victim->query_condition("cold_poison"));
        victim->receive_wound("qi", (damage_bonus - 30) / 2 );
        return HIW "$nֻ�����˿�һ��,һ�ɺ����Ʊ���һ���Ĵ���$n��ȫ��\n" NOR;
}
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bingxue-xinfa",1);
        level2= (int) me->query_skill("bingxue-xinfa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bingxue-xinfa" )
{
if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}
if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}
msg = HIB "$N" HIB "�����Ѫ�ķ�!! ȫ����˿�һ˲��ֹס����Ѫ��\n" NOR;
msg += HIB "һ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$n������\n" NOR;
ob->apply_condition("xscold_poison",12);

           message_vision(msg, me, ob);
           return j;
}       
}     