// Cuff��  ��ȭ������ȭ��̫�泤ȭ������ȭ�����ֳ�ȭ���˼�ȭ
// Claw��  �������֡�С�����֡�ӥצ������צ��
// Strike�������ơ��䵱���ơ����������

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([      "action": "$N������̧��һ�в�ȭ�ġ������ڡ�����׼$n��$l�ͻ���ȥ",
        "force" : 420,
        "attack": 130,
        "dodge" : 45,
        "parry" : 45,
        "damage": 180,
        "damage_type":  "����"
]),
([      "action": "$Nһ������ȭ�ġ��׺����᡹������������ת�ɹ��������������ɹ��֣���\n"
                  "��һ�����죬����$n$l",
        "force" : 512,
        "attack": 145,
        "dodge" : 10,
        "parry" : 75,
        "damage": 185,
        "damage_type":  "����"
]),
([      "action": "$N����һ�ݣ�ʩչС�����ֵ��ַ���˫�ֶ���$n$l���Ĺؽ�ֱֱץȥ",
        "force" : 410,
        "attack": 170,
        "dodge" : 35,
        "parry" : 35,
        "damage": 278,
        "damage_type":  "ץ��"
]),
([      "action": "$N��ȭ��������ȭת�ۻ��ţ�һ�����ֵ����ֳ�ȭͻȻ���������������������$n",
        "force" : 460,
        "attack": 150,
        "dodge" : 62,
        "parry" : 60,
        "damage": 290,
        "lvl"   : 30,
        "damage_type":  "����"
]),
([      "action": "ֻ��$N����������ʹ���˼�ȭ�еġ��˼�����ʽ����˫�ƶ���$n��$lƽƽ��ȥ",
        "force" : 480,
        "attack": 160,
        "dodge" : 40,
        "parry" : 40,
        "damage": 285,
        "damage_type":  "����"
]),
([      "action": "$N���һ����������$n���һ����������$n���ֻ�ȥ�����ǰ����Ƶ���ʽ",
        "force" : 510,
        "attack": 155,
        "dodge" : 30,
        "parry" : 30,
        "damage": 295,
        "damage_type":  "����"
]),
([      "action": "$N�������ߣ����ֻ��أ�����һ����������Ƶġ��ο�̽צ����Ѹ������$n$l",
        "force" : 510,
        "attack": 150,
        "dodge" : 45,
        "parry" : 45,
        "damage": 310,
        "damage_type":  "����"
]),
([      "action": "ֻ��$N������ʽ��˫�ֽ��䵱�ɵ�����ʹ���ܲ�͸�磬���в���$n��$l",
        "force" : 460,
        "attack": 155,
        "dodge" : 160,
        "parry" : 160,
        "damage": 305,
        "damage_type":  "����"
]),
([      "action": "$NͻȻ����һԾ����˫������צ״������$n��$l��Ȼץȥ����Ȼ��ӥצ������ʽ",
        "force" : 470,
        "attack": 185,
        "dodge" : 60,
        "parry" : 60,
        "damage": 355,
        "damage_type":  "ץ��"
]),
([      "action": "ֻ��$N����һ����˫�ַ������ϱ�ΪȦ��һ��̫��ȭ�����֡�ֱ��$n��$l",
        "force" : 350,
        "attack": 90,
        "dodge" : 210,
        "parry" : 330,
        "damage": 65,
        "damage_type":  "����"
]),
([      "action": "ֻ��$N��ǰһ��������һ�Ǵ������ֻ�ס���̣�����˳��һ����ʩһ��ˤ���ֻ���$n",
        "force" : 520,
        "attack": 155,
        "dodge" : 41,
        "parry" : 37,
        "damage": 303,
        "damage_type":  "����"
]),
([      "action": "$Nһ��ת����$n���������ֽ�$n���α�ס�͵ĳ�����ˤȥ����Ȼ���ɹŵ�ˤ����ʽ",
        "force" : 560,
        "attack": 185,
        "dodge" : 75,
        "parry" : 60,
        "damage": 325,
        "damage_type":  "ˤ��"
]),
});

string main_skill() { return "baihua-cuoquan"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���ٻ���ȭ������֡�\n");

        if (me->query("int") < 28)
                return notify_fail("�����������̫��޷�ѧϰ�ٻ���ȭ��\n");

        if (me->query("dex") < 23)
                return notify_fail("����������������޷�ѧϰ�ٻ���ȭ��\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������ΪԶԶ���㣬������ϰ�ٻ���ȭ��\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("����ڹ������ǳ���޷�ѧϰ�ٻ���ȭ��\n");

        if ((int)me->query_skill("unarmed", 1) < 150)
                return notify_fail("���ȭ�Ÿ������ޣ��޷����ٻ���ȭҪ�衣\n");

        if ((int)me->query_skill("cuff", 1) < 100)
                return notify_fail("���ȭ���������ޣ��޷����ٻ���ȭҪ�衣\n");

        if ((int)me->query_skill("claw", 1) < 100)
                return notify_fail("���צ���������ޣ��޷����ٻ���ȭҪ�衣\n");


       if (((int)me->query_skill("houquan", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("�������צ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");

        return 1;
}

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }  

int valid_combine(string combo) { return combo=="houquan" || combo=="bazhen-zhang"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("baihua-cuoquan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("������������ˡ�\n");
       if (((int)me->query_skill("houquan", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("�������צ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("���������̫���ˡ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -120);

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("baihua-cuoquan", 1);

        if (damage_bonus < 100 || lvl < 150) return 0;
if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (random(3)==0)
        {
                victim->receive_wound("qi", (damage_bonus ) / 2+10);
                return HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                       "�߹Ƕ��۵�������\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"baihua-cuoquan/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("baihua-cuoquan",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N���־۳ɻ�צ״! ����Ѫ��ץ��һ��ץס$n��"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}
 if ( random(4) == 0 && random(level) > 150){
         msg = GRN"$N���$n�Ĺ��� ʩ����ȭ�ġ������ڡ�������һ����˫��ͬʱ����$n��\n"NOR;
         msg += GRN"$n�е��ؿ�һ�ƣ���Ȼ���ܶ���!!��\n"NOR;
ob->start_busy(4);
message_vision(msg, me, ob);
}
           return j;
}      
