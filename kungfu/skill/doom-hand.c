 // doomstrike.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
                "$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
                "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
                "$n��һת��һ�С���������������$N����$w���֡�\n",
                "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
                 "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
                "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
                "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});
        

         
        mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ����ѩ����ʽ������׼$n��$l�����ĳ�����",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��������ķ�������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                70,
                "parry":                10,
                "force":                180,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С����������졹˫�Ʋ����Ƴ�",
                "dodge":                90,
                "parry":                90,
                "force":                420,
                "damage":                100,	
                "damage_type":  "����"
        ]),
        });

int valid_enable(string usage) { return usage == "hand" ||  usage == "parry" ; }
int valid_combine(string combo) { return combo=="hanshan-strike"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"doom-hand/" + action;
}
int valid_learn(object me)
{

   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("�����书������ϱ�ѩ�ķ���������\n");
        
        if( (int)me->query("max_neili") < 100 ) {
                return notify_fail("�������̫�����޷����������֡�\n");
        }
        return 1;
}  
int practice_skill(object me)
{
        
        if ((int)me->query("neili") < 100) {
                return notify_fail("�������������ϰ��\n");
        }

        me->add("neili", -50);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus) {
       int my_exp, your_exp, damage, lvl, bonus;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        lvl= me->query_skill("doom-hand",1);
        
        damage = random(lvl)+1;
        bonus = (my_exp-4000000)/500000*damage; 
        if (bonus>3*lvl) bonus=3*lvl;
        if (bonus>0) damage=damage+bonus;        
if (random(5)==0)
{
                victim->receive_wound("qi",damage+random(damage));
                if (random(2)==1) return HIR "$N�����˳�һ���ɺ�����棬�ǿ���$n��ȫ��\n" NOR;
                else    return HIW "$N����͸��˿˿����,$n�����ߡ�\n" NOR;
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