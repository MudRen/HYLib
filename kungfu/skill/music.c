#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 


string *parry_msg = ({
        "$n����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"NOR"֮����һ��������$N�ȿ���\n",
        "$n��������黮����������������������"+(order[random(13)])+"�����硹"NOR"֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ��"+(order[random(13)])+"��������"NOR"֮����$NһʱãȻ��֪���ԡ�\n", 
        });

        
string *unarmed_parry_msg = ({
        "$n����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"NOR"֮����һ��������$N�ȿ���\n",
        "$n��������黮����������������������"+(order[random(13)])+"����ǡ�"NOR"֮����$N�����е����񺳶���\n",
        "$n����ר���������ḧ���粦���ң����ഫ��"+(order[random(13)])+"��������"NOR"֮����$NһʱãȻ��֪���ԡ�\n", 
        });

mapping *action = ({
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"�����̡�"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"����ǡ�"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"��������"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),        
        
        ([      "action":               "$N��ָ���������󼲷����������̣�����"+(order[random(13)])+"������"NOR"֮����Ϯ��$n��$l",
                "dodge":                180,
                "parry":                20,
                "damage":               270,
                "damage_type":          "����",
                "weapon":               "ָ��",
        ]),
        ([      "action":               "$N�������ã�"+(order[random(13)])+"����ǡ�"NOR"��������Χ����ĵ�¡¡����ʮ�����Χ��$n",
                "dodge":                140,
                "parry":                90,
                "damage":               220,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������������ֺ���������"+(order[random(13)])+"�����̡�"NOR"֮�����ޱ�˿�꣬����Ʈ��$n��$l",
                "dodge":                120,
                "parry":                120,
                "damage":               290,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ֱ�ģ��������������ɢ��������������"+(order[random(13)])+"�����̡�"NOR"֮���У�����$n��$l",
                "dodge":                160,
                "parry":                20,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N˫����Ȼ�»��������������"+(order[random(13)])+"�����硹"NOR"֮����������ˮ֮������ֱȡ$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qidao"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("����ڹ��ķ���򲻹���\n");
    if ((int)me->query("max_neili") < 250)
   return notify_fail("�������̫����\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("��������޼�������Ϊ����! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("���Ѹ�׽����������ң�\n");

        if( (int)me->query_skill("chuanyun-tui", 1) < 100 )
                return notify_fail("��Ĵ����Ȼ������ң�\n");
                
        if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
                return notify_fail("��������ƻ������ң�\n");

        if( (int)me->query_skill("mantian-huayu", 1) < 100 )
                return notify_fail("������컨�껹�����ң�\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("�������ȭ�������ң�\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("��������黭�������ң�\n");

        if( (int)me->query_skill("taxue-wuhen", 1) < 100 )
                return notify_fail("���̤ѩ�޺ۻ������ң�\n");

    return 1;
}

int practice_skill(object me)
{
    object weapon;

     if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 70)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("�������������\n");

    if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("��������޼�������Ϊ����! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("���Ѹ�׽����������ң�\n");

        if( (int)me->query_skill("chuanyun-tui", 1) < 100 )
                return notify_fail("��Ĵ����Ȼ������ң�\n");
                
        if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
                return notify_fail("��������ƻ������ң�\n");

        if( (int)me->query_skill("mantian-huayu", 1) < 100 )
                return notify_fail("������컨�껹�����ң�\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("�������ȭ�������ң�\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("��������黭�������ң�\n");

        if( (int)me->query_skill("taxue-wuhen", 1) < 100 )
                return notify_fail("���̤ѩ�޺ۻ������ң�\n");

    me->receive_damage("qi", 55);
return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
if (( (int)me->query_skill("cuff", 1) >= 120 ) 
        &&	( (int)me->query_skill("music", 1) >= 120 )
	&&      ( (int)me->query("neili") >= 500 )
      && random(8)==0 ) {
		return ([
		"action": HIG"$N����Ĵָʳָ����������ӣ�����������"+(order[random(13)])+"�����̡�"HIG"֮����һ����������$n��"NOR,
	                "parry":(int)me->query_skill("parry",1)/3,
	       	       "damage":(int)me->query_skill("music",1)*2,
                 "dodge":(int)me->query_skill("dodge")/10+(int)me->query_skill("leg")/15,
		             "force": (int)me->query_skill("music")+(int)me->query_skill("leg"),
		"damage_type": "����"
  ]);
	}
return action[random(sizeof(action))];
} 
   
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	        string name;
        name = xue_name[random(sizeof(xue_name))];
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);

if (random(5)==0 && level>=200 && me->query_skill_mapped("force") == "xuantian-wuji")
{

        if (!victim->is_busy())
        victim->start_busy(2);
        //me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("music", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("music", 1) / 5 + damage_bonus / 5);
                return BLU "ֻ��һ�󴾺��������$N" BLU "��������$n" HIY "��" + name + "��"
                       NOR + BLU "��ʱ��������������ȫ�������Ҵܲ�ֹ��\n" NOR;
}

}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
     int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=ob->query("combat_exp");
        
        skill=me->query_skill("music",1);
        

        if (random(6)==0 && me->is_busy()) {
                message_vision(HIG"$N�����һ��������ͨ���ĵ���"+(order[random(13)])+"������ƪ��"NOR"������Ŀ��������Ȼ����������\n"NOR, me);       
if (me->query("eff_qi")<= me->query("max_qi") )
{
                me->add("qi",me->query_skill("art",1)+200);
                me->add("eff_qi",me->query_skill("art",1)+200);
}
                me->start_busy(1);
        }
        

}


string perform_action_file(string action)
{
    return __DIR__"music/" + action;
}