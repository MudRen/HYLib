// xue-dao.c Ѫ��
// Designed by secret(����)
//
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�߾�����$w,ʹ��һ��"+(order[random(13)])+"��ĥ��˱Ѫ��"NOR"��һ��б��$n��$l  ",
        "skill_name" : "ĥ��˱Ѫ",
        "force" : 100,
        "dodge" : 35,
        "parry" : 35,
        "lvl" : 0,
        "damage" : 320,
        "damage_type" : "����",
]),
([      "action" : "$N�͵�һ����ʹһ��"+(order[random(13)])+"����Ѫ���ء�"NOR"������$w����$n�Ĵ���  ",
        "skill_name" : "��Ѫ����",
        "force" : 140,
        "dodge" : 35,
        "parry" : 35,
        "lvl" : 8,
        "damage" : 225,
        "damage_type" : "����",
]),
([      "action" : "$N���һ�㣬ʹ��"+(order[random(13)])+"��Ѫ��ãã��"NOR"���������϶���ֱ��$n��$l  ",
        "skill_name" : "Ѫ��ãã",
        "force" : 180,
        "dodge" : 30,
        "parry" : 35,
        "lvl" : 16,
        "damage" : 230,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ��"+(order[random(13)])+"��Ż����Ѫ��"NOR"����$w��������һ��ѹ��$n  ",
        "skill_name" : "Ż����Ѫ",
        "force" : 220,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 24,
        "damage" : 240,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����ʹ��"+(order[random(13)])+"��Ѫ�����ˡ�"NOR"����$wֱ��$n��$l  ",
        "skill_name" : "Ѫ������",
        "force" : 250,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 32,
        "damage" : 250,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"��Ѫ���߰ߡ�"NOR"������б�̣���Ȼ����һ����ն$n������  ",
        "skill_name" : "Ѫ���߰�",
        "force" : 280,
        "dodge" : 50,
        "parry" : 55,
        "lvl" : 40,
        "damage" : 260,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ"+(order[random(13)])+"����Ѫ��Ѫ��"NOR"���ӵ�ֱָ$n���ؿ�  ",
        "skill_name" : "��Ѫ��Ѫ",
        "force" : 300,
        "dodge" : 55,
        "parry" : 50,
        "lvl" : 48,
        "damage" : 280,
        "damage_type" : "����",
]),
([      "action" : "$N������㣬ʹ��һ��"+(order[random(13)])+"��Ѫ�����桹"NOR"��ת���$w����$n������  ",
        "skill_name" : "Ѫ������",
        "force" : 320,
        "dodge" : 50,
        "parry" : 50,
        "lvl" : 56,
        "damage" : 300,
        "damage_type" : "����",
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��ĥ��˱Ѫ��"NOR"����$w���������$n�߽��ˣ�ͻȻ������ץס������˳��һ�ӣ�����$p$l",
        "skill_name" : "ĥ��˱Ѫ",
        "force" : 100,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 5,
        "damage" : 250,
        "damage_type" : "����",
]),
([      "action" : "$N�ٺ�һЦ��һʽ"+(order[random(13)])+"����ֽ������"NOR"��һ��������ȥ��$nֻ����ǰ���������$l��΢΢һ��",
        "skill_name" : "��ֽ����",
        "force" : 140,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 25,
        "damage" : 275,
        "damage_type" : "����",
]),
([      "action" : "$N��$w�ڿڣ�������$n���Դ�����ȥ����������ִӿ��г��������"+(order[random(13)])+"��Ѫ��ãã��"NOR"һ��֮�£�����ֱ��$p$l",
        "skill_name" : "Ѫ��ãã",
        "force" : 180,
        "dodge" : 65,
        "parry" : 55,
        "lvl" : 35,
        "damage" : 360,
        "damage_type" : "����",
]),
([      "action" : "$N�ٺ���Ц���У�һ��"+(order[random(13)])+"��Ѫϴ��ӡ�"NOR"��ͻ����$w��Ӱ������ӭͷ��ת������һ�����һ��������������ͷ����$n$l",
        "skill_name" : "Ѫϴ���",
        "force" : 220,
        "dodge" : 55,
        "lvl" : 55,
        "damage" : 390,
        "damage_type" : "����",
]),
([      "action" : "$N������ǰһ̽��һ��"+(order[random(13)])+"��Ѫ����硹"NOR"��$w���������б���һ��������һ�㣬Ѹ�����׵���$n�������ж������漴�յ����ʣ�������Ц",
        "skill_name" : "Ѫ�����",
        "force" : 250,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 75,
        "damage" : 300,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ������Ȼ������������$w�������ã�һʽ��Ѫ�����ۡ�"NOR"������ƬƬ����ն��$n��$l",
        "skill_name" : "Ѫ������",
        "force" : 280,
        "dodge" : 50,
        "parry" : 55,
        "lvl" : 95,
        "damage" : 360,
        "damage_type" : "����",
]),
([      "action" : "$N��͸���⣬����̹Ǻ��磬һ��"+(order[random(13)])+"��Ѫ��̹ǡ�"NOR"��ǰֱ�����£�һ����������������$n��$l",
        "skill_name" : "Ѫ��̹�",
        "force" : 300,
        "dodge" : 55,
        "parry" : 55,
        "lvl" : 105,
        "damage" : 380,
        "damage_type" : "����",
]),
([      "action" : "$Nһʽ"+(order[random(13)])+"��Ѫ�������"NOR"��һ��$wԽʹԽ�죬һ���ź�Ӱ������ȫ����$n��������������ֻ�����أ���������������",
        "skill_name" : "Ѫ�����",
        "force" : 320,
        "dodge" : 50,
        "parry" : 55,        	
        "lvl" : 125,
        "damage" : 320,
        "damage_type" : "����",
]),
});

