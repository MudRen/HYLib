#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
        "���$nһ��"+(order[random(13)])+"������Ʈ翡�"NOR"���Ӷ�����$v����$N��$w��\n",
        "���$n����$vһ�֣�һ��"+(order[random(13)])+"����ת���̡�"NOR"��б��$N��$w��\n",
        "���$n����$v�ն���ɣ�һ��"+(order[random(13)])+"������ü��"NOR"������$N��$w��\n",
        "���$n����$v������ת��һ��"+(order[random(13)])+"�����񹤡�"NOR"����ɨ$N��$w��\n",
        });

        
string *unarmed_parry_msg = ({
        "$n���е�$v�趯��ɣ�һ��"+(order[random(13)])+"�������ӡ�"NOR"����ס��$N�Ĺ��ơ�\n",
        "$n��Ӱ�ζ���һ��"+(order[random(13)])+"������񺿡�"NOR"������$N�����̡�\n",
        "$n����һ����һ��"+(order[random(13)])+"����ħͬ�塹"NOR"�����$N�Ĺ��ơ�\n",
        "$n���е�$v���϶��£�һ��"+(order[random(13)])+"����ڤ��Ӱ��"NOR"������$N��Ҫ����\n",
        });  
string *action_msg = ({
       "$N��$wһ�ڣ�����������������һʽ"+(order[random(13)])+"������է�졹"NOR"��Ȼ��ɣ�����ʵ�ʵ�����������������$n" NOR,
       "$w����һ�䣬���紩��������С��ϸ�壬����"+(order[random(13)])+"���������׸���"NOR"�ھ�ʽ"+(order[random(13)])+"��������꡹"NOR"" NOR,
       "$N�󿪴��أ��ڶ�ʽ"+(order[random(13)])+"��������ơ�"NOR"���������$n" NOR,
       "$N��������$w�߾ٹ�ͷ���˾�ֱ��������ʽ"+(order[random(13)])+"�����׷ٳǡ�"NOR"��Ȼ���ް�㻨��" NOR,
       "$w�ٱ䣬��$N���´�����ң��$n��$l������ʽ"+(order[random(13)])+"��Ѹ��ǧ�á�"NOR"��$n��ȫ�޷�׽������" NOR,
       "$N����$w������һ���һ���󻡣�$w�����ʽ"+(order[random(13)])+"�������ɳ��"NOR"������߷����㸫Ӱ����$nƽ�ƶ���" NOR,
       "$NԾ����գ�ʹ������ʽ"+(order[random(13)])+"���������ס�"NOR"������$w��Ю������֯��һ��������$n��ȥ" NOR,
       "$N�������У�$w������Ϊ��׾���˾��Ƴ�����ѩ����â������ʽ"+(order[random(13)])+"���������꡹"NOR"һ������һ���ع���$n" NOR,
       "$N�Ӹ����й�ֱ�������󷭴�����;ת�򣬵ڰ�ʽ"+(order[random(13)])+"������������"NOR"���ѱ任��������λ����������$n��$l" NOR,
       "$w��$N���е��𣬻���һ��Ư���Ļ�������$n��ͬʱ���ֻ�ȭֱ���������������ĵ�ʮʽ"+(order[random(13)])+"������������"NOR"" NOR,
});
mapping *action = ({
        ([      "action":               
"$N����$w�趯���Ų�һ����һ��"+(order[random(13)])+"���������ϡ�"NOR"������$w�����ǰ�ֱ��$n��$l��",
                "damage":               310,
                "force":               310,	
                "dodge":                60,
                "parry":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��"+(order[random(13)])+"��������ء�"NOR"�羪��һƲ����$n���޾�Ѷ��һ˲��$w������$n����ǰ��",
                "damage":               310,
                "force":               310,	
                "dodge":                30,
                "parry":                30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�����ݰ���ת��ͣ��һ��"+(order[random(13)])+"���������"NOR"��ֱȡ$n�ĸ���Ҫ����",
                "damage":               310,
                "force":               310,	
                "dodge":                60,
                "parry":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wǣ���������������һ��"+(order[random(13)])+"�����°�����"NOR"�����а���$n$l��ȥ��",
                "damage":               310,
                "force":               310,	
                "dodge":                100,
                "parry":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�ݷ����������㣬һ��"+(order[random(13)])+"���ط�����"NOR"��ͻȻ������һ�ɺ�����$N�ĸ���͸����",
                "damage":               310,
                "force":               310,	
                "dodge":                110,
                "parry":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"ͻȻ���ݷ�ռ䱻�Ϳհ㣬$N����$w����һ���̳���һʽ"+(order[random(13)])+"�������ס�"NOR"ʹ$n���������У�", 
                "damage":               310,
                "force":               310,	
                "dodge":                50,
                "parry":                50,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("����ڹ��ķ���򲻹���\n");
    if ((int)me->query("max_neili") < 250)
   return notify_fail("�������̫����\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("�����ѩ����̫���ˡ�\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("���ͨ��������̫���ˡ�\n");
       if (((int)me->query_skill("duanyun-fu", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("��Ķ��Ƹ�̫���ˡ�\n");
       if (((int)me->query_skill("axe", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("��Ļ�������̫���ˡ�\n");
       if (((int)me->query_skill("liumang-quan", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("�����å��ȭ̫���ˡ�\n");
       if (((int)me->query_skill("tiezhang-zhangfa", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("��������Ʒ�̫���ˡ�\n");


    return 1;
}



mapping query_action(object me, object weapon)
{

if (random(3)==0)
	        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force": 580 + random(50),
                "damage": 580 + random(50),
                "attack": 50 + random(30),
                "dodge" : 50 + random(30),
                "parry" : 50 + random(30),
                "damage_type" : random(2)?"����":"����",
        ]);
else         return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("��ʹ�õ��������ԡ�\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 70)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("����������������Ƹ���\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("�����ѩ����̫���ˡ�\n");


    me->receive_damage("qi", 55);
return 1;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N����һ������������һƬ��Ҷ���Ʈ��,$nͷһ�裬��֪����!\n"NOR;

victim->start_busy(3);

                return msg;
}


        if (random(3)==0) 
        {
victim->receive_wound("qi", (random(me->query_skill("xuanyuan-axe",1))+150));
                return HIM "ֻ����â������$n�rѪ�ĞR����$N" HIM "���Ͼۼ��������ϵ羢���ˣ�\n" NOR;
        }
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("xuanyuan-axe",1);             
if (weapon)
{

        if (random(5)==1 && me->query_skill("xuanyuan-axe",1)>100
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa")
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIR"$N�����,$n�޷�����Ҳ�޷�����!!\n"NOR;
        }
        if( damage_bonus > 30 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && random(2)==0
        && me->query_skill_mapped("force") == "guiyuan-tunafa") {
        victim->receive_wound("qi", (random(damage_bonus)+150));
        return HIB"$n��������$lҪ����Ѫ����һ��!!\n"NOR;
        }
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("xuanyuan-axe", 1);
level2 = me->query_skill("xuanyuan-axe", 1);
if (weapon)
{
        if (  level2 > 100
        && random(4)==1
        && (string)weapon->query("skill_type") == "axe"){
 
            msg = HIC"$n����ʱ��$N����󸫣�$n�޷�����Ҳ�޷�����!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
               }

}
message_vision(msg, me, ob);
}








string perform_action_file(string action)
{
    return __DIR__"xuanyuan-axe/" + action;
}

