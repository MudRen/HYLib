// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// mingyu-gong.c

#include <ansi.h>

inherit FORCE;

int valid_force(string force) { return 1; }  
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("mingyu-gong", 1);
        return lvl /10 * lvl /10 * 15 * 28 / 10 / 20;
}
string *dodge_msg = ({
        "$N���μ��٣����Ų�ƣ�����$n������Χ�ȹ�������ȴ�����ڼ䲻�ݷ��Ŀ�϶�ܹ�",
        "$N���п���ת�ۣ���$nÿ�ι���ǰ��ٿ����ʧ��һ���Ӿ��ѳ�$n�Ĺ�����Χ",        
        "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ������������", 
        "$Nƾ������������$n�Ĺ�����Χ�ڽ������ܣ���������һ����һ���Ĺ���",
        "$N��Ų���٣���Ȼ�ڿ����γ���Ӱ������������$Nһ��Ų��",
        "$n��ǰ��Ȼһ������ǰ$N����Ӱ�ƺ���Щ������������һ��$N������������ǰ����һ�ߵĽ���",
});

string *parry_msg = ({
        "�ۿ�$nת���ѹ�����$N���赭д��ȴ�ֿ���ޱȣ���$n����ʽ��������",
        "$n�ۿ�����֮�ʣ�ͻ��һ�����ᾢ�����ϣ�û�ȽӴ��������ֱ��Ѿ�ʹ������æ��һ�����ã���Ȼ����",
        "$n�������Ͼ�������ţ�뺣�������ŵ״������в��$Nȴ���Ѿ�����",
        "$n����һ�ݣ������������ƣ������ﳤ�գ���Զ��֪�����������޴�����",
});


string *action_msg = ({
        "$Nʮָ΢�ţ����Ƽ򵥵ģ�ȴ���ſ���ͬʱ����������ȻĪ�еĳ��������$n",
        "$N�������񹦣������𽥱��͸����ɭ��ɱ������ʵ�ʣ���������ס$n",
        "$N˫��һ��һ�գ�ƽʵ��һ��ȴ��$n���紦������֮�У���������",
        "$N�������������ޣ�һ��һʽ�������޷����������������ݺ���ȥ",
        "$N�û���������꣬����������˷���ȥ���γ�����С����",
        "$n����һ��������ѹ���£������Լ����β�����ͬʱһ�������ھ�����䣬����������$n������·",
        "$Nһ�л���$n��ͬʱһ�������ھ����಻����ӿ��$n�����ڣ��ֽ�ʴ��",
        "$N�������񹦣������������ýݣ��������ߴܶ���$nֻ�����ۻ�����",
        "$N΢һ���֣����������綾�ߺ�ˮ�Ƶر���Ⱥ�����裬�ҹ���$n",
        "$nֻ���ù������ھ�������������������һ����������ʲô���������ֱ۱��ǧ������ϵ��Լ�ֱ��ǰ��",
});

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 200 + random(120),
                "attack": 50 + random(60),
                "dodge" : 50 + random(60),
                "parry" : 50 + random(60),
                "damage" : 280 + random(60),
                "damage_type" : "����",  
        ]);
}

string query_dodge_msg(string limb){        return dodge_msg[random(sizeof(dodge_msg))];}

string query_parry_msg(object weapon){        return parry_msg[random(sizeof(parry_msg))];}

int valid_enable(string usage)
{
         return usage == "force" || usage == "unarmed" || usage == "sword" ||
                usage == "dodge" || usage == "parry";
}

int double_attack() { return 1; }

