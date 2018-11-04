 //hanshan-strike.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
        "$nһ�С�����һ�ߡ����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��ϣ���ȭһ�С�����Ϊ�������Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�ʨ��Ի͡����ͻ�$N��$w������\n",
        "$nһ�С����Ρ�������һ��$N��$w���֣���ƫ��$N��$w��\n",
        });

        
string *unarmed_parry_msg = ({
        "$nһ�С�������������Ƶ�$N��;���С�\n",
        "$n����������һ�С����׳�н������$N֮�ؾȡ�\n",
        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
        "$n˫ȭ�����ʹ��һ�С�һ��˫�񡹣�$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
        });  

mapping *action = ({
                ([      "action":               "$Nʹһ�С����ɲ��¡�����׼$n��$l��������һȭ",
                        "dodge":                30,
                        "parry":                40,
                        "damage":                100,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����ȭͷ��һ�С���ѩ��ɽ������$n��$l�к���ȥ",
                        "dodge":                30,
                        "parry":                30,
                        "damage":                100,	
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N������Σ���ȭ����ɽ���Ρ���$n��$l����",
                        "dodge":                30,
                        "parry":                30,
                        "damage":                100,	
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һ������ȭ��������ȭʹ�����������졹����$n$l",
                        "dodge":                90,
                   "parry":                30,
                        "damage":                100,	
                        "damage_type":  "����"
                 ]),
               ([      "action":               
                        "$Nʹ��һ�С�����ȡ����������һ����������󴩳�����$n��$l",
                                "dodge":                130,
                                "parry":                100,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ��һ�С������ݱ���������������Σ�����Ϊʵ����$n��$l",
                                "dodge":                100,
                                "parry":                230,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ�������ɵ�ɽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                           "dodge":                130,
                                "parry":                210,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N˫��һ�������б��¡���һ�ɼ��������Ĺ�������$n��$l",
                                "dodge":                220,
                                "parry":                230,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����Ǻ��⡹����$n$l",
                                "dodge":                120,
                                "parry":                130,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$Nʹ�������ǵ�㡹������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                                "dodge":                170,
                                "parry":                110,
                                "damage":                100,	
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                        "$N����������һ�С���������졹˫�Ʋ����Ƴ�",
                                "dodge":                170,
                                "parry":                240,
                                "damage":                100,	
                                "damage_type":  "����"
        ]),
        });


int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }
int valid_combine(string combo) { return combo=="doom-hand"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"hanshan-strike/" + action;
}
int valid_learn(object me)
{

   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("�����书������ϱ�ѩ�ķ���������\n");
        
        if( (int)me->query("max_neili") < 100 ) {
                return notify_fail("�������̫�����޷�����ɽ�Ʒ���\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("neili") < 10) {
                return notify_fail("�������������ϰ��\n");
        }

        me->add("neili", -5);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 200 ) return 0;
        badint = me->query_skill("doom-hand",1);
        if (random(5)==0) {
                if(badint) {
                        victim->receive_wound("qi",badint);
                        switch(random(3)) {
                                case 0: return "$N�ľ��������о������ƹ���ǽ����������һ������$n�����ţ�\n";
                                case 1: return "$N�������������������������뷢��$n��$l������������һ�����죡\n";
                                case 2: return "ֻ����$n��$l��������һ�� ������\n";
                                }
                }
        }
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