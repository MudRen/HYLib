#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 


string *parry_msg = ({
 "$n������������ס��$N�Ĺ��ơ�\n",
         });

        
string *unarmed_parry_msg = ({
"$n������������ס��$N�Ĺ��ơ�\n",
        });

mapping *action = ({
       ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"������ͷ��"NOR"�����־۳�һ�����������϶��£�����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"����б��"NOR"�����־۳�һ��������бб����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"��˫���ࡹ"NOR"��˫�־۳�һ������������ͬʱ����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"����������"NOR"��ȫ���ڿն�������ȫ�����������$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
       ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"�������ǡ�"NOR"�����־۳�һ�����������϶��£�����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"������ͼ��"NOR"�����־۳�һ��������бб����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"��������"NOR"��˫�־۳�һ������������ͬʱ����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"���������"NOR"��ȫ���ڿն�������ȫ�����������$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"���Ľ�������"NOR"�����־۳�һ�����������϶��£�����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"�����б�ɡ�"NOR"�����־۳�һ��������бб����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"��������ա�"NOR"��˫�־۳�һ������������ͬʱ����$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+(order[random(13)])+"����������"NOR"��ȫ���ڿն�������ȫ�����������$n��$l",
                "dodge":                70,
                "parry":                60,
                "force":                300,
                "damage":               310,
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="music"; }

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
//        me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("qidao", 1)/3  + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("qidao", 1)/3  + damage_bonus / 5);
        if (random(2)==0)
                        return  WHT"\n$N������ɫ��â��������ƬƬ����$n��$nֻ��" HIY "��" + name + "��" NOR + WHT "��һ����ʹ��\n"NOR;
                else 
                        return  HIC"\n$N��������Ϊһ�ߣ�����$n"+HIC"�����ڡ�\n"NOR;

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
                message_vision(HIG"$N�����һ��������ͨ���ĵ���"+(order[random(13)])+""+(order[random(13)])+"������ƪ��"NOR""NOR"������Ŀ��������Ȼ����������\n"NOR, me);       
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
    return __DIR__"qidao/" + action;
}