int valid_learn(object me)
{
        int level;
        int i;

        //if (me->query("gender") != "Ů��")
        //        return notify_fail("�㴿��֮�����㣬��������������񹦡�\n");
                


        if (me->query("int") < 30)
                return notify_fail("��������񹦹��ڼ��������⡣\n");

        if ((int)me->query("max_neili") < 3000)
            return notify_fail("���������Ϊ̫ǳ���޷���ת���񹦡�\n");

        level = me->query_skill("mingyu-gong", 1);
         if((int)me->query_skill("bingxue-xinfa",1) < 280)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n"); 

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("��ķ�ѩӳ÷����Ϊ������\n");
         if((int)me->query_skill("hanshan-strike",1) < 150)
                return notify_fail("��ĺ�ɽ�Ʒ���Ϊ������\n");
         if((int)me->query_skill("doom-hand",1) < 150)
                return notify_fail("��ĺ���������Ϊ������\n");                                
         if((int)me->query_skill("snowwhip",1) < 150)
                return notify_fail("��ĺ�ѩ�޷���Ϊ������\n");   

         if((int)me->query_skill("xueshan-sword",1) < 150)
                return notify_fail("���ѩɽ������Ϊ������\n");   

         if((int)me->query_skill("jinwu-blade",1) < 150)
                return notify_fail("��Ľ��ڵ�����Ϊ������\n");   


         if((int)me->query_skill("snowstep",1) < 280)
                return notify_fail("���÷ѩƮ����Ϊ������\n");   





        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬������ת���񹦡�\n");

        if (me->query_skill("force", 1)+100 < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "��������񹦡�\n");

        if (me->query_skill("unarmed", 1)+100 < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "��������񹦡�\n");

        return 1;
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2,damage3;
                mapping result;
        int ap, dp;
        int cost;
        level = (int) me->query_skill("bingxue-xinfa",1);
        level2= (int) me->query_skill("bingxue-xinfa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
damage3= (int) me->query("neili",1)/8+300;
        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query_skill("count", 1) * 6;
        dp = me->query_skill("force") * 12;
        
        if (ap / 2 + random(ap) < dp && random(5)==0  && me->query("neili") >=300)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                                           msg = HIR "$N" HIR "Ĭ�������ܾ�������"
                                            "�ھ�������$n" + HIR "��һ�У�$N" HIR
                                            "ֻ������������೤���У�˿���������á�\n"
                                            NOR;

                        break;
                case 1:
                                           msg = HIR "$n" HIR "һ�л���$n" HIR "����"
                                            "����ȴ��������޻���һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR;
                        
                        break;
                default:
                                           msg = HIR "����$N" HIR "΢΢һЦ����������"
                                            "�Ľ�����$n" HIR "��һ�У�����֮����֮����"
                                            "û���ܵ�����˺���\n" NOR;
 
                        break;
                }
if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage3);
}
if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage3);
}
           message_vision(msg, me, ob);
           return j;

        }
 
if (random(8)==0 && level>=300  )
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
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int i;
        object weapon;

        lvl = me->query_skill("mingyu-gong", 1);
        weapon = me->query_temp("weapon");

        if ( me->query_temp("mingyu_pfm/qiong")
             && me->query_temp("mingyu_pfm/qiong") > 0
             && !me->query_temp("mingyu_pfm/qiong_hit_done")
             && !weapon
             && me->query("neili") >=300
             )
        {
                me->add("neili", -40);
                message_vision(HIY"\n$Nǰ�н��䣬����������ǰ����������һʽ������˷������಻����\n"NOR,me);
                me->set_temp("mingyu_pfm/qiong_hit_done", 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                me->delete_temp("mingyu_pfm/qiong_hit_done");
        }


        if (damage_bonus < 80
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "mingyu-gong"
           || me->query_skill_mapped("unarmed") != "mingyu-gong"
           )
                return 0;
        if (damage_bonus / 2 > victim->query_con() || random(5)==0)
        {
                me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 80) / 2+30);
            victim->apply_condition("cold_poison", (me->query_skill("bingxue-xinfa"))/10 +
			victim->query_condition("cold_poison"));
if (random(2)==0)
{
                return  HIR "ֻ��$N" HIR "�����ھ������ڱŷ���һ���ᾢ����ʽ"
                                   "���������ݻ���$n" HIR "����Ԫ��\n" NOR;
}
else
{
                return  HIR "$N" HIR "���񹦵�Ǳ�������˳�����ͻȻ��$n"
                                   HIR "ֻ�к���һ�����һ����Ѫ��\n" NOR;
}
        }

}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("mingyu-gong", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 70;
        if (lvl < 250) return 80;
        if (lvl < 300) return 90;
        if (lvl < 350) return 100;
        if (lvl < 400) return 110;
        return 120;
}

int practice_skill(object me)
{
        return notify_fail("����ֻ����ѧ(learn)�������������ȡ�\n");
}

int difficult_level()
{
        return 1000;
}

string perform_action_file(string action)
{
        return __DIR__"mingyu-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"mingyu-gong/exert/" + action;
}

void skill_improved(object me)
{
        int lvl, layer;

        lvl = me->query_skill("mingyu-gong", 1);
        layer = lvl / 90;

        if ((lvl % 90) == 0 && layer > 9)
        {
                tell_object(me, HIY "��������ֽ���һ�㡣\n" NOR);
        } else
        if ((lvl % 90) == 0)
        {
                tell_object(me, HIY "�������˵�" + chinese_number(layer) +
                                "������񹦡�\n" NOR);
        }
}
