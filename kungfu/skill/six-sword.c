// murong-jiafa ����׷�꽣

#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
        ([      "name":                 "���겻ɢ",
                        "action":               "$Nʹһ��"+(order[random(13)])+"�����겻ɢ��"NOR"������$w���Ⱪ������$n��$l��ȥ",
                        "dodge":                50,
                         "parry":                50,
                        "force":                170,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "����ɭɭ",
                        "action":               "$N������ת��һ��"+(order[random(13)])+"������ɭɭ��"NOR"����$n��$l",
                        "dodge":                70,
                         "parry":                50,
                        "force":                200,
                        "force":                170,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "���Ƶ���",
                   "action":               "$N�趯$w��һ��"+(order[random(13)])+"�����Ƶ���"NOR"Ю�������������$n��$l",
                        "dodge":                40,
                         "parry":                50,
                        "damage":               290,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "���ܵظ�",
                        "action":               "$N����$w����һ��������"+(order[random(13)])+"�����ܵظ���"NOR"��$n��$l�̳�����",
                        "dodge":                40,
                         "parry":               60,
                        "damage":               140,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��������",
                        "action":               "$N����$w���Ⱪ����һ��"+(order[random(13)])+"���������ǡ�"NOR"��$n$l��ȥ",
                        "dodge":                60,
                         "parry":                50,
                        "damage":               120,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��������",
                        "action":               "$N����$w����һ���⻡��ֱָ$n$l��һ��"+(order[random(13)])+"���������¡�"NOR"��������������ȥ",
                        "dodge":                60,
                         "parry":                40,
                        "damage":               150,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "Ⱥħ����",
                        "action":               "$Nʹһ��"+(order[random(13)])+"��Ⱥħ���衹"NOR"������$w�����������$n��$l��������",
                        "dodge":                50,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�������",
                        "action":               "$N����һת��һ��"+(order[random(13)])+"���������"NOR"$wն��$n��$l",
                        "dodge":                50,
                        "damage":               220,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "�ٹ�ҹ��",
                        "action":               "$N�趯$w��һ��"+(order[random(13)])+"���ٹ�ҹ�С�"NOR"Ю�������������$n��$l",
                        "dodge":                40,
                        "force":                170,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "������·",
                        "action":               "$N����$wһ����ʹ��"+(order[random(13)])+"��������·��"NOR"��$n��$l�̳�һ��",
                   "dodge":                30,
                        "force":                170,
                        "damage":               170,

                        "damage_type":  "����"
                ]),
                ([      "name":                 "��Ӱ����",
                        "action":               "$N����$w���Ⱪ����һ��"+(order[random(13)])+"����Ӱ������"NOR"��$n$l��ȥ",
                        "dodge":                20,
                        "force":                170,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "��ع�",
                        "action":               "$N����$wֱָ$n$l��һ��"+(order[random(13)])+"����ع���"NOR"�������˽�����ȥ",
                        "dodge":                20,
                        "force":                170,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
      ([      "action":               
"$Nһչ$w��һ��"+(order[random(13)])+"��ʱ��ɫ��"NOR"�������ʣ�������ã�����$n������ ",
                //"dodge":                50,

                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��ڣ�����������������֣����������ξ��ĸо�����Ȼ�䣬
���㽣����������$n��������Ȼ���꽣����"+(order[random(13)])+"�����軨��"NOR"��",
                //"dodge":                120,
                "damage":               330,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ���Ƴ���һ��"+(order[random(13)])+"ҹѩ������"NOR"��ֻ��������֯����$n",
                //"dodge":                155,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ؽ�������ʹ��"+(order[random(13)])+"�������ԡ�"NOR"��ƬƬ��Ӱ����ȴ��Ȼ�������������$n",
                "dodge":                50,
                "damage":               320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������į������$w����бָ��$w��Ȼɫת�Ա̣���Ȼ���꽣���ľ���
"+(order[random(13)])+"�Ľ�һҹ̦����"NOR"�Ѿ��������������������̦�̵���$n������",
//                "dodge":                150,
                "damage":               300,
                "damage_type":  "����"
        ]),
       ([      "action":               
"$N���ֺ�ü��$wб�������������������ޣ������ƿ���������·��ʵ���飬��ʽ 
����δ�䡣���ǡ����ʮ��ʽ���еĵ�һʽ"+(order[random(13)])+"���������"NOR" ",
                "dodge":                50,
                "damage":               333,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڰ�ʽ"+(order[random(13)])+"�綯ǧ�塹"NOR"����������������������˷���ȴ 
�ֲ��嵽����һ�����졣"NOR,
                "dodge":                50,
                "damage":               340,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڶ�ʽ"+(order[random(13)])+"����ө��"NOR"���ؽ�������Ʈ��Ľ����������ͬ
ҹ������ө���裬Ϯ��$n$l��",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ᶶ�ὣ������ֻ������������Ʈҡ������ȴ�ǡ����ʮ��ʽ���е���ʽ
"+(order[random(13)])+"����ɽᰡ�"NOR" ",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ӣ��ƺ���̬���У�ͣ�в�����Ȼ�����Ʋ�����ı��֮���ѷ���$n$l��
���ǡ����ʮ��ʽ���е���ʽ"+(order[random(13)])+"�Ƶ����᡹"NOR"��",
                "dodge":                50,
                "damage":               310,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ӻ���һ���뻡������$w���㣬ʹ�������ʮ��ʽ���е���ʽ"+(order[random(13)])+"��Ѩ���硹"NOR"�� 
�����Ľ�����Ȼ������˷�����$n��",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�������ǰ������б�Ӷ��£�����һת��$wƽƽ�Ƴ���˿˿����ƮȻ������ 
���ǡ����ʮ��ʽ���е���ʽ"+(order[random(13)])+"˪��������"NOR"��",
                "dodge":                95,
                "damage":               370,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ƺ�����ң�������ǰƮ�������˷ֲ��巽��Ȼ������ȴ���� 
�����紺���Ⱦ���֡����ǡ����ʮ��ʽ���еھ�ʽ"+(order[random(13)])+"���Ǵ��硹"NOR"��",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "����"
        ]),                       
        ([      "action":               
"$Nʹ�������ʮ��ʽ���е�ʮʽ"+(order[random(13)])+"��÷��ѩ��"NOR"��ֻ���������裬�������䣬 
������÷�ڷ���Ʈ��$n$l��",
                "dodge":                95,
                "damage":               320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��ת��һ�����̶̵Ļ��⸡����ǰ�����ǡ����ʮ��ʽ���� 
��ʮ��ʽ"+(order[random(13)])+"���͸�Ƽ��"NOR"��ֻ������Ʈ��������$n$l����",
                "dodge":                60,
                "damage":               330,
                "damage_type":  "����"
        ]),     
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");

        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("���Ľ�ݽ������̫ǳ��\n");

        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");

        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("��Ĳκ�ָ���̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");


        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("six-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");

        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("��Ĳκ�ָ���̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");


        if ((int)me->query("jing") < 20)
                return notify_fail("�����������������׷�꽣��\n");
		if ((int)me->query("neili") < 20)
                return notify_fail("�����������������׷�꽣��\n");
        me->receive_damage("jing", 20);
		me->add("neili",-15);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"six-sword/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");

   if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
      && me->query_skill_prepared("finger") == "canhe-zhi"
      && me->query_skill_mapped("finger") == "canhe-zhi"
      && objectp(weapon)) {
        me->set_temp("lianhuan_hit", 1);
        weapon->unequip();
        if (random(2)==0) victim->start_busy(2);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
        weapon->wield();
        me->add("neili", -30);
        me->delete_temp("lianhuan_hit");
        me->add_temp("lianhuan", -1);
        }
        if (random(5) == 0 && me->query("neili") > 65)
        {
                me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 80) / 3+30);
                	return HIR "$NͻȻ����һ�ɶ���������ͷ����������ɱ��...."+(order[random(13)])+"��ɱɱɱ��"NOR"��\n" NOR;
        }

}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"����������$n�͹����ʹ������������$n�ĳ�����������$n�������������У�\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"ʹ�����ƶ�ת��$n����Ī�����������;ת�˷���ֱ���Լ�Ϯ��!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}