string *parry_msg = ({
"$n����һ�̣�$w��һ�����ߣ�ֱ��$N������.",
"$n������һ�������е�$w˳�ƻ��£�����$N�յ���ָ��\n",
"$n����һ�䣬�����е�$w����һ��,��$N�Ĺ�����ƫ��ȥ.",
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("longxiang", 1) >= 20 ||
            (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else
                return notify_fail("����ڹ����̫ǳ��\n");
        if ((int)me->query_skill("mingwang-jian", 1) < 80)
		return notify_fail("��Ĳ������������̫ǳ��\n");
        if ((int)me->query_skill("lamaism", 1) < 80)
		return notify_fail("��������ķ����̫ǳ��\n");

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
        level   = (int) me->query_skill("xue-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if(!me->query_skill("longxiang",1)
                && !me->query_skill("xiaowuxiang",1))
                return notify_fail("��"+(order[random(13)])+"��Ѫ����"NOR"����Ҫ��ѩɽ�ɵ��ڹ���Ϊ������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("mingwang-jian", 1) < 80)
		return notify_fail("��Ĳ������������̫ǳ��\n");
        if ((int)me->query_skill("lamaism", 1) < 80)
		return notify_fail("��������ķ����̫ǳ��\n");

        if ((int)me->query("qi") < 150)
                return notify_fail("�������������������"+(order[random(13)])+"��Ѫ����"NOR"��\n");

        me->receive_damage("qi", 50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xue-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(  me->query("jiali") > me->query_skill("force") 
          && me->query_skill_mapped("force") == "longxiang") 
             me->set_temp("xiuluo", 1);
if (damage_bonus <10) damage_bonus=10;
if( me->query_skill("xue-dao",1) > 200)
{
        if (random(me->query_str()) > victim->query_str() || random(8)==0) 
        { 
	  victim->receive_wound("qi",  random(me->query_skill("xue-dao",1)/2)+10 );
        return HIW "$Nа���󷢣���ʱ��â��ʤ�����Ŵ�����$n���ϻ�����$n" BLINK + 
                                    HIR "��Ѫ" NOR + HIW "���������\n" NOR;
        } 
}

      if( random(me->query_skill("xue-dao",1)) > 90 || random(2)==0) 
{
	  victim->receive_wound("qi", damage_bonus);
        return HIR "$n������ɨ�У���ʱһ���Ѫ�ɽ���ȥ��\n" NOR;
}




}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N ���������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��$n����һ�ң�������Ȼ�᲻������\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ! $n����һ�����³�һ����Ѫ!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}