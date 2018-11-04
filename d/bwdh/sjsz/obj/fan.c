//Cracked by Kafei
//ߡ��
//Ryu

#include <weapon.h>
#include <ansi.h>
inherit STAFF;
//inherit SKILL;

mapping *action = ({
([      "action" : 
"ž��һ����$N����ߡ��ߡ��һ���̰�����$n�羮Ѩ΢�㣬���ƺ�����������Ю���磬��������",
        "force" : 160,
        "dodge" : 10,
        "damage_type" : "����",
]),
([      "action" : 
"$N�������ӻӶ���һ�󾢷���$nӭ����ȥ�����о�������",
        "force" : 220,
        "dodge" : 5,
        "damage_type" : "����",
]),
([      "action" : 
"$Nһ�Ȼӳ������Ų���һ����������ߡ��һ���˴糤�ĵ�Ѩ�ʣ�����$n$l��ȥ",
        "force" : 300,
        "dodge" : 5,
        "damage_type" : "����",
]),
([      "action" : 
"$Nһ����ߡ��б�㣬������磬�ȵ����飬�ƻ���ʵ��ֱ��$n����",
        "force" : 360,
        "dodge" : -5,
        "damage_type" : "����",
]),
([      "action" : 
"$N������Х�������������һ�󼲷磬��$n��ȥ����������",
        "force" : 420,
        "dodge" : 10,
        "damage_type" : "����",
]),
([      "action" : 
"$N����ߡ�Ȼ�ת������һ�պϣ���ָת����ת�����ô���$n��$l",
        "force" : 480,
        "dodge" : 10,
        "damage_type" : "����",
])
});
void create()
{
    set_name(HIC"ߡ��"NOR, ({"fan","zheshan", "shan"}) );

        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","һ��ߡ�ȣ��ȹ��Ǹ����ġ�\n");
	set("rigidity", 1000000);
	set_weight(1000);
        set("value", 2000);
	set("ding", 10);
	set("material", "blacksteel");

        set("wield_msg",HIM"$N�������ͳ�һ��ߡ�ȣ�һ�ӣ����˿�����¶������һ�使�����ε�ĵ����\n"NOR);
        set("unwield_msg", "ž��һ����$N��ߡ�Ⱥ����������ս����С�\n");

	init_staff(200);
	set("actions", (: call_other, __FILE__, "query_action" :) );
        setup();
}
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
void init()
{
        add_action("do_duan", "duan");
        add_action("do_shoot", "shoot");
	add_action("do_duan", "break");
}
int do_duan(string arg)
{
        object target;
        object me = this_player();
        object weapon;

        if (!arg)
        return notify_fail("ʲô��\n");

        target = present(arg,environment(me));
        if( !target
        ||      !target->is_character()
	||      !me->is_fighting(target) )
                return notify_fail("ʲô��\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("id") != "fan" )
                return notify_fail("ʲô��\n");

        if( me->is_busy() )
                return notify_fail("��ǰһ��������û�����ꡣ\n");

        if( !objectp(weapon = target->query_temp("weapon")))
                return notify_fail("ʲô��\n");

        message_vision("\n$N�ۼ�$n��" + weapon->name()
                        + "����������ʳָ����һ�У���ס��"
			+ weapon->name() + "������б�Ż�ȥ��������"
			+ weapon->name() + "һ����\n", me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2){
	message_vision(HIW "ֻ���������һ����$n���е�" + weapon->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, me, target);
	weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
	}else{
	message_vision("$N��ߡ�Ⱥ�$n��" + weapon->name()
                                + "�����ð�����Ļ��ǡ�\n", me, target);
	me->start_busy(1+ random(3));
	}
	return 1;
}
int do_shoot(string arg)
{
   object me = this_player();
   object victim, weapon;

   if (!arg)
        return notify_fail("��Ҫ��˭��\n");

   victim = present(arg,environment(me));

	if( !objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("id") != "fan" )
                return notify_fail("ʲô��\n");

   if (!victim)
        return notify_fail("���ﲢ�޴��ˣ�\n");

   if (query("ding") < 1)
	return notify_fail("ߡ����Ķ����Ѿ������ˡ�\n");

   if (!living(victim))
        return notify_fail("�ⲻ�ǻ��\n");

   if (me->is_busy())
        return notify_fail("��ǰһ��������û�����ꡣ\n");

   if (victim == me) return notify_fail("�αض��һ�٣�\n");

   if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

   message_vision(HIG"$N����ķָһ���ȱ��ϵĻ�����һö�������ȹ��зɳ�����$n��ȥ��\n" NOR, me, victim);
   add("ding", -1);
   if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){ 
   message_vision(CYN"ֻ��һ���ҽУ������Ѷ�����$N�����ϡ�\n"NOR, victim);
   victim->apply_condition("insect_poison", 100);
   victim->receive_wound("qi", 500, "��" + me->query("name") +"ɱ����");
   victim->receive_wound("jing", 100, "��" + me->query("name") +"ɱ����");
   if (!victim->is_killing(me))
   victim->kill_ob(me);
   } else {
   message_vision(CYN"����$N����ض��˿�ȥ��\n"NOR, victim);
   if (!victim->is_killing(me))
   victim->kill_ob(me);
   }
   return 1;
}
