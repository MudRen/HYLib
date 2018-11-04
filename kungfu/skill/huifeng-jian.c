//huifeng-jian.c �ط������
#include <ansi.h>
inherit SKILL;  
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "���Ϯ��",
        "action" : "$N���⽣â������һ��"+(order[random(13)])+"�����Ϯ�¡�"NOR"������$w�����´󿪴��أ�
һ����������$n��$l",
        "force" : 250,
        "dodge" : 20,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "Ʈѩ����",
        "action" : "$N����Ȧת��һ��"+(order[random(13)])+"��Ʈѩ���ơ�"NOR"������$wƽչ�´̣�һ�����Ữ
��$n��$l",
        "force" : 260,
        "dodge" : 20,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "ǧ�徺��",
        "action" : "$N��������������������������$wʹ��һʽ"+(order[random(13)])+"��ǧ�徺�㡹"NOR"����$n��
$l",
        "force" : 280,
        "dodge" : 15,
        "damage" : 350,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N������ָ��������ת��һ��"+(order[random(13)])+"���������ڡ�"NOR"ֱȡ$n��$l",
        "force" : 200,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+(order[random(13)])+"������������"NOR"���������
����$n��$l",
        "force" : 220,
        "dodge" : 25,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "������ɳ",
        "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"+(order[random(13)])+"��������ɳ��"NOR"ԾԾ����Ʈ��$n��$l",
        "force" : 340,
        "dodge" : 25,
        "damage" : 320,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+(order[random(13)])+"���������Ρ�"NOR"������
����֮�ƣ�����$n��$l",
        "force" : 360,
        "dodge" : 115,
        "lvl" : 0,
        "damage" : 400,
        "damage_type" : "����"
]),
([      "name":   "��غ���",
        "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+(order[random(13)])+"����غ��衹"NOR"����
���ϴ���$n��$l",
        "force" : 400,
        "dodge" : 135,
        "damage" : 400,
        "lvl" : 0,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
//        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("huifeng-jian", 1))
//                return notify_fail("��Ļ����������̫ǳ��\n");
        return 1;
}
string *juejian_msg = ({ 
	HIR"�����$N$w���������������������ָ����$n$l��ǡ������糸�����к���֮��"NOR,
	HIW"$N$wһ�Σ�����$n$l��ȥ������ز�÷��裬���ֺ��ϣ����������з��������޶�"NOR,
	HIC"ȴ��$NƮ����ϣ�����оٽ������������ѷ�ס��$n��������֮�أ����þ����ޱ�"NOR,
	HIM"$N��ǰ������������磬�����������棬$w�����������$n�������������Ǽ������Ĺ���"NOR,
	HIG"$Nһ�������ݵ�$n��ǰ������΢�����ӽ�б�ã�����$n$l�����������鶯���"NOR,
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("huifeng-jian", 1);

        if (random(me->query_skill("huifeng-jian",1)) > 200 &&	
	 random(me->query_skill("linji-zhuang",1))>120 &&
            me->query_skill("force",1) > 200 )	
	{
		return (["action": random(2) == 1 ?
				HIR"$N$w"HIR"΢�࣬��һ�б㼴����������ֱָ$n����ҪѨ������֮�����ͺ���ֱ�Ƿ�����˼"NOR
				: juejian_msg[random(sizeof(juejian_msg))],
			 "force" : 500,
			 "dodge" : 50,
			 "damage": 500,
			 "damage_type": random(2)?"����":"����" ]);
	}
	else for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("��������������ط��������\n");
        me->receive_damage("qi", 10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
}       
        wa = me->query_temp("weapon");
        skill = (int)me->query_skill("huifeng-jian", 1);
        neili = (int)me->query("neili");
                me->reset_action();
                limb = ob->query("limbs")[random(sizeof(ob->query("limbs")))];

                

     if(  wa && wa->query("skill_type") == "sword"
        && random(skill) > ((int)ob->query_skill("parry", 1)/3)
         && random((int)me->query("combat_exp")) > (int)ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "huifeng-jian"
         && me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query_skill_mapped("force") == "linji-zhuang"
         && (int)me->query_skill("linji-zhuang", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && (int)me->query("qi") > 500
         && userp(me))
         {
               if(random(3) >= 1)
               {
               i = random(sizeof(action));// if(i=0) i=2;
                       msg = "$N����$n�Ľ�������Ӱ��ӯһ������������\n";
               
                                 msg += HIC"����$n����֮ʱ��"+action[i]["action"]+"��\n"NOR;
                                                
               msg += "$nû���ϵ�$N��������Ȼ����������æ֮�䣬�����޴룡\n";
               ob->receive_damage("qi", damage);
               p = ob->query("qi")*100/ob->query("max_qi");
               msg += damage_msg(damage/2, "����");
               msg += "( $n"+eff_status_msg(p)+" )\n";
                j = -(damage/2);               
               }
                else{                                                
                 msg = HIC"����$n����֮ʱ��"+action[i]["action"]+"��\n"NOR;
                                        
                 msg += "$n���һ��������$p�����ϵ�����$P���˹����������ŷ����ַ�һ�С�\n";
                 j = -damage/3; 
               }           

                        msg = replace_string( msg, "$w", wa->name() );
                                msg = replace_string( msg, "$l", limb );

                                message_vision(msg, me, ob);
         return j;
                }
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 90 ) return 0;

        if( random(2)==0 && me->query_temp("huifeng/jue")) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 30) / 2 );
                return HIR "$n���˿ڱ�$N�����������ɳ�һ��Ѫ����\n";
        }
}